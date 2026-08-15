#include "global.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "graphics.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "sound.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "safari_zone.h"
#include "battle_anim.h"
#include "data.h"
#include "pokemon_summary_screen.h"
#include "strings.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
extern const u8 gText_SafariBallsLeft2[];
extern const u8 gSpeciesNames[][6];

struct TestingBar
{
    s32 maxValue;
    s32 oldValue;
    s32 receivedValue;
    u32 unkC_0:5;
    u32 unk10;
};

enum
{   // Corresponds to gHealthboxElementsGfxTable (and the tables after it) in graphics.c
    // These are indexes into the tables, which are filled with 8x8 square pixel data.
    HEALTHBOX_GFX_0, //hp bar [black section]
    HEALTHBOX_GFX_1, //hp bar "H"
    HEALTHBOX_GFX_2, //hp bar "P"
    HEALTHBOX_GFX_HP_BAR_GREEN, //hp bar [0 pixels]
    HEALTHBOX_GFX_4,  //hp bar [1 pixels]
    HEALTHBOX_GFX_5,  //hp bar [2 pixels]
    HEALTHBOX_GFX_6,  //hp bar [3 pixels]
    HEALTHBOX_GFX_7,  //hp bar [4 pixels]
    HEALTHBOX_GFX_8,  //hp bar [5 pixels]
    HEALTHBOX_GFX_9,  //hp bar [6 pixels]
    HEALTHBOX_GFX_10, //hp bar [7 pixels]
    HEALTHBOX_GFX_11, //hp bar [8 pixels]
    HEALTHBOX_GFX_12, //exp bar [0 pixels]
    HEALTHBOX_GFX_13, //exp bar [1 pixels]
    HEALTHBOX_GFX_14, //exp bar [2 pixels]
    HEALTHBOX_GFX_15, //exp bar [3 pixels]
    HEALTHBOX_GFX_16, //exp bar [4 pixels]
    HEALTHBOX_GFX_17, //exp bar [5 pixels]
    HEALTHBOX_GFX_18, //exp bar [6 pixels]
    HEALTHBOX_GFX_19, //exp bar [7 pixels]
    HEALTHBOX_GFX_20, //exp bar [8 pixels]
    HEALTHBOX_GFX_STATUS_PSN_BATTLER0,  //status psn "(P"
    HEALTHBOX_GFX_22,                   //status psn "SN"
    HEALTHBOX_GFX_23,                   //status psn "|)"
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER0,  //status prz
    HEALTHBOX_GFX_25,
    HEALTHBOX_GFX_26,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER0,  //status slp
    HEALTHBOX_GFX_28,
    HEALTHBOX_GFX_29,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER0,  //status frz
    HEALTHBOX_GFX_31,
    HEALTHBOX_GFX_32,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER0,  //status brn
    HEALTHBOX_GFX_34,
    HEALTHBOX_GFX_35,
    HEALTHBOX_GFX_36, //misc [Black section]
    HEALTHBOX_GFX_37, //misc [Black section]
    HEALTHBOX_GFX_38, //misc [Black section]
    HEALTHBOX_GFX_39, //misc [Blank Health Window?]
    HEALTHBOX_GFX_40, //misc [Blank Health Window?]
    HEALTHBOX_GFX_41, //misc [Blank Health Window?]
    HEALTHBOX_GFX_42, //misc [Blank Health Window?]
    HEALTHBOX_GFX_43, //misc [Top of Health Window?]
    HEALTHBOX_GFX_44, //misc [Top of Health Window?]
    HEALTHBOX_GFX_45, //misc [Top of Health Window?]
    HEALTHBOX_GFX_46, //misc [Blank Health Window?]
    HEALTHBOX_GFX_HP_BAR_YELLOW, //hp bar yellow [0 pixels]
    HEALTHBOX_GFX_48, //hp bar yellow [1 pixels]
    HEALTHBOX_GFX_49, //hp bar yellow [2 pixels]
    HEALTHBOX_GFX_50, //hp bar yellow [3 pixels]
    HEALTHBOX_GFX_51, //hp bar yellow [4 pixels]
    HEALTHBOX_GFX_52, //hp bar yellow [5 pixels]
    HEALTHBOX_GFX_53, //hp bar yellow [6 pixels]
    HEALTHBOX_GFX_54, //hp bar yellow [7 pixels]
    HEALTHBOX_GFX_55, //hp bar yellow [8 pixels]
    HEALTHBOX_GFX_HP_BAR_RED,  //hp bar red [0 pixels]
    HEALTHBOX_GFX_57, //hp bar red [1 pixels]
    HEALTHBOX_GFX_58, //hp bar red [2 pixels]
    HEALTHBOX_GFX_59, //hp bar red [3 pixels]
    HEALTHBOX_GFX_60, //hp bar red [4 pixels]
    HEALTHBOX_GFX_61, //hp bar red [5 pixels]
    HEALTHBOX_GFX_62, //hp bar red [6 pixels]
    HEALTHBOX_GFX_63, //hp bar red [7 pixels]
    HEALTHBOX_GFX_64, //hp bar red [8 pixels]
    HEALTHBOX_GFX_65, //hp bar frame end
    HEALTHBOX_GFX_STATUS_BALL, // Full
    HEALTHBOX_GFX_STATUS_BALL_EMPTY,
    HEALTHBOX_GFX_STATUS_BALL_FAINTED,
    HEALTHBOX_GFX_STATUS_BALL_STATUSED,
    HEALTHBOX_GFX_STATUS_BALL_CAUGHT,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER1, //status2 "PSN"
    HEALTHBOX_GFX_72,
    HEALTHBOX_GFX_73,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER1, //status2 "PRZ"
    HEALTHBOX_GFX_75,
    HEALTHBOX_GFX_76,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER1, //status2 "SLP"
    HEALTHBOX_GFX_78,
    HEALTHBOX_GFX_79,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER1, //status2 "FRZ"
    HEALTHBOX_GFX_81,
    HEALTHBOX_GFX_82,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER1, //status2 "BRN"
    HEALTHBOX_GFX_84,
    HEALTHBOX_GFX_85,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER2, //status3 "PSN"
    HEALTHBOX_GFX_87,
    HEALTHBOX_GFX_88,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER2, //status3 "PRZ"
    HEALTHBOX_GFX_90,
    HEALTHBOX_GFX_91,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER2, //status3 "SLP"
    HEALTHBOX_GFX_93,
    HEALTHBOX_GFX_94,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER2, //status3 "FRZ"
    HEALTHBOX_GFX_96,
    HEALTHBOX_GFX_97,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER2, //status3 "BRN"
    HEALTHBOX_GFX_99,
    HEALTHBOX_GFX_100,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER3, //status4 "PSN"
    HEALTHBOX_GFX_102,
    HEALTHBOX_GFX_103,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER3, //status4 "PRZ"
    HEALTHBOX_GFX_105,
    HEALTHBOX_GFX_106,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER3, //status4 "SLP"
    HEALTHBOX_GFX_108,
    HEALTHBOX_GFX_109,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER3, //status4 "FRZ"
    HEALTHBOX_GFX_111,
    HEALTHBOX_GFX_112,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER3, //status4 "BRN"
    HEALTHBOX_GFX_114,
    HEALTHBOX_GFX_115,
    HEALTHBOX_GFX_FRAME_END,
    HEALTHBOX_GFX_FRAME_END_BAR,
};

const u8 *GetHealthboxElementGfxPtr(u8);
static void UpdateHpTextInHealthboxInDoubles(u8, s16, u8);
void UpdateNickInHealthbox(u8 healthboxSpriteId, struct Pokemon *mon);

// Defined in asm/battle_interface_mid.s / battle_interface_tail.s (still being converted to C).
void AddTextPrinterAndCreateWindowOnHealthbox(u8 healthboxSpriteId);
void UpdateLeftNoOfBallsTextOnHealthbox(u8 healthboxSpriteId);
static void UpdateStatusIconInHealthbox(u8 healthboxSpriteId);
static void TryAddPokeballIconToHealthbox(u8 healthboxSpriteId, bool8 noStatus);
static u8 GetStatusIconForBattlerId(u8 statusElementId, u8 battler);

