#include "global.h"
#include "battle_tower.h"
#include "constants/trainers.h"

extern void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId);

static void ClearBattleTowerRecord(struct EmeraldBattleTowerRecord *record)
{
    u32 i;

    for (i = 0; i < sizeof(struct EmeraldBattleTowerRecord) / 4; i++)
        ((u32 *)record)[i] = 0;
}

void SetEReaderTrainerGfxId(void)
{
    SetBattleFacilityTrainerGfxId(TRAINER_EREADER, 0);
}
