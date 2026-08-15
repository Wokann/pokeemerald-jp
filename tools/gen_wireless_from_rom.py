#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate wireless texts from ROM bytes (reliable, replaces data_b.s).

For each text symbol (a .globl whose body is .string in data_b.s):
  - read ROM bytes from its address to the next symbol;
  - decode to charmap text (kana/symbol first, control codes after);
  - split on $ into sub-texts; a trailing all-0x00 segment that makes
    the whole block 4-byte aligned is ALIGN(4) padding (dropped);
  - emit ALIGNED(4) definitions (the linker's =0 fill pads to 4).
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from decode_rom_text import decode

rom = (ROOT / "baserom_jp.gba").read_bytes()
lines = (ROOT / "data/data_b.s").read_text(encoding="utf-8", errors="replace").splitlines()

# collect .globl symbols with their bodies; keep those whose body has .string
globl = []
cur = None
cur_body = []
for l in lines:
    m = re.match(r'^\s*\.globl\s+(\w+)\s*$', l)
    if m:
        if cur is not None:
            globl.append((cur, cur_body))
        cur = m.group(1)
        cur_body = []
    elif cur is not None:
        cur_body.append(l)
if cur is not None:
    globl.append((cur, cur_body))

texts = []
for name, body in globl:
    if any(".string" in b for b in body):
        texts.append(name)

# symbol addresses
addrs = {}
for l in lines:
    m = re.match(r'^\s*(\w+):\s*@\s*0x([0-9A-Fa-f]+)', l)
    if m:
        addrs[m.group(1)] = int(m.group(2), 16)

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
    ls = []
    for p in parts:
        if re.fullmatch(r"\\[npl]", p):
            ls.append(buf + p)
            buf = ""
        else:
            buf += p
    if buf:
        ls.append(buf)
    if len(ls) == 1:
        return f'ALIGNED(4) const u8 {name}[] = _("{ls[0]}");'
    out = [f'ALIGNED(4) const u8 {name}[] = _(']
    for i, ln in enumerate(ls):
        if i < len(ls) - 1:
            out.append(f'    "{ln}"')
        else:
            out.append(f'    "{ln}");')
    return "\n".join(out)


out_lines = []
used = set()
for name in texts:
    if name not in addrs:
        continue
    va = addrs[name]
    # only the wireless/gift text block 0x082C0644..0x082C2B64
    if not (0x82C0644 <= va < 0x82C2B64):
        continue
    nxt = min((a for n2, a in addrs.items() if n2 != name and a > va), default=None)
    if nxt is None:
        continue
    raw = rom[va - 0x8000000: nxt - 0x8000000]
    if not raw:
        continue
    # if the block looks like pointers (many 0x08xxxxxx), skip
    import struct
    ptr_count = 0
    for i in range(0, len(raw) - 3, 4):
        v = struct.unpack_from("<I", raw, i)[0]
        if 0x08000000 <= v < 0x09000000:
            ptr_count += 1
    if ptr_count > len(raw) // 8:
        continue  # structural data, not text
    text = decode(raw)
    # trailing 0x00 padding after last $ (ALIGN4): check raw
    last_ff = raw.rfind(0xFF)
    trailing = raw[last_ff + 1:]
    is_align = len(trailing) > 0 and all(b == 0 for b in trailing) and len(raw) % 4 == 0
    subs = text.split("$")
    if is_align or subs[-1] == "":
        subs = subs[:-1]
    for i, sub in enumerate(subs):
        if i > 0:
            sub = sub.lstrip("\u3000")
        if sub == "":
            continue
        if i == 0:
            sn = name
        else:
            cand = next((v for k, v in US_NAMES.items() if k in sub), f"{name}_sub{i}")
            if cand in used:
                cand = f"{name}_sub{i}"
            sn = cand
        used.add(sn)
        out_lines.append(fmt_multi(sn, sub))
        out_lines.append("")

out = ROOT / "src/data/text/wireless_texts_rom.h"
out.write_text("\n".join(out_lines), encoding="utf-8")
print("written; defs:", sum(1 for l in out_lines if l.startswith("ALIGNED(4) const u8")))
