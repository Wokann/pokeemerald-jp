#include "global.h"
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
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "window.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define CRUSHER_START_Y (-104)

#define TAG_CRUSHER_BASE  1
#define PALTAG_EFFECT     2
#define GFXTAG_IMPACT     2
#define GFXTAG_SPARKLE    3
#define TAG_TIMER_DIGITS  4

#define F_INPUT_HIT_SYNC (1 << 2) // Input at same time as another player
#define INPUT_FLAGS_PER_PLAYER 3
#define INPUT_FLAG_MASK ((1 << INPUT_FLAGS_PER_PLAYER) - 1)

enum {
    RUN_CMD,
    SCHEDULE_CMD,
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
    u8 filler[18];
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

struct BerryCrushPlayerCoords
{
    u8 playerId;
    u8 windowGfxX;
    u8 windowGfxY;
    s16 impactXOffset;
    s16 impactYOffset;
    s16 berryXOffset;
    s16 berryXDest;
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
    u16 targetAPresses;                           // +18
    u16 totalAPresses;                            // +1A
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
    u8 localState[12];                            // +5C
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
s32 UpdateGame(struct BerryCrushGame *);
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

s32 UpdateGame(struct BerryCrushGame *game)
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

void PrintTextCentered(u8 windowId, u8 left, u8 colorId, const u8 *string)
{
    left = (left * 4) - (GetStringWidth(FONT_NORMAL, string, -1) / 2u);
    AddTextPrinterParameterized3(windowId, FONT_NORMAL, left, 0, sTextColorTable[colorId], 0, string);
}
