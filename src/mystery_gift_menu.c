#include "global.h"
#include "main.h"
#include "text.h"
#include "task.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "text_window.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "list_menu.h"
#include "menu.h"
#include "palette.h"
#include "constants/songs.h"
#include "sound.h"
#include "string_util.h"
#include "mystery_gift_menu.h"
#include "union_room.h"
#include "title_screen.h"
#include "ereader_screen.h"
#include "mystery_gift_client.h"
#include "mystery_gift_server.h"
#include "mystery_gift_view.h"
#include "constants/cable_club.h"
#include "event_data.h"

// JP: ROM data bound via ld_script_jp.txt (JP uses fixed ROM addresses).
extern const struct BgTemplate sBGTemplates[];
extern const struct WindowTemplate sMainWindows[];
extern const u16 sTextboxBorder_Pal[];
extern const u8 sTextColors_Header[];
extern const u8 gText_MysteryGift[];
extern const u8 gText_PickOKExit[];
extern const u8 gJPText_MysteryGift[];
extern const u8 gJPText_DecideStop[];
extern const u8 sMG_Ereader_TextColor_2[];
extern u8 sDownArrowCounterAndYCoordIdx[2];
extern const u8 gText_WhatToDoWithCards[];
extern const u8 gText_WhatToDoWithNews[];
extern const u8 sText_DiscardWonderCard[];
extern const u8 sText_DiscardWonderNews[];
extern const u8 sText_WasThrownAwayWonderCard[];
extern const u8 sText_WasThrownAwayWonderNews[];
extern const u8 sText_SavingGame1[];
extern const u8 sText_SavingGame2[];
extern const u32 sTextboxBorder_Gfx[];
extern const u8 sJPText_MeventMsg0[];
extern const u8 sJPText_MeventMsg1[];
extern const u8 sJPText_MeventMsg2a[];
extern const u8 sJPText_MeventMsg2b[];
extern const u8 sJPText_MeventMsg3a[];
extern const u8 sJPText_MeventMsg3b[];
extern const u8 sJPText_MeventMsg4[];
extern const u8 sJPText_MeventMsg5[];
extern const u8 sJPText_MeventMsg6[];
extern const u8 sJPText_MeventMsg7[];
extern const u8 sJPText_MeventMsg8[];
extern const u8 sJPText_MeventMsg9[];
extern const u8 sJPText_MeventMsg10a[];
extern const u8 sJPText_MeventMsg10b[];
extern const u8 sJPText_MeventMsg11[];
extern const u8 sJPText_MeventMsg12[];
extern const u8 sJPText_StampMsg2[];
extern const u8 sJPText_StampMsg3[];
extern const u8 sJPText_StampMsg4[];
extern const u8 sJPText_StampMsg5[];
extern const u8 sJPText_StampMsg6[];
extern const u8 sJPText_StampMsg7[];
extern const u8 sJPText_StampMsg9[];
extern const u8 sJPText_StampMsg12[];
extern const u8 sJPText_StampMsg14[];
extern const struct ListMenuTemplate sListMenuTemplate_ThreeOptions;
extern const struct ListMenuItem sListMenuItems_CardsOrNews[];
extern const struct ListMenuItem sListMenuItems_WirelessOrFriend[];
extern const struct WindowTemplate sWindowTemplate_ThreeOptions;
extern const struct WindowTemplate sWindowTemplate_YesNoMsg_Wide;
extern const struct WindowTemplate sWindowTemplate_YesNoMsg;
extern const struct WindowTemplate sWindowTemplate_YesNoBox;
extern const struct WindowTemplate sWindowTemplate_GiftSelect;
extern const struct WindowTemplate sWindowTemplate_GiftSelect_2Options;
extern const struct WindowTemplate sWindowTemplate_GiftSelect_1Option;
extern const struct WindowTemplate sWindowTemplate_GiftSelect_3Options;
extern const struct ListMenuTemplate sListMenu_ReceiveToss;
extern const struct ListMenuTemplate sListMenu_Receive;
extern const struct ListMenuTemplate sListMenu_ReceiveSendToss;
extern const struct ListMenuTemplate sListMenu_ReceiveSend;
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern bool32 ValidateReceivedWonderCard(void);
extern bool32 ValidateReceivedWonderNews(void);
extern struct WonderCard *GetSavedWonderCard(void);
extern struct WonderNews *GetSavedWonderNews(void);
extern void InitWonderCardResources(struct WonderCard *card, u8 *meventBuffer);
extern void InitWonderNewsResources(struct WonderNews *news);
extern u8 *sav1_get_mevent_buffer_2(void);
extern bool32 FadeToWonderCardMenu(void);
extern bool32 FadeToWonderNewsMenu(void);
extern void DestroyWonderCard(void);
extern void DestroyWonderNews(void);
extern bool32 FadeOutFromWonderCard(void);
extern bool32 FadeOutFromWonderNews(void);
extern void DestroyWonderCardResources(void);
extern void DestroyWonderNewsResources(void);
// JP: still in asm/mystery_gift.s; revert to C names as they are converted.
extern void bgid_upload_textbox_1(u8 bgId);
extern void task_add_00_mystery_gift(void);
void PrintMysteryGiftOrEReaderTopMenu(u8 isEReader);
void MG_DrawCheckerboardPattern(u32 bg);

// Window IDs for mystery gift / e-reader screens.
enum {
    WIN_HEADER,
    WIN_MSG,
    WIN_UNK,
};

