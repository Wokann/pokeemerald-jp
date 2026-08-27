#include "global.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "constants/field_effects.h"
#include "constants/metatile_behaviors.h"
#include "event_data.h"
#include "fieldmap.h"
#include "event_object_movement.h"
#include "script.h"
#include "field_player_avatar.h"
#include "field_effect.h"
#include "fldeff.h"
#include "palette.h"
#include "party_menu.h"
#include "secret_base.h"
#include "constants/vars.h"
#include "string_util.h"
#include "task.h"
extern void StartSecretBaseCaveFieldEffect(void);
extern void StartSecretBaseShrubFieldEffect(void);
extern void StartSecretBaseTreeFieldEffect(void);

#define tMetatileID data[0]
#define tX data[0]
#define tY data[1]
#define tState data[2]
extern void Task_SecretBasePCTurnOn(u8 taskId);
extern void Task_PopSecretBaseBalloon(u8 taskId);
extern void Task_SecretBaseMusicNoteMatSound(u8 taskId);
extern void Task_FieldPoisonEffect(u8 taskId);
static void Task_ComputerScreenCloseEffect(u8 taskId);
static void Task_ComputerScreenOpenEffect(u8 taskId);

#undef tState
#define tState         data[0]
#define tHorzIncrement data[1]
#define tVertIncrement data[2]
#define tWinLeft       data[3]
#define tWinRight      data[4]
#define tWinTop        data[5]
#define tWinBottom     data[6]
#define tBlendCnt      data[7]
#define tBlendY        data[8]

static void CreateComputerScreenEffectTask(TaskFunc func, u16 increment, u16 unused, u8 priority);
extern void Task_WateringBerryTreeAnim_0(u8 taskId);
extern void Task_WateringBerryTreeAnim_1(u8 taskId);
extern void Task_WateringBerryTreeAnim_2(u8 taskId);
extern void Task_WateringBerryTreeAnim_3(u8 taskId);
extern u8 sub_0808B634(void);
extern void sub_0808BB8C(u8 direction);
extern u8 sub_08092F08(u32 direction);
extern const u8 gUnknown_85CA70B[];
extern void CaveEntranceSpriteCallback1(struct Sprite *sprite);
extern void CaveEntranceSpriteCallback2(struct Sprite *sprite);
extern void CaveEntranceSpriteCallbackEnd(struct Sprite *sprite);
extern void ShrubEntranceSpriteCallback1(struct Sprite *sprite);
extern void ShrubEntranceSpriteCallback2(struct Sprite *sprite);
extern void ShrubEntranceSpriteCallbackEnd(struct Sprite *sprite);
extern void TreeEntranceSpriteCallback1(struct Sprite *sprite);
extern void TreeEntranceSpriteCallback2(struct Sprite *sprite);
extern void TreeEntranceSpriteCallbackEnd(struct Sprite *sprite);
static void SpriteCB_SandPillar_BreakTop(struct Sprite *sprite);
static void SpriteCB_SandPillar_BreakBase(struct Sprite *sprite);
static void SpriteCB_SandPillar_End(struct Sprite *sprite);
extern void FieldCallback_SecretBaseCave(void);
extern void FieldCallback_SecretBaseTree(void);
extern void FieldCallback_SecretBaseShrub(void);
extern const u8 SecretBase_EventScript_CaveUseSecretPower[];
extern const u8 SecretBase_EventScript_TreeUseSecretPower[];
extern const u8 SecretBase_EventScript_ShrubUseSecretPower[];

#include "fldeff_misc.h"

void ComputerScreenOpenEffect(u16 increment, u16 unused, u8 priority)
{
    CreateComputerScreenEffectTask(Task_ComputerScreenOpenEffect, increment, unused, priority);
}

void ComputerScreenCloseEffect(u16 increment, u16 unused, u8 priority)
{
    CreateComputerScreenEffectTask(Task_ComputerScreenCloseEffect, increment, unused, priority);
}

