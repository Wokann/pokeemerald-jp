#include "global.h"
#include "battle.h"

// JP alias of US gAIScriptPtr.
extern const u8 *gUnknown_203A804;

// This ROM-resident helper is the separate-owner form of US AIStackPop.
bool8 BattleAIStackPop(void)
{
    if (gBattleResources->AI_ScriptsStack->size != 0)
    {
        gBattleResources->AI_ScriptsStack->size--;
        gUnknown_203A804 = gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size];
        return TRUE;
    }

    return FALSE;
}
