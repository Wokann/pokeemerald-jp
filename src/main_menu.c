#include "global.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "menu.h"
#include "mystery_event_menu.h"
#include "mystery_gift_menu.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"

// JP keeps these tables in ROM; US builds them in C.
extern const u16 sMainMenuBgPal[];
extern const u16 sMainMenuTextPal[];
extern const struct BgTemplate sMainMenuBgTemplates[];
extern const struct WindowTemplate sWindowTemplates_MainMenu[];

extern void LoadMainMenuWindowFrameTiles(u8 windowId, u16 tileNum);
extern void Task_MainMenuCheckSaveFile(u8 taskId);
extern const u8 gUnknown_85C8D93[];
extern const u8 gUnknown_85C8C70[];
extern const u8 gUnknown_85C8C7C[];
extern const u8 gUnknown_85C8C87[];
extern const u8 gUnknown_85C8C91[];
extern const u8 gUnknown_85C8C9C[];
extern const u8 gUnknown_85C8CA7[];
extern const u8 gUnknown_85C8CB1[];
extern const u8 gUnknown_85C8CC7[];
extern const u8 gUnknown_85C8CEB[];
extern const struct BgTemplate sBirchBgTemplate;
extern const u32 sBirchSpeechShadowGfx[];
extern const u32 sBirchSpeechBgMap[];
extern const u16 sBirchSpeechBgPals[][16];
extern const u16 sBirchSpeechBgGradientPal[];
extern const struct WindowTemplate sNewGameBirchSpeechTextWindows[];
extern const u8 gUnknown_8277095[];
extern const u8 gUnknown_85C8F88[];
extern const u8 gUnknown_8277102[];
extern const u8 gUnknown_82771F4[];
extern const u8 gUnknown_8277200[];
extern void CreateMainMenuErrorWindow(const u8 *text);
extern void ClearMainMenuWindowTilemap(const struct WindowTemplate *);
extern void Task_DisplayMainMenu(u8 taskId);
extern u16 sCurrItemAndOptionMenuCheck;
extern const struct TextColor sTextColor_Headers;
extern const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu;
extern void MainMenu_FormatSavegameText(void);
extern void DrawMainMenuWindowBorder(const struct WindowTemplate *windowTemplate, u16 tileNum);
extern u8 AddScrollIndicatorArrowPair(const struct ScrollArrowsTemplate *template, u16 *ignore);
extern void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId);
extern void Task_HighlightSelectedMainMenuItem(u8 taskId);
extern void Task_NewGameBirchSpeech_Init(u8 taskId);
extern void Task_NewGameBirchSpeech_WaitToShowBirch(u8 taskId);
extern void Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome(u8 taskId);
extern void Task_NewGameBirchSpeech_AndYouAre(u8 taskId);
extern void AddBirchSpeechObjects(u8 taskId);
extern void NewGameBirchSpeech_StartFadeInTarget1OutTarget2(u8 taskId, u8 a1);
extern void NewGameBirchSpeech_StartFadePlatformOut(u8 taskId, u8 a1);
extern void NewGameBirchSpeech_StartFadeOutTarget1InTarget2(u8 taskId, u8 a1);
extern void NewGameBirchSpeech_StartFadePlatformIn(u8 taskId, u8 a1);
extern void NewGameBirchSpeech_ShowDialogueWindow(u8 taskId, u8 windowId);
extern void NewGameBirchSpeech_ClearWindow(u8 taskId);
extern void NewGameBirchSpeech_ShowPokeBallPrinterCallback(struct TextPrinter *textPrinter);
extern void Task_NewGameBirchSpeech_SlidePlatformAway(u8 taskId);
extern void NewGameBirchSpeech_ShowGenderMenu(void);
extern s8 NewGameBirchSpeech_ProcessGenderMenuInput(void);
extern void NewGameBirchSpeech_ClearGenderWindow(u8 taskId, u8 windowId);
extern void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId);
extern u8 sBirchSpeechMainTaskId;
extern u8 sStartedPokeBallTask;