bool8 IsComputerScreenOpenEffectActive(void)
{
    return FuncIsActiveTask(Task_ComputerScreenOpenEffect);
}

bool8 IsComputerScreenCloseEffectActive(void)
{
    return FuncIsActiveTask(Task_ComputerScreenCloseEffect);
}

static void CreateComputerScreenEffectTask(TaskFunc func, u16 increment, u16 unused, u8 priority)
{
    u8 taskId = CreateTask(func, priority);

    gTasks[taskId].tState = 0;
    gTasks[taskId].tHorzIncrement = increment == 0 ? 16 : increment;
    gTasks[taskId].tVertIncrement = increment == 0 ? 20 : increment;
    gTasks[taskId].func(taskId);
}

static void Task_ComputerScreenOpenEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tWinLeft = DISPLAY_WIDTH / 2;
        task->tWinRight = DISPLAY_WIDTH / 2;
        task->tWinTop = DISPLAY_HEIGHT / 2;
        task->tWinBottom = DISPLAY_HEIGHT / 2 + 1;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, (u16)WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, (u16)WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);

        break;
    case 1:
        task->tBlendCnt = GetGpuReg(REG_OFFSET_BLDCNT);
        task->tBlendY = GetGpuReg(REG_OFFSET_BLDY);

        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 16);

        break;
    case 2:
        task->tWinLeft -= task->tHorzIncrement;
        task->tWinRight += task->tHorzIncrement;

        if (task->tWinLeft < 1 || task->tWinRight > DISPLAY_WIDTH - 1)
        {
            task->tWinLeft = 0;
            task->tWinRight = DISPLAY_WIDTH;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, (u16)task->tBlendCnt);
            BlendPalettes(PALETTES_ALL, 0, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, (u16)WIN_RANGE(task->tWinLeft, task->tWinRight));

        if (task->tWinLeft != 0)
            return;
        break;
    case 3:
        task->tWinTop -= task->tVertIncrement;
        task->tWinBottom += task->tVertIncrement;

        if (task->tWinTop < 1 || task->tWinBottom > DISPLAY_HEIGHT - 1)
        {
            task->tWinTop = 0;
            task->tWinBottom = DISPLAY_HEIGHT;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, (u16)WIN_RANGE(task->tWinTop, task->tWinBottom));

        if (task->tWinTop != 0)
            return;
        break;
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, (u16)task->tBlendCnt);
        DestroyTask(taskId);
        return;
    }
    task->tState++;
}

static void Task_ComputerScreenCloseEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        gPlttBufferFaded[0] = 0;
        break;
    case 1:
        task->tWinLeft = 0;
        task->tWinRight = DISPLAY_WIDTH;
        task->tWinTop = 0;
        task->tWinBottom = DISPLAY_HEIGHT;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, (u16)WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, (u16)WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 2:
        task->tWinTop += task->tVertIncrement;
        task->tWinBottom -= task->tVertIncrement;

        if (task->tWinTop >= DISPLAY_HEIGHT / 2 || task->tWinBottom <= DISPLAY_HEIGHT / 2 + 1)
        {
            task->tWinTop = DISPLAY_HEIGHT / 2;
            task->tWinBottom = DISPLAY_HEIGHT / 2 + 1;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, 16);
        }
        SetGpuReg(REG_OFFSET_WIN0V, (u16)WIN_RANGE(task->tWinTop, task->tWinBottom));

        if (task->tWinTop != DISPLAY_HEIGHT / 2)
            return;
        break;
    case 3:
        task->tWinLeft += task->tHorzIncrement;
        task->tWinRight -= task->tHorzIncrement;

        if (task->tWinLeft >= DISPLAY_WIDTH / 2 || task->tWinRight <= DISPLAY_WIDTH / 2)
        {
            task->tWinLeft = DISPLAY_WIDTH / 2;
            task->tWinRight = DISPLAY_WIDTH / 2;
            BlendPalettes(PALETTES_ALL, 16, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, (u16)WIN_RANGE(task->tWinLeft, task->tWinRight));

        if (task->tWinLeft != DISPLAY_WIDTH / 2)
            return;
        break;
    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    task->tState++;
}

