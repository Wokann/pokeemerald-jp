#include "global.h"
#include "battle.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "sound.h"
#include "constants/songs.h"
#include "string_util.h"
#include "window.h"
#include "text.h"
#include "blit.h"
#include "menu.h"
#include "dynamic_placeholder_text_util.h"
#include "fonts.h"

static u16 RenderText(struct TextPrinter *);
static u32 RenderFont(struct TextPrinter *);
static u16 FontFunc_Small(struct TextPrinter *);
static u16 FontFunc_Normal(struct TextPrinter *);
static u16 FontFunc_Short(struct TextPrinter *);
static u16 FontFunc_ShortCopy1(struct TextPrinter *);
static u16 FontFunc_ShortCopy2(struct TextPrinter *);
static u16 FontFunc_ShortCopy3(struct TextPrinter *);

// JP-specific glyph decompressors (defined in text module / JP asm)
extern struct TextPrinter sTempTextPrinter;
extern struct TextPrinter sTextPrinters[WINDOWS_MAX];
extern u16 sFontHalfRowLookupTable[0x51];
extern u16 sLastTextBgColor;
extern u16 sLastTextFgColor;
extern u16 sLastTextShadowColor;
extern const struct FontInfo *gFonts;
extern bool8 gDisableTextPrinters;
extern struct TextGlyph gCurGlyph;
extern TextFlags gTextFlags;
extern const u8 sDownArrowTiles[];
extern const u8 sDarkDownArrowTiles[];
extern const u8 sDownArrowYCoords[];
extern const u8 sWindowVerticalScrollSpeeds[];
extern const u8 sKeypadIconTiles[];
struct KeypadIcon
{
    u16 tileOffset;
    u8 width;
    u8 height;
};
extern const struct KeypadIcon sKeypadIcons[];
extern const struct FontInfo sFontInfos[];
extern const u8 sMenuCursorDimensions[][2];
extern const struct GlyphWidthFunc sGlyphWidthFuncs[6];
extern const u8 sFontGlyphData_A0F14[];
extern const u8 sFontGlyphData_A4F14[];
extern const u8 sFontGlyphData_AD02C[];
extern const u8 sFontGlyphData_B5144[];
extern const u8 sFontGlyphData_9CF14[];
extern const u8 sFontGlyphData_BD25C[];
extern const u8 sGlyphWidthTable_ACF14[];
extern const u8 sGlyphWidthTable_B502C[];
extern const u8 sGlyphWidthTable_BD144[];
void DecompressGlyphFont9(u16 glyph);
void sub_08006304(u16 glyph);
void sub_08006354(u16 glyph);
void sub_08006418(u16 glyph);
void sub_080064B8(u16 glyph);
void sub_0800657C(u16 glyph);
void sub_08006640(u16 glyph);

static void SetFontsPointer(const struct FontInfo *fonts)
{
    gFonts = fonts;
}

void DeactivateAllTextPrinters(void)
{
    int printer;
    for (printer = 0; printer < WINDOWS_MAX; ++printer)
        sTextPrinters[printer].active = FALSE;
}

bool16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, TextPrinterCallback callback)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = gFonts[fontId].letterSpacing;
    printerTemplate.lineSpacing = gFonts[fontId].lineSpacing;
    printerTemplate.unk = gFonts[fontId].unk;
    printerTemplate.fgColor = gFonts[fontId].fgColor;
    printerTemplate.bgColor = gFonts[fontId].bgColor;
    printerTemplate.shadowColor = gFonts[fontId].shadowColor;
    return AddTextPrinter(&printerTemplate, speed, callback);
}

bool16 AddTextPrinter(struct TextPrinterTemplate *printerTemplate, u8 speed, TextPrinterCallback callback)
{
    int i;
    u16 j;

    if (!gFonts)
        return FALSE;

    sTempTextPrinter.active = TRUE;
    sTempTextPrinter.state = RENDER_STATE_HANDLE_CHAR;
    sTempTextPrinter.textSpeed = speed;
    sTempTextPrinter.delayCounter = 0;
    sTempTextPrinter.scrollDistance = 0;

    for (i = 0; i < (int)ARRAY_COUNT(sTempTextPrinter.subStructFields); i++)
        sTempTextPrinter.subStructFields[i] = 0;

    sTempTextPrinter.printerTemplate = *printerTemplate;
    sTempTextPrinter.callback = callback;

    GenerateFontHalfRowLookupTable(printerTemplate->fgColor, printerTemplate->bgColor, printerTemplate->shadowColor);
    if (speed != TEXT_SKIP_DRAW && speed != 0)
    {
        --sTempTextPrinter.textSpeed;
        sTextPrinters[printerTemplate->windowId] = sTempTextPrinter;
    }
    else
    {
        sTempTextPrinter.textSpeed = 0;

        // Render all text (up to limit) at once
        for (j = 0; j < 0x400; ++j)
        {
            if (RenderFont(&sTempTextPrinter) == RENDER_FINISH)
                break;
        }

        // All the text is rendered to the window but don't draw it yet.
        if (speed != TEXT_SKIP_DRAW)
            CopyWindowToVram(sTempTextPrinter.printerTemplate.windowId, COPYWIN_GFX);
        sTextPrinters[printerTemplate->windowId].active = FALSE;
    }
    gDisableTextPrinters = FALSE;
    return TRUE;
}

void RunTextPrinters(void)
{
    int i;

    if (!gDisableTextPrinters)
    {
        for (i = 0; i < WINDOWS_MAX; ++i)
        {
            if (sTextPrinters[i].active)
            {
                u16 renderCmd = RenderFont(&sTextPrinters[i]);
                switch (renderCmd)
                {
                case RENDER_PRINT:
                    CopyWindowToVram(sTextPrinters[i].printerTemplate.windowId, COPYWIN_GFX);
                case RENDER_UPDATE:
                    if (sTextPrinters[i].callback != NULL)
                        sTextPrinters[i].callback(&sTextPrinters[i].printerTemplate, renderCmd);
                    break;
                case RENDER_FINISH:
                    sTextPrinters[i].active = FALSE;
                    break;
                }
            }
        }
    }
}

bool16 IsTextPrinterActive(u8 id)
{
    return sTextPrinters[id].active;
}

static u32 RenderFont(struct TextPrinter *textPrinter)
{
    u32 ret;
    while (TRUE)
    {
        ret = gFonts[textPrinter->printerTemplate.fontId].fontFunction(textPrinter);
        if (ret != RENDER_REPEAT)
            return ret;
    }
}

#ifndef NONMATCHING
// 逐字节匹配版本：与 baserom_jp.gba 的原始编译结果完全一致。
__attribute__((naked)) void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0x10\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "lsls r1, r1, #0x18\n\t"
            "lsrs r1, r1, #0x18\n\t"
            "lsls r2, r2, #0x18\n\t"
            "lsrs r2, r2, #0x18\n\t"
            "str r1, [sp]\n\t"
            "str r0, [sp, #4]\n\t"
            "str r2, [sp, #8]\n\t"
            "ldr r3, _08004788\n\t"
            "strh r1, [r3]\n\t"
            "ldr r1, _0800478C\n\t"
            "strh r0, [r1]\n\t"
            "ldr r0, _08004790\n\t"
            "strh r2, [r0]\n\t"
            "movs r0, #0\n\t"
            "mov ip, r0\n\t"
            "movs r1, #0\n\t"
            "_08004714:\n\t"
            "movs r2, #0\n\t"
            "lsls r0, r1, #2\n\t"
            "adds r1, #1\n\t"
            "mov sl, r1\n\t"
            "add r0, sp\n\t"
            "mov r8, r0\n\t"
            "_08004720:\n\t"
            "movs r1, #0\n\t"
            "lsls r0, r2, #2\n\t"
            "adds r2, #1\n\t"
            "mov sb, r2\n\t"
            "add r0, sp\n\t"
            "str r0, [sp, #0xc]\n\t"
            "_0800472C:\n\t"
            "lsls r0, r1, #2\n\t"
            "adds r6, r1, #1\n\t"
            "mov r1, sp\n\t"
            "adds r4, r1, r0\n\t"
            "mov r5, sp\n\t"
            "mov r7, ip\n\t"
            "lsls r0, r7, #1\n\t"
            "ldr r1, _08004794\n\t"
            "adds r2, r0, r1\n\t"
            "movs r3, #2\n\t"
            "_08004740:\n\t"
            "ldm r5!, {r1}\n\t"
            "lsls r1, r1, #0xc\n\t"
            "ldr r0, [r4]\n\t"
            "lsls r0, r0, #0x8\n\t"
            "orrs r1, r0\n\t"
            "ldr r7, [sp, #0xc]\n\t"
            "ldr r0, [r7]\n\t"
            "lsls r0, r0, #0x4\n\t"
            "orrs r1, r0\n\t"
            "mov r7, r8\n\t"
            "ldr r0, [r7]\n\t"
            "orrs r0, r1\n\t"
            "strh r0, [r2]\n\t"
            "adds r2, #2\n\t"
            "movs r0, #1\n\t"
            "add ip, r0\n\t"
            "subs r3, #1\n\t"
            "cmp r3, #0\n\t"
            "bge _08004740\n\t"
            "adds r1, r6, #0\n\t"
            "cmp r1, #2\n\t"
            "ble _0800472C\n\t"
            "mov r2, sb\n\t"
            "cmp r2, #2\n\t"
            "ble _08004720\n\t"
            "mov r1, sl\n\t"
            "cmp r1, #2\n\t"
            "ble _08004714\n\t"
            "add sp, #0x10\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_08004788: .4byte sLastTextBgColor\n\t"
            "_0800478C: .4byte sLastTextFgColor\n\t"
            "_08004790: .4byte sLastTextShadowColor\n\t"
            "_08004794: .4byte sFontHalfRowLookupTable\n\t"
            ".syntax divided");
}

