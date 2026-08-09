#include "global.h"

extern u8 sTrainerBattleMode;

u8 GetTrainerBattleMode(void)
{
    return sTrainerBattleMode;
}

extern void DoBattlePikeWildBattle(void);

void BattleSetup_StartBattlePikeWildBattle(void)
{
    DoBattlePikeWildBattle();
}