static void Task_HighlightSelectedMainMenuItem(u8 taskId);
static bool8 HandleMainMenuInput(u8 taskId);
static void Task_HandleMainMenuInput(u8 taskId);
static void Task_HandleMainMenuAPressed(u8 taskId);
static void Task_HandleMainMenuBPressed(u8 taskId);
static void Task_DisplayMainMenuInvalidActionError(u8 taskId);
static void HighlightSelectedMainMenuItem(u8 menuType, u8 selectedMenuItem, s16 isScrolled);
static void Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome(u8 taskId);
static void Task_NewGameBirchSpeech_ThisIsAPokemon(u8 taskId);
static void Task_NewGameBirchSpeech_MainSpeech(u8 taskId);
static void Task_NewGameBirchSpeechSub_InitPokeBall(u8 taskId);
static void Task_NewGameBirchSpeechSub_WaitForLotad(u8 taskId);
static void Task_NewGameBirchSpeech_AndYouAre(u8 taskId);
static void Task_NewGameBirchSpeech_StartBirchLotadPlatformFade(u8 taskId);
static void Task_NewGameBirchSpeech_SlidePlatformAway(u8 taskId);
static void Task_NewGameBirchSpeech_StartPlayerFadeIn(u8 taskId);
static void Task_NewGameBirchSpeech_WaitForPlayerFadeIn(u8 taskId);
static void Task_NewGameBirchSpeech_BoyOrGirl(u8 taskId);
static void Task_NewGameBirchSpeech_WaitToShowGenderMenu(u8 taskId);
static void Task_NewGameBirchSpeech_ChooseGender(u8 taskId);
static void Task_NewGameBirchSpeech_SlideOutOldGenderSprite(u8 taskId);
static void Task_NewGameBirchSpeech_SlideInNewGenderSprite(u8 taskId);

#define tPlayerSpriteId data[2]
#define tPlayerGender data[6]
#define tBG1HOFS data[4]
#define tTimer data[7]
#define tBirchSpriteId data[8]
#define tLotadSpriteId data[9]
#define tBrendanSpriteId data[10]
#define tMaySpriteId data[11]
#define tIsDoneFadingSprites data[5]

#define tState data[0]

#define OPTION_MENU_FLAG (1 << 15)

enum
{
    ACTION_NEW_GAME,
    ACTION_CONTINUE,
    ACTION_OPTION,
    ACTION_MYSTERY_GIFT,
    ACTION_MYSTERY_EVENTS,
    ACTION_EREADER,
    ACTION_INVALID
};

enum
{
    HAS_NO_SAVED_GAME,
    HAS_SAVED_GAME,
    HAS_MYSTERY_GIFT,
    HAS_MYSTERY_EVENTS,
};

#define tMenuType data[0]
#define tCurrItem data[1]
#define tItemCount data[12]
#define tScrollArrowTaskId data[13]
#define tIsScrolled data[14]
#define tWirelessAdapterConnected data[15]

#define tArrowTaskIsScrolled data[15]

static void Task_WaitForBatteryDryErrorWindow(u8 taskId);
static void Task_MainMenuCheckBattery(u8 taskId);
static void Task_WaitForSaveFileErrorWindow(u8 taskId);

#define MAIN_MENU_BORDER_TILE 0x1D5

static void CB2_MainMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_MainMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitMainMenu(void)
{
    InitMainMenu(FALSE);
}

void CB2_ReinitMainMenu(void)
{
    InitMainMenu(TRUE);
}

static u32 InitMainMenu(bool8 returningFromOptionsMenu)
{
    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);

    ResetPaletteFade();
    LoadPalette(sMainMenuBgPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    if (returningFromOptionsMenu)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK); // fade to black
    else
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_WHITEALPHA); // fade to white
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, 2);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    InitWindows(sWindowTemplates_MainMenu);
    DeactivateAllTextPrinters();
    LoadMainMenuWindowFrameTiles(0, MAIN_MENU_BORDER_TILE);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    HideBg(1);
    CreateTask(Task_MainMenuCheckSaveFile, 0);

    return 0;
}

static void Task_WaitForBatteryDryErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (JOY_NEW(A_BUTTON)))
    {
        ClearWindowTilemap(7);
        ClearMainMenuWindowTilemap(&sWindowTemplates_MainMenu[7]);
        gTasks[taskId].func = Task_MainMenuCheckBattery;
    }
}

static void Task_MainMenuCheckBattery(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);

        if (!(RtcGetErrorStatus() & RTC_ERR_FLAG_MASK))
        {
            gTasks[taskId].func = Task_DisplayMainMenu;
        }
        else
        {
            CreateMainMenuErrorWindow(gUnknown_85C8D93);
            gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
        }
    }
}

