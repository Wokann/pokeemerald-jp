#!/usr/bin/env python3
"""Extract JP font glyph data from baserom_jp.gba.

The JP ROM stores its font glyphs as raw (non-LZ) tile data in data/data.s:
  sFontGlyphData_9CF14  (0x4000, 8x12 glyphs, 2D grid)
  sFontGlyphData_A0F14  (0x4000, 8x16 glyphs, 2D grid)
  sFontGlyphData_A4F14  (0x8000, 10x12 glyphs, 1D grid + sGlyphWidthTable_ACF14)
  sFontGlyphData_AD02C  (0x8000, 10x12 glyphs, 1D grid + sGlyphWidthTable_B502C)
  sFontGlyphData_B5144  (0x8000, 10x12 glyphs, 1D grid + sGlyphWidthTable_BD144)
  sFontGlyphData_BD25C  (0x203D, 8x12 glyphs, 2D grid)

These are JP-exclusive resources (no US equivalent), so they are named after
their JP labels and stored under graphics/fonts/ like pokeemerald's fonts.

Usage:
  python3 tools/extract_font_glyphs.py            # extract + rewrite data.s
  python3 tools/extract_font_glyphs.py --check    # verify only
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
DATA_S = ROOT / "data" / "data.s"
OUT_DIR = ROOT / "graphics" / "fonts"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    lines = DATA_S.read_text(encoding="utf-8").splitlines()

    pat_label = re.compile(r"^sFontGlyphData_([0-9A-Fa-f]+):\s*@\s*0x([0-9A-Fa-f]+)$")
    pat_inc = re.compile(
        r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
    )

    entries = []
    for i, line in enumerate(lines):
        m = pat_label.match(line)
        if not m:
            continue
        suffix = m.group(1)
        im = pat_inc.match(lines[i + 1])
        if not im:
            sys.exit(f"sFontGlyphData_{suffix}: expected baserom incbin after label")
        off = int(im.group(1), 16)
        size = int(im.group(2), 16)
        entries.append((suffix, off, size, i))

    if not entries:
        sys.exit("No sFontGlyphData entries found in data.s")

    problems = []
    new_lines = list(lines)
    for suffix, off, size, idx in entries:
        data = rom[off : off + size]
        if len(data) != size:
            problems.append(f"{suffix}: short read")
            continue
        out_path = OUT_DIR / f"jp_font_glyph_{suffix}.bin"
        if not args.check:
            OUT_DIR.mkdir(parents=True, exist_ok=True)
            out_path.write_bytes(data)
            new_lines[idx + 1] = f'\t.incbin "graphics/fonts/jp_font_glyph_{suffix}.bin"'
        else:
            # Verify the existing file matches the ROM bytes, if present.
            if out_path.exists() and out_path.read_bytes() != data:
                problems.append(f"{suffix}: existing file differs from ROM")

    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        DATA_S.write_text("\n".join(new_lines) + "\n", encoding="utf-8")
        print(f"Extracted {len(entries)} font glyph blocks to {OUT_DIR}")
    else:
        print(f"Check OK: {len(entries)} font glyph blocks")


if __name__ == "__main__":
    main()
