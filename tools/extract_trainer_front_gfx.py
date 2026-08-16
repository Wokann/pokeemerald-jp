#!/usr/bin/env python3
"""Extract JP trainer front pics + palettes.

The 93 trainer front pics live inside gMonBackPic_UnownQuestionMark's tail
incbin in data/data_b2d_gfx_pokemon_main.s (0xD51E6C..0xD66524), one LZ
front pic followed by one LZ palette per trainer. The tables in
data/data_b_mid2b5.s (gTrainerFrontPicTable / gTrainerFrontPicPaletteTable)
are rewritten to reference per-trainer labels.

Resource layout follows pokeemerald:
  graphics/trainers/front_pics/<trainer>.4bpp.lz
  graphics/trainers/front_pics/<trainer>.gbapal.lz

Usage:
  python3 tools/extract_trainer_front_gfx.py            # extract + rewrite
  python3 tools/extract_trainer_front_gfx.py --check    # verify only
"""

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
MAIN_S = ROOT / "data" / "data_b2d_gfx_pokemon_main.s"
MID2B5_S = ROOT / "data" / "data_b_mid2b5.s"
OUT_DIR = ROOT / "graphics" / "trainers" / "front_pics"
US_TRAINERS_H = Path("/home/kenny/pokeemerald/src/data/graphics/trainers.h")


def lz_stream_len(data):
    if len(data) < 4 or data[0] != 0x10:
        return None
    out_size = (data[3] << 16) | (data[2] << 8) | data[1]
    i = 4
    out = 0
    while out < out_size:
        if i >= len(data):
            return None
        flags = data[i]
        i += 1
        for bit in range(8):
            if out >= out_size:
                break
            if not (flags & (0x80 >> bit)):
                if i >= len(data):
                    return None
                out += 1
                i += 1
            else:
                if i + 1 >= len(data):
                    return None
                b1, b2 = data[i], data[i + 1]
                i += 2
                out += (b1 >> 4) + 3
    return i


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
    if len(names) != 93:
        sys.exit(f"expected 93 US trainer names, got {len(names)}")

    # Read JP tables.
    front = []  # (ptr, size, tag)
    for i in range(93):
        e = rom[0x2D8EE4 + i * 8 : 0x2D8EE4 + (i + 1) * 8]
        front.append(struct.unpack("<IHH", e))
    pal = []
    for i in range(93):
        e = rom[0x2D91CC + i * 8 : 0x2D91CC + (i + 1) * 8]
        pal.append(struct.unpack("<I", e[:4])[0])

    problems = []
    for i in range(93):
        f_off = front[i][0] - 0x08000000
        p_off = pal[i] - 0x08000000
        nxt_f = front[i + 1][0] - 0x08000000 if i + 1 < 93 else 0xD66524
        if lz_stream_len(rom[f_off : f_off + 0x20000]) is None:
            problems.append(f"{names[i]}: front pic not LZ")
        if lz_stream_len(rom[p_off : p_off + 0x200]) is None:
            problems.append(f"{names[i]}: palette not LZ")
    if problems:
        print("PROBLEMS:")
        for p in problems[:10]:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        OUT_DIR.mkdir(parents=True, exist_ok=True)
        for i in range(93):
            f_off = front[i][0] - 0x08000000
            p_off = pal[i] - 0x08000000
            nxt_f = front[i + 1][0] - 0x08000000 if i + 1 < 93 else 0xD66524
            (OUT_DIR / f"{names[i]}.4bpp.lz").write_bytes(rom[f_off:p_off])
            (OUT_DIR / f"{names[i]}.gbapal.lz").write_bytes(rom[p_off:nxt_f])

    # Rewrite data_b_mid2b5.s tables.
    raw = MID2B5_S.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")
    new_lines = list(lines)
    for i, line in enumerate(lines):
        if "gTrainerFrontPicTable:" in line:
            block = []
            for k in range(93):
                block.append(f"\t.4byte gTrainerFrontPic_{names[k]}")
                block.append(f"\t.hword 0x{front[k][1]:X}")
                block.append(f"\t.hword {front[k][2]}")
            new_lines[i + 1] = "\n".join(block)
        elif "gTrainerFrontPicPaletteTable:" in line:
            block = []
            for k in range(93):
                block.append(f"\t.4byte gTrainerPalette_{names[k]}")
                block.append(f"\t.4byte {k}")
            # The original incbin (0x3D0) is 93 entries + 29 extra table
            # entries (0x2D94B4..0x2D959C); keep the extra part as incbin.
            block.append(f'\t.incbin "baserom_jp.gba", 0x2D94B4, 0xE8')
            new_lines[i + 1] = "\n".join(block)
    if not args.check:
        MID2B5_S.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))

    # Rewrite the UnownQuestionMark tail incbin in pokemon_main.s.
    raw2 = MAIN_S.read_bytes()
    crlf2 = b"\r\n" in raw2
    lines2 = raw2.decode("utf-8").split("\r\n" if crlf2 else "\n")
    new2 = list(lines2)
    for i, line in enumerate(lines2):
        if re.match(r'^\s*\.incbin\s+"baserom_jp\.gba",\s*0xD51A6B', line, re.I) or \
           re.match(r'^\s*\.incbin\s+"baserom_jp\.gba",\s*0xd51a6b', line):
            block = ['\t.incbin "baserom_jp.gba", 0xD51A6B, 0x401']
            for k in range(93):
                f_off = front[k][0] - 0x08000000
                p_off = pal[k] - 0x08000000
                nxt_f = front[k + 1][0] - 0x08000000 if k + 1 < 93 else 0xD66524
                block.append(f"\t.globl gTrainerFrontPic_{names[k]}")
                block.append(f"gTrainerFrontPic_{names[k]}: @ 0x{front[k][0]:X}")
                block.append(f'\t.incbin "graphics/trainers/front_pics/{names[k]}.4bpp.lz"')
                block.append(f"\t.globl gTrainerPalette_{names[k]}")
                block.append(f"gTrainerPalette_{names[k]}: @ 0x{pal[k]:X}")
                block.append(f'\t.incbin "graphics/trainers/front_pics/{names[k]}.gbapal.lz"')
            # remaining tail (back pics etc.) stays as incbin
            tail_end = 0xD51A6B + 0x25F29
            block.append(f'\t.incbin "baserom_jp.gba", 0xD66524, 0x{tail_end - 0xD66524:X}')
            new2[i] = "\n".join(block)
            break
    if not args.check:
        MAIN_S.write_bytes(("\r\n".join(new2) if crlf2 else "\n".join(new2)).encode("utf-8"))

    print(f"{'Check' if args.check else 'Extracted'}: 93 trainer front pics "
          f"+ palettes -> {OUT_DIR}")


if __name__ == "__main__":
    main()
