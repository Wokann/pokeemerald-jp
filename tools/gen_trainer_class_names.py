#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate trainer_class_names.h as _(\"kana\") text (0x00-padded slots)."""
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


us_file = ROOT.parent / "pokeemerald" / "src" / "data" / "text" / "trainer_class_names.h"
us_idx = re.findall(r'^\s*\[(TRAINER_CLASS_\w+)\]', us_file.read_text(encoding="utf-8"), re.M)
print("US entries:", len(us_idx))

rom = (ROOT / "baserom_jp.gba").read_bytes()
lines = ["const u8 gTrainerClassNames[][TRAINER_NAME_LENGTH + 1] = {"]
for i, tc in enumerate(us_idx):
    slot = rom[0x2E3564 + i * 11: 0x2E3564 + (i + 1) * 11]
    kana = decode_kana(slot)
    lines.append(f'    [{tc}] = _("{kana}"),')
lines.append("};")

out = ROOT / "src/data/text/trainer_class_names.h"
out.write_text("\n".join(lines) + "\n", encoding="utf-8")
print(f"written {out}")
for l in lines[:5]:
    print(l)
