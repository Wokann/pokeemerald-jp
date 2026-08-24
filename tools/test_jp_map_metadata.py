#!/usr/bin/env python3
"""Regression checks for JP map.json header/connection generation."""

import unittest
from pathlib import Path

import jp_map_metadata


ROOT = Path(__file__).resolve().parents[1]
MAPS = (
    "Underwater_Route124",
    "Underwater_Route126",
    "Underwater_Route127",
    "Underwater_Route128",
    "Underwater_Route129",
)


class MapMetadataTests(unittest.TestCase):
    def test_checked_metadata_matches_canonical_json(self):
        for map_name in MAPS:
            map_dir = ROOT / "data" / "maps" / map_name
            data = jp_map_metadata.load_map(map_dir / "map.json")
            self.assertEqual(
                (map_dir / "header.inc").read_text(encoding="utf-8"),
                jp_map_metadata.render_header(data),
            )
            self.assertEqual(
                (map_dir / "connections.inc").read_text(encoding="utf-8"),
                jp_map_metadata.render_connections(data),
            )

    def test_headers_keep_us_style_names_with_jp_layout_aliases(self):
        for map_name in MAPS:
            text = (ROOT / "data" / "maps" / map_name / "header.inc").read_text(encoding="utf-8")
            self.assertIn(f"{map_name}:", text)
            self.assertIn(f"{map_name}_Layout", text)
            self.assertIn("gMapLayout_", text)
            self.assertIn("map_header_flags allow_cycling=", text)

    def test_connections_preserve_legacy_exports(self):
        for map_name in MAPS:
            data = jp_map_metadata.load_map(ROOT / "data" / "maps" / map_name / "map.json")
            legacy_stem = data["id"].removeprefix("MAP_")
            text = (ROOT / "data" / "maps" / map_name / "connections.inc").read_text(encoding="utf-8")
            self.assertIn(f".set {legacy_stem}_MapConnections,", text)
            self.assertIn(f".set gMapConnections_{legacy_stem},", text)


if __name__ == "__main__":
    unittest.main()