static void Task_HidePartyStatusSummary_BattleStart_1(u8);
static void Task_HidePartyStatusSummary_BattleStart_2(u8);
static void Task_HidePartyStatusSummary_DuringBattle(u8);

static void SpriteCB_HealthBoxOther(struct Sprite *);
static void SpriteCB_HealthBar(struct Sprite *);
static void SpriteCB_StatusSummaryBar_Enter(struct Sprite *);
static void SpriteCB_StatusSummaryBar_Exit(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_Enter(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_Exit(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_OnSwitchout(struct Sprite *);

static s32 CalcNewBarValue(s32, s32, s32, s32 *, u8, u16);
static u8 GetScaledExpFraction(s32, s32, s32, u8);
static void MoveBattleBarGraphically(u8, u8);
static u8 CalcBarFilledPixels(s32, s32, s32, s32 *, u8 *, u8);
static void Debug_TestHealthBar_Helper(struct TestingBar *, s32 *, u16 *);

enum
{
    PAL_STATUS_PSN,
    PAL_STATUS_PAR,
    PAL_STATUS_SLP,
    PAL_STATUS_FRZ,
    PAL_STATUS_BRN
};

// JP const data lives in data.s (battle_interface region 0x082FCB30-0x082FCE0C).
extern const struct SpriteTemplate gUnknown_82FCB38[2];
#define sHealthboxPlayerSpriteTemplates gUnknown_82FCB38
extern const struct SpriteTemplate gUnknown_82FCB68[2];
#define sHealthboxOpponentSpriteTemplates gUnknown_82FCB68
extern const struct SpriteTemplate gUnknown_82FCB98[1];
#define sHealthboxSafariSpriteTemplate gUnknown_82FCB98
extern const struct SpriteTemplate gUnknown_82FCBB8[4];
#define sHealthbarSpriteTemplates gUnknown_82FCBB8
extern const struct SubspriteTable gUnknown_82FCC84[2];
#define sHealthBar_SubspriteTables gUnknown_82FCC84
extern const struct SubspriteTable gUnknown_82FCCBC[1];
#define sStatusSummaryBar_SubspriteTable_Enter gUnknown_82FCCBC
extern const struct SubspriteTable gUnknown_82FCCC4[1];
#define sStatusSummaryBar_SubspriteTable_Exit gUnknown_82FCCC4
extern const struct CompressedSpriteSheet gUnknown_82FCD2C;
#define sStatusSummaryBarSpriteSheet gUnknown_82FCD2C
extern const struct SpritePalette gUnknown_82FCD34;
#define sStatusSummaryBarSpritePal gUnknown_82FCD34
extern const struct SpritePalette gUnknown_82FCD3C;
#define sStatusSummaryBallsSpritePal gUnknown_82FCD3C
extern const struct SpriteSheet gUnknown_82FCD44;
#define sStatusSummaryBallsSpriteSheet gUnknown_82FCD44
extern const struct SpriteTemplate gUnknown_82FCD5C[2];
#define sStatusSummaryBarSpriteTemplates gUnknown_82FCD5C
extern const struct SpriteTemplate gUnknown_82FCD8C[2];
#define sStatusSummaryBallsSpriteTemplates gUnknown_82FCD8C
extern const u8 gUnknown_82FCDBC[0x1E];
#define sLvTextTemplate gUnknown_82FCDBC
extern const u8 gUnknown_82FCDDA[0x14];
#define sEmptyWhiteText_GrayHighlight gUnknown_82FCDDA
extern const u8 gUnknown_82FCDEE[0x14];
#define sEmptyWhiteText_TransparentHighlight gUnknown_82FCDEE
extern const u16 gUnknown_82FCE02[5];
#define sStatusIconColors gUnknown_82FCE02

static s32 DummiedOutFunction(s16 unused1, s16 unused2, s32 unused3)
{
    return 9;
}

static void Debug_DrawNumber(s16 number, u16 *dest, bool8 unk)
{
    s8 i, j;
    u8 buff[4];

    for (i = 0; i < 4; i++)
        buff[i] = 0;

    for (i = 3; ; i--)
    {
        if (number > 0)
        {
            buff[i] = number % 10;
            number /= 10;
        }
        else
        {
            for (; i > -1; i--)
                buff[i] = 0xFF;

            if (buff[3] == 0xFF)
                buff[3] = 0;
            break;
        }
    }

    if (!unk)
    {
        for (i = 0, j = 0; i < 4; i++)
        {
            if (buff[j] == 0xFF)
            {
                dest[j + 0x00] &= 0xFC00;
                dest[j + 0x00] |= 0x1E;
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x1E;
            }
            else
            {
                dest[j + 0x00] &= 0xFC00;
                dest[j + 0x00] |= 0x14 + buff[j];
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x34 + buff[i];
            }
            j++;
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (buff[i] == 0xFF)
            {
                dest[i + 0x00] &= 0xFC00;
                dest[i + 0x00] |= 0x1E;
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x1E;
            }
            else
            {
                dest[i + 0x00] &= 0xFC00;
                dest[i + 0x00] |= 0x14 + buff[i];
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x34 + buff[i];
            }
        }
    }
}

static void UNUSED Debug_DrawNumberPair(s16 number1, s16 number2, u16 *dest)
{
    dest[4] = 0x1E;
    Debug_DrawNumber(number2, dest, FALSE);
    Debug_DrawNumber(number1, dest + 5, TRUE);
}

// Because the healthbox is too large to fit into one sprite, it is divided into two sprites.
// healthboxLeft  or healthboxMain  is the left part that is used as the 'main' sprite.
// healthboxRight or healthboxOther is the right part of the healthbox.
// There's also the third sprite under name of healthbarSprite that refers to the healthbar visible on the healtbox.

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_HealthBarSpriteId     data[5]
#define hMain_Battler               data[6]
#define hMain_Data7                 data[7]

// data fields for healthboxRight
#define hOther_HealthBoxSpriteId    data[5]

// data fields for healthbar
#define hBar_HealthBoxSpriteId      data[5]
#define hBar_Data6                  data[6]

static void TryAddPokeballIconToHealthbox(u8 healthboxSpriteId, bool8 noStatus)
{
    u8 battler, healthBarSpriteId;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
        return;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return;

    battler = gSprites[healthboxSpriteId].hMain_Battler;
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        return;
    if (!GetSetPokedexFlag(HoennToNationalOrder(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES)), FLAG_GET_CAUGHT))
        return;

    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;

    if (noStatus)
        CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_BALL_CAUGHT), (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 8) * TILE_SIZE_4BPP), 32);
    else
        CpuFill32(0, (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 8) * TILE_SIZE_4BPP), 32);
}

static u8 GetStatusIconForBattlerId(u8 statusElementId, u8 battler)
{
    u8 ret = statusElementId;

    switch (statusElementId)
    {
    case HEALTHBOX_GFX_STATUS_PSN_BATTLER0:
        if (battler == 0)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER0;
        else if (battler == 1)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER1;
        else if (battler == 2)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_PRZ_BATTLER0:
        if (battler == 0)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER0;
        else if (battler == 1)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER1;
        else if (battler == 2)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_SLP_BATTLER0:
        if (battler == 0)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER0;
        else if (battler == 1)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER1;
        else if (battler == 2)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_FRZ_BATTLER0:
        if (battler == 0)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER0;
        else if (battler == 1)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER1;
        else if (battler == 2)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_BRN_BATTLER0:
        if (battler == 0)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER0;
        else if (battler == 1)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER1;
        else if (battler == 2)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER3;
        break;
    }

    return ret;
}

