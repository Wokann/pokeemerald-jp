#!/usr/bin/env python3
"""Resolve the gUnknown_82D961C palette table and finish the UnownQ tail.

The table (8 entries of ptr+u32) is a palette alias list: 6 entries point at
trainer front palettes already extracted, 2 point at standalone palettes at
0x8D77524/0x8D7754C (inside the last UnownQ tail incbin). The table is
rewritten to label references, the 2 standalone palettes are extracted, and
the tail incbin is split (2 palettes + 0x420 leftover).

Usage:
  python3 tools/fix_unknown_82D961C.py            # fix + rewrite
  python3 tools/fix_unknown_82D961C.py --check    # verify only
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
OUT_DIR = ROOT / "graphics" / "trainers" / "palettes"
US_TRAINERS_H = Path("/home/kenny/pokeemerald/src/data/graphics/trainers.h")


def us_trainer_names():
    names = []
    for line in US_TRAINERS_H.read_text(encoding="utf-8").splitlines():
        m = re.match(r"const u32 gTrainerFrontPic_(\w+)\[\]", line)
        if m:
            names.append(m.group(1))
    return names


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    names = us_trainer_names()

    # gUnknown_82D961C: 8 x (ptr, u32)
    entries = []
    for i in range(8):
        e = rom[0x2D961C + i * 8 : 0x2D961C + (i + 1) * 8]
        ptr, val = struct.unpack("<II", e)
        entries.append((ptr, val))

    # front palette pointers (93) for alias resolution.
    front_pals = [
        struct.unpack("<I", rom[0x2D91CC + i * 8 : 0x2D91CC + i * 8 + 4])[0]
        for i in range(93)
    ]
    alias = {}
    for i, (ptr, val) in enumerate(entries):
        for k in range(93):
            if front_pals[k] == ptr:
                alias[i] = k
                break
    standalone = [i for i in range(8) if i not in alias]
    print(f"alias: {sorted(alias)}, standalone: {standalone}")

    # Extract the 2 standalone palettes.
    if not args.check:
        OUT_DIR.mkdir(parents=True, exist_ok=True)
        for i in standalone:
            off = entries[i][0] - 0x08000000
            data = rom[off : off + 40]
            (OUT_DIR / f"gUnknown_82D961C_{i}.gbapal.lz").write_bytes(data)

    # Rewrite the table in data_b_mid2b6.s.
    raw = MID2B6_S.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")
    new_lines = list(lines)
    for i, line in enumerate(lines):
        if "gUnknown_82D961C:" in line:
            block = []
            for k, (ptr, val) in enumerate(entries):
                if k in alias:
                    block.append(f"\t.4byte gTrainerPalette_{names[alias[k]]}")
                else:
                    block.append(f"\t.4byte gUnknown_82D961C_{k}_Pal")
                block.append(f"\t.4byte {val}")
            new_lines[i + 1] = "\n".join(block)
    if not args.check:
        MID2B6_S.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))

    # Split the last UnownQ tail incbin (0xD77524..0xD77994).
    raw2 = MAIN_S.read_bytes()
    crlf2 = b"\r\n" in raw2
    lines2 = raw2.decode("utf-8").split("\r\n" if crlf2 else "\n")
    new2 = list(lines2)
    for i, line in enumerate(lines2):
        if re.match(r'^\s*\.incbin\s+"baserom_jp\.gba",\s*0xD77524', line, re.I):
            block = []
            for k in standalone:
                off = entries[k][0] - 0x08000000
                block.append(f"\t.globl gUnknown_82D961C_{k}_Pal")
                block.append(f"gUnknown_82D961C_{k}_Pal: @ 0x{entries[k][0]:X}")
                block.append(f'\t.incbin "graphics/trainers/palettes/gUnknown_82D961C_{k}.gbapal.lz"')
            block.append('\t.incbin "baserom_jp.gba", 0xD77574, 0x420')
            new2[i] = "\n".join(block)
            break
    if not args.check:
        MAIN_S.write_bytes(("\r\n".join(new2) if crlf2 else "\n".join(new2)).encode("utf-8"))

    print(f"{'Check' if args.check else 'Fixed'}: gUnknown_82D961C table "
          f"({len(alias)} alias + {len(standalone)} standalone)")


if __name__ == "__main__":
    main()
