#!/usr/bin/env python3
"""One-time extractor for the historical JP tileset aggregate.

The historical input was data/data_b2d_mid30.s. Its tileset resources have
already been migrated to data/tilesets/{graphics,metatiles,headers}.inc, so
this tool no longer mutates the active source tree. ``--check`` reports that
the one-time extraction is not applicable; retaining the implementation keeps
the migration recipe available for an unstructured JP ROM baseline.

Verified against pokeemerald (same maps -> identical bytes):
  - tiles: LZ stream (pokemon toolchain format), 4-byte aligned
  - palettes: 512 bytes (16 x 16-color gbapal)
  - metatiles: metatileAttributes ptr - metatiles ptr bytes, byte-identical
    to pokeemerald's data/tilesets/*/*/metatiles.bin
  - metatileAttributes: size taken from pokeemerald's matching tileset
    (byte-identical too)
  - one tileset (EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY) is uncompressed

The giant incbin is split into per-tileset resource blocks; leftover gaps stay
as baserom incbins so the ROM byte order is unchanged.

Usage:
  python3 tools/extract_tilesets.py --check    # report migration status
"""

import argparse
import glob
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
LEGACY_S_PATH = ROOT / "data" / "data_b2d_mid30.s"
OUT_BASE = ROOT / "data" / "tilesets"
US_BASE = Path("/home/kenny/pokeemerald/data/tilesets")

PAT_TILESET = re.compile(r"^gTileset_(\w+):\s*@\s*0x([0-9A-Fa-f]+)$")
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


def us_tileset_for(metatiles_bytes):
    """Return a relative US tileset dir whose metatiles.bin matches, or None."""
    for f in glob.glob(str(US_BASE / "*" / "*" / "metatiles.bin")):
        if open(f, "rb").read() == metatiles_bytes:
            return os.path.relpath(os.path.dirname(f), US_BASE)
    return None


def attrs_size_for(metatiles_bytes):
    for f in glob.glob(str(US_BASE / "*" / "*" / "metatiles.bin")):
        if open(f, "rb").read() == metatiles_bytes:
            return os.path.getsize(f.replace("metatiles.bin", "metatile_attributes.bin"))
    return None


