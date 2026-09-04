#!/usr/bin/env python3
"""Regression coverage for Unicode Braille cells in tools/preproc.

The 22 fixtures are the contiguous Japanese Sealed Chamber braille owner.
Their labels and Japanese readings are cross-checked against:
https://wiki.52poke.com/wiki/%E5%B8%83%E5%91%8A%E7%9F%B3%E5%AE%A4
ROM bytes, rather than that secondary source, are the test oracle.
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


def braille_source(payload):
    """Spell an existing payload using only standard Unicode Braille cells."""
    text = []
    for value in payload:
        if value == 0xFE:
            text.append(r"\n")
        elif value < 0x40:
            text.append(unicode_cell_from_gba(value))
        else:
            raise AssertionError(f"unexpected braille payload byte 0x{value:02X}")
    return '\t.braille "' + "".join(text) + '$"\n'


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

    def test_all_japanese_braille_owner_spans_reencode_exactly(self):
        rom = ROM.read_bytes()
        region = rom[BRAILLE_START:BRAILLE_END]
        self.assertEqual(hashlib.sha256(region).hexdigest(), BRAILLE_SHA256)

        offset = BRAILLE_START
        for size in SPAN_SIZES:
            raw = rom[offset:offset + size]
            self.assertEqual(len(raw), size)
            self.assertEqual(raw[-1], 0xFF)
            payload = raw[6:-1]  # brailleformat header and EOS
            result = self.run_preproc(braille_source(payload))
            self.assertEqual(result.returncode, 0, f"0x{offset + 0x08000000:08X}: {result.stderr}")
            self.assertEqual(self.output_bytes(result), payload + b"\xFF")
            offset += size
        self.assertEqual(offset, BRAILLE_END)

    def test_unknown_japanese_text_is_rejected(self):
        result = self.run_preproc('\t.braille "コ$"\n')
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Unicode character", result.stderr)


if __name__ == "__main__":
    unittest.main()
