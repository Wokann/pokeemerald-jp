#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Regenerate move_names.h as __(\"kana$$$\") text with explicit FF padding."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# charmap forward
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
    """Decode kana bytes until FF; returns kana text and its encoded length."""
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


us_moves = ROOT.parent / "pokeemerald" / "src" / "data" / "text" / "move_names.h"
move_idx = re.findall(r'^\s*\[(MOVE_\w+)\]', us_moves.read_text(encoding="utf-8"), re.M)
rom = (ROOT / "baserom_jp.gba").read_bytes()

lines = ["const u8 gMoveNames[][MOVE_NAME_LENGTH + 1] = {"]
for i, mv in enumerate(move_idx):
    slot = rom[0x2EACC4 + i * 8: 0x2EACC4 + (i + 1) * 8]
    kana, kana_len = decode_kana(slot)
    fill = 8 - kana_len  # FF padding to the 8-byte slot
    assert fill >= 1, f"slot {i} {mv} kana_len {kana_len} too long"
    lines.append(f'    [{mv}] = __("{kana}{"$" * fill}"),')
lines.append("};")

out = ROOT / "src/data/text/move_names.h"
out.write_text("\n".join(lines) + "\n", encoding="utf-8")
print(f"written {out} ({len(move_idx)} entries)")
for l in lines[:6]:
    print(l)
