#!/usr/bin/env python3
"""Regression tests for the map-script label-order audit."""

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_map_label_alignment as audit


class MapLabelAlignmentTests(unittest.TestCase):
    def test_labels_include_local_and_global_without_addresses_or_strings(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "scripts.inc"
            path.write_text(
                "@ Header: not a label\n"
                "MapScripts:: @ 0x081DB7E8\n"
                "\t.string \"A: B$\"\n"
                "LocalScript:\n",
                encoding="utf-8",
            )
            self.assertEqual(audit.labels(path), ["MapScripts", "LocalScript"])

    def test_expected_extra_label_preserves_shared_order(self):
        known = {"Map": {"jp_only": {"JPExtra"}, "us_only": set(), "reason": "ROM byte"}}
        result = audit.compare_lists("Map", ["A", "JPExtra", "B"], ["A", "B"], known)
        self.assertEqual(result["status"], "known_difference")
        self.assertTrue(result["common_order_matches"])

    def test_reordered_or_unknown_labels_require_review(self):
        known = {"Map": {"jp_only": {"JPExtra"}, "us_only": set(), "reason": "ROM byte"}}
        self.assertEqual(
            audit.compare_lists("Map", ["B", "JPExtra", "A"], ["A", "B"], known)["status"],
            "needs_review",
        )
        self.assertEqual(
            audit.compare_lists("Map", ["A", "Other"], ["A", "B"], known)["status"],
            "needs_review",
        )

    def test_current_repository_has_only_recorded_label_differences(self):
        if not (audit.US_ROOT / "data/maps").is_dir():
            self.skipTest("US comparison tree is unavailable")
        result = audit.report(audit.JP_ROOT, audit.US_ROOT)
        self.assertGreater(result["compared_maps"], 400)
        self.assertEqual(result["counts"]["needs_review"], 0)
        self.assertEqual(result["counts"]["known_difference"], 4)
        self.assertEqual(result["jp_maps_without_us"], [])
        self.assertEqual(result["us_maps_without_jp"], [])


if __name__ == "__main__":
    unittest.main()