#else
// 可读的 C 版本（NONMATCHING）：语义与汇编版相同，但不保证逐字节一致，
// 便于阅读、修改和进一步反编译。启用方式见 include/config.h。
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
{
    u32 colors[3] = { bgColor, fgColor, shadowColor };
    s32 i, j, k, count;
    u32 *ptr;
    u16 *lookup = sFontHalfRowLookupTable;
    u32 ip = 0;

    sLastTextBgColor = bgColor;
    sLastTextFgColor = fgColor;
    sLastTextShadowColor = shadowColor;

    for (i = 0; i <= 2; i++)
        for (j = 0; j <= 2; j++)
            for (k = 0; k <= 2; k++)
            {
                ptr = colors;
                for (count = 2; count >= 0; count--, ptr++)
                    lookup[ip++] = (*ptr << 12) | (colors[k] << 8) | (colors[j] << 4) | colors[i];
            }
}
#endif

void SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
{
    *bgColor = sLastTextBgColor;
    *fgColor = sLastTextFgColor;
    *shadowColor = sLastTextShadowColor;
}

void RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
{
    GenerateFontHalfRowLookupTable(*fgColor, *bgColor, *shadowColor);
}

// JP ROM data at 0x0829BEB8 (glyph nibble -> palette index)
extern const u8 sGlyphPaletteIdxTable[];

void DecompressGlyphTile(const void *src_, void *dest_)
{
    const u8 *src = src_;
    u16 *dest = dest_;
    s32 i;

    for (i = 0; i < 16; i++)
    {
        u8 idx;
        if ((i << 31) != 0)
        {
            idx = *src++;
            src++;
        }
        else
        {
            idx = *(const u16 *)src >> 8;
        }
        *dest++ = sFontHalfRowLookupTable[sGlyphPaletteIdxTable[idx]];
    }
}

static u8 UNUSED GetLastTextColor(u8 colorType)
{
    switch (colorType)
    {
    case 0:
        return sLastTextFgColor;
    case 2:
        return sLastTextBgColor;
    case 1:
        return sLastTextShadowColor;
    default:
        return 0;
    }
}

#define GLYPH_COPY(windowTiles, widthOffset, j, i, glyphPixels, width, height) \
{ \
    u32 xAdd, yAdd, pixelData, bits, toOrr, dummyX; \
    u8 *dst; \
    xAdd = (j) + (width); \
    yAdd = (i) + (height); \
    dummyX = (j); \
    for (; (i) < yAdd; (i)++) \
    { \
        pixelData = *(glyphPixels)++; \
        for ((j) = dummyX; (j) < xAdd; (j)++) \
        { \
            if ((toOrr = pixelData & 0xF)) \
            { \
                dst = (windowTiles) + (((j) / 8) * 32) + (((j) % 8) / 2) + (((i) / 8) * (widthOffset)) + (((i) % 8) * 4); \
                bits = (((j) & 1) * 4); \
                *dst = (toOrr << bits) | (*dst & (0xF0 >> bits)); \
            } \
            pixelData >>= 4; \
        } \
    } \
}

