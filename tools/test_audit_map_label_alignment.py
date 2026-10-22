#!/usr/bin/env python3
"""Regression tests for the map-script label-order audit."""

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_map_label_alignment as audit
from test_audit_us_reference import fixture as reference_fixture, commit as commit_reference


class MapLabelAlignmentTests(unittest.TestCase):
    def test_labels_include_local_and_global_without_addresses_or_strings(self):
        parent = audit.JP_ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='label-alignment-', dir=parent) as temporary:
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

    def test_report_uses_requested_commit_not_dirty_us_labels(self):
        with reference_fixture() as (jp, us, revision):
            for root in (jp, us):
                path = root / 'data/maps/Map/scripts.inc'
                path.parent.mkdir(parents=True)
                path.write_text('Map_MapScripts::\nMap_Entry::\n')
            revision = commit_reference(us)
            (us / 'data/maps/Map/scripts.inc').write_text('Map_Entry::\nMap_MapScripts::\n')
            result = audit.report(jp, us, us_ref=revision)
            self.assertEqual(result['counts']['identical'], 1)
            self.assertEqual(result['counts']['needs_review'], 0)
            self.assertEqual(result['us_reference']['commit'], revision)

    def test_current_repository_has_only_recorded_label_differences(self):
        if not (audit.US_ROOT / "data/maps").is_dir():
            self.skipTest("US comparison tree is unavailable")
        result = audit.report(audit.JP_ROOT, audit.US_ROOT,
                              us_ref='731ad5bfd6e6f265508d0efcca0ba42f9dcf5881')
        self.assertGreater(result["compared_maps"], 400)
        self.assertEqual(result["counts"]["needs_review"], 0)
        self.assertEqual(result["counts"]["known_difference"], 3)
        self.assertEqual(result['us_reference']['mode'], 'git_snapshot')
        self.assertEqual(result["jp_maps_without_us"], [])
        self.assertEqual(result["us_maps_without_jp"], [])


if __name__ == "__main__":
    unittest.main()
