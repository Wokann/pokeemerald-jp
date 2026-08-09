#include "global.h"
#include "battle_tower.h"

static void ClearBattleTowerRecord(struct EmeraldBattleTowerRecord *record)
{
    u32 i;

    for (i = 0; i < sizeof(struct EmeraldBattleTowerRecord) / 4; i++)
        ((u32 *)record)[i] = 0;
}
