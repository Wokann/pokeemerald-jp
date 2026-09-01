#!/usr/bin/env python3
"""Regression coverage for exact external-label recovery in map verification."""
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import verify_generated_map_scripts as verifier  # noqa: E402


class ExternalLabelAddressTest(unittest.TestCase):
    def test_route111_local_and_cross_owner_texts_have_exact_addresses(self):
        labels = verifier._external_label_addresses()
        self.assertEqual(labels["Route111_Text_ClawFossilDisappeared"], 0x081EADDB)
        for name, address in (
            ("Route111_Text_WateredPlantsEveryDayTakeBerry", 0x0826388C),
            ("Route111_Text_GoingToTryToMakeDifferentColorBerries", 0x082638C8),
            ("Route111_Text_WhatColorBerriesToLookForToday", 0x082638F0),
        ):
            with self.subTest(name=name):
                self.assertEqual(verifier._resolve_address(name, labels), address)

    def test_conflicting_linked_symbol_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            symbol_map = Path(directory) / "symbols.map"
            symbol_map.write_text(
                "  0x0826388c  Route111_Text_WateredPlantsEveryDayTakeBerry\n"
                "  0x082638c8  Route111_Text_WateredPlantsEveryDayTakeBerry\n",
                encoding="utf-8",
            )
            with self.assertRaisesRegex(
                verifier.VerificationError, "conflicting addresses"
            ):
                verifier._linked_symbol_addresses(symbol_map)

    def test_conflicting_local_elf_symbol_is_rejected_only_when_requested(self):
        labels = verifier._external_label_addresses()
        with self.assertRaisesRegex(
            verifier.VerificationError, "linked ELF symbol VBlankCB has conflicting addresses"
        ):
            verifier._resolve_address("VBlankCB", labels)

    def test_route111_verifier_accepts_cross_owner_texts(self):
        verifier.verify_map("Route111", verbose=False)

    def test_main_verifies_multiple_map_names_in_order(self):
        calls = []

        def verify(name, *, verbose):
            calls.append((name, verbose))
            return f"source for {name}"

        with mock.patch.object(verifier, "verify_map", side_effect=verify):
            with mock.patch.object(sys, "argv", ["verify", "MapA", "MapB"]):
                verifier.main()

        self.assertEqual(calls, [("MapA", True), ("MapB", True)])

    def test_main_rejects_multi_map_output(self):
        with mock.patch.object(sys, "argv", ["verify", "MapA", "MapB", "--output", "out.inc"]):
            with self.assertRaisesRegex(SystemExit, "one map name"):
                verifier.main()


if __name__ == "__main__":
    unittest.main()
