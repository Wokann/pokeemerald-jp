#!/usr/bin/env python3
"""Regressions for native JP Summary/e-Reader/chat glyphs and PokeNav controls.

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
        verified_selectors = {sequence[1] for sequence in self.codec.extra_symbols} | {sequence[1] for sequence in self.codec.emoji}
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


class EReaderTextCodecTests(unittest.TestCase):
    def setUp(self):
        self.codec = JapaneseScriptTextCodec()

    def test_plus_decodes_to_the_ereader_glyph_name(self):
        self.assertEqual(self.codec.constants["PLUS"], b"\xF9\x04")
        decoded = self.codec.decode_one(b"\xF9\x04\xFF\xF9")
        self.assertEqual((decoded.source, decoded.consumed, decoded.ended), ("{PLUS}$", 3, True))

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_plus_round_trips_with_native_japanese_ereader_text(self):
        source = "カードeリーダー{PLUS}と\\nつうしん　できません$"
        raw = self.codec.preproc_bytes(source)
        self.assertEqual(raw.count(b"\xF9\x04"), 1)
        self.assertEqual(self.codec.verify_one(raw).source, source)

    def test_plus_mapping_cannot_silently_drift(self):
        for mapping in (None, b"\xF9\x05", b"\xF8\x04"):
            with self.subTest(mapping=mapping):
                self.codec.constants["PLUS"] = mapping
                with self.assertRaisesRegex(TextDecodeError, "PLUS must be f904"):
                    self.codec._validate_charmap_contract()


class PokeNavTextCodecTests(unittest.TestCase):
    TEMPLATES = (
        (0x5CB7D6, 0x5CB7EA, "{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}$"),
        (0x5CB7EA, 0x5CB7FE, "{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}$"),
        (0x5CB7FE, 0x5CB808, "{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}$"),
        (0x5CB829, 0x5CB841, "{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ$"),
        (0x5CB841, 0x5CB859, "{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ$"),
        (0x5CB859, 0x5CB867, "{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ$"),
    )

    def setUp(self):
        self.codec = JapaneseScriptTextCodec()

    def test_dynamic_slots_never_decode_as_colliding_audio_names(self):
        self.assertEqual(self.codec.constants["SE_M_HYPER_BEAM2"], b"\xF7\x00")
        self.assertEqual(self.codec.constants["MUS_RG_ROUTE1"], b"\xF7\x01")
        self.assertEqual(self.codec.decode(b"\xF7\x00\xF7\x01\xFF"), "{DYNAMIC 0x00}{DYNAMIC 0x01}$")

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_native_name_templates_preserve_dynamic_slots_and_level_font(self):
        for start, end, source in self.TEMPLATES:
            with self.subTest(address=f"0x{start:06X}"):
                raw = self.codec.preproc_bytes(source)
                self.assertEqual(len(raw), end - start)
                decoded = self.codec.verify_one(raw + b"\xF9")
                self.assertEqual(decoded.consumed, len(raw))
                self.assertIn("{DYNAMIC 0x00}", decoded.source)
                self.assertIn("{DYNAMIC 0x01}", decoded.source)
                self.assertIn("{LV_2}", decoded.source)
                self.assertEqual(decoded.source.count("{DYNAMIC "), source.count("{DYNAMIC "))
                self.assertNotIn("{SE_", decoded.source)
                self.assertNotIn("{MUS_", decoded.source)

    @unittest.skipUnless(BASEROM_PATH.is_file() and PREPROC_PATH.is_file(), "matching JP ROM and preproc are required")
    def test_name_template_fixtures_match_the_actual_jp_rom(self):
        rom = BASEROM_PATH.read_bytes()
        for start, end, source in self.TEMPLATES:
            with self.subTest(address=f"0x{start:06X}"):
                self.assertEqual(self.codec.preproc_bytes(source), rom[start:end])

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_match_call_menu_items_stop_at_each_independent_eos(self):
        sources = ("ふめい$", "よびだし$", "しょうさい$", "もどる$")
        packed = self.codec.preproc_bytes("".join(sources))
        position = 0
        for source, size in zip(sources, (4, 5, 6, 4)):
            decoded = self.codec.decode_one(packed[position:] + b"\xF9")
            self.assertEqual((decoded.source, decoded.consumed), (source, size))
            position += decoded.consumed
        self.assertEqual(position, len(packed))


class NamingScreenTextCodecTests(unittest.TestCase):
    DOUBLE_EOS_ROWS = (
        (0x56590B, 0x56591F, "カキクケコ　ハヒフヘホ　ワヲン　$\\n　$"),
        (0x56595B, 0x56596F, "かきくけこ　はひふへほ　わをん　$\\n　$"),
    )
    INSTRUCTIONS = "{DPAD_NONE}いどう　　{R_BUTTON}{JP_DAKUTEN}{JP_HANDAKUTEN}{JP_BIG}{JP_SMALL}　　{A_BUTTON}けってい　{B_BUTTON}もどる　$"

    def setUp(self):
        self.codec = JapaneseScriptTextCodec()

    def test_font_zero_hint_names_keep_the_native_glyph_ids(self):
        expected = {
            "JP_DAKUTEN": b"\xF9\xCF",
            "JP_HANDAKUTEN": b"\xF9\xD0",
            "JP_BIG": b"\xF9\xCD",
            "JP_SMALL": b"\xF9\xCE",
        }
        for name, raw in expected.items():
            with self.subTest(name=name):
                self.assertEqual(self.codec.constants[name], raw)

    def test_generic_decoder_does_not_guess_font_zero_hint_names(self):
        # A caller must establish font 0 before using the JP hint names.
        # The generic decoder keeps its existing emoji interpretation.
        for selector in (0xCD, 0xCE, 0xCF):
            with self.subTest(selector=selector):
                with self.assertRaisesRegex(TextDecodeError, "unknown extra-symbol"):
                    self.codec.decode(bytes((0xF9, selector, 0xFF)))
        self.assertEqual(self.codec.decode(b"\xF9\xD0\xFF"), "{EMOJI_UNDERSCORE}$")

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_fixed_width_kana_rows_keep_both_eos_sequences(self):
        for start, end, source in self.DOUBLE_EOS_ROWS:
            with self.subTest(address=f"0x{start:06X}"):
                raw = self.codec.preproc_bytes(source)
                self.assertEqual(len(raw), end - start)
                self.assertEqual(raw.count(b"\xFF"), 2)
                first = self.codec.decode_one(raw)
                self.assertEqual(first.consumed, 17)
                self.assertEqual(raw[first.consumed:], b"\xFE\x00\xFF")

    @unittest.skipUnless(BASEROM_PATH.is_file() and PREPROC_PATH.is_file(), "matching JP ROM and preproc are required")
    def test_double_eos_rows_match_the_complete_native_storage(self):
        rom = BASEROM_PATH.read_bytes()
        for start, end, source in self.DOUBLE_EOS_ROWS:
            with self.subTest(address=f"0x{start:06X}"):
                self.assertEqual(self.codec.preproc_bytes(source), rom[start:end])

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_native_instruction_hint_preserves_font_specific_ids(self):
        raw = self.codec.preproc_bytes(self.INSTRUCTIONS)
        self.assertEqual(len(raw), 33)
        self.assertIn(bytes.fromhex("f9cff9d0f9cdf9ce"), raw)
        if BASEROM_PATH.is_file():
            self.assertEqual(raw, BASEROM_PATH.read_bytes()[0x5658A0:0x5658C1])


class UnionRoomKeyboardTextCodecTests(unittest.TestCase):
    LAST_EMOJI_ROW = "{EMOJI_HIGHBAR}{UNDERSCORE}{EMOJI_SEMICOLON}:　$"

    def setUp(self):
        self.codec = JapaneseScriptTextCodec()

    def test_native_underscore_is_not_the_us_emoji_underscore(self):
        self.assertEqual(self.codec.constants["UNDERSCORE"], b"\xF9\x09")
        self.assertEqual(self.codec.constants["EMOJI_UNDERSCORE"], b"\xF9\xD0")
        self.assertEqual(self.codec.decode(b"\xF9\x09\xFF"), "{UNDERSCORE}$")
        self.assertEqual(self.codec.decode(b"\xF9\xD0\xFF"), "{EMOJI_UNDERSCORE}$")

    @unittest.skipUnless(PREPROC_PATH.is_file(), "matching JP preproc is required")
    def test_native_last_emoji_row_preserves_glyphs_and_eos(self):
        raw = self.codec.preproc_bytes(self.LAST_EMOJI_ROW)
        self.assertEqual(len(raw), 9)
        self.assertIn(b"\xF9\x09", raw)
        self.assertNotIn(b"\xF9\xD0", raw)
        decoded = self.codec.verify_one(raw + b"\xF9")
        self.assertEqual((decoded.source, decoded.consumed), (self.LAST_EMOJI_ROW, 9))
        for mapping in (None, b"\xF9\xD0", b"\xF8\x09"):
            with self.subTest(mapping=mapping):
                self.codec.constants["UNDERSCORE"] = mapping
                with self.assertRaisesRegex(TextDecodeError, "UNDERSCORE must be f909"):
                    self.codec._validate_charmap_contract()

    @unittest.skipUnless(BASEROM_PATH.is_file() and PREPROC_PATH.is_file(), "matching JP ROM and preproc are required")
    def test_all_38_native_keyboard_rows_round_trip_at_exact_boundaries(self):
        rom = BASEROM_PATH.read_bytes()
        position, count = 0x5CC4FE, 0
        while position < 0x5CC610:
            decoded = self.codec.verify_one(rom[position:0x5CC610])
            self.assertTrue(decoded.ended)
            self.assertGreater(decoded.consumed, 0)
            position += decoded.consumed
            count += 1
        self.assertEqual((position, count), (0x5CC610, 38))
        self.assertEqual(self.codec.preproc_bytes(self.LAST_EMOJI_ROW), rom[0x5CC607:0x5CC610])


if __name__ == "__main__":
    unittest.main()
