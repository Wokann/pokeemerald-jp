#ifndef POKEEMERALD_JP_DODRIO1_H
#define POKEEMERALD_JP_DODRIO1_H

#include "global.h"
#include "bg.h"
#include "dodrio_berry_picking.h"
#include "link.h"
#include "window.h"

// Dodrio berry-picking tables and window templates (0x82CB314..0x82CB67C)

struct DodrioGame;

extern const u8 gUnknown_85CCA7C[]; // JP text region (asm); sRecordsLabels point into it

void DoGameIntro(void);
void InitCountdown(void);
void DoCountdown(void);
void WaitGameStart(void);
void PlayGame_Leader(void);
void InitResults_Leader(void);
void DoResults(void);
void AskPlayAgain(void);
void EndLink(void);
void ExitGame(void);
void ResetGame_Dodrio(void);
void WaitEndGame_Leader(void);
void PlayGame_Member(void);
void InitResults_Member(void);
void WaitEndGame_Member(void);

// 0x82CB314 - JP adds a {0, 0, 0} terminator row to the US 3-row table.
const u8 sBerryFallDelays[][3] =
{
    { 40, 24, 13 },
    { 32, 19, 10 },
    { 22, 13,  7 },
    {  0,  0,  0 },
};

// 0x82CB320 - US 5-entry table padded to 8 bytes.
const u8 sTreeBorderXPos[8] = { 8, 5, 8, 11, 15, 0, 0, 0 };

// 0x82CB328 - US 7-entry table padded to 8 bytes.
const u8 sDifficultyThresholds[8] = { 5, 10, 20, 30, 50, 70, 100, 0 };

// 0x82CB330 - 3 x 10 berry ids (30 bytes), 2 pad bytes before the pointer
// table below.
const u8 sPrizeBerryIds[3][10] =
{
    { 15, 16, 17, 18, 19, 19, 18, 17, 16, 15 },
    { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
    { 30, 31, 32, 33, 34, 34, 33, 32, 31, 30 },
};

// 0x82CB350 / 0x82CB380
void (*const sLeaderFuncs[12])(void) =
{
    [FUNC_INTRO]            = DoGameIntro,
    [FUNC_INIT_COUNTDOWN]   = InitCountdown,
    [FUNC_COUNTDOWN]        = DoCountdown,
    [FUNC_WAIT_START]       = WaitGameStart,
    [FUNC_PLAY_GAME]        = PlayGame_Leader,
    [FUNC_INIT_RESULTS]     = InitResults_Leader,
    [FUNC_RESULTS]          = DoResults,
    [FUNC_ASK_PLAY_AGAIN]   = AskPlayAgain,
    [FUNC_END_LINK]         = EndLink,
    [FUNC_EXIT]             = ExitGame,
    [FUNC_RESET_GAME]       = ResetGame_Dodrio,
    [FUNC_WAIT_END_GAME]    = WaitEndGame_Leader,
};

void (*const sMemberFuncs[12])(void) =
{
    [FUNC_INTRO]            = DoGameIntro,
    [FUNC_INIT_COUNTDOWN]   = InitCountdown,
    [FUNC_COUNTDOWN]        = DoCountdown,
    [FUNC_WAIT_START]       = WaitGameStart,
    [FUNC_PLAY_GAME]        = PlayGame_Member,
    [FUNC_INIT_RESULTS]     = InitResults_Member,
    [FUNC_RESULTS]          = DoResults,
    [FUNC_ASK_PLAY_AGAIN]   = AskPlayAgain,
    [FUNC_END_LINK]         = EndLink,
    [FUNC_EXIT]             = ExitGame,
    [FUNC_RESET_GAME]       = ResetGame_Dodrio,
    [FUNC_WAIT_END_GAME]    = WaitEndGame_Member,
};

// 0x82CB3B0
const s16 sBerryScoreMultipliers[] = { 10, 30, 50, 50 };

// 0x82CB3B8
const struct WindowTemplate sRecordsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 5,
    .tilemapTop = 1,
    .width = 20,
    .height = 11,
    .paletteNum = 15,
    .baseBlock = 1,
};

// 0x82CB3C0 - JP records labels; texts still live in the mid94 text region.
const u8 *const sRecordsLabels[] =
{
    gUnknown_85CCA7C + 0x28A, // "きのみをとった　かいすう$"
    gUnknown_85CCA7C + 0x297, // "さいこう　とくてん$"
    gUnknown_85CCA7C + 0x2A1, // "5にんで　きのみを\nつづけてとった　かいすう$"
};

