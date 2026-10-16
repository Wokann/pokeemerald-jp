"""Regression checks for the JP Sound Check physical-manifest audit."""

from __future__ import annotations

import io
import struct
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

    def test_data_owner_has_native_names_and_table_sizes(self):
        data = audit.audit_data(self.rom)
        self.assertEqual((data["start"], data["end"], data["size"]),
                         ("0x08566D08", "0x08568A78", 0x1D70))
        self.assertEqual(data["names"]["name_objects"], 481)
        self.assertEqual(data["names"]["sound_effects"]["entries"], 270)
        self.assertEqual(data["names"]["music"]["entries"], 210)

    def test_name_pointer_into_text_interior_is_rejected(self):
        changed = bytearray(self.rom)
        struct.pack_into("<I", changed, 0x5682F8 + 4, 0x08566E7E)
        with self.assertRaisesRegex(audit.AuditError, "sound_effects\\[1\\].*non-object"):
            audit.audit_name_tables(changed)

    def test_name_pointer_into_following_owner_is_rejected(self):
        changed = bytearray(self.rom)
        struct.pack_into("<I", changed, 0x568730 + 4, audit.DATA_END)
        with self.assertRaisesRegex(audit.AuditError, "music\\[1\\].*non-object"):
            audit.audit_name_tables(changed)

    def test_name_table_padding_is_not_text(self):
        changed = bytearray(self.rom)
        changed[audit.NAME_POOL_END - audit.ROM_BASE] = 0xFF
        with self.assertRaisesRegex(audit.AuditError, "alignment byte"):
            audit.audit_name_tables(changed)

    def test_candidate_data_drift_is_rejected(self):
        changed = bytearray(self.rom)
        changed[audit.DATA_START - audit.ROM_BASE] ^= 1
        with self.assertRaisesRegex(audit.AuditError, "candidate differs in Sound Check data"):
            audit.compare_candidate_data(self.rom, changed)

    def test_following_owner_is_outside_data_contract(self):
        changed = bytearray(self.rom)
        changed[audit.DATA_END - audit.ROM_BASE] ^= 1
        self.assertEqual(audit.compare_candidate_data(self.rom, changed)["sha256"],
                         audit.DATA_SHA256)

    def test_missing_map_symbol_is_rejected(self):
        with TemporaryDirectory() as directory:
            path = Path(directory) / "candidate.map"
            path.write_text("                0x080E82DC                CB2_SoundCheck\n", encoding="utf-8")
            with self.assertRaisesRegex(audit.AuditError, "VBlankCB_SoundCheck"):
                audit.check_map(path)

    def test_linker_ram_assignment_lines_are_parsed(self):
        with TemporaryDirectory() as directory:
            path = Path(directory) / "candidate.map"
            path.write_text(
                "    0x02039cbc    sSoundCheckAudioUpdateEnabled = .\n"
                "    0x080e82dc    CB2_SoundCheck\n"
                "    0x08566d08    unsupported = OTHER + 4\n",
                encoding="utf-8",
            )
            self.assertEqual(audit.parse_map_symbols(path), {
                "sSoundCheckAudioUpdateEnabled": [0x02039CBC],
                "CB2_SoundCheck": [0x080E82DC],
            })

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
