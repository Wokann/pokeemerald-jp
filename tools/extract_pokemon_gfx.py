#!/usr/bin/env python3
"""Extract JP pokemon battle gfx resources from baserom_jp.gba.

Handles the four resource families in data/data_b2d_gfx_pokemon_main.s and
data/data_b2d_gfx_pokemon_none.s:
  gMonStillFrontPic_*  -> graphics/pokemon/<species>/front.4bpp.lz
  gMonPalette_*        -> graphics/pokemon/<species>/normal.gbapal.lz
  gMonBackPic_*        -> graphics/pokemon/<species>/back.4bpp.lz
  gMonShinyPalette_*   -> graphics/pokemon/<species>/shiny.gbapal.lz

Path mapping follows pokeemerald (src/data/graphics/pokemon.h plus
src/graphics.c for the CircledQuestionMark entries) and is cached in
tools/pokemon_gfx_map.txt.

JP ROM quirks handled here:
  - LZ streams are followed by up to 3 bytes of 0x00 alignment padding;
    those entries are extracted whole (padding included).
  - ShinyPalette entries carry ~0x420 extra bytes of leftover data after the
    actual 32-byte palette stream, and the Unown back pics carry ~0x400
    leftover bytes. For those, only the LZ stream becomes the .lz resource and
    the tail stays as a baserom incbin, preserving ROM layout.

Usage:
  python3 tools/extract_pokemon_gfx.py            # extract + rewrite .s
  python3 tools/extract_pokemon_gfx.py --check    # verify only
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
S_FILES = [
    ROOT / "data" / "data_b2d_gfx_pokemon_main.s",
    ROOT / "data" / "data_b2d_gfx_pokemon_none.s",
]
MAP_CACHE = ROOT / "tools" / "pokemon_gfx_map.txt"
US_SOURCES = [
    Path("/home/kenny/pokeemerald/src/data/graphics/pokemon.h"),
    Path("/home/kenny/pokeemerald/src/graphics.c"),
]


def lz_stream_len(data, out_size):
    """Length of a pokemon-toolchain LZ stream that decompresses to out_size
    bytes (header: 0x10 + 24-bit size; match: (b1 >> 4) + 3 len, 12-bit dist)."""
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


def resource_name(kind):
    return {
        "StillFrontPic": "front.4bpp.lz",
        "BackPic": "back.4bpp.lz",
        "Palette": "normal.gbapal.lz",
        "ShinyPalette": "shiny.gbapal.lz",
    }[kind]


def load_us_mapping():
    """{kind: {suffix_name: relative .lz path}} from pokeemerald sources."""
    mapping = {k: {} for k in ("StillFrontPic", "Palette", "BackPic", "ShinyPalette")}
    pat = re.compile(
        r'const u32 gMon(StillFrontPic|Palette|BackPic|ShinyPalette)_(\w+)\[\] = '
        r'INCGFX_U32\("([^"]+)"\s*,\s*"[^"]+"'
    )
    for src in US_SOURCES:
        if not src.exists():
            continue
        for line in src.read_text(encoding="utf-8").splitlines():
            m = pat.search(line)
            if not m:
                continue
            kind, name, path = m.groups()
            if path.endswith(".png"):
                out = path[: -len(".png")] + ".4bpp.lz"
            elif path.endswith(".pal"):
                out = path[: -len(".pal")] + ".gbapal.lz"
            elif path.endswith(".4bpp") or path.endswith(".gbapal"):
                out = path + ".lz"
            else:
                continue
            mapping[kind][name] = out
    if not all(mapping.values()):
        # Fall back to the cached map (self-contained runs).
        if MAP_CACHE.exists():
            mapping = {k: {} for k in mapping}
            for line in MAP_CACHE.read_text(encoding="utf-8").splitlines():
                kind, name, path = line.split()
                mapping[kind][name] = path
    return mapping


def parse_s(path):
    """[(kind, name, off, size, line_idx)]"""
    entries = []
    pat_label = re.compile(
        r"^gMon(StillFrontPic|Palette|BackPic|ShinyPalette)_(\w+):\s*@\s*0x([0-9A-Fa-f]+)$"
    )
    pat_inc = re.compile(
        r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
    )
    lines = path.read_text(encoding="utf-8").splitlines()
    for i, line in enumerate(lines):
        m = pat_label.match(line)
        if not m:
            continue
        kind, name = m.group(1), m.group(2)
        im = pat_inc.match(lines[i + 1])
        if im:
            entries.append((kind, name, int(im.group(1), 16), int(im.group(2), 16), i))
    return lines, entries


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    mapping = load_us_mapping()
    rom = ROM_PATH.read_bytes()

    if not args.check and not MAP_CACHE.exists():
        MAP_CACHE.write_text(
            "".join(
                f"{k} {n} {p}\n"
                for k in ("StillFrontPic", "Palette", "BackPic", "ShinyPalette")
                for n, p in sorted(mapping[k].items())
            ),
            encoding="utf-8",
        )

    all_entries = []
    for sfile in S_FILES:
        lines, entries = parse_s(sfile)
        all_entries.append((sfile, lines, entries))

    problems = []
    missing = [
        (k, n)
        for _, _, entries in all_entries
        for k, n, *_ in entries
        if n not in mapping[k]
    ]
    if missing:
        sys.exit(f"No US mapping for: {missing[:20]}")

    total = 0
    split = 0
    for sfile, lines, entries in all_entries:
        new_lines = list(lines)
        for kind, name, off, size, idx in entries:
            data = rom[off : off + size]
            out_size = (data[3] << 16) | (data[2] << 8) | data[1]
            if data[0] != 0x10:
                problems.append(f"{name}: bad LZ type byte {data[0]:#x}")
                continue
            stream_len = lz_stream_len(data, out_size)
            if stream_len is None:
                problems.append(f"{name}: LZ stream does not decompress to 0x{out_size:X}")
                continue

            rel_path = mapping[kind][name]
            out_path = ROOT / rel_path
            tail = data[stream_len:]
            is_pad = len(tail) <= 4 and all(b == 0 for b in tail)
            if is_pad:
                out_path.parent.mkdir(parents=True, exist_ok=True)
                out_path.write_bytes(data)
                new_lines[idx + 1] = f'\t.incbin "{rel_path}"'
            else:
                # Split: keep only the real LZ stream in the resource.
                out_path.parent.mkdir(parents=True, exist_ok=True)
                out_path.write_bytes(data[:stream_len])
                new_lines[idx + 1] = (
                    f'\t.incbin "{rel_path}"'
                    f"\n\t.incbin \"baserom_jp.gba\", 0x{off + stream_len:x}, 0x{size - stream_len:x}"
                )
                split += 1
            total += 1
        if not args.check:
            sfile.write_text("\n".join(new_lines) + "\n", encoding="utf-8")

    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        sys.exit(1)

    print(f"{'Check' if args.check else 'Extracted'}: {total} entries "
          f"({split} split with tail incbin)")


if __name__ == "__main__":
    main()