__attribute__((naked)) void CopyGlyphToWindow(struct TextPrinter *textPrinter)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0x6c\n\t"
            "adds r6, r0, #0\n\t"
            "ldr r0, _080048C0\n\t"
            "mov sb, r0\n\t"
            "ldrb r1, [r6, #4]\n\t"
            "lsls r0, r1, #1\n\t"
            "adds r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "mov r1, sb\n\t"
            "adds r2, r0, r1\n\t"
            "ldrb r0, [r2, #3]\n\t"
            "lsls r0, r0, #3\n\t"
            "ldrb r1, [r6, #8]\n\t"
            "subs r1, r0, r1\n\t"
            "ldr r3, _080048C4\n\t"
            "mov r8, r3\n\t"
            "mov r0, r8\n\t"
            "adds r0, #0x80\n\t"
            "ldrb r7, [r0]\n\t"
            "cmp r1, r7\n\t"
            "bge _08004886\n\t"
            "adds r7, r1, #0\n\t"
            "_08004886:\n\t"
            "ldrb r0, [r2, #4]\n\t"
            "lsls r0, r0, #3\n\t"
            "ldrb r4, [r6, #9]\n\t"
            "subs r0, r0, r4\n\t"
            "adds r1, r3, #0\n\t"
            "adds r1, #0x81\n\t"
            "ldrb r1, [r1]\n\t"
            "mov sl, r1\n\t"
            "adds r5, r4, #0\n\t"
            "cmp r0, sl\n\t"
            "bge _0800489E\n\t"
            "mov sl, r0\n\t"
            "_0800489E:\n\t"
            "movs r1, #0\n\t"
            "cmp r7, #8\n\t"
            "ble _080048A6\n\t"
            "movs r1, #1\n\t"
            "_080048A6:\n\t"
            "mov r0, sl\n\t"
            "cmp r0, #8\n\t"
            "ble _080048B0\n\t"
            "movs r0, #2\n\t"
            "orrs r1, r0\n\t"
            "_080048B0:\n\t"
            "cmp r1, #1\n\t"
            "beq _08004970\n\t"
            "cmp r1, #1\n\t"
            "bgt _080048C8\n\t"
            "cmp r1, #0\n\t"
            "beq _080048D6\n\t"
            "b _08004E38\n\t"
            ".align 2, 0\n\t"
            "_080048C0: .4byte gWindows\n\t"
            "_080048C4: .4byte gCurGlyph\n\t"
            "_080048C8:\n\t"
            "cmp r1, #2\n\t"
            "bne _080048CE\n\t"
            "b _08004AA4\n\t"
            "_080048CE:\n\t"
            "cmp r1, #3\n\t"
            "bne _080048D4\n\t"
            "b _08004BDC\n\t"
            "_080048D4:\n\t"
            "b _08004E38\n\t"
            "_080048D6:\n\t"
            "adds r2, r3, #0\n\t"
            "movs r1, #0\n\t"
            "adds r0, r5, #0\n\t"
            "cmp r1, sl\n\t"
            "blt _080048E2\n\t"
            "b _08004E38\n\t"
            "_080048E2:\n\t"
            "ldm r2!, {r3}\n\t"
            "str r3, [sp]\n\t"
            "movs r5, #0\n\t"
            "ldrb r4, [r6, #8]\n\t"
            "str r2, [sp, #0x28]\n\t"
            "adds r1, #1\n\t"
            "str r1, [sp, #0x20]\n\t"
            "adds r1, r0, #1\n\t"
            "str r1, [sp, #0x24]\n\t"
            "cmp r5, r7\n\t"
            "bge _08004960\n\t"
            "ldr r2, _0800496C\n\t"
            "mov ip, r2\n\t"
            "asrs r3, r0, #3\n\t"
            "mov sb, r3\n\t"
            "lsls r0, r0, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004906:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "mov r1, ip\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r3, ip\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, sb\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "ldr r2, [sp]\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004958\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004958:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, r7\n\t"
            "blt _08004906\n\t"
            "_08004960:\n\t"
            "ldr r2, [sp, #0x28]\n\t"
            "ldr r1, [sp, #0x20]\n\t"
            "ldr r0, [sp, #0x24]\n\t"
            "cmp r1, sl\n\t"
            "blt _080048E2\n\t"
            "b _08004E38\n\t"
            ".align 2, 0\n\t"
            "_0800496C: .4byte gWindows\n\t"
            "_08004970:\n\t"
            "movs r2, #0\n\t"
            "adds r1, r5, #0\n\t"
            "cmp r2, sl\n\t"
            "bge _080049FA\n\t"
            "_08004978:\n\t"
            "ldm r3!, {r0}\n\t"
            "mov sb, r0\n\t"
            "movs r5, #0\n\t"
            "ldrb r4, [r6, #8]\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "str r3, [sp, #0x38]\n\t"
            "adds r2, #1\n\t"
            "str r2, [sp, #0x30]\n\t"
            "adds r2, r1, #1\n\t"
            "str r2, [sp, #0x34]\n\t"
            "asrs r1, r1, #3\n\t"
            "mov ip, r1\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004994:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "ldr r1, _08004A9C\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "ldr r0, _08004A9C\n\t"
            "adds r3, r3, r0\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, ip\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, sb\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _080049E8\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_080049E8:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, #7\n\t"
            "ble _08004994\n\t"
            "ldr r3, [sp, #0x38]\n\t"
            "ldr r2, [sp, #0x30]\n\t"
            "ldr r1, [sp, #0x34]\n\t"
            "cmp r2, sl\n\t"
            "blt _08004978\n\t"
            "_080049FA:\n\t"
            "ldr r3, _08004AA0\n\t"
            "movs r2, #0\n\t"
            "ldrb r1, [r6, #9]\n\t"
            "cmp r2, sl\n\t"
            "blt _08004A06\n\t"
            "b _08004E38\n\t"
            "_08004A06:\n\t"
            "subs r7, #8\n\t"
            "str r7, [sp, #0x64]\n\t"
            "str r7, [sp, #4]\n\t"
            "_08004A0C:\n\t"
            "ldm r3!, {r0}\n\t"
            "mov ip, r0\n\t"
            "movs r5, #0\n\t"
            "ldrb r0, [r6, #8]\n\t"
            "adds r4, r0, #0\n\t"
            "adds r4, #8\n\t"
            "str r3, [sp, #0x50]\n\t"
            "adds r2, #1\n\t"
            "str r2, [sp, #0x48]\n\t"
            "adds r2, r1, #1\n\t"
            "str r2, [sp, #0x4c]\n\t"
            "ldr r3, [sp, #4]\n\t"
            "cmp r5, r3\n\t"
            "bge _08004A90\n\t"
            "ldr r7, _08004A9C\n\t"
            "asrs r0, r1, #3\n\t"
            "mov sb, r0\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004A34:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r1, r7, #0\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r3, r3, r7\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, sb\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, ip\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004A86\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004A86:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "ldr r1, [sp, #0x64]\n\t"
            "cmp r5, r1\n\t"
            "blt _08004A34\n\t"
            "_08004A90:\n\t"
            "ldr r3, [sp, #0x50]\n\t"
            "ldr r2, [sp, #0x48]\n\t"
            "ldr r1, [sp, #0x4c]\n\t"
            "cmp r2, sl\n\t"
            "blt _08004A0C\n\t"
            "b _08004E38\n\t"
            ".align 2, 0\n\t"
            "_08004A9C: .4byte gWindows\n\t"
            "_08004AA0: .4byte gCurGlyph + 0x20\n\t"
            "_08004AA4:\n\t"
            "adds r1, r3, #0\n\t"
            "movs r2, #0\n\t"
            "adds r0, r5, #0\n\t"
            "mov r3, sl\n\t"
            "subs r3, #8\n\t"
            "str r3, [sp, #0x68]\n\t"
            "_08004AB0:\n\t"
            "ldm r1!, {r3}\n\t"
            "mov sl, r3\n\t"
            "movs r5, #0\n\t"
            "ldrb r4, [r6, #8]\n\t"
            "str r1, [sp, #0x60]\n\t"
            "adds r2, #1\n\t"
            "str r2, [sp, #0x58]\n\t"
            "adds r1, r0, #1\n\t"
            "str r1, [sp, #0x5c]\n\t"
            "cmp r5, r7\n\t"
            "bge _08004B2E\n\t"
            "ldr r2, _08004BD4\n\t"
            "mov ip, r2\n\t"
            "asrs r3, r0, #3\n\t"
            "mov sb, r3\n\t"
            "lsls r0, r0, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004AD4:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "mov r1, ip\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r3, ip\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, sb\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, sl\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004B26\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004B26:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, r7\n\t"
            "blt _08004AD4\n\t"
            "_08004B2E:\n\t"
            "ldr r1, [sp, #0x60]\n\t"
            "ldr r2, [sp, #0x58]\n\t"
            "ldr r0, [sp, #0x5c]\n\t"
            "cmp r2, #7\n\t"
            "ble _08004AB0\n\t"
            "ldr r2, _08004BD8\n\t"
            "movs r1, #0\n\t"
            "ldrb r0, [r6, #9]\n\t"
            "adds r0, #8\n\t"
            "ldr r3, [sp, #0x68]\n\t"
            "cmp r1, r3\n\t"
            "blt _08004B48\n\t"
            "b _08004E38\n\t"
            "_08004B48:\n\t"
            "ldm r2!, {r3}\n\t"
            "mov sl, r3\n\t"
            "movs r5, #0\n\t"
            "ldrb r4, [r6, #8]\n\t"
            "str r2, [sp, #0x1c]\n\t"
            "adds r1, #1\n\t"
            "str r1, [sp, #0x14]\n\t"
            "adds r1, r0, #1\n\t"
            "str r1, [sp, #0x18]\n\t"
            "cmp r5, r7\n\t"
            "bge _08004BC6\n\t"
            "ldr r2, _08004BD4\n\t"
            "mov ip, r2\n\t"
            "asrs r3, r0, #3\n\t"
            "mov sb, r3\n\t"
            "lsls r0, r0, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004B6C:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "mov r1, ip\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r3, ip\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, sb\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, sl\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004BBE\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004BBE:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, r7\n\t"
            "blt _08004B6C\n\t"
            "_08004BC6:\n\t"
            "ldr r2, [sp, #0x1c]\n\t"
            "ldr r1, [sp, #0x14]\n\t"
            "ldr r0, [sp, #0x18]\n\t"
            "ldr r3, [sp, #0x68]\n\t"
            "cmp r1, r3\n\t"
            "blt _08004B48\n\t"
            "b _08004E38\n\t"
            ".align 2, 0\n\t"
            "_08004BD4: .4byte gWindows\n\t"
            "_08004BD8: .4byte gCurGlyph + 0x40\n\t"
            "_08004BDC:\n\t"
            "mov r2, r8\n\t"
            "movs r3, #0\n\t"
            "adds r1, r4, #0\n\t"
            "subs r7, #8\n\t"
            "str r7, [sp, #0x64]\n\t"
            "mov r0, sl\n\t"
            "subs r0, #8\n\t"
            "str r0, [sp, #0x68]\n\t"
            "_08004BEC:\n\t"
            "ldm r2!, {r0}\n\t"
            "mov sb, r0\n\t"
            "movs r5, #0\n\t"
            "ldrb r4, [r6, #8]\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "str r2, [sp, #0x2c]\n\t"
            "adds r3, #1\n\t"
            "mov sl, r3\n\t"
            "adds r2, r1, #1\n\t"
            "mov ip, r2\n\t"
            "asrs r1, r1, #3\n\t"
            "mov r8, r1\n\t"
            "lsrs r7, r0, #0x1b\n\t"
            "_08004C06:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "ldr r1, _08004D0C\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "ldr r0, _08004D0C\n\t"
            "adds r3, r3, r0\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, r8\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r3, r1, r7\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, sb\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004C58\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004C58:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, #7\n\t"
            "ble _08004C06\n\t"
            "ldr r2, [sp, #0x2c]\n\t"
            "mov r3, sl\n\t"
            "mov r1, ip\n\t"
            "cmp r3, #7\n\t"
            "ble _08004BEC\n\t"
            "ldr r3, _08004D10\n\t"
            "movs r2, #0\n\t"
            "ldrb r1, [r6, #9]\n\t"
            "ldr r0, [sp, #0x64]\n\t"
            "mov ip, r0\n\t"
            "_08004C74:\n\t"
            "ldm r3!, {r0}\n\t"
            "mov sl, r0\n\t"
            "movs r5, #0\n\t"
            "ldrb r0, [r6, #8]\n\t"
            "adds r4, r0, #0\n\t"
            "adds r4, #8\n\t"
            "str r3, [sp, #0x44]\n\t"
            "adds r2, #1\n\t"
            "str r2, [sp, #0x3c]\n\t"
            "adds r2, r1, #1\n\t"
            "str r2, [sp, #0x40]\n\t"
            "cmp r5, ip\n\t"
            "bge _08004CF4\n\t"
            "ldr r7, _08004D0C\n\t"
            "asrs r3, r1, #3\n\t"
            "mov sb, r3\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004C9A:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r1, r7, #0\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r3, r3, r7\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, sb\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, sl\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004CEC\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004CEC:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, ip\n\t"
            "blt _08004C9A\n\t"
            "_08004CF4:\n\t"
            "ldr r3, [sp, #0x44]\n\t"
            "ldr r2, [sp, #0x3c]\n\t"
            "ldr r1, [sp, #0x40]\n\t"
            "cmp r2, #7\n\t"
            "ble _08004C74\n\t"
            "ldr r3, _08004D14\n\t"
            "movs r2, #0\n\t"
            "ldrb r0, [r6, #9]\n\t"
            "adds r1, r0, #0\n\t"
            "adds r1, #8\n\t"
            "b _08004D92\n\t"
            ".align 2, 0\n\t"
            "_08004D0C: .4byte gWindows\n\t"
            "_08004D10: .4byte gCurGlyph + 0x20\n\t"
            "_08004D14: .4byte gCurGlyph + 0x40\n\t"
            "_08004D18:\n\t"
            "ldm r3!, {r0}\n\t"
            "mov sb, r0\n\t"
            "movs r5, #0\n\t"
            "ldrb r4, [r6, #8]\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "str r3, [sp, #0x54]\n\t"
            "adds r2, #1\n\t"
            "mov sl, r2\n\t"
            "adds r2, r1, #1\n\t"
            "mov ip, r2\n\t"
            "asrs r1, r1, #3\n\t"
            "mov r8, r1\n\t"
            "lsrs r7, r0, #0x1b\n\t"
            "_08004D32:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "ldr r1, _08004E48\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "ldr r0, _08004E48\n\t"
            "adds r3, r3, r0\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, r8\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r3, r1, r7\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, sb\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004D84\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004D84:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, #7\n\t"
            "ble _08004D32\n\t"
            "ldr r3, [sp, #0x54]\n\t"
            "mov r2, sl\n\t"
            "mov r1, ip\n\t"
            "_08004D92:\n\t"
            "ldr r0, [sp, #0x68]\n\t"
            "cmp r2, r0\n\t"
            "blt _08004D18\n\t"
            "ldr r3, _08004E4C\n\t"
            "movs r2, #0\n\t"
            "ldrb r0, [r6, #9]\n\t"
            "adds r1, r0, #0\n\t"
            "adds r1, #8\n\t"
            "ldr r0, [sp, #0x68]\n\t"
            "cmp r2, r0\n\t"
            "bge _08004E38\n\t"
            "ldr r0, [sp, #0x64]\n\t"
            "mov sl, r0\n\t"
            "_08004DAC:\n\t"
            "ldm r3!, {r0}\n\t"
            "mov ip, r0\n\t"
            "movs r5, #0\n\t"
            "ldrb r0, [r6, #8]\n\t"
            "adds r4, r0, #0\n\t"
            "adds r4, #8\n\t"
            "str r3, [sp, #0x10]\n\t"
            "adds r2, #1\n\t"
            "str r2, [sp, #8]\n\t"
            "adds r2, r1, #1\n\t"
            "str r2, [sp, #0xc]\n\t"
            "cmp r5, sl\n\t"
            "bge _08004E2C\n\t"
            "ldr r7, _08004E48\n\t"
            "asrs r3, r1, #3\n\t"
            "mov sb, r3\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "mov r8, r0\n\t"
            "_08004DD2:\n\t"
            "ldrb r0, [r6, #4]\n\t"
            "lsls r3, r0, #1\n\t"
            "adds r3, r3, r0\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r1, r7, #0\n\t"
            "adds r1, #8\n\t"
            "adds r1, r3, r1\n\t"
            "asrs r2, r4, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "ldr r1, [r1]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r3, r3, r7\n\t"
            "ldrb r0, [r3, #3]\n\t"
            "mov r2, sb\n\t"
            "muls r2, r0, r2\n\t"
            "adds r0, r2, #0\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "mov r0, r8\n\t"
            "adds r3, r1, r0\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, ip\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004E24\n\t"
            "movs r0, #1\n\t"
            "ands r0, r4\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r3]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r3]\n\t"
            "_08004E24:\n\t"
            "adds r5, #1\n\t"
            "adds r4, #1\n\t"
            "cmp r5, sl\n\t"
            "blt _08004DD2\n\t"
            "_08004E2C:\n\t"
            "ldr r3, [sp, #0x10]\n\t"
            "ldr r2, [sp, #8]\n\t"
            "ldr r1, [sp, #0xc]\n\t"
            "ldr r0, [sp, #0x68]\n\t"
            "cmp r2, r0\n\t"
            "blt _08004DAC\n\t"
            "_08004E38:\n\t"
            "add sp, #0x6c\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_08004E48: .4byte gWindows\n\t"
            "_08004E4C: .4byte gCurGlyph + 0x60\n\t"
            ".syntax divided");
}

__attribute__((naked)) void ClearTextSpan(struct Window *window, u16 x, u16 y, u16 width, u16 height)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0x40\n\t"
            "str r0, [sp]\n\t"
            "ldr r0, [sp, #0x60]\n\t"
            "lsls r1, r1, #0x10\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "str r1, [sp, #4]\n\t"
            "lsls r2, r2, #0x10\n\t"
            "lsrs r2, r2, #0x10\n\t"
            "str r2, [sp, #8]\n\t"
            "lsls r3, r3, #0x10\n\t"
            "lsrs r3, r3, #0x10\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r4, r0, #0x10\n\t"
            "subs r1, r3, r1\n\t"
            "ldr r5, _08004EC4\n\t"
            "adds r0, r5, #0\n\t"
            "adds r0, #0x80\n\t"
            "ldrb r7, [r0]\n\t"
            "adds r2, r5, #0\n\t"
            "cmp r1, r7\n\t"
            "bge _08004E86\n\t"
            "adds r7, r1, #0\n\t"
            "_08004E86:\n\t"
            "ldr r1, [sp, #8]\n\t"
            "subs r0, r4, r1\n\t"
            "adds r1, r2, #0\n\t"
            "adds r1, #0x81\n\t"
            "ldrb r1, [r1]\n\t"
            "str r1, [sp, #0xc]\n\t"
            "cmp r0, r1\n\t"
            "bge _08004E98\n\t"
            "str r0, [sp, #0xc]\n\t"
            "_08004E98:\n\t"
            "movs r1, #0\n\t"
            "movs r0, #7\n\t"
            "ands r0, r3\n\t"
            "adds r0, r3, r0\n\t"
            "lsrs r0, r0, #3\n\t"
            "str r0, [sp, #0x10]\n\t"
            "cmp r7, #8\n\t"
            "ble _08004EAA\n\t"
            "movs r1, #1\n\t"
            "_08004EAA:\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "cmp r3, #8\n\t"
            "ble _08004EB4\n\t"
            "movs r0, #2\n\t"
            "orrs r1, r0\n\t"
            "_08004EB4:\n\t"
            "cmp r1, #1\n\t"
            "beq _08004F54\n\t"
            "cmp r1, #1\n\t"
            "bgt _08004EC8\n\t"
            "cmp r1, #0\n\t"
            "beq _08004ED6\n\t"
            "b _0800533C\n\t"
            ".align 2, 0\n\t"
            "_08004EC4: .4byte gCurGlyph\n\t"
            "_08004EC8:\n\t"
            "cmp r1, #2\n\t"
            "bne _08004ECE\n\t"
            "b _08005058\n\t"
            "_08004ECE:\n\t"
            "cmp r1, #3\n\t"
            "bne _08004ED4\n\t"
            "b _08005158\n\t"
            "_08004ED4:\n\t"
            "b _0800533C\n\t"
            "_08004ED6:\n\t"
            "adds r1, r2, #0\n\t"
            "movs r0, #0\n\t"
            "ldr r2, [sp, #8]\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "cmp r0, r3\n\t"
            "blt _08004EE4\n\t"
            "b _0800533C\n\t"
            "_08004EE4:\n\t"
            "ldm r1!, {r3}\n\t"
            "mov r8, r3\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "str r1, [sp, #0x28]\n\t"
            "adds r0, #1\n\t"
            "mov sb, r0\n\t"
            "adds r0, r2, #1\n\t"
            "mov sl, r0\n\t"
            "cmp r5, r7\n\t"
            "bge _08004F46\n\t"
            "asrs r0, r2, #3\n\t"
            "ldr r1, [sp, #0x10]\n\t"
            "muls r0, r1, r0\n\t"
            "lsls r0, r0, #5\n\t"
            "mov ip, r0\n\t"
            "lsls r0, r2, #0x1d\n\t"
            "lsrs r6, r0, #0x1b\n\t"
            "_08004F08:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r2, [sp]\n\t"
            "adds r1, r2, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r1, ip\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004F3E\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_08004F3E:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r5, r7\n\t"
            "blt _08004F08\n\t"
            "_08004F46:\n\t"
            "ldr r1, [sp, #0x28]\n\t"
            "mov r0, sb\n\t"
            "mov r2, sl\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "cmp r0, r3\n\t"
            "blt _08004EE4\n\t"
            "b _0800533C\n\t"
            "_08004F54:\n\t"
            "adds r5, r2, #0\n\t"
            "movs r4, #0\n\t"
            "ldr r2, [sp, #8]\n\t"
            "ldr r0, [sp, #0xc]\n\t"
            "cmp r4, r0\n\t"
            "bge _08004FCA\n\t"
            "_08004F60:\n\t"
            "ldm r5!, {r1}\n\t"
            "mov r8, r1\n\t"
            "movs r6, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "asrs r0, r2, #3\n\t"
            "lsls r1, r2, #0x1d\n\t"
            "str r5, [sp, #0x2c]\n\t"
            "adds r4, #1\n\t"
            "mov sb, r4\n\t"
            "adds r2, #1\n\t"
            "mov sl, r2\n\t"
            "ldr r2, [sp, #0x10]\n\t"
            "muls r0, r2, r0\n\t"
            "lsls r0, r0, #5\n\t"
            "mov ip, r0\n\t"
            "lsrs r5, r1, #0x1b\n\t"
            "_08004F80:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r0, [sp]\n\t"
            "adds r1, r0, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r1, ip\n\t"
            "adds r4, r1, r5\n\t"
            "lsls r0, r6, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08004FB6\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_08004FB6:\n\t"
            "adds r6, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r6, #7\n\t"
            "ble _08004F80\n\t"
            "ldr r5, [sp, #0x2c]\n\t"
            "mov r4, sb\n\t"
            "mov r2, sl\n\t"
            "ldr r1, [sp, #0xc]\n\t"
            "cmp r4, r1\n\t"
            "blt _08004F60\n\t"
            "_08004FCA:\n\t"
            "ldr r1, _08005054\n\t"
            "movs r0, #0\n\t"
            "ldr r2, [sp, #8]\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "cmp r0, r3\n\t"
            "blt _08004FD8\n\t"
            "b _0800533C\n\t"
            "_08004FD8:\n\t"
            "subs r7, #8\n\t"
            "str r7, [sp, #0x18]\n\t"
            "str r7, [sp, #0x14]\n\t"
            "_08004FDE:\n\t"
            "ldm r1!, {r3}\n\t"
            "mov r8, r3\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "adds r3, #8\n\t"
            "mov ip, r1\n\t"
            "adds r0, #1\n\t"
            "mov sb, r0\n\t"
            "adds r0, r2, #1\n\t"
            "mov sl, r0\n\t"
            "ldr r1, [sp, #0x14]\n\t"
            "cmp r5, r1\n\t"
            "bge _08005044\n\t"
            "asrs r0, r2, #3\n\t"
            "ldr r1, [sp, #0x10]\n\t"
            "muls r0, r1, r0\n\t"
            "lsls r7, r0, #5\n\t"
            "lsls r0, r2, #0x1d\n\t"
            "lsrs r6, r0, #0x1b\n\t"
            "_08005004:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r2, [sp]\n\t"
            "adds r1, r2, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, r1, r7\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _0800503A\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_0800503A:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "ldr r0, [sp, #0x18]\n\t"
            "cmp r5, r0\n\t"
            "blt _08005004\n\t"
            "_08005044:\n\t"
            "mov r1, ip\n\t"
            "mov r0, sb\n\t"
            "mov r2, sl\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "cmp r0, r3\n\t"
            "blt _08004FDE\n\t"
            "b _0800533C\n\t"
            ".align 2, 0\n\t"
            "_08005054: .4byte gCurGlyph + 0x20\n\t"
            "_08005058:\n\t"
            "adds r0, r2, #0\n\t"
            "movs r1, #0\n\t"
            "ldr r2, [sp, #8]\n\t"
            "adds r3, r2, #0\n\t"
            "adds r3, #8\n\t"
            "str r3, [sp, #0x1c]\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "subs r3, #8\n\t"
            "str r3, [sp, #0x20]\n\t"
            "_0800506A:\n\t"
            "ldm r0!, {r3}\n\t"
            "mov r8, r3\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "str r0, [sp, #0x34]\n\t"
            "adds r1, #1\n\t"
            "mov sb, r1\n\t"
            "adds r0, r2, #1\n\t"
            "mov sl, r0\n\t"
            "cmp r5, r7\n\t"
            "bge _080050CC\n\t"
            "asrs r0, r2, #3\n\t"
            "ldr r1, [sp, #0x10]\n\t"
            "muls r0, r1, r0\n\t"
            "lsls r0, r0, #5\n\t"
            "mov ip, r0\n\t"
            "lsls r0, r2, #0x1d\n\t"
            "lsrs r6, r0, #0x1b\n\t"
            "_0800508E:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r2, [sp]\n\t"
            "adds r1, r2, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r1, ip\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _080050C4\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_080050C4:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r5, r7\n\t"
            "blt _0800508E\n\t"
            "_080050CC:\n\t"
            "ldr r0, [sp, #0x34]\n\t"
            "mov r1, sb\n\t"
            "mov r2, sl\n\t"
            "cmp r1, #7\n\t"
            "ble _0800506A\n\t"
            "ldr r2, _08005154\n\t"
            "movs r0, #0\n\t"
            "ldr r1, [sp, #0x1c]\n\t"
            "ldr r3, [sp, #0x20]\n\t"
            "cmp r0, r3\n\t"
            "blt _080050E4\n\t"
            "b _0800533C\n\t"
            "_080050E4:\n\t"
            "ldm r2!, {r3}\n\t"
            "mov r8, r3\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "str r2, [sp, #0x38]\n\t"
            "adds r0, #1\n\t"
            "mov sb, r0\n\t"
            "adds r0, r1, #1\n\t"
            "mov sl, r0\n\t"
            "cmp r5, r7\n\t"
            "bge _08005146\n\t"
            "asrs r0, r1, #3\n\t"
            "ldr r2, [sp, #0x10]\n\t"
            "muls r0, r2, r0\n\t"
            "lsls r0, r0, #5\n\t"
            "mov ip, r0\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "lsrs r6, r0, #0x1b\n\t"
            "_08005108:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r0, [sp]\n\t"
            "adds r1, r0, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "add r1, ip\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _0800513E\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_0800513E:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r5, r7\n\t"
            "blt _08005108\n\t"
            "_08005146:\n\t"
            "ldr r2, [sp, #0x38]\n\t"
            "mov r0, sb\n\t"
            "mov r1, sl\n\t"
            "ldr r3, [sp, #0x20]\n\t"
            "cmp r0, r3\n\t"
            "blt _080050E4\n\t"
            "b _0800533C\n\t"
            ".align 2, 0\n\t"
            "_08005154: .4byte gCurGlyph + 0x40\n\t"
            "_08005158:\n\t"
            "movs r2, #0\n\t"
            "ldr r4, [sp, #8]\n\t"
            "ldr r0, [sp, #4]\n\t"
            "adds r0, #8\n\t"
            "str r0, [sp, #0x3c]\n\t"
            "subs r7, #8\n\t"
            "str r7, [sp, #0x18]\n\t"
            "adds r1, r4, #0\n\t"
            "adds r1, #8\n\t"
            "str r1, [sp, #0x1c]\n\t"
            "ldr r3, [sp, #0xc]\n\t"
            "subs r3, #8\n\t"
            "str r3, [sp, #0x20]\n\t"
            "_08005172:\n\t"
            "ldm r5!, {r0}\n\t"
            "mov r8, r0\n\t"
            "movs r6, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "asrs r0, r4, #3\n\t"
            "lsls r1, r4, #0x1d\n\t"
            "mov sl, r5\n\t"
            "adds r2, #1\n\t"
            "mov ip, r2\n\t"
            "adds r4, #1\n\t"
            "mov sb, r4\n\t"
            "ldr r2, [sp, #0x10]\n\t"
            "muls r0, r2, r0\n\t"
            "lsls r7, r0, #5\n\t"
            "lsrs r5, r1, #0x1b\n\t"
            "_08005190:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r0, [sp]\n\t"
            "adds r1, r0, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, r1, r7\n\t"
            "adds r4, r1, r5\n\t"
            "lsls r0, r6, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _080051C6\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_080051C6:\n\t"
            "adds r6, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r6, #7\n\t"
            "ble _08005190\n\t"
            "mov r5, sl\n\t"
            "mov r2, ip\n\t"
            "mov r4, sb\n\t"
            "cmp r2, #7\n\t"
            "ble _08005172\n\t"
            "ldr r1, _0800534C\n\t"
            "movs r0, #0\n\t"
            "ldr r2, [sp, #8]\n\t"
            "ldr r3, [sp, #0x18]\n\t"
            "mov ip, r3\n\t"
            "_080051E2:\n\t"
            "ldm r1!, {r3}\n\t"
            "mov r8, r3\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #0x3c]\n\t"
            "str r1, [sp, #0x24]\n\t"
            "adds r0, #1\n\t"
            "mov sb, r0\n\t"
            "adds r0, r2, #1\n\t"
            "mov sl, r0\n\t"
            "cmp r5, ip\n\t"
            "bge _08005242\n\t"
            "asrs r0, r2, #3\n\t"
            "ldr r1, [sp, #0x10]\n\t"
            "muls r0, r1, r0\n\t"
            "lsls r7, r0, #5\n\t"
            "lsls r0, r2, #0x1d\n\t"
            "lsrs r6, r0, #0x1b\n\t"
            "_08005204:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r2, [sp]\n\t"
            "adds r1, r2, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, r1, r7\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _0800523A\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_0800523A:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r5, ip\n\t"
            "blt _08005204\n\t"
            "_08005242:\n\t"
            "ldr r1, [sp, #0x24]\n\t"
            "mov r0, sb\n\t"
            "mov r2, sl\n\t"
            "cmp r0, #7\n\t"
            "ble _080051E2\n\t"
            "ldr r6, _08005350\n\t"
            "movs r4, #0\n\t"
            "ldr r2, [sp, #0x1c]\n\t"
            "ldr r3, [sp, #0x20]\n\t"
            "cmp r4, r3\n\t"
            "bge _080052C0\n\t"
            "_08005258:\n\t"
            "ldm r6!, {r0}\n\t"
            "mov r8, r0\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #4]\n\t"
            "asrs r0, r2, #3\n\t"
            "lsls r1, r2, #0x1d\n\t"
            "mov ip, r6\n\t"
            "adds r4, #1\n\t"
            "mov sb, r4\n\t"
            "adds r2, #1\n\t"
            "mov sl, r2\n\t"
            "ldr r2, [sp, #0x10]\n\t"
            "muls r0, r2, r0\n\t"
            "lsls r7, r0, #5\n\t"
            "lsrs r6, r1, #0x1b\n\t"
            "_08005276:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r0, [sp]\n\t"
            "adds r1, r0, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, r1, r7\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _080052AC\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_080052AC:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r5, #7\n\t"
            "ble _08005276\n\t"
            "mov r6, ip\n\t"
            "mov r4, sb\n\t"
            "mov r2, sl\n\t"
            "ldr r1, [sp, #0x20]\n\t"
            "cmp r4, r1\n\t"
            "blt _08005258\n\t"
            "_080052C0:\n\t"
            "ldr r2, _08005354\n\t"
            "movs r0, #0\n\t"
            "ldr r1, [sp, #0x1c]\n\t"
            "ldr r3, [sp, #0x20]\n\t"
            "cmp r0, r3\n\t"
            "bge _0800533C\n\t"
            "ldr r3, [sp, #0x18]\n\t"
            "mov ip, r3\n\t"
            "_080052D0:\n\t"
            "ldm r2!, {r3}\n\t"
            "mov r8, r3\n\t"
            "movs r5, #0\n\t"
            "ldr r3, [sp, #0x3c]\n\t"
            "str r2, [sp, #0x30]\n\t"
            "adds r0, #1\n\t"
            "mov sb, r0\n\t"
            "adds r0, r1, #1\n\t"
            "mov sl, r0\n\t"
            "cmp r5, ip\n\t"
            "bge _08005330\n\t"
            "asrs r0, r1, #3\n\t"
            "ldr r2, [sp, #0x10]\n\t"
            "muls r0, r2, r0\n\t"
            "lsls r7, r0, #5\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "lsrs r6, r0, #0x1b\n\t"
            "_080052F2:\n\t"
            "asrs r1, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r1, r0\n\t"
            "ldr r0, [sp]\n\t"
            "adds r1, r0, r1\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, r1, r7\n\t"
            "adds r4, r1, r6\n\t"
            "lsls r0, r5, #2\n\t"
            "mov r2, r8\n\t"
            "lsrs r2, r0\n\t"
            "movs r0, #0xf\n\t"
            "ands r2, r0\n\t"
            "cmp r2, #0\n\t"
            "beq _08005328\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "lsls r2, r0\n\t"
            "movs r1, #0xf0\n\t"
            "asrs r1, r0\n\t"
            "ldrb r0, [r4]\n\t"
            "ands r1, r0\n\t"
            "orrs r2, r1\n\t"
            "strb r2, [r4]\n\t"
            "_08005328:\n\t"
            "adds r5, #1\n\t"
            "adds r3, #1\n\t"
            "cmp r5, ip\n\t"
            "blt _080052F2\n\t"
            "_08005330:\n\t"
            "ldr r2, [sp, #0x30]\n\t"
            "mov r0, sb\n\t"
            "mov r1, sl\n\t"
            "ldr r3, [sp, #0x20]\n\t"
            "cmp r0, r3\n\t"
            "blt _080052D0\n\t"
            "_0800533C:\n\t"
            "add sp, #0x40\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_0800534C: .4byte gCurGlyph + 0x20\n\t"
            "_08005350: .4byte gCurGlyph + 0x40\n\t"
            "_08005354: .4byte gCurGlyph + 0x60\n\t"
            ".syntax divided");
}

static u16 FontFunc_Small(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasFontIdBeenSet == FALSE)
    {
        subStruct->fontId = FONT_SMALL;
        subStruct->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_Normal(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasFontIdBeenSet == FALSE)
    {
        subStruct->fontId = FONT_NORMAL;
        subStruct->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_Short(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasFontIdBeenSet == FALSE)
    {
        subStruct->fontId = FONT_SHORT;
        subStruct->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortCopy1(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasFontIdBeenSet == FALSE)
    {
        subStruct->fontId = FONT_SHORT_COPY_1;
        subStruct->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortCopy2(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasFontIdBeenSet == FALSE)
    {
        subStruct->fontId = FONT_SHORT_COPY_2;
        subStruct->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortCopy3(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasFontIdBeenSet == FALSE)
    {
        subStruct->fontId = FONT_SHORT_COPY_3;
        subStruct->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}



void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (gTextFlags.autoScroll == 1)
    {
        subStruct->autoScrollDelay = 0;
    }
    else
    {
        subStruct->downArrowYPosIdx = 0;
        subStruct->downArrowDelay = 0;
    }
}

void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);
    const u8 *arrowTiles;

    if (gTextFlags.autoScroll == 0)
    {
        if (subStruct->downArrowDelay != 0)
        {
            subStruct->downArrowDelay--;
        }
        else
        {
            FillWindowPixelRect(
                textPrinter->printerTemplate.windowId,
                textPrinter->printerTemplate.bgColor << 4 | textPrinter->printerTemplate.bgColor,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);

            switch (gTextFlags.useAlternateDownArrow)
            {
            case FALSE:
            default:
                arrowTiles = sDownArrowTiles;
                break;
            case TRUE:
                arrowTiles = sDarkDownArrowTiles;
                break;
            }

            BlitBitmapRectToWindow(
                textPrinter->printerTemplate.windowId,
                arrowTiles,
                0,
                sDownArrowYCoords[subStruct->downArrowYPosIdx],
                8,
                16,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);
            CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);

            subStruct->downArrowDelay = 8;
            subStruct->downArrowYPosIdx++;
        }
    }
}

void TextPrinterClearDownArrow(struct TextPrinter *textPrinter)
{
    FillWindowPixelRect(
        textPrinter->printerTemplate.windowId,
        textPrinter->printerTemplate.bgColor << 4 | textPrinter->printerTemplate.bgColor,
        textPrinter->printerTemplate.currentX,
        textPrinter->printerTemplate.currentY,
        8,
        16);
    CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);
}

bool8 TextPrinterWaitAutoMode(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->autoScrollDelay == 49)
    {
        return TRUE;
    }
    else
    {
        subStruct->autoScrollDelay++;
        return FALSE;
    }
}

bool16 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter)
{
    bool8 result = FALSE;
    if (gTextFlags.autoScroll != 0)
    {
        result = TextPrinterWaitAutoMode(textPrinter);
    }
    else
    {
        TextPrinterDrawDownArrow(textPrinter);
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            result = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    return result;
}

bool16 TextPrinterWait(struct TextPrinter *textPrinter)
{
    bool16 result = FALSE;
    if (gTextFlags.autoScroll != 0)
    {
        result = TextPrinterWaitAutoMode(textPrinter);
    }
    else
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            result = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    return result;
}

void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool8 drawArrow, u8 *counter, u8 *yCoordIndex)
{
    const u8 *arrowTiles;

    if (*counter != 0)
    {
        --*counter;
    }
    else
    {
        FillWindowPixelRect(windowId, (bgColor << 4) | bgColor, x, y, 0x8, 0x10);
        if (drawArrow == 0)
        {
            switch (gTextFlags.useAlternateDownArrow)
            {
            case FALSE:
            default:
                arrowTiles = sDownArrowTiles;
                break;
            case TRUE:
                arrowTiles = sDarkDownArrowTiles;
                break;
            }

            BlitBitmapRectToWindow(windowId, arrowTiles, 0, sDownArrowYCoords[*yCoordIndex & 3], 8, 16, x, y - 2, 8, 16);
            CopyWindowToVram(windowId, COPYWIN_GFX);
            *counter = 8;
            ++*yCoordIndex;
        }
    }
}

static u16 RenderText(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);
    u16 currChar;
    s32 width;
    s32 widthHelper;

    switch (textPrinter->state)
    {
    case RENDER_STATE_HANDLE_CHAR:
        if (JOY_HELD(A_BUTTON | B_BUTTON) && subStruct->hasPrintBeenSpedUp)
            textPrinter->delayCounter = 0;

        if (textPrinter->delayCounter && textPrinter->textSpeed)
        {
            textPrinter->delayCounter--;
            if (gTextFlags.canABSpeedUpPrint && (JOY_NEW(A_BUTTON | B_BUTTON)))
            {
                subStruct->hasPrintBeenSpedUp = TRUE;
                textPrinter->delayCounter = 0;
            }
            return RENDER_UPDATE;
        }

        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED) && gTextFlags.autoScroll)
            textPrinter->delayCounter = 3;
        else
            textPrinter->delayCounter = textPrinter->textSpeed;

        currChar = *textPrinter->printerTemplate.currentChar;
        textPrinter->printerTemplate.currentChar++;

        switch (currChar)
        {
        case CHAR_NEWLINE:
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY += (gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing);
            return RENDER_REPEAT;
        case PLACEHOLDER_BEGIN:
            textPrinter->printerTemplate.currentChar++;
            return RENDER_REPEAT;
        case EXT_CTRL_CODE_BEGIN:
            currChar = *textPrinter->printerTemplate.currentChar;
            textPrinter->printerTemplate.currentChar++;
            switch (currChar)
            {
            case EXT_CTRL_CODE_COLOR:
                textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_HIGHLIGHT:
                textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHADOW:
                textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PALETTE:
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_FONT:
                subStruct->fontId = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_RESET_FONT:
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE:
                textPrinter->delayCounter = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->state = RENDER_STATE_PAUSE;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
                textPrinter->state = RENDER_STATE_WAIT;
                if (gTextFlags.autoScroll)
                    subStruct->autoScrollDelay = 0;
                return RENDER_UPDATE;
            case EXT_CTRL_CODE_WAIT_SE:
                textPrinter->state = RENDER_STATE_WAIT_SE;
                return RENDER_UPDATE;
            case EXT_CTRL_CODE_PLAY_BGM:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= *textPrinter->printerTemplate.currentChar << 8;
                textPrinter->printerTemplate.currentChar++;
                PlayBGM(currChar);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_ESCAPE:
                currChar = *textPrinter->printerTemplate.currentChar | 0x100;
                textPrinter->printerTemplate.currentChar++;
                break;
            case EXT_CTRL_CODE_PLAY_SE:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= (*textPrinter->printerTemplate.currentChar << 8);
                textPrinter->printerTemplate.currentChar++;
                PlaySE(currChar);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHIFT_RIGHT:
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHIFT_DOWN:
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_FILL_WINDOW:
                FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE_MUSIC:
                m4aMPlayStop(&gMPlayInfo_BGM);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_RESUME_MUSIC:
                m4aMPlayContinue(&gMPlayInfo_BGM);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_JPN:
            case EXT_CTRL_CODE_ENG:
                return RENDER_REPEAT;
            }
            break;
        case CHAR_PROMPT_CLEAR:
            textPrinter->state = RENDER_STATE_CLEAR;
            TextPrinterInitDownArrowCounters(textPrinter);
            return RENDER_UPDATE;
        case CHAR_PROMPT_SCROLL:
            textPrinter->state = RENDER_STATE_SCROLL_START;
            TextPrinterInitDownArrowCounters(textPrinter);
            return RENDER_UPDATE;
        case CHAR_EXTRA_SYMBOL:
            currChar = *textPrinter->printerTemplate.currentChar | 0x100;
            textPrinter->printerTemplate.currentChar++;
            break;
        case CHAR_KEYPAD_ICON:
            currChar = *textPrinter->printerTemplate.currentChar++;
            gCurGlyph.width = DrawKeypadIcon(textPrinter->printerTemplate.windowId, currChar, textPrinter->printerTemplate.currentX, textPrinter->printerTemplate.currentY);
            textPrinter->printerTemplate.currentX += gCurGlyph.width + textPrinter->printerTemplate.letterSpacing;
            return RENDER_PRINT;
        case EOS:
            return RENDER_FINISH;
        }

        switch (subStruct->fontId)
        {
        case 0:
            DecompressGlyphFont9(currChar);
            break;
        case 1:
            sub_08006304(currChar);
            break;
        case 2:
            sub_08006354(currChar);
            break;
        case 3:
            sub_08006418(currChar);
            break;
        case 4:
            sub_080064B8(currChar);
            break;
        case 5:
            sub_0800657C(currChar);
            break;
        }

        CopyGlyphToWindow(textPrinter);
        textPrinter->printerTemplate.currentX += gCurGlyph.width + textPrinter->printerTemplate.letterSpacing;
        return RENDER_PRINT;
    case RENDER_STATE_WAIT:
        if (TextPrinterWait(textPrinter))
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    case RENDER_STATE_CLEAR:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_SCROLL_START:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            TextPrinterClearDownArrow(textPrinter);
            textPrinter->scrollDistance = gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing;
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->state = RENDER_STATE_SCROLL;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_SCROLL:
        if (textPrinter->scrollDistance)
        {
            int scrollSpeed = GetPlayerTextSpeed();
            int speed = sWindowVerticalScrollSpeeds[scrollSpeed];
            if (textPrinter->scrollDistance < speed)
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, textPrinter->scrollDistance, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->scrollDistance = 0;
            }
            else
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, speed, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->scrollDistance -= speed;
            }
            CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);
        }
        else
        {
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_WAIT_SE:
        if (!IsSEPlaying())
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    case RENDER_STATE_PAUSE:
        if (textPrinter->delayCounter != 0)
            textPrinter->delayCounter--;
        else
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    }

    return RENDER_FINISH;
}

