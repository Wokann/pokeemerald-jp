#!/usr/bin/env python3
"""Extract JP front pic resources (gMonFrontPic_*) from baserom_jp.gba.

This is part of the pokeemerald-jp decompilation workflow:
  - Parses data/data_b2d_gfx_front.s for the 416 gMonFrontPic_* labels.
  - Writes each front pic to graphics/pokemon/<species>/anim_front.4bpp.lz,
    following pokeemerald's resource layout (the path mapping is taken from
    pokeemerald's src/anim_mon_front_pics.c, and cached in
    tools/front_pic_map.txt so the script stays self-contained afterwards).
  - Rewrites the .s incbin lines to reference the new .lz files.

JP ROM quirk: the UnownQuestionMark entry is followed by ~0x674DA bytes of
0xFF padding. Only the actual LZ stream is extracted as the .lz resource; the
padding stays as an incbin in the .s file so the ROM layout is unchanged.

Usage:
  python3 tools/extract_front_pics.py            # extract + rewrite .s
  python3 tools/extract_front_pics.py --check    # verify only (no writes)
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
FRONT_S_PATH = ROOT / "data" / "data_b2d_gfx_front.s"
MAP_CACHE = ROOT / "tools" / "front_pic_map.txt"
US_ANIM_FRONT_PICS = Path("/home/kenny/pokeemerald/src/anim_mon_front_pics.c")


def lz_stream_len(data, out_size):
    """Return the byte length of a pokemon-toolchain LZ stream that decompresses
    to out_size bytes (header: 0x10 + 24-bit size; match: (b1 >> 4) + 3 len,
    12-bit distance). Returns None if the stream cannot be parsed."""
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


def load_us_mapping():
    """Build {gMonFrontPic suffix: relative .lz path} from pokeemerald's
    anim_mon_front_pics.c. Handles both INCGFX_U32("x.png", ".4bpp.lz") and
    INCGFX_U32("x.4bpp", ".lz")."""
    mapping = {}
    if US_ANIM_FRONT_PICS.exists():
        for line in US_ANIM_FRONT_PICS.read_text(encoding="utf-8").splitlines():
            m = re.match(
                r'const u32 gMonFrontPic_(\w+)\[\] = INCGFX_U32\("([^"]+)"\s*,\s*"([^"]+)"',
                line,
            )
            if m:
                name, base, suffix = m.groups()
                if base.endswith(".png"):
                    # PNG source -> gbagfx produces <name>.4bpp.lz
                    mapping[name] = base[: -len(".png")] + ".4bpp.lz"
                elif base.endswith(".4bpp"):
                    # Already 4bpp source -> gbagfx produces <name>.4bpp.lz
                    mapping[name] = base + ".lz"
                else:
                    mapping[name] = f"{base}{suffix}"
    elif MAP_CACHE.exists():
        for line in MAP_CACHE.read_text(encoding="utf-8").splitlines():
            name, path = line.split()
            mapping[name] = path
    else:
        sys.exit("No mapping source available: pokeemerald repo or front_pic_map.txt")
    return mapping


def parse_front_s():
    """Return [(name, rom_addr, incbin_off, incbin_size, line_idx, cur_ref)].

    cur_ref is the .lz path currently referenced by the .s line, or None when
    the line still incbins from baserom_jp.gba.
    """
    entries = []
    lines = FRONT_S_PATH.read_text(encoding="utf-8").splitlines()
    for i, line in enumerate(lines):
        m = re.match(r"^gMonFrontPic_(\w+):\s*@\s*0x([0-9A-Fa-f]+)$", line)
        if not m:
            continue
        name = m.group(1)
        addr = int(m.group(2), 16)
        im = re.match(
            r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)',
            lines[i + 1],
        )
        if im:
            off = int(im.group(1), 16)
            size = int(im.group(2), 16)
            cur_ref = None
        else:
            off = size = None
            fm = re.match(r'\s*\.incbin\s+"([^"]+)"', lines[i + 1])
            cur_ref = fm.group(1) if fm else None
        entries.append((name, addr, off, size, i, cur_ref))
    return lines, entries


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    mapping = load_us_mapping()
    rom = ROM_PATH.read_bytes()
    lines, entries = parse_front_s()

    # Cache the mapping for future self-contained runs.
    if not args.check and not MAP_CACHE.exists():
        MAP_CACHE.write_text(
            "".join(f"{k} {v}\n" for k, v in sorted(mapping.items())),
            encoding="utf-8",
        )

    missing = [n for n, *_ in entries if n not in mapping]
    if missing:
        sys.exit(f"No US mapping for: {missing}")

    problems = []
    new_lines = list(lines)
    for name, addr, off, size, idx, cur_ref in entries:
        rel_path = mapping[name]
        out_path = ROOT / rel_path
        if off is None:
            # Already extracted earlier; migrate the existing .lz resource.
            src_path = ROOT / cur_ref
            if not src_path.exists():
                problems.append(f"{name}: referenced {cur_ref} does not exist")
                continue
            data = src_path.read_bytes()
        else:
            data = rom[off : off + size]
        out_size = (data[3] << 16) | (data[2] << 8) | data[1]
        if data[0] != 0x10:
            problems.append(f"{name}: bad LZ type byte {data[0]:#x}")
            continue
        stream_len = lz_stream_len(data, out_size)
        if stream_len is None:
            problems.append(f"{name}: LZ stream does not decompress to 0x{out_size:X}")
            continue

        if name == "UnownQuestionMark" and off is not None:
            # Only the real LZ stream belongs to the pic; the rest is 0xFF pad.
            pic_bytes = data[:stream_len]
            tail_off = off + stream_len
            tail_size = size - stream_len
            out_path.parent.mkdir(parents=True, exist_ok=True)
            out_path.write_bytes(pic_bytes)
            new_lines[idx + 1] = (
                f'\t.incbin "{rel_path}"'
                f'\n\t.incbin "baserom_jp.gba", 0x{tail_off:x}, 0x{tail_size:x}'
            )
            # sanity: the padding really is 0xFF
            if data[stream_len:].count(0xFF) / tail_size < 0.999:
                problems.append(f"{name}: unexpected non-0xFF padding tail")
        else:
            out_path.parent.mkdir(parents=True, exist_ok=True)
            out_path.write_bytes(data)
            new_lines[idx + 1] = f'\t.incbin "{rel_path}"'

    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        FRONT_S_PATH.write_text("\n".join(new_lines) + "\n", encoding="utf-8")
        print(f"Extracted {len(entries)} front pics, rewrote {FRONT_S_PATH.name}")
    else:
        print(f"Check OK: {len(entries)} front pics parse cleanly")


if __name__ == "__main__":
    main()
