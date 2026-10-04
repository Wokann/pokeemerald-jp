#!/usr/bin/env python3
"""Regression checks for ``audit_structure.py``."""

import json
import os
import struct
import sys
import tempfile
import unittest
from unittest import mock
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_structure as audit


def elf_fixture(symbols):
    """Minimal real ELF32 symbol table, including STT_FILE/local/global rows."""
    strings = bytearray(b"\0")
    table = bytearray(16)
    for name, address, info, section in symbols:
        offset = len(strings)
        strings.extend(name.encode("utf-8") + b"\0")
        table.extend(struct.pack("<IIIBBH", offset, address, 0, info, 0, section))
    code_offset = 52
    string_offset = code_offset + 0x100
    table_offset = string_offset + len(strings)
    sections_offset = table_offset + len(table)
    header = struct.pack("<16sHHIIIIIHHHHHH", b"\x7fELF\x01\x01" + bytes(10),
                         2, 40, 1, 0x08000101, 0, sections_offset, 0, 52,
                         0, 0, 40, 4, 0)
    sections = [
        (0,) * 10,
        (0, 1, 6, 0x08000100, code_offset, 0x100, 0, 0, 4, 0),
        (0, 3, 0, 0, string_offset, len(strings), 0, 0, 1, 0),
        (0, 2, 0, 0, table_offset, len(table), 2, 1, 4, 16),
    ]
    return header + bytes(0x100) + strings + table + b"".join(
        struct.pack("<10I", *section) for section in sections)


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

    def test_unowned_static_names_do_not_fan_out_without_linked_evidence(self):
        definitions = [audit.FunctionDef("one.c", "SharedStatic", False),
                       audit.FunctionDef("two.c", "SharedStatic", True)]
        entries = [audit.FuncmapEntry(0x08000100, None, "SharedStatic", "SharedStatic"),
                   audit.FuncmapEntry(0x08000110, None, "SharedStatic", "SharedStatic")]
        resolved, ambiguous = audit.resolve_funcmap_entries(definitions, entries)
        self.assertEqual(resolved, {})
        linked = {("SharedStatic", 0x08000100): {"one.c"},
                  ("SharedStatic", 0x08000110): {"two.c"}}
        resolved, ambiguous = audit.resolve_funcmap_entries(definitions, entries, linked)
        self.assertEqual(ambiguous, [])
        self.assertEqual([entry.address for entry in resolved[definitions[0]]], [0x08000100])
        self.assertEqual([entry.address for entry in resolved[definitions[1]]], [0x08000110])
        diagnostic = audit.legacy_binding_audit(definitions, entries, linked, resolved)
        self.assertEqual(diagnostic["legacy_name_fanout"]["natural_strict_naked_overlap"], 2)
        self.assertEqual(diagnostic["verified_owner_bindings"]["natural_strict_naked_overlap"], 0)
        self.assertEqual(diagnostic["rejected_assignment_counts"], {"confirmed_wrong_owner": 2})

    def test_swapped_current_standard_aliases_bind_by_actual_jp_name_address(self):
        definitions = [audit.FunctionDef("decompress.c", "Handle", False),
                       audit.FunctionDef("decompress.c", "Handle_2", True)]
        entries = [audit.FuncmapEntry(0x08000100, None, "Handle", "Handle_2"),
                   audit.FuncmapEntry(0x08000110, None, "Handle_2", "Handle")]
        linked = {("Handle", 0x08000100): {"decompress.c"},
                  ("Handle_2", 0x08000110): {"decompress.c"}}
        resolved, _ = audit.resolve_funcmap_entries(definitions, entries, linked)
        self.assertEqual([entry.address for entry in resolved[definitions[0]]], [0x08000100])
        self.assertEqual([entry.address for entry in resolved[definitions[1]]], [0x08000110])
        diagnostic = audit.legacy_binding_audit(definitions, entries, linked, resolved)
        self.assertEqual(diagnostic["rejected_assignment_counts"], {"confirmed_wrong_address": 2})

    def test_verified_jp_address_does_not_require_a_current_funcmap_alias_name(self):
        definition = audit.FunctionDef("one.c", "NewJpName", False)
        entry = audit.FuncmapEntry(0x08000100, None, "sub_08000100", "UsCandidate")
        resolved, _ = audit.resolve_funcmap_entries(
            [definition], [entry], {("NewJpName", 0x08000100): {"one.c"}})
        self.assertEqual(resolved, {definition: [entry]})

    def test_missing_or_conflicting_evidence_remains_unresolved(self):
        definition = audit.FunctionDef("one.c", "Known", False)
        entry = audit.FuncmapEntry(0x08000100, "one.s", "Known", "Known")
        for linked in ({}, {("Known", 0x08000100): {"one.c", "two.c"}}):
            resolved, _ = audit.resolve_funcmap_entries([definition], [entry], linked)
            self.assertEqual(resolved, {})
        diagnostic = audit.legacy_binding_audit([definition], [entry], {}, {})
        self.assertEqual(diagnostic["rejected_assignment_counts"], {"evidence_gap": 1})

    def test_same_source_same_name_multiple_addresses_are_not_silently_bound(self):
        definition = audit.FunctionDef("one.c", "Shared", False)
        entries = [audit.FuncmapEntry(address, None, "Shared", "Shared")
                   for address in (0x08000100, 0x08000110)]
        linked = {("Shared", entry.address): {"one.c"} for entry in entries}
        resolved, ambiguous = audit.resolve_funcmap_entries([definition], entries, linked)
        self.assertEqual(resolved, {})
        self.assertEqual(ambiguous, ["one.c:Shared"])

    def test_funcmap_source_owner_uses_full_path_not_basename(self):
        definition = audit.FunctionDef("libc/one.c", "Shared", False)
        self.assertTrue(audit.source_matches_definition("asm/libc/one.s", definition))
        self.assertFalse(audit.source_matches_definition("asm/other/one.s", definition))

    def test_same_address_alias_rows_preserve_conflicting_standard_names(self):
        definition = audit.FunctionDef("one.c", "Jp", False)
        entries = [audit.FuncmapEntry(0x08000100, None, "Jp", standard)
                   for standard in ("First", "Second")]
        resolved, _ = audit.resolve_funcmap_entries(
            [definition], entries, {("Jp", 0x08000100): {"one.c"}})
        self.assertEqual(set(resolved[definition]), set(entries))
        manifest = audit.module_manifest([definition], {}, set(), resolved, set())
        item = manifest[0]["unmatched_functions"][0]
        self.assertIsNone(item["us_standard_name"])
        self.assertEqual(item["us_standard_names"], ["First", "Second"])
        self.assertEqual(item["classification"], "ambiguous_us_standard_names")

    def test_elf_file_context_is_local_only_and_thumb_addresses_are_canonical(self):
        symbols = audit.elf_code_symbols(elf_fixture([
            ("one.c", 0, 4, 0xFFF1), ("Shared", 0x08000101, 2, 1),
            ("two.c", 0, 4, 0xFFF1), ("Shared", 0x08000111, 2, 1),
            ("Global", 0x08000121, 0x12, 1),
            ("AbsoluteAlias", 0x08000121, 0x12, 0xFFF1),
        ]))
        self.assertEqual(symbols, [("Global", 0x08000120, None),
                                   ("Shared", 0x08000100, "one.c"),
                                   ("Shared", 0x08000110, "two.c")])

    def test_linker_ranges_keep_nested_source_paths_and_exclude_data(self):
        ranges = audit.linker_code_ranges(
            " .text 0x08000100 0x10 src/libc/one.o\n"
            " .text.extra\n 0x08000110 0x4 build/jp/src/two.o\n"
            " .rodata 0x08000114 0x4 src/three.o\n"
            " .text 0x00000000 0x0 src/discarded.o\n")
        self.assertEqual(ranges, [(0x08000100, 0x08000110, "libc/one.c"),
                                  (0x08000110, 0x08000114, "two.c")])

    def test_linked_evidence_joins_real_elf_local_global_and_input_ranges(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            for name in ("one", "two"):
                (root / "src" / (name + ".c")).write_text("void Shared(void) {}\n")
            definitions = [audit.FunctionDef("one.c", "Shared", False),
                           audit.FunctionDef("two.c", "Shared", True),
                           audit.FunctionDef("one.c", "Global", False)]
            (root / "pokeemerald_jp.map").write_text(
                " .text 0x08000100 0x10 src/one.o\n"
                " .text 0x08000110 0x10 src/two.o\n"
                " .text.more 0x08000120 0x10 src/one.o\n")
            (root / "pokeemerald_jp.elf").write_bytes(elf_fixture([
                ("one.c", 0, 4, 0xFFF1), ("Shared", 0x08000101, 2, 1),
                ("two.c", 0, 4, 0xFFF1), ("Shared", 0x08000111, 2, 1),
                ("Global", 0x08000121, 0x12, 1),
            ]))
            linked, metadata = audit.linked_function_evidence(root, definitions)
            self.assertEqual(linked, {("Shared", 0x08000100): {"one.c"},
                                      ("Shared", 0x08000110): {"two.c"},
                                      ("Global", 0x08000120): {"one.c"}})
            self.assertEqual(metadata["status"], "available")
            (root / "pokeemerald_jp.map").unlink()
            self.assertEqual(audit.linked_function_evidence(root, definitions)[0], {})

    def test_conflicting_object_ranges_and_local_file_context_reject_bindings(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            for name in ("one", "two"):
                (root / "src" / (name + ".c")).write_text("void Shared(void) {}\n")
            definitions = [audit.FunctionDef("one.c", "Shared", False),
                           audit.FunctionDef("two.c", "Shared", False)]
            (root / "pokeemerald_jp.elf").write_bytes(elf_fixture([
                ("two.c", 0, 4, 0xFFF1), ("Shared", 0x08000101, 2, 1)]))
            (root / "pokeemerald_jp.map").write_text(" .text 0x08000100 0x10 src/one.o\n")
            linked, metadata = audit.linked_function_evidence(root, definitions)
            self.assertEqual(linked, {})
            self.assertEqual(metadata["owner_conflicts"], 1)
            (root / "pokeemerald_jp.map").write_text(
                " .text 0x08000100 0x10 src/one.o\n"
                " .text 0x08000100 0x10 src/two.o\n")
            self.assertEqual(audit.linked_function_evidence(root, definitions)[0], {})

    def test_source_newer_than_elf_is_not_bound_as_a_verified_build(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            source = root / "src" / "one.c"
            source.write_text("void Shared(void) {}\n")
            (root / "pokeemerald_jp.map").write_text(" .text 0x08000100 0x10 src/one.o\n")
            elf = root / "pokeemerald_jp.elf"
            elf.write_bytes(elf_fixture([("Shared", 0x08000101, 0x12, 1)]))
            newer = elf.stat().st_mtime_ns + 1000000000
            os.utime(source, ns=(newer, newer))
            linked, metadata = audit.linked_function_evidence(
                root, [audit.FunctionDef("one.c", "Shared", False)])
            self.assertEqual(linked, {})
            self.assertEqual(metadata["stale_source_owners"], ["one.c"])

    def test_missing_and_invalid_elf_are_explicit_not_name_only_fallbacks(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            self.assertEqual(audit.linked_function_evidence(root, [])[1]["reason"], "missing_jp_elf")
            (root / "pokeemerald_jp.elf").write_bytes(b"not an ELF")
            linked, metadata = audit.linked_function_evidence(root, [])
            self.assertEqual(linked, {})
            self.assertEqual(metadata["status"], "unavailable")
            self.assertIn("ELF32", metadata["reason"])
        self.assertEqual(audit.percentage(None), "unavailable")

    def test_path_only_inventory_is_not_the_semantic_gap_manifest(self):
        definitions = [audit.FunctionDef("exclusive.c", "Plain", False),
                       audit.FunctionDef("same.c", "NoUsCounterpart", False)]
        resolved = {definition: [audit.FuncmapEntry(0x08000100 + index * 4, None,
                                                   definition.name, definition.name)]
                    for index, definition in enumerate(definitions)}
        paths = audit.path_only_c_manifest(
            {"src/exclusive.c", "src/same.c", "src/data_wrapper.c"}, {"src/same.c"},
            definitions, resolved)
        self.assertEqual([item["path"] for item in paths], ["src/data_wrapper.c", "src/exclusive.c"])
        self.assertEqual(paths[0]["address_binding_status"], "no_function_definitions")
        gaps = audit.module_manifest(definitions, {}, set(), resolved, set())
        self.assertEqual([item["path"] for item in gaps], ["exclusive.c", "same.c"])

    def test_path_manifest_cli_is_explicit_and_rejects_markdown(self):
        with tempfile.TemporaryDirectory() as temporary:
            destination = Path(temporary) / "paths.json"
            report = {"jp_path_only_c_manifest": [{"path": "src/exclusive.c"}]}
            with mock.patch.object(sys, "argv", ["audit_structure.py", "--json",
                                                  "--jp-path-manifest", str(destination)]), \
                 mock.patch.object(audit, "build_report", return_value=report):
                audit.main()
            self.assertEqual(json.loads(destination.read_text()), report["jp_path_only_c_manifest"])
            with mock.patch.object(sys, "argv", ["audit_structure.py", "--jp-path-manifest",
                                                  str(destination.with_suffix(".md"))]), \
                 mock.patch.object(audit, "build_report") as build:
                with self.assertRaises(SystemExit):
                    audit.main()
            self.assertFalse(build.called)

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

    def test_incbin_reports_visible_baserom_byte_ranges(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "data" / "raw.s"
            source.parent.mkdir()
            source.write_text(
                '.incbin "baserom_jp.gba", 0x10, 0x20\n'
                '.incbin "baserom_jp.gba"\n',
                encoding="utf-8",
            )
            report = audit.incbin_progress(root)
        self.assertEqual(report["raw_baserom_visible_range_references"], 1)
        self.assertEqual(report["raw_baserom_visible_bytes"], 0x20)
        self.assertEqual(report["raw_baserom_unbounded_references"], 1)
        self.assertEqual(report["raw_baserom_manifest"][0]["owner"], "data/raw.s")

    def test_incbin_named_encoded_asset_is_not_reported_as_raw(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "assets.c"
            source.parent.mkdir()
            source.write_text(
                'INCBIN_U32("graphics/title_screen/pokemon_logo.8bpp.lz")\n'
                'INCBIN_U8("data/gUnknown_123456.lz")\n'
                'INCBIN_U8("graphics/misc/gUnknown_123456.4bpp.lz")\n',
                encoding="utf-8",
            )
            encoded_asset = root / "graphics" / "title_screen" / "pokemon_logo.8bpp.lz"
            encoded_asset.parent.mkdir(parents=True)
            encoded_asset.write_bytes(b"asset")
            raw_stream = root / "data" / "gUnknown_123456.lz"
            raw_stream.parent.mkdir()
            raw_stream.write_bytes(b"raw")
            anonymous_asset = root / "graphics" / "misc" / "gUnknown_123456.4bpp.lz"
            anonymous_asset.parent.mkdir(parents=True)
            anonymous_asset.write_bytes(b"raw")
            report = audit.incbin_progress(root)
        self.assertEqual(report["raw_binary_references"], 2)
        self.assertEqual(report["non_raw_references"], 1)
        self.assertEqual(report["manifest"][0]["classification_reason"], "named_encoded_asset")
        self.assertEqual(report["manifest"][1]["classification"], "raw_binary")
        self.assertEqual(report["manifest"][2]["classification_reason"], "anonymous_encoded_asset")

    def test_incbin_named_tileset_and_declared_layout_assets_are_not_raw(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "data" / "assets.s"
            source.parent.mkdir()
            resources = [
                "data/tilesets/secondary/battle_frontier_outside_west/tiles.4bpp.lz",
                "data/tilesets/secondary/battle_frontier_outside_west/metatiles.bin",
                "data/tilesets/secondary/battle_frontier_outside_west/metatile_attributes.bin",
                "data/layouts/NamedLayout/map.bin",
                "data/layouts/NamedLayout/border.bin",
                "data/layouts/UndeclaredLayout/map.bin",
                "data/data_b2d_mid26.bin",
                "data/tilesets/secondary/gUnknownOwner/tiles.4bpp.lz",
                "graphics/unknown_owner/tiles.4bpp.lz",
            ]
            source.write_text(
                "".join(f'.incbin \"{resource}\"\n' for resource in resources),
                encoding="utf-8",
            )
            for resource in resources:
                path = root / resource
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(b"asset")
            layouts = root / "data" / "layouts" / "layouts.json"
            layouts.write_text(
                '{"layouts": [{"blockdata_filepath": "data/layouts/NamedLayout/map.bin", '
                '"border_filepath": "data/layouts/NamedLayout/border.bin"}, '
                '{"blockdata_filepath": "data/data_b2d_mid26.bin"}]}',
                encoding="utf-8",
            )
            report = audit.incbin_progress(root)
        self.assertEqual(report["raw_binary_references"], 4)
        self.assertEqual(report["non_raw_references"], 5)
        reasons = {item["resource"]: item["classification_reason"]
                   for item in report["manifest"]}
        self.assertEqual(reasons[resources[0]], "named_tileset_resource")
        self.assertEqual(reasons[resources[1]], "named_tileset_resource")
        self.assertEqual(reasons[resources[2]], "named_tileset_resource")
        self.assertEqual(reasons[resources[3]], "declared_layout_resource")
        self.assertEqual(reasons[resources[4]], "declared_layout_resource")
        self.assertEqual(reasons[resources[5]], "raw_suffix_or_container")
        self.assertEqual(reasons[resources[6]], "raw_suffix_or_container")
        self.assertEqual(reasons[resources[7]], "raw_suffix_or_container")
        self.assertEqual(reasons[resources[8]], "anonymous_encoded_asset")

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
            (map_dir / "map.json").write_text('{"id":"MAP_INCLUDED"}', encoding="utf-8")
            (map_dir / "scripts.inc").write_text("", encoding="utf-8")
            (map_dir / "events.inc").write_text("", encoding="utf-8")
            (map_dir / "header.inc").write_text(
                '\t.4byte NULL\n'
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

    def test_map_convergence_prefers_final_map_events_stream(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            map_dir = root / "data/maps/FinalOwner"
            map_dir.mkdir(parents=True)
            (map_dir / "map.json").write_text('{"id":"MAP_FINAL_OWNER"}', encoding="utf-8")
            (map_dir / "scripts.inc").write_text("", encoding="utf-8")
            (map_dir / "events.inc").write_text("", encoding="utf-8")
            (map_dir / "header.inc").write_text(
                '\t.4byte NULL\n'
                '\t.4byte FinalOwner_MapEvents\n'
                '\t.4byte FinalOwner_MapScripts\n'
                '\t.4byte NULL\n', encoding="utf-8")
            (root / "data/event_scripts.s").write_text(
                '.include "data/maps/FinalOwner/scripts.inc"\n', encoding="utf-8")
            (root / "data/maps/events.inc").write_text(
                '.include "data/maps/FinalOwner/events.inc"\n', encoding="utf-8")
            (root / "data/map_events.s").write_text(
                '.include "data/maps/events.inc"\n', encoding="utf-8")
            (root / "data/data_b2d_mid26.s").write_text(
                '@ historical container after event-owner migration\n', encoding="utf-8")
            (root / "data/maps.s").write_text(
                '@ MAP_FINAL_OWNER (g1 m2)\n'
                '.include "data/maps/FinalOwner/header.inc"\n', encoding="utf-8")
            progress = audit.map_convergence_progress(root)
            artifacts = audit.map_artifact_progress(root, progress["records"])
        self.assertEqual(progress["stream_files"]["events"], "data/map_events.s")
        self.assertEqual(progress["event_stream_maps"], 1)
        self.assertEqual(progress["maps_in_both_streams"], 1)
        self.assertEqual(progress["records"][0]["name"], "FinalOwner")
        self.assertEqual(artifacts["upper_event_includes"], 1)
        self.assertEqual(artifacts["direct_structure_complete_maps"], 1)

    def test_map_convergence_inlines_map_header_aggregate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            map_dir = root / "data/maps/Aggregated"
            map_dir.mkdir(parents=True)
            (map_dir / "map.json").write_text(
                '{"id":"MAP_AGGREGATED","name":"Aggregated"}', encoding="utf-8")
            (map_dir / "scripts.inc").write_text("", encoding="utf-8")
            (map_dir / "events.inc").write_text("", encoding="utf-8")
            (map_dir / "header.inc").write_text(
                'Aggregated:\n'
                '\t.4byte NULL\n'
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

    def test_map_convergence_accepts_declared_shared_map_owners(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "data/maps").mkdir(parents=True)
            headers = []

            def add_map(name, map_id, events, scripts, *, shared_events=None,
                        shared_scripts=None, event_file=False, script_file=False):
                directory = root / "data/maps" / name
                directory.mkdir()
                payload = {"id": map_id, "name": name, "layout": None}
                if shared_events:
                    payload["shared_events_map"] = shared_events
                if shared_scripts:
                    payload["shared_scripts_map"] = shared_scripts
                (directory / "map.json").write_text(json.dumps(payload), encoding="utf-8")
                if event_file:
                    (directory / "events.inc").write_text(f"{events}::\n", encoding="utf-8")
                if script_file:
                    (directory / "scripts.inc").write_text(f"{scripts}::\n", encoding="utf-8")
                headers.extend([
                    f"@ {map_id} (g1 m{len(headers) // 5})",
                    "\t.4byte NULL", f"\t.4byte {events}",
                    f"\t.4byte {scripts}", "\t.4byte NULL",
                ])

            add_map("ContestHall", "MAP_CONTEST_HALL", "ContestHall_MapEvents",
                    "ContestHall_MapScripts", event_file=True, script_file=True)
            add_map("ContestHallBeauty", "MAP_CONTEST_HALL_BEAUTY", "ContestHall_MapEvents",
                    "ContestHall_MapScripts", shared_events="ContestHall",
                    shared_scripts="ContestHall")
            add_map("BattlePyramidSquare01", "MAP_BATTLE_PYRAMID_SQUARE01",
                    "BattlePyramidSquare01_MapEvents", "BattlePyramidSquare01_MapScripts",
                    event_file=True, script_file=True)
            add_map("BattlePyramidSquare02", "MAP_BATTLE_PYRAMID_SQUARE02",
                    "BattlePyramidSquare02_MapEvents", "BattlePyramidSquare01_MapScripts",
                    shared_scripts="BattlePyramidSquare01", event_file=True)
            add_map("SecretBase_BlueCave1", "MAP_SECRET_BASE_BLUE_CAVE1",
                    "SecretBase_BlueCave1_MapEvents", "SecretBase_MapScripts",
                    shared_scripts="SecretBase", event_file=True)
            (root / "data/event_scripts.s").write_text(
                '.include "data/maps/ContestHall/scripts.inc"\n'
                '.include "data/maps/BattlePyramidSquare01/scripts.inc"\n'
                '.include "data/scripts/shared_secret_base.inc"\n', encoding="utf-8")
            (root / "data/data_b2d_mid26.s").write_text(
                '.include "data/maps/ContestHall/events.inc"\n'
                '.include "data/maps/BattlePyramidSquare01/events.inc"\n'
                '.include "data/maps/BattlePyramidSquare02/events.inc"\n'
                '.include "data/maps/SecretBase_BlueCave1/events.inc"\n', encoding="utf-8")
            (root / "data/maps.s").write_text("\n".join(headers) + "\n", encoding="utf-8")
            shared = root / "data/scripts/shared_secret_base.inc"
            shared.parent.mkdir(parents=True)
            shared.write_text("SecretBase_MapScripts::\n", encoding="utf-8")

            convergence = audit.map_convergence_progress(root)
            records = {record["name"]: record for record in convergence["records"]}
            artifacts = audit.map_artifact_progress(root, convergence["records"])

        contest = records["ContestHallBeauty"]
        self.assertEqual(contest["events"]["status"], "shared")
        self.assertEqual(contest["scripts"]["status"], "shared")
        self.assertEqual(contest["events"]["shared_target"], "ContestHall_MapEvents")
        self.assertNotIn("create_or_recover_scripts_inc", contest["required_actions"])
        self.assertNotIn("restore_upper_events_include", contest["required_actions"])
        self.assertTrue(contest["structure"]["complete"])
        self.assertEqual(records["BattlePyramidSquare02"]["scripts"]["status"], "shared")
        self.assertEqual(records["BattlePyramidSquare02"]["events"]["status"], "direct")
        self.assertEqual(records["SecretBase_BlueCave1"]["scripts"]["shared_target"],
                         "SecretBase_MapScripts")
        self.assertEqual(artifacts["structure_complete_maps"], 5)
        self.assertEqual(artifacts["shared_scripts_maps"], 3)
        self.assertEqual(artifacts["shared_events_maps"], 1)

    def test_map_convergence_rejects_shared_owner_without_source_label(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            directory = root / "data/maps/Child"
            directory.mkdir(parents=True)
            (directory / "map.json").write_text(
                '{"id":"MAP_CHILD","shared_scripts_map":"Missing"}', encoding="utf-8")
            (root / "data/event_scripts.s").write_text("", encoding="utf-8")
            (root / "data/data_b2d_mid26.s").write_text("", encoding="utf-8")
            (root / "data/maps.s").write_text(
                "@ MAP_CHILD (g1 m1)\n\t.4byte NULL\n\t.4byte NULL\n"
                "\t.4byte Missing_MapScripts\n\t.4byte NULL\n", encoding="utf-8")
            record = audit.map_convergence_progress(root)["records"][0]
        self.assertEqual(record["scripts"]["status"], "shared_or_other")
        self.assertIn("create_or_recover_scripts_inc", record["required_actions"])

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