static u32 UNUSED GetStringWidthFixedWidthFont(const u8 *str, u8 fontId, u8 letterSpacing)
{
    int i;
    u8 width;
    int temp;
    int temp2;
    u8 line;
    int strPos;
    u8 lineWidths[8];
    const u8 *strLocal;

    for (i = 0; i < (int)ARRAY_COUNT(lineWidths); i++)
        lineWidths[i] = 0;

    width = 0;
    line = 0;
    strLocal = str;
    strPos = 0;

    do
    {
        temp = strLocal[strPos++];
        switch (temp)
        {
        case CHAR_NEWLINE:
        case EOS:
            lineWidths[line] = width;
            width = 0;
            line++;
            break;
        case EXT_CTRL_CODE_BEGIN:
            temp2 = strLocal[strPos++];
            switch (temp2)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                ++strPos;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++strPos;
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_FONT:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                ++strPos;
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            case EXT_CTRL_CODE_JPN:
            case EXT_CTRL_CODE_ENG:
            default:
                break;
            }
            break;
        case CHAR_DYNAMIC:
        case PLACEHOLDER_BEGIN:
            ++strPos;
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
            break;
        case CHAR_KEYPAD_ICON:
        case CHAR_EXTRA_SYMBOL:
            ++strPos;
        default:
            ++width;
            break;
        }
    } while (temp != EOS);

    for (width = 0, strPos = 0; strPos < 8; ++strPos)
    {
        if (width < lineWidths[strPos])
            width = lineWidths[strPos];
    }

    return (u8)(GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH) + letterSpacing) * width;
}