static void UpdateStatusIconInHealthbox(u8 healthboxSpriteId)
{
    s32 i;
    u8 battler, healthBarSpriteId;
    u32 status, pltAdder;
    const u8 *statusGfxPtr;
    s16 tileNumAdder;
    u8 statusPalId;

    battler = gSprites[healthboxSpriteId].hMain_Battler;
    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
    {
        status = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_STATUS);
        if (!IsDoubleBattle())
            tileNumAdder = 0x1A;
        else
            tileNumAdder = 0x12;
    }
    else
    {
        status = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_STATUS);
        tileNumAdder = 0x11;
    }

    if (status & STATUS1_SLEEP)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_SLP_BATTLER0, battler));
        statusPalId = PAL_STATUS_SLP;
    }
    else if (status & STATUS1_PSN_ANY)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_PSN_BATTLER0, battler));
        statusPalId = PAL_STATUS_PSN;
    }
    else if (status & STATUS1_BURN)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_BRN_BATTLER0, battler));
        statusPalId = PAL_STATUS_BRN;
    }
    else if (status & STATUS1_FREEZE)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_FRZ_BATTLER0, battler));
        statusPalId = PAL_STATUS_FRZ;
    }
    else if (status & STATUS1_PARALYSIS)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_PRZ_BATTLER0, battler));
        statusPalId = PAL_STATUS_PAR;
    }
    else
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_39);

        for (i = 0; i < 3; i++)
            CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder + i) * TILE_SIZE_4BPP), 32);

        if (!gBattleSpritesDataPtr->battlerData[battler].hpNumbersNoBars)
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 64);

        TryAddPokeballIconToHealthbox(healthboxSpriteId, TRUE);
        return;
    }

    pltAdder = PLTT_ID(gSprites[healthboxSpriteId].oam.paletteNum);
    pltAdder += battler + 12;

    FillPalette(sStatusIconColors[statusPalId], OBJ_PLTT_OFFSET + pltAdder, PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[OBJ_PLTT_OFFSET + pltAdder], (u16 *)OBJ_PLTT + pltAdder, PLTT_SIZEOF(1));
    CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder) * TILE_SIZE_4BPP), 96);
    if (IsDoubleBattle() == TRUE || GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        if (!gBattleSpritesDataPtr->battlerData[battler].hpNumbersNoBars)
        {
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_0), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 32);
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_65), (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 1) * TILE_SIZE_4BPP), 32);
        }
    }
    TryAddPokeballIconToHealthbox(healthboxSpriteId, FALSE);
}

u8 CreateBattlerHealthboxSprites(u8 battler)
{
    s16 data6 = 0;
    u8 healthboxLeftSpriteId, healthboxRightSpriteId;
    u8 healthbarSpriteId;
    struct Sprite *healthBarSpritePtr;

    if (!IsDoubleBattle())
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxPlayerSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.shape = ST_OAM_SQUARE;

            gSprites[healthboxRightSpriteId].oam.shape = ST_OAM_SQUARE;
            gSprites[healthboxRightSpriteId].oam.tileNum += 64;
        }
        else
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxOpponentSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxRightSpriteId].oam.tileNum += 32;

            data6 = 2;
        }
        gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

        gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
        gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;
    }
    else
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxPlayerSpriteTemplates[GetBattlerPosition(battler) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[GetBattlerPosition(battler) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

            gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
            gSprites[healthboxRightSpriteId].oam.tileNum += 32;
            gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

            data6 = 1;
        }
        else
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxOpponentSpriteTemplates[GetBattlerPosition(battler) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[GetBattlerPosition(battler) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

            gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
            gSprites[healthboxRightSpriteId].oam.tileNum += 32;
            gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

            data6 = 2;
        }
    }

    healthbarSpriteId = CreateSpriteAtEnd(&sHealthbarSpriteTemplates[gBattlerPositions[battler]], 140, 60, 0);
    healthBarSpritePtr = &gSprites[healthbarSpriteId];
    SetSubspriteTables(healthBarSpritePtr, &sHealthBar_SubspriteTables[GetBattlerSide(battler)]);
    healthBarSpritePtr->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    healthBarSpritePtr->oam.priority = 1;

    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + healthBarSpritePtr->oam.tileNum * TILE_SIZE_4BPP), 64);

    gSprites[healthboxLeftSpriteId].hMain_HealthBarSpriteId = healthbarSpriteId;
    gSprites[healthboxLeftSpriteId].hMain_Battler = battler;
    gSprites[healthboxLeftSpriteId].invisible = TRUE;

    gSprites[healthboxRightSpriteId].invisible = TRUE;

    healthBarSpritePtr->hBar_HealthBoxSpriteId = healthboxLeftSpriteId;
    healthBarSpritePtr->hBar_Data6 = data6;
    healthBarSpritePtr->invisible = TRUE;

    return healthboxLeftSpriteId;
}

u8 CreateSafariPlayerHealthboxSprites(void)
{
    u8 healthboxLeftSpriteId, healthboxRightSpriteId;

    healthboxLeftSpriteId = CreateSprite(&sHealthboxSafariSpriteTemplate, DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
    healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxSafariSpriteTemplate, DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

    gSprites[healthboxLeftSpriteId].oam.shape = ST_OAM_SQUARE;
    gSprites[healthboxRightSpriteId].oam.shape = ST_OAM_SQUARE;

    gSprites[healthboxRightSpriteId].oam.tileNum += 64;

    gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;
    gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;

    gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

    return healthboxLeftSpriteId;
}

const u8 *GetHealthboxElementGfxPtr(u8 elementId)
{
    return gHealthboxElementsGfxTable[elementId];
}

// Syncs the position of healthbar accordingly with the healthbox.
static void SpriteCB_HealthBar(struct Sprite *sprite)
{
    u8 healthboxSpriteId = sprite->hBar_HealthBoxSpriteId;

    switch (sprite->hBar_Data6)
    {
    case 0:
        sprite->x = gSprites[healthboxSpriteId].x + 16;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    case 1:
        sprite->x = gSprites[healthboxSpriteId].x + 16;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    case 2:
    default:
        sprite->x = gSprites[healthboxSpriteId].x + 8;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    }

    sprite->x2 = gSprites[healthboxSpriteId].x2;
    sprite->y2 = gSprites[healthboxSpriteId].y2;
}

static void SpriteCB_HealthBoxOther(struct Sprite *sprite)
{
    u8 healthboxMainSpriteId = sprite->hOther_HealthBoxSpriteId;

    sprite->x = gSprites[healthboxMainSpriteId].x + 64;
    sprite->y = gSprites[healthboxMainSpriteId].y;

    sprite->x2 = gSprites[healthboxMainSpriteId].x2;
    sprite->y2 = gSprites[healthboxMainSpriteId].y2;
}

void SetBattleBarStruct(u8 battler, u8 healthboxSpriteId, s32 maxVal, s32 oldVal, s32 receivedValue)
{
    gBattleSpritesDataPtr->battleBars[battler].healthboxSpriteId = healthboxSpriteId;
    gBattleSpritesDataPtr->battleBars[battler].maxValue = maxVal;
    gBattleSpritesDataPtr->battleBars[battler].oldValue = oldVal;
    gBattleSpritesDataPtr->battleBars[battler].receivedValue = receivedValue;
    gBattleSpritesDataPtr->battleBars[battler].currValue = -32768;
}

void SetHealthboxSpriteInvisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = TRUE;
    gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId].invisible = TRUE;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = TRUE;
}

void SetHealthboxSpriteVisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = FALSE;
    gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId].invisible = FALSE;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = FALSE;
}

static void UpdateSpritePos(u8 spriteId, s16 x, s16 y)
{
    gSprites[spriteId].x = x;
    gSprites[spriteId].y = y;
}

void DestoryHealthboxSprite(u8 healthboxSpriteId)
{
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].oam.affineParam]);
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId]);
    DestroySprite(&gSprites[healthboxSpriteId]);
}

void DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBattlerOnly)
{

}

void UpdateOamPriorityInAllHealthboxes(u8 priority)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        u8 healthboxLeftSpriteId = gHealthboxSpriteIds[i];
        u8 healthboxRightSpriteId = gSprites[gHealthboxSpriteIds[i]].oam.affineParam;
        u8 healthbarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

        gSprites[healthboxLeftSpriteId].oam.priority = priority;
        gSprites[healthboxRightSpriteId].oam.priority = priority;
        gSprites[healthbarSpriteId].oam.priority = priority;
    }
}

