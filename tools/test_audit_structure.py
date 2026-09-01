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

    def test_map_structure_is_not_semantic_review(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            complete = root / "data/maps/Complete"
            partial = root / "data/maps/Partial"
            complete.mkdir(parents=True)
            partial.mkdir(parents=True)
            for name in ("map.json", "scripts.inc", "events.inc"):
                (complete / name).write_text("", encoding="utf-8")
            for name in ("map.json", "scripts.inc"):
                (partial / name).write_text("", encoding="utf-8")
            (root / "data").mkdir(exist_ok=True)
            (root / "data/maps.s").write_text(
                '.include "data/maps/Complete/events.inc"\n', encoding="utf-8")
            progress = audit.map_artifact_progress(root)
        self.assertEqual(progress["structure_complete_maps"], 1)
        self.assertEqual(progress["structure_complete_map_names"], ["Complete"])
        self.assertEqual(progress["semantic_review"]["status"], "not_recorded")
        self.assertEqual(progress["semantic_review"]["reviewed_map_names"], [])

    def test_map_headers_keeps_direct_header_fields(self):
        headers = audit.map_headers(
            "@ MAP_DIRECT (g1 m2)\n"
            "\t.4byte gMapLayout_Direct @ mapLayout\n"
            "\t.4byte Direct_MapEvents @ events\n"
            "\t.4byte Direct_MapScripts @ mapScripts\n"
            "\t.4byte NULL @ connections\n"
        )
        self.assertEqual(headers["MAP_DIRECT"], {
            "id": "MAP_DIRECT", "group": 1, "number": 2,
            "mapLayout": "gMapLayout_Direct", "events": "Direct_MapEvents",
            "mapScripts": "Direct_MapScripts", "connections": "NULL",
        })

    def test_map_convergence_inlines_map_header_include(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            map_dir = root / "data/maps/Included"
            map_dir.mkdir(parents=True)
            (map_dir / "map.json").write_text(
                '{"id":"MAP_INCLUDED","layout":"LAYOUT_INCLUDED"}', encoding="utf-8")
            (map_dir / "scripts.inc").write_text("", encoding="utf-8")
            (map_dir / "events.inc").write_text("", encoding="utf-8")
            (map_dir / "header.inc").write_text(
                '\t.4byte gMapLayout_INCLUDED\n'
                '\t.4byte Included_MapEvents\n'
                '\t.4byte Included_MapScripts\n'
                '\t.4byte NULL\n', encoding="utf-8")
            (root / "data/event_scripts.s").write_text(
                '.include "data/maps/Included/scripts.inc"\n', encoding="utf-8")
            (root / "data/data_b2d_mid26.s").write_text(
                '.include "data/maps/Included/events.inc"\n', encoding="utf-8")
            (root / "data/maps.s").write_text(
                '@ MAP_INCLUDED (g1 m2)\n'
                '.include "data/maps/Included/header.inc"\n', encoding="utf-8")
            progress = audit.map_convergence_progress(root)
        record = progress["records"][0]
        self.assertEqual(progress["header_records"], 1)
        self.assertEqual(record["events"]["status"], "direct")
        self.assertEqual(record["scripts"]["status"], "direct")
        self.assertEqual(record["layout"]["status"], "direct")

    def test_map_convergence_inlines_map_header_aggregate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            map_dir = root / "data/maps/Aggregated"
            map_dir.mkdir(parents=True)
            (map_dir / "map.json").write_text(
                '{"id":"MAP_AGGREGATED","name":"Aggregated","layout":"LAYOUT_AGGREGATED"}',
                encoding="utf-8")
            (map_dir / "scripts.inc").write_text("", encoding="utf-8")
            (map_dir / "events.inc").write_text("", encoding="utf-8")
            (map_dir / "header.inc").write_text(
                'Aggregated:\n'
                '\t.4byte gMapLayout_AGGREGATED\n'
                '\t.4byte Aggregated_MapEvents\n'
                '\t.4byte Aggregated_MapScripts\n'
                '\t.4byte NULL\n', encoding="utf-8")
            (root / "data/maps/headers.inc").write_text(
                '.include "data/maps/Aggregated/header.inc"\n', encoding="utf-8")
            (root / "data/event_scripts.s").write_text(
                '.include "data/maps/Aggregated/scripts.inc"\n', encoding="utf-8")
            (root / "data/data_b2d_mid26.s").write_text(
                '.include "data/maps/Aggregated/events.inc"\n', encoding="utf-8")
            (root / "data/maps.s").write_text(
                '.include "data/maps/headers.inc"\n', encoding="utf-8")
            progress = audit.map_convergence_progress(root)
        record = progress["records"][0]
        self.assertEqual(progress["header_records"], 1)
        self.assertEqual(record["events"]["status"], "direct")
        self.assertEqual(record["scripts"]["status"], "direct")
        self.assertEqual(record["layout"]["status"], "direct")

    def test_map_convergence_accepts_canonical_layout_label(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            map_dir = root / "data/maps/Underwater_Route124"
            map_dir.mkdir(parents=True)
            (map_dir / "map.json").write_text(
                '{"id":"MAP_UNDERWATER_ROUTE124","layout":"LAYOUT_UNDERWATER_ROUTE124"}',
                encoding="utf-8")
            (map_dir / "scripts.inc").write_text("", encoding="utf-8")
            (map_dir / "events.inc").write_text("", encoding="utf-8")
            (map_dir / "header.inc").write_text(
                '\t.4byte Underwater_Route124_Layout\n'
                '\t.4byte Underwater_Route124_MapEvents\n'
                '\t.4byte Underwater_Route124_MapScripts\n'
                '\t.4byte NULL\n', encoding="utf-8")
            (root / "data/event_scripts.s").write_text(
                '.include "data/maps/Underwater_Route124/scripts.inc"\n', encoding="utf-8")
            (root / "data/data_b2d_mid26.s").write_text(
                '.include "data/maps/Underwater_Route124/events.inc"\n', encoding="utf-8")
            (root / "data/maps.s").write_text(
                '@ MAP_UNDERWATER_ROUTE124 (g1 m2)\n'
                '.include "data/maps/Underwater_Route124/header.inc"\n', encoding="utf-8")
            layouts_dir = root / "data/layouts"
            layouts_dir.mkdir(parents=True)
            (layouts_dir / "layouts.inc").write_text(
                'Underwater_Route124_Layout::\n'
                '\t.4byte 80 @ width\n', encoding="utf-8")
            progress = audit.map_convergence_progress(root)
        record = progress["records"][0]
        self.assertEqual(record["layout"]["expected"], "Underwater_Route124_Layout")
        self.assertEqual(record["layout"]["status"], "direct")
        self.assertTrue(record["layout"]["resource_chain"]["layout_defined"])

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

    def test_script_data_parsers_preserve_owner_order_and_linked_ranges(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            linker = root / "ld_script_jp.txt"
            linker.write_text(
                "script_data :\nALIGN(4)\n{\n"
                "    data/event_scripts.o(script_data);\n"
                "    data/mystery_event_script_cmd_table.o(script_data);\n"
                "} =0\n",
                encoding="utf-8",
            )
            link_map = root / "pokeemerald_jp.map"
            link_map.write_text(
                "script_data     0x08100000    0x44\n"
                " data/event_scripts.o(script_data)\n"
                " script_data    0x08100000    0x20 data/event_scripts.o\n"
                " data/mystery_event_script_cmd_table.o(script_data)\n"
                " script_data    0x08100020    0x24 data/mystery_event_script_cmd_table.o\n"
                "lib_text        0x08100044    0x4\n",
                encoding="utf-8",
            )
            self.assertEqual(audit.parse_script_data_linker_objects(linker), [
                "data/event_scripts.o", "data/mystery_event_script_cmd_table.o",
            ])
            parsed = audit.parse_script_data_map(link_map)
        self.assertEqual(parsed["section"], {
            "start": "0x08100000", "size": "0x44", "end": "0x08100044",
        })
        self.assertEqual(parsed["objects"], [
            {"owner": "data/event_scripts.o", "start": "0x08100000", "size": "0x20",
             "end": "0x08100020"},
            {"owner": "data/mystery_event_script_cmd_table.o", "start": "0x08100020",
             "size": "0x24", "end": "0x08100044"},
        ])

    def test_script_data_progress_requires_jp_terminal_evidence_for_split(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary) / "jp"
            us_root = Path(temporary) / "us"
            (root / "data").mkdir(parents=True)
            us_root.mkdir()
            (root / "ld_script_jp.txt").write_text(
                "script_data :\n{\n    data/event_scripts.o(script_data);\n} =0\n",
                encoding="utf-8",
            )
            (us_root / "ld_script.ld").write_text(
                "script_data :\n{\n"
                "    data/event_scripts.o(script_data);\n"
                "    data/mystery_event_script_cmd_table.o(script_data);\n"
                "} > ROM =0\n",
                encoding="utf-8",
            )
            (root / "pokeemerald_jp.map").write_text(
                "script_data     0x08100000    0x44\n"
                " data/event_scripts.o(script_data)\n"
                " script_data    0x08100000    0x44 data/event_scripts.o\n"
                "                0x08100000                gMysteryEventScriptCmdTable\n"
                "                0x08100044                gMysteryEventScriptCmdTableEnd\n",
                encoding="utf-8",
            )
            (us_root / "pokeemerald.map").write_text(
                "script_data     0x08200000    0x44\n"
                " data/event_scripts.o(script_data)\n"
                " script_data    0x08200000    0x20 data/event_scripts.o\n"
                " data/mystery_event_script_cmd_table.o(script_data)\n"
                " script_data    0x08200020    0x24 data/mystery_event_script_cmd_table.o\n",
                encoding="utf-8",
            )
            (root / "data/event_scripts.s").write_text(
                '.incbin "baserom_jp.gba", 0x100000, 0x44\n', encoding="utf-8")
            progress = audit.script_data_progress(root, us_root)
            (root / "ld_script_jp.txt").write_text(
                "script_data :\n{\n"
                "    data/event_scripts.o(script_data);\n"
                "    data/mystery_event_script_cmd_table.o(script_data);\n"
                "} =0\n",
                encoding="utf-8",
            )
            (root / "pokeemerald_jp.map").write_text(
                "script_data     0x08100000    0x44\n"
                " data/event_scripts.o(script_data)\n"
                " script_data    0x08100000    0x0 data/event_scripts.o\n"
                " data/mystery_event_script_cmd_table.o(script_data)\n"
                " script_data    0x08100000    0x44 data/mystery_event_script_cmd_table.o\n"
                "                0x08100000                gMysteryEventScriptCmdTable\n"
                "                0x08100044                gMysteryEventScriptCmdTableEnd\n",
                encoding="utf-8",
            )
            linked_progress = audit.script_data_progress(root, us_root)
        candidate = progress["candidate_splits"][0]
        self.assertEqual(progress["linker"]["missing_jp_owners"],
                         ["data/mystery_event_script_cmd_table.o"])
        self.assertEqual(candidate["status"], "ready_for_zero_displacement_owner_split")
        self.assertTrue(candidate["terminal_section_range"])
        self.assertEqual(candidate["size"], "0x44")
        self.assertEqual(progress["event_scripts_raw_baserom_ranges"][0]["rom_start"], "0x08100000")
        self.assertEqual(progress["method"]["us_role"], "owner_order_and_source_structure_only")
        self.assertEqual(linked_progress["candidate_splits"][0]["status"], "linked_as_named_owner")

    def test_top_level_raw_eventscript_manifest_keeps_map_candidates_separate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary) / "jp"
            us_root = Path(temporary) / "us"
            for directory in (root / "data/maps/Missing", us_root / "data/maps/Missing"):
                directory.mkdir(parents=True)
            (root / "data/maps/Missing/map.json").write_text("{}", encoding="utf-8")
            (us_root / "data/maps/Missing/scripts.inc").write_text("", encoding="utf-8")
            (us_root / "data/maps/Missing/events.inc").write_text("", encoding="utf-8")
            jp_text = (
                '.include "data/maps/Before/scripts.inc"\n'
                '.incbin "baserom_jp.gba", 0x100, 0x4\n'
                '.incbin "baserom_jp.gba", 0x104, 0x2\n'
                '.include "data/maps/After/scripts.inc"\n'
                '.incbin "baserom_jp.gba", 0x200, 0x2\n')
            us_text = (
                '.include "data/maps/Before/scripts.inc"\n'
                '.include "data/maps/Missing/scripts.inc"\n'
                '.include "data/maps/After/scripts.inc"\n')
            manifest = audit.top_level_event_script_raw_manifest(
                root, us_root, jp_text, us_text, ["data/event_scripts.o"])
        first = manifest["raw_ranges"][0]
        self.assertEqual(first["previous_include"]["path"], "data/maps/Before/scripts.inc")
        self.assertEqual(first["next_include"]["path"], "data/maps/After/scripts.inc")
        self.assertEqual(first["map_owner_classification"], "single_us_map_owner_candidate")
        self.assertEqual(first["us_map_owner_candidates"][0]["name"], "Missing")
        self.assertTrue(first["us_map_owner_candidates"][0]["jp_artifacts"]["map_json"])
        self.assertFalse(first["us_map_owner_candidates"][0]["jp_artifacts"]["scripts_inc"])
        self.assertEqual(first["owner_status"], "top_level_raw_unstructured")
        self.assertEqual(first["us_script_data_owner"], "data/event_scripts.o")
        self.assertEqual(manifest["raw_runs"][0], {
            "rom_start": "0x08000100", "rom_end": "0x08000106", "size": "0x6",
            "raw_range_lines": [2, 3], "owner_status": "top_level_raw_unstructured",
        })
        self.assertEqual(manifest["first_unstructured_raw_run"], manifest["raw_runs"][0])
        self.assertEqual(manifest["raw_ranges"][2]["map_owner_classification"],
                         "missing_jp_map_anchor")

    def test_markdown_report_contains_snapshot_definitions_and_reproduction(self):
        report = audit.build_report(audit.ROOT, audit.DEFAULT_US_ROOT)
        rendered = audit.render_markdown_report(report)
        self.assertIn("# 可复现结构审计进度", rendered)
        self.assertIn("## 当前快照", rendered)
        self.assertIn("## 指标定义", rendered)
        self.assertIn("--markdown-output DECOMP_PROGRESS.md", rendered)
        self.assertIn("--output` 只写 JSON", rendered)
        self.assertIn("同名 static 按 source owner 和地址保留", rendered)
        self.assertIn("地图语义复核：not_recorded", rendered)
        self.assertIn("transition-manifest", rendered)
        self.assertIn("script-data-manifest", rendered)

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

    def test_transition_manifest_cli_output_is_json(self):
        report = audit.build_report(audit.ROOT, audit.DEFAULT_US_ROOT)
        with tempfile.TemporaryDirectory() as temporary:
            destination = Path(temporary) / "transition.json"
            with mock.patch.object(sys, "argv", ["audit_structure.py", "--transition-manifest", str(destination)]), \
                 mock.patch.object(audit, "build_report", return_value=report):
                audit.main()
            rendered = destination.read_text(encoding="utf-8")
        self.assertIn('"categories"', rendered)

    def test_script_data_manifest_cli_output_is_json(self):
        report = {"script_data": {"candidate_splits": []}}
        with tempfile.TemporaryDirectory() as temporary:
            destination = Path(temporary) / "script-data.json"
            with mock.patch.object(sys, "argv", ["audit_structure.py", "--json", "--script-data-manifest", str(destination)]), \
                 mock.patch.object(audit, "build_report", return_value=report):
                audit.main()
            rendered = destination.read_text(encoding="utf-8")
        self.assertIn('"candidate_splits"', rendered)

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
