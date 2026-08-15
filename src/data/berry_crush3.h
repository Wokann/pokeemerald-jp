#ifndef POKEEMERALD_JP_BERRY_CRUSH3_H
#define POKEEMERALD_JP_BERRY_CRUSH3_H

#include "global.h"
#include "berry_crush.h"
#include "link.h"

// Berry-crush results/commands/map data (0x82C7C40..0x82C7F24)

struct BerryCrushGame;

extern const u8 gUnknown_85CC9D4[];        // JP text region (asm)
extern const u8 gText_CrushingResults[];   // JP text (asm)

u32 Cmd_BeginNormalPaletteFade(struct BerryCrushGame *game, u8 *args);
u32 Cmd_WaitPaletteFade(struct BerryCrushGame *game, u8 *args);
u32 Cmd_PrintMessage(struct BerryCrushGame *game, u8 *args);
u32 Cmd_ShowGameDisplay(struct BerryCrushGame *game, u8 *args);
u32 Cmd_HideGameDisplay(struct BerryCrushGame *game, u8 *args);
u32 Cmd_SignalReadyToBegin(struct BerryCrushGame *game, u8 *args);
u32 Cmd_AskPickBerry(struct BerryCrushGame *game, u8 *args);
u32 Cmd_GoToBerryPouch(struct BerryCrushGame *game, u8 *args);
u32 Cmd_WaitForOthersToPickBerries(struct BerryCrushGame *game, u8 *args);
u32 Cmd_DropBerriesIntoCrusher(struct BerryCrushGame *game, u8 *args);
u32 Cmd_DropLid(struct BerryCrushGame *game, u8 *args);
u32 Cmd_Countdown(struct BerryCrushGame *game, u8 *args);
u32 Cmd_PlayGame_Leader(struct BerryCrushGame *game, u8 *args);
u32 Cmd_PlayGame_Member(struct BerryCrushGame *game, u8 *args);
u32 Cmd_FinishGame(struct BerryCrushGame *game, u8 *args);
u32 Cmd_HandleTimeUp(struct BerryCrushGame *game, u8 *args);
u32 Cmd_TabulateResults(struct BerryCrushGame *game, u8 *args);
u32 Cmd_ShowResults(struct BerryCrushGame *game, u8 *args);
u32 Cmd_SaveGame(struct BerryCrushGame *game, u8 *args);
u32 Cmd_AskPlayAgain(struct BerryCrushGame *game, u8 *args);
u32 Cmd_CommunicatePlayAgainResponses(struct BerryCrushGame *game, u8 *args);
u32 Cmd_PlayAgain(struct BerryCrushGame *game, u8 *args);
u32 Cmd_StopGame(struct BerryCrushGame *game, u8 *args);
u32 Cmd_CloseLink(struct BerryCrushGame *game, u8 *args);
u32 Cmd_Quit(struct BerryCrushGame *game, u8 *args);

// 0x82C7C40 - JP results texts.  The first three live in the mid94 text
// region (gUnknown_85CC9D4), the rankings labels are sub-strings of
// gText_CrushingResults; they get gText_* names when that region is
// converted to C.
const u8 *const sResultsTexts[] =
{
    gUnknown_85CC9D4 + 0x8,       // "かい$"
    gUnknown_85CC9D4 + 0xC,       // "{STR_VAR_1},{STR_VAR_2}$"
    gUnknown_85CC9D4 + 0x14,      // "{STR_VAR_1}のみ$"
    gText_CrushingResults + 0xC,  // "ていねいさ　ランキング$"
    gText_CrushingResults + 0x18, // "たすけあい　ランキング$"
    gText_CrushingResults + 0x24, // "おすつよさ　ランキング$"
};

// 0x82C7C58
u32 (*const sBerryCrushCommands[CMD_QUIT + 1])(struct BerryCrushGame *, u8 *) =
{
    [CMD_NONE]             = NULL,
    [CMD_FADE]             = Cmd_BeginNormalPaletteFade,
    [CMD_WAIT_FADE]        = Cmd_WaitPaletteFade,
    [CMD_PRINT_MSG]        = Cmd_PrintMessage,
    [CMD_SHOW_GAME]        = Cmd_ShowGameDisplay,
    [CMD_HIDE_GAME]        = Cmd_HideGameDisplay,
    [CMD_READY_BEGIN]      = Cmd_SignalReadyToBegin,
    [CMD_ASK_PICK_BERRY]   = Cmd_AskPickBerry,
    [CMD_PICK_BERRY]       = Cmd_GoToBerryPouch,
    [CMD_WAIT_BERRIES]     = Cmd_WaitForOthersToPickBerries,
    [CMD_DROP_BERRIES]     = Cmd_DropBerriesIntoCrusher,
    [CMD_DROP_LID]         = Cmd_DropLid,
    [CMD_COUNTDOWN]        = Cmd_Countdown,
    [CMD_PLAY_GAME_LEADER] = Cmd_PlayGame_Leader,
    [CMD_PLAY_GAME_MEMBER] = Cmd_PlayGame_Member,
    [CMD_FINISH_GAME]      = Cmd_FinishGame,
    [CMD_TIMES_UP]         = Cmd_HandleTimeUp,
    [CMD_CALC_RESULTS]     = Cmd_TabulateResults,
    [CMD_SHOW_RESULTS]     = Cmd_ShowResults,
    [CMD_SAVE]             = Cmd_SaveGame,
    [CMD_ASK_PLAY_AGAIN]   = Cmd_AskPlayAgain,
    [CMD_COMM_PLAY_AGAIN]  = Cmd_CommunicatePlayAgainResponses,
    [CMD_PLAY_AGAIN_YES]   = Cmd_PlayAgain,
    [CMD_PLAY_AGAIN_NO]    = Cmd_StopGame,
    [CMD_CLOSE_LINK]       = Cmd_CloseLink,
    [CMD_QUIT]             = Cmd_Quit,
};