void InitBattlerHealthboxCoords(u8 battler)
{
    s16 x = 0, y = 0;

    if (!IsDoubleBattle())
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            x = 44, y = 30;
        else
            x = 158, y = 88;
    }
    else
    {
        switch (GetBattlerPosition(battler))
        {
        case B_POSITION_PLAYER_LEFT:
            x = 159, y = 76;
            break;
        case B_POSITION_PLAYER_RIGHT:
            x = 171, y = 101;
            break;
        case B_POSITION_OPPONENT_LEFT:
            x = 44, y = 19;
            break;
        case B_POSITION_OPPONENT_RIGHT:
            x = 32, y = 44;
            break;
        }
    }

    UpdateSpritePos(gHealthboxSpriteIds[battler], x, y);
}

static void UpdateLvlInHealthbox(u8 healthboxSpriteId, u8 lvl)
{
    u8 text[32];
    u8 xPos;
    u8 count;
    u8 i;

    memcpy(text, sLvTextTemplate, sizeof(sLvTextTemplate));

    if (!IsDoubleBattle())
    {
        if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
            xPos = 0x49;
        else
            xPos = 0x28;
    }
    else
    {
        if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
            xPos = 0x29;
        else
            xPos = 0x28;
    }

    if (lvl == 100)
    {
        ConvertIntToDecimalStringN(text + 6, 100, STR_CONV_MODE_LEFT_ALIGN, 3);
        count = 3;
    }
    else
    {
        CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_42),
                  (void *)(OBJ_VRAM0 + TILE_SIZE_4BPP * (gSprites[healthboxSpriteId].oam.tileNum + xPos)),
                  0x20);
        ConvertIntToDecimalStringN(text + 6, lvl, STR_CONV_MODE_LEFT_ALIGN, 2);
        if (lvl <= 9)
            StringCopy(text + 7, gText_HealthboxNickname + 4); // blank tile + EOS
        count = 2;
        xPos++;
    }

    RenderTextFont9(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);
    for (i = 0; i < count; i++)
    {
        CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[i * 64] + 32,
                  (void *)(OBJ_VRAM0 + TILE_SIZE_4BPP * (gSprites[healthboxSpriteId].oam.tileNum + xPos + i)),
                  0x20);
    }
}

void UpdateHpTextInHealthbox(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent)
{
    u8 text[20];
    u8 battler;
    u32 var;
    u8 i;

    memcpy(text, sEmptyWhiteText_GrayHighlight, sizeof(sEmptyWhiteText_GrayHighlight));
    battler = gSprites[healthboxSpriteId].hMain_Battler;
    if (IsDoubleBattle() == TRUE || GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        UpdateHpTextInHealthboxInDoubles(healthboxSpriteId, value, maxOrCurrent);
    }
    else
    {
        if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
        {
            if (maxOrCurrent == HP_CURRENT)
                var = 29;
            else
                var = 89;
        }
        else
        {
            if (maxOrCurrent == HP_CURRENT)
                var = 20;
            else
                var = 48;
        }

        ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
        RenderTextFont9(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

        for (i = 0; i < 3; i++)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[i * 64 + 32],
                      (void *)((OBJ_VRAM0) + TILE_SIZE_4BPP * (gSprites[healthboxSpriteId].oam.tileNum + var + i)),
                      0x20);
        }
    }
}

static void UpdateHpTextInHealthboxInDoubles(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent)
{
    u8 text[20];
    u8 battler;
    u8 r7;
    u8 *txtPtr;
    u8 i;
    u8 var;

    memcpy(text, sEmptyWhiteText_TransparentHighlight, sizeof(sEmptyWhiteText_TransparentHighlight));
    battler = gSprites[healthboxSpriteId].hMain_Battler;

    if (gBattleSpritesDataPtr->battlerData[battler].hpNumbersNoBars) // don't print text if only bars are visible
    {
        var = 4;
        if (maxOrCurrent == HP_CURRENT)
            var = 0;

        r7 = gSprites[healthboxSpriteId].data[5];
        txtPtr = ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
        if (!maxOrCurrent)
            StringCopy(txtPtr, gText_Slash);
        RenderTextFont9(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

        for (i = var; i < var + 3; i++)
        {
            if (i < 3)
            {
                CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[((i - var) * 64) + 32],
                      (void *)((OBJ_VRAM0) + 32 * (1 + gSprites[r7].oam.tileNum + i)),
                      0x20);
            }
            else
            {
                CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[((i - var) * 64) + 32],
                      (void *)((OBJ_VRAM0 + 0x20) + 32 * (i + gSprites[r7].oam.tileNum)),
                      0x20);
            }
        }

        if (maxOrCurrent == HP_CURRENT)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[224],
                      (void *)((OBJ_VRAM0) + ((gSprites[r7].oam.tileNum + 4) * TILE_SIZE_4BPP)),
                      0x20);
            CpuFill32(0, (void *)((OBJ_VRAM0) + (gSprites[r7].oam.tileNum * TILE_SIZE_4BPP)), 0x20);
        }
        else
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER) // Impossible to reach part, because the battler is from the opponent's side.
            {
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END),
                      (void *)(OBJ_VRAM0) + ((gSprites[healthboxSpriteId].oam.tileNum + 52) * TILE_SIZE_4BPP),
                       0x20);
            }
        }
    }
}

// Prints mon's nature, catch and flee rate. Probably used to test pokeblock-related features.
static void PrintSafariMonInfo(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 text[20];
    s32 j, spriteTileNum;
    u8 *barFontGfx;
    u8 i, var, nature, healthBarSpriteId;

    memcpy(text, sEmptyWhiteText_GrayHighlight, sizeof(sEmptyWhiteText_GrayHighlight));
    barFontGfx = &gMonSpritesGfxPtr->barFontGfx[0x520 + (GetBattlerPosition(gSprites[healthboxSpriteId].hMain_Battler) * 384)];
    var = 5;
    nature = GetNature(mon);
    StringCopy(&text[6], gNatureNamePointers[nature]);
    RenderTextFont9(barFontGfx, FONT_BOLD, text);

    for (j = 6, i = 0; i < var; i++, j++)
    {
        u8 elementId;

        if ((text[j] >= 55 && text[j] <= 74) || (text[j] >= 135 && text[j] <= 154))
            elementId = 44;
        else if ((text[j] >= 75 && text[j] <= 79) || (text[j] >= 155 && text[j] <= 159))
            elementId = 45;
        else
            elementId = 43;

        CpuCopy32(GetHealthboxElementGfxPtr(elementId), barFontGfx + (i * 64), 0x20);
    }

    for (j = 1; j < var + 1; j++)
    {
        spriteTileNum = (gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * TILE_SIZE_4BPP;
        CpuCopy32(barFontGfx, (void *)(OBJ_VRAM0) + (spriteTileNum), 0x20);
        barFontGfx += 0x20;

        spriteTileNum = (8 + gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * TILE_SIZE_4BPP;
        CpuCopy32(barFontGfx, (void *)(OBJ_VRAM0) + (spriteTileNum), 0x20);
        barFontGfx += 0x20;
    }

    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;
    ConvertIntToDecimalStringN(&text[6], gBattleStruct->safariCatchFactor, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(&text[9], gBattleStruct->safariEscapeFactor, STR_CONV_MODE_RIGHT_ALIGN, 2);
    text[5] = CHAR_SPACE;
    text[8] = CHAR_SLASH;
    RenderTextFont9(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

    j = healthBarSpriteId; // Needed to match for some reason.
    for (j = 0; j < 5; j++)
    {
        if (j <= 1)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[0x40 * j + 0x20],
                      (void *)(OBJ_VRAM0) + (gSprites[healthBarSpriteId].oam.tileNum + 2 + j) * TILE_SIZE_4BPP,
                      32);
        }
        else
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[0x40 * j + 0x20],
                      (void *)(OBJ_VRAM0 + 0xC0) + (j + gSprites[healthBarSpriteId].oam.tileNum) * TILE_SIZE_4BPP,
                      32);
        }
    }
}

