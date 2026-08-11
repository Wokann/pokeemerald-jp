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
