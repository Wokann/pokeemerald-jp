"""Regression checks for the JP decoration physical-manifest audit."""

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
import audit_decorations as audit


class DecorationAuditTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rom = (audit.ROOT / "baserom_jp.gba").read_bytes()

    def test_current_rom_manifest_has_expected_physical_contract(self):
        manifest = audit.audit_bytes(self.rom)
        self.assertEqual(manifest["record_count"], 121)
        self.assertEqual(manifest["description_count"], 120)
        self.assertEqual(manifest["tile_pointer_count"], 120)
        self.assertEqual(manifest["ranges"][3], {
            "name": "module",
            "start": "0x0857FE04",
            "end": "0x08581A0C",
            "size": 0x1C08,
            "sha256": "25fea2495bca42deb74c76533d2c5e8087917bc58dd0a41ec19a8856816592a4",
        })
        self.assertEqual(manifest["records"][1]["id"], 1)
        self.assertEqual(manifest["records"][1]["name_bytes"], "11020b02120804")

    def test_rejects_a_nonsequential_record_id(self):
        changed = bytearray(self.rom)
        changed[audit.TABLE_START - audit.ROM_BASE + 5 * audit.RECORD_SIZE] = 99
        with self.assertRaisesRegex(audit.AuditError, "record 5 has id 99"):
            audit.audit_bytes(changed)

    def test_candidate_comparison_rejects_a_byte_change(self):
        changed = bytearray(self.rom)
        changed[audit.TILES_START - audit.ROM_BASE] ^= 0x01
        with self.assertRaisesRegex(audit.AuditError, "candidate differs from baseline in tiles"):
            audit.compare_candidate(self.rom, changed)

    def test_link_map_requires_the_stable_table_address(self):
        with TemporaryDirectory() as directory:
            path = Path(directory) / "candidate.map"
            path.write_text("                0x08580cd0                gDecorations\n", encoding="utf-8")
            self.assertEqual(audit.check_link_map(path)["gDecorations"], "0x08580CD0")
            path.write_text("                0x08580cd1                gDecorations\n", encoding="utf-8")
            with self.assertRaisesRegex(audit.AuditError, "exactly once"):
                audit.check_link_map(path)

    def test_json_output_is_deterministic(self):
        outputs = []
        for _ in range(2):
            captured = io.StringIO()
            with mock.patch.object(sys, "argv", ["audit_decorations.py", "--json"]), redirect_stdout(captured):
                self.assertEqual(audit.main(), 0)
            outputs.append(captured.getvalue())
        self.assertEqual(outputs[0], outputs[1])


if __name__ == "__main__":
    unittest.main()
