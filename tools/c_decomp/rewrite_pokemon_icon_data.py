#!/usr/bin/env python3
"""Replace US static/const data tables in pokemon_icon.c with JP ROM externs."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
path = ROOT / "src" / "pokemon_icon.c"
text = path.read_text(encoding="utf-8")

# gMonIconTable (24-467), gMonIconPaletteIndices (468-911),
# gMonIconPaletteTable (912-924), sprite tables (925-1010).
start = text.index("const u8 *const gMonIconTable[]")
# The static sprite tables end before the first function (CreateMonIcon at
# ~1028). Find the closing "};" of sSpriteImageSizes (last static table).
end_marker = "u8 CreateMonIcon("
end = text.index(end_marker)
block = text[start:end]
last_close = block.rindex("};")

replacement = (
    "// JP keeps all icon tables in ROM.\n"
    "extern const u8 *const gMonIconTable[];\n"
    "extern const u8 gMonIconPaletteIndices[];\n"
    "extern const struct SpritePalette gMonIconPaletteTable[];\n"
    "extern const struct OamData sMonIconOamData;\n"
    "extern const union AnimCmd *const sMonIconAnims[];\n"
    "extern const union AffineAnimCmd *const sMonIconAffineAnims[];\n"
    "extern const u16 sSpriteImageSizes[3][4];\n"
    "\n"
)
text = text[:start] + replacement + text[start + last_close + 2 :]
path.write_text(text, encoding="utf-8")
print("rewritten")
