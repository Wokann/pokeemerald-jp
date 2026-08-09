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

extern void FieldInitRegionMap(void (*callback)(void));
extern void CB2_ReturnToFieldContinueScriptPlayMapMusic(void);
extern void SetMainCallback2(void (*callback)(void));

static void CB2_FieldShowRegionMap(void)
{
    FieldInitRegionMap(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void FieldShowRegionMap(void)
{
    SetMainCallback2(CB2_FieldShowRegionMap);
}
