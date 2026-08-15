#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate type_names.h as __(\"kana$$\") text with FF padding."""
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
    n = 0
    i = 0
    while i < len(slot) and slot[i] != 0xFF:
        for L in (2, 1):
            if slot[i:i + L] in rev:
                out.append(rev[slot[i:i + L]])
                i += L
                n += L
                break
        else:
            out.append("?")
            i += 1
            n += 1
    return "".join(out), n


us_types = ROOT.parent / "pokeemerald" / "src" / "battle_main.c"
text = open(us_types, encoding="utf-8").read()
idx = text.find("gTypeNames[")
body = text[idx:idx + 2000]
type_idx = re.findall(r'^\s*\[(TYPE_\w+)\]', body, re.M)
print("US type entries:", len(type_idx))

rom = (ROOT / "baserom_jp.gba").read_bytes()
lines = ["const u8 gTypeNames[NUMBER_OF_MON_TYPES][TYPE_NAME_LENGTH + 1] = {"]
for i, tp in enumerate(type_idx):
    slot = rom[0x2EBC88 + i * 5: 0x2EBC88 + (i + 1) * 5]
    kana, kana_len = decode_kana(slot)
    fill = 5 - kana_len
    assert fill >= 1, f"slot {i} too long"
    lines.append(f'    [{tp}] = __("{kana}{"$" * fill}"),')
lines.append("};")

out = ROOT / "src/data/text/type_names.h"
out.write_text("\n".join(lines) + "\n", encoding="utf-8")
print(f"written {out}")
for l in lines[:5]:
    print(l)
