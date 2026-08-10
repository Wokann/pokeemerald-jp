#!/usr/bin/env python3
"""Replace the naked-asm glyph helpers in text.c with plain C."""
import re
from pathlib import Path

P = Path(__file__).resolve().parents[2] / "src" / "text.c"
src = P.read_text(encoding="utf-8")

m = re.search(r"(^u8 GetMenuCursorDimensionByFont\(.*\n(?:.*\n)*?^\}\n)", src, re.M)
if not m:
    raise SystemExit("anchor not found")
head = src[: m.end()]

body = r'''
// JP-specific glyph functions (JP ROM 0x080062B4-0x0800668C)
void DecompressGlyphFont9(u16 glyphId)
{
    const u8 *glyphs = sFontGlyphData_9CF14 + (0x200 * (glyphId >> 4)) + (0x10 * (glyphId & 0xF));
    DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
    DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
    gCurGlyph.width = 8;
    gCurGlyph.height = 12;
}

u32 sub_08006300(u16 glyphId)
{
    return 8;
}

void sub_08006304(u16 glyphId)
{
    const u8 *glyphs = sFontGlyphData_A0F14 + (0x200 * (glyphId >> 4)) + (0x10 * (glyphId & 0xF));
    DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
    DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
    gCurGlyph.width = 8;
    gCurGlyph.height = 16;
}

u32 sub_08006350(u16 glyphId)
{
    return 8;
}

void sub_08006354(u16 glyphId)
{
    if (glyphId == 0)
    {
        u8 color = GetLastTextColor(2);
        s32 i = 0;
        u8 *buf = (u8 *)gCurGlyph.gfxBufferTop;
        u32 v = (color << 4) | color;
        for (; i < 0x80; i++)
        {
            *(u8 *)((u32)i + (u32)buf) = v;
            gCurGlyph.width = 10;
            gCurGlyph.height = 12;
        }
    }
    else
    {
        u32 hi = (glyphId >> 3) * 0x200;
        u32 lo = (glyphId & 7) * 0x20;
        const u8 *glyphs = sFontGlyphData_A4F14 + hi + lo;
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x10, (u8 *)gCurGlyph.gfxBufferTop + 0x20);
        DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
        DecompressGlyphTile(glyphs + 0x110, (u8 *)gCurGlyph.gfxBufferBottom + 0x20);
        gCurGlyph.width = sGlyphWidthTable_ACF14[glyphId];
        gCurGlyph.height = 12;
    }
}

u32 sub_080063F8(u16 glyphId)
{
    if (glyphId == 0)
        return 10;
    return sGlyphWidthTable_ACF14[glyphId];
}

void sub_08006418(u16 glyphId)
{
    if (glyphId == 0)
    {
        u8 color = GetLastTextColor(2);
        s32 i = 0;
        u8 *buf = (u8 *)gCurGlyph.gfxBufferTop;
        u32 v = (color << 4) | color;
        for (; i < 0x80; i++)
        {
            *(u8 *)((u32)i + (u32)buf) = v;
            gCurGlyph.width = 10;
            gCurGlyph.height = 12;
        }
    }
    else
    {
        u32 hi = (glyphId >> 3) * 0x200;
        u32 lo = (glyphId & 7) * 0x20;
        const u8 *glyphs = sFontGlyphData_A4F14 + hi + lo;
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x10, (u8 *)gCurGlyph.gfxBufferTop + 0x20);
        DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
        DecompressGlyphTile(glyphs + 0x110, (u8 *)gCurGlyph.gfxBufferBottom + 0x20);
        gCurGlyph.width = 10;
        gCurGlyph.height = 12;
    }
}

u32 sub_080064B4(u16 glyphId)
{
    return 10;
}

void sub_080064B8(u16 glyphId)
{
    if (glyphId == 0)
    {
        u8 color = GetLastTextColor(2);
        s32 i = 0;
        u8 *buf = (u8 *)gCurGlyph.gfxBufferTop;
        u32 v = (color << 4) | color;
        for (; i < 0x80; i++)
        {
            *(u8 *)((u32)i + (u32)buf) = v;
            gCurGlyph.width = 10;
            gCurGlyph.height = 12;
        }
    }
    else
    {
        u32 hi = (glyphId >> 3) * 0x200;
        u32 lo = (glyphId & 7) * 0x20;
        const u8 *glyphs = sFontGlyphData_AD02C + hi + lo;
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x10, (u8 *)gCurGlyph.gfxBufferTop + 0x20);
        DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
        DecompressGlyphTile(glyphs + 0x110, (u8 *)gCurGlyph.gfxBufferBottom + 0x20);
        gCurGlyph.width = sGlyphWidthTable_B502C[glyphId];
        gCurGlyph.height = 12;
    }
}

u32 sub_0800655C(u16 glyphId)
{
    if (glyphId == 0)
        return 10;
    return sGlyphWidthTable_B502C[glyphId];
}

void sub_0800657C(u16 glyphId)
{
    if (glyphId == 0)
    {
        u8 color = GetLastTextColor(2);
        s32 i = 0;
        u8 *buf = (u8 *)gCurGlyph.gfxBufferTop;
        u32 v = (color << 4) | color;
        for (; i < 0x80; i++)
        {
            *(u8 *)((u32)i + (u32)buf) = v;
            gCurGlyph.width = 10;
            gCurGlyph.height = 12;
        }
    }
    else
    {
        u32 hi = (glyphId >> 3) * 0x200;
        u32 lo = (glyphId & 7) * 0x20;
        const u8 *glyphs = sFontGlyphData_B5144 + hi + lo;
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x10, (u8 *)gCurGlyph.gfxBufferTop + 0x20);
        DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
        DecompressGlyphTile(glyphs + 0x110, (u8 *)gCurGlyph.gfxBufferBottom + 0x20);
        gCurGlyph.width = sGlyphWidthTable_BD144[glyphId];
        gCurGlyph.height = 12;
    }
}

u32 sub_08006620(u16 glyphId)
{
    if (glyphId == 0)
        return 10;
    return sGlyphWidthTable_BD144[glyphId];
}

void sub_08006640(u16 glyphId)
{
    const u8 *glyphs = sFontGlyphData_BD25C + (0x200 * (glyphId >> 4)) + (0x10 * (glyphId & 0xF));
    DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
    DecompressGlyphTile(glyphs + 0x100, gCurGlyph.gfxBufferBottom);
    gCurGlyph.width = 8;
    gCurGlyph.height = 12;
}
'''

P.write_text(head + body, encoding="utf-8")
print("restored glyph functions as C")
