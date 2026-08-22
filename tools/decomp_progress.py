#!/usr/bin/env python3
"""Inventory C source definitions and standalone asm in pokeemerald-jp.

Compares the src/ function-definition inventory of pokeemerald-jp against
pokeemerald's src/ per relative module path, and reports the remaining JP
functions still stored in standalone asm files.

This is a source-inventory report, not the strict C-conversion metric: inline
``__attribute__((naked))`` functions live in C files but are intentionally not
counted as C definitions here.  Use the external ``strict_progress.py`` after
a build for the authoritative ROM-level conversion rate.

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


def _find_closing_paren(text, start):
    """Return the position after the parenthesis opened at start, if balanced."""
    depth = 0
    for pos in range(start, len(text)):
        if text[pos] == "(":
            depth += 1
        elif text[pos] == ")":
            depth -= 1
            if depth == 0:
                return pos + 1
    return None


def _skip_trailing_attributes(text, pos):
    """Skip GNU attributes placed between a function parameter list and body."""
    while True:
        while pos < len(text) and text[pos].isspace():
            pos += 1
        if not text.startswith("__attribute__", pos):
            return pos
        open_paren = text.find("(", pos + len("__attribute__"))
        if open_paren == -1:
            return len(text)
        pos = _find_closing_paren(text, open_paren)
        if pos is None:
            return len(text)


def c_functions(path):
    funcs = set()
    text = path.read_text(encoding="utf-8")
    for m in FUNC_DEF_RE.finditer(text):
        name = m.group(1)
        end = _find_closing_paren(text, m.end() - 1)
        if end is None:
            continue
        end = _skip_trailing_attributes(text, end)
        # The former name-only regex also counted forward declarations.  A
        # function contributes to conversion progress only when this source
        # file supplies a body; this also prevents a naked-function prototype
        # from inflating the C count.
        if (end < len(text)
                and text[end] == "{"
                and name not in ("if", "for", "while", "switch", "sizeof")):
            funcs.add(name)
    return funcs


def c_modules(root):
    """Return definitions keyed by full path below src/, not basename alone."""
    return {
        path.relative_to(root).with_suffix("").as_posix(): c_functions(path)
        for path in sorted(root.glob("**/*.c"))
    }


def jp_asm_functions():
    funcs = set()
    for path in JP_ASM.glob("*.s"):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = ASM_FUNC_RE.match(line)
            if m:
                funcs.add(m.group(1))
    return funcs


def main():
    # Relative paths keep src/foo.c distinct from src/data/foo.c and
    # src/libc/foo.c, which basename-only accounting previously merged.
    jp_c = c_modules(JP_SRC)
    us_c = c_modules(US_SRC)
    jp_asm = jp_asm_functions()

    print(f"{'module':<36} {'JP C':>5} {'US C':>6}")
    total_jp = total_us = 0
    for module in sorted(set(jp_c) | set(us_c)):
        jp = len(jp_c.get(module, set()))
        us = len(us_c.get(module, set()))
        total_jp += jp
        total_us += us
        if jp:
            print(f"{module:<36} {jp:>5} {us:>6}")
    print(f"{'TOTAL':<36} {total_jp:>5} {total_us:>6}")

    print(f"\nStandalone JP asm functions: {len(jp_asm)}")
    print(f"C source definitions:         {total_jp}")
    print(f"C source inventory:           {total_jp}/{total_jp + len(jp_asm)} = {total_jp / max(total_jp + len(jp_asm), 1):.2%}")


if __name__ == "__main__":
    main()