static u32 (*GetFontWidthFunc(u8 fontId))(u16, bool32)
{
    u32 i;

    for (i = 0; i < 6; ++i)
    {
        if (fontId == sGlyphWidthFuncs[i].fontId)
            return sGlyphWidthFuncs[i].func;
    }

    return NULL;
}


s32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)
{
    u32 (*func)(u16);
    int localLetterSpacing;
    u32 lineWidth;
    const u8 *bufferPointer;
    s32 width;

    func = GetFontWidthFunc(fontId);
    if (func == NULL)
        return 0;

    if (letterSpacing == -1)
        localLetterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    else
        localLetterSpacing = letterSpacing;

    width = 0;
    lineWidth = 0;
    bufferPointer = 0;

    while (*str != EOS)
    {
        switch (*str)
        {
        case CHAR_NEWLINE:
            if (lineWidth <= width)
                break;
            width = lineWidth;
            lineWidth = 0;
            break;
        case PLACEHOLDER_BEGIN:
            switch (*++str)
            {
            case PLACEHOLDER_ID_STRING_VAR_1:
                bufferPointer = gStringVar1;
                break;
            case PLACEHOLDER_ID_STRING_VAR_2:
                bufferPointer = gStringVar2;
                break;
            case PLACEHOLDER_ID_STRING_VAR_3:
                bufferPointer = gStringVar3;
                break;
            default:
                return 0;
            }
        case CHAR_DYNAMIC:
            if (bufferPointer == NULL)
                bufferPointer = DynamicPlaceholderTextUtil_GetPlaceholderPtr(*++str);
            while (*bufferPointer != EOS)
            {
                lineWidth += func(*bufferPointer) + localLetterSpacing;
                bufferPointer++;
            }
            bufferPointer = 0;
            break;
        case EXT_CTRL_CODE_BEGIN:
            switch (*++str)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                ++str;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++str;
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
                ++str;
                break;
            case EXT_CTRL_CODE_FONT:
                func = GetFontWidthFunc(*++str);
                if (func == NULL)
                    return 0;
                if (letterSpacing == -1)
                    localLetterSpacing = GetFontAttribute(*str, FONTATTR_LETTER_SPACING);
                break;
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
                ++str;
                break;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                ++str;
                break;
            case EXT_CTRL_CODE_JPN:
            case EXT_CTRL_CODE_ENG:
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            default:
                break;
            }
            break;
        case CHAR_KEYPAD_ICON:
        case CHAR_EXTRA_SYMBOL:
            lineWidth += func(*++str | 0x100) + localLetterSpacing;
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
            break;
        default:
            lineWidth += func(*str) + localLetterSpacing;
            break;
        }
        ++str;
    }

    if (lineWidth > width)
        return lineWidth;
    return width;
}
u8 RenderTextFont9(u8 *pixels, u8 fontId, u8 *str)
{
    u8 shadowColor;
    u8 *strLocal;
    int strPos;
    int temp;
    int temp2;
    u8 colorBackup[3];
    u32 fgColor;
    u32 bgColor;

    SaveTextColors(&colorBackup[0], &colorBackup[1], &colorBackup[2]);

    fgColor = 1;
    bgColor = 0;
    shadowColor = 3;

    GenerateFontHalfRowLookupTable(1, 0, 3);
    strLocal = str;
    strPos = 0;

    do
    {
        temp = strLocal[strPos++];
        switch (temp)
        {
        case EXT_CTRL_CODE_BEGIN:
            temp2 = strLocal[strPos++];
            switch (temp2)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                fgColor = strLocal[strPos++];
                bgColor = strLocal[strPos++];
                shadowColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_COLOR:
                fgColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_HIGHLIGHT:
                bgColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_SHADOW:
                shadowColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_FONT:
                fontId = strLocal[strPos++];
                break;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++strPos;
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                ++strPos;
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            case EXT_CTRL_CODE_JPN:
            case EXT_CTRL_CODE_ENG:
            default:
                continue;
            }
            break;
        case CHAR_DYNAMIC:
        case CHAR_KEYPAD_ICON:
        case CHAR_EXTRA_SYMBOL:
        case PLACEHOLDER_BEGIN:
            ++strPos;
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
        case CHAR_NEWLINE:
        case EOS:
            break;
        default:
            {
                u8 f = fontId;
                if (f == 1)
                    goto decompressSmall;
                if (f != 7)
                    goto decompressSmall;
                sub_08006640(temp);
                goto decompressed;
decompressSmall:
                sub_08006304(temp);
decompressed:
                CpuCopy32(gCurGlyph.gfxBufferTop, pixels, 0x20);
                CpuCopy32(gCurGlyph.gfxBufferBottom, pixels + 0x20, 0x20);
                pixels += 0x40;
                break;
            }
        }
    }
    while (temp != EOS);

    RestoreTextColors(&colorBackup[0], &colorBackup[1], &colorBackup[2]);
    return 1;
}

