#include "global.h"
#include "berry_powder.h"
#include "event_data.h"
#include "item_menu.h"
#include "link.h"
#include "link_rfu.h"
#include "malloc.h"
#include "main.h"
#include "math_util.h"
#include "overworld.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "constants/rgb.h"
#include "constants/songs.h"

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
    u8 gfx[0x41AC - 0x124];                       // +124
};

// Berry Crush game state, EWRAM 0x02022944 (see sym_ewram_jp.txt).
extern EWRAM_DATA struct BerryCrushGame *sGame;

extern void RunOrScheduleCommand(u16, u8, u8 *);
extern void SetPaletteFadeArgs(u8 *, bool8, u32, s8, u8, u8, u16);
extern void GetBerryFromBag(void);
extern s32 UpdateGame(struct BerryCrushGame *);

void SaveResults(void);
static void VBlankCB(void);
static void MainCB(void);
static void MainTask(u8 taskId);
static void SetNamesAndTextSpeed(struct BerryCrushGame *);

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
