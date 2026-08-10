#include "global.h"
#include "blit.h"

void BlitBitmapRect4BitWithoutColorKey(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height)
{
    BlitBitmapRect4Bit(src, dst, srcX, srcY, dstX, dstY, width, height, 0xFF);
}

void BlitBitmapRect4Bit(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height, u8 colorKey)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierSrcY;
    s32 multiplierDstY;
    s32 loopSrcY, loopDstY;
    s32 loopSrcX, loopDstX;
    const u8 *pixelsSrc;
    u8 *pixelsDst;
    s32 toOrr;
    s32 toAnd;
    s32 toShift;

    if (dst->width - dstX < width)
        xEnd = (dst->width - dstX) + srcX;
    else
        xEnd = srcX + width;

    if (dst->height - dstY < height)
        yEnd = (dst->height - dstY) + srcY;
    else
        yEnd = height + srcY;

    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;

    if (colorKey == 0xFF)
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1B);
                pixelsDst = dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + (((loopDstY >> 3) * multiplierDstY) << 5) + ((u32)(loopDstY << 0x1d) >> 0x1B);
                toOrr = ((*pixelsSrc >> ((loopSrcX & 1) << 2)) & 0xF);
                toShift = ((loopDstX & 1) << 2);
                toOrr <<= toShift;
                toAnd = 0xF0 >> (toShift);
                *pixelsDst = toOrr | (*pixelsDst & toAnd);
            }
        }
    }
    else
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1B);
                pixelsDst = dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + (((loopDstY >> 3) * multiplierDstY) << 5) + ((u32)(loopDstY << 0x1d) >> 0x1B);
                toOrr = ((*pixelsSrc >> ((loopSrcX & 1) << 2)) & 0xF);
                if (toOrr != colorKey)
                {
                    toShift = ((loopDstX & 1) << 2);
                    toOrr <<= toShift;
                    toAnd = 0xF0 >> (toShift);
                    *pixelsDst = toOrr | (*pixelsDst & toAnd);
                }
            }
        }
    }
}

// Kept as naked asm: agbcc cannot reproduce the JP compiler's register
// allocation for this fill loop (x/sl, y/r5, fillValue/r7), which the
// other blit functions match.
__attribute__((naked)) void FillBitmapRect4Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #4\n\t"
            "mov sb, r0\n\t"
            "ldr r0, [sp, #0x24]\n\t"
            "ldr r4, [sp, #0x28]\n\t"
            "lsls r1, r1, #0x10\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "mov sl, r1\n\t"
            "lsls r2, r2, #0x10\n\t"
            "lsrs r2, r2, #0x10\n\t"
            "adds r5, r2, #0\n\t"
            "lsls r3, r3, #0x10\n\t"
            "lsrs r3, r3, #0x10\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0x10\n\t"
            "lsls r4, r4, #0x18\n\t"
            "lsrs r7, r4, #0x18\n\t"
            "adds r4, r1, r3\n\t"
            "mov r3, sb\n\t"
            "ldrh r1, [r3, #4]\n\t"
            "cmp r4, r1\n\t"
            "ble _08002D12\n\t"
            "adds r4, r1, #0\n\t"
            "_08002D12:\n\t"
            "adds r2, r2, r0\n\t"
            "mov ip, r2\n\t"
            "mov r2, sb\n\t"
            "ldrh r0, [r2, #6]\n\t"
            "cmp ip, r0\n\t"
            "ble _08002D20\n\t"
            "mov ip, r0\n\t"
            "_08002D20:\n\t"
            "movs r0, #7\n\t"
            "ands r0, r1\n\t"
            "adds r0, r1, r0\n\t"
            "asrs r0, r0, #3\n\t"
            "str r0, [sp]\n\t"
            "adds r1, r5, #0\n\t"
            "cmp r1, ip\n\t"
            "bge _08002D88\n\t"
            "_08002D30:\n\t"
            "mov r3, sl\n\t"
            "adds r0, r1, #1\n\t"
            "mov r8, r0\n\t"
            "cmp r3, r4\n\t"
            "bge _08002D82\n\t"
            "asrs r0, r1, #3\n\t"
            "ldr r2, [sp]\n\t"
            "muls r0, r2, r0\n\t"
            "lsls r6, r0, #5\n\t"
            "lsls r0, r1, #0x1d\n\t"
            "lsrs r5, r0, #0x1b\n\t"
            "_08002D46:\n\t"
            "asrs r2, r3, #1\n\t"
            "movs r0, #3\n\t"
            "ands r2, r0\n\t"
            "mov r0, sb\n\t"
            "ldr r1, [r0]\n\t"
            "adds r1, r1, r2\n\t"
            "asrs r0, r3, #3\n\t"
            "lsls r0, r0, #5\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, r1, r6\n\t"
            "adds r2, r1, r5\n\t"
            "movs r0, #1\n\t"
            "ands r0, r3\n\t"
            "cmp r0, #0\n\t"
            "beq _08002D72\n\t"
            "ldrb r0, [r2]\n\t"
            "movs r1, #0xf\n\t"
            "ands r1, r0\n\t"
            "lsls r0, r7, #4\n\t"
            "orrs r1, r0\n\t"
            "strb r1, [r2]\n\t"
            "b _08002D7C\n\t"
            "_08002D72:\n\t"
            "ldrb r1, [r2]\n\t"
            "movs r0, #0xf0\n\t"
            "ands r0, r1\n\t"
            "orrs r0, r7\n\t"
            "strb r0, [r2]\n\t"
            "_08002D7C:\n\t"
            "adds r3, #1\n\t"
            "cmp r3, r4\n\t"
            "blt _08002D46\n\t"
            "_08002D82:\n\t"
            "mov r1, r8\n\t"
            "cmp r1, ip\n\t"
            "blt _08002D30\n\t"
            "_08002D88:\n\t"
            "add sp, #4\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".syntax divided");
}

