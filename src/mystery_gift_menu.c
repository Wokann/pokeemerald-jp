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

s8 mevent_message_prompt_discard(u8 *textState, u16 *windowId, bool32 isWonderNews)
{
    if (isWonderNews == 0)
        return DoMysteryGiftYesNo(textState, windowId, 1, sText_DiscardWonderCard);
    else
        return DoMysteryGiftYesNo(textState, windowId, 1, sText_DiscardWonderNews);
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
