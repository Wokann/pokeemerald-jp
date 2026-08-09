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

extern void Overworld_ClearSavedMusic(void);
extern void SetMainCallback2(void (*callback)(void));
extern void CB2_ReturnToFieldContinueScriptPlayMapMusic(void);

static void CB2_EndFirstBattle(void)
{
    Overworld_ClearSavedMusic();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}
