#!/usr/bin/env python3
"""Summarize the remaining baserom incbins in data/*.s.

Outputs a per-file breakdown (block count, bytes, LZ vs raw) and a CSV of
every remaining block (label, offset, size, first bytes) to help plan the
next decompilation targets.

Usage:
  python3 tools/analyze_remaining.py [--csv out.csv]
"""

import argparse
import glob
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

PAT_LBL = re.compile(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]+)$")
PAT_INC = re.compile(
    r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--csv", help="write per-block CSV to this path")
    args = ap.parse_args()

    rom = (ROOT / "baserom_jp.gba").read_bytes()
    rows = []
    for f in sorted(glob.glob(str(ROOT / "data" / "*.s"))):
        lines = Path(f).read_text(encoding="utf-8", errors="replace").splitlines()
        cur = None
        for line in lines:
            m = PAT_LBL.match(line)
            if m:
                cur = m.group(1)
            im = PAT_INC.match(line)
            if im and cur:
                off = int(im.group(1), 16)
                size = int(im.group(2), 16)
                d = rom[off : off + 4]
                lz = size >= 4 and d[0] == 0x10
                rows.append((f, cur, off, size, lz))
                cur = None

    total_bytes = 0
    per_file = {}
    lz = raw = 0
    for f, name, off, size, is_lz in rows:
        total_bytes += size
        per_file[f] = per_file.get(f, [0, 0, 0])
        per_file[f][0] += 1
        per_file[f][1] += size
        if is_lz:
            lz += 1
            per_file[f][2] += 1
        else:
            raw += 1

    print(f"remaining blocks: {len(rows)} (LZ {lz}, raw {raw}), "
          f"{total_bytes / 1048576:.2f} MB")
    print(f"{'file':40s} {'blocks':>6s} {'bytes':>10s} {'LZ':>4s}")
    for f in sorted(per_file, key=lambda x: -per_file[x][1]):
        c, b, l = per_file[f]
        print(f"{Path(f).name:40s} {c:6d} {b:10d} {l:4d}")

    if args.csv:
        with open(args.csv, "w") as out:
            out.write("file,label,offset,size,lz\n")
            for f, name, off, size, is_lz in rows:
                out.write(f"{Path(f).name},{name},0x{off:X},{size},{int(is_lz)}\n")
        print(f"CSV written to {args.csv}")


if __name__ == "__main__":
    main()
