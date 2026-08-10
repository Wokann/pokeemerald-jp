#!/usr/bin/env python3
"""Rebuild the JP glyph function section after GetMenuCursorDimensionByFont."""
import sys
import re
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import embed_asm_func

P = Path(__file__).resolve().parents[2] / "src" / "text.c"
src = P.read_text(encoding="utf-8")

m = re.search(r"(^u8 GetMenuCursorDimensionByFont\(.*\n(?:.*\n)*?^\}\n)", src, re.M)
if not m:
    raise SystemExit("anchor not found")
head = src[: m.end()]

ASM = (Path(__file__).resolve().parents[2] / "asm" / "text.s")
if not ASM.exists():
    raise SystemExit("asm/text.s not present; run: git show HEAD:asm/text.s > asm/text.s")

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
glyphs = "\n// JP-specific glyph functions (JP ROM 0x080062B4-0x0800668C)\n"
for f in order:
    lines = embed_asm_func.extract(f)
    sig = "void " + f + "(u16 glyphId)"
    if f in ("sub_08006300", "sub_08006350", "sub_080063F8", "sub_080064B4", "sub_0800655C", "sub_08006620"):
        sig = "u32 " + f + "(u16 glyphId)"
    glyphs += embed_asm_func.build_c(f, sig, lines) + "\n\n"

P.write_text(head + glyphs, encoding="utf-8")
print("rebuilt glyph section")
