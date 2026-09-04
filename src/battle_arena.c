#include "global.h"
#include "battle.h"
#include "battle_arena.h"
#include "battle_script_commands.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "item.h"
#include "m4a.h"
#include "palette.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "util.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/songs.h"
#include "constants/vars.h"

#define BATTLE_ARENA_DATA __attribute__((section(".rodata.battle_arena_data")))

extern void (*const sArenaFunctions[])(void);
asm("sArenaFunctions = gUnknown_85DD7BC");
extern const s8 sArenaMindRatings[];
asm("sArenaMindRatings = gUnknown_85DD5F8");
extern const u16 sArenaShortStreakPrizeItems[];
asm("sArenaShortStreakPrizeItems = gUnknown_85DD7D8");
extern const u16 sArenaLongStreakPrizeItems[];
asm("sArenaLongStreakPrizeItems = gUnknown_85DD7E4");
extern const struct SpriteTemplate sArenaJudgmentIconSpriteTemplate;
asm("sArenaJudgmentIconSpriteTemplate = gUnknown_85DD794");
extern const struct CompressedSpriteSheet sArenaJudgmentSymbolsSpriteSheet[];
asm("sArenaJudgmentSymbolsSpriteSheet = gUnknown_85DD7AC");
extern const u32 sArenaJudgmentSymbolsPalette[];
asm("sArenaJudgmentSymbolsPalette = gUnknown_8D855CC");
extern const u8 sArenaTextPlayerMon1Name[];
asm("sArenaTextPlayerMon1Name = gUnknown_85ABD3C + 0x5E");
extern const u8 sArenaTextVs[];
asm("sArenaTextVs = gUnknown_85ABD3C + 0x61");
extern const u8 sArenaTextOpponentMon1Name[];
asm("sArenaTextOpponentMon1Name = gUnknown_85ABD3C + 0x64");
extern const u8 sArenaTextMind[];
asm("sArenaTextMind = gUnknown_85ABD3C + 0x67");
extern const u8 sArenaTextSkill[];
asm("sArenaTextSkill = gUnknown_85ABD3C + 0x6B");
extern const u8 sArenaTextBody[];
asm("sArenaTextBody = gUnknown_85ABD3C + 0x6E");
extern const u8 sArenaTextJudgment[];
asm("sArenaTextJudgment = gUnknown_85ABD3C + 0x72");

extern void TryGetStatusString(const u8 *text);
extern void sub_0814FA04(const u8 *text, u8 windowId);
extern void sub_081A482C(void);
void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler);


void CallBattleArenaFunction(void)
{
    sArenaFunctions[gSpecialVar_0x8004]();
}