#undef tState
#undef tHorzIncrement
#undef tVertIncrement
#undef tWinLeft
#undef tWinRight
#undef tWinTop
#undef tWinBottom
#undef tBlendCnt
#undef tBlendY
#define tState data[2]

void SetCurrentSecretBase(void)
{
    SetCurSecretBaseIdFromPosition(&gPlayerFacingPosition, gMapHeader.events);
    TrySetCurSecretBaseIndex();
}


void AdjustSecretPowerSpritePixelOffsets(void)
{
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
    else
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
}


bool8 SetUpFieldMove_SecretPower(void)
{
    u8 mb;

    CheckPlayerHasSecretBase();

    if (gSpecialVar_Result == 1 || (u8)GetPlayerFacingDirection() != DIR_NORTH)
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y);

    if ((u8)MetatileBehavior_IsSecretBaseCave(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseCave;
        return TRUE;
    }

    if ((u8)MetatileBehavior_IsSecretBaseTree(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseShrub;
        return TRUE;
    }

    if ((u8)MetatileBehavior_IsSecretBaseShrub(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseTree;
        return TRUE;
    }

    return FALSE;
}


void FieldCallback_SecretBaseCave(void)
{
    gFieldEffectArguments[0] = (u8)GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_CaveUseSecretPower);
}


bool8 FldEff_UseSecretPowerCave(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartSecretBaseCaveFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseCaveFieldEffect;

    return FALSE;
}

void StartSecretBaseCaveFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_CAVE);
    FieldEffectStart(FLDEFF_SECRET_POWER_CAVE);
}

extern const u8 gUnknown_856955C[];
extern const u8 gUnknown_85695DC[];
extern const u8 gUnknown_856965C[];
extern const u8 gUnknown_85696DC[];
extern const u8 gUnknown_856975C[];
extern const u8 gUnknown_856981C[];
extern const u8 gUnknown_856989C[];
extern const u8 gUnknown_856991C[];
extern const u8 gUnknown_856999C[];
extern const u8 gUnknown_8569A1C[];
extern const u8 gUnknown_8569A9C[];
extern const u8 gUnknown_8569B1C[];
extern const u8 gUnknown_8569B9C[];
extern const u8 gUnknown_8569C1C[];
extern const u8 gUnknown_8569C9C[];

