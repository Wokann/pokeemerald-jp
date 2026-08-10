#!/usr/bin/env python3
"""Extract a JP asm function's instructions and emit a C naked-asm body."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
asm_file = ROOT / "asm" / f"{sys.argv[1]}.s"
func = sys.argv[2]
lines = asm_file.read_text(encoding="utf-8").splitlines()

start = None
end = None
for i, line in enumerate(lines):
    if line.strip().startswith(f"thumb_func_start {func}"):
        start = i
    if start is not None and line.strip().startswith(f"thumb_func_end {func}"):
        end = i
        break
if start is None or end is None:
    print("function not found")
    sys.exit(1)

out = []
for line in lines[start + 1 : end]:
    s = line.strip()
    if not s or s.startswith("@") or s.startswith(".include") or s.startswith(".text"):
        continue
    if s.startswith(f"{func}:"):
        continue  # skip the function label line
    if s.startswith("thumb_func_start"):
        break
    out.append(s)

body = "\\n\\t".join(out)
print(f'__attribute__((naked)) void {func}(void)\n{{\n    __asm__(".syntax unified\\n\\t"\n            ".code 16\\n\\t"\n            "{body}"\n            ".syntax divided");\n}}')
