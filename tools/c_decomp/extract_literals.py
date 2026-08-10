#!/usr/bin/env python3
"""Extract literal-pool addresses referenced by each function in an asm file."""
import re
import sys
from pathlib import Path

asm_path = Path(sys.argv[1])
text = asm_path.read_text(encoding="utf-8")

lines = text.splitlines()
funcs = []
cur = None
for i, line in enumerate(lines):
    m = re.match(r"^(\w+): @ 0x([0-9A-Fa-f]+)", line)
    if m and i > 0 and "thumb_func_start" in lines[i - 1]:
        cur = {"name": m.group(1), "addr": int(m.group(2), 16), "refs": [], "idx": i}
        funcs.append(cur)
    elif cur is not None:
        lm = re.search(r"\.4byte (0x[0-9A-Fa-f]+)", line)
        if lm:
            cur["refs"].append(int(lm.group(1), 16))

for f in funcs:
    rom = [hex(x) for x in f["refs"] if 0x08000000 <= x <= 0x09FFFFFF]
    if rom:
        print(f"0x{f['addr']:08X} {f['name']}: {', '.join(rom)}")