static const struct OamData sOam_SecretPower =
{
    .y = 0,
    .x = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const union AnimCmd sAnim_SecretPowerCave[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineDropLeft[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineRiseLeft[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineDropRight[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineRiseRight[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SecretPowerShrub[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SecretPowerCave[] =
{
    sAnim_SecretPowerCave,
};

static const union AnimCmd *const sAnimTable_SecretPowerTree[] =
{
    sAnim_VineDropLeft,
    sAnim_VineRiseLeft,
    sAnim_VineDropRight,
    sAnim_VineRiseRight,
};

static const union AnimCmd *const sAnimTable_SecretPowerShrub[] =
{
    sAnim_SecretPowerShrub,
};

static const struct SpriteFrameImage sPicTable_SecretPowerCave[] =
{
    { gUnknown_856955C, 128, 0 },
    { gUnknown_85695DC, 128, 0 },
    { gUnknown_856965C, 128, 0 },
    { gUnknown_85696DC, 128, 0 },
    { gUnknown_856975C, 128, 0 },
};

static const struct SpriteFrameImage sPicTable_SecretPowerTree[] =
{
    { gUnknown_8569A9C, 128, 0 },
    { gUnknown_8569B1C, 128, 0 },
    { gUnknown_8569B9C, 128, 0 },
    { gUnknown_8569C1C, 128, 0 },
    { gUnknown_8569C9C, 128, 0 },
};

static const struct SpriteFrameImage sPicTable_SecretPowerShrub[] =
{
    { gUnknown_856981C, 128, 0 },
    { gUnknown_856989C, 128, 0 },
    { gUnknown_856991C, 128, 0 },
    { gUnknown_856999C, 128, 0 },
    { gUnknown_8569A1C, 128, 0 },
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerCave =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_TREE,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerCave,
    .images = sPicTable_SecretPowerCave,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CaveEntranceSpriteCallback1,
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerTree =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_PLANT,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerTree,
    .images = sPicTable_SecretPowerTree,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TreeEntranceSpriteCallback1,
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerShrub =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_PLANT,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerShrub,
    .images = sPicTable_SecretPowerShrub,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ShrubEntranceSpriteCallback1,
};

bool8 FldEff_SecretPowerCave(void)
{
    AdjustSecretPowerSpritePixelOffsets();
    CreateSprite(&sSpriteTemplate_SecretPowerCave,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);
    return FALSE;
}

void CaveEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_M_ROCK_THROW);
    sprite->data[0] = 0;
    sprite->callback = ShrubEntranceSpriteCallback2;
}


void ShrubEntranceSpriteCallback2(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        if (++sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = CaveEntranceSpriteCallbackEnd;
    }
}


void CaveEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_CAVE);
    ScriptContext_Enable();
}


void FieldCallback_SecretBaseShrub(void)
{
    gFieldEffectArguments[0] = (u8)GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_TreeUseSecretPower);
}


bool8 FldEff_UseSecretPowerShrub(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartSecretBaseTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseTreeFieldEffect;

    return FALSE;
}

void StartSecretBaseTreeFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_TREE);
    FieldEffectStart(FLDEFF_SECRET_POWER_TREE);
}

bool8 FldEff_SecretPowerTree(void)
{
    s16 mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y) & 0xFFF;

    if (mb == MB_SECRET_BASE_SPOT_TREE_LEFT)
        gFieldEffectArguments[7] = 0;

    if (mb == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        gFieldEffectArguments[7] = 2;

    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&sSpriteTemplate_SecretPowerTree,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    if (gFieldEffectArguments[7] == 1 || gFieldEffectArguments[7] == 3)
        ToggleSecretBaseEntranceMetatile();

    return FALSE;
}

void TreeEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_M_SCRATCH);
    sprite->animNum = gFieldEffectArguments[7];
    sprite->data[0] = 0;
    sprite->callback = TreeEntranceSpriteCallback2;
}


void TreeEntranceSpriteCallback2(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] >= 40)
    {
        if (gFieldEffectArguments[7] == 0 || gFieldEffectArguments[7] == 2)
            ToggleSecretBaseEntranceMetatile();

        sprite->data[0] = 0;
        sprite->callback = TreeEntranceSpriteCallbackEnd;
    }
}


void TreeEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_TREE);
    ScriptContext_Enable();
}


void FieldCallback_SecretBaseTree(void)
{
    gFieldEffectArguments[0] = (u8)GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_ShrubUseSecretPower);
}


bool8 FldEff_UseSecretPowerTree(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartSecretBaseShrubFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseShrubFieldEffect;

    return FALSE;
}

void StartSecretBaseShrubFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_SHRUB);
    FieldEffectStart(FLDEFF_SECRET_POWER_SHRUB);
}

bool8 FldEff_SecretPowerShrub(void)
{
    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&sSpriteTemplate_SecretPowerShrub,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    return FALSE;
}

void ShrubEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_M_POISON_POWDER);
    sprite->data[0] = 0;
    sprite->callback = CaveEntranceSpriteCallback2;
}


void CaveEntranceSpriteCallback2(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        sprite->data[0]++;

        if (sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = ShrubEntranceSpriteCallbackEnd;
    }
}


void ShrubEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_SHRUB);
    ScriptContext_Enable();
}


bool8 FldEff_SecretBasePCTurnOn(void)
{
    s16 x, y;
    u8 taskId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    taskId = CreateTask(Task_SecretBasePCTurnOn, 0);
    gTasks[taskId].tX = x;
    gTasks[taskId].tY = y;
    gTasks[taskId].tState = 0;

    return FALSE;
}

