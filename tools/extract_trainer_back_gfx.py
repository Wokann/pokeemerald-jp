#!/usr/bin/env python3
"""Extract JP trainer back pics (8 uncompressed 4bpp images).

The back pics live in gMonBackPic_UnownQuestionMark's remaining tail incbin
(0xD66524..0xD77524) as raw 4bpp data, referenced by gTrainerBackPicTable in
data/data_b_mid2b6.s. Order and bytes match pokeemerald's
graphics/trainers/back_pics/<name>.4bpp.

Usage:
  python3 tools/extract_trainer_back_gfx.py            # extract + rewrite
  python3 tools/extract_trainer_back_gfx.py --check    # verify only
"""

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
MID2B6_S = ROOT / "data" / "data_b_mid2b6.s"
MAIN_S = ROOT / "data" / "data_b2d_gfx_pokemon_main.s"
OUT_DIR = ROOT / "graphics" / "trainers" / "back_pics"

BACK_NAMES = [
    "Brendan", "May", "Red", "Leaf",
    "RubySapphireBrendan", "RubySapphireMay", "Wally", "Steven",
]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()

    # Read the 8-entry back pic table at 0x2D95DC.
    entries = []
    for i in range(8):
        e = rom[0x2D95DC + i * 8 : 0x2D95DC + (i + 1) * 8]
        ptr, size, tag = struct.unpack("<IHH", e)
        entries.append((ptr, size, tag))

    problems = []
    for i, (ptr, size, tag) in enumerate(entries):
        data = rom[ptr - 0x08000000 : ptr - 0x08000000 + size]
        if len(data) != size:
            problems.append(f"{BACK_NAMES[i]}: short read {len(data)} != {size}")
    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        OUT_DIR.mkdir(parents=True, exist_ok=True)
        for i, (ptr, size, tag) in enumerate(entries):
            data = rom[ptr - 0x08000000 : ptr - 0x08000000 + size]
            (OUT_DIR / f"{BACK_NAMES[i]}.4bpp").write_bytes(data)

    # Rewrite gTrainerBackPicTable in data_b_mid2b6.s.
    raw = MID2B6_S.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")
    new_lines = list(lines)
    for i, line in enumerate(lines):
        if "gTrainerBackPicTable:" in line:
            block = []
            for k, (ptr, size, tag) in enumerate(entries):
                block.append(f"\t.4byte gTrainerBackPic_{BACK_NAMES[k]}")
                block.append(f"\t.hword 0x{size:X}")
                block.append(f"\t.hword {tag}")
            new_lines[i + 1] = "\n".join(block)
    if not args.check:
        MID2B6_S.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))

    # Split the remaining UnownQ tail incbin in pokemon_main.s into the 8
    # back pic blocks + leftover (0xD77524..0xD77994).
    raw2 = MAIN_S.read_bytes()
    crlf2 = b"\r\n" in raw2
    lines2 = raw2.decode("utf-8").split("\r\n" if crlf2 else "\n")
    new2 = list(lines2)
    for i, line in enumerate(lines2):
        if re.match(r'^\s*\.incbin\s+"baserom_jp\.gba",\s*0xD66524', line, re.I):
            block = []
            for k, (ptr, size, tag) in enumerate(entries):
                block.append(f"\t.globl gTrainerBackPic_{BACK_NAMES[k]}")
                block.append(f"gTrainerBackPic_{BACK_NAMES[k]}: @ 0x{ptr:X}")
                block.append(f'\t.incbin "graphics/trainers/back_pics/{BACK_NAMES[k]}.4bpp"')
            block.append('\t.incbin "baserom_jp.gba", 0xD77524, 0x470')
            new2[i] = "\n".join(block)
            break
    if not args.check:
        MAIN_S.write_bytes(("\r\n".join(new2) if crlf2 else "\n".join(new2)).encode("utf-8"))

    print(f"{'Check' if args.check else 'Extracted'}: 8 trainer back pics "
          f"-> {OUT_DIR}")


if __name__ == "__main__":
    main()
