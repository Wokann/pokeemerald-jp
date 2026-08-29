#!/usr/bin/env python3
"""Regression checks for JP map.json header/connection generation."""

import unittest
from pathlib import Path

import jp_map_metadata


ROOT = Path(__file__).resolve().parents[1]
MAPS = (
    "CaveOfOrigin_B1F",
    "VictoryRoad_1F",
    "VictoryRoad_B1F",
    "VictoryRoad_B2F",
    "Underwater_Route124",
    "Underwater_Route126",
    "Underwater_Route127",
    "Underwater_Route128",
    "Underwater_Route129",
)

CONNECTED_MAPS = (
    "Underwater_Route124",
    "Underwater_Route126",
    "Underwater_Route127",
    "Underwater_Route128",
    "Underwater_Route129",
)

NULL_CONNECTION_MAPS = (
    "CaveOfOrigin_B1F",
    "VictoryRoad_1F",
    "VictoryRoad_B1F",
    "VictoryRoad_B2F",
)

CANONICAL_LAYOUT_MAPS = (
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

    def test_headers_use_real_map_and_layout_labels(self):
        for map_name in MAPS:
            text = (ROOT / "data" / "maps" / map_name / "header.inc").read_text(encoding="utf-8")
            self.assertIn(f"{map_name}:", text)
            if map_name in CANONICAL_LAYOUT_MAPS:
                self.assertIn(f".4byte {map_name}_Layout\n", text)
                self.assertNotIn("gMapLayout_", text)
            else:
                self.assertIn("gMapLayout_", text)
            self.assertIn("map_header_flags allow_cycling=", text)
            self.assertNotIn(".set ", text)

    def test_layout_symbol_keeps_legacy_names_outside_reviewed_family(self):
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_UNDERWATER_ROUTE124"),
            "Underwater_Route124_Layout",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_CAVE_OF_ORIGIN_B1F"),
            "gMapLayout_CAVE_OF_ORIGIN_B1F",
        )

    def test_connections_use_real_map_labels(self):
        for map_name in CONNECTED_MAPS:
            text = (ROOT / "data" / "maps" / map_name / "connections.inc").read_text(encoding="utf-8")
            self.assertIn(f"{map_name}_MapConnections:", text)
            self.assertNotIn(".set ", text)

    def test_null_connections_match_us_map_json_style(self):
        for map_name in NULL_CONNECTION_MAPS:
            data = jp_map_metadata.load_map(ROOT / "data" / "maps" / map_name / "map.json")
            self.assertIsNone(data["connections"])
            self.assertIn("\t.4byte NULL\n", jp_map_metadata.render_header(data))
            self.assertEqual(
                jp_map_metadata.render_connections(data),
                jp_map_metadata.warning(map_name),
            )


if __name__ == "__main__":
    unittest.main()
