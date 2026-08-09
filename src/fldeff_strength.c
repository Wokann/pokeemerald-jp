#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "fldeff.h"
#include "party_menu.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"

static void FieldCallback_Strength(void);
static void StartStrengthFieldEffect(void);

extern void FieldCallback_PrepareFadeInFromMenu(void);
extern u16 gSpecialVar_Result;  // EWRAM @ 0x02037290
// JP names for the pokeemerald equivalents (CreateFieldMoveTask,
// ScriptContext_SetupScript, ScriptContext_Enable).
extern u8 CreateFieldMoveTask(void);
extern void ScriptContext_SetupScript(const u8 *script);
extern void ScriptContext_Enable(void);

bool8 SetUpFieldMove_Strength(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER) == TRUE)
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Strength;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_Strength(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseStrength);
}

bool8 FldEff_UseStrength(void)
{
    u8 taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartStrengthFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartStrengthFieldEffect;
    GetMonNickname(&gPlayerParty[gFieldEffectArguments[0]], gStringVar1);
    return FALSE;
}

static void StartStrengthFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_STRENGTH);
    ScriptContext_Enable();
}
