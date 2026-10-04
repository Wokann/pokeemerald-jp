#!/usr/bin/env python3
"""Regressions for the JP Summary text's verified F9 05 / LV_2 glyph.

These six fixtures are the actual LV_2-bearing objects inside ROM offsets
[0x5CA4A6, 0x5CA5B6). The other two objects do not contain LV_2. Fixtures keep
the tests reproducible without redistributing a ROM; a locally available ROM
is independently checked against the same explicit half-open boundaries.
"""

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from jp_script_text import (
    BASEROM_PATH,
    PREPROC_PATH,
    JapaneseScriptTextCodec,
    TextDecodeError,
)


LV_2_OBJECTS = (
    (
        "gText_XNatureMetAtYZ", 0x5CA4A6, 0x5CA4CC,
        "f700f702f701f7050e02060800f905f700f703f701191407fe"
        "f700f704f701440044015010ff",
    ),
    (
        "gText_XNatureHatchedAtYZ", 0x5CA4CC, 0x5CA4F2,
        "f700f702f701f7050e02060800f905f700f703f701191407fe"
        "f700f704f701440006045010ff",
    ),
    (
        "gText_XNatureFatefulEncounter", 0x5CA512, 0x5CA53B,
        "f700f702f701f7050e02060800f905f700f703f701191407fe"
        "032e2202130715004401022d000c10ff",
    ),
    (
        "gText_XNatureProbablyMetAt", 0x5CA53B, 0x5CA563,
        "f700f702f701f7050e02060800f905f700f703f701191407fe"
        "f700f704f7014400015010260341ff",
    ),
    (
        "gText_XNatureMetSomewhereAt", 0x5CA570, 0x5CA593,
        "f700f702f701f7050e02060800f905f700f703f701191407fe"
        "450a06440044015010ff",
    ),
    (
        "gText_XNatureHatchedSomewhereAt", 0x5CA593, 0x5CA5B6,
        "f700f702f701f7050e02060800f905f700f703f701191407fe"
        "450a06440006045010ff",
    ),
)


class Lv2TextCodecTests(unittest.TestCase):
    def setUp(self):
        self.codec = JapaneseScriptTextCodec()

    def test_lv_2_decodes_to_its_verified_charmap_name(self):
        self.assertEqual(self.codec.constants["LV_2"], b"\xF9\x05")
        self.assertEqual(self.codec.decode(b"\xF9\x05\xFF"), "{LV_2}$")

    def test_summary_objects_decode_without_consuming_the_next_object(self):
        self.assertEqual(len(LV_2_OBJECTS), 6)
        for name, start, end, hex_bytes in LV_2_OBJECTS:
            with self.subTest(name=name, address=f"0x{start + 0x08000000:08X}"):
                raw = bytes.fromhex(hex_bytes)
                self.assertEqual(len(raw), end - start)
                self.assertEqual(raw.count(b"\xF9\x05"), 1)
                self.assertEqual(raw.count(b"\xFF"), 1)
                decoded = self.codec.decode_one(raw + b"\xF9")
                self.assertTrue(decoded.ended)
                self.assertEqual(decoded.consumed, len(raw))
                self.assertEqual(decoded.source.count("{LV_2}"), 1)
                self.assertIn("{DYNAMIC 0x00}", decoded.source)
                self.assertIn(r"\n", decoded.source)
                self.assertTrue(decoded.source.endswith("$"))

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_all_six_summary_objects_round_trip_through_real_preproc(self):
        for name, start, end, hex_bytes in LV_2_OBJECTS:
            with self.subTest(name=name, address=f"0x{start + 0x08000000:08X}"):
                raw = bytes.fromhex(hex_bytes)
                decoded = self.codec.verify_one(raw + b"\xF9")
                self.assertEqual(decoded.consumed, end - start)
                self.assertEqual(self.codec.preproc_bytes(decoded.source), raw)

    @unittest.skipUnless(BASEROM_PATH.is_file(), "matching JP ROM is required")
    def test_summary_fixtures_match_the_actual_jp_rom_spans(self):
        rom = BASEROM_PATH.read_bytes()
        for name, start, end, hex_bytes in LV_2_OBJECTS:
            with self.subTest(name=name, address=f"0x{start + 0x08000000:08X}"):
                self.assertEqual(rom[start:end], bytes.fromhex(hex_bytes))

    def test_unverified_f9_selectors_remain_hard_errors(self):
        verified_selectors = {5} | {sequence[1] for sequence in self.codec.emoji}
        for selector in range(256):
            if selector not in verified_selectors:
                with self.subTest(selector=f"0x{selector:02X}"):
                    with self.assertRaisesRegex(TextDecodeError, "unknown extra-symbol"):
                        self.codec.decode(bytes((0xF9, selector, 0xFF)))
        # These are also sound/music constants; scanning all F9-valued
        # constants must not let their names leak into text decoding.
        self.assertEqual(self.codec.constants["SE_RG_CARD_FLIP"], b"\xF9\x00")
        self.assertEqual(self.codec.constants["MUS_RG_ROUTE3"], b"\xF9\x01")

    def test_truncated_f9_remains_a_hard_error_in_both_decode_modes(self):
        for decode in (self.codec.decode, self.codec.decode_one):
            with self.subTest(mode=decode.__name__):
                with self.assertRaisesRegex(TextDecodeError, "truncated extra-symbol"):
                    decode(b"\xF9")

    def test_existing_emoji_decoding_is_unchanged(self):
        self.assertTrue(self.codec.emoji)
        for sequence, name in self.codec.emoji.items():
            with self.subTest(name=name):
                self.assertEqual(self.codec.decode(sequence + b"\xFF"), "{" + name + "}$")

    def test_lv_2_mapping_cannot_silently_drift(self):
        for mapping in (None, b"\xF9\x06", b"\xF8\x05"):
            with self.subTest(mapping=mapping):
                self.codec.constants["LV_2"] = mapping
                with self.assertRaisesRegex(TextDecodeError, "LV_2 must be f905"):
                    self.codec._validate_charmap_contract()


if __name__ == "__main__":
    unittest.main()
