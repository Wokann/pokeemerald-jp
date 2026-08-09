#include "global.h"
#include "random.h"

// EWRAM @ 0x02024660 / 0x02024664, IWRAM @ 0x03005AE0 / 0x03005AE4
extern u8 sUnknown;
extern u32 sRandCount;
extern u32 gRngValue;
extern u32 gRng2Value;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
    sUnknown = 0;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

u16 Random2(void)
{
    gRng2Value = ISO_RANDOMIZE1(gRng2Value);
    return gRng2Value >> 16;
}
