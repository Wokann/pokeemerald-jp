#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Add .globl to local symbols referenced across split data_b2d*.s files."""
import glob
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
files = sorted(glob.glob(str(ROOT / "data" / "data_b2d*.s")))

# per-file: defined symbols, .globl symbols, referenced symbols
defined = {}
globl = {}
refs = {}
for f in files:
    p = Path(f)
    text = p.read_text(encoding="utf-8", errors="replace")
    defined[f] = set(re.findall(r'^\s*(\w+):', text, re.M))
    globl[f] = set(re.findall(r'^\s*\.globl\s+(\w+)\s*$', text, re.M))
    refs[f] = set(re.findall(r'\.(?:4byte|word|2byte|byte)\s+(\w+)', text))

need = {}
for f in files:
    for s in refs[f]:
        # find defining file != f
        for f2 in files:
            if f2 != f and s in defined[f2] and s not in globl[f2]:
                need.setdefault(f2, set()).add(s)

total = 0
for f, syms in need.items():
    p = Path(f)
    lines = p.read_text(encoding="utf-8", errors="replace").split("\n")
    sym_lines = {}
    for i, l in enumerate(lines):
        m = re.match(r'^(\s*)(\w+):', l)
        if m and m.group(2) in syms:
            sym_lines.setdefault(m.group(2), i)
    inserted = 0
    for sym, idx in sorted(sym_lines.items(), key=lambda x: -x[1]):
        if idx > 0 and lines[idx - 1].strip().startswith(".globl"):
            continue
        lines.insert(idx, f"\t.globl {sym}")
        inserted += 1
    p.write_text("\n".join(lines), encoding="utf-8")
    total += inserted
    print(f"{Path(f).name}: +{inserted} .globl")
print("total:", total)
