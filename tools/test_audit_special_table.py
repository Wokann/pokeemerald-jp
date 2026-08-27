#!/usr/bin/env python3
"""Regression checks for ``audit_special_table.py``."""

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_special_table as audit


class SpecialTableAuditTests(unittest.TestCase):
    def make_root(self, root: Path, *, legacy: bool = False, generator: bool = False) -> None:
        table = root / "data/specials.inc"
        table.parent.mkdir(parents=True)
        table.write_text("\tdef_special First\n\tdef_special Second, waitstate=1\n", encoding="utf-8")
        macro = root / "asm/macros/event.inc"
        macro.parent.mkdir(parents=True)
        macro.write_text('\t.include "data/specials.inc"\n', encoding="utf-8")
        if legacy:
            path = root / "constants/specials_constants.inc"
            path.parent.mkdir(parents=True)
            path.write_text(".equ SPECIAL_First, 0\n", encoding="utf-8")
            verifier = root / "tools/verify.py"
            verifier.parent.mkdir(parents=True)
            verifier.write_text('include = "constants/specials_constants.inc"\n', encoding="utf-8")
        if generator:
            path = root / "tools/gen_special_constants.py"
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("# obsolete generator\n", encoding="utf-8")

    def test_single_owner_reports_canonical_table_and_references(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            self.make_root(root)
            report = audit.table_report(root)
        self.assertEqual(report["special_count"], 2)
        self.assertEqual(report["canonical_reference_sites"], ["asm/macros/event.inc:1"])
        self.assertTrue(report["single_owner"])

    def test_legacy_file_reference_and_generator_block_single_owner(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            self.make_root(root, legacy=True, generator=True)
            report = audit.table_report(root)
        self.assertFalse(report["single_owner"])
        self.assertTrue(report["legacy_constants_exists"])
        self.assertEqual(report["legacy_reference_sites"], ["tools/verify.py:1"])
        self.assertEqual(report["legacy_generator_paths"], ["tools/gen_special_constants.py"])

    def test_report_is_deterministic(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            self.make_root(root)
            first = audit.build_report(root, root)
            second = audit.build_report(root, root)
        self.assertEqual(first, second)

    def test_naming_manifest_uses_address_funcmap_and_never_auto_names_us_index(self):
        with tempfile.TemporaryDirectory() as temporary:
            jp_root = Path(temporary) / "jp"
            us_root = Path(temporary) / "us"
            self.make_root(jp_root)
            self.make_root(us_root)
            (jp_root / "data/specials.inc").write_text(
                "\tdef_special sub_08000000\n"
                "\t.set SPECIAL_SetDecoration, SPECIAL_sub_08000000\n"
                "\tdef_special sub_08000004\n"
                "\tdef_special sub_08000008\n"
                "\tdef_special sub_0800000C\n", encoding="utf-8")
            (us_root / "data/specials.inc").write_text(
                "\tdef_special UpstreamOnly\n"
                "\tdef_special SetDecoration\n", encoding="utf-8")
            (jp_root / "funcmap_jp.txt").write_text(
                "08000000 decoration.s sub_08000000 SetDecoration\n"
                "08000004 manual.s sub_08000004_jp\n"
                "0800000C other.c OtherCurrent CandidateOnly\n", encoding="utf-8")
            source = jp_root / "src/decoration.c"
            source.parent.mkdir(parents=True)
            source.write_text("void SetDecoration(void) {}\n", encoding="utf-8")
            script = jp_root / "data/scripts/calls.inc"
            script.parent.mkdir(parents=True)
            script.write_text("\tspecial sub_08000004\n", encoding="utf-8")
            report = audit.special_naming_report(jp_root, us_root)
        records = {record["jp_name"]: record for record in report["records"]}
        self.assertEqual(records["sub_08000000"]["category"], "safe_rename")
        self.assertEqual(records["sub_08000000"]["recommended_name"], "SetDecoration")
        self.assertEqual(records["sub_08000000"]["source_owner"], "decoration.s")
        self.assertEqual(records["sub_08000000"]["special_aliases"], ["SPECIAL_SetDecoration"])
        self.assertTrue(records["sub_08000000"]["master_def_is_raw"])
        self.assertEqual(records["sub_08000004"]["source_owner"], "manual.s")
        self.assertEqual(records["sub_08000004"]["explicit_call_count"], 1)
        self.assertEqual(records["sub_08000004"]["category"], "manual_semantic_review")
        self.assertEqual(records["sub_08000008"]["category"], "insufficient_evidence")
        self.assertEqual(records["sub_08000008"]["us_same_index_name"], None)
        self.assertEqual(records["sub_0800000C"]["category"], "address_candidate_requires_semantic_review")
        self.assertIsNone(records["sub_0800000C"]["recommended_name"])
        self.assertEqual(report["table_counts"], {"jp": 4, "us": 2})
        self.assertEqual(report["summary"]["funcmap_address_candidates"], 2)
        self.assertEqual(report["safe_rename_batches"][0]["specials"], ["sub_08000000"])


if __name__ == "__main__":
    unittest.main()
