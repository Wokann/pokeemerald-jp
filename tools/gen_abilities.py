#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate abilities.h as _(\"kana\") text (8-byte 0x00-padded slots)."""
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


def decode_kana(slot):
    out = []
    i = 0
    while i < len(slot) and slot[i] != 0xFF:
        for L in (2, 1):
            if slot[i:i + L] in rev:
                out.append(rev[slot[i:i + L]])
                i += L
                break
        else:
            out.append("?")
            i += 1
    return "".join(out)


us_file = ROOT.parent / "pokeemerald" / "src" / "data" / "text" / "abilities.h"
us_text = us_file.read_text(encoding="utf-8")
# only the description pointer table: [ABILITY_X] = s\w+Description
ability_idx = re.findall(r'^\s*\[(ABILITY_\w+)\] = s\w+Description,', us_text, re.M)
print("US ability description entries:", len(ability_idx))

rom = (ROOT / "baserom_jp.gba").read_bytes()
lines = ["const u8 gAbilityNames[ABILITIES_COUNT][8] = {"]
for i, ab in enumerate(ability_idx):
    slot = rom[0x2EBDC4 + i * 8: 0x2EBDC4 + (i + 1) * 8]
    kana = decode_kana(slot)
    lines.append(f'    [{ab}] = _("{kana}"),')
lines.append("};")
lines.append("")
lines.append("// JP stores ability descriptions inline in fixed 19-byte slots")
lines.append("// (kana + 0x00 word spaces + 0xFF EOS + 0x00 padding).")
lines.append("const u8 gAbilityDescriptionPointers[ABILITIES_COUNT][19] = {")
for i, ab in enumerate(ability_idx):
    slot = rom[0x2EC034 + i * 19: 0x2EC034 + (i + 1) * 19]
    kana = decode_kana(slot)
    lines.append(f'    [{ab}] = _("{kana}"),')
lines.append("};")

out = ROOT / "src/data/text/abilities.h"
out.write_text("\n".join(lines) + "\n", encoding="utf-8")
print(f"written {out}")
for l in lines[:5]:
    print(l)
print("...")
for l in lines[-4:]:
    print(l)
