#!/usr/bin/env python3
"""Regression checks for the JP mystery-event command-table generator."""

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import generate_mystery_event_cmd_table as generator


class MysteryEventCommandTableTests(unittest.TestCase):
    def test_funcmap_resolves_every_jp_table_handler(self):
        rom = generator.BASEROM_DEFAULT.read_bytes()
        words = [int.from_bytes(rom[offset: offset + 4], "little")
                 for offset in range(generator.TABLE_OFFSET,
                                     generator.TABLE_OFFSET + generator.TABLE_SIZE, 4)]
        labels = generator.build_label_map()
        self.assertEqual([labels.get(word & ~1) for word in words], [
            "MEScrCmd_nop", "MEScrCmd_checkcompat", "MEScrCmd_end", "MEScrCmd_setmsg",
            "MEScrCmd_setstatus", "MEScrCmd_runscript", "MEScrCmd_initramscript",
            "MEScrCmd_setenigmaberry", "MEScrCmd_giveribbon", "MEScrCmd_enableresetrtc",
            "MEScrCmd_addrareword", "MEScrCmd_setrecordmixinggift", "MEScrCmd_givepokemon",
            "MEScrCmd_addtrainer", "MEScrCmd_givenationaldex", "MEScrCmd_checksum",
            "MEScrCmd_crc",
        ])

    def test_owner_source_is_direct_and_not_an_include_wrapper(self):
        text = generator.OUT.read_text(encoding="utf-8")
        self.assertTrue(text.startswith('\t.section script_data, "aw", %progbits\n'))
        self.assertNotIn(".include", text)
        self.assertEqual(text.count("\t.4byte "), 17)
        self.assertIn("gMysteryEventScriptCmdTable:", text)
        self.assertIn("gMysteryEventScriptCmdTableEnd:", text)


if __name__ == "__main__":
    unittest.main()