#define DOWN_ARROW_X 208
#define DOWN_ARROW_Y 20

static void VBlankCB_MysteryGiftEReader(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

void CB2_MysteryGiftEReader(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

static bool32 HandleMysteryGiftOrEReaderSetup(s32 isEReader)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        ScanlineEffect_Stop();
        ResetBgsAndClearDma3BusyFlags(0);

        InitBgsFromTemplates(0, sBGTemplates, 4);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);

        SetBgTilemapBuffer(3, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));

        bgid_upload_textbox_1(3);
        InitWindows(sMainWindows);
        DeactivateAllTextPrinters();
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gMain.state++;
        break;
    case 1:
        LoadPalette(sTextboxBorder_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(GetTextWindowPalette(2), BG_PLTT_ID(13), PLTT_SIZE_4BPP);
        Menu_LoadStdPalAt(BG_PLTT_ID(12));
        LoadUserWindowBorderGfx(0, 0xA, BG_PLTT_ID(14));
        LoadUserWindowBorderGfx_(0, 0x1, BG_PLTT_ID(15));
        FillBgTilemapBufferRect(0, 0x000, 0, 0, 32, 32, 17);
        FillBgTilemapBufferRect(1, 0x000, 0, 0, 32, 32, 17);
        FillBgTilemapBufferRect(2, 0x000, 0, 0, 32, 32, 17);
        MG_DrawCheckerboardPattern(3);
        PrintMysteryGiftOrEReaderTopMenu(isEReader);
        gMain.state++;
        break;
    case 2:
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    case 3:
        ShowBg(0);
        ShowBg(3);
        PlayBGM(MUS_RG_MYSTERY_GIFT);
        SetVBlankCallback(VBlankCB_MysteryGiftEReader);
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        return TRUE;
    }

    return FALSE;
}

void CB2_InitMysteryGift(void)
{
    if (HandleMysteryGiftOrEReaderSetup(FALSE))
    {
        SetMainCallback2(CB2_MysteryGiftEReader);
        gGiftIsFromEReader = FALSE;
        task_add_00_mystery_gift();
    }
    RunTasks();
}

void CB2_InitEReader(void)
{
    if (HandleMysteryGiftOrEReaderSetup(TRUE))
    {
        SetMainCallback2(CB2_MysteryGiftEReader);
        gGiftIsFromEReader = TRUE;
        CreateEReaderTask();
    }
}

void MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void)
{
    gGiftIsFromEReader = FALSE;
    FreeAllWindowBuffers();
    Free(GetBgTilemapBuffer(0));
    Free(GetBgTilemapBuffer(1));
    Free(GetBgTilemapBuffer(2));
    Free(GetBgTilemapBuffer(3));
    SetMainCallback2(CB2_InitTitleScreen);
}

void PrintMysteryGiftOrEReaderTopMenu(u8 isEReader)
{
    FillWindowPixelBuffer(WIN_HEADER, 0);
    if (!isEReader)
    {
        AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, 2, 2, 0, 0, sTextColors_Header, 0, gText_MysteryGift);
        AddTextPrinterParameterized4(WIN_HEADER, FONT_SMALL, 0x64, 2, 0, 0, sTextColors_Header, 0, gText_PickOKExit);
    }
    else
    {
        AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, 2, 2, 0, 0, sTextColors_Header, 0, gJPText_MysteryGift);
        AddTextPrinterParameterized4(WIN_HEADER, FONT_SMALL, 0x78, 2, 0, 0, sTextColors_Header, 0, gJPText_DecideStop);
    }
    CopyWindowToVram(WIN_HEADER, COPYWIN_GFX);
    PutWindowTilemap(WIN_HEADER);
}

void MG_DrawTextBorder(u8 windowId)
{
    DrawTextBorderOuter(windowId, 0x01, 0xF);
}

void MG_DrawCheckerboardPattern(u32 bg)
{
    s32 i = 0, j;

    FillBgTilemapBufferRect(bg, 0x003, 0, 0, 32, 2, 17);

    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((i & 1) != (j & 1))
                FillBgTilemapBufferRect(bg, 1, j, i + 2, 1, 1, 17);
            else
                FillBgTilemapBufferRect(bg, 2, j, i + 2, 1, 1, 17);
        }
    }
}

void ClearScreenInBg0(bool32 ignoreTopTwoRows)
{
    switch (ignoreTopTwoRows)
    {
    case 0:
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 17);
        break;
    case 1:
        FillBgTilemapBufferRect(0, 0, 0, 2, 32, 30, 17);
        break;
    }
    CopyBgTilemapBufferToVram(0);
}

void MG_AddMessageTextPrinter(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    FillWindowPixelBuffer(WIN_MSG, 0x11);
    AddTextPrinterParameterized4(WIN_MSG, FONT_NORMAL, 2, 2, 0, 1, sMG_Ereader_TextColor_2, 0, gStringVar4);
    DrawTextBorderOuter(WIN_MSG, 0x001, 0xF);
    PutWindowTilemap(WIN_MSG);
    CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
}

void ClearMessage(void)
{
    rbox_fill_rectangle(WIN_MSG);
    ClearWindowTilemap(WIN_MSG);
    CopyWindowToVram(WIN_MSG, COPYWIN_MAP);
}

