#include "global.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "frontier_util.h"
#include "item.h"
#include "string_util.h"
#include "constants/items.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/frontier_util.h"
#include "constants/trainers.h"

// This file's functions.
static void InitPalaceChallenge(void);
static void GetPalaceData(void);
static void SetPalaceData(void);
static void GetPalaceCommentId(void);
static void SetPalaceOpponent(void);
static void BufferOpponentIntroSpeech(void);
static void IncrementPalaceStreak(void);
static void SavePalaceChallenge(void);
static void SetRandomPalacePrize(void);
static void GivePalacePrize(void);

// JP keeps the dispatch table and prize/streak tables in ROM.
extern void (*const sBattlePalaceFunctions[])(void);
extern const u16 sBattlePalaceEarlyPrizes[6];
extern const u16 sBattlePalaceLatePrizes[9];
extern const u32 sWinStreakFlags[][2];
extern const u32 sWinStreakMasks[][2];

// JP asm name for the still-asm frontier save helper; US: SaveGameFrontier.
void sub_081A482C(void);

__attribute__((naked)) void CallBattlePalaceFunction(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _08195578\n\t"
        "	ldr r0, _0819557C\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "	pop {r0}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08195574(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08195578: .4byte sBattlePalaceFunctions\n\t"
        "_0819557C: .4byte 0x02037280\n\t"
        ".syntax divided\n\t"
    );
}

static void InitPalaceChallenge(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (!(gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}

static void GetPalaceData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case PALACE_DATA_PRIZE:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.palacePrize;
        break;
    case PALACE_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
        break;
    case PALACE_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    }
}

static void SetPalaceData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case PALACE_DATA_PRIZE:
        gSaveBlock2Ptr->frontier.palacePrize = gSpecialVar_0x8006;
        break;
    case PALACE_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case PALACE_DATA_WIN_STREAK_ACTIVE:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
        break;
    }
}

static void GetPalaceCommentId(void)
{
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < 50)
        gSpecialVar_Result = Random() % 3;
    else if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < 99)
        gSpecialVar_Result = 3;
    else
        gSpecialVar_Result = 4;
}

static void SetPalaceOpponent(void)
{
    gTrainerBattleOpponent_A = 5 *(Random() % 255) / 64u;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void BufferOpponentIntroSpeech(void)
{
    if (gTrainerBattleOpponent_A < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static void IncrementPalaceStreak(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < MAX_STREAK)
    {
        gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode]++;

        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][(lvlMode > gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode]) ? 1 : 0])
            gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    }
}

static void SavePalaceChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    sub_081A482C();
}

static void SetRandomPalacePrize(void)
{
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > 41)
        gSaveBlock2Ptr->frontier.palacePrize = sBattlePalaceLatePrizes[Random() % ARRAY_COUNT(sBattlePalaceLatePrizes)];
    else
        gSaveBlock2Ptr->frontier.palacePrize = sBattlePalaceEarlyPrizes[Random() % ARRAY_COUNT(sBattlePalaceEarlyPrizes)];
}

static void GivePalacePrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.palacePrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.palacePrize, gStringVar1);
        gSaveBlock2Ptr->frontier.palacePrize = 0;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}