u8 BattleArena_ShowJudgmentWindow(u8 *state)
{
    int i;
    s32 x;
    u8 result = 0;

    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 0, 8, 0);
        SetGpuReg(0x48, 0x3F3E);
        LoadCompressedSpriteSheet(sArenaJudgmentSymbolsSpriteSheet);
        LoadCompressedPalette(sArenaJudgmentSymbolsPalette, 0x1F0, 0x20);
        gBattle_WIN0H = 0xFF;
        gBattle_WIN0V = 0x70;
        (*state)++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            HandleBattleWindow(6, 0, 23, 13, 0);
            (*state)++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattleTextBuff1[0] = 0xA1;
            gBattleTextBuff1[1] = 0xFF;
            gBattleTextBuff2[0] = 0xA1;
            gBattleTextBuff2[1] = 0xFF;
            TryGetStatusString(sArenaTextPlayerMon1Name);
            sub_0814FA04(gDisplayedStringBattle, 15);
            sub_0814FA04(sArenaTextVs, 16);
            TryGetStatusString(sArenaTextOpponentMon1Name);
            sub_0814FA04(gDisplayedStringBattle, 17);
            sub_0814FA04(sArenaTextMind, 18);
            sub_0814FA04(sArenaTextSkill, 19);
            sub_0814FA04(sArenaTextBody, 20);
            TryGetStatusString(sArenaTextJudgment);
            sub_0814FA04(gDisplayedStringBattle, 21);
            (*state)++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetGpuReg(0x48, 0x3F3F);
            for (x = 64 << 16, i = 7; i >= 0; x += 16 << 16, i--)
            {
                u8 spriteId = CreateSprite(&sArenaJudgmentIconSpriteTemplate, x >> 16, 84, 0);
                StartSpriteAnim(&gSprites[spriteId], 3);
            }
            result = 1;
            (*state)++;
        }
        break;
    case 4:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 40, 0, 0);
        ShowJudgmentSprite(160, 40, 0, 1);
        TryGetStatusString(sArenaTextJudgment);
        sub_0814FA04(gDisplayedStringBattle, 21);
        (*state)++;
        result = 1;
        break;
    case 5:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 56, 1, 0);
        ShowJudgmentSprite(160, 56, 1, 1);
        TryGetStatusString(sArenaTextJudgment);
        sub_0814FA04(gDisplayedStringBattle, 21);
        (*state)++;
        result = 1;
        break;
    case 6:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 72, 2, 0);
        ShowJudgmentSprite(160, 72, 2, 1);
        TryGetStatusString(sArenaTextJudgment);
        sub_0814FA04(gDisplayedStringBattle, 21);
        (*state)++;
        result = 1;
        break;
    case 7:
        PlaySE(SE_ARENA_TIMEUP2);
        if (gBattleTextBuff1[0] > gBattleTextBuff2[0])
        {
            result = 2;
            gBattleScripting.battler = 0;
        }
        else if (gBattleTextBuff1[0] < gBattleTextBuff2[0])
        {
            result = 3;
            gBattleScripting.battler = 1;
        }
        else
        {
            result = 4;
        }
        (*state)++;
        break;
    case 8:
        (*state)++;
        break;
    case 9:
        SetGpuReg(0x48, 0x3F3E);
        HandleBattleWindow(6, 0, 23, 13, 1);
        CopyBgTilemapBufferToVram(0);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 8, 0, 0);
        (*state)++;
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            SetGpuReg(0x48, 0x3F3F);
            FreeSpriteTilesByTag(1000);
            result = 1;
            (*state)++;
        }
        break;
    }

    return result;
}


void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler)
{
    int animNum = 0;
    int pointsPlayer = 0;
    int pointsOpponent = 0;
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    switch (category)
    {
    case 0:
        pointsPlayer = mindPoints[battler];
        pointsOpponent = mindPoints[BATTLE_OPPOSITE(battler)];
        break;
    case 1:
        pointsPlayer = skillPoints[battler];
        pointsOpponent = skillPoints[BATTLE_OPPOSITE(battler)];
        break;
    case 2:
        pointsPlayer = gBattleMons[battler].hp * 100 / hpAtStart[battler];
        pointsOpponent = gBattleMons[BATTLE_OPPOSITE(battler)].hp * 100 / hpAtStart[BATTLE_OPPOSITE(battler)];
        break;
    }

    if (pointsPlayer > pointsOpponent)
    {
        animNum = 2;
        if (battler != 0)
            gBattleTextBuff2[0] += 2;
        else
            gBattleTextBuff1[0] += 2;
    }
    else if (pointsPlayer == pointsOpponent)
    {
        animNum = 1;
        if (battler != 0)
            gBattleTextBuff2[0] += 1;
        else
            gBattleTextBuff1[0] += 1;
    }
    else
    {
        animNum = 0;
    }

    pointsPlayer = CreateSprite(&sArenaJudgmentIconSpriteTemplate, x, y, 0);
    StartSpriteAnim(&gSprites[pointsPlayer], animNum);
}


void SpriteCB_JudgmentIcon(struct Sprite *sprite)
{
    if (gBattleCommunication[0] > 8)
        DestroySprite(sprite);
}


void BattleArena_InitPoints(void)
{
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    mindPoints[0] = 0;
    mindPoints[1] = 0;
    skillPoints[0] = 0;
    skillPoints[1] = 0;
    hpAtStart[0] = gBattleMons[0].hp;
    hpAtStart[1] = gBattleMons[1].hp;
}


