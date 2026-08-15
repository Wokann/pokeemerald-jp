#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate nature_names.h: static kana strings + gNatureNamePointers."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

fwd = {}
for l in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
    m = re.match(r"^'(.+?)'\s*=\s*([0-9A-Fa-f ]+)$", l)
    if m:
        try:
            fwd[m.group(1)] = bytes(int(x, 16) for x in m.group(2).split())
        except ValueError:
            pass
rev = {}
for ch, b in fwd.items():
    rev.setdefault(b, ch)


def decode(s):
    out = []
    for b in s:
        if b == 0xFF:
            break
        out.append(rev.get(bytes([b]), "?"))
    return "".join(out)


us_file = ROOT.parent / "pokeemerald" / "src" / "data" / "text" / "nature_names.h"
us_text = us_file.read_text(encoding="utf-8")
# [NATURE_X] = sYYYNatureName pairs in pointer array
ptr_pairs = re.findall(r'^\s*\[(NATURE_\w+)\] = (s\w+NatureName)', us_text, re.M)
print("US pointer entries:", len(ptr_pairs))

rom = (ROOT / "baserom_jp.gba").read_bytes()
import struct
ptrs = [struct.unpack_from("<I", rom, 0x5ECE24 + i * 4)[0] for i in range(25)]

strings = []
for i, (nature, sname) in enumerate(ptr_pairs):
    end = (ptrs[i + 1] - 0x8000000) if i + 1 < 25 else 0x5ECE24
    raw = rom[ptrs[i] - 0x8000000: end]
    text = decode(raw)
    strings.append((nature, sname, text))

lines = []
for nature, sname, text in strings:
    lines.append(f'static const u8 {sname}[] = _("{text}");')
lines.append("")
lines.append("const u8 *const gNatureNamePointers[NUM_NATURES] = {")
for nature, sname, text in strings:
    lines.append(f"    [{nature}] = {sname},")
lines.append("};")

out = ROOT / "src/data/text/nature_names.h"
out.write_text("\n".join(lines) + "\n", encoding="utf-8")
print(f"written {out}")
for l in lines[:6]:
    print(l)