void SwapHpBarsWithHpText(void)
{
    s32 i;
    u8 healthBarSpriteId;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gSprites[gHealthboxSpriteIds[i]].callback == SpriteCallbackDummy
         && GetBattlerSide(i) != B_SIDE_OPPONENT
         && (IsDoubleBattle() || GetBattlerSide(i) != B_SIDE_PLAYER))
        {
            bool8 noBars;

            gBattleSpritesDataPtr->battlerData[i].hpNumbersNoBars ^= 1;
            noBars = gBattleSpritesDataPtr->battlerData[i].hpNumbersNoBars;
            if (GetBattlerSide(i) == B_SIDE_PLAYER)
            {
                if (!IsDoubleBattle())
                    continue;
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    continue;

                if (noBars == TRUE) // bars to text
                {
                    healthBarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

                    CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 0x100);
                    UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_HP), HP_CURRENT);
                    UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_MAX_HP), HP_MAX);
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthboxSpriteIds[i]);
                    UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gPlayerParty[gBattlerPartyIndexes[i]], HEALTHBOX_HEALTH_BAR);
                    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END_BAR), (void *)(OBJ_VRAM0 + 0x680 + gSprites[gHealthboxSpriteIds[i]].oam.tileNum * TILE_SIZE_4BPP), 32);
                }
            }
            else
            {
                if (noBars == TRUE) // bars to text
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    {
                        // Most likely a debug function.
                        PrintSafariMonInfo(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]]);
                    }
                    else
                    {
                        healthBarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

                        CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * 32), 0x100);
                        UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gEnemyParty[gBattlerPartyIndexes[i]], MON_DATA_HP), HP_CURRENT);
                        UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gEnemyParty[gBattlerPartyIndexes[i]], MON_DATA_MAX_HP), HP_MAX);
                    }
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthboxSpriteIds[i]);
                    UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]], HEALTHBOX_HEALTH_BAR);
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                        UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]], HEALTHBOX_NICK);
                }
            }
            gSprites[gHealthboxSpriteIds[i]].hMain_Data7 ^= 1;
        }
    }
}

#define tBattler                data[0]
#define tSummaryBarSpriteId     data[1]
#define tBallIconSpriteId(n)    data[3 + n]
#define tIsBattleStart          data[10]
#define tBlend                  data[15]

u8 CreatePartyStatusSummarySprites(u8 battler, struct HpAndStatus *partyInfo, bool8 skipPlayer, bool8 isBattleStart)
{
    bool8 isOpponent;
    s16 bar_X, bar_Y, bar_pos2_X, bar_data0;
    s32 i, j, var;
    u8 summaryBarSpriteId;
    u8 ballIconSpritesIds[PARTY_SIZE];
    u8 taskId;

    if (!skipPlayer || GetBattlerPosition(battler) != B_POSITION_OPPONENT_RIGHT)
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            isOpponent = FALSE;
            bar_X = 136, bar_Y = 96;
            bar_pos2_X = 100;
            bar_data0 = -5;
        }
        else
        {
            isOpponent = TRUE;

            if (!skipPlayer || !IsDoubleBattle())
                bar_X = 104, bar_Y = 40;
            else
                bar_X = 104, bar_Y = 16;

            bar_pos2_X = -100;
            bar_data0 = 5;
        }
    }
    else
    {
        isOpponent = TRUE;
        bar_X = 104, bar_Y = 40;
        bar_pos2_X = -100;
        bar_data0 = 5;
    }

    LoadCompressedSpriteSheetUsingHeap(&sStatusSummaryBarSpriteSheet);
    LoadSpriteSheet(&sStatusSummaryBallsSpriteSheet);
    LoadSpritePalette(&sStatusSummaryBarSpritePal);
    LoadSpritePalette(&sStatusSummaryBallsSpritePal);

    summaryBarSpriteId = CreateSprite(&sStatusSummaryBarSpriteTemplates[isOpponent], bar_X, bar_Y, 10);
    SetSubspriteTables(&gSprites[summaryBarSpriteId], sStatusSummaryBar_SubspriteTable_Enter);
    gSprites[summaryBarSpriteId].x2 = bar_pos2_X;
    gSprites[summaryBarSpriteId].data[0] = bar_data0;

    if (isOpponent)
    {
        gSprites[summaryBarSpriteId].x -= 96;
        gSprites[summaryBarSpriteId].oam.matrixNum = ST_OAM_HFLIP;
    }
    else
    {
        gSprites[summaryBarSpriteId].x += 96;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        ballIconSpritesIds[i] = CreateSpriteAtEnd(&sStatusSummaryBallsSpriteTemplates[isOpponent], bar_X, bar_Y - 4, 9);

        if (!isBattleStart)
            gSprites[ballIconSpritesIds[i]].callback = SpriteCB_StatusSummaryBalls_OnSwitchout;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].x2 = 0;
            gSprites[ballIconSpritesIds[i]].y2 = 0;
        }

        gSprites[ballIconSpritesIds[i]].data[0] = summaryBarSpriteId;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].x += 10 * i + 24;
            gSprites[ballIconSpritesIds[i]].data[1] = i * 7 + 10;
            gSprites[ballIconSpritesIds[i]].x2 = 120;
        }
        else
        {
            gSprites[ballIconSpritesIds[i]].x -= 10 * (5 - i) + 24;
            gSprites[ballIconSpritesIds[i]].data[1] = (6 - i) * 7 + 10;
            gSprites[ballIconSpritesIds[i]].x2 = -120;
        }

        gSprites[ballIconSpritesIds[i]].data[2] = isOpponent;
    }

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (partyInfo[i].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data[7] = 1;
                }
                else if (partyInfo[i].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0)
                {
                    // mon with major status
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
            }
        }
        else
        {
            for (i = 0, var = PARTY_SIZE - 1, j = 0; j < PARTY_SIZE; j++)
            {
                if (partyInfo[j].hp == HP_EMPTY_SLOT)
                {
                     // empty slot or an egg
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data[7] = 1;
                    var--;
                    continue;
                }
                else if (partyInfo[j].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaLostPlayerMons & gBitTable[j])
                {
                    // fainted arena mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0)
                {
                    // mon with primary status
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
                i++;
            }
        }
    }
    else
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS))
        {
            for (var = PARTY_SIZE - 1, i = 0; i < PARTY_SIZE; i++)
            {
                if (partyInfo[i].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data[7] = 1;
                }
                else if (partyInfo[i].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0)
                {
                    // mon with primary status
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 2;
                }
                var--;
            }
        }
        else
        {
            for (var = 0, i = 0, j = 0; j < PARTY_SIZE; j++)
            {
                if (partyInfo[j].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data[7] = 1;
                    i++;
                    continue;
                }
                else if (partyInfo[j].hp == 0)
                {
                     // fainted mon
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaLostOpponentMons & gBitTable[j])
                {
                     // fainted arena mon
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0)
                {
                     // mon with primary status
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 2;
                }
                var++;
            }
        }
    }

    taskId = CreateTask(TaskDummy, 5);
    gTasks[taskId].tBattler = battler;
    gTasks[taskId].tSummaryBarSpriteId = summaryBarSpriteId;

    for (i = 0; i < PARTY_SIZE; i++)
        gTasks[taskId].tBallIconSpriteId(i) = ballIconSpritesIds[i];

    gTasks[taskId].tIsBattleStart = isBattleStart;

    if (isBattleStart)
    {
        gBattleSpritesDataPtr->animationData->field_9_x1C++;
    }

    PlaySE12WithPanning(SE_BALL_TRAY_ENTER, 0);
    return taskId;
}

