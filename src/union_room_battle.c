#include "global.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "bg.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "gba/isagbprint.h"
#include "gpu_regs.h"
#include "link.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "script.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "task.h"
#include "union_room.h"
#include "window.h"
#include "constants/battle.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/game_stat.h"
#include "constants/rgb.h"
#include "constants/trainers.h"

extern const struct BgTemplate sUnionRoomBattleBgTemplates[];
extern const struct WindowTemplate sUnionRoomBattleWindowTemplates[];
extern const u8 sWirelessScreenTextColors[];
extern const u8 sURBattleText_CommStandby[];
extern const u8 sURBattleText_BattleWasRefused[];
extern const u8 sURBattleText_RefusedBattle[];
extern struct UnionRoomBattle *sURoomBattleData;

struct UnionRoomBattle
{
    s16 textState;
};

void CB2_SetUpPartiesAndStartBattle(void)
{
    s32 i;
    StartUnionRoomBattle(BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER);
    for (i = 0; i < UNION_ROOM_PARTY_SIZE; i++)
        gEnemyParty[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1];
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);
    for (i = 0; i < UNION_ROOM_PARTY_SIZE; i++)
        gPlayerParty[i] = gEnemyParty[i];
    IncrementGameStat(GAME_STAT_NUM_UNION_ROOM_BATTLES);
    CalculatePlayerPartyCount();
    gTrainerBattleOpponent_A = TRAINER_UNION_ROOM;
    SetMainCallback2(CB2_InitBattle);
}

void AddTextPrinterForUnionRoomBattle(u8 windowId, const u8 *str, u8 x, u8 y, s32 speed)
{
    s32 letterSpacing = 0;
    s32 lineSpacing = 1;
    FillWindowPixelBuffer(windowId, (sWirelessScreenTextColors[0] << 4) | sWirelessScreenTextColors[0]);
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, letterSpacing, lineSpacing, sWirelessScreenTextColors, speed, str);
}

bool32 PrintUnionRoomBattleMessage(s16 *state, const u8 *str, s32 speed)
{
    switch (*state)
    {
    case 0:
        DrawTextBorderOuter(0, 0x001, 0xD);
        AddTextPrinterForUnionRoomBattle(0, str, 1, 1, speed);
        PutWindowTilemap(0);
        CopyWindowToVram(0, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        if (!IsTextPrinterActive(0))
        {
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void VBlankCB_UnionRoomBattle(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_UnionRoomBattle(void)
{
    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
        sURoomBattleData = AllocZeroed(sizeof(struct UnionRoomBattle));
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sUnionRoomBattleBgTemplates, 1);
        ResetTempTileDataBuffers();
        if (!InitWindows(sUnionRoomBattleWindowTemplates))
            return;
        DeactivateAllTextPrinters();
        ClearWindowTilemap(0);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        FillBgTilemapBufferRect(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 0xF);
        LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(13));
        LoadUserWindowBorderGfx_(0, 1, BG_PLTT_ID(13));
        Menu_LoadStdPal();
        SetVBlankCallback(VBlankCB_UnionRoomBattle);
        gMain.state++;
        break;
    case 1:
        if (PrintUnionRoomBattleMessage(&sURoomBattleData->textState, sURBattleText_CommStandby, 0))
        {
            gMain.state++;
        }
        break;
    case 2:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        ShowBg(0);
        gMain.state++;
        break;
    case 3:
        if (!UpdatePaletteFade())
        {
            memset(gBlockSendBuffer, 0, 0x20);
            if (gSelectedOrderFromParty[0] == -gSelectedOrderFromParty[1])
            {
                gBlockSendBuffer[0] = ACTIVITY_DECLINE | IN_UNION_ROOM;
            }
            else
            {
                gBlockSendBuffer[0] = ACTIVITY_ACCEPT | IN_UNION_ROOM;
            }
            SendBlock(0, gBlockSendBuffer, 0x20);
            gMain.state++;
        }
        break;
    case 4:
        if (GetBlockReceivedStatus() == 3)
        {
            if (gBlockRecvBuffer[0][0] == (ACTIVITY_ACCEPT | IN_UNION_ROOM)
             && gBlockRecvBuffer[1][0] == (ACTIVITY_ACCEPT | IN_UNION_ROOM))
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gMain.state = 50;
            }
            else
            {
                SetCloseLinkCallback();
                if (gBlockRecvBuffer[GetMultiplayerId()][0] == (ACTIVITY_DECLINE | IN_UNION_ROOM))
                {
                    gMain.state = 6;
                }
                else
                {
                    gMain.state = 8;
                }
            }
            ResetBlockReceivedFlags();
        }
        break;
    case 50:
        if (!UpdatePaletteFade())
        {
            SetLinkStandbyCallback();
            gMain.state++;
        }
        break;
    case 51:
        if (IsLinkTaskFinished())
        {
            SetMainCallback2(CB2_SetUpPartiesAndStartBattle);
        }
        break;
    case 6:
        if (!gReceivedRemoteLinkPlayers)
        {
            gMain.state++;
        }
        break;
    case 7:
        if (PrintUnionRoomBattleMessage(&sURoomBattleData->textState, sURBattleText_RefusedBattle, 1))
        {
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    case 8:
        if (!gReceivedRemoteLinkPlayers)
        {
            gMain.state++;
        }
        break;
    case 9:
        if (PrintUnionRoomBattleMessage(&sURoomBattleData->textState, sURBattleText_BattleWasRefused, 1))
        {
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
