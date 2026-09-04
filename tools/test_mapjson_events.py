#!/usr/bin/env python3
"""Regression checks for mapjson's event-only output mode."""

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


if __name__ == "__main__":
    unittest.main()
