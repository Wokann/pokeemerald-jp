#!/usr/bin/env python3
"""Check the complete JP command-table prefix and retained US macro interfaces."""

import hashlib
import re
import shutil
import subprocess
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import audit_eventscript_sync as audit
import decompile_scripts as legacy
import generate_script_cmd_table as generator
import jp_script_parser as parser
import verify_generated_map_scripts as gate


class ScriptCommandInterfaceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.opcodes = parser.build_opcode_table()
        cls.formats, cls.by_name = legacy.build_macro_formats(cls.opcodes)
        cls.specials = legacy.build_specials_map()

    def test_every_macro_opcode_has_a_real_jp_dispatch_slot(self):
        source = (ROOT / "asm/macros/event.inc").read_text(encoding="utf-8")
        code = "\n".join(line.partition("@")[0] for line in source.splitlines())
        referenced = set(re.findall(r"\bSCR_OP_\w+\b", code))
        self.assertEqual(referenced - self.opcodes.keys(), set())
        self.assertEqual(len(self.opcodes), 225)
        self.assertEqual(max(self.opcodes.values()), 0xE0)

    def test_us_only_macro_calls_fail_with_an_explicit_jp_diagnostic(self):
        for source in (
            "buffercontestname STR_VAR_1, CONTEST_CATEGORY_COOL\n",
            "bufferitemnameplural STR_VAR_2, ITEM_POKE_BALL, 2\n",
            "setmodernfatefulencounter 0\n",
            "checkmodernfatefulencounter VAR_0x8004\n",
        ):
            name = source.split()[0]
            with self.subTest(command=name), self.assertRaisesRegex(
                gate.VerificationError,
                name + " is not supported by the JP script engine",
            ):
                gate.assemble_candidate(source, 0x08000000)

    def test_us_only_macros_do_not_decode_as_jp_commands(self):
        unsupported = {
            "buffercontestname",
            "bufferitemnameplural",
            "setmodernfatefulencounter",
            "checkmodernfatefulencounter",
        }
        for formats in (parser.FORMATS, self.formats):
            self.assertFalse(unsupported & {name for name, _ in formats.values()})
        self.assertFalse(unsupported & {name for name, _ in self.by_name})
        for opcode in (0xE1, 0xE2):
            self.assertNotIn(opcode, self.formats)
            with self.subTest(opcode=opcode), patch.object(
                parser, "ROM", bytes([opcode, 0, 0, 0, 0, 0])
            ):
                self.assertIsNone(parser.decode_instruction(0x08000000))

    def test_jp_obedience_names_preserve_bytes_and_instruction_boundaries(self):
        for opcode, constant, command in (
            (0xCD, "SCR_OP_SETMONOBEDIENT", "setmonobedient"),
            (0xCE, "SCR_OP_CHECKMONOBEDIENCE", "checkmonobedience"),
        ):
            raw = bytes([opcode, 4, 0x80, 2])
            with self.subTest(command=command):
                self.assertEqual(self.opcodes[constant], opcode)
                self.assertEqual(
                    gate.assemble_candidate(command + " VAR_0x8004\nend\n", 0x08000000),
                    raw,
                )
                decoded = legacy.decode_chunk(raw, self.formats, self.specials)
                self.assertEqual(decoded.splitlines()[0].strip(), command + " 0x8004")
                self.assertEqual(legacy.encode_lines(decoded, self.by_name, self.specials), raw)
                with patch.object(parser, "ROM", raw):
                    self.assertEqual(parser.parse_script(0x08000000), [
                        (0, command, [0x8004], []), (3, "end", [], [])
                    ])

    def test_c_header_and_generator_keep_jp_names_without_numeric_aliases(self):
        header = {item["name"]: item["value"] for item in audit.parse_opcode_header(
            ROOT / "include/constants/script_commands.h"
        )}
        for name, opcode in (
            ("SCR_OP_SHOWELEVMENU", 0xB2),
            ("SCR_OP_SETMONOBEDIENT", 0xCD),
            ("SCR_OP_CHECKMONOBEDIENCE", 0xCE),
        ):
            self.assertEqual(header[name], opcode)
            self.assertEqual(self.opcodes[name], opcode)
        self.assertEqual(generator.JP_OPCODE_CONSTANT_OVERRIDES[0xCD], "SCR_OP_SETMONOBEDIENT")
        self.assertEqual(generator.JP_OPCODE_CONSTANT_OVERRIDES[0xCE], "SCR_OP_CHECKMONOBEDIENCE")
        for name in ("SCR_OP_DRAWBOX_JP", "SCR_OP_CD", "SCR_OP_CE"):
            self.assertNotIn(name, header)
            self.assertNotIn(name, self.opcodes)
        self.assertNotIn(("drawbox_jp", 0), self.by_name)

    def test_handler_identity_matches_rom_funcmap_config_and_current_elf(self):
        rom = (ROOT / "baserom_jp.gba").read_bytes()
        labels = generator.build_label_map()
        funcmap = (ROOT / "funcmap_jp.txt").read_text(encoding="utf-8")
        config = (ROOT / "pokeemerald_jp.cfg").read_text(encoding="utf-8")
        for opcode, address, name in (
            (0xB2, 0x0809B3D4, "ScrCmd_showelevmenu"),
            (0xCD, 0x0809B51C, "ScrCmd_setmonobedient"),
            (0xCE, 0x0809B554, "ScrCmd_checkmonobedience"),
        ):
            with self.subTest(handler=name):
                pointer = 0x1DABAC + opcode * 4
                self.assertEqual(
                    int.from_bytes(rom[pointer:pointer + 4], "little"), address | 1
                )
                self.assertEqual(labels[address], name)
                self.assertIn("%08x scrcmd.s %s\n" % (address, name), funcmap)
                self.assertIn("thumb_func 0x%x %s\n" % (address, name), config)
        self.assertEqual(rom[0x9B3D4:0x9B3D8], bytes.fromhex("00 20 70 47"))

    def test_showelevmenu_has_one_real_owner_and_no_special_tail_alias(self):
        source = (ROOT / "src/scrcmd.c").read_text(encoding="utf-8")
        funcmap = (ROOT / "funcmap_jp.txt").read_text(encoding="utf-8")
        config = (ROOT / "pokeemerald_jp.cfg").read_text(encoding="utf-8")
        self.assertEqual(source.count("bool8 ScrCmd_showelevmenu("), 1)
        self.assertNotRegex(source, r"\.set\s+ScrCmd_showelevmenu\b")
        self.assertNotIn("ScrCmd_drawbox_jp", source)
        self.assertEqual(funcmap.count(" ScrCmd_showelevmenu\n"), 1)
        self.assertEqual(config.count(" ScrCmd_showelevmenu\n"), 1)
        self.assertNotIn("08098c94", funcmap)
        self.assertNotIn("0x8098c94", config)

    def test_full_top_level_prefix_assembles_to_the_original_rom(self):
        # Assemble the actual production definitions, not a reconstructed list
        # of pointers. The fresh linked ELF resolves all external C/data names.
        source = (ROOT / "data/event_scripts.s").read_text(encoding="utf-8")
        start = source.index("\t.set ALLOCATE_SCRIPT_CMD_TABLE, 1")
        end = source.index("gStdScripts_End::") + len("gStdScripts_End::")
        prefix = source[start:end] + "\n"
        # Unlike an isolated map, the prefix calls the global C API. A private
        # static function may have the same name (e.g. ShowContestPainting).
        # Bind only actual global/weak ELF exports and preserve their exact
        # values, including Thumb function bits. Do not weaken the map gate's
        # deliberate rejection of ambiguous local labels.
        targets = set(re.findall(r"\.4byte\s+(\w+)", prefix))
        targets.update(re.findall(
            r"^\s*script_cmd_table_entry\s+\w+\s+(\w+)",
            (ROOT / "data/script_cmd_table.inc").read_text(encoding="utf-8"), re.M,
        ))
        targets.update(name for name, _ in self.specials.values())
        aliases = gate._compile_time_aliases()
        readelf = shutil.which("arm-none-eabi-readelf") or shutil.which("readelf")
        self.assertIsNotNone(readelf, "readelf is required to inspect exact ELF export values")
        symbols = subprocess.check_output(
            [readelf, "-sW", str(ROOT / "pokeemerald_jp.elf")], text=True,
        )
        for line in symbols.splitlines():
            fields = line.split()
            if (len(fields) == 8 and fields[4] in {"GLOBAL", "WEAK"}
                    and fields[6] != "UND" and fields[7] in targets):
                name, value = fields[7], int(fields[1], 16)
                self.assertNotIn(name, aliases)
                aliases[name] = value
        self.assertIn("ShowContestPainting", aliases)
        with patch.object(gate, "_compile_time_aliases", return_value=aliases):
            actual = gate.assemble_candidate(prefix, 0x081DABAC)
        expected = (ROOT / "baserom_jp.gba").read_bytes()[0x1DABAC:0x1DB7E8]
        self.assertEqual(len(actual), 0xC3C)
        self.assertEqual(actual, expected)
        self.assertEqual(hashlib.sha256(actual).hexdigest(),
                         "9738d6ed123059b59e58774bdc6a402a2194eb12d47e11b75926a724a9111da3")


if __name__ == "__main__":
    unittest.main()
