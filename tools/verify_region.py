#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Verify a generated text region reproduces the ROM layout."""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
rom = (ROOT / "baserom_jp.gba").read_bytes()
import argparse
ap = argparse.ArgumentParser()
ap.add_argument("--header", default="test_region.h")
ap.add_argument("--src", default="data/data_b2d.s")
a = ap.parse_args()
import subprocess
try:
    raw = subprocess.run(
        ["git", "show", f"HEAD:{a.src}"], capture_output=True, cwd=ROOT
    ).stdout
    if not raw:
        raw = (ROOT / a.src).read_bytes()
except Exception:
    raw = (ROOT / a.src).read_bytes()
lines = raw.decode("utf-8", errors="replace").splitlines()
addrs = {}
for l in lines:
    m = re.match(r'^\s*(\w+):\s*@\s*0x([0-9A-Fa-f]+)', l)
    if m:
        addrs[m.group(1)] = int(m.group(2), 16)

test = ROOT / "tools/test_region.c"
test.write_text(f'#include "global.h"\n#include "{a.header}"\n', encoding="utf-8")
cmd = ("cd /home/kenny/pokeemerald-jp && cpp -iquote include -iquote src/data/text -I tools/agbcc/include -I tools/agbcc "
       "-nostdinc -undef -std=gnu89 -P -x c tools/test_region.c | tools/preproc/preproc -i tools/test_region.c charmap.txt")
out = subprocess.run(cmd, shell=True, capture_output=True, text=True, encoding="utf-8", errors="replace").stdout
defs = re.findall(r'const u8 (\w+)\[\] = \s*\{(.*?)\};', out, re.S)
print("defs:", len(defs))

import collections
groups = collections.OrderedDict()
for name, body in defs:
    base_name = re.sub(r"_sub\d+.*$", "", name)
    groups.setdefault(base_name, []).append((name, body))
ok = 0
bad = []
for base_name, members in groups.items():
    if base_name not in addrs:
        for name, body in members:
            bad.append((name, 0, -2, 0, 0))
        continue
    va = addrs[base_name]
    off = 0
    for name, body in members:
        blen = len(re.findall(r'0x([0-9A-Fa-f]{2})', body))
        bytes_ = bytes(int(x, 16) for x in re.findall(r'0x([0-9A-Fa-f]{2})', body))
        slot = rom[va - 0x8000000 + off: va - 0x8000000 + off + blen]
        if bytes_ == slot:
            ok += 1
        else:
            for i, (a, b) in enumerate(zip(bytes_, slot)):
                if a != b:
                    bad.append((name, va + off, i, a, b))
                    break
            else:
                bad.append((name, va + off, -1, 0, 0))
        off += blen  # contiguous (no ALIGN(4) padding in this region)

print(f"match {ok}/{len(defs)}, bad {len(bad)}")
for b in bad[:10]:
    print("  ", b)
