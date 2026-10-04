#!/usr/bin/env python3
"""Coverage/negative regressions for recursive EventScript text audits."""
import json
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_script_text_sources as audit
from jp_script_text import CHARMAP_PATH, PREPROC_PATH, JapaneseScriptTextCodec

A = 0x08000020
B = 0x08000040


class RecursiveTextAuditTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.codec = JapaneseScriptTextCodec()

    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.put("charmap.txt", CHARMAP_PATH.read_text(encoding="utf-8"))
        self.put("asm/macros/event.inc", ".macro brailleformat a:req, b:req, c:req, d:req, e:req, f:req\n"
                 ".byte \\a\n.byte \\b\n.byte \\c\n.byte \\d\n.byte \\e\n.byte \\f\n.endm\n")
        self.put("data/event_scripts.s", "")
        (self.root / "baserom_jp.gba").write_bytes(bytes(256))
        self.encoded = {"あ$": b"\x01\xFF", "い$": b"\x02\xFF",
                        "あ": b"\x01", "$": b"\xFF",
                        r"あ\nい$": b"\x01\xFE\x02\xFF",
                        "{PAUSE}あ$": b"\xFC\x08\x01\xFF"}

    def put(self, path, content):
        target = self.root / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(content, encoding="utf-8")
        return target

    def rom(self, offset, raw):
        path = self.root / "baserom_jp.gba"
        data = bytearray(path.read_bytes())
        data[offset:offset + len(raw)] = raw
        path.write_bytes(data)

    def report(self, symbols=None):
        return audit.build_report(
            self.root, symbols=symbols or {}, codec=self.codec,
            encoder=lambda kind, source: (
                b"\x01\x08\xFE\x1F\xFF" if kind == "braille" else self.encoded[source]
            ),
        )

    def assert_passes(self, report, objects=1):
        self.assertEqual(report["summary"]["verified_objects"], objects)
        self.assertEqual(report["findings"], [])
        self.assertFalse(audit.report_failed(report))
        self.assertEqual(report["semantic_review"], "not_recorded")

    def test_legacy_parent_address_and_pure_string_child(self):
        self.put("data/event_scripts.s", 'OldOwner: @ 0x08000020\n'
                 '.include "data/scripts/old.inc"\n')
        self.put("data/scripts/old.inc", '.string "あ"\n.string "$"\n')
        self.rom(0x20, b"\x01\xFF")
        result = self.report()
        self.assert_passes(result)
        self.assertEqual(result["objects"][0]["path"], "data/scripts/old.inc")
        self.assertEqual(result["objects"][0]["label"], "OldOwner")

    def test_modern_internal_double_colon_and_local_labels_from_linked_symbols(self):
        self.put("data/event_scripts.s", '.include "data/maps/Test/scripts.inc"\n')
        self.put("data/maps/Test/scripts.inc", "Test_MapScripts::\n.byte 0\n"
                 "Test_EventScript::\nend\nTest_Movement:\nstep_end\n"
                 'Test_Text_First::\n.string "あ$"\nTest_Text_Second:\n.string "い$"\n')
        self.rom(0x20, b"\x01\xFF")
        self.rom(0x40, b"\x02\xFF")
        result = self.report({"Test_Text_First": {A}, "Test_Text_Second": {B}})
        self.assert_passes(result, 2)
        self.assertEqual(result["summary"]["text_blocks"], 2)
        self.assertEqual([x["label"] for x in result["objects"]],
                         ["Test_Text_First", "Test_Text_Second"])

    def test_recursive_include_continues_a_fragmented_text_object(self):
        self.put("data/event_scripts.s", '.include "data/scripts/first.inc"\n')
        self.put("data/scripts/first.inc", 'Text:: @ 0x08000020\n'
                 '.string "あ"\n.include "data/text/tail.inc"\n')
        self.put("data/text/tail.inc", '.string "$"\n')
        self.rom(0x20, b"\x01\xFF")
        result = self.report()
        self.assert_passes(result)
        self.assertEqual(result["summary"]["source_files"], 3)
        self.assertEqual(result["summary"]["text_directives"], 2)

    def test_zero_coverage_is_a_failure_even_with_no_text_directives(self):
        self.put("data/event_scripts.s", "Script:: @ 0x08000020\nend\n"
                 "Movement:: @ 0x08000040\nstep_end\n")
        result = self.report()
        self.assertEqual(result["summary"]["verified_objects"], 0)
        self.assertTrue(audit.report_failed(result))
        self.assertIn("zero_coverage", [x.get("category") for x in result["findings"]])

    def test_missing_label_address_is_reported_not_skipped(self):
        self.put("data/event_scripts.s", 'Text::\n.string "あ$"\n')
        result = self.report()
        self.assertEqual(result["summary"]["uncovered_blocks"], 1)
        self.assertTrue(audit.report_failed(result))
        self.assertIn("no linked symbol", result["findings"][0]["reason"])

    def test_annotation_link_disagreement_and_same_name_multiple_addresses_fail(self):
        self.put("data/event_scripts.s", 'Text:: @ 0x08000020\n.string "あ$"\n')
        for symbols in ({"Text": {B}}, {"Text": {A, B}}):
            with self.subTest(symbols=symbols):
                result = self.report(symbols)
                self.assertTrue(audit.report_failed(result))
                self.assertIn("conflicting/ambiguous", result["findings"][0]["reason"])

    def test_mismatch_and_unterminated_text_fail(self):
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ$"\n')
        result = self.report()
        self.assertEqual(result["summary"]["mismatched_objects"], 1)
        self.assertTrue(audit.report_failed(result))
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ"\n')
        result = self.report()
        self.assertIn("unterminated text", result["findings"][0]["reason"])
        self.assertTrue(audit.report_failed(result))

    def test_partial_coverage_always_fails(self):
        self.put("data/event_scripts.s", 'Good: @ 0x08000020\n.string "あ$"\n'
                 'Missing::\n.string "い$"\n')
        self.rom(0x20, b"\x01\xFF")
        result = self.report()
        self.assertEqual(result["summary"]["verified_objects"], 1)
        self.assertEqual(result["summary"]["uncovered_blocks"], 1)
        self.assertTrue(audit.report_failed(result))

    def test_instructions_before_text_are_not_a_text_address_anchor(self):
        self.put("data/event_scripts.s", 'Movement:: @ 0x08000020\nstep_end\n.string "あ$"\n')
        self.rom(0x20, b"\x01\xFF")
        result = self.report()
        self.assertTrue(audit.report_failed(result))
        self.assertIn("non-text bytes", result["findings"][0]["reason"])

    def test_padding_after_eos_does_not_become_part_of_the_previous_text(self):
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ$"\n'
                 '.byte 0 @ next-owner padding\n')
        self.rom(0x20, b"\x01\xFF")
        result = self.report()
        self.assert_passes(result)
        self.assertEqual(result["objects"][0]["end"], A + 2)

    def test_unanchored_text_after_other_bytes_is_not_hidden(self):
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ$"\n'
                 '.byte 0\n.string "い$"\n')
        self.rom(0x20, b"\x01\xFF")
        result = self.report()
        self.assertEqual(result["summary"]["verified_objects"], 1)
        self.assertEqual(result["summary"]["uncovered_blocks"], 1)
        self.assertTrue(audit.report_failed(result))

    def test_multiple_eos_are_reported_as_separate_objects(self):
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ$"\n.string "い$"\n')
        self.rom(0x20, b"\x01\xFF\x02\xFF")
        result = self.report()
        self.assert_passes(result, 2)
        self.assertEqual([x["start"] for x in result["objects"]], [A, A + 2])

    def test_braille_format_header_and_inline_rows_are_verified_separately(self):
        self.put("data/event_scripts.s", 'Braille: @ 0x08000020\n'
                 'brailleformat 4, 6, 26, 13, 7, 9\n.braille "あ\\nい$"\n')
        self.rom(0x20, bytes((4, 6, 26, 13, 7, 9)) + b"\x01\x08\xFE\x1F\xFF")
        result = self.report()
        self.assert_passes(result)
        self.assertEqual(result["objects"][0]["kind"], "braille")
        self.assertEqual(result["objects"][0]["size"], 11)
        self.assertEqual(result["summary"]["inline_line_controls"], 0)

    def test_unknown_braille_header_expression_fails(self):
        self.put("data/event_scripts.s", 'Braille: @ 0x08000020\n'
                 'brailleformat SYMBOL, 6, 26, 13, 7, 9\n.braille "あ$"\n')
        result = self.report()
        self.assertTrue(audit.report_failed(result))
        self.assertIn("explicit byte operands", result["findings"][0]["reason"])

    def test_changed_brailleformat_macro_cannot_silently_pass(self):
        self.put("data/event_scripts.s", 'Braille: @ 0x08000020\n'
                 'brailleformat 4, 6, 26, 13, 7, 9\n.braille "あ$"\n')
        self.rom(0x20, bytes((4, 6, 26, 13, 7, 9)) + b"\x01\x08\xFE\x1F\xFF")
        self.put("asm/macros/event.inc", ".macro brailleformat a:req, b:req, c:req, d:req, e:req, f:req\n"
                 ".byte \\b\n.byte \\a\n.byte \\c\n.byte \\d\n.byte \\e\n.byte \\f\n.endm\n")
        result = self.report()
        self.assertTrue(audit.report_failed(result))
        self.assertIn("unverified brailleformat", result["findings"][0]["reason"])

    def test_missing_and_cyclic_includes_fail_without_unbounded_recursion(self):
        for source in ('.include "data/text/missing.inc"\n',
                       '.include "data/event_scripts.s"\n'):
            with self.subTest(source=source):
                self.put("data/event_scripts.s", source)
                result = self.report()
                self.assertTrue(audit.report_failed(result))
                self.assertTrue(result["findings"])

    def test_unselected_conditional_and_raw_ranges_remain_uncovered(self):
        for source in ('.ifdef UNKNOWN\nText: @ 0x08000020\n.string "あ$"\n.endif\n',
                       '.incbin "baserom_jp.gba", 0x20, 0x2\n'):
            with self.subTest(source=source):
                self.put("data/event_scripts.s", source)
                result = self.report()
                self.assertTrue(audit.report_failed(result))
                self.assertEqual(result["summary"]["verified_objects"], 0)

    def test_strict_modes_and_escaped_literal_line_controls(self):
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ\\nい$"\n')
        self.rom(0x20, b"\x01\xFE\x02\xFF")
        result = self.report()
        self.assertFalse(audit.report_failed(result))
        self.assertTrue(audit.report_failed(result, strict_layout=True))
        self.assertEqual(audit.inline_line_controls([audit.StringLine(1, r"あ\\nい$")]), [])
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "{PAUSE}あ$"\n')
        self.rom(0x20, b"\xFC\x08\x01\xFF")
        result = self.report()
        self.assertFalse(audit.report_failed(result))
        self.assertTrue(audit.report_failed(result, strict_control_syntax=True))

    def test_report_serialization_is_deterministic(self):
        self.put("data/event_scripts.s", 'Text: @ 0x08000020\n.string "あ$"\n')
        self.rom(0x20, b"\x01\xFF")
        self.assertEqual(json.dumps(self.report(), sort_keys=True),
                         json.dumps(self.report(), sort_keys=True))

    def test_text_symbols_accept_exact_map_nm_rows_and_retain_collisions(self):
        path = self.put("symbols.txt", "0x08000020 Text\n08000040 t Text\n"
                        "0x08000050 Alias = 0x08000020\n")
        self.assertEqual(audit.text_symbols(path), {"Text": {A, B}})

    def test_bad_elf_is_rejected_not_treated_as_an_empty_success(self):
        path = self.root / "bad.elf"
        path.write_bytes(b"not an ELF")
        with self.assertRaisesRegex(ValueError, "little-endian ELF"):
            audit.elf_script_symbols(path)

    def test_cli_zero_coverage_returns_failure_with_a_machine_readable_reason(self):
        result = subprocess.run(
            [sys.executable, "-B", str(Path(audit.__file__)),
             "--root", str(self.root), "--json"],
            capture_output=True, text=True,
        )
        self.assertEqual(result.returncode, 1, result.stderr)
        report = json.loads(result.stdout)
        self.assertEqual(report["summary"]["verified_objects"], 0)
        self.assertEqual(report["findings"][-1]["category"], "zero_coverage")

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_selected_root_preproc_reencodes_real_source(self):
        path = self.root / "tools/preproc/preproc"
        path.parent.mkdir(parents=True)
        path.symlink_to(PREPROC_PATH)
        self.assertEqual(audit.source_encoder(self.root)("string", "あ$"), b"\x01\xFF")

    def test_elf_local_global_symbols_are_read_without_name_overwrite(self):
        # Four sections: null, section names, symbol strings, symbol table;
        # a fifth script_data section supplies the real section index.
        names = b"\0.shstrtab\0.strtab\0.symtab\0script_data\0"
        symbols = b"\0Text\0"
        table = bytes(16) + struct.pack("<IIIBBH", 1, A, 0, 0, 0, 4)
        table += struct.pack("<IIIBBH", 1, B, 0, 0x10, 0, 4)
        shoff = 52
        payload = shoff + 5 * 40
        blob = bytearray(payload)
        ident = b"\x7fELF\x01\x01\x01" + bytes(9)
        struct.pack_into("<16sHHIIIIIHHHHHH", blob, 0, ident, 2, 40, 1,
                         0, 0, shoff, 0, 52, 0, 0, 40, 5, 1)
        sections = [
            (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
            (1, 3, 0, 0, payload, len(names), 0, 0, 1, 0),
            (11, 3, 0, 0, payload + len(names), len(symbols), 0, 0, 1, 0),
            (19, 2, 0, 0, payload + len(names) + len(symbols), len(table), 2, 1, 4, 16),
            (27, 1, 0, A, 0, 0, 0, 0, 1, 0),
        ]
        for index, section in enumerate(sections):
            struct.pack_into("<10I", blob, shoff + index * 40, *section)
        blob.extend(names + symbols + table)
        path = self.root / "test.elf"
        path.write_bytes(blob)
        self.assertEqual(audit.elf_script_symbols(path), {"Text": {A, B}})


if __name__ == "__main__":
    unittest.main()
