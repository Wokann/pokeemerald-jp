#!/usr/bin/env python3
"""Fix song part ownership in data/data_b2c_mid8_tail.s.

Three songs have uncompiled parts that were mis-attributed to the previous
song header's incbin:
  - sSongHeader_268's incbin (0x86FCF4, 0x2C) is sSong269_Part0
  - sSongHeader_269's incbin (0x86FD2C, 0x9EC) is sSong350_Part0..8
  - sSongHeader_454's incbin (0x8B7A48, 0x25FC) is sSong455_Part0..9

This script splits those incbins into per-part labels and rewrites the song
headers' hardcoded part pointers to reference the labels. Byte order in the
ROM is unchanged.

Usage:
  python3 tools/fix_song_parts.py            # fix + rewrite .s
  python3 tools/fix_song_parts.py --check    # verify only
"""

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
S_PATH = ROOT / "data" / "data_b2c_mid8_tail.s"


def read_song_parts(rom, lines, num):
    for i, line in enumerate(lines):
        m = re.match(rf"^sSongHeader_{num}:\s*@\s*0x([0-9A-Fa-f]+)$", line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        b = rom[addr - 0x08000000 : addr - 0x08000000 + 64]
        tc = b[0]
        parts = [struct.unpack("<I", b[8 + k * 4 : 12 + k * 4])[0] for k in range(tc)]
        return i, parts
    sys.exit(f"song {num} not found")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    raw = S_PATH.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")

    # Groups: (container header whose incbin holds the parts, parts owner header)
    groups = [
        (268, 269),
        (269, 350),
        (454, 455),
    ]

    problems = []
    edits = {}  # line_idx -> list of replacement lines
    for container, owner in groups:
        c_idx, c_parts = read_song_parts(rom, lines, container)
        o_idx, o_parts = read_song_parts(rom, lines, owner)
        if not o_parts:
            problems.append(f"song {owner}: no parts")
            continue

        # The container's incbin must start exactly at the owner's first part.
        inc_idx = None
        for j in range(1, 8):
            im = re.match(
                r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)',
                lines[c_idx + j],
            )
            if im:
                inc_idx = c_idx + j
                inc_off = int(im.group(1), 16)
                inc_size = int(im.group(2), 16)
                break
        if inc_idx is None:
            problems.append(f"song {container}: no incbin after header")
            continue
        if inc_off != o_parts[0] - 0x08000000:
            problems.append(
                f"song {container}: incbin 0x{inc_off:X} != first part "
                f"0x{o_parts[0] - 0x08000000:X}"
            )
            continue

        # Split the incbin into per-part incbins.
        blocks = []
        for k, p in enumerate(o_parts):
            if k + 1 < len(o_parts):
                end = o_parts[k + 1] - 0x08000000
            else:
                end = inc_off + inc_size
            blocks.append((p - 0x08000000, end, k))
        out_lines = []
        for start, end, k in blocks:
            out_lines.append(f"sSong{owner}_Part{k}: @ 0x{start + 0x08000000:X}")
            out_lines.append(f'\t.incbin "baserom_jp.gba", 0x{start:X}, 0x{end - start:X}')
        edits[inc_idx] = out_lines

        # Rewrite the owner's hardcoded part pointers to labels.
        ptr_line = None
        for j in range(2, 8):
            if "@ tone" in lines[o_idx + j]:
                continue
            pm = re.match(r"(\s*\.4byte\s+)(.+?)(\s*@\s+parts)?$", lines[o_idx + j])
            if pm and ("0x" in pm.group(2) or "sSong" in pm.group(2)):
                ptr_line = (o_idx + j, pm.group(1), pm.group(2))
                break
        if ptr_line is None:
            problems.append(f"song {owner}: part pointer line not found")
            continue
        new_labels = ", ".join(f"sSong{owner}_Part{k}" for k in range(len(o_parts)))
        edits[ptr_line[0]] = [f"{ptr_line[1]}{new_labels}  @ parts"]

    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        new_lines = list(lines)
        for idx in sorted(edits, reverse=True):
            new_lines[idx : idx + 1] = edits[idx]
        S_PATH.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))
    print(f"{'Check' if args.check else 'Fixed'}: 3 song incbins split into "
          f"20 part labels")


if __name__ == "__main__":
    main()
