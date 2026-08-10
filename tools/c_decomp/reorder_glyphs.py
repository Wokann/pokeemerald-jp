#!/usr/bin/env python3
"""Reorder glyph helper functions in text.c to match JP ROM order."""
import re
from pathlib import Path

P = Path(__file__).resolve().parents[2] / "src" / "text.c"
src = P.read_text(encoding="utf-8")

# JP ROM order after GetMenuCursorDimensionByFont
order = [
    "DecompressGlyphFont9",
    "sub_08006300",
    "sub_08006304",
    "sub_08006350",
    "sub_08006354",
    "sub_080063F8",
    "sub_08006418",
    "sub_080064B4",
    "sub_080064B8",
    "sub_0800655C",
    "sub_0800657C",
    "sub_08006620",
    "sub_08006640",
]


def extract_func(name):
    global src
    pat = re.compile(
        rf"(^(?:u32|void|u8|static u32|static void|__attribute__\(\(naked\)\) void) {name}\(.*\n(?:.*\n)*?^\}}\n)",
        re.M,
    )
    m = pat.search(src)
    if not m:
        raise SystemExit(f"function not found: {name}")
    body = m.group(1)
    src = src[: m.start()] + src[m.end() :]
    return body


def find_anchor():
    global src
    m = re.search(r"(^u8 GetMenuCursorDimensionByFont\(.*\n(?:.*\n)*?^\}\n)", src, re.M)
    if not m:
        raise SystemExit("anchor not found")
    return m.end()


anchor = find_anchor()
bodies = {n: extract_func(n) for n in order}
new_block = "".join(bodies[n] for n in order)
src = src[:anchor] + new_block + src[anchor:]
P.write_text(src, encoding="utf-8")
print("reordered", len(order), "functions")