static void Task_WaitForSaveFileErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (JOY_NEW(A_BUTTON)))
    {
        ClearWindowTilemap(7);
        ClearMainMenuWindowTilemap(&sWindowTemplates_MainMenu[7]);
        gTasks[taskId].func = Task_DisplayMainMenu;
    }
}

static void Task_DisplayMainMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 palette;

    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);

        palette = RGB_BLACK;
        LoadPalette(&palette, BG_PLTT_ID(15) + 14, PLTT_SIZEOF(1));

        palette = RGB_WHITE;
        LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));

        palette = RGB(12, 12, 12);
        LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));

        palette = RGB(26, 26, 25);
        LoadPalette(&palette, BG_PLTT_ID(15) + 12, PLTT_SIZEOF(1));

        // Note: If there is no save file, the save block is zeroed out,
        // so the default gender is MALE.
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            palette = RGB(4, 16, 31);
            LoadPalette(&palette, BG_PLTT_ID(15) + 1, PLTT_SIZEOF(1));
        }
        else
        {
            palette = RGB(31, 3, 21);
            LoadPalette(&palette, BG_PLTT_ID(15) + 1, PLTT_SIZEOF(1));
        }

        switch (gTasks[taskId].tMenuType)
        {
            case HAS_NO_SAVED_GAME:
            default:
                FillWindowPixelBuffer(0, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(1, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(0, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C70);
                AddTextPrinterParameterized3(1, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C87);
                PutWindowTilemap(0);
                PutWindowTilemap(1);
                CopyWindowToVram(0, COPYWIN_GFX);
                CopyWindowToVram(1, COPYWIN_GFX);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[0], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[1], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_SAVED_GAME:
                FillWindowPixelBuffer(2, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(3, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(4, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C7C);
                AddTextPrinterParameterized3(3, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C70);
                AddTextPrinterParameterized3(4, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C87);
                MainMenu_FormatSavegameText();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                CopyWindowToVram(2, COPYWIN_GFX);
                CopyWindowToVram(3, COPYWIN_GFX);
                CopyWindowToVram(4, COPYWIN_GFX);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_MYSTERY_GIFT:
                FillWindowPixelBuffer(2, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(3, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(4, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(5, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C7C);
                AddTextPrinterParameterized3(3, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C70);
                if (tWirelessAdapterConnected)
                    AddTextPrinterParameterized3(4, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C91);
                else if (IsMysteryEventEnabled())
                    AddTextPrinterParameterized3(4, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8CA7);
                else
                    AddTextPrinterParameterized3(4, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C9C);
                AddTextPrinterParameterized3(5, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C87);
                MainMenu_FormatSavegameText();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                CopyWindowToVram(2, COPYWIN_GFX);
                CopyWindowToVram(3, COPYWIN_GFX);
                CopyWindowToVram(4, COPYWIN_GFX);
                CopyWindowToVram(5, COPYWIN_GFX);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[5], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_MYSTERY_EVENTS:
                FillWindowPixelBuffer(2, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(3, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(4, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(5, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(6, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C7C);
                AddTextPrinterParameterized3(3, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C70);
                AddTextPrinterParameterized3(4, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C9C);
                AddTextPrinterParameterized3(5, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8CA7);
                AddTextPrinterParameterized3(6, FONT_NORMAL, 0, 2, &sTextColor_Headers, -1, gUnknown_85C8C87);
                MainMenu_FormatSavegameText();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                PutWindowTilemap(6);
                CopyWindowToVram(2, COPYWIN_GFX);
                CopyWindowToVram(3, COPYWIN_GFX);
                CopyWindowToVram(4, COPYWIN_GFX);
                CopyWindowToVram(5, COPYWIN_GFX);
                CopyWindowToVram(6, COPYWIN_GFX);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[5], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[6], MAIN_MENU_BORDER_TILE);
                tScrollArrowTaskId = AddScrollIndicatorArrowPair(&sScrollArrowsTemplate_MainMenu, &sCurrItemAndOptionMenuCheck);
                gTasks[tScrollArrowTaskId].func = Task_ScrollIndicatorArrowPairOnMainMenu;
                if (sCurrItemAndOptionMenuCheck == 4)
                {
                    ChangeBgY(0, 0x2000, BG_COORD_ADD);
                    ChangeBgY(1, 0x2000, BG_COORD_ADD);
                    tIsScrolled = TRUE;
                    gTasks[tScrollArrowTaskId].tArrowTaskIsScrolled = TRUE;
                }
                break;
        }
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
    }
}

static void Task_HighlightSelectedMainMenuItem(u8 taskId)
{
    HighlightSelectedMainMenuItem(gTasks[taskId].tMenuType, gTasks[taskId].tCurrItem, gTasks[taskId].tIsScrolled);
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

static bool8 HandleMainMenuInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        IsWirelessAdapterConnected();   // why bother calling this here? debug? Task_HandleMainMenuAPressed will check too
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_HandleMainMenuAPressed;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
        gTasks[taskId].func = Task_HandleMainMenuBPressed;
    }
    else if ((JOY_NEW(DPAD_UP)) && tCurrItem > 0)
    {
        if (tMenuType == HAS_MYSTERY_EVENTS && tIsScrolled == TRUE && tCurrItem == 1)
        {
            ChangeBgY(0, 0x2000, BG_COORD_SUB);
            ChangeBgY(1, 0x2000, BG_COORD_SUB);
            gTasks[tScrollArrowTaskId].tArrowTaskIsScrolled = tIsScrolled = FALSE;
        }
        tCurrItem--;
        sCurrItemAndOptionMenuCheck = tCurrItem;
        return TRUE;
    }
    else if ((JOY_NEW(DPAD_DOWN)) && tCurrItem < tItemCount - 1)
    {
        if (tMenuType == HAS_MYSTERY_EVENTS && tCurrItem == 3 && tIsScrolled == FALSE)
        {
            ChangeBgY(0, 0x2000, BG_COORD_ADD);
            ChangeBgY(1, 0x2000, BG_COORD_ADD);
            gTasks[tScrollArrowTaskId].tArrowTaskIsScrolled = tIsScrolled = TRUE;
        }
        tCurrItem++;
        sCurrItemAndOptionMenuCheck = tCurrItem;
        return TRUE;
    }
    return FALSE;
}

static void Task_HandleMainMenuInput(u8 taskId)
{
    if (HandleMainMenuInput(taskId))
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
}

static void Task_HandleMainMenuAPressed(u8 taskId)
{
    bool8 wirelessAdapterConnected;
    u8 action;

    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tMenuType == HAS_MYSTERY_EVENTS)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollArrowTaskId);
        ClearStdWindowAndFrame(0, TRUE);
        ClearStdWindowAndFrame(1, TRUE);
        ClearStdWindowAndFrame(2, TRUE);
        ClearStdWindowAndFrame(3, TRUE);
        ClearStdWindowAndFrame(4, TRUE);
        ClearStdWindowAndFrame(5, TRUE);
        ClearStdWindowAndFrame(6, TRUE);
        ClearStdWindowAndFrame(7, TRUE);
        wirelessAdapterConnected = IsWirelessAdapterConnected();
        switch (gTasks[taskId].tMenuType)
        {
            case HAS_NO_SAVED_GAME:
            default:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_NEW_GAME;
                        break;
                    case 1:
                        action = ACTION_OPTION;
                        break;
                }
                break;
            case HAS_SAVED_GAME:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_CONTINUE;
                        break;
                    case 1:
                        action = ACTION_NEW_GAME;
                        break;
                    case 2:
                        action = ACTION_OPTION;
                        break;
                }
                break;
            case HAS_MYSTERY_GIFT:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_CONTINUE;
                        break;
                    case 1:
                        action = ACTION_NEW_GAME;
                        break;
                    case 2:
                        if (IsMysteryGiftEnabled())
                        {
                            if (gTasks[taskId].data[15])
                            {
                                action = ACTION_MYSTERY_GIFT;
                                if (!wirelessAdapterConnected)
                                {
                                    action = ACTION_INVALID;
                                    gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                                }
                            }
                            else if (wirelessAdapterConnected)
                            {
                                action = ACTION_INVALID;
                                gTasks[taskId].tMenuType = HAS_SAVED_GAME;
                            }
                            else
                            {
                                action = ACTION_EREADER;
                            }
                        }
                        else if (wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_MYSTERY_GIFT;
                        }
                        else
                        {
                            action = ACTION_MYSTERY_EVENTS;
                        }
                        break;
                    case 3:
                        action = ACTION_OPTION;
                        break;
                }
                break;
            case HAS_MYSTERY_EVENTS:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_CONTINUE;
                        break;
                    case 1:
                        action = ACTION_NEW_GAME;
                        break;
                    case 2:
                        if (gTasks[taskId].data[15])
                        {
                            action = ACTION_MYSTERY_GIFT;
                            if (!wirelessAdapterConnected)
                            {
                                action = ACTION_INVALID;
                                gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                            }
                        }
                        else if (wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_SAVED_GAME;
                        }
                        else
                        {
                            action = ACTION_EREADER;
                        }
                        break;
                    case 3:
                        if (wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_MYSTERY_GIFT;
                        }
                        else
                        {
                            action = ACTION_MYSTERY_EVENTS;
                        }
                        break;
                    case 4:
                        action = ACTION_OPTION;
                        break;
                }
                break;
        }
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        switch (action)
        {
            case ACTION_NEW_GAME:
            default:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                gTasks[taskId].func = Task_NewGameBirchSpeech_Init;
                break;
            case ACTION_CONTINUE:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                SetMainCallback2(CB2_ContinueSavedGame);
                DestroyTask(taskId);
                break;
            case ACTION_OPTION:
                gMain.savedCallback = CB2_ReinitMainMenu;
                SetMainCallback2(CB2_InitOptionMenu);
                DestroyTask(taskId);
                break;
            case ACTION_MYSTERY_GIFT:
                SetMainCallback2(CB2_InitMysteryGift);
                DestroyTask(taskId);
                break;
            case ACTION_MYSTERY_EVENTS:
                SetMainCallback2(CB2_InitMysteryEventMenu);
                DestroyTask(taskId);
                break;
            case ACTION_EREADER:
                SetMainCallback2(CB2_InitEReader);
                DestroyTask(taskId);
                break;
            case ACTION_INVALID:
                gTasks[taskId].tCurrItem = 0;
                gTasks[taskId].func = Task_DisplayMainMenuInvalidActionError;
                gPlttBufferUnfaded[BG_PLTT_ID(15) + 1] = RGB_WHITE;
                gPlttBufferFaded[BG_PLTT_ID(15) + 1] = RGB_WHITE;
                SetGpuReg(REG_OFFSET_BG2HOFS, 0);
                SetGpuReg(REG_OFFSET_BG2VOFS, 0);
                SetGpuReg(REG_OFFSET_BG1HOFS, 0);
                SetGpuReg(REG_OFFSET_BG1VOFS, 0);
                SetGpuReg(REG_OFFSET_BG0HOFS, 0);
                SetGpuReg(REG_OFFSET_BG0VOFS, 0);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
                return;
        }
        FreeAllWindowBuffers();
        if (action != ACTION_OPTION)
            sCurrItemAndOptionMenuCheck = 0;
        else
            sCurrItemAndOptionMenuCheck |= OPTION_MENU_FLAG;  // entering the options menu
    }
}

