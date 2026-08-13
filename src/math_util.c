#include "global.h"

// JP ground tilemap state used by the cable-car system.
struct GroundTilemapData
{
    u8 filler_0[0x18];
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
    u8 field_1C;
};

extern struct GroundTilemapData *gGroundTilemapData;
void BufferNextGroundSegment(void);
void DrawNextGroundSegmentGoingUp(void);
void DrawNextGroundSegmentGoingDown(void);

void InitGroundTilemapData(u8 mode)
{
    if (mode == 0)
        goto mode0;
    if (mode == 1)
        goto mode1;
mode0:
    gGroundTilemapData->field_1B = 2;
    gGroundTilemapData->field_19 = 0;
    gGroundTilemapData->field_1A = 0x14;
    gGroundTilemapData->field_18 = 0xC;
    BufferNextGroundSegment();
    DrawNextGroundSegmentGoingUp();
    goto done;
mode1:
    gGroundTilemapData->field_1B = 2;
    gGroundTilemapData->field_19 = 0x1C;
    gGroundTilemapData->field_1A = 0x14;
    gGroundTilemapData->field_18 = 4;
    BufferNextGroundSegment();
    DrawNextGroundSegmentGoingDown();
done:
    gGroundTilemapData->field_1C = 0;
}

s16 MathUtil_Mul16(s16 x, s16 y)
{
    s32 result;

    result = x;
    result *= y;
    result /= 256;
    return result;
}

s16 MathUtil_Mul16Shift(u8 s, s16 x, s16 y)
{
    s32 result;

    result = x;
    result *= y;
    result /= (1 << s);
    return result;
}

s32 MathUtil_Mul32(s32 x, s32 y)
{
    s64 result;

    result = x;
    result *= y;
    result /= 256;
    return result;
}

s16 MathUtil_Div16(s16 x, s16 y)
{
    if (y == 0)
    {
        return 0;
    }
    return (x << 8) / y;
}

s16 MathUtil_Div16Shift(u8 s, s16 x, s16 y)
{
    if (y == 0)
    {
        return 0;
    }
    return (x << s) / y;
}

s32 MathUtil_Div32(s32 x, s32 y)
{
    s64 _x;

    if (y == 0)
    {
        return 0;
    }
    _x = x;
    _x *= 256;
    return _x / y;
}

s16 MathUtil_Inv16(s16 y)
{
    s32 x;

    x = 0x10000;
    return x / y;
}

s16 MathUtil_Inv16Shift(u8 s, s16 y)
{
    s32 x;

    x = 0x100 << s;
    return x / y;
}