void Task_SecretBasePCTurnOn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 4:
    case 12:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 8:
    case 16:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 20:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        FieldEffectActiveListRemove(FLDEFF_PCTURN_ON);
        ScriptContext_Enable();
        DestroyTask(taskId);
        return;
    }

    tState++;
}


void DoSecretBasePCTurnOffEffect(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    PlaySE(SE_PC_OFF);

    if (!(u16)VarGet(VAR_CURRENT_SECRET_BASE))
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_PC | MAPGRID_IMPASSABLE);
    else
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_RegisterPC | MAPGRID_IMPASSABLE);

    CurrentMapDrawMetatileAt(x, y);
}

void PopSecretBaseBalloon(s16 metatileId, s16 x, s16 y)
{
    u8 taskId = CreateTask(Task_PopSecretBaseBalloon, 0);

    gTasks[taskId].data[0] = metatileId;
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 1;
}

void Task_PopSecretBaseBalloon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[3] == 6)
        data[3] = 0;
    else
        data[3]++;

    if (data[3] == 0)
    {
        if (data[4] == 2)
            DoBalloonSoundEffect(data[0]);

        MapGridSetMetatileIdAt(data[1], data[2], data[0] + data[4]);
        CurrentMapDrawMetatileAt(data[1], data[2]);

        if (data[4] == 3)
            DestroyTask(taskId);
        else
            data[4]++;
    }
}


static void DoBalloonSoundEffect(s16 metatileId)
{
    switch (metatileId)
    {
    case METATILE_SecretBase_RedBalloon:
        PlaySE(SE_BALLOON_RED);
        break;
    case METATILE_SecretBase_BlueBalloon:
        PlaySE(SE_BALLOON_BLUE);
        break;
    case METATILE_SecretBase_YellowBalloon:
        PlaySE(SE_BALLOON_YELLOW);
        break;
    case METATILE_SecretBase_MudBall:
        PlaySE(SE_MUD_BALL);
        break;
    }
}


bool8 FldEff_NopA700(void)
{
    return FALSE;
}

bool8 FldEff_NopA6FC(void)
{
    return FALSE;
}

void DoSecretBaseBreakableDoorEffect(s16 x, s16 y)
{
    PlaySE(SE_BREAKABLE_DOOR);
    MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_BreakableDoor_BottomOpen);
    MapGridSetMetatileIdAt(x, y - 1, METATILE_SecretBase_BreakableDoor_TopOpen);
    CurrentMapDrawMetatileAt(x, y);
    CurrentMapDrawMetatileAt(x, y - 1);
}


static void Task_ShatterSecretBaseBreakableDoor(u8 taskId)
{
    if (gTasks[taskId].data[0] == 7)
    {
        DoSecretBaseBreakableDoorEffect(gTasks[taskId].data[1], gTasks[taskId].data[2]);
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0]++;
    }
}


void ShatterSecretBaseBreakableDoor(s16 x, s16 y)
{
    u8 dir = (u8)GetPlayerFacingDirection();

    if (dir == DIR_SOUTH)
    {
        DoSecretBaseBreakableDoorEffect(x, y);
    }
    else if (dir == DIR_NORTH)
    {
        u8 taskId = CreateTask(Task_ShatterSecretBaseBreakableDoor, 5);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = x;
        gTasks[taskId].data[2] = y;
    }
}


static void Task_SecretBaseMusicNoteMatSound(u8 taskId)
{
    if (gTasks[taskId].data[1] == 7)
    {
        switch (gTasks[taskId].tMetatileID)
        {
        case METATILE_SecretBase_NoteMat_C_Low:
            PlaySE(SE_NOTE_C);
            break;
        case METATILE_SecretBase_NoteMat_D:
            PlaySE(SE_NOTE_D);
            break;
        case METATILE_SecretBase_NoteMat_E:
            PlaySE(SE_NOTE_E);
            break;
        case METATILE_SecretBase_NoteMat_F:
            PlaySE(SE_NOTE_F);
            break;
        case METATILE_SecretBase_NoteMat_G:
            PlaySE(SE_NOTE_G);
            break;
        case METATILE_SecretBase_NoteMat_A:
            PlaySE(SE_NOTE_A);
            break;
        case METATILE_SecretBase_NoteMat_B:
            PlaySE(SE_NOTE_B);
            break;
        case METATILE_SecretBase_NoteMat_C_High:
            PlaySE(SE_NOTE_C_HIGH);
            break;
        }

        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[1]++;
    }
}