static void Task_HandleMainMenuBPressed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tMenuType == HAS_MYSTERY_EVENTS)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollArrowTaskId);
        sCurrItemAndOptionMenuCheck = 0;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitTitleScreen);
        DestroyTask(taskId);
    }
}

static void Task_DisplayMainMenuInvalidActionError(u8 taskId)
{
    switch (gTasks[taskId].tCurrItem)
    {
        case 0:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
            switch (gTasks[taskId].tMenuType)
            {
                case 0:
                    CreateMainMenuErrorWindow(gUnknown_85C8CB1);
                    break;
                case 1:
                    CreateMainMenuErrorWindow(gUnknown_85C8CC7);
                    break;
                case 2:
                    CreateMainMenuErrorWindow(gUnknown_85C8CEB);
                    break;
            }
            gTasks[taskId].tCurrItem++;
            break;
        case 1:
            if (!gPaletteFade.active)
                gTasks[taskId].tCurrItem++;
            break;
        case 2:
            RunTextPrinters();
            if (!IsTextPrinterActive(7))
                gTasks[taskId].tCurrItem++;
            break;
        case 3:
            if (JOY_NEW(A_BUTTON | B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_HandleMainMenuBPressed;
            }
    }
}

static void HighlightSelectedMainMenuItem(u8 menuType, u8 selectedMenuItem, s16 isScrolled)
{
    SetGpuReg(REG_OFFSET_WIN0H, 0x9E7);

    switch (menuType)
    {
        case HAS_NO_SAVED_GAME:
        default:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x11F);
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x213F);
                    break;
            }
            break;
        case HAS_SAVED_GAME:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x13F);
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    break;
            }
            break;
        case HAS_MYSTERY_GIFT:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x13F);
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    break;
                case 3:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x819F);
                    break;
            }
            break;
        case HAS_MYSTERY_EVENTS:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x13F);
                    break;
                case 1:
                    if (isScrolled)
                        SetGpuReg(REG_OFFSET_WIN0V, 0x213F);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    break;
                case 2:
                    if (isScrolled)
                        SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    break;
                case 3:
                    if (isScrolled)
                        SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, 0x819F);
                    break;
                case 4:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x819F);
                    break;
            }
            break;
    }
}

