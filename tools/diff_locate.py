#!/usr/bin/env python3
"""Locate ROM differences between baserom and build against funcmap."""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
JP = (ROOT / "baserom_jp.gba").read_bytes()
BUILD = (ROOT / "pokeemerald_jp.gba").read_bytes()

funcs = []  # (addr, name)
for line in (ROOT / "funcmap_jp.txt").read_text(encoding="utf-8").splitlines():
    m = re.match(r"^([0-9A-Fa-f]{8})\s+\S+\s+(\S+)\s*$", line)
    if m:
        funcs.append((int(m.group(1), 16), m.group(2)))
funcs.sort()

diffs = []
for i, (a, b) in enumerate(zip(JP, BUILD)):
    if a != b:
        diffs.append((i, a, b))

print(f"total differing bytes: {len(diffs)}")
for off, a, b in diffs[:40]:
    addr = 0x08000000 + off
    # find containing function
    name = "?"
    for fa, fn in funcs:
        if fa <= addr:
            name = fn
        else:
            break
    print(f"  off {off:7d}  addr 0x{addr:08X}  JP 0x{a:02X} vs 0x{b:02X}  in {name}")
