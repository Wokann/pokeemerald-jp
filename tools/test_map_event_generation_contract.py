#!/usr/bin/env python3
"""Regressions for the finite JSON-owned map-event clean/rebuild contract."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

import audit_map_event_generation as audit

ROOT = Path(__file__).resolve().parents[1]


def clean_event_recipe():
    source = (ROOT / "Makefile").read_text()
    match = re.search(r"(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)", source)
    if not match:
        raise AssertionError("production clean recipe is missing")
    lines = [line for line in match[1].splitlines(keepends=True)
             if "$(JP_STRUCTURED_MAP_EVENTS)" in line]
    if lines != ["\trm -f $(JP_STRUCTURED_MAP_EVENTS)\n"]:
        raise AssertionError("clean must use the exact, non-recursive JSON-owned event allowlist")
    return lines[0]


class MapEventGenerationContractTests(unittest.TestCase):
    def test_production_clean_uses_only_the_existing_finite_json_target_set(self):
        self.assertEqual(clean_event_recipe(), "\trm -f $(JP_STRUCTURED_MAP_EVENTS)\n")
        source = (ROOT / "Makefile").read_text()
        self.assertIn("JP_STRUCTURED_MAP_EVENTS := $(JP_STRUCTURED_MAPS:%=data/maps/%/events.inc)", source)
        self.assertIn("$(JP_STRUCTURED_MAP_EVENTS): data/maps/%/events.inc: data/maps/%/map.json | tools",
                      source)
        self.assertIn("\t$(MAPJSON) events emerald $< $(@D)", source)

    @unittest.skipUnless(shutil.which("make"), "GNU make required")
    def test_actual_clean_recipe_preserves_json_scripts_metadata_and_unlisted_sources(self):
        with tempfile.TemporaryDirectory(prefix="map-events-clean-") as directory:
            root = Path(directory)
            tracked = {}
            for name in ("First", "Second", "NotGenerated"):
                folder = root / "data/maps" / name
                folder.mkdir(parents=True)
                for filename in ("map.json", "scripts.inc", "header.inc", "connections.inc", "events.inc"):
                    path = folder / filename
                    data = (name + "/" + filename + "\n").encode()
                    path.write_bytes(data)
                    tracked[path] = data
            (root / "Makefile").write_text(
                "JP_STRUCTURED_MAP_EVENTS := data/maps/First/events.inc data/maps/Second/events.inc\n"
                "clean:\n" + clean_event_recipe())
            subprocess.run(["make", "--no-print-directory", "clean"], cwd=root, check=True,
                           stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            deleted = {root / "data/maps" / name / "events.inc" for name in ("First", "Second")}
            for path, data in tracked.items():
                if path in deleted:
                    self.assertFalse(path.exists())
                else:
                    self.assertEqual(path.read_bytes(), data, str(path.relative_to(root)))

    def test_missing_event_source_is_reported_instead_of_silently_declaring_completion(self):
        with tempfile.TemporaryDirectory(prefix="map-events-missing-") as directory:
            root = Path(directory)
            folder = root / "data/maps/First"
            folder.mkdir(parents=True)
            (folder / "map.json").write_text("{}\n")
            with self.assertRaisesRegex(RuntimeError, "missing generated source: data/maps/First/events.inc"):
                audit.tracked_event_sources(root)

    @unittest.skipUnless(shutil.which("make"), "GNU make required")
    def test_makefile_coverage_rejects_both_missing_and_stale_json_targets(self):
        with tempfile.TemporaryDirectory(prefix="map-events-coverage-") as directory:
            root = Path(directory)
            folder = root / "data/maps/First"
            folder.mkdir(parents=True)
            (folder / "map.json").write_text("{}\n")
            (folder / "events.inc").write_text("First_MapEvents::\n")
            sources = audit.tracked_event_sources(root)
            makefile = root / "Makefile"
            for targets, error in (
                ("", "missing Makefile targets"),
                ("data/maps/First/events.inc data/maps/Stale/events.inc", "stale Makefile targets"),
            ):
                makefile.write_text("JP_STRUCTURED_MAP_EVENTS := " + targets + "\nall:\n\t@:\n")
                with self.subTest(targets=targets), self.assertRaisesRegex(RuntimeError, error):
                    audit.verify_makefile_coverage(root, sources)
            makefile.write_text("JP_STRUCTURED_MAP_EVENTS := data/maps/First/events.inc\nall:\n\t@:\n")
            audit.verify_makefile_coverage(root, sources)

    @unittest.skipUnless(audit.MAPJSON.is_file(), "built mapjson required")
    def test_real_generator_creates_absent_outputs_deterministically_in_empty_directories(self):
        for name in ("PetalburgCity", "ContestHallBeauty", "BattlePyramidSquare01"):
            source = ROOT / "data/maps" / name / "map.json"
            expected = source.with_name("events.inc").read_bytes()
            with self.subTest(map=name), tempfile.TemporaryDirectory(prefix="map-events-new-") as directory:
                for number in (1, 2):
                    output = Path(directory) / str(number)
                    output.mkdir()
                    self.assertFalse((output / "events.inc").exists())
                    subprocess.run([str(audit.MAPJSON), "events", "emerald", str(source), str(output)],
                                   cwd=ROOT, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    self.assertEqual((output / "events.inc").read_bytes(), expected)

    @unittest.skipUnless(audit.MAPJSON.is_file(), "built mapjson required")
    def test_every_json_event_source_is_reproducible_not_only_the_sample_maps(self):
        sources = audit.tracked_event_sources(ROOT)
        self.assertEqual(len(sources), 518)
        audit.verify_makefile_coverage(ROOT, sources)
        self.assertEqual(audit.verify_generation(ROOT, sources), [])


if __name__ == "__main__":
    unittest.main()
