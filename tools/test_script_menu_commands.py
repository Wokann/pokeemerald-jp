#!/usr/bin/env python3
"""Use US menu names while preserving JP dispatch and parameter lengths."""

import re
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))

import audit_eventscript_sync as audit
import decompile_scripts as legacy
import jp_script_parser as parser
import verify_generated_map_scripts as gate


class ScriptMenuCommandTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.opcodes = legacy.build_opcode_table()
        cls.formats, cls.by_name = legacy.build_macro_formats(cls.opcodes)
        cls.specials = legacy.build_specials_map()

    def test_all_decoder_opcodes_follow_the_actual_225_entry_order(self):
        expected = {entry['name']: entry['value'] for entry in audit.parse_opcode_table(
            ROOT / 'data/script_cmd_table.inc')}
        self.assertEqual(len(expected), 225)
        self.assertEqual(self.opcodes, expected)
        self.assertEqual(parser.build_opcode_table(), expected)

    def test_decoder_entry_order_does_not_require_address_comments(self):
        with tempfile.TemporaryDirectory() as temporary:
            table = Path(temporary) / 'commands.inc'
            table.write_text(
                '@ script_cmd_table_entry SCR_OP_FAKE Handler\n'
                'script_cmd_table_entry SCR_OP_A Handler\n'
                'script_cmd_table_entry SCR_OP_B Handler @ 0x99\n'
                'gScriptCmdTableEnd::\n.4byte ScrCmd_nop\n', encoding='utf-8')
            for module in (parser, legacy):
                with self.subTest(decoder=module.__name__), patch.object(module, 'CMD_TABLE', table):
                    self.assertEqual(module.build_opcode_table(), {'SCR_OP_A': 0, 'SCR_OP_B': 1})

    def test_macro_bytes_match_all_four_menu_slots(self):
        for source, expected in (
                ('drawbox\n', bytes.fromhex('72')),
                ('erasebox 0, 0, 29, 19\n', bytes.fromhex('73 00 00 1D 13')),
                ('drawboxtext 1, 2, 3, 4\n', bytes.fromhex('74 01 02 03 04')),
                ('showelevmenu\n', bytes.fromhex('B2'))):
            with self.subTest(source=source):
                self.assertEqual(gate.assemble_candidate(source, 0x08000000), expected)

    def test_both_decoders_infer_the_handler_parameter_lengths(self):
        for formats in (parser.FORMATS, self.formats):
            for opcode, name, size in ((0x72, 'drawbox', 1), (0x73, 'erasebox', 5),
                                      (0x74, 'drawboxtext', 5), (0xB2, 'showelevmenu', 1)):
                with self.subTest(decoder=id(formats), opcode=opcode):
                    self.assertEqual(formats[opcode][0], name)
                    self.assertEqual(1 + sum(arg[0] for arg in formats[opcode][1]), size)

    def test_strict_decoder_keeps_end_at_the_next_instruction_boundary(self):
        for command, name, args in (
                (bytes.fromhex('72'), 'drawbox', []),
                (bytes.fromhex('73 02 03 04 05'), 'erasebox', [2, 3, 4, 5]),
                (bytes.fromhex('74 02 03 04 05'), 'drawboxtext', [2, 3, 4, 5]),
                (bytes.fromhex('B2'), 'showelevmenu', [])):
            with self.subTest(command=command.hex()), patch.object(parser, 'ROM', command + b'\x02'):
                self.assertEqual(parser.decode_instruction(0x08000000),
                                 (len(command), name, args, []))
                self.assertEqual(parser.parse_script(0x08000000),
                                 [(0, name, args, []), (len(command), 'end', [], [])])

    def test_both_decoders_preserve_goto_after_skipped_parameter_bytes(self):
        command = bytes.fromhex('74 02 03 04 05')
        raw = command + bytes.fromhex('05 00 00 20 08 02')
        with patch.object(parser, 'ROM', raw):
            self.assertEqual(parser.parse_script(0x08000000), [
                (0, 'drawboxtext', [2, 3, 4, 5], []),
                (5, 'goto', [0x08200000], [0x08200000]),
                (10, 'end', [], []),
            ])
        decoded = legacy.decode_chunk(raw, self.formats, self.specials)
        self.assertEqual([line.strip() for line in decoded.splitlines()], [
            'drawboxtext 0x2, 0x3, 0x4, 0x5', 'goto 0x8200000', 'end'])
        self.assertEqual(legacy.encode_lines(decoded, self.by_name, self.specials), raw)

    def test_chunk_decoder_round_trips_menu_commands_without_splitting_arguments(self):
        for command, name in ((bytes.fromhex('72'), 'drawbox'),
                              (bytes.fromhex('73 02 03 04 05'), 'erasebox'),
                              (bytes.fromhex('74 02 03 04 05'), 'drawboxtext'),
                              (bytes.fromhex('B2'), 'showelevmenu')):
            raw = command + b'\x02'
            with self.subTest(command=command.hex()):
                decoded = legacy.decode_chunk(raw, self.formats, self.specials)
                self.assertEqual(len(decoded.splitlines()), 2)
                self.assertEqual(decoded.splitlines()[0].strip().split()[0], name)
                self.assertEqual(decoded.splitlines()[1].strip(), 'end')
                self.assertEqual(legacy.encode_lines(decoded, self.by_name, self.specials), raw)

    def test_wrong_macro_argument_counts_are_rejected_by_the_encoder(self):
        for source in ('drawbox 0x0, 0x0, 0x1D, 0x13\n', 'erasebox\n',
                       'drawboxtext\n', 'showelevmenu 0x08000000\n',
                       'drawbox_jp\n', 'mossdeepgym2\n'):
            with self.subTest(source=source), self.assertRaisesRegex(ValueError, 'unknown command'):
                legacy.encode_lines(source, self.by_name, self.specials)

    def test_strict_decoder_rejects_truncated_menu_parameter_bytes(self):
        for opcode in (0x73, 0x74):
            for count in range(4):
                raw = bytes([opcode]) + bytes(range(count))
                with self.subTest(opcode=opcode, supplied=count), patch.object(parser, 'ROM', raw):
                    self.assertIsNone(parser.decode_instruction(0x08000000))

    def test_jp_rom_dispatch_and_handler_consumption_are_the_contract(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for opcode, handler in ((0x72, 0x0809A715), (0x73, 0x0809A769),
                                (0x74, 0x0809A775), (0xB2, 0x0809B3D5)):
            with self.subTest(opcode=opcode):
                start = 0x1DABAC + opcode * 4
                self.assertEqual(int.from_bytes(rom[start:start + 4], 'little'), handler)
        self.assertEqual(rom[0x9A714:0x9A718], bytes.fromhex('00 20 70 47'))
        self.assertEqual(rom[0x9A768:0x9A772], bytes.fromhex('81 68 04 31 81 60 00 20 70 47'))
        self.assertEqual(rom[0x9A774:0x9A77E], bytes.fromhex('81 68 04 31 81 60 00 20 70 47'))
        self.assertEqual(rom[0x9B3D4:0x9B3D8], bytes.fromhex('00 20 70 47'))
        source = (ROOT / 'src/scrcmd.c').read_text(encoding='utf-8')
        bodies = {}
        for handler in ('drawbox', 'erasebox', 'drawboxtext', 'showelevmenu'):
            match = re.search(r'bool8 ScrCmd_' + handler
                              + r'\(struct ScriptContext \*ctx\)\s*\{(.*?)\n\}', source, re.S)
            self.assertIsNotNone(match)
            bodies[handler] = re.sub(r'//[^\n]*', '', match.group(1))
        self.assertEqual(bodies['drawbox'].split(), ['return', 'FALSE;'])
        self.assertEqual(bodies['showelevmenu'].split(), ['return', 'FALSE;'])
        self.assertEqual(bodies['erasebox'].count('ScriptReadByte(ctx)'), 4)
        self.assertEqual(bodies['drawboxtext'].split(),
                         ['ctx->scriptPtr', '+=', '4;', 'return', 'FALSE;'])

    def test_existing_cable_club_calls_keep_the_verified_jp_opcode(self):
        source = (ROOT / 'data/scripts/cable_club.inc').read_text(encoding='utf-8')
        calls = re.findall(r'^\s*erasebox\s+([^\n]+)$', source, re.M)
        self.assertEqual(calls, ['0, 0, 29, 19'] * 6)
        self.assertNotRegex(source, r'(?m)^\s*drawboxtext(?:\s|$)')
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for offset in (0x246994, 0x2469AC, 0x2469F6, 0x246A3B, 0x246A7B, 0x2471E1):
            self.assertEqual(rom[offset:offset + 5], bytes.fromhex('73 00 00 1D 13'))

    def test_funcmap_and_disassembly_config_follow_the_real_handler_names(self):
        funcmap = (ROOT / 'funcmap_jp.txt').read_text()
        config = (ROOT / 'pokeemerald_jp.cfg').read_text()
        for address, handler in ((0x0809A714, 'ScrCmd_drawbox'),
                                 (0x0809A768, 'ScrCmd_erasebox'),
                                 (0x0809A774, 'ScrCmd_drawboxtext'),
                                 (0x0809B3D4, 'ScrCmd_showelevmenu')):
            with self.subTest(handler=handler):
                self.assertIn('%08x scrcmd.s %s\n' % (address, handler), funcmap)
                self.assertIn('thumb_func 0x%x %s\n' % (address, handler), config)


if __name__ == '__main__':
    unittest.main()
