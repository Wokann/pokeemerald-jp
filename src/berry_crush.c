#include "global.h"
#include "berry.h"
#include "berry_crush.h"
#include "bg.h"
#include "berry_powder.h"
#include "decompress.h"
#include "digit_obj_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item_menu.h"
#include "item_icon.h"
#include "link.h"
#include "link_rfu.h"
#include "malloc.h"
#include "main.h"
#include "math_util.h"
#include "menu.h"
#include "minigame_countdown.h"
#include "overworld.h"
#include "palette.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "window.h"
#include "constants/items.h"
#include "constants/game_stat.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define MAX_TIME (10 * 60 * 60) // Timer can go up to 9:59:59

#define CRUSHER_START_Y (-104)

#define TAG_CRUSHER_BASE  1
#define PALTAG_EFFECT     2
#define GFXTAG_IMPACT     2
#define GFXTAG_SPARKLE    3
#define TAG_TIMER_DIGITS  4

#define TAG_COUNTDOWN 0x1000

#define F_MSG_CLEAR  (1 << 0)
#define F_MSG_EXPAND (1 << 1)

#define F_INPUT_HIT_A (1 << 0)
#define F_INPUT_HIT_B (1 << 1)
#define F_INPUT_HIT_SYNC (1 << 2) // Input at same time as another player
#define INPUT_FLAGS_PER_PLAYER 3
#define INPUT_FLAG_MASK ((1 << INPUT_FLAGS_PER_PLAYER) - 1)

// Values for the inputState field
enum {
    INPUT_STATE_NONE,
    INPUT_STATE_HIT,      // Hit the crusher
    INPUT_STATE_HIT_SYNC, // Hit the crusher at same time as another player
};

// Flag for whether a given player has sent their data this round
#define SEND_GAME_STATE 2

enum {
    RUN_CMD,
    SCHEDULE_CMD,
};

enum {
    MSG_PICK_BERRY,
    MSG_WAIT_PICK,
    MSG_POWDER,
    MSG_SAVING,
    MSG_PLAY_AGAIN,
    MSG_NO_BERRIES,
    MSG_DROPPED,
    MSG_TIMES_UP,
    MSG_COMM_STANDBY,
};

// IDs for the main berry crush game functions
enum {
    CMD_NONE,
    CMD_FADE,
    CMD_WAIT_FADE,
    CMD_PRINT_MSG,
    CMD_SHOW_GAME,
    CMD_HIDE_GAME,
    CMD_READY_BEGIN,
    CMD_ASK_PICK_BERRY,
    CMD_PICK_BERRY,
    CMD_WAIT_BERRIES,
    CMD_DROP_BERRIES,
    CMD_DROP_LID,
    CMD_COUNTDOWN,
    CMD_PLAY_GAME_LEADER,
    CMD_PLAY_GAME_MEMBER,
    CMD_FINISH_GAME,
    CMD_TIMES_UP,
    CMD_CALC_RESULTS,
    CMD_SHOW_RESULTS,
    CMD_SAVE,
    CMD_ASK_PLAY_AGAIN,
    CMD_COMM_PLAY_AGAIN,
    CMD_PLAY_AGAIN_YES,
    CMD_PLAY_AGAIN_NO,
    CMD_CLOSE_LINK,
    CMD_QUIT,
};

#define PLAY_AGAIN_YES        0
#define PLAY_AGAIN_NO         1
#define PLAY_AGAIN_NO_BERRIES 3

// Main states for the game. Many are assigned but never checked
enum {
    STATE_INIT = 1,
    STATE_RESET,
    STATE_PICK_BERRY,
    STATE_DROP_BERRIES,
    STATE_DROP_LID,
    STATE_COUNTDOWN,
    STATE_PLAYING,
    STATE_FINISHED,
    STATE_TIMES_UP,
    STATE_10, // Unused
    STATE_RESULTS_PRESSES,
    STATE_RESULTS_RANDOM,
    STATE_RESULTS_CRUSHING,
    STATE_14, // Unused
    STATE_PLAY_AGAIN,
};

#define RESULTS_STATE_START STATE_RESULTS_PRESSES
#define RESULTS_STATE_END   STATE_RESULTS_CRUSHING

enum {
    COLORID_GRAY,
    COLORID_BLACK,
    COLORID_LIGHT_GRAY,
    COLORID_BLUE,
    COLORID_GREEN,
    COLORID_RED,
};

struct BerryCrushGame_Player
{
    u8 name[PLAYER_NAME_LENGTH + 1]; // +0
    u16 berryId;
    u16 inputTime;
    u16 neatInputStreak;
    u16 timeSincePrevInput;
    u16 maxNeatInputStreak;
    u16 numAPresses;
    u16 numSyncedAPresses;
    u16 timePressingA;
    u8 inputFlags;
    u8 inputState;
    u8 filler[2];
};

struct BerryCrushGame_LocalState
{
    u16 sendFlag;              // +0x5C
    bool8 endGame:1;
    bool8 bigSparkle:1;
    bool8 pushedAButton:1;
    u8 playerPressedAFlags:5;
    s8 vibration;              // +0x5F
    u16 depth;                 // +0x60
    u16 timer;                 // +0x62
    u16 inputFlags;            // +0x64
    u16 sparkleAmount;         // +0x66
};

struct BerryCrushGame_Results
{
    u32 powder;                     // +0x68
    u16 time;                       // +0x6C
    u16 targetPressesPerSec;        // +0x6E
    u16 silkiness;                  // +0x70
    u16 totalAPresses;              // +0x72
    u16 stats[2][MAX_RFU_PLAYERS];  // +0x74
    u8 playerIdsRanked[2][MAX_RFU_PLAYERS + 3]; // +0x88
};

enum {
    RESULTS_PAGE_PRESSES,
    RESULTS_PAGE_RANDOM,
    RESULTS_PAGE_CRUSHING,
    NUM_RESULTS_PAGES
};

#define randomPageId playerIdsRanked[0][7]

struct BerryCrushGame_LinkState
{
    u16 rfuCmd;
    u16 sendFlag;
    bool8 endGame:1;
    bool8 bigSparkle:1;
    bool8 pushedAButton:1;
    u8 playerPressedAFlags:5;
    s8 vibration;
    u16 depth;
    u16 timer;
    u16 inputFlags;
    u16 sparkleAmount;
};

struct BerryCrushGame_Gfx
{
    u8 counter;                               // +0
    u8 vibrationIdx;
    u8 numVibrations;
    bool8 vibrating;
    s16 minutes;
    s16 secondsInt;
    s16 secondsFrac;
    const struct BerryCrushPlayerCoords *playerCoords[MAX_RFU_PLAYERS]; // +0xC
    struct Sprite *coreSprite;                // +0x20
    struct Sprite *impactSprites[MAX_RFU_PLAYERS]; // +0x24
    struct Sprite *berrySprites[MAX_RFU_PLAYERS]; // +0x38
    struct Sprite *sparkleSprites[11];        // +0x4C
    struct Sprite *timerSprites[2];           // +0x78
    u8 resultsState;                          // +0x80
    u8 unused;
    u8 resultsWindowId;
    u8 nameWindowIds[MAX_RFU_PLAYERS];        // +0x83
    u16 bgBuffers[4][0x800];                  // +0x88
};

struct BerryCrushGame
{
    MainCallback exitCallback;                    // +0
    u32 (*cmdCallback)(struct BerryCrushGame *, u8 *); // +4
    u8 localId;                                   // +8
    u8 playerCount;                               // +9
    u8 taskId;                                    // +A
    u8 textSpeed;                                 // +B
    u8 cmdState;                                  // +C
    u8 unused;                                    // +D
    u8 nextCmd;                                   // +E
    u8 afterPalFadeCmd;                           // +F
    u16 cmdTimer;                                 // +10
    u16 gameState;                                // +12
    u16 playAgainState;                           // +14
    u16 pressingSpeed;                            // +16
    s16 targetAPresses;                           // +18
    s16 totalAPresses;                            // +1A
    s32 powder;                                   // +1C
    s32 targetDepth;                              // +20
    u8 newDepth;                                  // +24
    u8 noRoomForPowder:1;                         // +25
    u8 newRecord:1;
    u8 playedSound:1;
    u8 endGame:1;
    u8 bigSparkle:1;
    u8 sparkleAmount:3;
    u16 leaderTimer;                              // +26
    u16 timer;                                    // +28
    s16 depth;                                    // +2A
    s16 vibration;                                // +2C
    s16 bigSparkleCounter;                        // +2E
    s16 numBigSparkles;                           // +30
    s16 numBigSparkleChecks;                      // +32
    s16 sparkleCounter;                           // +34
    u8 commandArgs[12];                           // +36
    u16 sendCmd[6];                               // +42
    u16 recvCmd[7];                               // +4E
    struct BerryCrushGame_LocalState localState;  // +5C
    struct BerryCrushGame_Results results;        // +68
    struct BerryCrushGame_Player players[MAX_RFU_PLAYERS]; // +98
    struct BerryCrushGame_Gfx gfx;                // +124
};

// Berry Crush game state, EWRAM 0x02022944 (see sym_ewram_jp.txt).
extern EWRAM_DATA struct BerryCrushGame *sGame;

void RunOrScheduleCommand(u16, u8, u8 *);
extern void SetPaletteFadeArgs(u8 *, bool8, u32, s8, u8, u8, u16);
extern void GetBerryFromBag(void);
extern const struct BgTemplate sBgTemplates[4];
extern const u8 sCrusherTop_Tilemap[];
extern const u8 sContainerCap_Tilemap[];
extern const u8 sBg_Tilemap[];
extern const u16 sPlayerBerrySpriteTags[MAX_RFU_PLAYERS];
extern const struct SpriteTemplate sSpriteTemplate_PlayerBerry;
extern const s8 sImpactCoords[3][2];
extern const s8 sSparkleCoords[][2];
extern const u32 sPressingSpeedConversionTable[];
extern const u8 sTextColorTable[][3];
extern const struct BerryCrushPlayerCoords sPlayerCoords[];
extern const u8 sPlayerIdToPosId[][MAX_RFU_PLAYERS];
extern const struct WindowTemplate sWindowTemplates_PlayerNames[];
extern const u32 sPlayerNameWindowGfx[];
extern const struct CompressedSpriteSheet sSpriteSheets[];
extern const struct SpritePalette sSpritePals[];
extern const struct SpriteTemplate sSpriteTemplate_CrusherBase;
extern const struct SpriteTemplate sSpriteTemplate_Impact;
extern const struct SpriteTemplate sSpriteTemplate_Sparkle;
extern const struct SpriteTemplate sSpriteTemplate_Timer;
extern const struct DigitObjUtilTemplate sDigitObjTemplates[];
extern u32 (*const sBerryCrushCommands[26])(struct BerryCrushGame *, u8 *);
extern const u8 *const sMessages[];
extern const u8 sReceivedPlayerBitmasks[];
extern const u8 sBitTable[8];
extern const u8 sSyncPressBonus[8];
extern const u8 sVibrationData[MAX_RFU_PLAYERS][4];
extern const s8 sIntroOutroVibrationData[][7];
extern const u8 sSparkleThresholds[MAX_RFU_PLAYERS - 1][4];
extern const u8 sBigSparkleThresholds[MAX_RFU_PLAYERS - 1];
extern void ResetGame(struct BerryCrushGame *);
extern void SetPrintMessageArgs(u8 *, u8, u8, u16, u8);
extern void PrintResultsText(struct BerryCrushGame *, u8, u8, u8);
extern void PrintCrushingResults(struct BerryCrushGame *);
// JP layout: the results window templates are embedded in
// sWindowTemplates_PlayerNames at indices 6..8, and the ROM code reaches
// them through an overlapping symbol at sBgTemplates + 4
// (STATE_RESULTS_* = 11..13).  Express that overlap as a constant offset so
// the compiled address computation stays byte-identical.
#define sWindowTemplates_Results ((const struct WindowTemplate *)((const u8 *)sWindowTemplates_PlayerNames - 40))
extern const u8 sResultsWindowHeights[2][MAX_RFU_PLAYERS - 1];
extern const u8 *const sResultsTexts[];
void PrintTextCentered(u8 windowId, u8 left, u8 colorId, const u8 *string);
void CreatePlayerNameWindows(struct BerryCrushGame *);
void DrawPlayerNameWindows(struct BerryCrushGame *);
extern void CopyPlayerNameWindowGfxToBg(struct BerryCrushGame *);
void CreateGameSprites(struct BerryCrushGame *);
void DestroyGameSprites(struct BerryCrushGame *);
void SpriteCB_Sparkle_Init(struct Sprite *);

void SaveResults(void);
static void VBlankCB(void);
static void MainCB(void);
static void MainTask(u8 taskId);
static void SetNamesAndTextSpeed(struct BerryCrushGame *);
s32 ShowGameDisplay(void);
s32 HideGameDisplay(void);
static s32 UpdateGame(struct BerryCrushGame *);
void PrintTimer(struct BerryCrushGame_Gfx *, u16);
void HideTimer(struct BerryCrushGame_Gfx *);
void ResetCrusherPos(struct BerryCrushGame *);
void CreateBerrySprites(struct BerryCrushGame *, struct BerryCrushGame_Gfx *);
void UpdateInputEffects(struct BerryCrushGame *, struct BerryCrushGame_Gfx *);

struct BerryCrushGame *GetBerryCrushGame(void)
{
    return sGame;
}

u32 QuitBerryCrush(MainCallback exitCallback)
{
    if (!sGame)
        return 2;

    if (!exitCallback)
        exitCallback = sGame->exitCallback;

    DestroyTask(sGame->taskId);
    Free(sGame);
    sGame = NULL;
    SetMainCallback2(exitCallback);
    if (exitCallback == CB2_ReturnToField)
    {
        gTextFlags.autoScroll = TRUE;
        PlayNewMapMusic(MUS_POKE_CENTER);
        SetMainCallback1(CB1_Overworld);
    }

    return 0;
}