// 0x82C7CC0
const u8 sSparkleThresholds[MAX_RFU_PLAYERS - 1][4] =
{
    { 2,  4,  6,  7 },
    { 3,  5,  8, 11 },
    { 3,  7, 11, 15 },
    { 4,  8, 12, 17 },
};

// 0x82C7CD0
const u8 sBigSparkleThresholds[MAX_RFU_PLAYERS - 1] = { 5, 7, 9, 12 };

// 0x82C7CD4 - the code only reads the first four bitmasks; the following
// 80 bytes are JP-specific unreferenced data (six u32 values followed by
// seven 8-byte coordinate-like rows).
const u8 sReceivedPlayerBitmasks[] = { 0x03, 0x07, 0x0F, 0x1F };
const u8 gUnknown_82C7CD8[] =
{
    0xE0, 0x01, 0x00, 0x00, 0xC9, 0x12, 0x00, 0x00,
    0xEA, 0x12, 0x00, 0x00, 0xFF, 0x21, 0x00, 0x00,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x1C, 0x03, 0x0D, 0x13, 0x00,
    0x00, 0x01, 0x06, 0x1C, 0x0D, 0x0D, 0x67, 0x00,
    0x00, 0x01, 0x06, 0x1C, 0x07, 0x0D, 0x67, 0x00,
    0x00, 0x01, 0x08, 0x13, 0x03, 0x0D, 0x13, 0x00,
    0x00, 0x16, 0x07, 0x06, 0x04, 0x0D, 0x4C, 0x00,
    0x00, 0x04, 0x06, 0x16, 0x05, 0x0D, 0x13, 0x00,
    0x00, 0x05, 0x08, 0x13, 0x03, 0x0D, 0x13, 0x00,
};

// 0x82C7D28 - for each player the list of columns starting with the one to
// their left; only the active range is read (see pokeemerald
// dodrio_berry_picking.c sActiveColumnMap).
const u8 sActiveColumnMap[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS][11] =
{
    { // 1 player (never used), columns 4-6.
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    },
    { // 2 players (never used), columns 3-6
        {0, 1, 2, 3, 4, 5, 6, 3, 8, 9, 0},
        {0, 1, 2, 5, 6, 3, 4, 5, 8, 9, 0},
    },
    { // 3 players, columns 2-7
        {0, 1, 2, 3, 4, 5, 6, 7, 2, 9, 0},
        {0, 1, 4, 5, 6, 7, 2, 3, 4, 9, 0},
        {0, 1, 6, 7, 2, 3, 4, 5, 6, 9, 0},
    },
    { // 4 players, columns 1-8
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 0},
        {0, 3, 4, 5, 6, 7, 8, 1, 2, 3, 0},
        {0, 5, 6, 7, 8, 1, 2, 3, 4, 5, 0},
        {0, 7, 8, 1, 2, 3, 4, 5, 6, 7, 0},
    },
    { // 5 players, all columns (0-9)
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
        {4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4},
        {6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6},
        {8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8},
    },
};

// 0x82C7E3B - which falling-berry column corresponds to which Dodrio head.
const u8 sDodrioHeadToColumnMap[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS][3] =
{
    { // 1 player (never used)
        {4, 5, 6},
    },
    { // 2 players (never used)
        {3, 4, 5},
        {5, 6, 3},
    },
    { // 3 players
        {4, 5, 6},
        {6, 7, 2},
        {2, 3, 4},
    },
    { // 4 players
        {3, 4, 5},
        {5, 6, 7},
        {7, 8, 1},
        {1, 2, 3},
    },
    { // 5 players
        {4, 5, 6},
        {6, 7, 8},
        {8, 9, 0},
        {0, 1, 2},
        {2, 3, 4},
    },
};

// 0x82C7E86 - player ids and their neighbours {L, M, R}.
const u8 sDodrioNeighborMap[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS][3] =
{
    { // 1 player (never used)
        {1, 0, 1},
    },
    { // 2 players (never used)
        {1, 0, 1},
        {0, 1, 0},
    },
    { // 3 players
        {2, 0, 1},
        {0, 1, 2},
        {1, 2, 0},
    },
    { // 4 players
        {3, 0, 1},
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 0},
    },
    { // 5 players
        {4, 0, 1},
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 0},
    },
};

// 0x82C7ED4 - player id at each column; 9 = no player.
ALIGNED(4) const u8 sPlayerIdAtColumn[MAX_RFU_PLAYERS][11] =
{
    {9, 9, 9, 9, 1, 1, 1, 9, 9, 9, 9},
    {9, 9, 9, 0, 0, 1, 1, 0, 9, 9, 9},
    {9, 9, 2, 2, 0, 0, 1, 1, 1, 9, 9},
    {9, 3, 3, 0, 0, 1, 1, 2, 2, 3, 9},
    {3, 3, 4, 4, 0, 0, 1, 1, 2, 2, 3},
};

// 0x82C7F0B - columns that belong solely to one player; JP keeps the
// original buggy row ({1, 3, 5, 6, 9}, column 6 shared, 7 not).
const u8 sUnsharedColumns[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS] =
{
    {5},
    {4, 6},
    {3, 5, 7},
    {2, 4, 6, 8},
    {1, 3, 5, 6, 9},
};

#endif // POKEEMERALD_JP_BERRY_CRUSH3_H