static void Task_NewGameBirchSpeech_Init(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgFromTemplate(&sBirchBgTemplate);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    LZ77UnCompVram(sBirchSpeechShadowGfx, (void *)VRAM);
    LZ77UnCompVram(sBirchSpeechBgMap, (void *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sBirchSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sBirchSpeechBgGradientPal[8], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddBirchSpeechObjects(taskId);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gTasks[taskId].tBG1HOFS = 0;
    gTasks[taskId].func = Task_NewGameBirchSpeech_WaitToShowBirch;
    gTasks[taskId].tPlayerSpriteId = SPRITE_NONE;
    gTasks[taskId].data[3] = 0xFF;
    gTasks[taskId].tTimer = 0xD8;
    PlayBGM(MUS_ROUTE122);
    ShowBg(0);
    ShowBg(1);
}

static void Task_NewGameBirchSpeech_WaitToShowBirch(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        spriteId = gTasks[taskId].tBirchSpriteId;
        gSprites[spriteId].x = 136;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 10);
        NewGameBirchSpeech_StartFadePlatformOut(taskId, 20);
        gTasks[taskId].tTimer = 80;
        gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome;
    }
}

static void Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            InitWindows(sNewGameBirchSpeechTextWindows);
            LoadMainMenuWindowFrameTiles(0, 0xDB);
            LoadMessageBoxGfx(0, 0xE4, BG_PLTT_ID(15));
            NewGameBirchSpeech_ShowDialogueWindow(0, 1);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_GFX);
            NewGameBirchSpeech_ClearWindow(0);
            StringExpandPlaceholders(gStringVar4, gUnknown_8277095);
            AddTextPrinterForMessage(TRUE);
            gTasks[taskId].func = Task_NewGameBirchSpeech_ThisIsAPokemon;
        }
    }
}

