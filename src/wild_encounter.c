#include "global.h"

extern u8 sWildEncountersDisabled;

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

extern u32 sFeebasRngValue;

static void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = (u16)seed;
}
