#include "global.h"
#include "link.h"
#include "mystery_event_script.h"
#include "save.h"
#include "berry_tag_screen.h"
#include "berry.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "main.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "menu.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "decompress.h"
#include "bg.h"
#include "palette.h"
#include "graphics.h"
#include "strings.h"
#include "string_util.h"

extern const u8 gUnknown_85CD159[];
extern const u8 gUnknown_85CD19F[];
extern const struct BgTemplate gUnknown_85CD204[1];
extern const struct WindowTemplate gUnknown_85CD208[];
extern const u8 gUnknown_85CD0DC[];
extern const u8 gUnknown_85CD0FE[];
extern const u8 gUnknown_85CD123[];
extern const u8 gUnknown_85CD133[];
extern u8 gUnknown_203B9C4;

void CB2_MysteryEventMenu(void);
static void PrintMysteryMenuText(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed);

enum
{
    WIN_MSG,
    WIN_LOADING,
};
static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_081787FC(void) __attribute__((alias("VBlankCB")));

bool8 CheckLanguageMatch(void)
{
    return (gLinkPlayers[0].language == gLinkPlayers[1].language);
}

void CB2_InitMysteryEventMenu(void)
{
    s32 i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    SetVBlankCallback(VBlankCB);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_85CD204, 1);
    if (InitWindows(gUnknown_85CD208))
    {
        DeactivateAllTextPrinters();
        for (i = 0; i < 2; i++)
            FillWindowPixelBuffer(i, PIXEL_FILL(0));

        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
        LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(13));
        Menu_LoadStdPalAt(BG_PLTT_ID(14));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        CreateTask(Task_DestroySelf, 0);
        StopMapMusic();
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        RunTextPrinters();
        UpdatePaletteFade();
        SetBackdropFromColor(RGB_BLACK);
        SetMainCallback2(CB2_MysteryEventMenu);
    }
}

bool8 GetEventLoadMessage(u8 *dest, u32 status)
{
    bool8 retVal = TRUE;

    if (status == MEVENT_STATUS_LOAD_OK)
    {
        StringCopy(dest, gUnknown_85CD159);
        retVal = FALSE;
    }

    if (status == MEVENT_STATUS_SUCCESS)
        retVal = FALSE;

    if (status == MEVENT_STATUS_LOAD_ERROR)
        StringCopy(dest, gUnknown_85CD19F);

    return retVal;
}

void CB2_MysteryEventMenu(void)
{
    switch (gMain.state)
    {
    case 0:
        DrawStdFrameWithCustomTileAndPalette(WIN_MSG, TRUE, 1, 0xD);
        PutWindowTilemap(WIN_MSG);
        CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
        ShowBg(0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            PrintMysteryMenuText(WIN_MSG, gUnknown_85CD0DC, 1, 2, 1);
            gMain.state++;
        }
        break;
    case 2:
        if (!IsTextPrinterActive(WIN_MSG))
        {
            gMain.state++;
            gLinkType = LINKTYPE_MYSTERY_EVENT;
            OpenLink();
        }
        break;
    case 3:
        if ((gLinkStatus & LINK_STAT_MASTER) && (gLinkStatus & LINK_STAT_PLAYER_COUNT) > 4)
        {
            PlaySE(SE_PIN);
            PrintMysteryMenuText(WIN_MSG, gUnknown_85CD0FE, 1, 2, 1);
            gMain.state++;
        }
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseLink();
            gMain.state = 15;
        }
        break;
    case 4:
        if (!IsTextPrinterActive(WIN_MSG))
            gMain.state++;
        break;
    case 5:
        if (GetLinkPlayerCount_2() == 2)
        {
            if (JOY_NEW(A_BUTTON))
            {
                PlaySE(SE_SELECT);
                CheckShouldAdvanceLinkState();
                DrawStdFrameWithCustomTileAndPalette(WIN_LOADING, TRUE, 1, 0xD);
                PrintMysteryMenuText(WIN_LOADING, gUnknown_85CD123, 1, 2, 0);
                PutWindowTilemap(WIN_LOADING);
                CopyWindowToVram(WIN_LOADING, COPYWIN_FULL);
                gMain.state++;
            }
            else if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                CloseLink();
                gMain.state = 15;
            }
        }
        else
        {
            GetEventLoadMessage(gStringVar4, MEVENT_STATUS_LOAD_ERROR);
            PrintMysteryMenuText(WIN_MSG, gStringVar4, 1, 2, 1);
            gMain.state = 13;
        }
        break;
    case 6:
        if (IsLinkConnectionEstablished())
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (GetLinkPlayerDataExchangeStatusTimed(2, 2) == EXCHANGE_DIFF_SELECTIONS)
                {
                    SetCloseLinkCallback();
                    GetEventLoadMessage(gStringVar4, MEVENT_STATUS_LOAD_ERROR);
                    PrintMysteryMenuText(WIN_MSG, gStringVar4, 1, 2, 1);
                    gMain.state = 13;
                }
                else if (CheckLanguageMatch())
                {
                    PrintMysteryMenuText(WIN_MSG, gUnknown_85CD133, 1, 2, 1);
                    gMain.state++;
                }
                else
                {
                    CloseLink();
                    GetEventLoadMessage(gStringVar4, MEVENT_STATUS_LOAD_ERROR);
                    PrintMysteryMenuText(WIN_MSG, gStringVar4, 1, 2, 1);
                    gMain.state = 13;
                }
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseLink();
            gMain.state = 15;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(WIN_MSG))
            gMain.state++;
        break;
    case 8:
        if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            gMain.state++;
        }
        break;
    case 9:
        gMain.state++;
        break;
    case 10:
        SetCloseLinkCallback();
        gMain.state++;
        break;
    case 11:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            u16 status = RunMysteryEventScript(gDecompressionBuffer);
            CpuFill32(0, gDecompressionBuffer, 0x7D4);
            if (!GetEventLoadMessage(gStringVar4, status))
                TrySavingData(SAVE_NORMAL);
            gMain.state++;
        }
        break;
    case 12:
        PrintMysteryMenuText(WIN_MSG, gStringVar4, 1, 2, 1);
        gMain.state++;
        break;
    case 13:
        if (!IsTextPrinterActive(WIN_MSG))
        {
            gMain.state++;
            gUnknown_203B9C4 = 0;
        }
        break;
    case 14:
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            gMain.state++;
        }
        break;
    case 15:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gMain.state++;
        break;
    case 16:
        if (!gPaletteFade.active)
            DoSoftReset();
        break;
    }

    if (gLinkStatus & LINK_STAT_CONN_ESTABLISHED && !IsLinkMaster())
    {
        CloseLink();
        GetEventLoadMessage(gStringVar4, MEVENT_STATUS_LOAD_ERROR);
        PrintMysteryMenuText(WIN_MSG, gStringVar4, 1, 2, 1);
        gMain.state = 13;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void PrintMysteryMenuText(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed)
{
    u8 textColor[3];
    u8 letterSpacing = 0;
    u8 lineSpacing = 1;

    textColor[0] = 1;
    textColor[1] = 2;
    textColor[2] = 3;
    FillWindowPixelBuffer(windowId, PIXEL_FILL(textColor[0]));
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, letterSpacing, lineSpacing, textColor, speed, text);
}

void sub_08178D7C(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed) __attribute__((alias("PrintMysteryMenuText")));