// 0x82CB3CC
const u8 sRecordDigitCounts[] = { 4, 7, 4, 0 };

// 0x82CB3D0
const u16 sRecordLabelYs[] = { 26, 42, 58 };

// 0x82CB3D6
const u16 sRecordValueYs[] = { 26, 42, 72 };

// 0x82CB3DC - JP-only initial berry results (twenty u16s).
const u16 sBerryResultsInit[] =
{
    9999, 0, 90, 9999, 9999, 9999, 70, 9999, 9999, 0,
    9999, 0, 9999, 9999, 60, 0, 9999, 9999, 9999, 0,
};

// 0x82CB404 - JP default player names (hiragana / letters / digits).
const u8 sDefaultPlayerName1[] = _("あいうえおかき");
const u8 sDefaultPlayerName2[] = _("ABCDEFG");
const u8 sDefaultPlayerName3[] = _("0123456");

// 0x82CB41C
const u8 *const sPlayerNames[] =
{
    sDefaultPlayerName1,
    sDefaultPlayerName1,
    sDefaultPlayerName1,
    sDefaultPlayerName2,
    sDefaultPlayerName3,
};

// 0x82CB430 - US sBgTemplates plus two filler entries.
const struct BgTemplate sDodrioBgTemplates[] =
{
    { .bg = 0, .charBaseIndex = 0, .mapBaseIndex = 30, .screenSize = 0, .paletteMode = 0, .priority = 0, .baseTile = 0 },
    { .bg = 1, .charBaseIndex = 2, .mapBaseIndex = 12, .screenSize = 1, .paletteMode = 0, .priority = 1, .baseTile = 0 },
    { .bg = 2, .charBaseIndex = 2, .mapBaseIndex = 14, .screenSize = 1, .paletteMode = 0, .priority = 1, .baseTile = 0 },
    { .bg = 3, .charBaseIndex = 3, .mapBaseIndex = 31, .screenSize = 0, .paletteMode = 0, .priority = 2, .baseTile = 0 },
    { .bg = 3, .charBaseIndex = 3, .mapBaseIndex = 15, .screenSize = 0, .paletteMode = 0, .priority = 0, .baseTile = 0 },
    { .bg = 0, .charBaseIndex = 0, .mapBaseIndex = 0,  .screenSize = 0, .paletteMode = 0, .priority = 0, .baseTile = 0 },
};

// 0x82CB448 - JP results window layouts (differ from US).
const struct WindowTemplate sDodrioWindowTemplates_Results[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 0x13,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 28,
        .height = 13,
        .paletteNum = 13,
        .baseBlock = 0x67,
    },
};

// 0x82CB458 - JP prize window layout (differs from US).
const struct WindowTemplate sWindowTemplate_Prize =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 28,
    .height = 7,
    .paletteNum = 13,
    .baseBlock = 0x67,
};

// 0x82CB460
const struct WindowTemplate sWindowTemplates_PlayAgain[] =
{
    { // WIN_PLAY_AGAIN
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 19,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 0x13,
    },
    { // WIN_YES_NO
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 7,
        .width = 6,
        .height = 4,
        .paletteNum = 13,
        .baseBlock = 0x4C,
    },
};

// 0x82CB470
const struct WindowTemplate sWindowTemplate_DroppedOut =
{
    .bg = 0,
    .tilemapLeft = 4,
    .tilemapTop = 6,
    .width = 22,
    .height = 5,
    .paletteNum = 13,
    .baseBlock = 0x13,
};

// 0x82CB478
const struct WindowTemplate sWindowTemplate_CommStandby =
{
    .bg = 0,
    .tilemapLeft = 5,
    .tilemapTop = 8,
    .width = 19,
    .height = 3,
    .paletteNum = 13,
    .baseBlock = 0x13,
};

// 0x82CB480 - unreferenced byte-for-byte duplicate of the five dodrio maps
// already expressed in berry_crush3.h (sActiveColumnMap, sDodrioHeadToColumnMap,
// sDodrioNeighborMap, sPlayerIdAtColumn, sUnsharedColumns).
const u8 gUnknown_82CB480[] =
{
#include "dodrio1_dup_maps.inc"
};

#endif // POKEEMERALD_JP_DODRIO1_H
