#!/usr/bin/env python3
"""Extract LZ-compressed graphics from data/data_rest2c.s to graphics/misc/.

The file holds battle/roulette UI graphics. Blocks whose data starts with a
pokemon-toolchain LZ header are extracted:
  - clean blocks (stream + <=4 padding) -> whole block as <label>.4bpp.lz
  - blocks with a tail -> only the LZ stream as .lz; tail stays as incbin
Non-LZ blocks are left untouched.

Usage:
  python3 tools/extract_misc_gfx.py            # extract + rewrite .s
  python3 tools/extract_misc_gfx.py --check    # verify only
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
S_PATH = ROOT / "data" / "data_rest2c.s"
OUT_DIR = ROOT / "graphics" / "misc"

PAT_LBL = re.compile(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]+)$")
PAT_INC = re.compile(
    r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
)


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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    raw = S_PATH.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")

    blocks = []
    cur = None
    for i, line in enumerate(lines):
        m = PAT_LBL.match(line)
        if m:
            cur = (m.group(1), i)
        im = PAT_INC.match(line)
        if im and cur:
            off = int(im.group(1), 16)
            size = int(im.group(2), 16)
            blocks.append((cur[0], cur[1], off, size))
            cur = None

    problems = []
    edits = {}
    extracted = 0
    for name, idx, off, size in blocks:
        data = rom[off : off + size]
        slen = lz_stream_len(data)
        if slen is None:
            continue  # not LZ, leave alone
        tail = size - slen
        is_pad = tail <= 4 and all(b == 0 for b in data[slen:])
        rel = f"graphics/misc/{name}.4bpp.lz"
        if is_pad:
            out_bytes = data
            replacement = f'\t.incbin "{rel}"'
        else:
            out_bytes = data[:slen]
            replacement = (
                f'\t.incbin "{rel}"'
                f"\n\t.incbin \"baserom_jp.gba\", 0x{off + slen:X}, 0x{tail:X}"
            )
        if not args.check:
            OUT_DIR.mkdir(parents=True, exist_ok=True)
            (OUT_DIR / f"{name}.4bpp.lz").write_bytes(out_bytes)
        edits[idx + 1] = replacement
        extracted += 1

    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        new_lines = list(lines)
        for idx, repl in edits.items():
            new_lines[idx] = repl
        S_PATH.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))
    print(f"{'Check' if args.check else 'Extracted'}: {extracted} LZ blocks "
          f"-> {OUT_DIR}")


if __name__ == "__main__":
    main()
