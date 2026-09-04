#!/usr/bin/env python3
"""Regression coverage for readable Japanese Braille in tools/preproc.

The 22 fixtures are the contiguous Japanese Sealed Chamber braille owner. Their
readable kana and glyph comments are cross-checked against:
https://wiki.52poke.com/wiki/%E5%B8%83%E5%91%8A%E7%9F%B3%E5%AE%A4
ROM bytes, rather than that secondary source, are the byte-exact test oracle.
"""

import hashlib
import re
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
PREPROC = ROOT / "tools" / "preproc" / "preproc"
CHARMAP = ROOT / "charmap.txt"
ROM = ROOT / "baserom_jp.gba"
BRAILLE_START = 0x2635D2
BRAILLE_END = 0x2637C2
BRAILLE_SHA256 = "a3157e2a69e79d7e992715205b4c59ed6cc1a4e15affbd68ed863434a44e9ae4"
SPAN_SIZES = (
    0x10, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0A, 0x0C, 0x0A,
    0x12, 0x30, 0x2B, 0x1A, 0x23, 0x0F, 0x1F, 0x25, 0x27, 0x1F, 0x29,
)
READABLE_JAPANESE_BRAILLE = (
    "ココデ アガレ",
    "アイウエオ",
    "カキクケコ",
    "サシスセソ",
    "タチツテト",
    "ナニヌネノ",
    "ハヒフヘホ",
    "マミムメモ",
    "ヤユヨ",
    "ラリルレロ",
    "ワヲン",
    "ココデ\nアナヲ ホル",
    "サイショニ ホエルオー\nサイゴニ ジーランス\nソシテ スベテガ\nヒラカレル",
    "ワタシタチワ\nコノ アナデ\nクラシ セイカツ シ\nソシテ イキテ キタ",
    "スベテワ\nポケモンノ\nオカゲダ",
    "ダガ\nワタシタチワ\nアノ ポケモンヲ\nトジコメタ",
    "コワカッタノダ",
    "ユーキ アル\nモノヨ\nキボーニ\nミチタ モノヨ",
    "トビラヲ アケヨ\nソコニ エイエンノ\nポケモンガ イル",
    "ヒダリ ヒダリ\nシタ シタ\nソコデ\nイワクダキヲ ツカエ",
    "カベカラ\nハナレズ\nココヲ\nヒトマワリ セヨ",
    "ワレワレノ イシヲ\nツギシ モノヨ\nマンナカデ\nヒカリカガヤケ",
)


def unicode_cell_from_gba(code):
    """Convert a GBA row-major six-dot index to a Unicode Braille cell."""
    dots = (
        (code & 0x01)
        | ((code & 0x02) << 2)
        | ((code & 0x04) >> 1)
        | ((code & 0x08) << 1)
        | ((code & 0x10) >> 2)
        | (code & 0x20)
    )
    return chr(0x2800 + dots)


def braille_glyphs(payload):
    """Render an existing payload as a Unicode Braille visual checksum."""
    text = []
    for value in payload:
        if value == 0xFE:
            text.append("\n")
        elif value < 0x40:
            text.append(unicode_cell_from_gba(value))
        else:
            raise AssertionError(f"unexpected braille payload byte 0x{value:02X}")
    return "".join(text)


def braille_source(reading, payload):
    """Write readable kana plus one glyph-comment line for a fixture."""
    glyph_comment = braille_glyphs(payload).replace("\n", " / ")
    literal = reading.replace("\n", r"\n")
    return f'\t@ 点字: {glyph_comment}\n\t.braille "{literal}$"\n'


class UnicodeBraillePreprocessorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        subprocess.run(["make", "-C", str(ROOT / "tools" / "preproc")], check=True)

    def run_preproc(self, source):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "braille.s"
            path.write_text(source, encoding="utf-8")
            return subprocess.run(
                [str(PREPROC), str(path), str(CHARMAP)],
                cwd=ROOT,
                text=True,
                capture_output=True,
            )

    @staticmethod
    def output_bytes(result):
        return bytes(int(value, 16) for value in re.findall(r"0x([0-9A-F]{2})", result.stdout))

    def test_unicode_cells_use_the_documented_dot_order(self):
        result = self.run_preproc('\t.braille "⠪⠐⠟⠀⠁⠡⠛$"\n')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(
            self.output_bytes(result),
            bytes((0x26, 0x08, 0x1F, 0x00, 0x01, 0x21, 0x0F, 0xFF)),
        )

    def test_readable_japanese_braille_owner_spans_reencode_exactly(self):
        rom = ROM.read_bytes()
        region = rom[BRAILLE_START:BRAILLE_END]
        self.assertEqual(hashlib.sha256(region).hexdigest(), BRAILLE_SHA256)

        offset = BRAILLE_START
        for size, reading in zip(SPAN_SIZES, READABLE_JAPANESE_BRAILLE):
            raw = rom[offset:offset + size]
            self.assertEqual(len(raw), size)
            self.assertEqual(raw[-1], 0xFF)
            payload = raw[6:-1]  # brailleformat header and EOS
            result = self.run_preproc(braille_source(reading, payload))
            self.assertEqual(result.returncode, 0, f"0x{offset + 0x08000000:08X}: {result.stderr}")
            self.assertEqual(
                self.output_bytes(result),
                payload + b"\xFF",
                f"0x{offset + 0x08000000:08X}: {reading!r}",
            )
            offset += size
        self.assertEqual(offset, BRAILLE_END)

    def test_braille_owner_uses_readable_kana_with_glyph_comments(self):
        source = (ROOT / "data" / "text" / "braille.inc").read_text(encoding="utf-8")
        records = re.findall(
            r'^\t@ 点字: (.*)\n\t\.braille "([^"]*)\$"$',
            source,
            re.MULTILINE,
        )
        self.assertEqual(len(records), len(READABLE_JAPANESE_BRAILLE))

        rom = ROM.read_bytes()
        offset = BRAILLE_START
        for (glyph_comment, source_literal), size, reading in zip(
            records, SPAN_SIZES, READABLE_JAPANESE_BRAILLE
        ):
            raw = rom[offset:offset + size]
            self.assertEqual(
                glyph_comment,
                braille_glyphs(raw[6:-1]).replace("\n", " / "),
            )
            self.assertEqual(source_literal.replace(r"\n", "\n"), reading)
            offset += size

    def test_hiragana_and_katakana_encode_the_same_braille_cells(self):
        katakana = self.run_preproc('\t.braille "ココデ アガレ$"\n')
        hiragana = self.run_preproc('\t.braille "ここで あがれ$"\n')
        self.assertEqual(katakana.returncode, 0, katakana.stderr)
        self.assertEqual(hiragana.returncode, 0, hiragana.stderr)
        self.assertEqual(self.output_bytes(katakana), self.output_bytes(hiragana))

    def test_unknown_japanese_text_is_rejected(self):
        result = self.run_preproc('\t.braille "漢$"\n')
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Unicode character", result.stderr)


if __name__ == "__main__":
    unittest.main()