bool32 PrintMysteryGiftMenuMessage(u8 *textState, const u8 *str)
{
    switch (*textState)
    {
    case 0:
        MG_AddMessageTextPrinter(str);
        (*textState)++;
        break;
    case 1:
        DrawDownArrow(WIN_MSG, DOWN_ARROW_X, DOWN_ARROW_Y, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            (*textState)++;
        break;
    case 2:
        DrawDownArrow(WIN_MSG, DOWN_ARROW_X, DOWN_ARROW_Y, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        *textState = 0;
        ClearMessage();
        return TRUE;
    case 0xFF:
        *textState = 2;
        return FALSE;
    }
    return FALSE;
}

static void HideDownArrow(void)
{
    DrawDownArrow(WIN_MSG, DOWN_ARROW_X, DOWN_ARROW_Y, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

static void ShowDownArrow(void)
{
    DrawDownArrow(WIN_MSG, DOWN_ARROW_X, DOWN_ARROW_Y, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

static bool32 UNUSED HideDownArrowAndWaitButton(u8 *textState)
{
    switch (*textState)
    {
    case 0:
        HideDownArrow();
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            (*textState)++;
        break;
    case 1:
        ShowDownArrow();
        *textState = 0;
        return TRUE;
    }
    return FALSE;
}

bool32 PrintStringAndWait2Seconds(u8 *counter, const u8 *str)
{
    if (*counter == 0)
        MG_AddMessageTextPrinter(str);

    if (++(*counter) > 120)
    {
        *counter = 0;
        ClearMessage();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

u32 MysteryGift_HandleThreeOptionMenu(u8 *unused0, u16 *unused1, u8 whichMenu)
{
    struct ListMenuTemplate listMenuTemplate = sListMenuTemplate_ThreeOptions;
    s32 response;

    if (whichMenu == 0)
        listMenuTemplate.items = sListMenuItems_CardsOrNews;
    else
        listMenuTemplate.items = sListMenuItems_WirelessOrFriend;

    response = DoMysteryGiftListMenu(&sWindowTemplate_ThreeOptions, &listMenuTemplate, 1, 0xA, 0xE0);
    if (response != LIST_NOTHING_CHOSEN)
    {
        ClearWindowTilemap(WIN_UNK);
        CopyWindowToVram(WIN_UNK, COPYWIN_MAP);
    }
    return response;
}

s8 DoMysteryGiftYesNo(u8 *textState, u16 *windowId, bool8 yesNoBoxPlacement, const u8 *str)
{
    struct WindowTemplate windowTemplate;
    s8 input;

    switch (*textState)
    {
    case 0:
        StringExpandPlaceholders(gStringVar4, str);
        if (yesNoBoxPlacement == 0)
            *windowId = AddWindow(&sWindowTemplate_YesNoMsg_Wide);
        else
            *windowId = AddWindow(&sWindowTemplate_YesNoMsg);
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, FONT_NORMAL, 2, 2, 0, 1, sMG_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, COPYWIN_GFX);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        windowTemplate = sWindowTemplate_YesNoBox;
        if (yesNoBoxPlacement == 0)
            windowTemplate.tilemapTop = 9;
        else
            windowTemplate.tilemapTop = 15;
        CreateYesNoMenuAtPos(&windowTemplate, FONT_NORMAL, 2, 2, 10, 14, 0);
        (*textState)++;
        break;
    case 2:
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input == MENU_B_PRESSED || input == 0 || input == 1)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, COPYWIN_MAP);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case 0xFF:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, COPYWIN_MAP);
        RemoveWindow(*windowId);
        return MENU_B_PRESSED;
    }
    return MENU_NOTHING_CHOSEN;
}

s32 HandleGiftSelectMenu(u8 *textState, u16 *windowId, bool32 cannotToss, bool32 cannotSend)
{
    s32 input;

    switch (*textState)
    {
    case 0:
        if (!cannotToss)
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithCards);
        else
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithNews);
        *windowId = AddWindow(&sWindowTemplate_GiftSelect);
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, FONT_NORMAL, 2, 2, 0, 1, sMG_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, COPYWIN_GFX);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        if (cannotSend)
        {
            if (!cannotToss)
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_2Options, &sListMenu_ReceiveToss, 1, 0xA, 0xE0);
            else
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_1Option, &sListMenu_Receive, 1, 0xA, 0xE0);
        }
        else
        {
            if (!cannotToss)
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_3Options, &sListMenu_ReceiveSendToss, 1, 0xA, 0xE0);
            else
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_2Options, &sListMenu_ReceiveSend, 1, 0xA, 0xE0);
        }
        if (input != LIST_NOTHING_CHOSEN)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, COPYWIN_MAP);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case 0xFF:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, COPYWIN_MAP);
        RemoveWindow(*windowId);
        return LIST_CANCEL;
    }
    return LIST_NOTHING_CHOSEN;
}

bool32 ValidateCardOrNews(bool32 isWonderNews)
{
    if (!isWonderNews)
        return ValidateReceivedWonderCard();
    else
        return ValidateReceivedWonderNews();
}

bool32 HandleLoadWonderCardOrNews(u8 *state, bool32 isWonderNews)
{
    switch (*state)
    {
    case 0:
        if (!isWonderNews)
            InitWonderCardResources(GetSavedWonderCard(), sav1_get_mevent_buffer_2());
        else
            InitWonderNewsResources(GetSavedWonderNews());
        (*state)++;
        break;
    case 1:
        if (!isWonderNews)
        {
            if (!FadeToWonderCardMenu())
                return FALSE;
        }
        else
        {
            if (!FadeToWonderNewsMenu())
                return FALSE;
        }
        *state = 0;
        return TRUE;
    }

    return FALSE;
}

