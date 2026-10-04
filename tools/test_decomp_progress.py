#!/usr/bin/env python3
"""Compatibility and explicit-unit tests for the source inventory CLI."""

import contextlib
import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))
import decomp_progress as progress


class ProgressInventoryTests(unittest.TestCase):
    def make_roots(self, temporary):
        root, us = Path(temporary) / "jp", Path(temporary) / "us"
        (root / "src").mkdir(parents=True)
        (us / "src").mkdir(parents=True)
        (root / "asm/nested").mkdir(parents=True)
        (root / "src/one.c").write_text(
            "#ifndef NONMATCHING\nNAKED\nvoid Pick(void) { asm(\"\"); }\n"
            "#else\nvoid Pick(void) {}\n#endif\nstatic inline void Inline(void) {}\n")
        (us / "src/one.c").write_text("void Pick(void) {}\n")
        (root / "asm/one.s").write_text("thumb_func_start Shared\n")
        (root / "asm/two.s").write_text("thumb_func_start Shared\n")
        (root / "asm/nested/three.s").write_text("arm_func_start Extra\n")
        return root, us

    def test_source_only_preserves_legacy_unit_and_does_not_read_build_artifacts(self):
        with tempfile.TemporaryDirectory() as temporary:
            root, us = self.make_roots(temporary)
            with mock.patch.object(progress.audit, "linked_function_evidence", side_effect=AssertionError("source-only")):
                first = progress.inventory_report(root, us)
                second = progress.inventory_report(root, us)
        self.assertEqual(first, second)
        legacy = first["legacy_source_inventory"]
        self.assertEqual(legacy["unit"], "source-name")
        self.assertEqual((legacy["jp_c_definitions"], legacy["standalone_jp_asm_functions"]), (1, 1))
        source = first["default_source_inventory"]
        self.assertEqual((source["non_naked"], source["naked"], source["inline"], source["standalone_asm"]), (1, 1, 1, 3))
        self.assertIsNone(source["inline_not_emitted"])
        self.assertIsNone(first["jp_address_metrics"]["strict_c_rate"])

    def test_missing_linked_inputs_are_unavailable_not_a_completion_ratio(self):
        with tempfile.TemporaryDirectory() as temporary:
            root, us = self.make_roots(temporary)
            report = progress.inventory_report(root, us, linked=True)
        self.assertEqual(report["jp_address_metrics"]["metric_status"], "unavailable")
        self.assertIsNone(report["jp_address_metrics"]["strict_c_rate"])
        self.assertEqual(report["jp_address_metrics"]["binding_evidence"]["reason"], "missing_jp_elf")

    def test_missing_us_root_hard_fails_before_reporting(self):
        with tempfile.TemporaryDirectory() as temporary:
            missing = Path(temporary) / "missing"
            with self.assertRaisesRegex(ValueError, "missing src/"):
                progress.inventory_report(Path(temporary), missing)
            with mock.patch.object(sys, "argv", ["decomp_progress.py", "--us-root", str(missing)]), \
                 mock.patch.object(progress, "inventory_report") as build, \
                 contextlib.redirect_stderr(io.StringIO()):
                with self.assertRaises(SystemExit):
                    progress.main()
                self.assertFalse(build.called)

    def test_json_and_legacy_human_footer_are_explicit_and_compatible(self):
        with tempfile.TemporaryDirectory() as temporary:
            root, us = self.make_roots(temporary)
            for arguments in (["--json"], []):
                output = io.StringIO()
                with mock.patch.object(progress, "ROOT", root), \
                     mock.patch.object(sys, "argv", ["decomp_progress.py", "--us-root", str(us), *arguments]), \
                     contextlib.redirect_stdout(output):
                    progress.main()
                if arguments:
                    self.assertEqual(json.loads(output.getvalue())["legacy_source_inventory"]["unit"], "source-name")
                else:
                    lines = output.getvalue().splitlines()
                    self.assertTrue(lines[-3].startswith("Standalone JP asm functions:"))
                    self.assertTrue(lines[-2].startswith("C source definitions:"))
                    self.assertTrue(lines[-1].startswith("C source inventory:"))
                    self.assertIn("NOT ROM completion", lines[-1])


if __name__ == "__main__":
    unittest.main()
