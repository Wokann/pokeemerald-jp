#include "global.h"

extern u8 gBattleOutcome;

u8 GetBattleOutcome(void)
{
    return gBattleOutcome;
}

extern void PCTurnOffEffect(void);

void DoPCTurnOffEffect(void)
{
    PCTurnOffEffect();
}