static void Task_NewGameBirchSpeech_ThisIsAPokemon(u8 taskId)
{
    if (!gPaletteFade.active && !RunTextPrintersAndIsPrinter0Active())
    {
        gTasks[taskId].func = Task_NewGameBirchSpeech_MainSpeech;
        StringExpandPlaceholders(gStringVar4, gUnknown_85C8F88);
        AddTextPrinterWithCallbackForMessage(TRUE, NewGameBirchSpeech_ShowPokeBallPrinterCallback);
        sBirchSpeechMainTaskId = taskId;
    }
}

static void Task_NewGameBirchSpeech_MainSpeech(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StringExpandPlaceholders(gStringVar4, gUnknown_8277102);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_AndYouAre;
    }
}

static void Task_NewGameBirchSpeechSub_InitPokeBall(u8 taskId)
{
    u8 spriteId = gTasks[sBirchSpeechMainTaskId].tLotadSpriteId;

    gSprites[spriteId].x = 100;
    gSprites[spriteId].y = 75;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].data[0] = 0;

    CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 112, 58, 0, 0, 32, PALETTES_BG, SPECIES_LOTAD);
    gTasks[taskId].func = Task_NewGameBirchSpeechSub_WaitForLotad;
    gTasks[sBirchSpeechMainTaskId].tTimer = 0;
}

static void Task_NewGameBirchSpeechSub_WaitForLotad(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Sprite *sprite = &gSprites[gTasks[sBirchSpeechMainTaskId].tLotadSpriteId];

    switch (tState)
    {
        case 0:
            if (sprite->callback != SpriteCallbackDummy)
                return;
            sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
            break;
        case 1:
            if (gTasks[sBirchSpeechMainTaskId].tTimer >= 96)
            {
                DestroyTask(taskId);
                if (gTasks[sBirchSpeechMainTaskId].tTimer < 0x4000)
                    gTasks[sBirchSpeechMainTaskId].tTimer++;
            }
            return;
    }
    tState++;
    if (gTasks[sBirchSpeechMainTaskId].tTimer < 0x4000)
        gTasks[sBirchSpeechMainTaskId].tTimer++;
}