bool32 DestroyNewsOrCard(bool32 isWonderNews)
{
    if (!isWonderNews)
        DestroyWonderCard();
    else
        DestroyWonderNews();
    return TRUE;
}

bool32 TearDownCardOrNews_ReturnToTopMenu(bool32 isWonderNews)
{
    if (!isWonderNews)
    {
        if (FadeOutFromWonderCard())
            DestroyWonderCardResources();
        else
            return FALSE;
    }
    else
    {
        if (FadeOutFromWonderNews())
            DestroyWonderNewsResources();
        else
            return FALSE;
    }
    return TRUE;
}

// JP: declared s32 so callers treat the result as already sign-extended
// (the base ROM's callers do not re-sign-extend this s8 value).
s32 mevent_message_prompt_discard(u8 *textState, u16 *windowId, bool32 isWonderNews)
{
    if (isWonderNews == 0)
        return DoMysteryGiftYesNo(textState, windowId, 1, sText_DiscardWonderCard);
    else
        return DoMysteryGiftYesNo(textState, windowId, 1, sText_DiscardWonderNews);
}

bool32 mevent_message_was_thrown_away(u8 *state, bool32 isWonderNews)
{
    if (!isWonderNews)
        return PrintMysteryGiftMenuMessage(state, sText_WasThrownAwayWonderCard);
    else
        return PrintMysteryGiftMenuMessage(state, sText_WasThrownAwayWonderNews);
}

bool32 mevent_save_game(u8 *state)
{
    switch (*state)
    {
    case 0:
        MG_AddMessageTextPrinter(sText_SavingGame1);
        (*state)++;
        break;
    case 1:
        TrySavingData(0);
        (*state)++;
        break;
    case 2:
        MG_AddMessageTextPrinter(sText_SavingGame2);
        (*state)++;
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            (*state)++;
        break;
    case 4:
        *state = 0;
        ClearMessage();
        return TRUE;
    }
    return FALSE;
}

u16 GetMysteryGiftBaseBlock(void)
{
    return 0x1A9;
}

void bgid_upload_textbox_1(u8 bgId)
{
    DecompressAndLoadBgGfxUsingHeap(bgId, sTextboxBorder_Gfx, 0x100, 0, 0);
}

const u8 *mevent_message(u32 *out, u8 param1, u8 param2, u32 msgId)
{
    const u8 *ret = NULL;

    *out = 0;
    switch (msgId)
    {
    case 0: *out = 0; ret = sJPText_MeventMsg0; break;
    case 1: *out = 0; ret = sJPText_MeventMsg1; break;
    case 2: *out = 1; ret = sJPText_MeventMsg2a; if (param2 == 0) ret = sJPText_MeventMsg2b; break;
    case 3: *out = 1; ret = sJPText_MeventMsg3a; if (param2 == 0) ret = sJPText_MeventMsg3b; break;
    case 4: *out = 1; ret = sJPText_MeventMsg4; break;
    case 5: *out = 0; ret = sJPText_MeventMsg5; break;
    case 6: *out = 0; ret = sJPText_MeventMsg6; break;
    case 7: *out = 0; ret = sJPText_MeventMsg7; break;
    case 8: *out = 0; ret = sJPText_MeventMsg8; break;
    case 9: *out = 0; ret = sJPText_MeventMsg9; break;
    case 10: *out = 0; ret = sJPText_MeventMsg10a; if (param1 == 0) ret = sJPText_MeventMsg10b; break;
    case 11: *out = 0; ret = sJPText_MeventMsg11; break;
    case 12: *out = 1; ret = sJPText_MeventMsg12; break;
    case 13: *out = 1; break;
    case 14: *out = 0; break;
    }
    return ret;
}