void BlitBitmapRect4BitTo8Bit(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height, u8 colorKey, u8 paletteOffset)
{
    s32 palOffsetBits;
    s32 xEnd;
    s32 yEnd;
    s32 multiplierSrcY;
    s32 multiplierDstY;
    s32 loopSrcY, loopDstY;
    s32 loopSrcX, loopDstX;
    const u8 *pixelsSrc;
    u8 *pixelsDst;
    s32 colorKeyBits;

    palOffsetBits = (u32)(paletteOffset << 0x1C) >> 0x18;
    colorKeyBits = (u32)(colorKey << 0x1C) >> 0x18;

    if (dst->width - dstX < width)
        xEnd = (dst->width - dstX) + srcX;
    else
        xEnd = width + srcX;

    if (dst->height - dstY < height)
        yEnd = (srcY + dst->height) - dstY;
    else
        yEnd = srcY + height;

    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;

    if (colorKey == 0xFF)
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            pixelsSrc = src->pixels + ((srcX >> 1) & 3) + ((srcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1b);
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsDst = dst->pixels + (loopDstX & 7) + ((loopDstX >> 3) << 6) + (((loopDstY >> 3) * multiplierDstY) << 6) + ((u32)(loopDstY << 0x1d) >> 0x1a);
                if (loopSrcX & 1)
                {
                    *pixelsDst = palOffsetBits + (*pixelsSrc >> 4);
                }
                else
                {
                    pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1b);
                    *pixelsDst = palOffsetBits + (*pixelsSrc & 0xF);
                }
            }
        }
    }
    else
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            pixelsSrc = src->pixels + ((srcX >> 1) & 3) + ((srcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1b);
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                if (loopSrcX & 1)
                {
                    if ((*pixelsSrc & 0xF0) != colorKeyBits)
                    {
                        pixelsDst = dst->pixels + (loopDstX & 7) + ((loopDstX >> 3) << 6) + (((loopDstY >> 3) * multiplierDstY) << 6) + ((u32)(loopDstY << 0x1d) >> 0x1a);
                        *pixelsDst = palOffsetBits + (*pixelsSrc >> 4);
                    }
                }
                else
                {
                    pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1b);
                    if ((*pixelsSrc & 0xF) != colorKey)
                    {
                        pixelsDst = dst->pixels + (loopDstX & 7) + ((loopDstX >> 3) << 6) + (((loopDstY >> 3) * multiplierDstY) << 6) + ((u32)(loopDstY << 0x1d) >> 0x1a);
                        *pixelsDst = palOffsetBits + (*pixelsSrc & 0xF);
                    }
                }
            }
        }
    }
}

void FillBitmapRect8Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierY;
    s32 loopX, loopY;

    xEnd = x + width;
    if (xEnd > surface->width)
        xEnd = surface->width;

    yEnd = y + height;
    if (yEnd > surface->height)
        yEnd = surface->height;

    multiplierY = (surface->width + (surface->width & 7)) >> 3;

    for (loopY = y; loopY < yEnd; loopY++)
    {
        for (loopX = x; loopX < xEnd; loopX++)
        {
            u8 *pixels = surface->pixels + (loopX & 7) + ((loopX >> 3) << 6) + (((loopY >> 3) * multiplierY) << 6) + ((u32)(loopY << 0x1d) >> 0x1a);
            *pixels = fillValue;
        }
    }
}
