#!/usr/bin/env python3
"""Print each .4byte literal with the enclosing function name."""
import re
import sys
from pathlib import Path

lines = Path(sys.argv[1]).read_text(encoding="utf-8").splitlines()
cur = "?"
for i, line in enumerate(lines):
    m = re.match(r"^(\w+): @ 0x([0-9A-Fa-f]+)", line)
    if m and i > 0 and "thumb_func_start" in lines[i - 1]:
        cur = m.group(1)
    lm = re.search(r"\.4byte (0x[0-9A-Fa-f]+)", line)
    if lm:
        v = int(lm.group(1), 16)
        if 0x08000000 <= v <= 0x09FFFFFF or 0x02000000 <= v < 0x04000000:
            print(f"{cur}: {lm.group(1)}")