// Slide the party summary tray back offscreen
void Task_HidePartyStatusSummary(u8 taskId)
{
    u8 ballIconSpriteIds[PARTY_SIZE];
    bool8 isBattleStart;
    u8 summaryBarSpriteId;
    u8 battler;
    s32 i;

    isBattleStart = gTasks[taskId].tIsBattleStart;
    summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;
    battler = gTasks[taskId].tBattler;

    for (i = 0; i < PARTY_SIZE; i++)
        ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));

    gTasks[taskId].tBlend = 16;

    for (i = 0; i < PARTY_SIZE; i++)
        gSprites[ballIconSpriteIds[i]].oam.objMode = ST_OAM_OBJ_BLEND;

    gSprites[summaryBarSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;

    if (isBattleStart)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            {
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[1] = 7 * i;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[3] = 0;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[4] = 0;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].callback = SpriteCB_StatusSummaryBalls_Exit;
            }
            else
            {
                gSprites[ballIconSpriteIds[i]].data[1] = 7 * i;
                gSprites[ballIconSpriteIds[i]].data[3] = 0;
                gSprites[ballIconSpriteIds[i]].data[4] = 0;
                gSprites[ballIconSpriteIds[i]].callback = SpriteCB_StatusSummaryBalls_Exit;
            }
        }
        gSprites[summaryBarSpriteId].data[0] /= 2;
        gSprites[summaryBarSpriteId].data[1] = 0;
        gSprites[summaryBarSpriteId].callback = SpriteCB_StatusSummaryBar_Exit;
        SetSubspriteTables(&gSprites[summaryBarSpriteId], sStatusSummaryBar_SubspriteTable_Exit);
        gTasks[taskId].func = Task_HidePartyStatusSummary_BattleStart_1;
    }
    else
    {
        gTasks[taskId].func = Task_HidePartyStatusSummary_DuringBattle;
    }
}

static void Task_HidePartyStatusSummary_BattleStart_1(u8 taskId)
{
    if ((gTasks[taskId].data[11]++ % 2) == 0)
    {
        if (--gTasks[taskId].tBlend < 0)
            return;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
    }
    if (gTasks[taskId].tBlend == 0)
        gTasks[taskId].func = Task_HidePartyStatusSummary_BattleStart_2;
}

static void Task_HidePartyStatusSummary_BattleStart_2(u8 taskId)
{
    u8 ballIconSpriteIds[PARTY_SIZE];
    s32 i;

    u8 battler = gTasks[taskId].tBattler;
    if (--gTasks[taskId].tBlend == -1)
    {
        u8 summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;

        for (i = 0; i < PARTY_SIZE; i++)
            ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

        gBattleSpritesDataPtr->animationData->field_9_x1C--;
        if (gBattleSpritesDataPtr->animationData->field_9_x1C == 0)
        {
            DestroySpriteAndFreeResources(&gSprites[summaryBarSpriteId]);
            DestroySpriteAndFreeResources(&gSprites[ballIconSpriteIds[0]]);
        }
        else
        {
            FreeSpriteOamMatrix(&gSprites[summaryBarSpriteId]);
            DestroySprite(&gSprites[summaryBarSpriteId]);
            FreeSpriteOamMatrix(&gSprites[ballIconSpriteIds[0]]);
            DestroySprite(&gSprites[ballIconSpriteIds[0]]);
        }

        for (i = 1; i < PARTY_SIZE; i++)
            DestroySprite(&gSprites[ballIconSpriteIds[i]]);
    }
    else if (gTasks[taskId].tBlend == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

static void Task_HidePartyStatusSummary_DuringBattle(u8 taskId)
{
    u8 ballIconSpriteIds[PARTY_SIZE];
    s32 i;
    u8 battler = gTasks[taskId].tBattler;

    if (--gTasks[taskId].tBlend >= 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
    }
    else if (gTasks[taskId].tBlend == -1)
    {
        u8 summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;

        for (i = 0; i < PARTY_SIZE; i++)
            ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

        DestroySpriteAndFreeResources(&gSprites[summaryBarSpriteId]);
        DestroySpriteAndFreeResources(&gSprites[ballIconSpriteIds[0]]);

        for (i = 1; i < PARTY_SIZE; i++)
            DestroySprite(&gSprites[ballIconSpriteIds[i]]);
    }
    else if (gTasks[taskId].tBlend == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

#undef tBattler
#undef tSummaryBarSpriteId
#undef tBallIconSpriteId
#undef tIsBattleStart
#undef tBlend

static void SpriteCB_StatusSummaryBar_Enter(struct Sprite *sprite)
{
    if (sprite->x2 != 0)
        sprite->x2 += sprite->data[0];
}

static void SpriteCB_StatusSummaryBar_Exit(struct Sprite *sprite)
{
    sprite->data[1] += 32;
    if (sprite->data[0] > 0)
        sprite->x2 += sprite->data[1] >> 4;
    else
        sprite->x2 -= sprite->data[1] >> 4;
    sprite->data[1] &= 0xF;
}

static void SpriteCB_StatusSummaryBalls_Enter(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;
    s8 pan;

    if (sprite->data[1] > 0)
    {
        sprite->data[1]--;
        return;
    }

    var1 = sprite->data[2];
    var2 = sprite->data[3];
    var2 += 56;
    sprite->data[3] = var2 & 0xFFF0;

    if (var1 != 0)
    {
        sprite->x2 += var2 >> 4;
        if (sprite->x2 > 0)
            sprite->x2 = 0;
    }
    else
    {
        sprite->x2 -= var2 >> 4;
        if (sprite->x2 < 0)
            sprite->x2 = 0;
    }

    if (sprite->x2 == 0)
    {
        pan = SOUND_PAN_TARGET;
        if (var1 != 0)
            pan = SOUND_PAN_ATTACKER;

        if (sprite->data[7] != 0)
            PlaySE2WithPanning(SE_BALL_TRAY_EXIT, pan);
        else
            PlaySE1WithPanning(SE_BALL_TRAY_BALL, pan);

        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBalls_Exit(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;

    if (sprite->data[1] > 0)
    {
        sprite->data[1]--;
        return;
    }
    var1 = sprite->data[2];
    var2 = sprite->data[3];
    var2 += 56;
    sprite->data[3] = var2 & 0xFFF0;
    if (var1 != 0)
        sprite->x2 += var2 >> 4;
    else
        sprite->x2 -= var2 >> 4;
    if (sprite->x2 + sprite->x > 248
     || sprite->x2 + sprite->x < -8)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBalls_OnSwitchout(struct Sprite *sprite)
{
    u8 barSpriteId = sprite->data[0];

    sprite->x2 = gSprites[barSpriteId].x2;
    sprite->y2 = gSprites[barSpriteId].y2;
}

void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId)
{
    s32 maxHp, currHp;
    u8 battler = gSprites[healthboxSpriteId].hMain_Battler;

    if (elementId == HEALTHBOX_ALL && !IsDoubleBattle())
        GetBattlerSide(battler); // Pointless function call.

    if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
    {
        u8 isDoubles;

        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_CURRENT_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_HP), HP_CURRENT);
        if (elementId == HEALTHBOX_MAX_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_MAX_HP), HP_MAX);
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(battler, healthboxSpriteId, maxHp, currHp, 0);
            MoveBattleBar(battler, healthboxSpriteId, HEALTH_BAR, 0);
        }
        isDoubles = IsDoubleBattle();
        if (!isDoubles && (elementId == HEALTHBOX_EXP_BAR || elementId == HEALTHBOX_ALL))
        {
            u16 species;
            u32 exp, currLevelExp;
            s32 currExpBarValue, maxExpBarValue;
            u8 level;

            LoadBattleBarGfx(3);
            species = GetMonData(mon, MON_DATA_SPECIES);
            level = GetMonData(mon, MON_DATA_LEVEL);
            exp = GetMonData(mon, MON_DATA_EXP);
            currLevelExp = gExperienceTables[gSpeciesInfo[species].growthRate][level];
            currExpBarValue = exp - currLevelExp;
            maxExpBarValue = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1] - currLevelExp;
            SetBattleBarStruct(battler, healthboxSpriteId, maxExpBarValue, currExpBarValue, isDoubles);
            MoveBattleBar(battler, healthboxSpriteId, EXP_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT)
            AddTextPrinterAndCreateWindowOnHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT || elementId == HEALTHBOX_SAFARI_BALLS_TEXT)
            UpdateLeftNoOfBallsTextOnHealthbox(healthboxSpriteId);
    }
    else
    {
        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(battler, healthboxSpriteId, maxHp, currHp, 0);
            MoveBattleBar(battler, healthboxSpriteId, HEALTH_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
    }
}

#define B_EXPBAR_PIXELS 64
#define B_HEALTHBAR_PIXELS 48

s32 MoveBattleBar(u8 battler, u8 healthboxSpriteId, u8 whichBar, u8 unused)
{
    s32 currentBarValue;

    if (whichBar == HEALTH_BAR) // health bar
    {
        currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battler].maxValue,
                    gBattleSpritesDataPtr->battleBars[battler].oldValue,
                    gBattleSpritesDataPtr->battleBars[battler].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battler].currValue,
                    B_HEALTHBAR_PIXELS / 8, 1);
    }
    else // exp bar
    {
        u16 expFraction = GetScaledExpFraction(gBattleSpritesDataPtr->battleBars[battler].oldValue,
                    gBattleSpritesDataPtr->battleBars[battler].receivedValue,
                    gBattleSpritesDataPtr->battleBars[battler].maxValue, 8);
        if (expFraction == 0)
            expFraction = 1;
        expFraction = abs(gBattleSpritesDataPtr->battleBars[battler].receivedValue / expFraction);

        currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battler].maxValue,
                    gBattleSpritesDataPtr->battleBars[battler].oldValue,
                    gBattleSpritesDataPtr->battleBars[battler].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battler].currValue,
                    B_EXPBAR_PIXELS / 8, expFraction);
    }

    if (whichBar == EXP_BAR || (whichBar == HEALTH_BAR && !gBattleSpritesDataPtr->battlerData[battler].hpNumbersNoBars))
        MoveBattleBarGraphically(battler, whichBar);

    if (currentBarValue == -1)
        gBattleSpritesDataPtr->battleBars[battler].currValue = 0;

    return currentBarValue;
}

