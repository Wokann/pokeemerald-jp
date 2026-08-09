#!/usr/bin/env python3
"""For each asm module, report which functions are converted to C and
whether the converted functions form one contiguous ROM-ordered run."""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ASM = ROOT / "asm"
SRC = ROOT / "src"

ASM_FUNC_RE = re.compile(r"^\s*thumb_func_start\s+(\w+)\s*$")
FUNC_DEF_RE = re.compile(
    r"^(?:static\s+)?(?:const\s+)?"
    r"(?:u8|u16|u32|s8|s16|s32|bool8|bool16|void|int|\w+)\s+\*?\s*"
    r"([A-Za-z_]\w*)\s*\(",
    re.MULTILINE,
)


def c_funcs(path):
    funcs = set()
    text = path.read_text(encoding="utf-8")
    for m in FUNC_DEF_RE.finditer(text):
        name = m.group(1)
        if name not in ("if", "for", "while", "switch", "sizeof"):
            funcs.add(name)
    return funcs


total_converted = 0
for asm_path in sorted(ASM.glob("*.s")):
    stem = asm_path.stem
    c_path = SRC / f"{stem}.c"
    if not c_path.exists():
        continue
    asm_funcs = [
        m.group(1)
        for line in asm_path.read_text(encoding="utf-8").splitlines()
        if (m := ASM_FUNC_RE.match(line))
    ]
    conv = c_funcs(c_path)
    marks = [1 if f in conv else 0 for f in asm_funcs]
    if not marks:
        continue
    total_converted += sum(marks)
    # contiguous run?
    runs = []
    in_run = False
    for i, m in enumerate(marks):
        if m and not in_run:
            runs.append([i, i])
            in_run = True
        elif m:
            runs[-1][1] = i
        else:
            in_run = False
    if len(runs) == 1:
        start, end = runs[0]
        pos = "head" if start == 0 else ("tail" if end == len(marks) - 1 else "middle")
        print(f"{stem:34s} {len(marks):4d} funcs, {sum(marks):3d} converted "
              f"[{start}-{end}] {pos}")
    else:
        desc = ",".join(f"[{s}-{e}]" for s, e in runs)
        print(f"{stem:34s} {len(marks):4d} funcs, {sum(marks):3d} converted "
              f"MULTIPLE RUNS: {desc}")
print(f"total converted: {total_converted}")