def parse_tilesets(lines):
    entries = []
    for i, line in enumerate(lines):
        m = PAT_TILESET.match(line)
        if not m:
            continue
        name = m.group(1)
        addr = int(m.group(2), 16)
        defs = {}
        for j in range(1, 7):
            mm = re.match(r"\s*\.(byte|4byte)\s+(\S+)\s*(?:@\s+(\w+))?", lines[i + j])
            if mm and mm.group(3):
                v = mm.group(2)
                defs[mm.group(3)] = int(v, 16) - 0x08000000 if v.startswith("0x") else v
        entries.append((name, addr, defs, i))
    return entries


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    if not LEGACY_S_PATH.is_file():
        if args.check:
            print("Tileset extraction is not applicable: resources already live in data/tilesets/.")
            return
        sys.exit("The one-time tileset source has been migrated; use --check for its status.")

    rom = ROM_PATH.read_bytes()
    raw = LEGACY_S_PATH.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")

    entries = parse_tilesets(lines)
    print(f"tilesets: {len(entries)}")

    # Sort by tiles address to reconstruct the data layout order.
    entries.sort(key=lambda e: e[2]["tiles"])

    problems = []
    blocks = []  # (start, end, kind, name, label_suffix)
    for name, addr, defs, _ in entries:
        t, p, m, a = defs["tiles"], defs["palettes"], defs["metatiles"], defs["metatileAttributes"]
        comp = rom[addr - 0x08000000]
        if comp == 1:
            tlen = lz_stream_len(rom[t : t + 0x80000])
            if tlen is None:
                problems.append(f"{name}: tiles LZ parse failed")
                continue
            tiles_end = t + tlen
            tiles_end = (tiles_end + 3) & ~3
        else:
            tiles_end = p  # uncompressed: data runs to the palettes pointer
        if p - t != tiles_end - t:
            problems.append(f"{name}: tiles end mismatch {tiles_end - t:#x} vs {p - t:#x}")
            continue
        if p + 0x200 > len(rom):
            problems.append(f"{name}: palettes OOB")
            continue
        msz = a - m
        mt_bytes = rom[m : m + msz]
        attrs_size = attrs_size_for(mt_bytes)
        if attrs_size is None:
            problems.append(f"{name}: no US attrs match for metatiles {msz:#x}")
            continue
        blocks.append((t, p, "tiles", name, "Tiles"))
        blocks.append((p, p + 0x200, "palettes", name, "Palettes"))
        blocks.append((m, a, "metatiles", name, "Metatiles"))
        blocks.append((a, a + attrs_size, "attrs", name, "MetatileAttributes"))

    if problems:
        print("PROBLEMS:")
        for p in problems[:20]:
            print("  ", p)
        sys.exit(1)

    blocks.sort(key=lambda b: b[0])

    # US directory mapping for resource placement.
    us_dir = {}
    for name, addr, defs, _ in entries:
        m, a = defs["metatiles"], defs["metatileAttributes"]
        mt_bytes = rom[m : a]
        d = us_tileset_for(mt_bytes)
        us_dir[name] = d if d else name.lower()

    if not args.check:
        for name, addr, defs, _ in entries:
            b = blocks
            d = us_dir[name]
            t, p, m, a = defs["tiles"], defs["palettes"], defs["metatiles"], defs["metatileAttributes"]
            out = OUT_BASE / d
            out.mkdir(parents=True, exist_ok=True)
            # tiles
            tlen = lz_stream_len(rom[t : t + 0x80000])
            tiles_end = ((t + tlen) + 3) & ~3 if tlen else p
            (out / "tiles.4bpp.lz").write_bytes(rom[t:tiles_end])
            # palettes (16 x 32-byte gbapal)
            pal_dir = out / "palettes"
            pal_dir.mkdir(exist_ok=True)
            for k in range(16):
                (pal_dir / f"{k:02d}.gbapal").write_bytes(rom[p + k * 32 : p + (k + 1) * 32])
            # metatiles + attrs
            (out / "metatiles.bin").write_bytes(rom[m:a])
            attrs_size = attrs_size_for(rom[m:a])
            (out / "metatile_attributes.bin").write_bytes(rom[a : a + attrs_size])

    # Rewrite: split the giant gUnknown_830FD4C incbin into blocks + gaps.
    # Locate the giant incbin line.
    giant_idx = None
    for i, line in enumerate(lines):
        m = PAT_INC.match(line)
        if m and int(m.group(1), 16) == 0x30FD4C:
            giant_idx = i
            break
    if giant_idx is None:
        sys.exit("gUnknown_830FD4C incbin not found")

    new_lines = list(lines)

    # Replace hardcoded pointers in the tileset structs with labels.
    # (Must run before the giant incbin split: inserting lines shifts indices.)
    for name, addr, defs, idx in entries:
        for j in range(1, 7):
            mm = re.match(r"(\s*\.4byte\s+)0x([0-9A-Fa-f]+)(\s+@\s+(\w+))", new_lines[idx + j])
            if mm:
                ptr = int(mm.group(2), 16) - 0x08000000
                field = mm.group(4)
                suffix = {
                    "tiles": "Tiles",
                    "palettes": "Palettes",
                    "metatiles": "Metatiles",
                    "metatileAttributes": "MetatileAttributes",
                }.get(field)
                if suffix and ptr == defs.get(field, -1):
                    new_lines[idx + j] = (
                        f"{mm.group(1)}gTileset_{name}_{suffix}{mm.group(3)}"
                    )

    region_start = 0x30FD4C
    region_end = 0x30FD4C + 0xA7DD8
    pieces = []
    cursor = region_start
    for start, end, kind, name, suffix in blocks:
        if start > cursor:
            pieces.append((cursor, start, None, None, None))
        pieces.append((start, end, kind, name, suffix))
        cursor = end
    if cursor < region_end:
        pieces.append((cursor, region_end, None, None, None))

    out_lines = []
    for start, end, kind, name, suffix in pieces:
        if kind is None:
            out_lines.append(f'\t.incbin "baserom_jp.gba", 0x{start:X}, 0x{end - start:X}')
        else:
            d = us_dir[name]
            fname = {
                "tiles": "tiles.4bpp.lz",
                "palettes": "palettes/00.gbapal",
                "metatiles": "metatiles.bin",
                "attrs": "metatile_attributes.bin",
            }[kind]
            out_lines.append(f"gTileset_{name}_{suffix}:")
            out_lines.append(f'\t.incbin "data/tilesets/{d}/{fname}"')
            if kind == "palettes":
                for k in range(1, 16):
                    out_lines.append(f'\t.incbin "data/tilesets/{d}/palettes/{k:02d}.gbapal"')

    new_lines[giant_idx : giant_idx + 1] = out_lines

    if not args.check:
        LEGACY_S_PATH.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))
    print(f"{'Check' if args.check else 'Extracted'}: {len(blocks)//4} tilesets "
          f"-> {OUT_BASE}")


if __name__ == "__main__":
    main()
