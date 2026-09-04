#!/usr/bin/env python3
"""Regression checks for mapjson's event-only output mode."""

import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MAPJSON_DIR = ROOT / "tools" / "mapjson"
MAPJSON = MAPJSON_DIR / "mapjson"


class MapJsonEventOutputTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        subprocess.run(["make", "-C", str(MAPJSON_DIR)], check=True)

    def render_events(self, map_name):
        with tempfile.TemporaryDirectory() as output_dir:
            subprocess.run(
                [
                    str(MAPJSON),
                    "events",
                    "emerald",
                    str(ROOT / "data" / "maps" / map_name / "map.json"),
                    output_dir,
                ],
                check=True,
            )
            return (Path(output_dir) / "events.inc").read_bytes()

    def test_normal_event_output_keeps_a_terminal_separator(self):
        rendered = self.render_events("Underwater_Route124")
        checked_in = (ROOT / "data" / "maps" / "Underwater_Route124" / "events.inc").read_bytes()
        self.assertEqual(rendered, checked_in)
        self.assertTrue(rendered.endswith(b"\n\n"))

    def test_shared_event_output_stays_empty(self):
        rendered = self.render_events("ContestHallBeauty")
        checked_in = (ROOT / "data" / "maps" / "ContestHallBeauty" / "events.inc").read_bytes()
        self.assertEqual(rendered, checked_in)
        self.assertEqual(rendered, b"\n")

    def test_jp_specific_event_values_are_not_normalized_to_us(self):
        """Keep source-proven JP event data distinct from the US map JSON."""
        cases = (
            (
                "Route119",
                "coord_events",
                (
                    {
                        "type": "weather",
                        "x": 28,
                        "y": 13,
                        "elevation": 0,
                        "weather": "COORD_EVENT_WEATHER_ROUTE119_CYCLE",
                    },
                    {
                        "type": "weather",
                        "x": 33,
                        "y": 13,
                        "elevation": 3,
                        "weather": "COORD_EVENT_WEATHER_ROUTE119_CYCLE",
                    },
                    {
                        "type": "weather",
                        "x": 34,
                        "y": 10,
                        "elevation": 3,
                        "weather": "COORD_EVENT_WEATHER_SUNNY",
                    },
                ),
                (
                    "\tcoord_weather_event 28, 13, 0, COORD_EVENT_WEATHER_ROUTE119_CYCLE\n",
                    "\tcoord_weather_event 33, 13, 3, COORD_EVENT_WEATHER_ROUTE119_CYCLE\n",
                    "\tcoord_weather_event 34, 10, 3, COORD_EVENT_WEATHER_SUNNY\n",
                ),
            ),
            (
                "Route110_TrickHousePuzzle4",
                "object_events",
                (
                    {
                        "graphics_id": "OBJ_EVENT_GFX_PUSHABLE_BOULDER",
                        "x": 1,
                        "y": 10,
                        "elevation": 3,
                        "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
                        "movement_range_x": 0,
                        "movement_range_y": 0,
                        "trainer_type": "TRAINER_TYPE_NONE",
                        "trainer_sight_or_berry_tree_id": "0",
                        "script": "EventScript_StrengthBoulder",
                        "flag": "FLAG_TEMP_12",
                    },
                    {
                        "graphics_id": "OBJ_EVENT_GFX_PUSHABLE_BOULDER",
                        "x": 12,
                        "y": 5,
                        "elevation": 3,
                        "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
                        "movement_range_x": 0,
                        "movement_range_y": 0,
                        "trainer_type": "TRAINER_TYPE_NONE",
                        "trainer_sight_or_berry_tree_id": "0",
                        "script": "EventScript_StrengthBoulder",
                        "flag": "FLAG_TEMP_1B",
                    },
                ),
                (
                    "\tobject_event 6, OBJ_EVENT_GFX_PUSHABLE_BOULDER, 1, 10, 3, "
                    "MOVEMENT_TYPE_LOOK_AROUND, 0, 0, TRAINER_TYPE_NONE, 0, "
                    "EventScript_StrengthBoulder, FLAG_TEMP_12\n",
                    "\tobject_event 15, OBJ_EVENT_GFX_PUSHABLE_BOULDER, 12, 5, 3, "
                    "MOVEMENT_TYPE_LOOK_AROUND, 0, 0, TRAINER_TYPE_NONE, 0, "
                    "EventScript_StrengthBoulder, FLAG_TEMP_1B\n",
                ),
            ),
            (
                "LilycoveCity_DepartmentStore_1F",
                "object_events",
                (
                    {
                        "graphics_id": "OBJ_EVENT_GFX_POKEFAN_M",
                        "x": 3,
                        "y": 6,
                        "elevation": 3,
                        "movement_type": "MOVEMENT_TYPE_WANDER_AROUND",
                        "movement_range_x": 1,
                        "movement_range_y": 1,
                        "trainer_type": "TRAINER_TYPE_NONE",
                        "trainer_sight_or_berry_tree_id": "0",
                        "script": "LilycoveCity_DepartmentStore_1F_EventScript_PokefanM",
                        "flag": "0",
                    },
                ),
                (
                    "\tobject_event 5, OBJ_EVENT_GFX_POKEFAN_M, 3, 6, 3, "
                    "MOVEMENT_TYPE_WANDER_AROUND, 1, 1, TRAINER_TYPE_NONE, 0, "
                    "LilycoveCity_DepartmentStore_1F_EventScript_PokefanM, 0\n",
                ),
            ),
            (
                "SafariZone_Southeast",
                "bg_events",
                (
                    {
                        "type": "hidden_item",
                        "x": 35,
                        "y": 32,
                        "elevation": 3,
                        "item": "ITEM_FULL_RESTORE",
                        "flag": "FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE",
                    },
                ),
                (
                    "\tbg_hidden_item_event 35, 32, 3, ITEM_FULL_RESTORE, "
                    "FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE\n",
                ),
            ),
        )

        us_root = Path("/home/kenny/pokeemerald")
        for map_name, event_key, jp_entries, generated_lines in cases:
            with self.subTest(map_name=map_name):
                map_dir = ROOT / "data" / "maps" / map_name
                jp_map = json.loads((map_dir / "map.json").read_text(encoding="utf-8"))
                us_map = json.loads(
                    (us_root / "data" / "maps" / map_name / "map.json").read_text(
                        encoding="utf-8"))
                rendered = self.render_events(map_name)
                for jp_entry, generated_line in zip(jp_entries, generated_lines):
                    self.assertIn(jp_entry, jp_map[event_key])
                    self.assertNotIn(jp_entry, us_map[event_key])
                    self.assertIn(generated_line.encode(), rendered)


if __name__ == "__main__":
    unittest.main()