void BattleArena_AddMindPoints(u8 battler)
{
    gBattleStruct->arenaMindPoints[battler] += sArenaMindRatings[gCurrentMove];
}


void BattleArena_AddSkillPoints(u8 battler)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    if (gHitMarker & HITMARKER_OBEYS)
    {
        u8 *failedMoveBits = &gBattleStruct->alreadyStatusedMoveAttempt;

        if (*failedMoveBits & gBitTable[battler])
        {
            *failedMoveBits &= ~(gBitTable[battler]);
            skillPoints[battler] -= 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        {
            if (!(gMoveResultFlags & MOVE_RESULT_MISSED)
             || gBattleCommunication[MISS_TYPE] != B_MSG_PROTECTED)
                skillPoints[battler] -= 2;
        }
        else if ((gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
              && (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE))
        {
            skillPoints[battler] += 1;
        }
        else if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
        {
            skillPoints[battler] += 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
        {
            skillPoints[battler] -= 1;
        }
        else if (!gProtectStructs[battler].protected)
        {
            skillPoints[battler] += 1;
        }
    }
}


void BattleArena_DeductSkillPoints(u8 battler, u16 stringId)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    switch (stringId)
    {
    case STRINGID_PKMNSXMADEYUSELESS:
    case STRINGID_PKMNSXMADEITINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSFLINCHING:
    case STRINGID_PKMNSXBLOCKSY2:
    case STRINGID_PKMNSXPREVENTSYLOSS:
    case STRINGID_PKMNSXMADEYINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSBURNS:
    case STRINGID_PKMNSXBLOCKSY:
    case STRINGID_PKMNPROTECTEDBY:
    case STRINGID_PKMNPREVENTSUSAGE:
    case STRINGID_PKMNRESTOREDHPUSING:
    case STRINGID_PKMNPREVENTSPARALYSISWITH:
    case STRINGID_PKMNPREVENTSROMANCEWITH:
    case STRINGID_PKMNPREVENTSPOISONINGWITH:
    case STRINGID_PKMNPREVENTSCONFUSIONWITH:
    case STRINGID_PKMNRAISEDFIREPOWERWITH:
    case STRINGID_PKMNANCHORSITSELFWITH:
    case STRINGID_PKMNPREVENTSSTATLOSSWITH:
    case STRINGID_PKMNSTAYEDAWAKEUSING:
        skillPoints[battler] -= 3;
        break;
    }
}


void sub_081A545C(u8 battler)
{
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    hpAtStart[battler] = gBattleMons[battler].hp;
    if (hpAtStart[BATTLE_OPPOSITE(battler)] > gBattleMons[BATTLE_OPPOSITE(battler)].hp)
        hpAtStart[BATTLE_OPPOSITE(battler)] = gBattleMons[BATTLE_OPPOSITE(battler)].hp;
}


void InitArenaChallenge(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_OPEN;
    else
        isCurrent = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_50;
    if (!isCurrent)
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}


void GetArenaData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case ARENA_DATA_PRIZE:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaPrize;
        break;
    case ARENA_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
        break;
    case ARENA_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_OPEN;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_50;
        break;
    }
}


void SetArenaData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case ARENA_DATA_PRIZE:
        gSaveBlock2Ptr->frontier.arenaPrize = gSpecialVar_0x8006;
        break;
    case ARENA_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case ARENA_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_ARENA_OPEN;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~STREAK_ARENA_OPEN;
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_ARENA_50;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~STREAK_ARENA_50;
        }
        break;
    }
}


void sub_081A56B4(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    sub_081A482C();
}


void SetArenaPrize(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.arenaPrize = sArenaLongStreakPrizeItems[Random() % 9];
    else
        gSaveBlock2Ptr->frontier.arenaPrize = sArenaShortStreakPrizeItems[Random() % 6];
}


void GiveArenaPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.arenaPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.arenaPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.arenaPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}


void BufferArenaOpponentName(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}