void PlaySecretBaseMusicNoteMatSound(s16 metatileId)
{
    u8 taskId = CreateTask(Task_SecretBaseMusicNoteMatSound, 5);

    gTasks[taskId].tMetatileID = metatileId;
    gTasks[taskId].data[1] = 0;
}

static void SpriteCB_GlitterMatSparkle(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] == 8)
        PlaySE(SE_M_HEAL_BELL);

    if (sprite->data[0] >= 32)
        DestroySprite(sprite);
}


void DoSecretBaseGlitterMatSparkle(void)
{
    s16 x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s16 y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    u8 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 4);

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].oam.paletteNum = 5;
        gSprites[spriteId].callback = SpriteCB_GlitterMatSparkle;
        gSprites[spriteId].data[0] = 0;
    }
}


extern const struct SpriteTemplate gUnknown_856A270;

bool8 FldEff_SandPillar(void)
{
    s16 x, y;

    LockPlayerFieldControls();
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    gFieldEffectArguments[5] = x;
    gFieldEffectArguments[6] = y;

    switch (GetPlayerFacingDirection())
    {
    case DIR_SOUTH:
        CreateSprite(&gUnknown_856A270,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 32,
                     0);

        break;

    case DIR_NORTH:
        CreateSprite(&gUnknown_856A270,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y,
                     148);

        break;

    case DIR_WEST:
        CreateSprite(&gUnknown_856A270,
                     gSprites[gPlayerAvatar.spriteId].oam.x - 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);

        break;

    case DIR_EAST:
        CreateSprite(&gUnknown_856A270,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 24,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);

        break;
    }

    return FALSE;
}

static void SpriteCB_SandPillar_BreakTop(struct Sprite *sprite)
{
    PlaySE(SE_M_ROCK_THROW);

    if (MapGridGetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1) == METATILE_SecretBase_SandOrnament_TopWall)
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_SecretBase_Wall_TopMid | MAPGRID_IMPASSABLE);
    else
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_SecretBase_SandOrnament_BrokenTop);

    MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_SecretBase_Ground);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);

    sprite->data[0] = 0;
    sprite->callback = SpriteCB_SandPillar_BreakBase;
}

static void SpriteCB_SandPillar_BreakBase(struct Sprite *sprite)
{
    if (sprite->data[0] < 18)
    {
        sprite->data[0]++;
    }
    else
    {
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_SecretBase_SandOrnament_BrokenBase | MAPGRID_IMPASSABLE);
        CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_SandPillar_End;
    }
}

static void SpriteCB_SandPillar_End(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SAND_PILLAR);
    ScriptContext_Enable();
}

void GetShieldToyTVDecorationInfo(void)
{
    s16 x, y;
    s32 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    metatileId = MapGridGetMetatileIdAt(x, y);

    switch (metatileId)
    {
    case METATILE_SecretBase_GoldShield_Base1:
        ConvertIntToDecimalStringN(gStringVar1, 100, 0, 3);
        StringCopy(gStringVar2, gUnknown_85CA70B + 0x34);
        gSpecialVar_Result = 0;
        if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x10);
        }
        break;
    case METATILE_SecretBase_SilverShield_Base1:
        ConvertIntToDecimalStringN(gStringVar1, 50, 0, 2);
        StringCopy(gStringVar2, gUnknown_85CA70B + 0x37);
        gSpecialVar_Result = 0;
        if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x20);
        }
        break;
    case METATILE_SecretBase_TV:
        gSpecialVar_Result = 1;
        if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x80);
        }
        break;
    case METATILE_SecretBase_RoundTV:
        gSpecialVar_Result = 2;
        if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x80);
        }
        break;
    case METATILE_SecretBase_CuteTV:
        gSpecialVar_Result = 3;
        if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x80);
        }
        break;
    }
}