u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(
        windowId,
        sKeypadIconTiles + (sKeypadIcons[keypadIconId].tileOffset * 0x20),
        0,
        0,
        0x80,
        0x80,
        x,
        y,
        sKeypadIcons[keypadIconId].width,
        sKeypadIcons[keypadIconId].height);
    return sKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconTileOffset(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].tileOffset;
}

u8 GetKeypadIconWidth(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconHeight(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].height;
}

void SetDefaultFontsPointer(void)
{
    SetFontsPointer(sFontInfos);
}

u8 GetFontAttribute(u8 fontId, u8 attributeId)
{
    int result = 0;
    switch (attributeId)
    {
        case FONTATTR_MAX_LETTER_WIDTH:
            result = sFontInfos[fontId].maxLetterWidth;
            break;
        case FONTATTR_MAX_LETTER_HEIGHT:
            result = sFontInfos[fontId].maxLetterHeight;
            break;
        case FONTATTR_LETTER_SPACING:
            result = sFontInfos[fontId].letterSpacing;
            break;
        case FONTATTR_LINE_SPACING:
            result = sFontInfos[fontId].lineSpacing;
            break;
        case FONTATTR_UNKNOWN:
            result = sFontInfos[fontId].unk;
            break;
        case FONTATTR_COLOR_FOREGROUND:
            result = sFontInfos[fontId].fgColor;
            break;
        case FONTATTR_COLOR_BACKGROUND:
            result = sFontInfos[fontId].bgColor;
            break;
        case FONTATTR_COLOR_SHADOW:
            result = sFontInfos[fontId].shadowColor;
            break;
    }
    return result;
}

u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension)
{
    return sMenuCursorDimensions[fontId][whichDimension];
}

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
