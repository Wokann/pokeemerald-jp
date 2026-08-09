#include "global.h"
#include "trig.h"

extern const s16 gSineTable[128];        // ROM @ 0x082FA8CC
extern const s16 gSineDegreeTable[180];  // ROM @ 0x082FAB4C

// amplitude * sin(index*(PI/128))
s16 Sin(s16 index, s16 amplitude)
{
    return (amplitude * gSineTable[index]) >> 8;
}

// amplitude * cos(index*(PI/128))
s16 Cos(s16 index, s16 amplitude)
{
    return (amplitude * gSineTable[index + 64]) >> 8;
}

// angle in degrees
s16 Sin2(u16 angle)
{
    s32 angleMod = angle % 180;
    s32 negate = ((angle / 180) & 1);
    s16 value = gSineDegreeTable[angleMod];

    if (negate)
        return -value;
    else
        return value;
}

// angle in degrees
s16 Cos2(u16 angle)
{
    return Sin2(angle + 90);
}
