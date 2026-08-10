#!/usr/bin/env python3
"""Replace a C function in src/text.c with a naked-asm version of the JP body."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ASM = (ROOT / "asm" / "text.s").read_text(encoding="utf-8").splitlines()


def extract(func):
    out = []
    in_func = False
    for line in ASM:
        s = line.strip()
        if s == f"thumb_func_start {func}":
            in_func = True
            continue
        if in_func and s == f"thumb_func_end {func}":
            break
        if not in_func:
            continue
        if not s or s.startswith("@"):
            continue
        if re.match(rf"^{func}: @ ", s):
            continue
        out.append(s)
    return out


def build_c(func, signature, lines):
    parts = [f'__attribute__((naked)) {signature}',
             "{",
             '    __asm__(".syntax unified\\n\\t"',
             '            ".code 16\\n\\t"']
    for i, s in enumerate(lines):
        esc = s.replace('"', '\\"')
        end = '\\n\\t"' if i < len(lines) - 1 else '\\n\\t"'
        parts.append(f'            "{esc}{end}')
    parts.append('            ".syntax divided");')
    parts.append("}")
    return "\n".join(parts)


def replace_in_text_c(func, signature):
    text_c = ROOT / "src" / "text.c"
    src = text_c.read_text(encoding="utf-8")
    lines = extract(func)
    new_func = build_c(func, signature, lines)
    # find the old function: from its signature line to the next "\n}\n" at col 0
    m = re.search(rf"^.*\b{func}\(.*\n(?:.*\n)*?^\}}\n", src, re.M)
    if not m:
        print(f"ERROR: cannot find function {func} in text.c")
        sys.exit(1)
    text_c.write_text(src[: m.start()] + new_func + "\n" + src[m.end() :], encoding="utf-8")
    print(f"replaced {func}: {len(lines)} asm lines")


if __name__ == "__main__":
    func = sys.argv[1]
    signature = sys.argv[2]
    replace_in_text_c(func, signature)
