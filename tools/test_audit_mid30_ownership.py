#!/usr/bin/env python3
"""Regression checks for the mid30 ownership report."""

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_mid30_ownership as audit


class Mid30OwnershipTests(unittest.TestCase):
    def test_report_keeps_raw_ranges_and_final_owners_separate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary) / "jp"
            us_root = Path(temporary) / "us"
            for base in (root, us_root):
                (base / "data/maps/Example").mkdir(parents=True)
                (base / "data/layouts").mkdir(parents=True, exist_ok=True)
            (root / "data/data_b2d_mid30.s").write_text(
                'Before: @ 0x08300000\n'
                '\t.incbin "baserom_jp.gba", 0x300000, 0x4\n'
                '\t.include "data/layouts/layouts.inc"\n'
                '\t.incbin "baserom_jp.gba", 0x300010, 0x2\n'
                '\t.include "data/maps/Example/header.inc"\n'
                '\t.include "data/maps/Example/connections.inc"\n'
                '@ MAP_EXAMPLE (g0 m0)\n'
                'gMapConnections_EXAMPLE:\n', encoding="utf-8")
            (root / "data/layouts/layouts.inc").write_text(
                'Example_Layout::\nAnother_Layout::\n', encoding="utf-8")
            (us_root / "data/layouts/layouts.inc").write_text("", encoding="utf-8")
            for base in (root, us_root):
                (base / "data/maps/Example/map.json").write_text(
                    '{"id": "MAP_EXAMPLE"}', encoding="utf-8")
                (base / "data/maps/Example/header.inc").write_text("", encoding="utf-8")
                (base / "data/maps/Example/connections.inc").write_text("", encoding="utf-8")
            payload = audit.report(root, us_root)
        self.assertEqual(payload["summary"]["raw_baserom_regions"], 2)
        self.assertEqual(payload["summary"]["structured_layouts"], 2)
        layout = next(item for item in payload["regions_in_physical_source_order"]
                      if item["classification"] == "layouts_final_owner")
        self.assertEqual(layout["rom_start"], "0x08300004")
        self.assertEqual(layout["rom_end"], "0x08300010")
        self.assertEqual(payload["first_unresolved_boundary"]["rom_start"], "0x08300000")
        self.assertEqual(payload["protected_from_script_data_sweep"]["final_map_owners"], [
            "data/maps/Example/header.inc", "data/maps/Example/connections.inc",
        ])
        self.assertEqual(payload["summary"]["map_header_mapped_pending_extraction"], 1)
        self.assertEqual(payload["summary"]["map_connections_mapped_pending_extraction"], 1)
        self.assertEqual(payload["tilesets"]["status"], "requires_boundary_audit")


if __name__ == "__main__":
    unittest.main()