static void MoveBattleBarGraphically(u8 battler, u8 whichBar)
{
    u8 array[8];
    u8 filledPixelsCount, level;
    u8 barElementId;
    u8 i;

    switch (whichBar)
    {
    case HEALTH_BAR:
        filledPixelsCount = CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battler].maxValue,
                            gBattleSpritesDataPtr->battleBars[battler].oldValue,
                            gBattleSpritesDataPtr->battleBars[battler].receivedValue,
                            &gBattleSpritesDataPtr->battleBars[battler].currValue,
                            array, B_HEALTHBAR_PIXELS / 8);

        if (filledPixelsCount > (B_HEALTHBAR_PIXELS * 50 / 100)) // more than 50 % hp
            barElementId = HEALTHBOX_GFX_HP_BAR_GREEN;
        else if (filledPixelsCount > (B_HEALTHBAR_PIXELS * 20 / 100)) // more than 20% hp
            barElementId = HEALTHBOX_GFX_HP_BAR_YELLOW;
        else
            barElementId = HEALTHBOX_GFX_HP_BAR_RED; // 20 % or less

        for (i = 0; i < 6; i++)
        {
            u8 healthbarSpriteId = gSprites[gBattleSpritesDataPtr->battleBars[battler].healthboxSpriteId].hMain_HealthBarSpriteId;
            if (i < 2)
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + (gSprites[healthbarSpriteId].oam.tileNum + 2 + i) * TILE_SIZE_4BPP), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + 64 + (i + gSprites[healthbarSpriteId].oam.tileNum) * TILE_SIZE_4BPP), 32);
        }
        break;
    case EXP_BAR:
        CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battler].maxValue,
                    gBattleSpritesDataPtr->battleBars[battler].oldValue,
                    gBattleSpritesDataPtr->battleBars[battler].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battler].currValue,
                    array, B_EXPBAR_PIXELS / 8);
        level = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_LEVEL);
        if (level == MAX_LEVEL)
        {
            for (i = 0; i < 8; i++)
                array[i] = 0;
        }
        for (i = 0; i < 8; i++)
        {
            if (i < 4)
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + (gSprites[gBattleSpritesDataPtr->battleBars[battler].healthboxSpriteId].oam.tileNum + 0x24 + i) * TILE_SIZE_4BPP), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + 0xB80 + (i + gSprites[gBattleSpritesDataPtr->battleBars[battler].healthboxSpriteId].oam.tileNum) * TILE_SIZE_4BPP), 32);
        }
        break;
    }
}

