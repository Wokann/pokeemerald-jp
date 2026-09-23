"""Regression checks for the JP Sound Check physical-manifest audit."""

from __future__ import annotations

import io
import sys
import unittest
from contextlib import redirect_stdout
from pathlib import Path
from tempfile import TemporaryDirectory
from unittest import mock


TOOLS = Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))
import audit_sound_check as audit


class SoundCheckAuditTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rom = (audit.ROOT / "baserom_jp.gba").read_bytes()

    def test_current_rom_span_has_the_expected_contract(self):
        manifest = audit.audit_baseline(self.rom)
        self.assertEqual(manifest["code"], {
            "start": "0x080E82DC",
            "end": "0x080E977C",
            "size": 0x14A0,
            "sha256": "030fdc725465e2ea9b852bd9404b327b547ff654b4768e9190c97b12581b7414",
        })
        self.assertEqual(manifest["symbols"]["Task_SoundCheck"], "0x080E84A4")
        self.assertEqual(manifest["ewram"][3]["size"], 0x24)

    def test_candidate_drift_is_rejected(self):
        changed = bytearray(self.rom)
        changed[audit.CODE_START - audit.ROM_BASE] ^= 1
        with self.assertRaisesRegex(audit.AuditError, "candidate differs"):
            audit.compare_candidate(self.rom, changed)

    def test_missing_map_symbol_is_rejected(self):
        with TemporaryDirectory() as directory:
            path = Path(directory) / "candidate.map"
            path.write_text("                0x080E82DC                CB2_SoundCheck\n", encoding="utf-8")
            with self.assertRaisesRegex(audit.AuditError, "VBlankCB_SoundCheck"):
                audit.check_map(path)

    def test_complete_candidate_metadata_contract(self):
        with TemporaryDirectory() as directory:
            root = Path(directory)
            all_symbols = list(audit.CODE_SYMBOLS.items())
            all_symbols.extend((name, address) for name, address, _ in audit.EWRAM_SYMBOLS)
            all_symbols.extend((name, address) for name, address, _ in audit.IWRAM_SYMBOLS)
            link_map = root / "candidate.map"
            link_map.write_text(
                "".join(f"                0x{address:08X}                {name}\n" for name, address in all_symbols),
                encoding="utf-8",
            )
            self.assertEqual(audit.check_map(link_map)["checked_symbols"], len(all_symbols))

            ewram = root / "sym_ewram_jp.txt"
            ewram.write_text(
                "".join(f"{name} = .;\n. += {size:#x};\n" for name, _, size in audit.EWRAM_SYMBOLS),
                encoding="utf-8",
            )
            iwram = root / "sym_iwram_jp.txt"
            iwram.write_text(
                "".join(f"{name} = .;\n. += {size:#x};\n" for name, _, size in audit.IWRAM_SYMBOLS),
                encoding="utf-8",
            )
            self.assertEqual(audit.check_ram_symbols(ewram, audit.EWRAM_SYMBOLS)["checked_symbols"], 6)
            self.assertEqual(audit.check_ram_symbols(iwram, audit.IWRAM_SYMBOLS)["checked_symbols"], 1)

    def test_ram_size_and_legacy_source_alias_are_rejected(self):
        with TemporaryDirectory() as directory:
            root = Path(directory)
            ewram = root / "sym_ewram_jp.txt"
            ewram.write_text("sSoundCheckAudioUpdateEnabled = .;\n. += 0x2;\n", encoding="utf-8")
            with self.assertRaisesRegex(audit.AuditError, "expected 0x1"):
                audit.check_ram_symbols(ewram, (audit.EWRAM_SYMBOLS[0],))
            source = root / "sound_check.c"
            source.write_text("SPECIAL_InitSecretBaseVars\n", encoding="utf-8")
            with self.assertRaisesRegex(audit.AuditError, "misleading Special"):
                audit.check_source(source)

    def test_json_output_is_deterministic(self):
        output = []
        for _ in range(2):
            captured = io.StringIO()
            with mock.patch.object(sys, "argv", ["audit_sound_check.py", "--json"]), redirect_stdout(captured):
                self.assertEqual(audit.main(), 0)
            output.append(captured.getvalue())
        self.assertEqual(output[0], output[1])


if __name__ == "__main__":
    unittest.main()
