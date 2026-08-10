#!/usr/bin/env python3
"""Remove US-only static functions/data from text.c so .text matches JP."""
import re
from pathlib import Path

P = Path(__file__).resolve().parents[2] / "src" / "text.c"
src = P.read_text(encoding="utf-8")
lines = src.splitlines(keepends=True)


def drop_range(start, end):
    """Delete lines[start:end] (0-based, end exclusive)."""
    global lines
    lines = lines[:start] + lines[end:]


def find_line(pred, start=0):
    for i in range(start, len(lines)):
        if pred(lines[i]):
            return i
    raise SystemExit(f"line not found: {pred}")


# 1. EWRAM statics -> extern
for i, ln in enumerate(lines):
    if "static EWRAM_DATA struct TextPrinter sTempTextPrinter" in ln:
        lines[i] = "extern struct TextPrinter sTempTextPrinter;\n"
    elif "static EWRAM_DATA struct TextPrinter sTextPrinters" in ln:
        lines[i] = "extern struct TextPrinter sTextPrinters[WINDOWS_MAX];\n"

# 2. Data block: from "static const u8 sFontHalfRowOffsets[]" to
#    "static const u16 sFontBoldJapaneseGlyphs" inclusive -> replace with externs.
start = find_line(lambda l: "static const u8 sFontHalfRowOffsets[]" in l)
end = find_line(lambda l: "static const u16 sFontBoldJapaneseGlyphs[]" in l)
end += 1
externs = (
    "extern const u8 sDownArrowTiles[];\n"
    "extern const u8 sDarkDownArrowTiles[];\n"
    "extern const u8 sDownArrowYCoords[];\n"
    "extern const u8 sWindowVerticalScrollSpeeds[];\n"
    "extern const u8 sKeypadIconTiles[];\n"
    "extern const struct KeypadIcon sKeypadIcons[];\n"
    "extern const struct FontInfo sFontInfos[];\n"
    "extern const u8 sMenuCursorDimensions[][2];\n"
)
lines[start:end] = [externs]

# 3. static declarations at top (FontFunc_Narrow/SmallNarrow, glyph funcs)
src2 = "".join(lines)
src2 = re.sub(r"static u16 FontFunc_Narrow\(struct TextPrinter \*\);\n", "", src2)
src2 = re.sub(r"static u16 FontFunc_SmallNarrow\(struct TextPrinter \*\);\n", "", src2)
for name in (
    "DecompressGlyph_Small",
    "DecompressGlyph_Normal",
    "DecompressGlyph_Short",
    "DecompressGlyph_Narrow",
    "DecompressGlyph_SmallNarrow",
    "DecompressGlyph_Bold",
    "GetGlyphWidth_Small",
    "GetGlyphWidth_Normal",
    "GetGlyphWidth_Short",
    "GetGlyphWidth_Narrow",
    "GetGlyphWidth_SmallNarrow",
):
    src2 = re.sub(rf"static void {name}\(u16[^;\n]*;\n", "", src2)
    src2 = re.sub(rf"static u32 {name}\(u16[^;\n]*;\n", "", src2)
lines = src2.splitlines(keepends=True)
print("after step3 lines:", len(lines), "has glyph def:",
      any("static void DecompressGlyph_Small(u16 glyphId" in l for l in lines))

# 4. Drop FontFunc_Narrow / FontFunc_SmallNarrow bodies
src2 = "".join(lines)
for name in ("FontFunc_Narrow", "FontFunc_SmallNarrow"):
    pat = re.compile(
        rf"static u16 {name}\(struct TextPrinter \*textPrinter\)\n(?:.*\n)*?^\}}\n",
        re.M,
    )
    src2, n = pat.subn("", src2)
    print(f"removed {name}: {n}")
lines = src2.splitlines(keepends=True)

# 5. Drop glyph function block (DecompressGlyph_Small .. DecompressGlyph_Bold)
start = find_line(lambda l: "static void DecompressGlyph_Small(u16 glyphId" in l)
print("glyph start at", start, lines[start].rstrip())
end = find_line(lambda l: l.startswith("static void DecompressGlyph_Bold(u16 glyphId"), start)
print("bold at", end, lines[end].rstrip())
end = find_line(lambda l: l.rstrip() == "}" and not l.startswith((" ", "\t")), end) + 1
drop_range(start, end)
print(f"dropped glyph block lines {start}-{end}")

P.write_text("".join(lines), encoding="utf-8")
print("done")
