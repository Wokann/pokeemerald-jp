#include "global.h"
#include "event_data.h"
#include "item_menu.h"
#include "link.h"
#include "link_rfu.h"
#include "malloc.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "text.h"
#include "constants/rgb.h"
#include "constants/songs.h"

struct BerryCrushGame_Player
{
    u16 berryId;
    u8 filler[26];
};

struct BerryCrushGame
{
    MainCallback exitCallback;      // +0
    u32 filler4;                    // +4
    u8 localId;                     // +8
    u8 playerCount;                 // +9
    u8 taskId;                      // +a
    u8 textSpeed;                   // +b
    u8 cmdState;                    // +c
    u8 unused;                      // +d
    u8 nextCmd;                     // +e
    u8 afterPalFadeCmd;             // +f
    u16 cmdTimer;                   // +10
    u16 gameState;                  // +12
    u16 filler14[17];               // +14..+35
    u8 commandArgs[12];             // +36
    u8 filler42[0x5E];              // +42..+9F
    struct BerryCrushGame_Player players[MAX_RFU_PLAYERS]; // +0xA0
    u8 filler[0x41AC - 0xA0 - MAX_RFU_PLAYERS * 28];
};

// Berry Crush game state, EWRAM 0x02022944 (see sym_ewram_jp.txt).
extern EWRAM_DATA struct BerryCrushGame *sGame;

extern void SetNamesAndTextSpeed(struct BerryCrushGame *);
extern void RunOrScheduleCommand(u16, u8, u8 *);
extern void SetPaletteFadeArgs(u8 *, bool8, u32, s8, u8, u8, u16);
extern void MainCB(void);
extern void MainTask(u8 taskId);
extern void VBlankCB(void);
extern void GetBerryFromBag(void);

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
