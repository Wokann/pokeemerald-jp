#!/usr/bin/env python3
"""Replace the US static data block in wallclock.c with JP ROM externs."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
path = ROOT / "src" / "wallclock.c"
text = path.read_text(encoding="utf-8")

start = text.index("static const u32 sHand_Gfx[]")
# sClockHandCoords table ends with "};" followed by a blank line; find the
# matching close for that array (the last "};" before "#define sAngle").
end_marker = "#define sAngle"
end = text.index(end_marker)
block = text[start:end]
# locate the final "};" inside the block (closes sClockHandCoords) and keep
# everything after it (the function definitions that follow the data).
last_close = block.rindex("};")
replacement = (
    "// JP keeps all wall-clock graphics, templates and sprite tables in ROM.\n"
    "extern const u16 sTextPrompt_Pal[];\n"
    "extern const struct WindowTemplate sWindowTemplates[];\n"
    "extern const struct WindowTemplate sWindowTemplate_ConfirmYesNo;\n"
    "extern const struct BgTemplate sBgTemplates[];\n"
    "extern const struct CompressedSpriteSheet sSpriteSheet_ClockHand;\n"
    "extern const struct SpritePalette sSpritePalettes_Clock[];\n"
    "extern const struct SpriteTemplate sSpriteTemplate_MinuteHand;\n"
    "extern const struct SpriteTemplate sSpriteTemplate_HourHand;\n"
    "extern const struct SpriteTemplate sSpriteTemplate_PM;\n"
    "extern const struct SpriteTemplate sSpriteTemplate_AM;\n"
    "extern const s8 sClockHandCoords[][2];\n"
    "\n"
)
text = text[:start] + replacement + text[start + last_close + 2 :]
path.write_text(text, encoding="utf-8")
print("rewritten")
