#!/usr/bin/env python3
"""Synthetic, ROM-free regressions for conservative owner-review evidence."""
import copy
import io
import json
import subprocess
import sys
import tempfile
import unittest
from contextlib import redirect_stdout
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_map_owner_reviews as audit


class OwnerReviewTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name) / "jp"
        self.us = Path(self.temporary.name) / "us"
        self.root.mkdir()
        self.us.mkdir()
        self.rom = bytes(range(64))  # Synthetic bytes; never extracted ROM.
        (self.root / "baserom_jp.gba").write_bytes(self.rom)
        (self.root / "pokeemerald_jp.gba").write_bytes(self.rom)
        self.script = "data/maps/Example/scripts.inc"
        self.map_json = "data/maps/Example/map.json"
        self.events = "data/maps/Example/events.inc"
        self.write(self.root, self.script, "Example_MapScripts::\n\tend\n")
        self.write(self.us, self.script, "Example_MapScripts::\n\tend\n")
        self.write(self.root, self.map_json, '{"id":"MAP_EXAMPLE"}\n')
        self.write(self.root, self.events, "Example_MapEvents::\n\t.4byte 0\n")
        self.write(self.root, "tools/mapjson/mapjson", "synthetic generator marker\n")
        sources = {path: self.hash(self.root, path)
                   for path in (self.script, self.map_json, self.events)}
        anchors = [{"tree": tree, "path": self.script, "start_line": 1, "end_line": 2}
                   for tree in ("jp", "us")]
        declaration = {"state": "reviewed", "reviewer": "Project reviewer",
                       "summary": "Synthetic scoped comparison", "evidence": anchors}
        self.owner = {
            "id": "map:Example", "jp_sources": sources,
            "us_sources": {self.script: self.hash(self.us, self.script)},
            "dependency_roots": {"jp": list(sources), "us": [self.script]},
            "spans": [{"kind": "script", "start": audit.ROM_BASE,
                       "end": audit.ROM_BASE + 8, "sha256": audit.sha256(self.rom[:8])}],
            "shared_dependencies": [],
            "events": {"map_json": self.map_json, "events_inc": self.events},
            "labels": {"jp": self.script, "us": self.script, "jp_only": [], "us_only": []},
            "manual_review": {**{gate: copy.deepcopy(declaration) for gate in audit.GATES},
                              "unreviewed_text": []},
        }
        self.data = {"schema_version": 1, "rom": {"size": len(self.rom), "sha256": audit.sha256(self.rom)},
                     "owners": [self.owner]}

    def write(self, root, path, text):
        target = root / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(text, encoding="utf-8")

    def hash(self, root, path):
        return audit.sha256((root / path).read_bytes())

    def save(self):
        self.write(self.root, "audits/reviews.json", json.dumps(self.data))
        return "audits/reviews.json"

    def report(self, **kwargs):
        return audit.audit_reviews(self.root, self.us, self.save(),
                                   built_rom_path="pokeemerald_jp.gba", **kwargs)

    def record(self, **kwargs):
        return self.report(**kwargs)["records"][0]

    def cli(self, *options):
        output = io.StringIO()
        with redirect_stdout(output):
            code = audit.main(["--root", str(self.root), "--us-root", str(self.us), "--json", *options])
        return code, output.getvalue()

    def fake_generation(self, argv, **kwargs):
        self.assertEqual(argv[:3], [str(self.root / "tools/mapjson/mapjson"), "events", "emerald"])
        self.assertEqual(Path(argv[3]), self.root / self.map_json)
        self.assertNotIn("shell", kwargs)
        (Path(argv[4]) / "events.inc").write_bytes((self.root / self.events).read_bytes())
        return subprocess.CompletedProcess(argv, 0, b"", b"")

    def test_absent_manifest_is_not_recorded_and_reads_nothing(self):
        with mock.patch.object(audit, "read_project_file", side_effect=AssertionError("unexpected read")):
            report = audit.audit_reviews(self.root, self.us)
        self.assertEqual(report["semantic_review"], "not_recorded")
        self.assertEqual(report["summary"]["reviewed_map_names"], [])
        self.assertEqual(self.cli()[0], 0)
        self.assertEqual(self.cli("--require-current")[0], 1)

    def test_empty_manifest_does_not_infer_completion_from_files(self):
        self.data["owners"] = []
        self.assertEqual(self.report()["semantic_review"], "not_recorded")

    def test_all_executable_checks_pass_but_full_dependency_scope_is_unverified(self):
        with mock.patch.object(audit.subprocess, "run", side_effect=self.fake_generation) as run:
            report = self.report(run_generation=True)
        record = report["records"][0]
        self.assertEqual(run.call_count, 1)
        self.assertEqual(record["status"], "partial")
        self.assertIn("manual_dependency_scope_unverified", record["issues"])
        self.assertIn("source_to_rom_binding_unverified", record["issues"])
        self.assertEqual(record["machine_checks"]["json_events_equal"]["status"], "passed")
        self.assertEqual(record["machine_checks"]["label_order"]["status"], "passed")
        self.assertEqual(record["machine_checks"]["spans"][0]["built_rom_equality"], "passed")
        self.assertTrue(all(x["status"] == "declared_current" for x in record["manual_checks"].values()))
        self.assertEqual(report["summary"]["reviewed_map_names"], [])

    def test_no_generation_is_run_without_explicit_flag(self):
        with mock.patch.object(audit.subprocess, "run", side_effect=AssertionError("unexpected command")):
            record = self.record()
        self.assertEqual(record["machine_checks"]["json_events_equal"]["status"], "not_run")

    def test_source_hash_change_is_stale_and_does_not_refresh_manifest(self):
        path = self.save()
        before = (self.root / path).read_bytes()
        self.write(self.root, self.script, "Example_MapScripts::\n\treturn\n")
        report = audit.audit_reviews(self.root, self.us, path)
        self.assertEqual(report["records"][0]["status"], "stale")
        self.assertEqual(report["records"][0]["manual_checks"]["script_semantics"]["status"], "stale")
        self.assertEqual((self.root / path).read_bytes(), before)

    def test_us_only_change_invalidates_declaration(self):
        self.write(self.us, self.script, "Example_MapScripts::\n\treturn\n")
        self.assertEqual(self.record()["status"], "stale")

    def test_macro_or_charmap_change_invalidates_evidence(self):
        for path in ("asm/macros/event.inc", "charmap.txt"):
            with self.subTest(path=path):
                self.write(self.root, path, "original\n")
                self.owner["jp_sources"][path] = self.hash(self.root, path)
                self.owner["dependency_roots"]["jp"].append(path)
                self.write(self.root, path, "changed\n")
                self.assertEqual(self.record()["status"], "stale")
                self.owner["jp_sources"].pop(path)
                self.owner["dependency_roots"]["jp"].remove(path)

    def test_new_include_without_hash_is_detected_even_if_entry_hash_is_updated(self):
        included = "data/scripts/shared.inc"
        self.write(self.root, self.script, 'Example_MapScripts::\n\t.include "' + included + '"\n')
        self.write(self.root, included, "Shared::\n\tend\n")
        self.owner["jp_sources"][self.script] = self.hash(self.root, self.script)
        record = self.record()
        self.assertIn("jp:unhashed_include:" + included, record["issues"])
        self.assertEqual(record["status"], "partial")

    def test_literal_include_recursion_handles_cycles(self):
        a, b = "data/scripts/a.inc", "data/scripts/b.inc"
        self.write(self.root, a, '\t.include "' + b + '"\n')
        self.write(self.root, b, '\t.include "' + a + '"\n')
        self.assertEqual(audit.discover_includes(self.root, [a]), ([a, b], []))

    def test_conditional_includes_are_not_claimed_as_selected_dependencies(self):
        self.write(self.root, "data/source.c", '#if NONMATCHING\n#include "first.h"\n#else\n#include "second.h"\n#endif\n')
        for name in ("first", "second"):
            self.write(self.root, "include/" + name + ".h", "/* fixture */\n")
        found, issues = audit.discover_includes(self.root, ["data/source.c"])
        self.assertEqual(found, ["data/source.c", "include/first.h", "include/second.h"])
        self.assertEqual(issues, [])

    def test_nonliteral_and_ambiguous_includes_stay_unverified(self):
        self.write(self.root, "src/source.c", '#include CHOSEN_HEADER\n#include "same.h"\n')
        self.write(self.root, "src/same.h", "one\n")
        self.write(self.root, "include/same.h", "two\n")
        _, issues = audit.discover_includes(self.root, ["src/source.c"])
        self.assertIn("nonliteral_include:src/source.c", issues)
        self.assertIn("unresolved_or_ambiguous_include:src/source.c:same.h", issues)

    def test_source_changed_during_generation_is_not_current(self):
        def changing_generator(argv, **kwargs):
            result = self.fake_generation(argv, **kwargs)
            self.write(self.root, self.script, "Example_MapScripts::\n\treturn\n")
            return result
        with mock.patch.object(audit.subprocess, "run", side_effect=changing_generator):
            record = self.record(run_generation=True)
        self.assertEqual(record["status"], "stale")
        self.assertIn("source_snapshot_changed", record["issues"])

    def test_unreviewed_text_blocks_completion(self):
        self.owner["manual_review"]["unreviewed_text"] = ["Example_Text_Unreviewed"]
        record = self.record()
        self.assertIn("unreviewed_text", record["issues"])
        self.assertEqual(record["status"], "partial")

    def test_missing_shared_owner_is_reported_not_assumed_reviewed(self):
        self.owner["shared_dependencies"] = ["shared:Missing"]
        self.assertIn("missing_shared_review:shared:Missing", self.record()["issues"])

    def test_missing_manual_evidence_stays_incomplete(self):
        self.owner["manual_review"]["script_semantics"]["evidence"] = []
        self.assertEqual(self.record()["manual_checks"]["script_semantics"]["status"], "incomplete_evidence")

    def test_out_of_source_line_evidence_cannot_be_current(self):
        self.owner["manual_review"]["text_semantics"]["evidence"][0]["end_line"] = 100
        self.assertEqual(self.record()["manual_checks"]["text_semantics"]["status"], "incomplete_evidence")

    def test_no_manual_review_is_not_replaced_by_matching_labels(self):
        for gate in audit.GATES:
            self.owner["manual_review"][gate]["state"] = "not_reviewed"
        record = self.record()
        self.assertEqual(record["machine_checks"]["label_order"]["status"], "passed")
        self.assertTrue(all(x["status"] == "not_reviewed" for x in record["manual_checks"].values()))

    def add_shared(self, name="Helper", start=8, end=16):
        shared = copy.deepcopy(self.owner)
        shared["id"] = "shared:" + name
        shared["events"] = None
        shared["shared_dependencies"] = []
        shared["spans"] = [{"kind": "data", "start": audit.ROM_BASE + start,
                            "end": audit.ROM_BASE + end, "sha256": audit.sha256(self.rom[start:end])}]
        self.data["owners"].append(shared)
        return shared

    def test_shared_owner_is_counted_once_not_once_per_consumer(self):
        self.add_shared()
        self.owner["shared_dependencies"] = ["shared:Helper"]
        records = self.report()["records"]
        self.assertEqual([x["id"] for x in records], ["map:Example", "shared:Helper"])
        self.assertIn("shared_dependency_not_reviewed:shared:Helper", records[0]["issues"])

    def test_shared_dependency_cycles_are_rejected(self):
        first = self.add_shared("First")
        second = self.add_shared("Second", 16, 24)
        first["shared_dependencies"] = [second["id"]]
        second["shared_dependencies"] = [first["id"]]
        with self.assertRaisesRegex(audit.ManifestError, "cyclic"):
            self.report()

    def test_duplicate_owner_ids_are_rejected(self):
        self.data["owners"].append(copy.deepcopy(self.owner))
        with self.assertRaisesRegex(audit.ManifestError, "duplicate owner"):
            self.report()

    def test_duplicate_and_overlapping_spans_are_rejected(self):
        for start, end in ((0, 8), (4, 12), (7, 9)):
            with self.subTest(start=start, end=end):
                self.add_shared(start=start, end=end)
                with self.assertRaisesRegex(audit.ManifestError, "overlapping or duplicate"):
                    self.report()
                self.data["owners"].pop()

    def test_touching_half_open_spans_are_allowed(self):
        self.add_shared(start=8, end=16)
        self.assertEqual(self.report()["summary"]["manifest_records"], 2)

    def test_out_of_rom_empty_reversed_and_bool_ranges_are_rejected(self):
        cases = ((audit.ROM_BASE - 1, audit.ROM_BASE + 8),
                 (audit.ROM_BASE, audit.ROM_BASE + 65),
                 (audit.ROM_BASE, audit.ROM_BASE),
                 (audit.ROM_BASE + 8, audit.ROM_BASE + 4),
                 (True, audit.ROM_BASE + 8))
        for start, end in cases:
            with self.subTest(start=start, end=end):
                self.owner["spans"][0].update(start=start, end=end)
                with self.assertRaises(audit.ManifestError):
                    self.report()

    def test_bad_sha256_and_bool_schema_are_rejected(self):
        for bad in ("0" * 63, "A" * 64, None, []):
            with self.subTest(bad=bad):
                self.data["rom"]["sha256"] = bad
                with self.assertRaises(audit.ManifestError):
                    self.report()
        self.data["rom"]["sha256"] = audit.sha256(self.rom)
        self.data["schema_version"] = True
        with self.assertRaises(audit.ManifestError):
            self.report()

    def test_missing_dependency_set_is_rejected_not_completed(self):
        self.owner.pop("dependency_roots")
        with self.assertRaises(audit.ManifestError):
            self.report()

    def test_manual_passed_and_manifest_commands_are_rejected_never_executed(self):
        original = copy.deepcopy(self.owner)
        changes = (lambda: self.owner.update(command="touch should-never-exist"),
                   lambda: self.owner["manual_review"]["script_semantics"].update(state="passed"),
                   lambda: self.owner.update(status="passed"))
        for change in changes:
            self.owner.clear()
            self.owner.update(copy.deepcopy(original))
            change()
            with mock.patch.object(audit.subprocess, "run", side_effect=AssertionError("command executed")):
                with self.assertRaises(audit.ManifestError):
                    self.report(run_generation=True)
        self.assertFalse((self.root / "should-never-exist").exists())

    def test_wrong_type_paths_are_validation_errors_not_tracebacks(self):
        for change in (lambda: self.owner["labels"].update(jp=[]),
                       lambda: self.owner["manual_review"]["text_semantics"]["evidence"][0].update(path=[])):
            change()
            code, raw = self.cli("--manifest", self.save())
            self.assertEqual(code, 2)
            self.assertEqual(json.loads(raw)["semantic_review"], "invalid_manifest")

    def test_lexical_path_escape_and_hidden_paths_are_rejected(self):
        for path in ("", ".", "../outside", "/etc/passwd", "a/../../outside", "a//b", "a/./b",
                     "C:/outside", "a\\b", ".git/config", "data/.secret"):
            with self.subTest(path=path):
                self.owner["jp_sources"][path] = "0" * 64
                with self.assertRaises(audit.ManifestError):
                    self.report()
                self.owner["jp_sources"].pop(path)

    def test_symlink_source_escape_is_rejected(self):
        outside = Path(self.temporary.name) / "outside.inc"
        outside.write_text("outside\n")
        source = self.root / self.script
        source.unlink()
        source.symlink_to(outside)
        with self.assertRaisesRegex(audit.ManifestError, "escapes project"):
            self.report()

    def test_symlink_include_escape_is_rejected(self):
        outside = Path(self.temporary.name) / "outside.inc"
        outside.write_text("outside\n")
        self.write(self.root, self.script, 'Example_MapScripts::\n\t.include "escape.inc"\n')
        (self.root / "escape.inc").symlink_to(outside)
        self.owner["jp_sources"][self.script] = self.hash(self.root, self.script)
        with self.assertRaisesRegex(audit.ManifestError, "escapes project"):
            self.report()

    def test_manifest_and_rom_cli_paths_cannot_escape(self):
        code, _ = self.cli("--manifest", "../outside.json")
        self.assertEqual(code, 2)
        code, _ = self.cli("--manifest", self.save(), "--rom", "../outside.gba")
        self.assertEqual(code, 2)

    def test_json_duplicate_keys_nonfinite_and_oversized_input_are_rejected(self):
        for text in ('{"schema_version":1,"schema_version":1}', '{"schema_version":NaN}',
                     '{"schema_version":Infinity}'):
            self.write(self.root, "audits/reviews.json", text)
            with self.assertRaises(audit.ManifestError):
                audit.load_manifest(self.root / "audits/reviews.json")
        path = self.save()
        with mock.patch.object(audit, "MAX_MANIFEST", 10):
            with self.assertRaisesRegex(audit.ManifestError, "size limit"):
                audit.load_manifest(self.root / path)

    def test_wrong_map_generation_pair_cannot_validate_another_owner(self):
        self.owner["events"]["map_json"] = "data/maps/Other/map.json"
        with self.assertRaises(audit.ManifestError):
            self.report()

    def test_label_mismatch_fails_and_jp_exception_is_not_semantic_parity(self):
        self.write(self.root, self.script, "Example_MapScripts::\n\tend\nJP_Extra::\n\tend\n")
        self.owner["jp_sources"][self.script] = self.hash(self.root, self.script)
        self.assertEqual(self.record()["status"], "failed")
        self.owner["labels"]["jp_only"] = ["JP_Extra"]
        record = self.record()
        self.assertEqual(record["machine_checks"]["label_order"]["status"], "passed")
        self.assertEqual(record["status"], "partial")

    def test_empty_or_duplicate_labels_cannot_pass(self):
        for source in ("\tend\n", "Example::\nExample::\n"):
            self.write(self.root, self.script, source)
            self.owner["jp_sources"][self.script] = self.hash(self.root, self.script)
            self.assertEqual(self.record()["machine_checks"]["label_order"]["status"], "failed")

    def test_span_hash_or_built_rom_mismatch_fails(self):
        self.owner["spans"][0]["sha256"] = "0" * 64
        self.assertEqual(self.record()["status"], "failed")
        self.owner["spans"][0]["sha256"] = audit.sha256(self.rom[:8])
        (self.root / "pokeemerald_jp.gba").write_bytes(bytes([255]) + self.rom[1:])
        self.assertEqual(self.record()["machine_checks"]["spans"][0]["built_rom_equality"], "failed")

    def test_rom_identity_mismatch_and_missing_rom_are_not_verified(self):
        self.data["rom"]["sha256"] = "0" * 64
        self.assertEqual(self.record()["status"], "failed")
        (self.root / "baserom_jp.gba").unlink()
        record = self.record()
        self.assertEqual(record["machine_checks"]["rom_identity"], "unavailable")
        self.assertEqual(record["status"], "partial")

    def test_generated_events_mismatch_fails(self):
        def wrong(argv, **kwargs):
            (Path(argv[4]) / "events.inc").write_bytes(b"wrong\n")
            return subprocess.CompletedProcess(argv, 0, b"", b"")
        with mock.patch.object(audit.subprocess, "run", side_effect=wrong):
            self.assertEqual(self.record(run_generation=True)["status"], "failed")

    def test_two_outputs_are_identical_and_strict_mode_refuses_partial(self):
        path = self.save()
        first = self.cli("--manifest", path, "--built-rom", "pokeemerald_jp.gba")
        second = self.cli("--manifest", path, "--built-rom", "pokeemerald_jp.gba")
        self.assertEqual(first, second)
        self.assertEqual(first[0], 0)
        self.assertEqual(json.loads(first[1])["semantic_review"], "partial")
        self.assertEqual(self.cli("--manifest", path, "--require-current")[0], 1)

    def test_owner_and_hash_dictionary_order_does_not_change_report(self):
        self.add_shared()
        before = json.dumps(self.report(), sort_keys=True)
        self.data["owners"].reverse()
        self.owner["jp_sources"] = dict(reversed(list(self.owner["jp_sources"].items())))
        self.assertEqual(before, json.dumps(self.report(), sort_keys=True))

    def test_numeric_parser_and_nesting_limits_are_structured_errors(self):
        # Exercise Python's integer/depth parser limits, not merely JSON syntax.
        for source in ('{"schema_version":' + "9" * 5000 + '}', "[" * 1500 + "0" + "]" * 1500):
            self.write(self.root, "audits/reviews.json", source)
            code, report = self.cli("--manifest", "audits/reviews.json")
            self.assertEqual(code, 2)
            self.assertEqual(json.loads(report)["semantic_review"], "invalid_manifest")

    def test_source_reader_is_bounded(self):
        self.write(self.root, "large.inc", "a" * 11)
        with self.assertRaisesRegex(audit.ManifestError, "size limit"):
            audit.read_project_file(self.root, "large.inc", limit=10)

    def test_generation_outputs_are_deterministic_despite_temporary_directory_names(self):
        path = self.save()
        with mock.patch.object(audit.subprocess, "run", side_effect=self.fake_generation):
            first = self.cli("--manifest", path, "--built-rom", "pokeemerald_jp.gba", "--run-generation-check")
            second = self.cli("--manifest", path, "--built-rom", "pokeemerald_jp.gba", "--run-generation-check")
        self.assertEqual(first, second)


if __name__ == "__main__":
    unittest.main()