void StartBerryCrush(MainCallback exitCallback)
{
    u8 playerCount = 0;
    u8 multiplayerId;

    if (!gReceivedRemoteLinkPlayers || gWirelessCommType == 0)
    {
        SetMainCallback2(exitCallback);
        gRfu.errorParam0 = 0;
        gRfu.errorParam1 = 0;
        gRfu.errorState = RFU_ERROR_STATE_OCCURRED;
        return;
    }

    playerCount = GetLinkPlayerCount();
    multiplayerId = GetMultiplayerId();
    if (playerCount < 2 || multiplayerId >= playerCount)
    {
        SetMainCallback2(exitCallback);
        gRfu.errorParam0 = 0;
        gRfu.errorParam1 = 0;
        gRfu.errorState = RFU_ERROR_STATE_OCCURRED;
        return;
    }

    sGame = AllocZeroed(sizeof(*sGame));
    if (!sGame)
    {
        SetMainCallback2(exitCallback);
        gRfu.errorParam0 = 0;
        gRfu.errorParam1 = 0;
        gRfu.errorState = RFU_ERROR_STATE_OCCURRED;
        return;
    }

    sGame->exitCallback = exitCallback;
    sGame->localId = multiplayerId;
    sGame->playerCount = playerCount;
    SetNamesAndTextSpeed(sGame);
    sGame->gameState = 1;
    sGame->nextCmd = 1;
    sGame->afterPalFadeCmd = 6;
    SetPaletteFadeArgs(sGame->commandArgs, TRUE, PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    RunOrScheduleCommand(4, 1, sGame->commandArgs);
    SetMainCallback2(MainCB);
    sGame->taskId = CreateTask(MainTask, 8);
    gTextFlags.autoScroll = FALSE;
}

void GetBerryFromBag(void)
{
    if (gSpecialVar_ItemId < FIRST_BERRY_INDEX || gSpecialVar_ItemId > LAST_BERRY_INDEX + 1)
        gSpecialVar_ItemId = FIRST_BERRY_INDEX;
    else
        RemoveBagItem(gSpecialVar_ItemId, 1);

    sGame->players[sGame->localId].berryId = gSpecialVar_ItemId - FIRST_BERRY_INDEX;
    sGame->nextCmd = 1;
    sGame->afterPalFadeCmd = 9;
    SetPaletteFadeArgs(sGame->commandArgs, FALSE, PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    RunOrScheduleCommand(4, 1, sGame->commandArgs);
    sGame->taskId = CreateTask(MainTask, 8);
    SetMainCallback2(MainCB);
}

void ChooseBerry(void)
{
    DestroyTask(sGame->taskId);
    ChooseBerryForMachine(GetBerryFromBag);
}

void BerryCrush_SetVBlankCB(void)
{
    SetVBlankCallback(VBlankCB);
}

void UNUSED BerryCrush_InitVBlankCB(void)
{
    SetVBlankCallback(NULL);
}

void SaveResults(void)
{
    u32 time, presses;

    time = sGame->results.time;
    time = Q_24_8(time);
    time = MathUtil_Div32(time, Q_24_8(60));
    presses = sGame->results.totalAPresses;
    presses = Q_24_8(presses);
    presses = MathUtil_Div32(presses, time) & 0xFFFF;
    sGame->pressingSpeed = presses;

    switch (sGame->playerCount)
    {
    case 2:
        if (sGame->pressingSpeed > gSaveBlock2Ptr->berryCrush.pressingSpeeds[0])
        {
            sGame->newRecord = TRUE;
            gSaveBlock2Ptr->berryCrush.pressingSpeeds[0] = sGame->pressingSpeed;
        }
        break;
    case 3:
        if (sGame->pressingSpeed > gSaveBlock2Ptr->berryCrush.pressingSpeeds[1])
        {
            sGame->newRecord = TRUE;
            gSaveBlock2Ptr->berryCrush.pressingSpeeds[1] = sGame->pressingSpeed;
        }
        break;
    case 4:
        if (sGame->pressingSpeed > gSaveBlock2Ptr->berryCrush.pressingSpeeds[2])
        {
            sGame->newRecord = TRUE;
            gSaveBlock2Ptr->berryCrush.pressingSpeeds[2] = sGame->pressingSpeed;
        }
        break;
    case 5:
        if (sGame->pressingSpeed > gSaveBlock2Ptr->berryCrush.pressingSpeeds[3])
        {
            sGame->newRecord = TRUE;
            gSaveBlock2Ptr->berryCrush.pressingSpeeds[3] = sGame->pressingSpeed;
        }
        break;
    }

    sGame->powder = sGame->results.powder;
    if (GiveBerryPowder(sGame->powder))
        return;

    sGame->noRoomForPowder = TRUE;
}

static void VBlankCB(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void MainCB(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

static void MainTask(u8 taskId)
{
    if (sGame->cmdCallback)
        sGame->cmdCallback(sGame, sGame->commandArgs);

    UpdateGame(sGame);
}

static void SetNamesAndTextSpeed(struct BerryCrushGame *game)
{
    u8 i;

    for (i = 0; i < game->playerCount; i++)
    {
        memcpy(game->players[i].name, gLinkPlayers[i].name, PLAYER_NAME_LENGTH);
        game->players[i].name[PLAYER_NAME_LENGTH] = EOS;
    }

    if (i <= MAX_RFU_PLAYERS - 1)
    {
        do
        {
            memset(game->players[i].name, 1, PLAYER_NAME_LENGTH);
            game->players[i].name[PLAYER_NAME_LENGTH] = EOS;
            i++;
        } while (i <= MAX_RFU_PLAYERS - 1);
    }

    switch (gSaveBlock2Ptr->optionsTextSpeed)
    {
    case OPTIONS_TEXT_SPEED_SLOW:
        game->textSpeed = 8;
        break;
    case OPTIONS_TEXT_SPEED_MID:
        game->textSpeed = 4;
        break;
    case OPTIONS_TEXT_SPEED_FAST:
        game->textSpeed = 1;
        break;
    }
}

s32 ShowGameDisplay(void)
{
    struct BerryCrushGame *game = GetBerryCrushGame();

    if (!game)
        return -1;

    switch (game->cmdState)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ScanlineEffect_Stop();
        ResetTempTileDataBuffers();
        break;
    case 1:
        CpuFill16(0, (void *)OAM, OAM_SIZE);
        gReservedSpritePaletteCount = 0;
        DigitObjUtil_Init(3);
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(1, game->gfx.bgBuffers[0]);
        SetBgTilemapBuffer(2, game->gfx.bgBuffers[2]);
        SetBgTilemapBuffer(3, game->gfx.bgBuffers[3]);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 64);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        break;
    case 5:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        DecompressAndCopyTileDataToVram(1, gBerryCrush_Crusher_Gfx, 0, 0, 0);
        break;
    case 6:
        if (FreeTempTileDataBuffersIfPossible())
            return 0;

        InitStandardTextBoxWindows();
        InitTextBoxGfxAndPrinters();
        CreatePlayerNameWindows(game);
        DrawPlayerNameWindows(game);
        gPaletteFade.bufferTransferDisabled = TRUE;
        break;
    case 7:
        LoadPalette(gBerryCrush_Crusher_Pal, BG_PLTT_ID(0), 12 * PLTT_SIZE_4BPP);
        CopyToBgTilemapBuffer(1, sCrusherTop_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(2, sContainerCap_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(3, sBg_Tilemap, 0, 0);
        CopyPlayerNameWindowGfxToBg(game);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 8:
        LoadWirelessStatusIndicatorSpriteGfx();
        CreateWirelessStatusIndicatorSprite(0, 0);
        CreateGameSprites(game);
        SetGpuReg(REG_OFFSET_BG1VOFS, -gSpriteCoordOffsetY);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        break;
    case 9:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        BerryCrush_SetVBlankCB();
        game->cmdState = 0;
        return 1;
    }

    game->cmdState++;
    return 0;
}

s32 HideGameDisplay(void)
{
    struct BerryCrushGame *game = GetBerryCrushGame();

    if (!game)
        return -1;

    switch (game->cmdState)
    {
    case 0:
        Rfu_SetLinkStandbyCallback();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
    case 2:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 3:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 5:
        FreeAllWindowBuffers();
        HideBg(0);
        UnsetBgTilemapBuffer(0);
        HideBg(1);
        UnsetBgTilemapBuffer(1);
        HideBg(2);
        UnsetBgTilemapBuffer(2);
        HideBg(3);
        UnsetBgTilemapBuffer(3);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        break;
    case 6:
        DestroyWirelessStatusIndicatorSprite();
        DestroyGameSprites(game);
        DigitObjUtil_Free();
        break;
    case 7:
        game->cmdState = 0;
        return 1;
    }

    game->cmdState++;
    return 0;
}

static s32 UpdateGame(struct BerryCrushGame *game)
{
    gSpriteCoordOffsetY = game->depth + game->vibration;
    SetGpuReg(REG_OFFSET_BG1VOFS, -gSpriteCoordOffsetY);

    if (game->gameState == STATE_PLAYING)
        PrintTimer(&game->gfx, game->timer);

    return 0;
}

void ResetCrusherPos(struct BerryCrushGame *game)
{
    game->depth = CRUSHER_START_Y;
    game->vibration = 0;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = CRUSHER_START_Y;
}

// Sprite data for berry sprites. Identical to fields for sparkle sprites
#define sX         data[0]
#define sYSpeed    data[1]
#define sYAccel    data[2]
#define sXSpeed    data[3]
#define sSinIdx    data[4]
#define sSinSpeed  data[5]
#define sAmplitude data[6]
// The last element (data[7]) is a bitfield.
// The first 15 bits are the y coord to stop at.
// The last bit is a flag for whether or not to move horizontally too
#define sBitfield  data[7]
#define MASK_TARGET_Y 0x7FFF
#define F_MOVE_HORIZ  0x8000

void CreateBerrySprites(struct BerryCrushGame *game, struct BerryCrushGame_Gfx *gfx)
{
    u8 i;
    u8 spriteId;
    s16 distance, var1;
    s16 *data;
    s16 speed;
    u32 var2;

    for (i = 0; i < game->playerCount; i++)
    {
        spriteId = AddCustomItemIconSprite(
            &sSpriteTemplate_PlayerBerry,
            sPlayerBerrySpriteTags[i],
            sPlayerBerrySpriteTags[i],
            game->players[i].berryId + FIRST_BERRY_INDEX);
        gfx->berrySprites[i] = &gSprites[spriteId];
        gfx->berrySprites[i]->oam.priority = 3;
        gfx->berrySprites[i]->affineAnimPaused = TRUE;
        gfx->berrySprites[i]->x = gfx->playerCoords[i]->berryXOffset + 120;
        gfx->berrySprites[i]->y = -16;
        data = gfx->berrySprites[i]->data;
        speed = 512;
        sYSpeed = speed;
        sYAccel = 32;
        sBitfield = 112;
        distance = gfx->playerCoords[i]->berryXDest - gfx->playerCoords[i]->berryXOffset;
        sAmplitude = distance / 4;
        distance *= 128;
        var2 = speed + 32;
        var2 = var2 / 2;
        var1 = MathUtil_Div16Shift(7, Q_8_8(63.5), var2);
        sX = (u16)gfx->berrySprites[i]->x * 128;
        sXSpeed = MathUtil_Div16Shift(7, distance, var1);
        var1 = MathUtil_Mul16Shift(7, var1, 85);
        sSinIdx = 0;
        sSinSpeed = MathUtil_Div16Shift(7, Q_8_8(63.5), var1);
        sBitfield |= F_MOVE_HORIZ;
        if (gfx->playerCoords[i]->berryXOffset < 0)
            StartSpriteAffineAnim(gfx->berrySprites[i], 1);
    }
}

void SpriteCB_DropBerryIntoCrusher(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    sYSpeed += sYAccel;
    sprite->y2 += sYSpeed >> 8;
    if (sBitfield & F_MOVE_HORIZ)
    {
        sprite->sX += sXSpeed;
        sSinIdx += sSinSpeed;
        sprite->x2 = Sin(sSinIdx >> 7, sAmplitude);
        if ((sBitfield & F_MOVE_HORIZ) && (sSinIdx >> 7) > 126)
        {
            sprite->x2 = 0;
            sBitfield &= MASK_TARGET_Y;
        }
    }

    sprite->x = sX >> 7;
    if (sprite->y + sprite->y2 >= (sBitfield & MASK_TARGET_Y))
    {
        sprite->callback = SpriteCallbackDummy;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void BerryCrushFreeBerrySpriteGfx(struct BerryCrushGame *game, struct BerryCrushGame_Gfx *gfx)
{
    u8 i;
    for (i = 0; i < game->playerCount; i++)
    {
        FreeSpritePaletteByTag(sPlayerBerrySpriteTags[i]);
        FreeSpriteTilesByTag(sPlayerBerrySpriteTags[i]);
    }
}

void UpdateInputEffects(struct BerryCrushGame *game, struct BerryCrushGame_Gfx *gfx)
{
    u8 numPlayersPressed;
    struct BerryCrushGame_LinkState *linkState;
    u8 i;
    u16 temp1, xModifier;

    numPlayersPressed = 0;
    linkState = (struct BerryCrushGame_LinkState *)game->recvCmd;

    // Read inputs and update impact effects
    for (i = 0; i < game->playerCount; i++)
    {
        #define flags temp1

        flags = linkState->inputFlags >> (i * INPUT_FLAGS_PER_PLAYER);
        flags &= INPUT_FLAG_MASK;
        if (flags)
        {
            numPlayersPressed++;
            if (flags & F_INPUT_HIT_SYNC)
                StartSpriteAnim(gfx->impactSprites[i], 1); // Big impact sprite
            else
                StartSpriteAnim(gfx->impactSprites[i], 0); // Small impact sprite

            gfx->impactSprites[i]->invisible = FALSE;
            gfx->impactSprites[i]->animPaused = FALSE;
            gfx->impactSprites[i]->x2 = sImpactCoords[(flags % (ARRAY_COUNT(sImpactCoords) + 1)) - 1][0];
            gfx->impactSprites[i]->y2 = sImpactCoords[(flags % (ARRAY_COUNT(sImpactCoords) + 1)) - 1][1];
        }

        #undef flags
    }

    if (numPlayersPressed == 0)
    {
        game->playedSound = FALSE;
    }
    else
    {
        // Update sparkle effect
        #define yModifier temp1

        yModifier = (u8)(game->timer % 3);
        xModifier = yModifier;
        for (i = 0; i < linkState->sparkleAmount * 2 + 3; i++)
        {
            if (gfx->sparkleSprites[i]->invisible)
            {
                gfx->sparkleSprites[i]->callback = SpriteCB_Sparkle_Init;
                gfx->sparkleSprites[i]->x = sSparkleCoords[i][0] + 120;
                gfx->sparkleSprites[i]->y = sSparkleCoords[i][1] + 136 - (yModifier * 4);
                gfx->sparkleSprites[i]->x2 = sSparkleCoords[i][0] + (sSparkleCoords[i][0] / (xModifier * 4));
                gfx->sparkleSprites[i]->y2 = sSparkleCoords[i][1];
                if (linkState->bigSparkle)
                    StartSpriteAnim(gfx->sparkleSprites[i], 1);
                else
                    StartSpriteAnim(gfx->sparkleSprites[i], 0);

                yModifier++;
                if (yModifier > 3)
                    yModifier = 0;
            }
        }

        #undef yModifier

        if (game->playedSound)
        {
            game->playedSound = FALSE;
        }
        else
        {
            if (numPlayersPressed == 1)
                PlaySE(SE_MUD_BALL);
            else
                PlaySE(SE_BREAKABLE_DOOR);

            game->playedSound = TRUE;
        }
    }
}

bool32 AreEffectsFinished(struct BerryCrushGame *game, struct BerryCrushGame_Gfx *gfx)
{
    u8 i;

    // Are any impact sprites active
    for (i = 0; i < game->playerCount; i++)
    {
        if (!gfx->impactSprites[i]->invisible)
            return FALSE;
    }

    // Are any sparkle sprites active
    for (i = 0; i < ARRAY_COUNT(gfx->sparkleSprites); i++)
    {
        if (!gfx->sparkleSprites[i]->invisible)
            return FALSE;
    }

    if (game->vibration != 0)
        game->vibration = 0;

    return TRUE;
}

void FramesToMinSec(struct BerryCrushGame_Gfx *gfx, u16 frames)
{
    u8 i = 0;
    u32 fractionalFrames = 0;
    s16 r3 = 0;

    gfx->minutes = frames / (60 * 60);
    gfx->secondsInt = (frames % (60 * 60)) / 60;
    r3 = MathUtil_Mul16(Q_8_8(frames % 60), 4);

    for (i = 0; i < 8; i++)
    {
        if ((r3 >> (7 - i)) & 1)
            fractionalFrames += sPressingSpeedConversionTable[i];
    }

    gfx->secondsFrac = fractionalFrames / 1000000;
}

void PrintTimer(struct BerryCrushGame_Gfx *gfx, u16 timer)
{
    FramesToMinSec(gfx, timer);
    DigitObjUtil_PrintNumOn(0, gfx->minutes);
    DigitObjUtil_PrintNumOn(1, gfx->secondsInt);
    DigitObjUtil_PrintNumOn(2, gfx->secondsFrac);
}

void HideTimer(struct BerryCrushGame_Gfx *gfx)
{
    gfx->timerSprites[0]->invisible = TRUE;
    gfx->timerSprites[1]->invisible = TRUE;
    DigitObjUtil_HideOrShow(2, TRUE);
    DigitObjUtil_HideOrShow(1, TRUE);
    DigitObjUtil_HideOrShow(0, TRUE);
}

void CreatePlayerNameWindows(struct BerryCrushGame *game)
{
    u8 i;
    for (i = 0; i < game->playerCount; i++)
    {
        game->gfx.playerCoords[i] = &sPlayerCoords[sPlayerIdToPosId[game->playerCount - 2][i]];
        game->gfx.nameWindowIds[i] = AddWindow(&sWindowTemplates_PlayerNames[game->gfx.playerCoords[i]->playerId]);
        PutWindowTilemap(game->gfx.nameWindowIds[i]);
        FillWindowPixelBuffer(game->gfx.nameWindowIds[i], 0);
    }
}

void DrawPlayerNameWindows(struct BerryCrushGame *game)
{
    u8 i;
    for (i = 0; i < game->playerCount; i++)
    {
        PutWindowTilemap(game->gfx.nameWindowIds[i]);
        if (i == game->localId)
        {
            AddTextPrinterParameterized4(
                game->gfx.nameWindowIds[i],
                FONT_NORMAL,
                36 - GetStringWidth(FONT_NORMAL, game->players[i].name, 0) / 2u,
                1,
                0,
                0,
                sTextColorTable[COLORID_BLACK],
                0,
                game->players[i].name
            );
        }
        else
        {
            AddTextPrinterParameterized4(
                game->gfx.nameWindowIds[i],
                FONT_NORMAL,
                36 - GetStringWidth(FONT_NORMAL, game->players[i].name, 0) / 2u,
                1,
                0,
                0,
                sTextColorTable[COLORID_LIGHT_GRAY],
                0,
                game->players[i].name
            );
        }
        CopyWindowToVram(game->gfx.nameWindowIds[i], COPYWIN_FULL);
    }
    CopyBgTilemapBufferToVram(0);
}

void CreateGameSprites(struct BerryCrushGame *game)
{
    u8 i = 0;
    u8 spriteId;

    game->depth = CRUSHER_START_Y;
    game->vibration = 0;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = CRUSHER_START_Y;
    for (i = 0; i <= 3; i++)
        LoadCompressedSpriteSheet(&sSpriteSheets[i]);
    LoadSpritePalettes(sSpritePals);

    // Create sprite for crusher base
    spriteId = CreateSprite(&sSpriteTemplate_CrusherBase, 120, 88, 5);
    game->gfx.coreSprite = &gSprites[spriteId];
    game->gfx.coreSprite->oam.priority = 3;
    game->gfx.coreSprite->coordOffsetEnabled = TRUE;
    game->gfx.coreSprite->animPaused = TRUE;

    // Create sprites for the impact effect
    for (i = 0; i < game->playerCount; i++)
    {
        spriteId = CreateSprite(
            &sSpriteTemplate_Impact,
            game->gfx.playerCoords[i]->impactXOffset + 120,
            game->gfx.playerCoords[i]->impactYOffset + 32,
            0
        );
        game->gfx.impactSprites[i] = &gSprites[spriteId];
        game->gfx.impactSprites[i]->oam.priority = 1;
        game->gfx.impactSprites[i]->invisible = TRUE;
        game->gfx.impactSprites[i]->coordOffsetEnabled = TRUE;
        game->gfx.impactSprites[i]->animPaused = TRUE;
    }

    // Create sprites for sparkle effect
    for (i = 0; i <= 10; i++)
    {
        spriteId = CreateSprite(
            &sSpriteTemplate_Sparkle,
            sSparkleCoords[i][0] + 120,
            sSparkleCoords[i][1] + 136,
            6
        );
        game->gfx.sparkleSprites[i] = &gSprites[spriteId];
        game->gfx.sparkleSprites[i]->oam.priority = 3;
        game->gfx.sparkleSprites[i]->invisible = TRUE;
        game->gfx.sparkleSprites[i]->animPaused = TRUE;
        game->gfx.sparkleSprites[i]->data[0] = i;
    }

    // Create sprites for timer
    for (i = 0; i <= 1; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Timer, 24 * i + 176, 8, 0);
        game->gfx.timerSprites[i] = &gSprites[spriteId];
        game->gfx.timerSprites[i]->oam.priority = 0;
        game->gfx.timerSprites[i]->invisible = FALSE;
        game->gfx.timerSprites[i]->animPaused = FALSE;
    }
    DigitObjUtil_CreatePrinter(0, 0, &sDigitObjTemplates[0]);
    DigitObjUtil_CreatePrinter(1, 0, &sDigitObjTemplates[1]);
    DigitObjUtil_CreatePrinter(2, 0, &sDigitObjTemplates[2]);

    if (game->gameState == STATE_INIT)
        HideTimer(&game->gfx);
}

void DestroyGameSprites(struct BerryCrushGame *game)
{
    u8 i = 0;
    FreeSpriteTilesByTag(TAG_TIMER_DIGITS);
    FreeSpriteTilesByTag(GFXTAG_SPARKLE);
    FreeSpriteTilesByTag(GFXTAG_IMPACT);
    FreeSpriteTilesByTag(TAG_CRUSHER_BASE);
    FreeSpritePaletteByTag(TAG_TIMER_DIGITS);
    FreeSpritePaletteByTag(PALTAG_EFFECT);
    FreeSpritePaletteByTag(TAG_CRUSHER_BASE);
    for (i = 0; i < ARRAY_COUNT(game->gfx.timerSprites); i++)
        DestroySprite(game->gfx.timerSprites[i]);
    DigitObjUtil_DeletePrinter(2);
    DigitObjUtil_DeletePrinter(1);
    DigitObjUtil_DeletePrinter(0);
    for (i = 0; i < ARRAY_COUNT(game->gfx.sparkleSprites); i++)
        DestroySprite(game->gfx.sparkleSprites[i]);
    for (i = 0; i < game->playerCount; i++)
        DestroySprite(game->gfx.impactSprites[i]);
    if (game->gfx.coreSprite->inUse)
        DestroySprite(game->gfx.coreSprite);
}

void SpriteCB_Impact(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->invisible = TRUE;
        sprite->animPaused = TRUE;
    }
}

void SpriteCB_Sparkle_End(struct Sprite *sprite)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sprite->data); i++)
        sprite->data[i] = 0;
    sprite->x2 = 0;
    sprite->y2 = 0;
    sprite->invisible = TRUE;
    sprite->animPaused = TRUE;
    sprite->callback = SpriteCallbackDummy;
}

void SpriteCB_Sparkle(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    sYSpeed += sYAccel;
    sprite->y2 += sYSpeed >> 8;
    if (sBitfield & F_MOVE_HORIZ)
    {
        sprite->sX += sXSpeed;
        sSinIdx += sSinSpeed;
        sprite->x2 = Sin(sSinIdx >> 7, sAmplitude);
        if (sBitfield & F_MOVE_HORIZ && sSinIdx >> 7 > 126)
        {
            sprite->x2 = 0;
            sBitfield &= MASK_TARGET_Y;
        }
    }
    sprite->x = sX >> 7;
    if (sprite->y + sprite->y2 > (sBitfield & MASK_TARGET_Y))
        sprite->callback = SpriteCB_Sparkle_End;
}

void SpriteCB_Sparkle_Init(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    s16 xMult, xDiv;
    s32 var;
    u32 zero = 0;

    var = 640;
    sYSpeed = var;
    sYAccel = 32;
    sBitfield = 168; // Setting bits in MASK_TARGET_Y
    xMult = sprite->x2 * 128;
    xDiv = MathUtil_Div16Shift(7, (168 - sprite->y) << 7, (var + 32) >> 1);
    sprite->sX = sprite->x << 7;
    sXSpeed = MathUtil_Div16Shift(7, xMult, xDiv);
    var = MathUtil_Mul16Shift(7, xDiv, 85);
    sSinIdx = zero;
    sSinSpeed = MathUtil_Div16Shift(7, Q_8_8(63.5), var);
    sAmplitude = sprite->x2 / 4;
    sBitfield |= F_MOVE_HORIZ;
    sprite->y2 = zero;
    sprite->x2 = zero;
    sprite->callback = SpriteCB_Sparkle;
    sprite->animPaused = FALSE;
    sprite->invisible = FALSE;
}

void RunOrScheduleCommand(u16 cmdId, u8 mode, u8 *args)
{
    struct BerryCrushGame *game = GetBerryCrushGame();

    if (cmdId >= ARRAY_COUNT(sBerryCrushCommands))
        cmdId = CMD_NONE;
    switch (mode)
    {
    case RUN_CMD:
        if (cmdId != CMD_NONE)
            sBerryCrushCommands[cmdId](game, args);
        if (game->nextCmd >= ARRAY_COUNT(sBerryCrushCommands))
            game->nextCmd = CMD_NONE;
        game->cmdCallback = sBerryCrushCommands[game->nextCmd];
        break;
    case SCHEDULE_CMD:
        game->cmdCallback = sBerryCrushCommands[cmdId];
        break;
    }
}

u32 Cmd_WaitPaletteFade(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        if (UpdatePaletteFade())
            return 0;
        if(args[0] != 0)
            game->cmdState++;
        else
            game->cmdState = 3;
        return 0;
    case 1:
        Rfu_SetLinkStandbyCallback();
        game->cmdState++;
        return 0;
    case 2:
        if (IsLinkTaskFinished())
        {
            game->cmdState++;
            return 0;
        }
        return 0;
    case 3:
        RunOrScheduleCommand(game->afterPalFadeCmd, SCHEDULE_CMD, NULL);
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_PrintMessage(struct BerryCrushGame *game, u8 *args)
{
    u16 keys = args[3];
    keys <<= 8;
    keys |= args[2];

    switch (game->cmdState)
    {
    case 0:
        DrawDialogueFrame(0, FALSE);
        if (args[1] & F_MSG_EXPAND)
        {
            StringExpandPlaceholders(gStringVar4, sMessages[args[0]]);
            AddTextPrinterParameterized2(0, FONT_NORMAL, gStringVar4, game->textSpeed, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        }
        else
        {
            AddTextPrinterParameterized2(0, FONT_NORMAL, sMessages[args[0]], game->textSpeed, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        }
        CopyWindowToVram(0, COPYWIN_FULL);
        break;
    case 1:
        if (!IsTextPrinterActive(0))
        {
            // If no wait keys are given, skip
            // waiting state below
            if (keys == 0)
                game->cmdState++;
            break;
        }
        return 0;
    case 2:
        if (!JOY_NEW(keys))
            return 0;
        break;
    case 3:
        if (args[1] & F_MSG_CLEAR)
            ClearDialogWindowAndFrame(0, TRUE);
        RunOrScheduleCommand(game->nextCmd, SCHEDULE_CMD, NULL);
        game->cmdState = args[4];
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_ShowGameDisplay(struct BerryCrushGame *game, u8 *args)
{
    if (ShowGameDisplay())
        RunOrScheduleCommand(game->nextCmd, RUN_CMD, game->commandArgs);
    return 0;
}

u32 Cmd_HideGameDisplay(struct BerryCrushGame *game, u8 *args)
{
    if (HideGameDisplay())
        RunOrScheduleCommand(game->nextCmd, RUN_CMD, game->commandArgs);
    return 0;
}

u32 Cmd_SignalReadyToBegin(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        Rfu_SetLinkStandbyCallback();
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            PlayNewMapMusic(MUS_RG_GAME_CORNER);
            RunOrScheduleCommand(CMD_ASK_PICK_BERRY, SCHEDULE_CMD, NULL);
            game->gameState = STATE_PICK_BERRY;
            game->cmdState = 0;
        }
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_AskPickBerry(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    default:
        game->cmdState++;
        break;
    case 0:
        ResetGame(game);
        SetPrintMessageArgs(args, MSG_PICK_BERRY, F_MSG_CLEAR, 0, 1);
        game->nextCmd = CMD_ASK_PICK_BERRY;
        RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
        break;
    case 1:
        game->nextCmd = CMD_PICK_BERRY;
        RunOrScheduleCommand(CMD_HIDE_GAME, SCHEDULE_CMD, NULL);
        game->cmdState = 2;
        break;
    }
    return 0;
}

u32 Cmd_GoToBerryPouch(struct BerryCrushGame *game, u8 *args)
{
    game->cmdCallback = NULL;
    SetMainCallback2(ChooseBerry);
    return 0;
}

u32 Cmd_WaitForOthersToPickBerries(struct BerryCrushGame *game, u8 *args)
{
    u8 i;

    switch (game->cmdState)
    {
    case 0:
        SetPrintMessageArgs(args, MSG_WAIT_PICK, 0, 0, 1);
        game->nextCmd = CMD_WAIT_BERRIES;
        RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
        return 0;
    case 1:
        Rfu_SetLinkStandbyCallback();
        break;
    case 2:
        if (!IsLinkTaskFinished())
            return 0;

        // Send player's chosen berry to partners
        memset(game->sendCmd, 0, sizeof(game->sendCmd));
        game->sendCmd[0] = game->players[game->localId].berryId;
        SendBlock(0, game->sendCmd, 2);
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        game->cmdTimer = 0;
        break;
    case 4:
        // Wait for partners responses
        if (GetBlockReceivedStatus() != sReceivedPlayerBitmasks[game->playerCount - 2])
            return 0;

        // Read partners chosen berries
        for (i = 0; i < game->playerCount; i++)
        {
            game->players[i].berryId = gBlockRecvBuffer[i][0];
            if (game->players[i].berryId > LAST_BERRY_INDEX + 1)
                game->players[i].berryId = 0;
            game->targetAPresses += gBerryCrush_BerryData[game->players[i].berryId].difficulty;
            game->powder += gBerryCrush_BerryData[game->players[i].berryId].powder;
        }
        game->cmdTimer = 0;
        ResetBlockReceivedFlags();
        game->targetDepth = MathUtil_Div32(Q_24_8(game->targetAPresses), Q_24_8(32));
        break;
    case 5:
        ClearDialogWindowAndFrame(0, TRUE);
        RunOrScheduleCommand(CMD_DROP_BERRIES, SCHEDULE_CMD, NULL);
        game->gameState = STATE_DROP_BERRIES;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_DropBerriesIntoCrusher(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        CreateBerrySprites(game, &game->gfx);
        Rfu_SetLinkStandbyCallback();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        game->gfx.counter = 0;
        game->gfx.vibrationIdx = 0;
        game->gfx.numVibrations = 0;
        game->gfx.vibrating = FALSE;
        break;
    case 2:
        game->gfx.berrySprites[game->gfx.counter]->callback = SpriteCB_DropBerryIntoCrusher;
        game->gfx.berrySprites[game->gfx.counter]->affineAnimPaused = FALSE;
        PlaySE(SE_BALL_THROW);
        break;
    case 3:
        if (game->gfx.berrySprites[game->gfx.counter]->callback == SpriteCB_DropBerryIntoCrusher)
            return 0;
        game->gfx.berrySprites[game->gfx.counter] = NULL;
        game->gfx.counter++;
        Rfu_SetLinkStandbyCallback();
        break;
    case 4:
        if (!IsLinkTaskFinished())
            return 0;
        if (game->gfx.counter < game->playerCount)
        {
            game->cmdState = 2;
            return 0;
        }
        game->gfx.counter = 0;
        break;
    case 5:
        BerryCrushFreeBerrySpriteGfx(game, &game->gfx);
        Rfu_SetLinkStandbyCallback();
        break;
    case 6:
        if (!IsLinkTaskFinished())
            return 0;
        PlaySE(SE_FALL);
        RunOrScheduleCommand(CMD_DROP_LID, SCHEDULE_CMD, NULL);
        game->gameState = STATE_DROP_LID;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_DropLid(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        game->depth += 4;
        if (game->depth < 0)
            return 0;
        game->depth = 0;
        game->gfx.vibrationIdx = 4;
        game->gfx.counter = 0;
        game->gfx.numVibrations = sIntroOutroVibrationData[game->gfx.vibrationIdx][0];
        PlaySE(SE_M_STRENGTH);
        break;
    case 1:
        game->vibration = sIntroOutroVibrationData[game->gfx.vibrationIdx][game->gfx.counter];
        SetGpuReg(REG_OFFSET_BG0VOFS, -game->vibration);
        SetGpuReg(REG_OFFSET_BG2VOFS, -game->vibration);
        SetGpuReg(REG_OFFSET_BG3VOFS, -game->vibration);
        game->gfx.counter++;
        if (game->gfx.counter < game->gfx.numVibrations)
            return 0;
        if (game->gfx.vibrationIdx == 0)
            break;
        game->gfx.vibrationIdx--;
        game->gfx.numVibrations = sIntroOutroVibrationData[game->gfx.vibrationIdx][0];
        game->gfx.counter = 0;
        return 0;
    case 2:
        game->vibration = 0;
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        Rfu_SetLinkStandbyCallback();
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        RunOrScheduleCommand(CMD_COUNTDOWN, SCHEDULE_CMD, NULL);
        game->gameState = STATE_COUNTDOWN;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_Countdown(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        StartMinigameCountdown(TAG_COUNTDOWN, TAG_COUNTDOWN, 120, 80, 0);
        break;
    case 2:
        if (IsMinigameCountdownRunning())
            return 0;
        // fallthrough
    case 0:
        Rfu_SetLinkStandbyCallback();
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        game->gfx.counter = 0;
        game->gfx.vibrationIdx = 0;
        game->gfx.numVibrations = 0;
        game->gfx.vibrating = FALSE;
        game->cmdTimer = 0;
        if (game->localId == 0)
            RunOrScheduleCommand(CMD_PLAY_GAME_LEADER, SCHEDULE_CMD, NULL);
        else
            RunOrScheduleCommand(CMD_PLAY_GAME_MEMBER, SCHEDULE_CMD, NULL);
        game->gameState = STATE_PLAYING;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

// Receive and process data from all players
// Only used by the link leader
void HandlePartnerInput(struct BerryCrushGame *game)
{
    u8 numPlayersPressed = 0;
    u8 i = 0;
    u16 timeDiff;
    s32 temp = 0;
    struct BerryCrushGame_LinkState *linkState;

    for (i = 0; i < game->playerCount; i++)
    {
        linkState = (struct BerryCrushGame_LinkState *)gRecvCmds[i];

        // Skip player if we have not received a packet from them
        if ((linkState->rfuCmd & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
            continue;
        if (linkState->sendFlag != SEND_GAME_STATE)
            continue;

        if (linkState->pushedAButton)
        {
            game->localState.playerPressedAFlags |= sBitTable[i];
            game->players[i].inputState = INPUT_STATE_HIT;
            game->players[i].numAPresses++;
            numPlayersPressed++;
            timeDiff = game->timer - game->players[i].inputTime;

            // If the interval between inputs is regular, the input is considered "neat"
            // This counts toward the player's neatness score
            if (timeDiff >= game->players[i].timeSincePrevInput - 1
             && timeDiff <= game->players[i].timeSincePrevInput + 1)
            {
                // On neat input streak
                game->players[i].neatInputStreak++;
                game->players[i].timeSincePrevInput = timeDiff;
                if (game->players[i].neatInputStreak > game->players[i].maxNeatInputStreak)
                    game->players[i].maxNeatInputStreak = game->players[i].neatInputStreak;
            }
            else
            {
                // End neat input streak
                game->players[i].neatInputStreak = 0;
                game->players[i].timeSincePrevInput = timeDiff;
            }

            game->players[i].inputTime = game->timer;
            game->players[i].inputFlags++;
            if (game->players[i].inputFlags > F_INPUT_HIT_B)
                game->players[i].inputFlags = 0;
        }
        else
        {
            game->players[i].inputState = INPUT_STATE_NONE;
        }
    }
    if (numPlayersPressed > 1)
    {
        // For each player that pressed A, flag their input as synchronous
        // This is used to change their impact sprite to a big impact
        for (i = 0; i < game->playerCount; i++)
        {
            if (game->players[i].inputState == INPUT_STATE_NONE)
                continue;
            game->players[i].inputState |= INPUT_STATE_HIT_SYNC;
            game->players[i].numSyncedAPresses++;
        }
    }
    if (numPlayersPressed == 0)
        return;

    game->bigSparkleCounter += numPlayersPressed;
    numPlayersPressed += sSyncPressBonus[numPlayersPressed - 1];
    game->sparkleCounter += numPlayersPressed;
    game->totalAPresses += numPlayersPressed;
    if (game->targetAPresses - game->totalAPresses > 0)
    {
        temp = (s32)game->totalAPresses;
        temp = Q_24_8(temp);
        temp = MathUtil_Div32(temp, game->targetDepth);
        temp = Q_24_8_TO_INT(temp);
        game->newDepth = (u8)temp;
        return;
    }

    // Target number of A presses has been reached, game is complete
    game->newDepth = 32;
    game->localState.endGame = TRUE;
}

// Updates the crusher, input flags, and timer to send to group members
// Only used by the link leader
void UpdateLeaderGameState(struct BerryCrushGame *game)
{
    u8 numPlayersPressed = 0;
    u16 flags = 0;
    u16 temp = 0;
    u8 i = 0;

    for (i = 0; i < game->playerCount; i++)
    {
        if (game->players[i].inputState != INPUT_STATE_NONE)
        {
            numPlayersPressed++;
            flags = game->players[i].inputFlags + F_INPUT_HIT_A;
            if (game->players[i].inputState & INPUT_STATE_HIT_SYNC)
                flags |= F_INPUT_HIT_SYNC;
            flags <<= INPUT_FLAGS_PER_PLAYER * i;
            game->localState.inputFlags |= flags;
        }
    }
    temp = (u16)game->newDepth;
    game->localState.depth = temp;
    if (numPlayersPressed == 0)
    {
        if (game->gfx.vibrating)
            game->gfx.counter++;
    }
    else if (game->gfx.vibrating)
    {
        if (numPlayersPressed != game->gfx.vibrationIdx)
        {
            game->gfx.vibrationIdx = numPlayersPressed - 1;
            game->gfx.numVibrations = sVibrationData[numPlayersPressed - 1][0];
        }
        else
        {
            game->gfx.counter++;
        }
    }
    else
    {
        game->gfx.counter = 0;
        game->gfx.vibrationIdx = numPlayersPressed - 1;
        game->gfx.numVibrations = sVibrationData[numPlayersPressed - 1][0];
        game->gfx.vibrating = TRUE;
    }

    if (game->gfx.vibrating)
    {
        if (game->gfx.counter >= game->gfx.numVibrations)
        {
            game->gfx.counter = 0;
            game->gfx.vibrationIdx = 0;
            game->gfx.numVibrations = 0;
            game->gfx.vibrating = FALSE;
            temp = 0;
        }
        else
        {
            temp = sVibrationData[game->gfx.vibrationIdx][game->gfx.counter + 1];
        }
        game->localState.vibration = (u8)temp;
    }
    else
    {
        game->localState.vibration = 0;
    }
    game->localState.timer = game->leaderTimer;
}

// Checks for input and sends data to group members
void HandlePlayerInput(struct BerryCrushGame *game)
{
    if (JOY_NEW(A_BUTTON))
        game->localState.pushedAButton = TRUE;

    if (JOY_HELD(A_BUTTON))
    {
        if (game->players[game->localId].timePressingA < game->timer)
            game->players[game->localId].timePressingA++;
    }

    // Only send data to other players if you are the leader or you pressed A
    if (game->localId != 0 && !game->localState.pushedAButton)
        return;
    game->localState.sendFlag = SEND_GAME_STATE;

    // Every 30 frames, check whether the sparkles produced should be big,
    // depending on how many A presses there were in that time
    if (game->timer % 30 == 0)
    {
        if (game->bigSparkleCounter > sBigSparkleThresholds[game->playerCount - 2])
        {
            game->numBigSparkles++;
            game->bigSparkle = TRUE;
        }
        else
        {
            game->bigSparkle = FALSE;
        }
        game->bigSparkleCounter = 0;
        game->numBigSparkleChecks++;
    }

    // Every 15 frames, update the amount of sparkles that should be produced,
    // depending on how many A presses there were in that time (including the bonus)
    if (game->timer % 15 == 0)
    {
        // BUG: The wrong field is used twice below
        // As a result, only a sparkleAmount of 0, 1, or 4 is attainable
        #ifdef BUGFIX
        #define field sparkleAmount
        #else
        #define field sparkleCounter
        #endif

        if (game->sparkleCounter < sSparkleThresholds[game->playerCount - 2][0])
            game->sparkleAmount = 0;
        else if (game->sparkleCounter < sSparkleThresholds[game->playerCount - 2][1])
            game->sparkleAmount = 1;
        else if (game->sparkleCounter < sSparkleThresholds[game->playerCount - 2][2])
            game->field = 2;
        else if (game->sparkleCounter < sSparkleThresholds[game->playerCount - 2][3])
            game->field = 3;
        else
            game->sparkleAmount = 4;
        game->sparkleCounter = 0;

        #undef field
    }
    else
    {
        game->cmdTimer++;
        if (game->cmdTimer > 60)
        {
            if (game->cmdTimer > 70)
            {
                ClearRecvCommands();
                game->cmdTimer = 0;
            }
            else if (game->localState.playerPressedAFlags == 0)
            {
                ClearRecvCommands();
                game->cmdTimer = 0;
            }
        }

    }
    if (game->timer >= MAX_TIME)
        game->localState.endGame = TRUE;
    game->localState.bigSparkle = game->bigSparkle;
    game->localState.sparkleAmount = game->sparkleAmount;
    memcpy(game->sendCmd, &game->localState, sizeof(game->sendCmd));
    Rfu_SendPacket(game->sendCmd);
}

void RecvLinkData(struct BerryCrushGame *game)
{
    u8 i = 0;
    struct BerryCrushGame_LinkState *linkState = NULL;

    for (i = 0; i < game->playerCount; i++)
        game->players[i].inputState = INPUT_STATE_NONE;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
    {
        game->playedSound = FALSE;
        return;
    }
    if (gRecvCmds[0][1] != 2)
    {
        game->playedSound = FALSE;
        return;
    }

    memcpy(game->recvCmd, gRecvCmds[0], sizeof(game->recvCmd));
    linkState = (struct BerryCrushGame_LinkState *)&game->recvCmd;
    game->depth = linkState->depth;
    game->vibration = (s16)linkState->vibration;
    game->timer = linkState->timer;
    UpdateInputEffects(game, &(game->gfx));

    if (linkState->endGame)
        game->endGame = TRUE;
}

u32 Cmd_PlayGame_Leader(struct BerryCrushGame *game, u8 *args)
{
    memset(&game->localState, 0, sizeof(game->localState));
    memset(&game->recvCmd, 0, sizeof(game->recvCmd));
    RecvLinkData(game);
    SetGpuReg(REG_OFFSET_BG0VOFS, -game->vibration);
    SetGpuReg(REG_OFFSET_BG2VOFS, -game->vibration);
    SetGpuReg(REG_OFFSET_BG3VOFS, -game->vibration);
    if (game->endGame)
    {
        if (game->timer >= MAX_TIME)
        {
            game->timer = MAX_TIME;
            RunOrScheduleCommand(CMD_TIMES_UP, SCHEDULE_CMD, NULL);
        }
        else
        {
            RunOrScheduleCommand(CMD_FINISH_GAME, SCHEDULE_CMD, NULL);
        }
        game->cmdTimer = 0;
        game->cmdState = 0;
        return 0;
    }
    else
    {
        game->leaderTimer++;
        HandlePartnerInput(game);
        UpdateLeaderGameState(game);
        HandlePlayerInput(game);
        return 0;
    }
}

u32 Cmd_PlayGame_Member(struct BerryCrushGame *game, u8 *args)
{
    memset(&game->localState, 0, sizeof(game->localState));
    memset(&game->recvCmd, 0, sizeof(game->recvCmd));
    RecvLinkData(game);
    SetGpuReg(REG_OFFSET_BG0VOFS, -game->vibration);
    SetGpuReg(REG_OFFSET_BG2VOFS, -game->vibration);
    SetGpuReg(REG_OFFSET_BG3VOFS, -game->vibration);
    if (game->endGame)
    {
        if (game->timer >= MAX_TIME)
        {
            game->timer = MAX_TIME;
            RunOrScheduleCommand(CMD_TIMES_UP, SCHEDULE_CMD, NULL);
        }
        else
        {
            RunOrScheduleCommand(CMD_FINISH_GAME, SCHEDULE_CMD, NULL);
        }
        game->cmdTimer = 0;
        game->cmdState = 0;
        return 0;
    }
    else
    {
        HandlePlayerInput(game);
        return 0;
    }
}

// Game was 'won', crusher was pushed down fully before time was up
u32 Cmd_FinishGame(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        game->gameState = STATE_FINISHED;
        PlaySE(SE_M_STRENGTH);
        BlendPalettes(PALETTES_ALL, 8, RGB_YELLOW);
        game->gfx.counter = 2;
        break;
    case 1:
        if (--game->gfx.counter != (u8)-1)
            return 0;
        BlendPalettes(PALETTES_ALL, 0, RGB_YELLOW);
        game->gfx.vibrationIdx = 4;
        game->gfx.counter = 0;
        game->gfx.numVibrations = sIntroOutroVibrationData[game->gfx.vibrationIdx][0];
        break;
    case 2:
        game->vibration = sIntroOutroVibrationData[game->gfx.vibrationIdx][game->gfx.counter];
        SetGpuReg(REG_OFFSET_BG0VOFS, -game->vibration);
        SetGpuReg(REG_OFFSET_BG2VOFS, -game->vibration);
        SetGpuReg(REG_OFFSET_BG3VOFS, -game->vibration);
        if (++game->gfx.counter < game->gfx.numVibrations)
            return 0;
        if (game->gfx.vibrationIdx != 0)
        {
            game->gfx.vibrationIdx--;
            game->gfx.numVibrations = sIntroOutroVibrationData[game->gfx.vibrationIdx][0];
            game->gfx.counter = 0;
            return 0;
        }
        break;
    case 3:
        game->vibration = 0;
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        break;
    case 4:
        if (!AreEffectsFinished(game, &game->gfx))
            return 0;
        Rfu_SetLinkStandbyCallback();
        game->cmdTimer = 0;
        break;
    case 5:
        if (!IsLinkTaskFinished())
            return 0;
        RunOrScheduleCommand(CMD_CALC_RESULTS, SCHEDULE_CMD, NULL);
        game->cmdTimer = 0;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_HandleTimeUp(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        game->gameState = STATE_TIMES_UP;
        PlaySE(SE_FAILURE);
        BlendPalettes(PALETTES_ALL, 8, RGB_RED);
        game->gfx.counter = 4;
        break;
    case 1:
        if (--game->gfx.counter != (u8)-1)
            return 0;
        BlendPalettes(PALETTES_ALL, 0, RGB_RED);
        game->gfx.counter = 0;
        break;
    case 2:
        if (!AreEffectsFinished(game, &game->gfx))
            return 0;
        Rfu_SetLinkStandbyCallback();
        game->cmdTimer = 0;
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        ConvertIntToDecimalStringN(gStringVar1, game->powder, STR_CONV_MODE_LEFT_ALIGN, 6);
        SetPrintMessageArgs(args, MSG_TIMES_UP, F_MSG_CLEAR, 0, 0);
        game->nextCmd = CMD_SAVE;
        RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
        game->cmdTimer = 0;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_ShowResults(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        if (!OpenResultsWindow(game, &game->gfx))
            return 0;
        break;
    case 1:
        CopyBgTilemapBufferToVram(0);
        game->gfx.counter = 30;
        break;
    case 2:
        if (game->gfx.counter != 0)
        {
            game->gfx.counter--;
            return 0;
        }
        if (!(JOY_NEW(A_BUTTON)))
            return 0;
        PlaySE(SE_SELECT);
        CloseResultsWindow(game);
        break;
    case 3:
        // Progress through each page of the results
        if (game->gameState < RESULTS_STATE_END)
        {
            game->gameState++;
            game->cmdState = 0;
            return 0;
        }
        break;
    case 4:
        // Print message showing how much powder was created
        ConvertIntToDecimalStringN(gStringVar1, game->powder, STR_CONV_MODE_LEFT_ALIGN, 6);
        ConvertIntToDecimalStringN(gStringVar2, GetBerryPowder(), STR_CONV_MODE_LEFT_ALIGN, 6);
        SetPrintMessageArgs(args, MSG_POWDER, F_MSG_CLEAR | F_MSG_EXPAND, 0, 0);
        game->nextCmd = CMD_SAVE;
        RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_SaveGame(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        if (game->timer >= MAX_TIME)
            HideTimer(&game->gfx);
        SetPrintMessageArgs(args, MSG_COMM_STANDBY, 0, 0, 1);
        game->nextCmd = CMD_SAVE;
        RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
        game->cmdState = 0; // State is progressed by CMD_PRINT_MSG
        return 0;
    case 1:
        Rfu_SetLinkStandbyCallback();
        break;
    case 2:
        if (!IsLinkTaskFinished())
            return 0;
        DrawDialogueFrame(0, FALSE);
        AddTextPrinterParameterized2(0, FONT_NORMAL, gText_SavingDontTurnOffPower, 0, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        CopyWindowToVram(0, COPYWIN_FULL);
        CreateTask(Task_LinkFullSave, 0);
        break;
    case 3:
        if (FuncIsActiveTask(Task_LinkFullSave))
            return 0;
        break;
    case 4:
        RunOrScheduleCommand(CMD_ASK_PLAY_AGAIN, SCHEDULE_CMD, NULL);
        game->gameState = STATE_PLAY_AGAIN;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_AskPlayAgain(struct BerryCrushGame *game, u8 *args)
{
    s8 input = 0;

    switch (game->cmdState)
    {
    case 0:
        SetPrintMessageArgs(args, MSG_PLAY_AGAIN, 0, 0, 1);
        game->nextCmd = CMD_ASK_PLAY_AGAIN;
        RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
        game->cmdState = 0; // State is progressed by CMD_PRINT_MSG
        return 0;
    case 1:
        DisplayYesNoMenuDefaultYes();
        break;
    case 2:
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input != -2)
        {
            memset(game->sendCmd, 0, sizeof(game->sendCmd));
            if (input == 0)
            {
                // Selected Yes
                if (HasAtLeastOneBerry())
                    game->playAgainState = PLAY_AGAIN_YES;
                else
                    game->playAgainState = PLAY_AGAIN_NO_BERRIES;
            }
            else
            {
                // Selected No
                game->playAgainState = PLAY_AGAIN_NO;
            }

            // Close Yes/No and start communication
            ClearDialogWindowAndFrame(0, TRUE);
            SetPrintMessageArgs(args, MSG_COMM_STANDBY, 0, 0, 0);
            game->nextCmd = CMD_COMM_PLAY_AGAIN;
            RunOrScheduleCommand(CMD_PRINT_MSG, SCHEDULE_CMD, NULL);
            game->cmdState = 0;
        }
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_CommunicatePlayAgainResponses(struct BerryCrushGame *game, u8 *args)
{
    u8 i = 0;

    switch (game->cmdState)
    {
    case 0:
        Rfu_SetLinkStandbyCallback();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;

        // Send player's Yes/No response to partners
        game->sendCmd[0] = game->playAgainState;
        game->recvCmd[0] = 0;
        SendBlock(0, game->sendCmd, sizeof(u16));
        break;
    case 2:
        if (!IsLinkTaskFinished())
            return 0;
        game->cmdTimer = 0;
        break;
    case 3:
        // Wait for partners responses
        if (GetBlockReceivedStatus() != sReceivedPlayerBitmasks[game->playerCount - 2])
            return 0;

        // Read partners responses
        for (i = 0; i < game->playerCount; i++)
            game->recvCmd[0] += gBlockRecvBuffer[i][0];

        if (game->recvCmd[0] != PLAY_AGAIN_YES)
            RunOrScheduleCommand(CMD_PLAY_AGAIN_NO, SCHEDULE_CMD, NULL);
        else
            RunOrScheduleCommand(CMD_PLAY_AGAIN_YES, SCHEDULE_CMD, NULL);
        ResetBlockReceivedFlags();
        game->sendCmd[0] = 0;
        game->recvCmd[0] = 0;
        game->cmdTimer = 0;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_PlayAgain(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 16, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 1:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 2:
        ClearDialogWindowAndFrame(0, TRUE);
        ResetCrusherPos(game);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 3:
        if (UpdatePaletteFade())
            return 0;
        RunOrScheduleCommand(CMD_ASK_PICK_BERRY, SCHEDULE_CMD, NULL);
        game->gameState = STATE_PICK_BERRY;
        game->cmdState = 0;
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_StopGame(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        DrawDialogueFrame(0, FALSE);
        if (game->playAgainState == PLAY_AGAIN_NO_BERRIES)
            AddTextPrinterParameterized2(0, FONT_NORMAL, sMessages[MSG_NO_BERRIES], game->textSpeed, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        else
            AddTextPrinterParameterized2(0, FONT_NORMAL, sMessages[MSG_DROPPED], game->textSpeed, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        CopyWindowToVram(0, COPYWIN_FULL);
        break;
    case 1:
        if (IsTextPrinterActive(0))
            return 0;
        game->gfx.counter = 120;
        break;
    case 2:
        if (game->gfx.counter != 0)
        {
            game->gfx.counter--;
        }
        else
        {
            RunOrScheduleCommand(CMD_CLOSE_LINK, SCHEDULE_CMD, NULL);
            game->cmdState = 0;
        }
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_CloseLink(struct BerryCrushGame *game, u8 *args)
{
    switch (game->cmdState)
    {
    case 0:
        Rfu_SetLinkStandbyCallback();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        SetCloseLinkCallback();
        break;
    case 2:
        if (gReceivedRemoteLinkPlayers)
            return 0;
        game->nextCmd = CMD_QUIT;
        RunOrScheduleCommand(CMD_HIDE_GAME, SCHEDULE_CMD, NULL);
        game->cmdState = 2; // ???
        return 0;
    }
    game->cmdState++;
    return 0;
}

u32 Cmd_Quit(struct BerryCrushGame *game, u8 *args)
{
    QuitBerryCrush(NULL);
    return 0;
}

void ResetGame(struct BerryCrushGame *game)
{
    u8 i = 0;

    IncrementGameStat(GAME_STAT_PLAYED_BERRY_CRUSH);
    game->unused = 0;
    game->cmdTimer = 0;
    game->gameState = STATE_RESET;
    game->playAgainState = 0;
    game->powder = 0;
    game->targetAPresses = 0;
    game->totalAPresses = 0;
    game->targetDepth = 0;
    game->newDepth = 0;
    game->noRoomForPowder = FALSE;
    game->newRecord = FALSE;
    game->playedSound = FALSE;
    game->endGame = FALSE;
    game->bigSparkle = FALSE;
    game->sparkleAmount = 0;
    game->leaderTimer = 0;
    game->timer = 0;
    game->bigSparkleCounter = 0;
    game->numBigSparkleChecks = -1;
    game->numBigSparkles = 0;
    game->sparkleCounter = 0;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        game->players[i].berryId = -1;
        game->players[i].inputTime = 0;
        game->players[i].neatInputStreak = 0;
        game->players[i].timeSincePrevInput = 1;
        game->players[i].maxNeatInputStreak = 0;
        game->players[i].numAPresses = 0;
        game->players[i].numSyncedAPresses = 0;
        game->players[i].timePressingA = 0;
        game->players[i].inputFlags = 0;
        game->players[i].inputState = INPUT_STATE_NONE;
    }
}

void SetPaletteFadeArgs(u8 *args, bool8 communicateAfter, u32 selectedPals, s8 delay, u8 startY, u8 targetY, u16 palette)
{
    args[0] = ((u8 *)&selectedPals)[0];
    args[1] = ((u8 *)&selectedPals)[1];
    args[2] = ((u8 *)&selectedPals)[2];
    args[3] = ((u8 *)&selectedPals)[3];
    args[4] = delay;
    args[5] = startY;
    args[6] = targetY;
    args[7] = ((u8 *)&palette)[0];
    args[8] = ((u8 *)&palette)[1];
    args[9] = communicateAfter;
}

void SetPrintMessageArgs(u8 *args, u8 msgId, u8 flags, u16 waitKeys, u8 followupState)
{
    args[0] = msgId;
    args[1] = flags;
    args[2] = ((u8 *)&waitKeys)[0];
    args[3] = ((u8 *)&waitKeys)[1];
    args[4] = followupState;
}

void CloseResultsWindow(struct BerryCrushGame *game)
{
    ClearStdWindowAndFrameToTransparent(game->gfx.resultsWindowId, TRUE);
    RemoveWindow(game->gfx.resultsWindowId);
    DrawPlayerNameWindows(game);
}

bool32 OpenResultsWindow(struct BerryCrushGame *game, struct BerryCrushGame_Gfx *gfx)
{
    u8 playerCountIdx;
    struct WindowTemplate template;

    switch (gfx->resultsState)
    {
    case 0:
        playerCountIdx = game->playerCount - 2;
        HideTimer(gfx);
        memcpy(&template, &sWindowTemplates_Results[game->gameState], sizeof(struct WindowTemplate));
        if (game->gameState == STATE_RESULTS_CRUSHING)
            template.height = sResultsWindowHeights[1][playerCountIdx];
        else
            template.height = sResultsWindowHeights[0][playerCountIdx];
        gfx->resultsWindowId = AddWindow(&template);
        break;
    case 1:
        PutWindowTilemap(gfx->resultsWindowId);
        FillWindowPixelBuffer(gfx->resultsWindowId, PIXEL_FILL(0));
        break;
    case 2:
        LoadUserWindowBorderGfx_(gfx->resultsWindowId, 541, BG_PLTT_ID(13));
        DrawStdFrameWithCustomTileAndPalette(gfx->resultsWindowId, FALSE, 541, 13);
        break;
    case 3:
        playerCountIdx = game->playerCount - 2;
        switch (game->gameState)
        {
        case STATE_RESULTS_PRESSES:
            PrintTextCentered(gfx->resultsWindowId, 20, COLORID_BLUE, gText_PressesRankings);
            PrintResultsText(game, RESULTS_PAGE_PRESSES, 0xA0, 8 * sResultsWindowHeights[0][playerCountIdx] - game->playerCount * 13);
            gfx->resultsState = 5; // Skip past Crushing Results text
            return FALSE;
        case STATE_RESULTS_RANDOM:
            PrintTextCentered(gfx->resultsWindowId, 20, COLORID_GREEN, sResultsTexts[game->results.randomPageId + NUM_RESULTS_PAGES]);
            PrintResultsText(game, RESULTS_PAGE_RANDOM, 0xA0, 8 * sResultsWindowHeights[0][playerCountIdx] - game->playerCount * 13);
            gfx->resultsState = 5; // Skip past Crushing Results text
            return FALSE;
        case STATE_RESULTS_CRUSHING:
            PrintTextCentered(gfx->resultsWindowId, 22, COLORID_BLUE, gText_CrushingResults);
            PrintResultsText(game, RESULTS_PAGE_CRUSHING, 0xB0, 18);
            break;
        }
        break;
    case 4:
        PrintCrushingResults(game);
        break;
    case 5:
        CopyWindowToVram(gfx->resultsWindowId, COPYWIN_FULL);
        gfx->resultsState = 0;
        return TRUE;
    }
    gfx->resultsState++;
    return FALSE;
}

#define tState             data[0]
#define tWindowId          data[1]
#define tPressingSpeeds(i) data[2 + (i)] // data[2]-[5], for different group sizes

extern void Task_ShowRankings(u8 taskId);

void ShowBerryCrushRankings(void)
{
    u8 taskId;

    LockPlayerFieldControls();
    taskId = CreateTask(Task_ShowRankings, 0);
    gTasks[taskId].tPressingSpeeds(0) = gSaveBlock2Ptr->berryCrush.pressingSpeeds[0];
    gTasks[taskId].tPressingSpeeds(1) = gSaveBlock2Ptr->berryCrush.pressingSpeeds[1];
    gTasks[taskId].tPressingSpeeds(2) = gSaveBlock2Ptr->berryCrush.pressingSpeeds[2];
    gTasks[taskId].tPressingSpeeds(3) = gSaveBlock2Ptr->berryCrush.pressingSpeeds[3];
}

void PrintTextCentered(u8 windowId, u8 left, u8 colorId, const u8 *string)
{
    left = (left * 4) - (GetStringWidth(FONT_NORMAL, string, -1) / 2u);
    AddTextPrinterParameterized3(windowId, FONT_NORMAL, left, 0, sTextColorTable[colorId], 0, string);
}

__attribute__((naked)) void sub_08021FC0(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x14\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #0xc]\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08021FF4\n\t"
        "	adds r6, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08022040\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _08021FF8\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08022006\n\t"
        "	b _0802221A\n\t"
        "	.align 2, 0\n\t"
        "_08021FF4: .4byte gUnknown_3005B68\n\t"
        "_08021FF8:\n\t"
        "	cmp r0, #2\n\t"
        "	bne _08021FFE\n\t"
        "	b _080221E0\n\t"
        "_08021FFE:\n\t"
        "	cmp r0, #3\n\t"
        "	bne _08022004\n\t"
        "	b _080221F4\n\t"
        "_08022004:\n\t"
        "	b _0802221A\n\t"
        "_08022006:\n\t"
        "	ldr r0, _08022038\n\t"
        "	bl AddWindow\n\t"
        "	strh r0, [r6, #2]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	movs r1, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	ldr r4, _0802203C\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0xd0\n\t"
        "	bl LoadUserWindowBorderGfx_\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #0xd\n\t"
        "	bl DrawStdFrameWithCustomTileAndPalette\n\t"
        "	b _0802221A\n\t"
        "	.align 2, 0\n\t"
        "_08022038: .4byte 0x082C5F04\n\t"
        "_0802203C: .4byte 0x0000021D\n\t"
        "_08022040:\n\t"
        "	ldr r0, _080221B0\n\t"
        "	mov sl, r0\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	mov r8, r1\n\t"
        "	movs r0, #1\n\t"
        "	mov r1, sl\n\t"
        "	mov r2, r8\n\t"
        "	bl GetStringWidth\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	movs r4, #0x60\n\t"
        "	subs r0, r4, r0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	ldr r5, _080221B4\n\t"
        "	str r5, [sp]\n\t"
        "	mov r1, sb\n\t"
        "	str r1, [sp, #4]\n\t"
        "	mov r1, sl\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r7, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r0, _080221B8\n\t"
        "	mov sl, r0\n\t"
        "	movs r0, #1\n\t"
        "	mov r1, sl\n\t"
        "	mov r2, r8\n\t"
        "	bl GetStringWidth\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	subs r4, r4, r0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r7, r4, #0x18\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	str r5, [sp]\n\t"
        "	mov r1, sb\n\t"
        "	str r1, [sp, #4]\n\t"
        "	mov r1, sl\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r7, #0\n\t"
        "	movs r3, #0x12\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	movs r0, #0x2a\n\t"
        "	mov sl, r0\n\t"
        "_080220A6:\n\t"
        "	mov r1, sb\n\t"
        "	adds r1, #2\n\t"
        "	ldr r0, _080221BC\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _080221C0\n\t"
        "	ldr r1, _080221C4\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	ldr r1, _080221C8\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _080221C0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #4\n\t"
        "	mov r3, sl\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	movs r0, #1\n\t"
        "	ldr r1, _080221CC\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	movs r1, #0xbc\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	ldr r1, _080221C8\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _080221CC\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r7, #0\n\t"
        "	mov r3, sl\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	movs r2, #0\n\t"
        "	mov r0, sb\n\t"
        "	lsls r4, r0, #1\n\t"
        "	mov r1, sl\n\t"
        "	adds r1, #0xd\n\t"
        "	str r1, [sp, #0x10]\n\t"
        "	movs r0, #1\n\t"
        "	add sb, r0\n\t"
        "	adds r0, r4, r6\n\t"
        "	ldrb r3, [r0, #4]\n\t"
        "	movs r1, #1\n\t"
        "	mov r8, r1\n\t"
        "	ldr r5, _080221D0\n\t"
        "_0802211A:\n\t"
        "	movs r0, #7\n\t"
        "	subs r1, r0, r2\n\t"
        "	adds r0, r3, #0\n\t"
        "	asrs r0, r1\n\t"
        "	mov r1, r8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08022136\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r1, r1, r0\n\t"
        "	str r1, [sp, #0xc]\n\t"
        "_08022136:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #7\n\t"
        "	bls _0802211A\n\t"
        "	adds r0, r4, r6\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	lsrs r1, r1, #8\n\t"
        "	ldr r0, _080221BC\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #3\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	ldr r1, _080221D4\n\t"
        "	bl __udivsi3\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, _080221D8\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _080221C0\n\t"
        "	ldr r1, _080221DC\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r7, #0\n\t"
        "	subs r0, #0x31\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	ldr r1, _080221C8\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _080221C0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	mov r3, sl\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	mov r1, sb\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	cmp r0, #3\n\t"
        "	bls _080220A6\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	b _0802221A\n\t"
        "	.align 2, 0\n\t"
        "_080221B0: .4byte 0x085CCA70\n\t"
        "_080221B4: .4byte 0x082C5EF9\n\t"
        "_080221B8: .4byte 0x085CCA7C\n\t"
        "_080221BC: .4byte gStringVar1\n\t"
        "_080221C0: .4byte gStringVar4\n\t"
        "_080221C4: .4byte 0x085CCA8C\n\t"
        "_080221C8: .4byte sTextColorTable\n\t"
        "_080221CC: .4byte 0x085CCA20\n\t"
        "_080221D0: .4byte sPressingSpeedConversionTable\n\t"
        "_080221D4: .4byte 0x000F4240\n\t"
        "_080221D8: .4byte gStringVar2\n\t"
        "_080221DC: .4byte 0x085CCA18\n\t"
        "_080221E0:\n\t"
        "	ldr r0, _080221F0\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0802221A\n\t"
        "	b _08022220\n\t"
        "	.align 2, 0\n\t"
        "_080221F0: .4byte gMain\n\t"
        "_080221F4:\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearStdWindowAndFrameToTransparent\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	ldrb r0, [r6, #2]\n\t"
        "	bl RemoveWindow\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	mov r0, sb\n\t"
        "	b _0802221E\n\t"
        "_0802221A:\n\t"
        "	ldrh r0, [r6]\n\t"
        "	adds r0, #1\n\t"
        "_0802221E:\n\t"
        "	strh r0, [r6]\n\t"
        "_08022220:\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_08022434(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r6, r0, #0\n\t"
        "	movs r5, #0\n\t"
        "	ldr r0, _08022448\n\t"
        "	ldr r4, _0802244C\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	b _0802247E\n\t"
        "	.align 2, 0\n\t"
        "_08022448: .4byte sPlayerNameWindowGfx\n\t"
        "_0802244C: .4byte gDecompressionBuffer\n\t"
        "_08022450:\n\t"
        "	lsls r1, r5, #2\n\t"
        "	movs r2, #0x98\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r0, r6, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r4, r1\n\t"
        "	ldrb r2, [r3, #1]\n\t"
        "	ldrb r3, [r3, #2]\n\t"
        "	movs r0, #0xa\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #3\n\t"
        "	bl CopyToBgTilemapBufferRect\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "_0802247E:\n\t"
        "	ldrb r0, [r6, #9]\n\t"
        "	cmp r5, r0\n\t"
        "	blo _08022450\n\t"
        "	movs r0, #3\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_080229BC(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldrb r2, [r1]\n\t"
        "	ldrb r3, [r1, #1]\n\t"
        "	lsls r3, r3, #8\n\t"
        "	orrs r2, r3\n\t"
        "	ldrb r3, [r1, #2]\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	orrs r2, r3\n\t"
        "	ldrb r3, [r1, #3]\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	adds r0, r2, #0\n\t"
        "	orrs r0, r3\n\t"
        "	ldrb r2, [r1, #9]\n\t"
        "	strb r2, [r1]\n\t"
        "	ldrb r4, [r1, #8]\n\t"
        "	lsls r4, r4, #8\n\t"
        "	ldrb r2, [r1, #7]\n\t"
        "	orrs r4, r2\n\t"
        "	ldr r5, _08022A10\n\t"
        "	ldrb r3, [r5, #8]\n\t"
        "	movs r2, #0x7f\n\t"
        "	ands r2, r3\n\t"
        "	strb r2, [r5, #8]\n\t"
        "	movs r5, #4\n\t"
        "	ldrsb r5, [r1, r5]\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	ldrb r3, [r1, #6]\n\t"
        "	str r4, [sp]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	bl UpdatePaletteFade\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r6, #0xe]\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08022A10: .4byte gPaletteFade\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_08023A40(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	ldrb r0, [r0, #0xc]\n\t"
        "	cmp r0, #7\n\t"
        "	bls _08023A56\n\t"
        "	b _08023DF4\n\t"
        "_08023A56:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08023A60\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08023A60: .4byte 0x08023A64\n\t"
        "_08023A64: @ jump table\n\t"
        "	.4byte _08023A84 @ case 0\n\t"
        "	.4byte _08023ACA @ case 1\n\t"
        "	.4byte _08023ADE @ case 2\n\t"
        "	.4byte _08023B52 @ case 3\n\t"
        "	.4byte _08023CE2 @ case 4\n\t"
        "	.4byte _08023D8E @ case 5\n\t"
        "	.4byte _08023DA0 @ case 6\n\t"
        "	.4byte _08023DD4 @ case 7\n\t"
        "_08023A84:\n\t"
        "	mov r4, r8\n\t"
        "	adds r4, #0x42\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #4\n\t"
        "	bl memset\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1, #8]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, r8\n\t"
        "	adds r1, #0xae\n\t"
        "	mov r3, r8\n\t"
        "	ldrh r2, [r3, #0x28]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, r2\n\t"
        "	bls _08023AAC\n\t"
        "	strh r2, [r1]\n\t"
        "_08023AAC:\n\t"
        "	mov r5, r8\n\t"
        "	ldrb r0, [r5, #8]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, r8\n\t"
        "	adds r1, #0xae\n\t"
        "	ldrh r0, [r1]\n\t"
        "	strh r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #2\n\t"
        "	bl SendBlock\n\t"
        "	b _08023DF4\n\t"
        "_08023ACA:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08023AD6\n\t"
        "	b _08023DFC\n\t"
        "_08023AD6:\n\t"
        "	movs r0, #0\n\t"
        "	mov r6, r8\n\t"
        "	strh r0, [r6, #0x10]\n\t"
        "	b _08023DF4\n\t"
        "_08023ADE:\n\t"
        "	bl GetBlockReceivedStatus\n\t"
        "	ldr r2, _08023B44\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r3, [r1, #9]\n\t"
        "	subs r1, r3, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _08023AF8\n\t"
        "	b _08023DFC\n\t"
        "_08023AF8:\n\t"
        "	movs r2, #0\n\t"
        "	mov sb, r2\n\t"
        "	mov r4, r8\n\t"
        "	adds r4, #0x42\n\t"
        "	cmp sb, r3\n\t"
        "	bhs _08023B2C\n\t"
        "	ldr r2, _08023B48\n\t"
        "_08023B06:\n\t"
        "	mov r3, sb\n\t"
        "	lsls r1, r3, #3\n\t"
        "	subs r1, r1, r3\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, r8\n\t"
        "	lsls r0, r3, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	adds r1, #0xae\n\t"
        "	strh r0, [r1]\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	mov r5, r8\n\t"
        "	ldrb r5, [r5, #9]\n\t"
        "	cmp sb, r5\n\t"
        "	blo _08023B06\n\t"
        "_08023B2C:\n\t"
        "	movs r0, #0\n\t"
        "	mov r6, r8\n\t"
        "	strh r0, [r6, #0x10]\n\t"
        "	strh r0, [r4]\n\t"
        "	bl ResetBlockReceivedFlags\n\t"
        "	ldrb r0, [r6, #8]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08023B4C\n\t"
        "	movs r0, #3\n\t"
        "	strb r0, [r6, #0xc]\n\t"
        "	b _08023DFC\n\t"
        "	.align 2, 0\n\t"
        "_08023B44: .4byte sReceivedPlayerBitmasks\n\t"
        "_08023B48: .4byte gBlockRecvBuffer\n\t"
        "_08023B4C:\n\t"
        "	movs r0, #6\n\t"
        "	mov r1, r8\n\t"
        "	b _08023DFA\n\t"
        "_08023B52:\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #0x68\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x30\n\t"
        "	bl memset\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r1, [r2, #0x28]\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #0x6c\n\t"
        "	strh r1, [r0]\n\t"
        "	movs r3, #0x18\n\t"
        "	ldrsh r4, [r2, r3]\n\t"
        "	ldrh r0, [r2, #0x28]\n\t"
        "	movs r1, #0x3c\n\t"
        "	bl __udivsi3\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __divsi3\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x6e\n\t"
        "	strh r0, [r1]\n\t"
        "	mov r5, r8\n\t"
        "	movs r6, #0x30\n\t"
        "	ldrsh r0, [r5, r6]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	movs r4, #0xc8\n\t"
        "	lsls r4, r4, #6\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl MathUtil_Mul32\n\t"
        "	adds r2, r0, #0\n\t"
        "	movs r0, #0x32\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl MathUtil_Div32\n\t"
        "	adds r2, r0, r4\n\t"
        "	asrs r2, r2, #8\n\t"
        "	movs r1, #0x7f\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r1\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x70\n\t"
        "	strh r0, [r1]\n\t"
        "	lsls r2, r2, #8\n\t"
        "	movs r1, #0xc8\n\t"
        "	lsls r1, r1, #7\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl MathUtil_Div32\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldrb r1, [r5, #9]\n\t"
        "	ldr r0, [r5, #0x1c]\n\t"
        "	muls r0, r1, r0\n\t"
        "	lsls r4, r0, #8\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl MathUtil_Mul32\n\t"
        "	adds r4, r0, #0\n\t"
        "	asrs r0, r4, #8\n\t"
        "	str r0, [r5, #0x68]\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	movs r1, #3\n\t"
        "	bl __umodsi3\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x8f\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r2, #0\n\t"
        "	mov sb, r2\n\t"
        "	adds r7, r1, #0\n\t"
        "	ldrb r3, [r5, #9]\n\t"
        "	cmp sb, r3\n\t"
        "	blo _08023BFC\n\t"
        "	b _08023DF4\n\t"
        "_08023BFC:\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #0x88\n\t"
        "	add r0, sb\n\t"
        "	mov r5, sb\n\t"
        "	strb r5, [r0]\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #0x90\n\t"
        "	add r0, sb\n\t"
        "	strb r5, [r0]\n\t"
        "	mov r6, sb\n\t"
        "	lsls r2, r6, #1\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x74\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r0, r6, #3\n\t"
        "	subs r0, r0, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r5, r8\n\t"
        "	adds r3, r5, r0\n\t"
        "	adds r5, r3, #0\n\t"
        "	adds r5, #0xaa\n\t"
        "	ldrh r0, [r5]\n\t"
        "	strh r0, [r1]\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x72\n\t"
        "	ldrh r6, [r1]\n\t"
        "	adds r0, r0, r6\n\t"
        "	strh r0, [r1]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	adds r6, r2, #0\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08023C6A\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _08023C46\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08023C4C\n\t"
        "	b _08023CC4\n\t"
        "_08023C46:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _08023C88\n\t"
        "	b _08023CC4\n\t"
        "_08023C4C:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08023C8E\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xa8\n\t"
        "	ldrh r2, [r0]\n\t"
        "	lsls r2, r2, #8\n\t"
        "	adds r0, r2, #0\n\t"
        "	movs r1, #0xc8\n\t"
        "	lsls r1, r1, #7\n\t"
        "	bl MathUtil_Mul32\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldrh r4, [r5]\n\t"
        "	b _08023CBA\n\t"
        "_08023C6A:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08023C8E\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xac\n\t"
        "	ldrh r2, [r0]\n\t"
        "	lsls r2, r2, #8\n\t"
        "	adds r0, r2, #0\n\t"
        "	movs r1, #0xc8\n\t"
        "	lsls r1, r1, #7\n\t"
        "	bl MathUtil_Mul32\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldrh r4, [r5]\n\t"
        "	b _08023CBA\n\t"
        "_08023C88:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08023C92\n\t"
        "_08023C8E:\n\t"
        "	movs r4, #0\n\t"
        "	b _08023CC4\n\t"
        "_08023C92:\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0xae\n\t"
        "	ldrh r0, [r1]\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r2, [r2, #0x28]\n\t"
        "	cmp r0, r2\n\t"
        "	blo _08023CA6\n\t"
        "	movs r4, #0xc8\n\t"
        "	lsls r4, r4, #7\n\t"
        "	b _08023CC4\n\t"
        "_08023CA6:\n\t"
        "	ldrh r2, [r1]\n\t"
        "	lsls r2, r2, #8\n\t"
        "	adds r0, r2, #0\n\t"
        "	movs r1, #0xc8\n\t"
        "	lsls r1, r1, #7\n\t"
        "	bl MathUtil_Mul32\n\t"
        "	adds r2, r0, #0\n\t"
        "	mov r3, r8\n\t"
        "	ldrh r4, [r3, #0x28]\n\t"
        "_08023CBA:\n\t"
        "	lsls r4, r4, #8\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl MathUtil_Div32\n\t"
        "	adds r4, r0, #0\n\t"
        "_08023CC4:\n\t"
        "	asrs r4, r4, #4\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #0x7e\n\t"
        "	adds r0, r0, r6\n\t"
        "	strh r4, [r0]\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	mov r5, r8\n\t"
        "	ldrb r5, [r5, #9]\n\t"
        "	cmp sb, r5\n\t"
        "	blo _08023BFC\n\t"
        "	b _08023DF4\n\t"
        "_08023CE2:\n\t"
        "	movs r6, #0\n\t"
        "	mov sb, r6\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1, #9]\n\t"
        "	subs r0, #1\n\t"
        "	adds r1, #0x68\n\t"
        "	str r1, [sp, #0xc]\n\t"
        "	cmp sb, r0\n\t"
        "	bge _08023D82\n\t"
        "_08023CF4:\n\t"
        "	mov r2, r8\n\t"
        "	ldrb r0, [r2, #9]\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	mov r3, sb\n\t"
        "	adds r3, #1\n\t"
        "	str r3, [sp, #8]\n\t"
        "	cmp r4, sb\n\t"
        "	bls _08023D70\n\t"
        "	adds r2, #0x74\n\t"
        "	str r2, [sp]\n\t"
        "	mov r5, r8\n\t"
        "	adds r5, #0x88\n\t"
        "	str r5, [sp, #4]\n\t"
        "	movs r6, #0x90\n\t"
        "	add r6, r8\n\t"
        "	mov sl, r6\n\t"
        "	movs r0, #0x7e\n\t"
        "	add r0, r8\n\t"
        "	mov ip, r0\n\t"
        "_08023D1E:\n\t"
        "	subs r7, r4, #1\n\t"
        "	lsls r6, r7, #1\n\t"
        "	ldr r1, [sp]\n\t"
        "	adds r3, r1, r6\n\t"
        "	lsls r5, r4, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r2, [r3]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r2, r0\n\t"
        "	bhs _08023D46\n\t"
        "	ldrh r0, [r1]\n\t"
        "	strh r2, [r1]\n\t"
        "	strh r0, [r3]\n\t"
        "	ldr r1, [sp, #4]\n\t"
        "	adds r2, r1, r4\n\t"
        "	ldrb r3, [r2]\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r0, [r1]\n\t"
        "	strb r0, [r2]\n\t"
        "	strb r3, [r1]\n\t"
        "_08023D46:\n\t"
        "	mov r2, ip\n\t"
        "	adds r3, r2, r6\n\t"
        "	adds r1, r2, r5\n\t"
        "	ldrh r2, [r3]\n\t"
        "	ldrh r5, [r1]\n\t"
        "	cmp r2, r5\n\t"
        "	bhs _08023D68\n\t"
        "	ldrh r0, [r1]\n\t"
        "	strh r2, [r1]\n\t"
        "	strh r0, [r3]\n\t"
        "	mov r6, sl\n\t"
        "	adds r2, r6, r4\n\t"
        "	ldrb r3, [r2]\n\t"
        "	adds r1, r6, r7\n\t"
        "	ldrb r0, [r1]\n\t"
        "	strb r0, [r2]\n\t"
        "	strb r3, [r1]\n\t"
        "_08023D68:\n\t"
        "	lsls r0, r7, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, sb\n\t"
        "	bhi _08023D1E\n\t"
        "_08023D70:\n\t"
        "	ldr r1, [sp, #8]\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	mov r2, r8\n\t"
        "	ldrb r0, [r2, #9]\n\t"
        "	subs r0, #1\n\t"
        "	cmp sb, r0\n\t"
        "	blt _08023CF4\n\t"
        "_08023D82:\n\t"
        "	movs r0, #0\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	movs r2, #0x30\n\t"
        "	bl SendBlock\n\t"
        "	b _08023DF4\n\t"
        "_08023D8E:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08023DFC\n\t"
        "	movs r0, #0\n\t"
        "	mov r3, r8\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	b _08023DF4\n\t"
        "_08023DA0:\n\t"
        "	bl GetBlockReceivedStatus\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08023DFC\n\t"
        "	mov r4, r8\n\t"
        "	adds r4, #0x68\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x30\n\t"
        "	bl memset\n\t"
        "	ldr r1, _08023DD0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #0x30\n\t"
        "	bl memcpy\n\t"
        "	bl ResetBlockReceivedFlags\n\t"
        "	movs r0, #0\n\t"
        "	mov r5, r8\n\t"
        "	strh r0, [r5, #0x10]\n\t"
        "	b _08023DF4\n\t"
        "	.align 2, 0\n\t"
        "_08023DD0: .4byte gBlockRecvBuffer\n\t"
        "_08023DD4:\n\t"
        "	bl sub_08020B74\n\t"
        "	movs r0, #0x12\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl sub_08022950\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	mov r6, r8\n\t"
        "	strh r1, [r6, #0x12]\n\t"
        "	strb r0, [r6, #0xc]\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x24\n\t"
        "	strb r0, [r1]\n\t"
        "	b _08023DFC\n\t"
        "_08023DF4:\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1, #0xc]\n\t"
        "	adds r0, #1\n\t"
        "_08023DFA:\n\t"
        "	strb r0, [r1, #0xc]\n\t"
        "_08023DFC:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_08021758(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x38\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	str r1, [sp, #0x10]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	str r2, [sp, #0x14]\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	str r3, [sp, #0x18]\n\t"
        "	movs r7, #0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0x1c]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #0x20]\n\t"
        "	ldr r2, [sp, #0xc]\n\t"
        "	adds r2, #0x68\n\t"
        "	str r2, [sp, #0x24]\n\t"
        "	ldr r4, [sp, #0xc]\n\t"
        "	ldrb r4, [r4, #9]\n\t"
        "	cmp r7, r4\n\t"
        "	blo _08021792\n\t"
        "	b _08021A9A\n\t"
        "_08021792:\n\t"
        "	ldr r0, [sp, #0x10]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	str r0, [sp, #0x28]\n\t"
        "	movs r2, #0xd3\n\t"
        "	lsls r2, r2, #1\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r2, r1, r2\n\t"
        "	str r2, [sp, #0x2c]\n\t"
        "_080217A2:\n\t"
        "	bl DynamicPlaceholderTextUtil_Reset\n\t"
        "	ldr r4, [sp, #0x10]\n\t"
        "	cmp r4, #1\n\t"
        "	beq _0802188C\n\t"
        "	cmp r4, #1\n\t"
        "	bgt _080217B6\n\t"
        "	cmp r4, #0\n\t"
        "	beq _080217CE\n\t"
        "	b _080217BE\n\t"
        "_080217B6:\n\t"
        "	ldr r4, [sp, #0x10]\n\t"
        "	cmp r4, #2\n\t"
        "	bne _080217BE\n\t"
        "	b _08021990\n\t"
        "_080217BE:\n\t"
        "	ldr r0, [sp, #0x20]\n\t"
        "	adds r0, #0xa2\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, [sp, #0x1c]\n\t"
        "	lsls r5, r1, #3\n\t"
        "	adds r2, r7, #1\n\t"
        "	mov sb, r2\n\t"
        "	b _08021A0A\n\t"
        "_080217CE:\n\t"
        "	ldr r0, [sp, #0x24]\n\t"
        "	adds r0, #0x20\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r0, [r0]\n\t"
        "	str r0, [sp, #0x1c]\n\t"
        "	lsls r3, r7, #1\n\t"
        "	ldr r2, [sp, #0x24]\n\t"
        "	adds r2, #0xc\n\t"
        "	cmp r7, #0\n\t"
        "	beq _080217F4\n\t"
        "	adds r0, r2, r3\n\t"
        "	subs r1, r7, #1\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r2, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	ldrh r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _080217F4\n\t"
        "	str r7, [sp, #0x20]\n\t"
        "_080217F4:\n\t"
        "	ldr r4, [sp, #0x28]\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	adds r0, r4, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r3, r0\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldr r0, _08021880\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #4\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _08021884\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldr r5, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	adds r1, r5, #0\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	ldr r2, [sp, #0x14]\n\t"
        "	subs r0, r2, r0\n\t"
        "	subs r0, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r4, [sp, #0x2c]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0xd\n\t"
        "	adds r4, r7, #0\n\t"
        "	muls r4, r1, r4\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	adds r4, r1, r4\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r2, _08021888\n\t"
        "	str r2, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r4, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r2, [sp, #0x2c]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	adds r2, r6, #0\n\t"
        "	subs r2, #0x21\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r1, _08021888\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _08021880\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r3, r4, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r2, #0xa2\n\t"
        "	mov r8, r2\n\t"
        "	ldr r4, [sp, #0x1c]\n\t"
        "	lsls r5, r4, #3\n\t"
        "	adds r0, r7, #1\n\t"
        "	mov sb, r0\n\t"
        "	b _08021A0A\n\t"
        "	.align 2, 0\n\t"
        "_08021880: .4byte gStringVar1\n\t"
        "_08021884: .4byte sResultsTexts\n\t"
        "_08021888: .4byte sTextColorTable\n\t"
        "_0802188C:\n\t"
        "	ldr r1, [sp, #0x24]\n\t"
        "	adds r0, r1, r7\n\t"
        "	adds r0, #0x28\n\t"
        "	ldrb r0, [r0]\n\t"
        "	str r0, [sp, #0x1c]\n\t"
        "	lsls r3, r7, #1\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0xc\n\t"
        "	cmp r7, #0\n\t"
        "	beq _080218B6\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xa\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #8\n\t"
        "	adds r1, r2, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	ldrh r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _080218B6\n\t"
        "	str r7, [sp, #0x20]\n\t"
        "_080218B6:\n\t"
        "	ldr r0, [sp, #0x28]\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	adds r4, r0, r1\n\t"
        "	lsls r4, r4, #1\n\t"
        "	adds r4, r3, r4\n\t"
        "	adds r4, r2, r4\n\t"
        "	ldrh r1, [r4]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	ldr r0, _08021974\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #3\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	movs r3, #0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r6, #0xf\n\t"
        "	ands r6, r0\n\t"
        "	movs r2, #0\n\t"
        "	ldr r4, [sp, #0x10]\n\t"
        "	lsls r4, r4, #2\n\t"
        "	str r4, [sp, #0x34]\n\t"
        "	ldr r0, [sp, #0x14]\n\t"
        "	subs r0, #0x34\n\t"
        "	str r0, [sp, #0x30]\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r1, #0xa2\n\t"
        "	mov r8, r1\n\t"
        "	ldr r4, [sp, #0x1c]\n\t"
        "	lsls r5, r4, #3\n\t"
        "	adds r0, r7, #1\n\t"
        "	mov sb, r0\n\t"
        "	movs r1, #3\n\t"
        "	mov sl, r1\n\t"
        "	movs r4, #1\n\t"
        "	mov ip, r4\n\t"
        "	ldr r4, _08021978\n\t"
        "_080218FE:\n\t"
        "	mov r0, sl\n\t"
        "	subs r1, r0, r2\n\t"
        "	adds r0, r6, #0\n\t"
        "	asrs r0, r1\n\t"
        "	mov r1, ip\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08021916\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r3, r3, r0\n\t"
        "_08021916:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #3\n\t"
        "	bls _080218FE\n\t"
        "	adds r0, r3, #0\n\t"
        "	ldr r1, _0802197C\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, _08021980\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _08021984\n\t"
        "	ldr r2, [sp, #0x34]\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _08021988\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	ldr r4, [sp, #0x2c]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r1, [sp, #0x30]\n\t"
        "	lsls r2, r1, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r1, #0xd\n\t"
        "	adds r3, r7, #0\n\t"
        "	muls r3, r1, r3\n\t"
        "	ldr r4, [sp, #0x18]\n\t"
        "	adds r3, r4, r3\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r1, _0802198C\n\t"
        "	str r1, [sp]\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #4]\n\t"
        "	ldr r1, _08021988\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	b _08021A0A\n\t"
        "	.align 2, 0\n\t"
        "_08021974: .4byte gStringVar1\n\t"
        "_08021978: .4byte sPressingSpeedConversionTable\n\t"
        "_0802197C: .4byte 0x000F4240\n\t"
        "_08021980: .4byte gStringVar2\n\t"
        "_08021984: .4byte sResultsTexts\n\t"
        "_08021988: .4byte gStringVar4\n\t"
        "_0802198C: .4byte sTextColorTable\n\t"
        "_08021990:\n\t"
        "	str r7, [sp, #0x1c]\n\t"
        "	str r7, [sp, #0x20]\n\t"
        "	lsls r4, r7, #3\n\t"
        "	subs r0, r4, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, [sp, #0xc]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xa0\n\t"
        "	ldrb r2, [r0]\n\t"
        "	cmp r2, #0x2b\n\t"
        "	bls _080219A8\n\t"
        "	movs r2, #0\n\t"
        "_080219A8:\n\t"
        "	lsls r1, r2, #3\n\t"
        "	subs r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _08021A20\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _08021A24\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _08021A28\n\t"
        "	ldr r1, [r0, #8]\n\t"
        "	ldr r0, _08021A2C\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #1\n\t"
        "	ldr r1, _08021A2C\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldr r0, [sp, #0x14]\n\t"
        "	subs r2, r0, r2\n\t"
        "	subs r2, #4\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r1, [sp, #0x2c]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r1, #0xd\n\t"
        "	adds r3, r7, #0\n\t"
        "	muls r3, r1, r3\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	adds r3, r1, r3\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r1, _08021A30\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _08021A2C\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	movs r2, #0xa2\n\t"
        "	adds r2, r2, r7\n\t"
        "	mov r8, r2\n\t"
        "	adds r5, r4, #0\n\t"
        "	adds r4, r7, #1\n\t"
        "	mov sb, r4\n\t"
        "_08021A0A:\n\t"
        "	ldr r1, [sp, #0x1c]\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	ldrb r0, [r0, #8]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08021A3C\n\t"
        "	ldr r0, _08021A34\n\t"
        "	ldr r1, _08021A38\n\t"
        "	bl StringCopy\n\t"
        "	b _08021A44\n\t"
        "	.align 2, 0\n\t"
        "_08021A20: .4byte 0x08563150\n\t"
        "_08021A24: .4byte gStringVar1\n\t"
        "_08021A28: .4byte sResultsTexts\n\t"
        "_08021A2C: .4byte gStringVar4\n\t"
        "_08021A30: .4byte sTextColorTable\n\t"
        "_08021A34: .4byte gStringVar3\n\t"
        "_08021A38: .4byte 0x085CC9C8\n\t"
        "_08021A3C:\n\t"
        "	ldr r0, _08021AAC\n\t"
        "	ldr r1, _08021AB0\n\t"
        "	bl StringCopy\n\t"
        "_08021A44:\n\t"
        "	ldr r4, _08021AAC\n\t"
        "	mov r1, r8\n\t"
        "	strb r1, [r4]\n\t"
        "	ldr r2, [sp, #0x1c]\n\t"
        "	subs r1, r5, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, #0x98\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	adds r1, r0, r1\n\t"
        "	movs r0, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
        "	ldr r0, _08021AB4\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
        "	ldr r1, [sp, #0x2c]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r1, #0xd\n\t"
        "	adds r3, r7, #0\n\t"
        "	muls r3, r1, r3\n\t"
        "	ldr r2, [sp, #0x18]\n\t"
        "	adds r3, r2, r3\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r4, _08021AB8\n\t"
        "	str r4, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r2, _08021AB4\n\t"
        "	str r2, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #4\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	mov r4, sb\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	cmp r7, r0\n\t"
        "	bhs _08021A9A\n\t"
        "	b _080217A2\n\t"
        "_08021A9A:\n\t"
        "	add sp, #0x38\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08021AAC: .4byte gStringVar3\n\t"
        "_08021AB0: .4byte 0x085CC9D4\n\t"
        "_08021AB4: .4byte gStringVar4\n\t"
        "_08021AB8: .4byte sTextColorTable\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08021ABC(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x1c\n\t"
        "	mov r8, r0\n\t"
        "	movs r0, #0\n\t"
        "	mov sl, r0\n\t"
        "	movs r6, #0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #0xc]\n\t"
        "	mov r2, r8\n\t"
        "	adds r2, #0x68\n\t"
        "	str r2, [sp, #0x10]\n\t"
        "	movs r4, #0xd3\n\t"
        "	lsls r4, r4, #1\n\t"
        "	add r4, r8\n\t"
        "	mov sb, r4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #4\n\t"
        "	bl GetWindowAttribute\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	movs r1, #0xda\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	movs r0, #0x92\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	ldrh r1, [r2, #4]\n\t"
        "	bl sub_08021674\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r4, _08021CF4\n\t"
        "	str r4, [sp]\n\t"
        "	str r6, [sp, #4]\n\t"
        "	ldr r1, _08021CF8\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #2\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r4, _08021CFC\n\t"
        "	movs r0, #1\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	movs r1, #0xae\n\t"
        "	subs r0, r1, r0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldr r1, _08021CF4\n\t"
        "	str r1, [sp]\n\t"
        "	mov r2, sl\n\t"
        "	str r2, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	adds r0, r6, #0\n\t"
        "	subs r0, #0x29\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r0, #0x95\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	movs r4, #0\n\t"
        "	ldrsh r1, [r0, r4]\n\t"
        "	ldr r0, _08021D00\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _08021D04\n\t"
        "	movs r1, #0x96\n\t"
        "	lsls r1, r1, #1\n\t"
        "	add r1, r8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r1, r2]\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r5, _08021D08\n\t"
        "	ldr r1, _08021D0C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	mov r4, sb\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r1, _08021CF4\n\t"
        "	str r1, [sp]\n\t"
        "	mov r2, sl\n\t"
        "	str r2, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r4, _08021D10\n\t"
        "	movs r0, #1\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	subs r1, r6, #1\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r6, r1, #0x18\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldr r2, _08021CF4\n\t"
        "	str r2, [sp]\n\t"
        "	mov r1, sl\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	adds r0, r6, #0\n\t"
        "	subs r0, #9\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r0, #0x94\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	ldr r0, _08021D00\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #1\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r1, _08021D14\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	mov r4, sb\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r1, _08021CF4\n\t"
        "	str r1, [sp]\n\t"
        "	mov r2, sl\n\t"
        "	str r2, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0xd\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r4, _08021CF4\n\t"
        "	str r4, [sp]\n\t"
        "	mov r1, sl\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _08021D18\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #2\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r4, _08021D1C\n\t"
        "	movs r0, #1\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	movs r2, #0xae\n\t"
        "	subs r0, r2, r0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldr r2, _08021CF4\n\t"
        "	str r2, [sp]\n\t"
        "	mov r1, sl\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	mov r4, r8\n\t"
        "	ldrb r2, [r4, #0x16]\n\t"
        "	ldrh r0, [r4, #0x16]\n\t"
        "	mov ip, r0\n\t"
        "	movs r1, #7\n\t"
        "	mov sb, r1\n\t"
        "	movs r5, #1\n\t"
        "	ldr r3, _08021D20\n\t"
        "_08021C62:\n\t"
        "	mov r4, sb\n\t"
        "	mov r0, sl\n\t"
        "	subs r1, r4, r0\n\t"
        "	adds r0, r2, #0\n\t"
        "	asrs r0, r1\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08021C80\n\t"
        "	mov r1, sl\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r4, [sp, #0xc]\n\t"
        "	adds r4, r4, r0\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "_08021C80:\n\t"
        "	mov r0, sl\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	cmp r0, #7\n\t"
        "	bls _08021C62\n\t"
        "	ldr r0, _08021D00\n\t"
        "	mov r2, ip\n\t"
        "	lsrs r1, r2, #8\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #3\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _08021D04\n\t"
        "	ldr r1, _08021D24\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	bl __udivsi3\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _08021D08\n\t"
        "	ldr r1, _08021D28\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r6, #0\n\t"
        "	subs r0, #0x31\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #0x25\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08021D30\n\t"
        "	movs r0, #0xd3\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _08021D2C\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	b _08021D4A\n\t"
        "	.align 2, 0\n\t"
        "_08021CF4: .4byte sTextColorTable\n\t"
        "_08021CF8: .4byte 0x085CC9F0\n\t"
        "_08021CFC: .4byte 0x085CCA14\n\t"
        "_08021D00: .4byte gStringVar1\n\t"
        "_08021D04: .4byte gStringVar2\n\t"
        "_08021D08: .4byte gStringVar4\n\t"
        "_08021D0C: .4byte 0x085CCA0C\n\t"
        "_08021D10: .4byte 0x085CCA08\n\t"
        "_08021D14: .4byte 0x085CCA04\n\t"
        "_08021D18: .4byte 0x085CC9F4\n\t"
        "_08021D1C: .4byte 0x085CCA20\n\t"
        "_08021D20: .4byte sPressingSpeedConversionTable\n\t"
        "_08021D24: .4byte 0x000F4240\n\t"
        "_08021D28: .4byte 0x085CCA18\n\t"
        "_08021D2C: .4byte 0x082C5EFF\n\t"
        "_08021D30:\n\t"
        "	movs r0, #0xd3\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _08021DC8\n\t"
        "	str r1, [sp]\n\t"
        "	str r2, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "_08021D4A:\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0xd\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	movs r4, #0xd3\n\t"
        "	lsls r4, r4, #1\n\t"
        "	add r8, r4\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldr r2, _08021DC8\n\t"
        "	mov sb, r2\n\t"
        "	str r2, [sp]\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp, #4]\n\t"
        "	ldr r1, _08021DCC\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #2\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r0, _08021DD0\n\t"
        "	ldr r4, [sp, #0x10]\n\t"
        "	ldrh r1, [r4, #8]\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #3\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _08021DD4\n\t"
        "	ldr r1, _08021DD8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringLength\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0xd\n\t"
        "	movs r2, #0x52\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r6, r1, #0x18\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1]\n\t"
        "	mov r2, sb\n\t"
        "	str r2, [sp]\n\t"
        "	str r5, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	add sp, #0x1c\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08021DC8: .4byte sTextColorTable\n\t"
        "_08021DCC: .4byte 0x085CC9FC\n\t"
        "_08021DD0: .4byte gStringVar1\n\t"
        "_08021DD4: .4byte gStringVar4\n\t"
        "_08021DD8: .4byte 0x085CCA28\n\t"
        ".syntax divided\n\t"
    );
}