void DrawArenaRefereeTextBox(void)
{
    u8 width = 22;
    u8 palNum = 7;
    u8 height;

    FillBgTilemapBufferRect(0, 0,     0,  14, 1,     6, palNum);
    FillBgTilemapBufferRect(0, 0,     29, 14, 1,     6, palNum);
    FillBgTilemapBufferRect(0, 0x31,  1,  14, 1,     1, palNum);
    height = 2;
    FillBgTilemapBufferRect(0, 0x32,  2,  14, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x33,  3,  14, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x34,  4,  14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x35,  26, 14, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x32,  27, 14, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x36,  28, 14, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x37,  1,  15, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x38,  2,  15, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x3B,  3,  15, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x39,  4,  15, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x43B, 26, 15, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x38,  27, 15, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x3A,  28, 15, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x37,  1,  16, 1,     height, palNum);
    FillBgTilemapBufferRect(0, 0x38,  2,  16, 1,     height, palNum);
    FillBgTilemapBufferRect(0, 0x3C,  3,  16, 1,     height, palNum);
    FillBgTilemapBufferRect(0, 0x39,  4,  16, width, height, palNum);
    FillBgTilemapBufferRect(0, 0x43C, 26, 16, 1,     height, palNum);
    FillBgTilemapBufferRect(0, 0x38,  27, 16, 1,     height, palNum);
    FillBgTilemapBufferRect(0, 0x3A,  28, 16, 1,     height, palNum);
    FillBgTilemapBufferRect(0, 0x37,  1,  18, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x38,  2,  18, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x83B, 3,  18, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x39,  4,  18, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0xC3B, 26, 18, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x38,  27, 18, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x3A,  28, 18, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x831, 1,  19, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x832, 2,  19, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 3,  19, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 4,  19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 26, 19, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x832, 27, 19, 1,     1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 28, 19, 1,     1, palNum);
}


void EraseArenaRefereeTextBox(void)
{
    u8 palNum = 0;
    u8 width = 26;
    u8 height;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}



BATTLE_ARENA_DATA const u8 gUnknown_85DD5F8[] = {
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01,
    0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xFF, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x01, 0x00, 0x01, 0x00, 0x01, 0xFF, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x0C, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x64, 0xD7, 0x5D, 0x08,
    0x6C, 0xD7, 0x5D, 0x08, 0x74, 0xD7, 0x5D, 0x08, 0x7C, 0xD7, 0x5D, 0x08,
};
BATTLE_ARENA_DATA const u8 gUnknown_85DD794[] = {
    0xE8, 0x03, 0xFF, 0xFF, 0x5C, 0xD7, 0x5D, 0x08, 0x84, 0xD7, 0x5D, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x10, 0xF3, 0x2B, 0x08, 0x89, 0x52, 0x1A, 0x08,
};
BATTLE_ARENA_DATA const u8 gUnknown_85DD7AC[] = {
    0xCC, 0x54, 0xD8, 0x08, 0x00, 0x02, 0xE8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
BATTLE_ARENA_DATA const u8 gUnknown_85DD7BC[] = {
    0xA5, 0x54, 0x1A, 0x08, 0x55, 0x55, 0x1A, 0x08, 0xED, 0x55, 0x1A, 0x08, 0xB5, 0x56, 0x1A, 0x08,
    0xF9, 0x56, 0x1A, 0x08, 0x79, 0x57, 0x1A, 0x08, 0xD1, 0x57, 0x1A, 0x08,
};
BATTLE_ARENA_DATA const u8 gUnknown_85DD7D8[] = {
    0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x43, 0x00, 0x42, 0x00, 0x46, 0x00,
};
BATTLE_ARENA_DATA const u8 gUnknown_85DD7E4[] = {
    0xB3, 0x00, 0xB4, 0x00, 0xB7, 0x00, 0xC8, 0x00, 0xB9, 0x00, 0xBB, 0x00, 0xC4, 0x00, 0xC6, 0x00,
    0xBA, 0x00, 0x00, 0x00,
};
