#include "global.h"

extern u8 sWildEncountersDisabled;

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}
