#!/usr/bin/env python3
"""Regression checks for ``audit_structure.py``."""

import sys
import tempfile
import unittest
from unittest import mock
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_structure as audit


class StructureAuditTests(unittest.TestCase):
    def test_naked_definition_is_not_a_strict_c_definition(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "sample.c"
            source.parent.mkdir()
            source.write_text(
                "__attribute__((naked)) void Naked(void) { __asm__(\"\"); }\n"
                "void Plain(void) { }\n",
                encoding="utf-8",
            )
            definitions = audit.function_definitions(source, root)
        self.assertEqual([(item.name, item.naked) for item in definitions],
                         [("Naked", True), ("Plain", False)])

    def test_naked_macro_survives_conditional_signature(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "sample.c"
            source.parent.mkdir()
            source.write_text(
                "NAKED\n#if OLD\nstatic void Conditional(void)\n#else\n"
                "static void Conditional(int value)\n#endif\n{ asm(\"bx lr\"); }\n"
                "static void Plain(void) { }\n",
                encoding="utf-8",
            )
            definitions = audit.function_definitions(source, root)
        self.assertEqual([(item.name, item.naked) for item in definitions],
                         [("Conditional", True), ("Plain", False)])

    def test_default_preprocessor_selects_only_the_naked_nonmatching_branch(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "sample.c"
            source.parent.mkdir()
            source.write_text(
                "#ifndef NONMATCHING\nNAKED\nstatic void Conditional(void)\n"
                "#else\nstatic void Conditional(int value)\n#endif\n{ asm(\"bx lr\"); }\n",
                encoding="utf-8",
            )
            definitions = audit.function_definitions(source, root)
        self.assertEqual([(item.name, item.naked) for item in definitions],
                         [("Conditional", True)])

    def test_known_jp_naked_macro_functions_are_not_strict_c(self):
        expected = {
            ("librfu_intr.c", "Callback_Dummy_M"),
            ("librfu_intr.c", "Callback_Dummy_S"),
            ("librfu_intr.c", "Callback_Dummy_ID"),
            ("multiboot.c", "MultiBootWaitCycles"),
        }
        definitions = {
            (item.path, item.name): item.naked
            for item in audit.c_inventory(audit.ROOT)
            if (item.path, item.name) in expected
        }
        self.assertEqual(definitions, {key: True for key in expected})

    def test_funcmap_aliases_share_one_address(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "funcmap.txt"
            path.write_text("08000000 JpName UsName\n08000000 Alias UsName\n", encoding="utf-8")
            entries, total = audit.parse_funcmap(path)
        self.assertEqual(total, 1)
        self.assertEqual([(entry.current, entry.standard) for entry in entries],
                         [("JpName", "UsName"), ("Alias", "UsName")])

    def test_funcmap_source_prefixed_row_uses_symbol_columns(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "funcmap.txt"
            path.write_text("08000000 module.s Symbol\n08000004 module.s JpName UsName\n",
                            encoding="utf-8")
            entries, total = audit.parse_funcmap(path)
        self.assertEqual(total, 2)
        self.assertEqual([(entry.source, entry.current, entry.standard) for entry in entries],
                         [("module.s", "Symbol", "Symbol"),
                          ("module.s", "JpName", "UsName")])

    def test_funcmap_duplicate_static_names_resolve_by_source_owner(self):
        definitions = [
            audit.FunctionDef("one.c", "SharedStatic", False),
            audit.FunctionDef("two.c", "SharedStatic", False),
        ]
        entries = [
            audit.FuncmapEntry(0x08000000, "one.s", "SharedStatic", "SharedStatic"),
            audit.FuncmapEntry(0x08000004, "two.s", "SharedStatic", "SharedStatic"),
        ]
        resolved, ambiguous = audit.resolve_funcmap_entries(definitions, entries)
        self.assertEqual(ambiguous, [])
        self.assertEqual([entry.address for entry in resolved[definitions[0]]], [0x08000000])
        self.assertEqual([entry.address for entry in resolved[definitions[1]]], [0x08000004])

    def test_manifest_separates_placeholders_and_runtime(self):
        definitions = [
            audit.FunctionDef("module.c", "nullsub_1", False),
            audit.FunctionDef("libc/runtime.c", "RuntimeOnly", False),
        ]
        manifest = audit.module_manifest(
            definitions,
            {},
            set(),
            {
                definitions[0]: [audit.FuncmapEntry(0x08000000, None, "nullsub_1", "nullsub_1")],
                definitions[1]: [audit.FuncmapEntry(0x08000004, None, "RuntimeOnly", "RuntimeOnly")],
            },
            set(),
        )
        self.assertEqual(manifest[0]["category"], "library_or_runtime")
        self.assertEqual(manifest[1]["category"], "placeholder_only")

    def test_manifest_marks_us_binary_only_symbol(self):
        definition = audit.FunctionDef("module.c", "LibrarySymbol", False)
        manifest = audit.module_manifest(
            [definition],
            {},
            {"LibrarySymbol"},
            {definition: [audit.FuncmapEntry(0x08000000, None, "LibrarySymbol", "LibrarySymbol")]},
            set(),
        )
        item = manifest[0]["unmatched_functions"][0]
        self.assertEqual(manifest[0]["category"], "us_binary_only")
        self.assertEqual(item["suggested_action"], "locate_us_non_c_or_symbol_owner")

    def test_incbin_manifest_tracks_owner_and_missing_resource(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "assets.s"
            source.parent.mkdir()
            source.write_text(
                '.incbin "graphics/present.bin"\n'
                'INCBIN_U8("graphics/missing.bin")\n',
                encoding="utf-8",
            )
            asset = root / "graphics" / "present.bin"
            asset.parent.mkdir()
            asset.write_bytes(b"asset")
            report = audit.incbin_progress(root)
        self.assertEqual(report["raw_binary_references"], 2)
        self.assertEqual(report["missing_resource_paths"], 1)
        self.assertEqual(report["manifest"][0]["owner"], "src/assets.s")

    def test_incbin_header_is_a_scanned_source_owner(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            header = root / "src" / "data" / "assets.h"
            header.parent.mkdir(parents=True)
            header.write_text('INCBIN_U8("graphics/header.bin")\n', encoding="utf-8")
            asset = root / "graphics" / "header.bin"
            asset.parent.mkdir()
            asset.write_bytes(b"asset")
            report = audit.incbin_progress(root)
        self.assertEqual(report["references"], 1)
        self.assertEqual(report["manifest"][0]["owner"], "src/data/assets.h")

    def test_asset_naming_reports_a_unique_us_basename_candidate(self):
        incbin = {"manifest": [
            {"resource": "graphics/jp/path/shared.bin"},
            {"resource": "sound/aligned.bin"},
        ]}
        with tempfile.TemporaryDirectory() as temporary:
            us_root = Path(temporary)
            candidate = us_root / "graphics/us/path/shared.bin"
            candidate.parent.mkdir(parents=True)
            candidate.write_bytes(b"asset")
            exact = us_root / "sound/aligned.bin"
            exact.parent.mkdir(parents=True)
            exact.write_bytes(b"asset")
            report = audit.asset_naming_progress(incbin, us_root)
        self.assertEqual(report["unique_us_basename_candidates"], 1)
        self.assertEqual(report["exact_us_paths"], 1)
        self.assertEqual(report["manifest"][0]["us_candidates"], ["graphics/us/path/shared.bin"])

    def test_first_map_owner_names_deduplicates_shared_tables(self):
        entries = [
            (0x08000000, "First", 0, 0, [], None),
            (0x08000000, "Shared", 0, 1, [], None),
            (0x08000010, "Second", 0, 2, [], None),
        ]
        self.assertEqual(audit.first_map_owner_names(entries), {"First", "Second"})

    def test_map_entries_uses_requested_us_root_not_emitter_default(self):
        class FakeEmitter:
            US_JSON = Path("hard-coded.json")
            MAP_NAMES = {"old": "name"}

            @classmethod
            def build_map_names(cls):
                return {"path": cls.US_JSON.name}

            @classmethod
            def map_entries(cls, include_empty=False):
                return [cls.MAP_NAMES, include_empty]

        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            groups = root / "data/maps/map_groups.json"
            groups.parent.mkdir(parents=True)
            groups.write_text("{}", encoding="utf-8")
            result = audit.map_entries_for_us_root(FakeEmitter, root)
        self.assertEqual(result, [{"path": "map_groups.json"}, True])
        self.assertEqual(FakeEmitter.US_JSON, Path("hard-coded.json"))

    def test_markdown_report_contains_snapshot_definitions_and_reproduction(self):
        report = audit.build_report(audit.ROOT, audit.DEFAULT_US_ROOT)
        rendered = audit.render_markdown_report(report)
        self.assertIn("# 可复现结构审计进度", rendered)
        self.assertIn("## 当前快照", rendered)
        self.assertIn("## 指标定义", rendered)
        self.assertIn("--markdown-output DECOMP_PROGRESS.md", rendered)
        self.assertIn("--output` 只写 JSON", rendered)
        self.assertIn("同名 static 按 source owner 和地址保留", rendered)

    def test_json_output_rejects_markdown_destination_without_writing(self):
        with tempfile.TemporaryDirectory() as temporary:
            destination = Path(temporary) / "DECOMP_PROGRESS.md"
            destination.write_text("keep this markdown\n", encoding="utf-8")
            with mock.patch.object(sys, "argv", ["audit_structure.py", "--output", str(destination)]), \
                 mock.patch.object(audit, "build_report") as build:
                with self.assertRaisesRegex(SystemExit, "--markdown-output"):
                    audit.main()
            self.assertFalse(build.called)
            self.assertEqual(destination.read_text(encoding="utf-8"), "keep this markdown\n")

    def test_markdown_cli_output_is_explicit_and_atomic(self):
        report = audit.build_report(audit.ROOT, audit.DEFAULT_US_ROOT)
        with tempfile.TemporaryDirectory() as temporary:
            destination = Path(temporary) / "DECOMP_PROGRESS.md"
            with mock.patch.object(sys, "argv", ["audit_structure.py", "--markdown-output", str(destination)]), \
                 mock.patch.object(audit, "build_report", return_value=report):
                audit.main()
            rendered = destination.read_text(encoding="utf-8")
        self.assertIn("严格 C：", rendered)
        self.assertIn("## 复现与输入", rendered)
        self.assertFalse(list(destination.parent.glob(".DECOMP_PROGRESS.md.*.tmp")))

    def test_transition_manifest_preserves_all_matching_categories(self):
        manifest = audit.transition_manifest({"src/module_mid2_tail.c", "data/gUnknown_8123456.inc"})
        self.assertEqual(manifest[0]["categories"], ["address"])
        self.assertEqual(manifest[1]["categories"], ["tail", "mid"])

    def test_current_report_has_consistent_address_metrics(self):
        report = audit.build_report(audit.ROOT, audit.DEFAULT_US_ROOT)
        functions = report["functions"]
        self.assertLessEqual(functions["strict_c_addresses"],
                             functions["funcmap_unique_addresses"])
        self.assertLessEqual(functions["module_aligned_addresses"],
                             functions["standard_owned_addresses"])
        self.assertLessEqual(functions["standard_owned_addresses"],
                             functions["strict_c_addresses"])
        self.assertEqual(functions["strict_naked_address_overlap"], 0)
        self.assertEqual(report["maps"]["non_owner_scripts_inc"], 0)


if __name__ == "__main__":
    unittest.main()
