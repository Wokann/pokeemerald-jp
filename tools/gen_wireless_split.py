#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Split $-separated sub-texts into ALIGNED(4) contiguous definitions.

Each sub-text is 4-byte aligned in the JP ROM: content + $ (0xFF)
terminator, then 0x00 padding to the next 4-byte boundary.  In C every
sub-text is declared ALIGNED(4), so the linker's `=0` fill reproduces
the padding.  Leading full-width spaces of sub-texts after the first
are that padding and are stripped.
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
text = (ROOT / "src/data/text/wireless_texts.h").read_text(encoding="utf-8")
entries = re.findall(r'^const u8 (\w+)\[\] = _\((.*?)\);\n', text, re.S | re.M)

US_NAMES = {
    "シングルバトル": "sJPText_SingleBattle",
    "ダブルバトル": "sJPText_DoubleBattle",
    "マルチバトル": "sJPText_MultiBattle",
    "ポケモンこうかん": "sJPText_TradePokemon",
    "チャット": "sJPText_Chat",
    "ふしぎなカードをくばる": "sJPText_DistWonderCard",
    "ふしぎなニュースをくばる": "sJPText_DistWonderNews",
    "ふしぎなできごと": "sJPText_DistMysteryEvent",
    "なわとび": "sJPText_HoldPokemonJump",
    "きのみマッシャー": "sJPText_HoldBerryCrush",
    "きのみどり": "sJPText_HoldBerryPicking",
    "ぐるぐるこうかん": "sJPText_HoldSpinTrade",
    "ぐるぐるショップ": "sJPText_HoldSpinShop",
}


def fmt_multi(name, s):
    parts = re.split(r"(\\[npl])", s)
    buf = ""
    lines = []
    for p in parts:
        if re.fullmatch(r"\\[npl]", p):
            lines.append(buf + p)
            buf = ""
        else:
            buf += p
    if buf:
        lines.append(buf)
    if len(lines) == 1:
        return f'ALIGNED(4) const u8 {name}[] = _("{lines[0]}");'
    out = [f'ALIGNED(4) const u8 {name}[] = _(']
    for i, ln in enumerate(lines):
        if i < len(lines) - 1:
            out.append(f'    "{ln}"')
        else:
            out.append(f'    "{ln}");')
    return "\n".join(out)


out_lines = []
used_names = set()
for name, body in entries:
    joined = "".join(re.findall(r'"((?:[^"\\]|\\.)*)"', body))
    if "$" not in joined:
        out_lines.append(fmt_multi(name, joined))
        out_lines.append("")
        continue
    subs = joined.split("$")
    if subs[-1] == "":
        subs = subs[:-1]
    for i, sub in enumerate(subs):
        if i > 0:
            sub = sub.lstrip("\u3000")  # leading 0x00 padding = ALIGN(4) fill
        if sub == "":
            continue  # trailing 0x00 padding only (ALIGN(4) fill)
        if i == 0:
            sub_name = name
        else:
            cand = next((v for k, v in US_NAMES.items() if k in sub), f"{name}_sub{i}")
            if cand in used_names:
                cand = f"{name}_sub{i}"
            sub_name = cand
        used_names.add(sub_name)
        out_lines.append(fmt_multi(sub_name, sub))
        out_lines.append("")

out = ROOT / "src/data/text/wireless_texts_split.h"
out.write_text("\n".join(out_lines), encoding="utf-8")
print("written; defs:", sum(1 for l in out_lines if l.startswith("ALIGNED(4) const u8")))
