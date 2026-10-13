#!/usr/bin/env python3
"""ROM-free regressions for explicit multi-object C compilation inventories."""
import hashlib
import os
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_structure as audit
from test_audit_structure import elf_fixture, object_fixture


class CompileVariantTests(unittest.TestCase):
    SOURCE = (
        "#ifndef EXTRA\nvoid Main(void) {}\n#else\nvoid Tail(void) {}\n#endif\n"
    )
    RECIPE = (
        "\t@$(CPP) $(CPPFLAGS) -P -x c $< | "
        "$(or $(CC1),$(CC)) $(CFLAGS) -o - - > $@.gen.s\n"
        "\t@$(AS) $(ASFLAGS) -o $@ - < $@.gen.s\n"
    )

    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        (self.root / "src").mkdir()
        (self.root / "src/one.c").write_text(self.SOURCE)
        self.make()

    def make(self, flags="-DEXTRA", prerequisite="src/one.c", recipe=None):
        text = (
            "$(C_BUILDDIR)/tail.o: CPPFLAGS += " + flags + "\n"
            "$(C_BUILDDIR)/tail.o: " + prerequisite + "\n"
            + (self.RECIPE if recipe is None else recipe)
        )
        (self.root / "Makefile").write_text(text)
        return text

    def linked(self, *, object_name="Tail", object_info=0x12,
               object_section=".text", object_offset=1, with_object=True,
               map_name="src/tail.o", tail_info=0x12):
        if with_object:
            (self.root / "src/tail.o").write_bytes(object_fixture(
                object_name, object_section, info=object_info, offset=object_offset))
        (self.root / "pokeemerald_jp.map").write_text(
            " .text 0x08000100 0x20 src/one.o\n"
            f" .text 0x08000120 0x20 {map_name}\n")
        (self.root / "pokeemerald_jp.elf").write_bytes(elf_fixture([
            ("Main", 0x08000101, 0x12, 1),
            (object_name, 0x08000121, tail_info, 1),
        ]))
        definitions = audit.c_inventory(self.root)
        linked, metadata = audit.linked_function_evidence(self.root, definitions)
        entries = [
            audit.FuncmapEntry(0x08000100, None, "Main", "Main"),
            audit.FuncmapEntry(0x08000120, None, "OldTail", "Tail"),
        ]
        resolved, multiple = audit.resolve_funcmap_entries(definitions, entries, linked)
        result = audit.function_binding_inventory(
            definitions, entries, linked, metadata, resolved, multiple)
        return definitions, linked, metadata, result

    def test_explicit_defines_preserve_offsets_and_select_only_the_actual_branch(self):
        source = "#if MODE == 2\nvoid Two(void) {}\n#else\nvoid Other(void) {}\n#endif\n"
        selected = audit.active_preprocessor_text(source, defines={"MODE": 2})
        self.assertEqual(len(selected), len(source))
        self.assertEqual(selected.count("\n"), source.count("\n"))
        self.assertIn("void Two", selected)
        self.assertNotIn("void Other", selected)
        self.assertNotIn("void Two", audit.active_preprocessor_text(source))

    def test_variant_metadata_requires_literal_rule_and_recipe(self):
        variants = audit.c_compile_variants(self.root)
        self.assertEqual(variants, [{
            "source_owner": "one.c", "object_owner": "tail.c",
            "input_object": "src/tail.o", "defines": {"EXTRA": 1},
            "makefile_sha256": hashlib.sha256((self.root / "Makefile").read_bytes()).hexdigest(),
        }])
        self.make(recipe="")
        self.assertEqual(audit.c_compile_variants(self.root), [])

    def test_shared_definitions_are_not_counted_per_compilation_mode(self):
        (self.root / "src/one.c").write_text(
            "void Common(void) {}\n" + self.SOURCE
            + "#ifdef NONMATCHING\nvoid Unselected(void) {}\n#endif\n")
        definitions = audit.c_inventory(self.root)
        self.assertEqual([d.name for d in definitions], ["Common", "Main", "Tail"])
        self.assertTrue(all(not d.naked for d in definitions))
        self.assertEqual(dict(definitions[-1].name_inputs).keys(), {"Makefile"})

    def test_default_duplicate_definitions_are_not_silently_removed(self):
        (self.root / "src/one.c").write_text("void Main(void) {}\nvoid Main(void) {}\n")
        self.assertEqual(len(audit.c_inventory(self.root)), 2)

    def test_integer_defines_include_zero_and_hex_without_make_expansion(self):
        self.make(flags="-DEXTRA -DZERO=0 -DMODE=0x2")
        self.assertEqual(audit.c_compile_variants(self.root)[0]["defines"],
                         {"EXTRA": 1, "MODE": 2, "ZERO": 0})

    def test_unsupported_flags_and_conflicting_assignments_are_rejected(self):
        for flags in ("-DEXTRA -I include", "-UEXTRA", "-DEXTRA=OTHER",
                      "$(EXTRA_FLAGS)", "-DEXTRA=1 -DEXTRA=2"):
            with self.subTest(flags=flags):
                self.make(flags=flags)
                self.assertEqual(audit.c_compile_variants(self.root), [])
        self.make()
        with (self.root / "Makefile").open("a") as stream:
            stream.write("$(C_BUILDDIR)/tail.o: CPPFLAGS := -DEXTRA\n")
        self.assertEqual(audit.c_compile_variants(self.root), [])

    def test_conditional_rules_are_not_guessed_as_selected(self):
        text = self.make()
        (self.root / "Makefile").write_text("ifdef OPTIONAL\n" + text + "endif\n")
        self.assertEqual(audit.c_compile_variants(self.root), [])
        (self.root / "Makefile").write_text(
            text + "ifdef OPTIONAL\n$(C_BUILDDIR)/tail.o: CPPFLAGS += -DOTHER\nendif\n")
        self.assertEqual(audit.c_compile_variants(self.root), [])

    def test_missing_ambiguous_nonfirst_or_escaping_sources_are_rejected(self):
        (self.root / "src/two.c").write_text("void Other(void) {}\n")
        for prerequisite in ("src/missing.c", "src/one.c src/two.c",
                             "$(CHOSEN_SOURCE) src/one.c", "src/../one.c"):
            with self.subTest(prerequisite=prerequisite):
                self.make(prerequisite=prerequisite)
                self.assertEqual(audit.c_compile_variants(self.root), [])
        with tempfile.TemporaryDirectory() as outside:
            external = Path(outside) / "external.c"
            external.write_text("void External(void) {}\n")
            (self.root / "src/external.c").symlink_to(external)
            self.make(prerequisite="src/external.c")
            self.assertEqual(audit.c_compile_variants(self.root), [])

    def test_built_variant_has_real_source_owner_and_exact_object_evidence(self):
        definitions, linked, metadata, result = self.linked()
        self.assertEqual([d.name for d in definitions], ["Main", "Tail"])
        self.assertEqual(linked, {
            ("Main", 0x08000100): {"one.c"}, ("Tail", 0x08000120): {"one.c"},
        })
        self.assertEqual(result["strict_c_addresses"], 2)
        self.assertEqual(result["unresolved_bindings"], [])
        self.assertIn("src/tail.o", metadata["inputs"]["input_objects"])
        self.assertEqual(metadata["owner_conflicts"], 0)

    def test_variant_without_elf_or_map_is_not_address_evidence(self):
        definitions = audit.c_inventory(self.root)
        linked, metadata = audit.linked_function_evidence(self.root, definitions)
        self.assertEqual(linked, {})
        self.assertEqual(metadata["reason"], "missing_jp_elf")
        _definitions, linked, _metadata, result = self.linked()
        (self.root / "pokeemerald_jp.map").unlink()
        linked, metadata = audit.linked_function_evidence(
            self.root, audit.c_inventory(self.root))
        self.assertEqual(linked, {})
        self.assertEqual(metadata["reason"], "missing_jp_link_map")

    def test_missing_nontyped_wrong_section_offset_or_owner_cannot_bind_tail(self):
        cases = (
            {"with_object": False}, {"object_info": 0x10},
            {"object_section": ".iwram"}, {"object_offset": 5},
            {"map_name": "src/unrelated_tail.o"},
        )
        for options in cases:
            with self.subTest(options=options):
                obj = self.root / "src/tail.o"
                obj.unlink(missing_ok=True)
                _definitions, linked, _metadata, result = self.linked(**options)
                self.assertNotIn(("Tail", 0x08000120), linked)
                self.assertEqual(result["strict_c_addresses"], 1)

    def test_make_or_object_newer_than_elf_invalidates_variant_evidence(self):
        for path in ("Makefile", "src/tail.o"):
            with self.subTest(path=path):
                _definitions, _linked, _metadata, _result = self.linked()
                newer = (self.root / "pokeemerald_jp.elf").stat().st_mtime_ns + 1_000_000_000
                os.utime(self.root / path, ns=(newer, newer))
                linked, metadata = audit.linked_function_evidence(
                    self.root, audit.c_inventory(self.root))
                self.assertNotIn(("Tail", 0x08000120), linked)
                if path == "Makefile":
                    self.assertIn("one.c", metadata["stale_source_owners"])
                    self.make()
                else:
                    self.assertEqual(metadata["input_object_errors"]["src/tail.o"],
                                     "input_object_newer_than_elf")

    def test_asm_link_name_is_selected_in_variant_and_bound_to_typed_jp_symbol(self):
        (self.root / "src/one.c").write_text(
            "#ifndef EXTRA\nvoid Main(void) {}\n#else\n"
            'void Tail(void) __asm__("RawTail");\nvoid Tail(void) {}\n#endif\n')
        definitions, linked, metadata, result = self.linked(object_name="RawTail")
        self.assertEqual((definitions[-1].name, definitions[-1].link_name), ("Tail", "RawTail"))
        self.assertIn(("Tail", 0x08000120), linked)
        self.assertEqual(result["strict_c_addresses"], 2)
        self.assertEqual(metadata["asm_link_name_bindings"][0]["link_name"], "RawTail")

    def test_naked_variant_is_not_promoted_by_an_inactive_c_body(self):
        (self.root / "src/one.c").write_text(
            "#ifndef EXTRA\nvoid Main(void) {}\n#else\n"
            "#ifndef NONMATCHING\nNAKED\nvoid Tail(void) { asm(\"bx lr\"); }\n"
            "#else\nvoid Tail(void) {}\n#endif\n#endif\n")
        definitions, _linked, _metadata, result = self.linked()
        self.assertEqual([(d.name, d.naked) for d in definitions],
                         [("Main", False), ("Tail", True)])
        self.assertEqual((result["strict_c_addresses"], result["naked_assembly_addresses"]), (1, 1))


if __name__ == "__main__":
    unittest.main()