bool32 PrintMGSuccessMessage(u8 *state, const u8 *str, u16 *counter)
{
    switch (*state)
    {
    case 0:
        if (str != NULL)
            MG_AddMessageTextPrinter(str);
        PlayFanfare(0x172);
        *counter = 0;
        (*state)++;
        break;
    case 1:
        (*counter)++;
        if (*counter > 240)
            (*state)++;
        break;
    case 2:
        if (IsFanfareTaskInactive())
        {
            *state = 0;
            ClearMessage();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

const u8 *mevent_message_stamp_card_etc_send_status(u32 *out, u8 unused, u32 status)
{
    const u8 *ret = sJPText_MeventMsg11;

    *out = 0;
    switch (status)
    {
    case 0: ret = sJPText_MeventMsg0; break;
    case 1: ret = sJPText_MeventMsg1; break;
    case 2: ret = sJPText_StampMsg2; *out = 1; break;
    case 3: ret = sJPText_StampMsg3; *out = 1; break;
    case 4: ret = sJPText_StampMsg4; break;
    case 5: ret = sJPText_StampMsg5; break;
    case 6: ret = sJPText_StampMsg6; break;
    case 7: ret = sJPText_StampMsg7; break;
    case 8: ret = sJPText_MeventMsg8; break;
    case 9: ret = sJPText_StampMsg9; break;
    case 10: ret = sJPText_StampMsg14; break;
    case 11: ret = sJPText_MeventMsg11; break;
    case 12: ret = sJPText_StampMsg12; break;
    case 13: ret = sJPText_StampMsg12; break;
    case 14: ret = sJPText_StampMsg14; break;
    default: break;
    }
    return ret;
}

bool32 PrintMGSendStatus(u8 *state, u16 *counter, u8 unused, u32 status)
{
    u32 out;
    const u8 *str = mevent_message_stamp_card_etc_send_status(&out, unused, status);

    if (out != 0)
        return PrintMGSuccessMessage(state, str, counter);
    else
        return PrintMysteryGiftMenuMessage(state, str);
}

// States for task00_mystery_gift.  Mirrors the US MG_STATE_* enum; JP uses
// the same values (0..37).
enum {
    MG_STATE_TO_MAIN_MENU,
    MG_STATE_MAIN_MENU,
    MG_STATE_DONT_HAVE_ANY,
    MG_STATE_SOURCE_PROMPT,
    MG_STATE_SOURCE_PROMPT_INPUT,
    MG_STATE_CLIENT_LINK_START,
    MG_STATE_CLIENT_LINK_WAIT,
    MG_STATE_CLIENT_COMMUNICATING,
    MG_STATE_CLIENT_LINK,
    MG_STATE_CLIENT_YES_NO,
    MG_STATE_CLIENT_MESSAGE,
    MG_STATE_CLIENT_ASK_TOSS,
    MG_STATE_CLIENT_ASK_TOSS_UNRECEIVED,
    MG_STATE_CLIENT_LINK_END,
    MG_STATE_CLIENT_COMM_COMPLETED,
    MG_STATE_CLIENT_RESULT_MSG,
    MG_STATE_CLIENT_ERROR,
    MG_STATE_SAVE_LOAD_GIFT,
    MG_STATE_LOAD_GIFT,
    MG_STATE_UNUSED,
    MG_STATE_HANDLE_GIFT_INPUT,
    MG_STATE_HANDLE_GIFT_SELECT,
    MG_STATE_ASK_TOSS,
    MG_STATE_ASK_TOSS_UNRECEIVED,
    MG_STATE_TOSS,
    MG_STATE_TOSS_SAVE,
    MG_STATE_TOSSED,
    MG_STATE_GIFT_INPUT_EXIT,
    MG_STATE_RECEIVE,
    MG_STATE_SEND,
    MG_STATE_SERVER_LINK_WAIT,
    MG_STATE_SERVER_LINK_START,
    MG_STATE_SERVER_LINK,
    MG_STATE_SERVER_LINK_END,
    MG_STATE_SERVER_LINK_END_WAIT,
    MG_STATE_SERVER_RESULT_MSG,
    MG_STATE_SERVER_ERROR,
    MG_STATE_EXIT,
};

struct MysteryGiftTaskData
{
    u16 var; // Multipurpose
    u16 unused1;
    u16 unused2;
    u16 unused3;
    u8 state;
    u8 textState;
    u8 unused4;
    u8 unused5;
    bool8 isWonderNews;
    bool8 sourceIsFriend;
    u8 msgId;
    u8 *clientMsg;
};

// JP: still in asm/mevent*.s; revert to C names as they are converted.
extern void mevent_client_do_init(u8 isWonderNews);
extern u32 mevent_client_do_exec(u16 *var);
extern const u8 *mevent_client_get_buffer(void);
extern void mevent_client_set_param(u32 param);
extern void mevent_client_inc_flag(void);
extern void mevent_srv_new_wcard(void);
extern void mevent_srv_init_wnews(void);
extern u32 mevent_srv_common_do_exec(u16 *var);
extern void GenerateRandomNews(u32 newsId);
extern bool32 CheckReceivedGiftFromWonderCard(void);
extern bool32 WonderCard_Test_Unk_08_6(void);
extern bool32 WonderNews_Test_Unk_02(void);
extern u32 MENews_GetInput(u16 newKeys);
extern void MENews_RemoveScrollIndicatorArrowPair(void);
extern void MENews_AddScrollIndicatorArrowPair(void);

// JP: text bound via ld_script_jp.txt.
extern const u8 sJPText_MgDontHaveCard[];
extern const u8 sJPText_MgDontHaveNews[];
extern const u8 sJPText_MgWhereCard[];
extern const u8 sJPText_MgWhereNews[];
extern const u8 sJPText_MgCommunicating[];
extern const u8 sJPText_MgCommCompleted[];
extern const u8 sJPText_MgThrowAwayCard[];
extern const u8 sJPText_MgHaventReceived[];
extern const u8 sJPText_MgDiscardConfirm[];
extern const u8 sJPText_MgSendingCard[];
extern const u8 sJPText_MgSendingNews[];

void task00_mystery_gift(u8 taskId);

void task_add_00_mystery_gift(void)
{
    u8 taskId = CreateTask(task00_mystery_gift, 0);
    struct MysteryGiftTaskData *data = (void *)gTasks[taskId].data;

    data->state = MG_STATE_TO_MAIN_MENU;
    data->textState = 0;
    data->unused4 = 0;
    data->unused5 = 0;
    data->isWonderNews = FALSE;
    data->sourceIsFriend = FALSE;
    data->var = 0;
    data->unused1 = 0;
    data->unused2 = 0;
    data->unused3 = 0;
    data->msgId = 0;
    data->clientMsg = AllocZeroed(0x40);
}

void task00_mystery_gift(u8 taskId)
{
    struct MysteryGiftTaskData *data = (void *)gTasks[taskId].data;
    u32 successMsg, input;
    const u8 *msg;

    switch (data->state)
    {
    case MG_STATE_TO_MAIN_MENU:
        data->state = MG_STATE_MAIN_MENU;
        break;
    case MG_STATE_MAIN_MENU:
        // Main Mystery Gift menu, player can select Wonder Cards or News (or exit)
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->var, FALSE))
        {
        case 0: // "Wonder Cards"
            data->isWonderNews = FALSE;
            if (ValidateReceivedWonderCard() == TRUE)
                data->state = MG_STATE_LOAD_GIFT;
            else
                data->state = MG_STATE_DONT_HAVE_ANY;
            break;
        case 1: // "Wonder News"
            data->isWonderNews = TRUE;
            if (ValidateReceivedWonderNews() == TRUE)
                data->state = MG_STATE_LOAD_GIFT;
            else
                data->state = MG_STATE_DONT_HAVE_ANY;
            break;
        case LIST_CANCEL:
            data->state = MG_STATE_EXIT;
            break;
        }
        break;
    case MG_STATE_DONT_HAVE_ANY:
        if (!data->isWonderNews)
        {
            if (PrintMysteryGiftMenuMessage(&data->textState, sJPText_MgDontHaveCard))
                data->state = MG_STATE_SOURCE_PROMPT;
        }
        else
        {
            if (PrintMysteryGiftMenuMessage(&data->textState, sJPText_MgDontHaveNews))
                data->state = MG_STATE_SOURCE_PROMPT;
        }
        break;
    case MG_STATE_SOURCE_PROMPT:
        if (!data->isWonderNews)
            MG_AddMessageTextPrinter(sJPText_MgWhereCard);
        else
            MG_AddMessageTextPrinter(sJPText_MgWhereNews);
        data->state = MG_STATE_SOURCE_PROMPT_INPUT;
        break;
    case MG_STATE_SOURCE_PROMPT_INPUT:
        // Choose where to access the Wonder Card/News from
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->var, TRUE))
        {
        case 0: // "Wireless Communication"
            ClearMessage();
            data->state = MG_STATE_CLIENT_LINK_START;
            data->sourceIsFriend = FALSE;
            break;
        case 1: // "Friend"
            ClearMessage();
            data->state = MG_STATE_CLIENT_LINK_START;
            data->sourceIsFriend = TRUE;
            break;
        case LIST_CANCEL:
            ClearMessage();
            if (ValidateCardOrNews(data->isWonderNews))
                data->state = MG_STATE_LOAD_GIFT;
            else
                data->state = MG_STATE_TO_MAIN_MENU;
            break;
        }
        break;
    case MG_STATE_CLIENT_LINK_START:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        switch (data->isWonderNews)
        {
        case FALSE:
            if (data->sourceIsFriend == TRUE)
                CreateTask_LinkMysteryGiftWithFriend(ACTIVITY_WONDER_CARD_DUP);
            else if (data->sourceIsFriend == FALSE)
                CreateTask_LinkMysteryGiftOverWireless(ACTIVITY_WONDER_CARD_DUP);
            break;
        case TRUE:
            if (data->sourceIsFriend == TRUE)
                CreateTask_LinkMysteryGiftWithFriend(ACTIVITY_WONDER_NEWS_DUP);
            else if (data->sourceIsFriend == FALSE)
                CreateTask_LinkMysteryGiftOverWireless(ACTIVITY_WONDER_NEWS_DUP);
            break;
        }
        data->state = MG_STATE_CLIENT_LINK_WAIT;
        break;
    case MG_STATE_CLIENT_LINK_WAIT:
        if (gReceivedRemoteLinkPlayers)
        {
            ClearScreenInBg0(TRUE);
            data->state = MG_STATE_CLIENT_COMMUNICATING;
            mevent_client_do_init(data->isWonderNews);
        }
        else if (gSpecialVar_Result == LINKUP_FAILED)
        {
            // Link failed, return to link start menu
            ClearScreenInBg0(TRUE);
            data->state = MG_STATE_SOURCE_PROMPT;
        }
        break;
    case MG_STATE_CLIENT_COMMUNICATING:
        MG_AddMessageTextPrinter(sJPText_MgCommunicating);
        data->state = MG_STATE_CLIENT_LINK;
        break;
    case MG_STATE_CLIENT_LINK:
        switch (mevent_client_do_exec(&data->var) - 2)
        {
        case 4: // link end
            Rfu_SetCloseLinkCallback();
            data->msgId = data->var;
            data->state = MG_STATE_CLIENT_LINK_END;
            break;
        case 3: // copy message
            memcpy(data->clientMsg, mevent_client_get_buffer(), 0x40);
            mevent_client_inc_flag();
            break;
        case 1: // print message
            data->state = MG_STATE_CLIENT_MESSAGE;
            break;
        case 0: // yes/no prompt
            data->state = MG_STATE_CLIENT_YES_NO;
            break;
        case 2: // ask toss
            data->state = MG_STATE_CLIENT_ASK_TOSS;
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            break;
        }
        break;
    case MG_STATE_CLIENT_YES_NO:
        input = DoMysteryGiftYesNo(&data->textState, &data->var, FALSE, mevent_client_get_buffer());
        switch (input)
        {
        case 0: // Yes
            mevent_client_set_param(FALSE);
            mevent_client_inc_flag();
            data->state = MG_STATE_CLIENT_COMMUNICATING;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            mevent_client_set_param(TRUE);
            mevent_client_inc_flag();
            data->state = MG_STATE_CLIENT_COMMUNICATING;
            break;
        }
        break;
    case MG_STATE_CLIENT_MESSAGE:
        if (PrintMysteryGiftMenuMessage(&data->textState, mevent_client_get_buffer()))
        {
            mevent_client_inc_flag();
            data->state = MG_STATE_CLIENT_COMMUNICATING;
        }
        break;
    case MG_STATE_CLIENT_ASK_TOSS:
        // Player is receiving a new Wonder Card/News but needs to toss an existing one to make room.
        // Ask for confirmation.
        input = DoMysteryGiftYesNo(&data->textState, &data->var, FALSE, sJPText_MgThrowAwayCard);
        switch (input)
        {
        case 0: // Yes
            if (CheckReceivedGiftFromWonderCard() == TRUE)
                data->state = MG_STATE_CLIENT_ASK_TOSS_UNRECEIVED;
            else
            {
                mevent_client_set_param(FALSE);
                mevent_client_inc_flag();
                data->state = MG_STATE_CLIENT_COMMUNICATING;
            }
            break;
        case 1: // No
        case MENU_B_PRESSED:
            mevent_client_set_param(TRUE);
            mevent_client_inc_flag();
            data->state = MG_STATE_CLIENT_COMMUNICATING;
            break;
        }
        break;
    case MG_STATE_CLIENT_ASK_TOSS_UNRECEIVED:
        // Player has selected to toss a Wonder Card that they haven't received the gift for.
        // Ask for confirmation again.
        input = DoMysteryGiftYesNo(&data->textState, &data->var, FALSE, sJPText_MgHaventReceived);
        switch (input)
        {
        case 0: // Yes
            mevent_client_set_param(FALSE);
            mevent_client_inc_flag();
            data->state = MG_STATE_CLIENT_COMMUNICATING;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            mevent_client_set_param(TRUE);
            mevent_client_inc_flag();
            data->state = MG_STATE_CLIENT_COMMUNICATING;
            break;
        }
        break;
    case MG_STATE_CLIENT_LINK_END:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = MG_STATE_CLIENT_COMM_COMPLETED;
        }
        break;
    case MG_STATE_CLIENT_COMM_COMPLETED:
        if (PrintStringAndWait2Seconds(&data->textState, sJPText_MgCommCompleted))
        {
            if (data->sourceIsFriend == TRUE)
                StringCopy(gStringVar1, gLinkPlayers[0].name);
            data->state = MG_STATE_CLIENT_RESULT_MSG;
        }
        break;
    case MG_STATE_CLIENT_RESULT_MSG:
        msg = mevent_message(&successMsg, data->isWonderNews, data->sourceIsFriend, data->msgId);
        if (msg == NULL)
            msg = data->clientMsg;
        if (successMsg)
            input = PrintMGSuccessMessage(&data->textState, msg, &data->var);
        else
            input = PrintMysteryGiftMenuMessage(&data->textState, msg);
        // input var re-used, here it is TRUE if the message is finished
        if (input)
        {
            if (data->msgId == CLI_MSG_NEWS_RECEIVED)
            {
                if (data->sourceIsFriend == TRUE)
                    GenerateRandomNews(1);
                else
                    GenerateRandomNews(2);
            }
            if (!successMsg)
                data->state = MG_STATE_TO_MAIN_MENU;
            else
                data->state = MG_STATE_SAVE_LOAD_GIFT;
        }
        break;
    case MG_STATE_SAVE_LOAD_GIFT:
        if (mevent_save_game(&data->textState))
            data->state = MG_STATE_LOAD_GIFT;
        break;
    case MG_STATE_LOAD_GIFT:
        if (HandleLoadWonderCardOrNews(&data->textState, data->isWonderNews))
            data->state = MG_STATE_HANDLE_GIFT_INPUT;
        break;
    case MG_STATE_UNUSED:
        break;
    case MG_STATE_HANDLE_GIFT_INPUT:
        if (!data->isWonderNews)
        {
            // Handle Wonder Card input
            if (JOY_NEW(A_BUTTON))
                data->state = MG_STATE_HANDLE_GIFT_SELECT;
            if (JOY_NEW(B_BUTTON))
                data->state = MG_STATE_GIFT_INPUT_EXIT;
        }
        else
        {
            switch (MENews_GetInput(gMain.newKeys))
            {
            case NEWS_INPUT_A:
                MENews_RemoveScrollIndicatorArrowPair();
                data->state = MG_STATE_HANDLE_GIFT_SELECT;
                break;
            case NEWS_INPUT_B:
                data->state = MG_STATE_GIFT_INPUT_EXIT;
                break;
            }
        }
        break;
    case MG_STATE_HANDLE_GIFT_SELECT:
    {
        // A Wonder Card/News has been selected, handle its menu
        u32 result;

        if (!data->isWonderNews)
        {
            if (WonderCard_Test_Unk_08_6())
                result = HandleGiftSelectMenu(&data->textState, &data->var, data->isWonderNews, FALSE);
            else
                result = HandleGiftSelectMenu(&data->textState, &data->var, data->isWonderNews, TRUE);
        }
        else
        {
            if (WonderNews_Test_Unk_02())
                result = HandleGiftSelectMenu(&data->textState, &data->var, data->isWonderNews, FALSE);
            else
                result = HandleGiftSelectMenu(&data->textState, &data->var, data->isWonderNews, TRUE);
        }
        switch (result)
        {
        case 0: // Receive
            data->state = MG_STATE_RECEIVE;
            break;
        case 1: // Send
            data->state = MG_STATE_SEND;
            break;
        case 2: // Toss
            data->state = MG_STATE_ASK_TOSS;
            break;
        case LIST_CANCEL:
            if (data->isWonderNews == TRUE)
                MENews_AddScrollIndicatorArrowPair();
            data->state = MG_STATE_HANDLE_GIFT_INPUT;
            break;
        }
        break;
    }
    case MG_STATE_ASK_TOSS:
        // Player is attempting to discard a saved Wonder Card/News
        switch (mevent_message_prompt_discard(&data->textState, &data->var, data->isWonderNews))
        {
        case 0: // Yes
            if (!data->isWonderNews && CheckReceivedGiftFromWonderCard() == TRUE)
                data->state = MG_STATE_ASK_TOSS_UNRECEIVED;
            else
                data->state = MG_STATE_TOSS;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            data->state = MG_STATE_HANDLE_GIFT_SELECT;
            break;
        }
        break;
    case MG_STATE_ASK_TOSS_UNRECEIVED:
        // Player has selected to toss a Wonder Card that they haven't received the gift for.
        // Ask for confirmation again.
        input = DoMysteryGiftYesNo(&data->textState, &data->var, TRUE, sJPText_MgDiscardConfirm);
        switch (input)
        {
        case 0: // Yes
            data->state = MG_STATE_TOSS;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            data->state = MG_STATE_HANDLE_GIFT_SELECT;
            break;
        }
        break;
    case MG_STATE_TOSS:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews))
        {
            DestroyNewsOrCard(data->isWonderNews);
            data->state = MG_STATE_TOSS_SAVE;
        }
        break;
    case MG_STATE_TOSS_SAVE:
        if (mevent_save_game(&data->textState))
            data->state = MG_STATE_TOSSED;
        break;
    case MG_STATE_TOSSED:
        if (mevent_message_was_thrown_away(&data->textState, data->isWonderNews))
            data->state = MG_STATE_TO_MAIN_MENU;
        break;
    case MG_STATE_GIFT_INPUT_EXIT:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews))
            data->state = MG_STATE_TO_MAIN_MENU;
        break;
    case MG_STATE_RECEIVE:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews))
            data->state = MG_STATE_SOURCE_PROMPT;
        break;
    case MG_STATE_SEND:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews))
        {
            switch (data->isWonderNews)
            {
            case FALSE:
                CreateTask_SendMysteryGift(ACTIVITY_WONDER_CARD_DUP);
                break;
            case TRUE:
                CreateTask_SendMysteryGift(ACTIVITY_WONDER_NEWS_DUP);
                break;
            }
            data->sourceIsFriend = TRUE;
            data->state = MG_STATE_SERVER_LINK_WAIT;
        }
        break;
    case MG_STATE_SERVER_LINK_WAIT:
        if (gReceivedRemoteLinkPlayers)
        {
            ClearScreenInBg0(TRUE);
            data->state = MG_STATE_SERVER_LINK_START;
        }
        else if (gSpecialVar_Result == LINKUP_FAILED)
        {
            ClearScreenInBg0(TRUE);
            data->state = MG_STATE_LOAD_GIFT;
        }
        break;
    case MG_STATE_SERVER_LINK_START:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        if (!data->isWonderNews)
        {
            MG_AddMessageTextPrinter(sJPText_MgSendingCard);
            mevent_srv_new_wcard();
        }
        else
        {
            MG_AddMessageTextPrinter(sJPText_MgSendingNews);
            mevent_srv_init_wnews();
        }
        data->state = MG_STATE_SERVER_LINK;
        break;
    case MG_STATE_SERVER_LINK:
        if (mevent_srv_common_do_exec(&data->var) == SVR_RET_END)
        {
            data->msgId = data->var;
            data->state = MG_STATE_SERVER_LINK_END;
        }
        break;
    case MG_STATE_SERVER_LINK_END:
        Rfu_SetCloseLinkCallback();
        StringCopy(gStringVar1, gLinkPlayers[1].name);
        data->state = MG_STATE_SERVER_LINK_END_WAIT;
        break;
    case MG_STATE_SERVER_LINK_END_WAIT:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = MG_STATE_SERVER_RESULT_MSG;
        }
        break;
    case MG_STATE_SERVER_RESULT_MSG:
        if (PrintMGSendStatus(&data->textState, &data->var, data->sourceIsFriend, data->msgId))
        {
            if (data->sourceIsFriend == TRUE && data->msgId == SVR_MSG_NEWS_SENT)
            {
                GenerateRandomNews(3);
                data->state = MG_STATE_SAVE_LOAD_GIFT;
            }
            else
            {
                data->state = MG_STATE_TO_MAIN_MENU;
            }
        }
        break;
    case MG_STATE_SERVER_ERROR:
    case MG_STATE_CLIENT_ERROR:
        // There was an error during the link process.
        if (PrintMysteryGiftMenuMessage(&data->textState, sJPText_MeventMsg11))
            data->state = MG_STATE_TO_MAIN_MENU;
        break;
    case MG_STATE_EXIT:
        CloseLink();
        Free(data->clientMsg);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}
