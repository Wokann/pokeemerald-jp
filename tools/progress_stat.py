#!/usr/bin/env python3
"""Estimate decompile progress from the ld script: count .text/.rodata
input lines coming from src vs asm, weighted by nothing (simple ratio).
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ld = (ROOT / "ld_script_jp.txt").read_text(encoding="utf-8")

src_text = 0
asm_text = 0
src_rodata = 0
asm_rodata = 0
src_data = 0
asm_data = 0

for line in ld.splitlines():
    m = re.search(r"\s(src|asm)/([\w.]+)\.o\(\.(text|rodata)(?:\.\S+)?\)", line)
    if not m:
        continue
    kind, fname, sect = m.group(1), m.group(2), m.group(3)
    if sect == "text":
        if kind == "src":
            src_text += 1
        else:
            asm_text += 1
    elif sect == "rodata":
        if kind == "src":
            src_rodata += 1
        else:
            asm_rodata += 1

total_text = src_text + asm_text
print("text inputs: src=%d asm=%d  C-ratio=%.1f%%" % (
    src_text, asm_text, 100.0 * src_text / total_text if total_text else 0))
print("rodata inputs: src=%d asm=%d" % (src_rodata, asm_rodata))

# function-count based estimate
import re as _re
asm_funcs = 0
for p in sorted((ROOT / "asm").glob("*.s")):
    t = p.read_text(encoding="utf-8", errors="replace")
    asm_funcs += len(_re.findall(r"^\s*thumb_func_start", t, _re.M))
print("asm funcs (thumb_func_start):", asm_funcs)
