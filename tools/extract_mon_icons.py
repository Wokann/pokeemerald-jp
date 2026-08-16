#!/usr/bin/env python3
"""Extract JP pokemon icons from gMonShinyPalette tails.

Each gMonShinyPalette_<X> tail incbin (0x420 bytes) in
data/data_b2d_gfx_pokemon_main.s is actually the species icon: 0x400 bytes of
32x64 4bpp data followed by 0x20 leftover. gMonIconTable (data_b_mid57_a.s)
points at these tails; icons match pokeemerald's
graphics/pokemon/<species>/icon.4bpp byte-for-byte.

Usage:
  python3 tools/extract_mon_icons.py            # extract + rewrite
  python3 tools/extract_mon_icons.py --check    # verify only
"""

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
MAIN_S = ROOT / "data" / "data_b2d_gfx_pokemon_main.s"
MID57A_S = ROOT / "data" / "data_b2d_mid57_a.s"
OUT_DIR = ROOT / "graphics" / "pokemon"
US_ICON_C = Path("/home/kenny/pokeemerald/src/pokemon_icon.c")

PAT_LBL = re.compile(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]+)$")
PAT_INC = re.compile(
    r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
)


def us_icon_names():
    """SPECIES index -> gMonIcon_<name> from US pokemon_icon.c."""
    mapping = []
    for line in US_ICON_C.read_text(encoding="utf-8").splitlines():
        m = re.match(r"^\s*\[\s*SPECIES_(\w+)\s*\]\s*=\s*gMonIcon_(\w+)", line)
        if m:
            mapping.append(m.group(2))
    return mapping


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    names = us_icon_names()
    if len(names) != 440:
        sys.exit(f"expected 440 US icon entries, got {len(names)}")

    # Read gMonIconTable (440 pointers) at 0x8556804.
    ptrs = []
    for i in range(440):
        p = struct.unpack("<I", rom[0x556804 + i * 4 : 0x556804 + (i + 1) * 4])[0]
        ptrs.append(p)

    # Map each unique position to one canonical label name (first occurrence).
    pos_name = {}
    for k, p in enumerate(ptrs):
        if p not in pos_name:
            pos_name[p] = names[k]
    pos_idx = {p: next(k for k, pp in enumerate(ptrs) if pp == p) for p in pos_name}

    problems = []
    seen = {}
    for i, p in enumerate(ptrs):
        if p in seen:
            continue
        data = rom[p - 0x08000000 : p - 0x08000000 + 0x400]
        if len(data) != 0x400:
            problems.append(f"icon {i}: short read")
        seen[p] = i

    if problems:
        print("PROBLEMS:")
        for p in problems[:10]:
            print("  ", p)
        sys.exit(1)

    # Extract icons.
    if not args.check:
        for p, idx in seen.items():
            sp = OUT_DIR / names[idx].lower()
            sp.mkdir(parents=True, exist_ok=True)
            (sp / "icon.4bpp").write_bytes(rom[p - 0x08000000 : p - 0x08000000 + 0x400])

    # Rewrite gMonIconTable in mid57_a.s: label + first-pointer address comment.
    raw = MID57A_S.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")
    edits = {}
    for i, line in enumerate(lines):
        if re.match(r"^gMonIconTable:\s*@", line):
            # duplicate label on the next line
            if i + 1 < len(lines) and re.match(r"^gMonIconTable:\s*@", lines[i + 1]):
                edits[i + 1] = None  # delete
            # first .4byte data line right after the label(s)
            j = i + 1
            while j < len(lines) and re.match(r"^gMonIconTable:\s*@", lines[j]):
                j += 1
            rows = [f"\t.4byte gMonIcon_{pos_name[p]}" for p in ptrs]
            edits[j] = rows
            break
    if not args.check:
        new_lines = list(lines)
        for idx in sorted(edits, reverse=True):
            if edits[idx] is None:
                del new_lines[idx]
            else:
                new_lines[idx : idx + 1] = edits[idx]
        MID57A_S.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))

    # Split icon data out of the containing incbins across all data/*.s.
    import glob as _glob
    for f in sorted(_glob.glob(str(ROOT / "data" / "*.s"))):
        raw2 = Path(f).read_bytes()
        crlf2 = b"\r\n" in raw2
        lines2 = raw2.decode("utf-8").split("\r\n" if crlf2 else "\n")
        inc_lines = []  # (line_idx, off, size)
        for i, line in enumerate(lines2):
            im = PAT_INC.match(line)
            if im:
                inc_lines.append((i, int(im.group(1), 16), int(im.group(2), 16)))
        edits2 = {}
        for inc_idx, off, size in inc_lines:
            inner = []
            for p in pos_name:
                if off <= p - 0x08000000 < off + size:
                    inner.append(p)
            if not inner:
                continue
            inner.sort()
            block = []
            cursor = off
            for p in inner:
                po = p - 0x08000000
                if po > cursor:
                    block.append(f'\t.incbin "baserom_jp.gba", 0x{cursor:X}, 0x{po - cursor:X}')
                name = pos_name[p].lower()
                block.append(f"\t.globl gMonIcon_{pos_name[p]}")
                block.append(f"gMonIcon_{pos_name[p]}: @ 0x{p:X}")
                block.append(f'\t.incbin "graphics/pokemon/{name}/icon.4bpp"')
                cursor = po + 0x400
            if cursor < off + size:
                block.append(f'\t.incbin "baserom_jp.gba", 0x{cursor:X}, 0x{off + size - cursor:X}')
            edits2[inc_idx] = block
        if edits2 and not args.check:
            new2 = list(lines2)
            for idx in sorted(edits2, reverse=True):
                new2[idx : idx + 1] = edits2[idx]
            Path(f).write_bytes(("\r\n".join(new2) if crlf2 else "\n".join(new2)).encode("utf-8"))

    print(f"{'Check' if args.check else 'Extracted'}: {len(seen)} unique icons "
          f"-> {OUT_DIR}")


if __name__ == "__main__":
    main()