static void Task_NewGameBirchSpeech_AndYouAre(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        sStartedPokeBallTask = FALSE;
        StringExpandPlaceholders(gStringVar4, gUnknown_82771F4);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_StartBirchLotadPlatformFade;
    }
}

static void Task_NewGameBirchSpeech_StartBirchLotadPlatformFade(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[gTasks[taskId].tLotadSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
        NewGameBirchSpeech_StartFadePlatformIn(taskId, 1);
        gTasks[taskId].tTimer = 64;
        gTasks[taskId].func = Task_NewGameBirchSpeech_SlidePlatformAway;
    }
}

static void Task_NewGameBirchSpeech_SlidePlatformAway(u8 taskId)
{
    if (gTasks[taskId].tBG1HOFS != -60)
    {
        gTasks[taskId].tBG1HOFS -= 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBG1HOFS);
    }
    else
    {
        gTasks[taskId].tBG1HOFS = -60;
        gTasks[taskId].func = Task_NewGameBirchSpeech_StartPlayerFadeIn;
    }
}

static void Task_NewGameBirchSpeech_StartPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tLotadSpriteId].invisible = TRUE;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            u8 spriteId = gTasks[taskId].tBrendanSpriteId;

            gSprites[spriteId].x = 180;
            gSprites[spriteId].y = 60;
            gSprites[spriteId].invisible = FALSE;
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gTasks[taskId].tPlayerSpriteId = spriteId;
            gTasks[taskId].tPlayerGender = MALE;
            NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
            NewGameBirchSpeech_StartFadePlatformOut(taskId, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForPlayerFadeIn;
        }
    }
}

static void Task_NewGameBirchSpeech_WaitForPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gTasks[taskId].func = Task_NewGameBirchSpeech_BoyOrGirl;
    }
}

static void Task_NewGameBirchSpeech_BoyOrGirl(u8 taskId)
{
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gUnknown_8277200);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameBirchSpeech_WaitToShowGenderMenu;
}

static void Task_NewGameBirchSpeech_WaitToShowGenderMenu(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        NewGameBirchSpeech_ShowGenderMenu();
        gTasks[taskId].func = Task_NewGameBirchSpeech_ChooseGender;
    }
}

static void Task_NewGameBirchSpeech_ChooseGender(u8 taskId)
{
    int gender = NewGameBirchSpeech_ProcessGenderMenuInput();
    int gender2;

    switch (gender)
    {
        case MALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            NewGameBirchSpeech_ClearGenderWindow(1, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WhatsYourName;
            break;
        case FEMALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            NewGameBirchSpeech_ClearGenderWindow(1, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WhatsYourName;
            break;
    }
    gender2 = Menu_GetCursorPos();
    if (gender2 != gTasks[taskId].tPlayerGender)
    {
        gTasks[taskId].tPlayerGender = gender2;
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 0);
        gTasks[taskId].func = Task_NewGameBirchSpeech_SlideOutOldGenderSprite;
    }
}

static void Task_NewGameBirchSpeech_SlideOutOldGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;
    if (gTasks[taskId].tIsDoneFadingSprites == 0)
    {
        gSprites[spriteId].x += 4;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].tPlayerGender != MALE)
            spriteId = gTasks[taskId].tMaySpriteId;
        else
            spriteId = gTasks[taskId].tBrendanSpriteId;
        gSprites[spriteId].x = DISPLAY_WIDTH;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 0);
        gTasks[taskId].func = Task_NewGameBirchSpeech_SlideInNewGenderSprite;
    }
}

static void Task_NewGameBirchSpeech_SlideInNewGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].x > 180)
    {
        gSprites[spriteId].x -= 4;
    }
    else
    {
        gSprites[spriteId].x = 180;
        if (gTasks[taskId].tIsDoneFadingSprites)
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
            gTasks[taskId].func = Task_NewGameBirchSpeech_ChooseGender;
        }
    }
}

#undef tMenuType
#undef tCurrItem
#undef tItemCount
#undef tScrollArrowTaskId
#undef tIsScrolled
#undef tWirelessAdapterConnected
#undef tArrowTaskIsScrolled
