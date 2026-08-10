#!/usr/bin/env python3
"""Compare JP asm function offsets with built object offsets."""
import re
import subprocess
import sys
from pathlib import Path

if sys.argv[1].startswith("git:"):
    proc = subprocess.run(
        ["git", "show", sys.argv[1][4:]], capture_output=True, text=True
    )
    asm = proc.stdout
else:
    asm = Path(sys.argv[1]).read_text(encoding="utf-8")
obj = sys.argv[2]

jp = []
for m in re.finditer(r"^(\w+): @ 0x([0-9A-Fa-f]+)", asm, re.M):
    jp.append((m.group(1), int(m.group(2), 16)))

nm = subprocess.run(
    ["tools/binutils/bin/arm-none-eabi-nm", "-S", obj], capture_output=True, text=True
).stdout
built = []
for line in nm.splitlines():
    p = line.split()
    if len(p) >= 4 and p[2] in ("T", "t"):
        built.append((p[3], int(p[0], 16)))
built.sort(key=lambda x: x[1])

base = jp[0][1]
for i, (name, addr) in enumerate(jp):
    rel = addr - base
    if i < len(built):
        bname, boff = built[i]
        flag = "" if boff == rel else f"OFF built={boff}"
        print(f"{name}: jp_rel={rel:#x} {flag}")
