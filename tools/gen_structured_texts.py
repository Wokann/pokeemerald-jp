#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Parse wireless text blocks (text segments + pointer arrays) from ROM."""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from decode_rom_text import decode

rom = (ROOT / "baserom_jp.gba").read_bytes()
# use the pre-split data_b.s symbol table (git HEAD) for addresses
import subprocess
git_out = subprocess.run(["git", "-C", str(ROOT), "show", "HEAD:data/data_b.s"],
                         capture_output=True, text=True, encoding="utf-8", errors="replace")
lines = git_out.stdout.splitlines()

addrs = {}
for l in lines:
    m = re.match(r'^\s*(\w+):\s*@\s*0x([0-9A-Fa-f]+)', l)
    if m:
        addrs[m.group(1)] = int(m.group(2), 16)

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

text_names = [n for n, b in globl if any(".string" in x for x in b) and n in addrs and 0x82C0644 <= addrs[n] < 0x82C2B64]


def is_rom_ptr(raw, pos):
    if pos + 4 > len(raw):
        return False
    v = struct.unpack_from("<I", raw, pos)[0]
    return 0x08000000 <= v < 0x09000000


def parse_block(raw):
    segs = []
    pos = 0
    while pos < len(raw):
        if pos % 4 == 0 and is_rom_ptr(raw, pos) and is_rom_ptr(raw, pos + 4):
            vals = []
            p = pos
            while p + 4 <= len(raw) and is_rom_ptr(raw, p):
                vals.append(struct.unpack_from("<I", raw, p)[0])
                p += 4
            segs.append(("ptrs", pos, p, vals))
            pos = p
            continue
        ff = raw.find(0xFF, pos)
        if ff == -1:
            if pos < len(raw):
                segs.append(("text", pos, len(raw), raw[pos:]))
            break
        seg_end = ff + 1
        segs.append(("text", pos, seg_end, raw[pos:seg_end]))
        pad = (4 - (seg_end % 4)) % 4
        pos = seg_end + pad
    return segs


def fmt_text(name, s):
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


def name_for_text(text, fallback):
    for k, v in US_NAMES.items():
        if k in text:
            return v
    return fallback


out_lines = []
used = set()
# pass 1: parse ALL symbols' blocks (incl .incbin), build global addr->symbol map
all_seg_syms = {}
for name in addrs:
    va = addrs[name]
    nxt = min((a for n2, a in addrs.items() if n2 != name and a > va), default=None)
    if nxt is None:
        continue
    raw = rom[va - 0x8000000: nxt - 0x8000000]
    if not raw:
        continue
    segs = parse_block(raw)
    for idx, seg in enumerate(segs):
        if seg[0] == "text":
            seg_va = va + seg[1]
            all_seg_syms.setdefault(seg_va, f"{name}_seg{idx}")

# pass 2: emit definitions for all symbols in the wireless block
wireless_symbols = [n for n in addrs if 0x82C0644 <= addrs[n] < 0x82C2B64]
for name in wireless_symbols:
    va = addrs[name]
    nxt = min((a for n2, a in addrs.items() if n2 != name and a > va), default=None)
    if nxt is None:
        continue
    raw = rom[va - 0x8000000: nxt - 0x8000000]
    if not raw:
        continue
    segs = parse_block(raw)
    seg_syms = {}
    for idx, seg in enumerate(segs):
        if seg[0] == "text":
            seg_va = va + seg[1]
            txt = decode(seg[3])
            if txt.endswith("$"):
                txt = txt[:-1]
            if idx == 0:
                sn = name
            else:
                cand = name_for_text(txt, f"{name}_sub{idx}")
                if cand in used:
                    cand = f"{name}_sub{idx}"
                sn = cand
            used.add(sn)
            seg_syms[seg_va] = sn
            all_seg_syms[seg_va] = sn
            out_lines.append(fmt_text(sn, txt))
            out_lines.append("")
        else:
            pname = "sJPLinkGroupActionTexts"
            if pname in used:
                pname = f"{name}_ptrs"
            used.add(pname)
            out_lines.append(f"const u8 *const {pname}[] = {{")
            for v in seg[3]:
                tgt = all_seg_syms.get(v)
                if tgt is None:
                    print(f"WARN: {name} ptr 0x{v:08X} unresolved")
                out_lines.append(f"    {tgt},")
            out_lines.append("};")
            out_lines.append("")

out = ROOT / "src/data/text/wireless_structured.h"
out.write_text("\n".join(out_lines), encoding="utf-8")
print("written; defs:", sum(1 for l in out_lines if l.startswith("ALIGNED(4) const u8")))
print("ptrs arrays:", sum(1 for l in out_lines if l.startswith("const u8 *const")))
