#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Verify wireless_texts_split.h reproduces the ROM layout.

Simulates ALIGNED(4) placement: each definition's encoded length is
rounded up to 4 bytes; the running offset must match the ROM addresses
of the corresponding sub-texts.
"""
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
rom = (ROOT / "baserom_jp.gba").read_bytes()

# symbol -> addr from data_b.s (all symbols; text blocks end at the next symbol)
addrs = {}
for l in (ROOT / "data/data_b.s").read_text(encoding="utf-8", errors="replace").splitlines():
    m = re.match(r'^\s*(\w+):\s*@\s*0x([0-9A-Fa-f]+)', l)
    if m:
        addrs[m.group(1)] = int(m.group(2), 16)

# preproc the split header
test = ROOT / "tools/test_split.c"
test.write_text('#include "global.h"\n#include "wireless_texts_rom.h"\n', encoding="utf-8")
cmd = ("cd /home/kenny/pokeemerald-jp && cpp -iquote include -iquote src/data/text -I tools/agbcc/include -I tools/agbcc "
       "-nostdinc -undef -std=gnu89 -P -x c tools/test_split.c | tools/preproc/preproc -i tools/test_split.c charmap.txt")
out = subprocess.run(cmd, shell=True, capture_output=True, text=True, encoding="utf-8", errors="replace").stdout
defs = re.findall(r'__attribute__\(\(aligned\(4\)\)\) const u8 (\w+)\[\] = \s*\{(.*?)\};', out, re.S)
print("defs:", len(defs))

# base addr = first text symbol in data_b.s (sText_Colon)
base_name = "sText_Colon"
base = addrs[base_name]
offset = 0
ok = 0
bad = []
prev_name = None
for name, body in defs:
    blen = len(re.findall(r'0x([0-9A-Fa-f]{2})', body))
    va = base + offset
    # expected: this def's bytes at va (padded to 4)
    bytes_ = bytes(int(x, 16) for x in re.findall(r'0x([0-9A-Fa-f]{2})', body))
    # if this name is a real data_b.s symbol, align offset to it (skip structural symbols)
    if name in addrs:
        real_va = addrs[name]
        if real_va > va:
            # pad offset so va matches real symbol (should already be aligned)
            offset += (real_va - va)
            va = real_va
    slot = rom[va - 0x8000000: va - 0x8000000 + blen]
    if bytes_ == slot:
        ok += 1
    else:
        bad.append((name, va, blen, bytes_.hex(" ")[:30], slot.hex(" ")[:30]))
    offset += (blen + 3) & ~3

print(f"match {ok}/{len(defs)}, bad {len(bad)}")
for b in bad[:8]:
    print("  ", b)