bool8 sub_080FB654(u16 x, u8 y)
{
    if (!CurMapIsSecretBase())
        return FALSE;
    if (y == 0)
    {
        if ((u16)(x - METATILE_SecretBase_SandOrnament_Top) <= 1)
            return TRUE;
        if (x == METATILE_SecretBase_BreakableDoor_TopClosed)
            return TRUE;
    }
    else
    {
        if (x == METATILE_SecretBase_SandOrnament_Base1)
            return TRUE;
        if (x == METATILE_SecretBase_BreakableDoor_BottomClosed)
            return TRUE;
    }
    return FALSE;
}

#undef tState
#define tState data[0]
#define tMosaic data[1]

static void Task_FieldPoisonEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        tMosaic += 2;
        if (tMosaic > 8)
            tState++;
        break;
    case 1:
        tMosaic -= 2;
        if (tMosaic == 0)
            tState++;
        break;
    case 2:
        DestroyTask(taskId);
        return;
    }
    SetGpuReg(REG_OFFSET_MOSAIC, (u16)((tMosaic << 4) | tMosaic));
}

#undef tState
#undef tMosaic
#define tState data[2]


void FldEffPoison_Start(void)
{
    PlaySE(SE_FIELD_POISON);
    CreateTask(Task_FieldPoisonEffect, 80);
}

bool32 sub_080FB730(void)
{
    return FuncIsActiveTask(Task_FieldPoisonEffect);
}

void Task_WateringBerryTreeAnim_0(u8 taskId)
{
    gTasks[taskId].func = Task_WateringBerryTreeAnim_1;
}

void Task_WateringBerryTreeAnim_1(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObjEvent)
        || ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        sub_0808BB8C((u8)GetPlayerFacingDirection());
        ObjectEventSetHeldMovement(playerObjEvent, sub_08092F08((u8)GetPlayerFacingDirection()));
        gTasks[taskId].func = Task_WateringBerryTreeAnim_2;
    }
}


void Task_WateringBerryTreeAnim_2(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        s16 value = gTasks[taskId].data[1]++;

        if (value < 10)
            ObjectEventSetHeldMovement(playerObjEvent, sub_08092F08((u8)GetPlayerFacingDirection()));
        else
            gTasks[taskId].func = Task_WateringBerryTreeAnim_3;
    }
}


void Task_WateringBerryTreeAnim_3(u8 taskId)
{
    SetPlayerAvatarTransitionFlags((u8)sub_0808B634());
    DestroyTask(taskId);
    ScriptContext_Enable();
}


void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_WateringBerryTreeAnim_0, 80);
}

extern const struct SpritePalette sSpritePalette_RecordMixLights;
extern const struct SpriteTemplate sSpriteTemplate_RecordMixLights;

u8 CreateRecordMixingLights(void)
{
    u8 spriteId;

    LoadSpritePalette(&sSpritePalette_RecordMixLights);

    spriteId = CreateSprite(&sSpriteTemplate_RecordMixLights, 0, 0, 82);

    if (spriteId == MAX_SPRITES)
    {
        return MAX_SPRITES;
    }
    else
    {
        struct Sprite *sprite = &gSprites[spriteId];
        GetMapCoordsFromSpritePos(16, 13, &sprite->x, &sprite->y);
        sprite->coordOffsetEnabled = TRUE;
        sprite->x += 16;
        sprite->y += 2;
    }
    return spriteId;
}

void DestroyRecordMixingLights(void)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].template == &sSpriteTemplate_RecordMixLights)
        {
            FreeSpritePalette(&gSprites[i]);
            DestroySprite(&gSprites[i]);
        }
    }
}
