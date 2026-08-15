#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Extract the 5 comm-error texts from data.s as _() C strings."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
data_s = (ROOT / "data/data.s").read_text(encoding="utf-8", errors="replace")
lines = data_s.splitlines()

# locate the 5 gText_ blocks (line 419-437, 0-based 418..437)
start = next(i for i, l in enumerate(lines) if "gText_CommErrorCheckConnections:" in l) - 1
end = next(i for i, l in enumerate(lines) if "sCommErrorBg_Gfx:" in l)
print("block lines:", start + 1, "to", end)

# parse by .globl groups; keep only gText_*
texts = []
group = []
cur = None
for i in range(start, end):
    if ".globl" in lines[i]:
        if cur is not None:
            group.append((cur, cur_lines))
        m = re.match(r'^\s*\.globl\s+(\w+)\s*$', lines[i])
        cur = m.group(1) if m else None
        cur_lines = []
    else:
        sm = re.match(r'^\s*\.string\s+"(.*)"\s*$', lines[i])
        if sm and cur:
            cur_lines.append(sm.group(1))
if cur is not None:
    group.append((cur, cur_lines))

texts = [(n, ls) for n, ls in group if n.startswith("gText_")]

print("texts:", len(texts))
for name, ls in texts:
    joined = "".join(ls)
    print(f"  {name}: {len(ls)} lines, {len(joined)} chars, ends with $: {joined.endswith('$')}")

# generate C file
out_lines = []
for name, ls in texts:
    joined = "".join(ls)
    if joined.endswith("$"):
        joined = joined[:-1]  # preproc appends 0xFF EOS
    out_lines.append(f'const u8 {name}[] = _("{joined}");')
    out_lines.append("")
out = ROOT / "src/data/text/comm_error_texts.h"
out.write_text("\n".join(out_lines), encoding="utf-8")
print("written", out)
