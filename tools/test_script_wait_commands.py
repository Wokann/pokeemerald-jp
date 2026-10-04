#!/usr/bin/env python3
"""Verify door/cry wait names against the JP ROM's actual callbacks."""

import re
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import generate_script_cmd_table as generator
import jp_emit_maps as emitter
import jp_script_parser as parser
import verify_generated_map_scripts as gate


class ScriptWaitCommandTests(unittest.TestCase):
    def test_table_parser_and_c_constants_use_the_real_wait_opcodes(self):
        constants = (ROOT / "include/constants/script_commands.h").read_text()
        entries = re.findall(
            r"^\s*script_cmd_table_entry\s+(\w+)\s+(\w+)\s*@",
            (ROOT / "data/script_cmd_table.inc").read_text(), re.MULTILINE,
        )
        for constant, handler, macro, opcode in (
            ("SCR_OP_WAITDOORANIM", "ScrCmd_waitdooranim", "waitdooranim", 0xAE),
            ("SCR_OP_WAITMONCRY", "ScrCmd_waitmoncry", "waitmoncry", 0xC5),
        ):
            with self.subTest(opcode=opcode):
                self.assertEqual(entries[opcode], (constant, handler))
                self.assertEqual(parser.OPCODE_BY_NAME[constant], opcode)
                self.assertEqual(parser.FORMATS[opcode][0], macro)
                match = re.search(r"\b" + constant + r"\s*=\s*(0x[0-9A-Fa-f]+)", constants)
                self.assertIsNotNone(match)
                self.assertEqual(int(match.group(1), 16), opcode)

    def test_standard_macros_emit_the_verified_bytes(self):
        self.assertEqual(gate.assemble_candidate("\twaitdooranim\n\twaitmoncry\n", 0x08000000), b"\xAE\xC5")
        macros = (ROOT / "asm/macros/event.inc").read_text()
        self.assertNotIn(".macro waitdooranim_jp", macros)
        self.assertNotIn(".macro waitmoncry_jp", macros)

    def test_handlers_reference_the_actual_native_callbacks(self):
        source = (ROOT / "src/scrcmd.c").read_text()
        for handler, callback in (
            ("ScrCmd_waitdooranim", "IsDoorAnimationStopped"),
            ("ScrCmd_waitmoncry", "IsCryFinished"),
        ):
            with self.subTest(handler=handler):
                body = re.search(r"bool8 " + handler + r"\(struct ScriptContext \*ctx\)\s*\{([^}]+)\}", source)
                self.assertIsNotNone(body)
                self.assertEqual(body.group(1).split(), ["SetupNativeScript(ctx,", callback + ");", "return", "TRUE;"])

    def test_jp_rom_table_and_callback_literals_remain_at_the_real_addresses(self):
        rom = (ROOT / "baserom_jp.gba").read_bytes()
        for opcode, handler, literal, callback in (
            (0xAE, 0x0809B2FD, 0x0809B30C, 0x0809B2E5),
            (0xC5, 0x0809B1B5, 0x0809B1C4, 0x080A2F41),
        ):
            with self.subTest(opcode=opcode):
                offset = 0x1DABAC + opcode * 4
                self.assertEqual(int.from_bytes(rom[offset:offset + 4], "little"), handler)
                offset = literal - 0x08000000
                self.assertEqual(int.from_bytes(rom[offset:offset + 4], "little"), callback)

    def test_generator_resolves_the_current_handlers_by_jp_elf_address(self):
        symbols = generator.build_label_map()
        self.assertEqual(symbols[0x0809B2FC], "ScrCmd_waitdooranim")
        self.assertEqual(symbols[0x0809B1B4], "ScrCmd_waitmoncry")

    def test_emitter_has_no_reverse_wait_name_overrides(self):
        for owner, semantic in emitter.MAP_VERIFIED_SEMANTIC_LABELS.items():
            for address, aliases in semantic.get("command_aliases", {}).items():
                with self.subTest(owner=owner, address=address):
                    self.assertFalse({"waitdooranim", "waitmoncry"} & set(aliases))


if __name__ == "__main__":
    unittest.main()
