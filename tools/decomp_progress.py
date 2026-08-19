#!/usr/bin/env python3
"""Measure how much of pokeemerald has been decompiled into pokeemerald-jp.

Compares the src/ function inventory of pokeemerald-jp against
pokeemerald's src/ per module, and against the JP asm inventory:

  * functions converted to C in src/ (per module),
  * total JP asm functions vs pokeemerald src functions,
  * data region incbin coverage (how many bytes of data.s are still
    raw .incbin vs structured).

Usage:
    python3 tools/decomp_progress.py
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
US_SRC = ROOT.parent / "pokeemerald" / "src"
JP_ASM = ROOT / "asm"
JP_SRC = ROOT / "src"

FUNC_DEF_RE = re.compile(
    r"^(?:static\s+)?(?:const\s+)?"
    r"(?:u8|u16|u32|s8|s16|s32|bool8|bool16|void|int|\w+)\s+"
    r"(?:UNUSED\s+)?\*?\s*"
    r"([A-Za-z_]\w*)\s*\(",
    re.MULTILINE,
)
ASM_FUNC_RE = re.compile(r"^\s*thumb_func_start\s+(\w+)\s*$")


def c_functions(path):
    funcs = set()
    text = path.read_text(encoding="utf-8")
    for m in FUNC_DEF_RE.finditer(text):
        name = m.group(1)
        if name not in ("if", "for", "while", "switch", "sizeof"):
            funcs.add(name)
    return funcs


def jp_asm_functions():
    funcs = set()
    for path in JP_ASM.glob("*.s"):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = ASM_FUNC_RE.match(line)
            if m:
                funcs.add(m.group(1))
    return funcs


def main():
    # Recurse into subdirectories (src/libc/, src/data/) so converted
    # newlib/libc functions are counted too.
    jp_c = {p.stem: c_functions(p) for p in sorted(JP_SRC.glob("**/*.c"))}
    us_c = {p.stem: c_functions(p) for p in sorted(US_SRC.glob("**/*.c"))}
    jp_asm = jp_asm_functions()

    converted = set()
    for funcs in jp_c.values():
        converted |= funcs

    print(f"{'module':<28} {'JP C':>5} {'US C':>6} {'conv':>5}")
    total_jp = total_us = total_conv = 0
    for module in sorted(set(jp_c) | set(us_c)):
        jp = len(jp_c.get(module, set()))
        us = len(us_c.get(module, set()))
        conv = len(converted & jp_c.get(module, set()))
        total_jp += jp
        total_us += us
        total_conv += conv
        if jp or conv:
            print(f"{module:<28} {jp:>5} {us:>6} {conv:>5}")
    print(f"{'TOTAL':<28} {total_jp:>5} {total_us:>6} {total_conv:>5}")

    print(f"\nJP asm functions: {len(jp_asm)}")
    print(f"Converted to C:   {len(converted)}")
    print(f"C conversion:     {len(converted)}/{len(converted) + len(jp_asm)} = {len(converted) / max(len(converted) + len(jp_asm), 1):.2%}")


if __name__ == "__main__":
    main()
