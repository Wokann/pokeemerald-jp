#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Extract wireless/gift texts from data_b.s as US-style multi-line _() strings.

Only symbols declared as `const u8 X[]` (plain text) are kept; struct
arrays (ListMenuItem, WindowTemplate, etc.) are excluded.
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# Build declaration map from src C files: name -> is_text
decl = {}
for p in (ROOT / "src").rglob("*.c"):
    t = p.read_text(encoding="utf-8", errors="replace")
    for m in re.finditer(r'extern\s+const\s+u8\s+(\w+)\[\]', t):
        decl[m.group(1)] = True
    for m in re.finditer(r'extern\s+const\s+struct\s+\w+\s+(\w+)\[\]', t):
        decl[m.group(1)] = False
    for m in re.finditer(r'extern\s+const\s+(?!u8|struct)[\w\s*]+\s+(\w+)\[\]', t):
        decl.setdefault(m.group(1), False)


def is_text(name):
    if name in decl:
        return decl[name]
    # heuristic fallback
    if re.match(r's(WindowTemplate|ListMenu|ListMenuItem|BGTemplate|Textbox|Template|TextColor|TextColors|MenuAction|SpriteTemplate)\w*', name):
        return False
    return True


lines = (ROOT / "data/data_b.s").read_text(encoding="utf-8", errors="replace").splitlines()
start = next(i for i, l in enumerate(lines) if "sText_Colon:" in l) - 1
end = next(i for i, l in enumerate(lines) if "sTextColors_Header:" in l)

group = []
cur = None
cur_lines = []
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


def fmt_text(name, joined):
    # strip one trailing $ terminator (preproc appends 0xFF); keep inner $
    if joined.endswith("$"):
        joined = joined[:-1]
    # split on \n / \p / \l (literal backslash sequences in the extracted text)
    parts = re.split(r"(\\[npl])", joined)
    # re-join so each control char stays at the end of its line
    lines_parts = []
    buf = ""
    for part in parts:
        if re.fullmatch(r"\\[npl]", part):
            lines_parts.append(buf + part)
            buf = ""
        else:
            buf += part
    if buf:
        lines_parts.append(buf)
    parts = lines_parts
    if len(parts) == 1:
        return f'const u8 {name}[] = _("{parts[0]}");'
    out = [f'const u8 {name}[] = _(']
    for i, part in enumerate(parts):
        if i < len(parts) - 1:
            out.append(f'    "{part}"')
        else:
            out.append(f'    "{part}");')
    return "\n".join(out)


out_lines = []
kept = 0
for name, ls in group:
    if not ls or not is_text(name):
        continue
    joined = "".join(ls)
    out_lines.append(fmt_text(name, joined))
    out_lines.append("")
    kept += 1

out = ROOT / "src/data/text/wireless_texts.h"
out.write_text("\n".join(out_lines), encoding="utf-8")
print(f"kept {kept} texts")
