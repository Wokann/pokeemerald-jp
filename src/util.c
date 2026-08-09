#include "global.h"
#include "constants/rgb.h"
#include "palette.h"
#include "sprite.h"
#include "util.h"

extern const struct SpriteTemplate sInvisibleSpriteTemplate;  // ROM @ 0x082FAD34
extern const u8 sSpriteDimensions[3][4][2];  // ROM @ 0x082FAD4C
extern const u16 sCrc16Table[256];          // ROM @ 0x082FAD64

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *))
{
    u8 sprite = CreateSprite(&sInvisibleSpriteTemplate, DISPLAY_WIDTH + 8, DISPLAY_HEIGHT + 8, 14);
    gSprites[sprite].invisible = TRUE;
    gSprites[sprite].callback = callback;
    return sprite;
}

void StoreWordInTwoHalfwords(u16 *h, u32 w)
{
    h[0] = (u16)(w);
    h[1] = (u16)(w >> 16);
}

void LoadWordFromTwoHalfwords(u16 *h, u32 *w)
{
    *w = h[0] | (s16)h[1] << 16;
}

void SetBgAffineStruct(struct BgAffineSrcData *src, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha)
{
    src->texX = texX;
    src->texY = texY;
    src->scrX = scrX;
    src->scrY = scrY;
    src->sx = sx;
    src->sy = sy;
    src->alpha = alpha;
}

void DoBgAffineSet(struct BgAffineDstData *dest, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha)
{
    struct BgAffineSrcData src;

    SetBgAffineStruct(&src, texX, texY, scrX, scrY, sx, sy, alpha);
    BgAffineSet(&src, dest, 1);
}

void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output)
{
    u8 x, y;
    s8 i, j;
    u8 ALIGNED(4) xflip[32];
    u8 h = sSpriteDimensions[shape][size][1];
    u8 w = sSpriteDimensions[shape][size][0];

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            int tile = (*tilemap & 0x3ff) * 32;

            if ((*tilemap & 0xc00) == 0)
            {
                CpuCopy32(tiles + tile, output, 32);
            }
            else if ((*tilemap & 0xc00) == 0x800)
            {
                for (i = 0; i < 8; i++)
                    CpuCopy32(tiles + (tile + (7 - i) * 4), output + i * 4, 4);
            }
            else
            {
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        u8 i2 = i * 4;
                        xflip[i2 + (3 - j)] = (tiles[tile + i2 + j] & 0xf) << 4;
                        xflip[i2 + (3 - j)] |= tiles[tile + i2 + j] >> 4;
                    }
                }
                if (*tilemap & 0x800)
                {
                    for (i = 0; i < 8; i++)
                        CpuCopy32(xflip + (7 - i) * 4, output + i * 4, 4);
                }
                else
                {
                    CpuCopy32(xflip, output, 32);
                }
            }
            tilemap++;
            output += 32;
        }
        tilemap += (32 - w);
    }
}

int CountTrailingZeroBits(u32 value)
{
    u8 i;

    for (i = 0; i < 32; i++)
    {
        if ((value & 1) == 0)
            value >>= 1;
        else
            return i;
    }
    return 0;
}

u16 CalcCRC16(const u8 *data, s32 length)
{
    u16 i, j;
    u16 crc = 0x1121;

    for (i = 0; i < length; i++)
    {
        crc ^= data[i];
        for (j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc >>= 1;
        }
    }
    return ~crc;
}

u16 CalcCRC16WithTable(const u8 *data, u32 length)
{
    u16 i;
    u16 crc = 0x1121;
    u8 byte;

    for (i = 0; i < length; i++)
    {
        byte = crc >> 8;
        crc ^= data[i];
        crc = byte ^ sCrc16Table[(u8)crc];
    }
    return ~crc;
}

u32 CalcByteArraySum(const u8 *data, u32 length)
{
    u32 sum, i;
    for (sum = 0, i = 0; i < length; i++)
        sum += data[i];
    return sum;
}

void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor)
{
    u16 i;
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
        s8 r = data1->r;
        s8 g = data1->g;
        s8 b = data1->b;
        struct PlttData *data2 = (struct PlttData *)&blendColor;
        gPlttBufferFaded[index] = RGB(r + (((data2->r - r) * coeff) >> 4),
                                      g + (((data2->g - g) * coeff) >> 4),
                                      b + (((data2->b - b) * coeff) >> 4));
    }
}