static s32 CalcNewBarValue(s32 maxValue, s32 oldValue, s32 receivedValue, s32 *currValue, u8 scale, u16 toAdd)
{
    s32 ret, newValue;
    scale *= 8;

    if (*currValue == -32768) // first function call
    {
        if (maxValue < scale)
            *currValue = Q_24_8(oldValue);
        else
            *currValue = oldValue;
    }

    newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    if (maxValue < scale)
    {
        if (newValue == Q_24_8_TO_INT(*currValue) && (*currValue & 0xFF) == 0)
            return -1;
    }
    else
    {
        if (newValue == *currValue) // we're done, the bar's value has been updated
            return -1;
    }

    if (maxValue < scale) // handle cases of max var having less pixels than the whole bar
    {
        s32 toAdd = Q_24_8(maxValue) / scale;

        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            if (ret >= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
        else // move bar left
        {
            *currValue -= toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            // try round up
            if ((*currValue & 0xFF) > 0)
                ret++;
            if (ret <= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
    }
    else
    {
        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            if (*currValue > newValue)
                *currValue = newValue;
            ret = *currValue;
        }
        else // move bar left
        {
            *currValue -= toAdd;
            if (*currValue < newValue)
                *currValue = newValue;
            ret = *currValue;
        }
    }

    return ret;
}

static u8 CalcBarFilledPixels(s32 maxValue, s32 oldValue, s32 receivedValue, s32 *currValue, u8 *pixelsArray, u8 scale)
{
    u8 pixels, filledPixels, totalPixels;
    u8 i;

    s32 newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    totalPixels = scale * 8;

    for (i = 0; i < scale; i++)
        pixelsArray[i] = 0;

    if (maxValue < totalPixels)
        pixels = (*currValue * totalPixels / maxValue) >> 8;
    else
        pixels = *currValue * totalPixels / maxValue;

    filledPixels = pixels;

    if (filledPixels == 0 && newValue > 0)
    {
        pixelsArray[0] = 1;
        filledPixels = 1;
    }
    else
    {
        for (i = 0; i < scale; i++)
        {
            if (pixels >= 8)
            {
                pixelsArray[i] = 8;
            }
            else
            {
                pixelsArray[i] = pixels;
                break;
            }
            pixels -= 8;
        }
    }

    return filledPixels;
}

// These two functions seem as if they were made for testing the health bar.
static s16 UNUSED Debug_TestHealthBar(struct TestingBar *barInfo, s32 *currValue, u16 *dest, s32 unused)
{
    s16 ret, var;

    ret = CalcNewBarValue(barInfo->maxValue,
                    barInfo->oldValue,
                    barInfo->receivedValue,
                    currValue, B_HEALTHBAR_PIXELS / 8, 1);
    Debug_TestHealthBar_Helper(barInfo, currValue, dest);

    if (barInfo->maxValue < B_HEALTHBAR_PIXELS)
        var = *currValue >> 8;
    else
        var = *currValue;

    DummiedOutFunction(barInfo->maxValue, var, unused);

    return ret;
}

static void Debug_TestHealthBar_Helper(struct TestingBar *barInfo, s32 *currValue, u16 *dest)
{
    u8 pixels[6];
    u16 src[6];
    u8 i;

    CalcBarFilledPixels(barInfo->maxValue, barInfo->oldValue,
                barInfo->receivedValue, currValue, pixels, B_HEALTHBAR_PIXELS / 8);

    for (i = 0; i < 6; i++)
        src[i] = (barInfo->unkC_0 << 12) | (barInfo->unk10 + pixels[i]);

    CpuCopy16(src, dest, sizeof(src));
}

static u8 GetScaledExpFraction(s32 oldValue, s32 receivedValue, s32 maxValue, u8 scale)
{
    s32 newVal, result;
    s8 oldToMax, newToMax;

    scale *= 8;
    newVal = oldValue - receivedValue;

    if (newVal < 0)
        newVal = 0;
    else if (newVal > maxValue)
        newVal = maxValue;

    oldToMax = oldValue * scale / maxValue;
    newToMax = newVal * scale / maxValue;
    result = oldToMax - newToMax;

    return abs(result);
}

u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale)
{
    u8 result = hp * scale / maxhp;

    if (result == 0 && hp > 0)
        return 1;

    return result;
}

u8 GetHPBarLevel(s16 hp, s16 maxhp)
{
    u8 result;

    if (hp == maxhp)
    {
        result = HP_BAR_FULL;
    }
    else
    {
        u8 fraction = GetScaledHPFraction(hp, maxhp, B_HEALTHBAR_PIXELS);
        if (fraction > (B_HEALTHBAR_PIXELS * 50 / 100)) // more than 50 % hp
            result = HP_BAR_GREEN;
        else if (fraction > (B_HEALTHBAR_PIXELS * 20 / 100)) // more than 20% hp
            result = HP_BAR_YELLOW;
        else if (fraction > 0)
            result = HP_BAR_RED;
        else
            result = HP_BAR_EMPTY;
    }

    return result;
}

__attribute__((naked)) void UpdateNickInHealthbox(u8 healthboxSpriteId, struct Pokemon *mon)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	ldr r5, _08073B64\n\t"
        "	ldr r1, _08073B68\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringCopy\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl StringAppend\n\t"
        "	adds r7, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonGender\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r0, #0x1d\n\t"
        "	beq _08073B40\n\t"
        "	cmp r0, #0x20\n\t"
        "	bne _08073B56\n\t"
        "_08073B40:\n\t"
        "	lsls r1, r2, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #1\n\t"
        "	ldr r0, _08073B6C\n\t"
        "	adds r1, r1, r0\n\t"
        "	mov r0, sp\n\t"
        "	bl StringCompare\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08073B56\n\t"
        "	movs r5, #0x64\n\t"
        "_08073B56:\n\t"
        "	cmp r5, #0\n\t"
        "	beq _08073B74\n\t"
        "	cmp r5, #0xfe\n\t"
        "	beq _08073B7C\n\t"
        "	ldr r1, _08073B70\n\t"
        "	b _08073B7E\n\t"
        "	.align 2, 0\n\t"
        "_08073B64: .4byte gDisplayedStringBattle\n\t"
        "_08073B68: .4byte gText_HealthboxNickname\n\t"
        "_08073B6C: .4byte gSpeciesNames\n\t"
        "_08073B70: .4byte gText_HealthboxGender_None\n\t"
        "_08073B74:\n\t"
        "	ldr r1, _08073B78\n\t"
        "	b _08073B7E\n\t"
        "	.align 2, 0\n\t"
        "_08073B78: .4byte gText_HealthboxGender_Male\n\t"
        "_08073B7C:\n\t"
        "	ldr r1, _08073C20\n\t"
        "_08073B7E:\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r1, _08073C24\n\t"
        "	mov r2, sl\n\t"
        "	lsls r5, r2, #4\n\t"
        "	adds r0, r5, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x3a]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerPosition\n\t"
        "	ldr r1, _08073C28\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r1, #0xba\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #7\n\t"
        "	movs r0, #0xa4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r7, r0, r1\n\t"
        "	ldr r4, _08073C2C\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringLength\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	mov r6, r8\n\t"
        "	subs r6, #6\n\t"
        "	movs r1, #0\n\t"
        "	mov sb, r1\n\t"
        "	mov r2, r8\n\t"
        "	adds r0, r2, r4\n\t"
        "	movs r2, #6\n\t"
        "	subs r2, r2, r6\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	bl StringFill\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringLength\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ldr r1, _08073C30\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #7\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl RenderTextFont9\n\t"
        "	movs r6, #3\n\t"
        "	cmp sb, r8\n\t"
        "	bhs _08073C72\n\t"
        "_08073BFE:\n\t"
        "	ldr r0, _08073C2C\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x37\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x13\n\t"
        "	bls _08073C1C\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x79\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x13\n\t"
        "	bhi _08073C34\n\t"
        "_08073C1C:\n\t"
        "	movs r0, #0x2c\n\t"
        "	b _08073C52\n\t"
        "	.align 2, 0\n\t"
        "_08073C20: .4byte gText_HealthboxGender_Female\n\t"
        "_08073C24: .4byte gSprites\n\t"
        "_08073C28: .4byte gMonSpritesGfxPtr\n\t"
        "_08073C2C: .4byte gDisplayedStringBattle\n\t"
        "_08073C30: .4byte 0xFFFA0000\n\t"
        "_08073C34:\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x4b\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _08073C4C\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x65\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _08073C50\n\t"
        "_08073C4C:\n\t"
        "	movs r0, #0x2d\n\t"
        "	b _08073C52\n\t"
        "_08073C50:\n\t"
        "	movs r0, #0x2b\n\t"
        "_08073C52:\n\t"
        "	bl GetHealthboxElementGfxPtr\n\t"
        "	mov r2, sb\n\t"
        "	lsls r1, r2, #6\n\t"
        "	adds r1, r7, r1\n\t"
        "	ldr r2, _08073CE8\n\t"
        "	bl CpuSet\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	adds r6, #1\n\t"
        "	cmp sb, r8\n\t"
        "	blo _08073BFE\n\t"
        "_08073C72:\n\t"
        "	ldr r1, _08073CEC\n\t"
        "	mov r2, sl\n\t"
        "	adds r0, r5, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #0x3a]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08073CF4\n\t"
        "	bl IsDoubleBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08073CF4\n\t"
        "	movs r6, #0\n\t"
        "	cmp r6, r8\n\t"
        "	bge _08073D64\n\t"
        "	ldr r0, _08073CF0\n\t"
        "	mov sb, r0\n\t"
        "	ldr r5, _08073CE8\n\t"
        "_08073CA2:\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	lsls r0, r0, #0x16\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r1, r6, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #5\n\t"
        "	mov r2, sb\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl CpuSet\n\t"
        "	adds r7, #0x20\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	lsls r0, r0, #0x16\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0xa\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #5\n\t"
        "	mov r2, sb\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl CpuSet\n\t"
        "	adds r7, #0x20\n\t"
        "	adds r6, #1\n\t"
        "	cmp r6, r8\n\t"
        "	blt _08073CA2\n\t"
        "	b _08073D64\n\t"
        "	.align 2, 0\n\t"
        "_08073CE8: .4byte 0x04000008\n\t"
        "_08073CEC: .4byte gSprites\n\t"
        "_08073CF0: .4byte 0x06010000\n\t"
        "_08073CF4:\n\t"
        "	ldr r1, _08073D74\n\t"
        "	mov r2, sl\n\t"
        "	adds r0, r5, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldrh r0, [r5, #0x3a]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08073D12\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "_08073D12:\n\t"
        "	movs r6, #0\n\t"
        "	cmp r6, r8\n\t"
        "	bge _08073D64\n\t"
        "	ldr r1, _08073D78\n\t"
        "	mov sl, r1\n\t"
        "	ldr r2, _08073D7C\n\t"
        "	mov sb, r2\n\t"
        "_08073D20:\n\t"
        "	ldrh r0, [r5, #4]\n\t"
        "	lsls r0, r0, #0x16\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r4, r6, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #5\n\t"
        "	mov r2, sl\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r0, r7, #0\n\t"
        "	mov r2, sb\n\t"
        "	bl CpuSet\n\t"
        "	adds r7, #0x20\n\t"
        "	ldrh r0, [r5, #4]\n\t"
        "	lsls r0, r0, #0x16\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #9\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #5\n\t"
        "	mov r2, sl\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r0, r7, #0\n\t"
        "	mov r2, sb\n\t"
        "	bl CpuSet\n\t"
        "	adds r7, #0x20\n\t"
        "	adds r6, r4, #0\n\t"
        "	cmp r6, r8\n\t"
        "	blt _08073D20\n\t"
        "_08073D64:\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08073D74: .4byte gSprites\n\t"
        "_08073D78: .4byte 0x06010000\n\t"
        "_08073D7C: .4byte 0x04000008\n\t"
        ".syntax divided\n\t"
    );
}
