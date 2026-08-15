#include "global.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "decompress.h"
#include "data.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "main_menu.h"
#include "save.h"
#include "menu.h"
#include "mystery_event_menu.h"
#include "mystery_gift_menu.h"
#include "naming_screen.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokeball.h"
#include "random.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"

// JP keeps these tables in ROM; US builds them in C.
extern const u16 sMainMenuBgPal[];
extern const u16 sMainMenuTextPal[];
extern const struct BgTemplate sMainMenuBgTemplates[];
extern const struct WindowTemplate sWindowTemplates_MainMenu[];

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
extern const u8 gUnknown_8277213[];
extern const u8 gText_Birch_SoItsPlayer[];
extern const u8 gUnknown_827722D[];
extern const u8 gUnknown_8277265[];
extern const u8 gUnknown_85CCCBD[];
extern const u8 gUnknown_85CCCC7[];
extern const u8 gUnknown_85CCCD4[];
extern const u8 gUnknown_85CCCE1[];
extern const u8 sTextColor_Savegame[];
extern const union AffineAnimCmd *const sSpriteAffineAnimTable_PlayerShrink[];
extern const struct MenuAction sMenuActions_Gender[];
extern const u8 *const sMalePresetNames[];
extern const u8 *const sFemalePresetNames[];
extern void PrintTextArray(u8 windowId, u8 fontId, u8 x, u8 y, u8 lineHeight, u8 itemCount, const struct MenuAction *texts);
extern u8 sub_081984B0(u8 windowId, u8 fontId, u8 x, u8 y, u8 lineHeight, u8 itemCount, u8 initialCursorPos);
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern void Task_DisplayMainMenu(u8 taskId);
void Task_MainMenuCheckSaveFile(u8 taskId);
extern u16 sCurrItemAndOptionMenuCheck;
extern const struct TextColor sTextColor_Headers;
extern const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu;
extern void MainMenu_FormatSavegameText(void);
extern u8 AddScrollIndicatorArrowPair(const struct ScrollArrowsTemplate *template, u16 *ignore);
extern void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId);
extern void Task_HighlightSelectedMainMenuItem(u8 taskId);
extern void Task_NewGameBirchSpeech_Init(u8 taskId);
extern void Task_NewGameBirchSpeech_WaitToShowBirch(u8 taskId);
extern void Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome(u8 taskId);
extern void Task_NewGameBirchSpeech_AndYouAre(u8 taskId);
extern void AddBirchSpeechObjects(u8 taskId);
extern void NewGameBirchSpeech_ShowDialogueWindow(u8 taskId, u8 windowId);
extern void Task_NewGameBirchSpeech_SlidePlatformAway(u8 taskId);
extern void NewGameBirchSpeech_ShowGenderMenu(void);
extern s8 NewGameBirchSpeech_ProcessGenderMenuInput(void);
extern void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId);
extern void CB2_NewGameBirchSpeech_ReturnFromNamingScreen(void);
extern void NewGameBirchSpeech_SetDefaultPlayerName(u8 nameId);
extern void Task_NewGameBirchSpeech_AreYouReady(u8 taskId);
extern void Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox(u8 taskId);
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
static void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId);
static void Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint(u8 taskId);
static void Task_NewGameBirchSpeech_WaitPressBeforeNameChoice(u8 taskId);
static void Task_NewGameBirchSpeech_StartNamingScreen(u8 taskId);
static void Task_NewGameBirchSpeech_SoItsPlayerName(u8 taskId);
static void Task_NewGameBirchSpeech_CreateNameYesNo(u8 taskId);
static void Task_NewGameBirchSpeech_ProcessNameYesNoMenu(u8 taskId);
static void Task_NewGameBirchSpeech_SlidePlatformAway2(u8 taskId);
static void Task_NewGameBirchSpeech_ReshowBirchLotad(u8 taskId);
static void Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter(u8 taskId);
static void Task_NewGameBirchSpeech_AreYouReady(u8 taskId);
static void Task_NewGameBirchSpeech_ShrinkPlayer(u8 taskId);
static void Task_NewGameBirchSpeech_WaitForPlayerShrink(u8 taskId);
static void Task_NewGameBirchSpeech_FadePlayerToWhite(u8 taskId);
static void Task_NewGameBirchSpeech_Cleanup(u8 taskId);
static void CB2_NewGameBirchSpeech_ReturnFromNamingScreen(void);
static void SpriteCB_Null(struct Sprite *sprite);
static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *sprite);
static u8 NewGameBirchSpeech_CreateLotadSprite(u8 x, u8 y);
static void AddBirchSpeechObjects(u8 taskId);
static void NewGameBirchSpeech_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay);
static void NewGameBirchSpeech_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay);
static void NewGameBirchSpeech_StartFadePlatformIn(u8 taskId, u8 delay);
static void NewGameBirchSpeech_StartFadePlatformOut(u8 taskId, u8 delay);
static void NewGameBirchSpeech_ShowGenderMenu(void);
static s8 NewGameBirchSpeech_ProcessGenderMenuInput(void);
static void NewGameBirchSpeech_SetDefaultPlayerName(u8 nameId);
static void MainMenu_FormatSavegameText(void);
static void MainMenu_FormatSavegamePlayer(void);
static void MainMenu_FormatSavegameTime(void);
static void MainMenu_FormatSavegamePokedex(void);
static void MainMenu_FormatSavegameBadges(void);
static void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset);
static void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum);
static void ClearMainMenuWindowTilemap(const struct WindowTemplate *template);
void NewGameBirchSpeech_ClearGenderWindowTilemap(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 unused);
static void NewGameBirchSpeech_ClearWindow(u8 windowId);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
static void NewGameBirchSpeech_ShowDialogueWindow(u8 windowId, u8 copyToVram);
static void Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox(u8 taskId);

#define NUM_PRESET_NAMES 20
#define BIRCH_DLG_BASE_TILE_NUM 0xE4

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
static void NewGameBirchSpeech_WaitForThisIsPokemonText(struct TextPrinterTemplate *printer, u16 renderCmd);
static void NewGameBirchSpeech_ClearGenderWindow(u8 windowId, bool8 copyToVram);
static void NewGameBirchSpeech_CreateDialogueWindowBorder(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palNum);

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
        AddTextPrinterWithCallbackForMessage(TRUE, NewGameBirchSpeech_WaitForThisIsPokemonText);
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

static void NewGameBirchSpeech_WaitForThisIsPokemonText(struct TextPrinterTemplate *printer, u16 renderCmd)
{
    if (*(printer->currentChar - 2) == EXT_CTRL_CODE_PAUSE && !sStartedPokeBallTask)
    {
        sStartedPokeBallTask = TRUE;
        CreateTask(Task_NewGameBirchSpeechSub_InitPokeBall, 0);
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

static void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId)
{
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gUnknown_8277213);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint;
}

static void Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
        gTasks[taskId].func = Task_NewGameBirchSpeech_WaitPressBeforeNameChoice;
}

static void Task_NewGameBirchSpeech_WaitPressBeforeNameChoice(u8 taskId)
{
    if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON)))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_NewGameBirchSpeech_StartNamingScreen;
    }
}

static void Task_NewGameBirchSpeech_StartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tLotadSpriteId);
        NewGameBirchSpeech_SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_NewGameBirchSpeech_ReturnFromNamingScreen);
    }
}

static void Task_NewGameBirchSpeech_SoItsPlayerName(u8 taskId)
{
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_SoItsPlayer);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameBirchSpeech_CreateNameYesNo;
}

static void Task_NewGameBirchSpeech_CreateNameYesNo(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        CreateYesNoMenuParameterized(2, 1, 0xDB, 0xC7, 2, 15);
        gTasks[taskId].func = Task_NewGameBirchSpeech_ProcessNameYesNoMenu;
    }
}

static void Task_NewGameBirchSpeech_ProcessNameYesNoMenu(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            PlaySE(SE_SELECT);
            gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
            NewGameBirchSpeech_StartFadePlatformIn(taskId, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_SlidePlatformAway2;
            break;
        case MENU_B_PRESSED:
        case 1:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_NewGameBirchSpeech_BoyOrGirl;
    }
}

static void Task_NewGameBirchSpeech_SlidePlatformAway2(u8 taskId)
{
    if (gTasks[taskId].tBG1HOFS)
    {
        gTasks[taskId].tBG1HOFS += 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBG1HOFS);
    }
    else
    {
        gTasks[taskId].func = Task_NewGameBirchSpeech_ReshowBirchLotad;
    }
}

static void Task_NewGameBirchSpeech_ReshowBirchLotad(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBrendanSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tMaySpriteId].invisible = TRUE;
        spriteId = gTasks[taskId].tBirchSpriteId;
        gSprites[spriteId].x = 136;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        spriteId = gTasks[taskId].tLotadSpriteId;
        gSprites[spriteId].x = 100;
        gSprites[spriteId].y = 75;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
        NewGameBirchSpeech_StartFadePlatformOut(taskId, 1);
        NewGameBirchSpeech_ClearWindow(0);
        StringExpandPlaceholders(gStringVar4, gUnknown_827722D);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter;
    }
}

static void Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gSprites[gTasks[taskId].tLotadSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gSprites[gTasks[taskId].tLotadSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
            NewGameBirchSpeech_StartFadePlatformIn(taskId, 1);
            gTasks[taskId].tTimer = 64;
            gTasks[taskId].func = Task_NewGameBirchSpeech_AreYouReady;
        }
    }
}

static void Task_NewGameBirchSpeech_AreYouReady(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tLotadSpriteId].invisible = TRUE;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
            return;
        }
        if (gSaveBlock2Ptr->playerGender != MALE)
            spriteId = gTasks[taskId].tMaySpriteId;
        else
            spriteId = gTasks[taskId].tBrendanSpriteId;
        gSprites[spriteId].x = 120;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
        NewGameBirchSpeech_StartFadePlatformOut(taskId, 1);
        StringExpandPlaceholders(gStringVar4, gUnknown_8277265);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_ShrinkPlayer;
    }
}

static void Task_NewGameBirchSpeech_ShrinkPlayer(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            spriteId = gTasks[taskId].tPlayerSpriteId;
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_PlayerShrink;
            InitSpriteAffineAnim(&gSprites[spriteId]);
            StartSpriteAffineAnim(&gSprites[spriteId], 0);
            gSprites[spriteId].callback = SpriteCB_MovePlayerDownWhileShrinking;
            BeginNormalPaletteFade(PALETTES_BG, 0, 0, 16, RGB_BLACK);
            FadeOutBGMTemporarily(4);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForPlayerShrink;
        }
    }
}

static void Task_NewGameBirchSpeech_WaitForPlayerShrink(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].affineAnimEnded)
        gTasks[taskId].func = Task_NewGameBirchSpeech_FadePlayerToWhite;
}

static void Task_NewGameBirchSpeech_FadePlayerToWhite(u8 taskId)
{
    u8 spriteId;

    if (!gPaletteFade.active)
    {
        spriteId = gTasks[taskId].tPlayerSpriteId;
        gSprites[spriteId].callback = SpriteCB_Null;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        BeginNormalPaletteFade(PALETTES_OBJECTS, 0, 0, 16, RGB_WHITEALPHA);
        gTasks[taskId].func = Task_NewGameBirchSpeech_Cleanup;
    }
}

static void Task_NewGameBirchSpeech_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tLotadSpriteId);
        ResetAllPicSprites();
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
    }
}

static void CB2_NewGameBirchSpeech_ReturnFromNamingScreen(void)
{
    u8 taskId;
    u8 spriteId;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, 2);
    InitBgFromTemplate(&sBirchBgTemplate);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    LZ77UnCompVram(sBirchSpeechShadowGfx, (u8 *)VRAM);
    LZ77UnCompVram(sBirchSpeechBgMap, (u8 *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sBirchSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sBirchSpeechBgGradientPal[1], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ResetTasks();
    taskId = CreateTask(Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox, 0);
    gTasks[taskId].tTimer = 5;
    gTasks[taskId].tBG1HOFS = -60;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddBirchSpeechObjects(taskId);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        gTasks[taskId].tPlayerGender = FEMALE;
        spriteId = gTasks[taskId].tMaySpriteId;
    }
    else
    {
        gTasks[taskId].tPlayerGender = MALE;
        spriteId = gTasks[taskId].tBrendanSpriteId;
    }
    gSprites[spriteId].x = 180;
    gSprites[spriteId].y = 60;
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].tPlayerSpriteId = spriteId;
    SetGpuReg(REG_OFFSET_BG1HOFS, -60);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    ShowBg(0);
    ShowBg(1);
    IntrEnable(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    InitWindows(sNewGameBirchSpeechTextWindows);
    LoadMainMenuWindowFrameTiles(0, 0xDB);
    LoadMessageBoxGfx(0, 0xE4, BG_PLTT_ID(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void SpriteCB_Null(struct Sprite *sprite)
{
}

static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *sprite)
{
    u32 y;

    y = (sprite->y << 16) + sprite->data[0] + 0xC000;
    sprite->y = y >> 16;
    sprite->data[0] = y;
}

static u8 NewGameBirchSpeech_CreateLotadSprite(u8 x, u8 y)
{
    return CreateMonPicSprite_Affine(SPECIES_LOTAD, SHINY_ODDS, 0, MON_PIC_AFFINE_FRONT, x, y, 14, TAG_NONE);
}

static void AddBirchSpeechObjects(u8 taskId)
{
    u8 birchSpriteId;
    u8 lotadSpriteId;
    u8 brendanSpriteId;
    u8 maySpriteId;

    birchSpriteId = AddNewGameBirchObject(0x88, 0x3C, 1);
    gSprites[birchSpriteId].callback = SpriteCB_Null;
    gSprites[birchSpriteId].oam.priority = 0;
    gSprites[birchSpriteId].invisible = TRUE;
    gTasks[taskId].tBirchSpriteId = birchSpriteId;
    lotadSpriteId = NewGameBirchSpeech_CreateLotadSprite(100, 0x4B);
    gSprites[lotadSpriteId].callback = SpriteCB_Null;
    gSprites[lotadSpriteId].oam.priority = 0;
    gSprites[lotadSpriteId].invisible = TRUE;
    gTasks[taskId].tLotadSpriteId = lotadSpriteId;
    brendanSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_BRENDAN), 120, 60, 0, &gDecompressionBuffer[0]);
    gSprites[brendanSpriteId].callback = SpriteCB_Null;
    gSprites[brendanSpriteId].invisible = TRUE;
    gSprites[brendanSpriteId].oam.priority = 0;
    gTasks[taskId].tBrendanSpriteId = brendanSpriteId;
    maySpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_MAY), 120, 60, 0, &gDecompressionBuffer[TRAINER_PIC_SIZE]);
    gSprites[maySpriteId].callback = SpriteCB_Null;
    gSprites[maySpriteId].invisible = TRUE;
    gSprites[maySpriteId].oam.priority = 0;
    gTasks[taskId].tMaySpriteId = maySpriteId;
}

#define tMainTask data[0]
#define tAlphaCoeff1 data[1]
#define tAlphaCoeff2 data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_NewGameBirchSpeech_FadeOutTarget1InTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 0)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1--;
        gTasks[taskId].tAlphaCoeff2++;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameBirchSpeech_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadeOutTarget1InTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 16;
    gTasks[taskId2].tAlphaCoeff2 = 0;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameBirchSpeech_FadeInTarget1OutTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 16)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1++;
        gTasks[taskId].tAlphaCoeff2--;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameBirchSpeech_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadeInTarget1OutTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 0;
    gTasks[taskId2].tAlphaCoeff2 = 16;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tAlphaCoeff1
#undef tAlphaCoeff2

#define tPalIndex data[1]
#define tDelayBefore data[2]

static void Task_NewGameBirchSpeech_FadePlatformIn(u8 taskId)
{
    if (gTasks[taskId].tDelayBefore)
    {
        gTasks[taskId].tDelayBefore--;
    }
    else if (gTasks[taskId].tPalIndex == 8)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tPalIndex++;
        LoadPalette(&sBirchSpeechBgGradientPal[gTasks[taskId].tPalIndex], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    }
}

static void NewGameBirchSpeech_StartFadePlatformIn(u8 taskId, u8 delay)
{
    u8 taskId2;

    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadePlatformIn, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tPalIndex = 0;
    gTasks[taskId2].tDelayBefore = 8;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameBirchSpeech_FadePlatformOut(u8 taskId)
{
    if (gTasks[taskId].tDelayBefore)
    {
        gTasks[taskId].tDelayBefore--;
    }
    else if (gTasks[taskId].tPalIndex == 0)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tPalIndex--;
        LoadPalette(&sBirchSpeechBgGradientPal[gTasks[taskId].tPalIndex], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    }
}

static void NewGameBirchSpeech_StartFadePlatformOut(u8 taskId, u8 delay)
{
    u8 taskId2;

    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadePlatformOut, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tPalIndex = 8;
    gTasks[taskId2].tDelayBefore = 8;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void NewGameBirchSpeech_ShowGenderMenu(void)
{
    DrawMainMenuWindowBorder(&sNewGameBirchSpeechTextWindows[1], 0xDB);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    PrintTextArray(1, 1, GetMenuCursorDimensionByFont(1, 0), 2, 0x10, 2, sMenuActions_Gender);
    sub_081984B0(1, 1, 0, 2, 0x10, 2, 0);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_GFX);
}

static s8 NewGameBirchSpeech_ProcessGenderMenuInput(void)
{
    return Menu_ProcessInputNoWrap();
}

static void NewGameBirchSpeech_SetDefaultPlayerName(u8 nameId)
{
    const u8 *name;
    u8 i;

    if (gSaveBlock2Ptr->playerGender == MALE)
        name = sMalePresetNames[nameId];
    else
        name = sFemalePresetNames[nameId];
    for (i = 0; i <= 4; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];
    gSaveBlock2Ptr->playerName[5] = EOS;
}

void CreateMainMenuErrorWindow(const u8 *str)
{
    FillWindowPixelBuffer(7, PIXEL_FILL(1));
    AddTextPrinterParameterized(7, FONT_NORMAL, str, 0, 2, 2, 0);
    PutWindowTilemap(7);
    CopyWindowToVram(7, COPYWIN_GFX);
    DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[7], MAIN_MENU_BORDER_TILE);
    SetGpuReg(REG_OFFSET_WIN0H, 0x9E7);
    SetGpuReg(REG_OFFSET_WIN0V, 0x719F);
}

static void MainMenu_FormatSavegameText(void)
{
    MainMenu_FormatSavegamePlayer();
    MainMenu_FormatSavegamePokedex();
    MainMenu_FormatSavegameTime();
    MainMenu_FormatSavegameBadges();
}

static void MainMenu_FormatSavegamePlayer(void)
{
    StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    StringExpandPlaceholders(gStringVar4, gUnknown_85CCCBD);
    AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 0x11, sTextColor_Savegame, -1, gStringVar4);
}

static void MainMenu_FormatSavegameTime(void)
{
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock2Ptr->playTimeHours, 0, 3);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->playTimeMinutes, 2, 2);
    StringExpandPlaceholders(gStringVar4, gUnknown_85CCCC7);
    AddTextPrinterParameterized3(2, FONT_NORMAL, 0x67, 0x11, sTextColor_Savegame, -1, gStringVar4);
}

static void MainMenu_FormatSavegamePokedex(void)
{
    u16 count;

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        if (IsNationalPokedexEnabled())
            count = GetNationalPokedexCount(1);
        else
            count = GetHoennPokedexCount(1);
        ConvertIntToDecimalStringN(gStringVar1, count, 0, 3);
        StringExpandPlaceholders(gStringVar4, gUnknown_85CCCD4);
        AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 0x21, sTextColor_Savegame, -1, gStringVar4);
    }
}

static void MainMenu_FormatSavegameBadges(void)
{
    u8 badgeCount = 0;
    u32 badge;

    for (badge = FLAG_BADGE01_GET; badge <= FLAG_BADGE08_GET; badge++)
    {
        if (FlagGet(badge))
            badgeCount++;
    }
    ConvertIntToDecimalStringN(gStringVar1, badgeCount, 2, 1);
    StringExpandPlaceholders(gStringVar4, gUnknown_85CCCE1);
    AddTextPrinterParameterized3(2, FONT_NORMAL, 0x6F, 0x21, sTextColor_Savegame, -1, gStringVar4);
}

static void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
}

static void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
{
    u16 r9 = 1 + baseTileNum;
    u16 r10 = 2 + baseTileNum;
    u16 sp18 = 3 + baseTileNum;
    u16 spC = 5 + baseTileNum;
    u16 sp10 = 6 + baseTileNum;
    u16 sp14 = 7 + baseTileNum;
    u16 r6 = 8 + baseTileNum;

    FillBgTilemapBufferRect(template->bg, baseTileNum, template->tilemapLeft - 1, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, r9, template->tilemapLeft, template->tilemapTop - 1, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r10, template->tilemapLeft + template->width, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp18, template->tilemapLeft - 1, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, spC, template->tilemapLeft + template->width, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, sp10, template->tilemapLeft - 1, template->tilemapTop + template->height, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp14, template->tilemapLeft, template->tilemapTop + template->height, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r6, template->tilemapLeft + template->width, template->tilemapTop + template->height, 1, 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

static void ClearMainMenuWindowTilemap(const struct WindowTemplate *template)
{
    FillBgTilemapBufferRect(template->bg, 0, template->tilemapLeft - 1, template->tilemapTop - 1, template->tilemapLeft + template->width + 1, template->tilemapTop + template->height + 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

void NewGameBirchSpeech_ClearGenderWindowTilemap(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 unused)
{
    FillBgTilemapBufferRect(bg, 0, x + 255, y + 255, width + 2, height + 2, 2);
}

static void NewGameBirchSpeech_ClearGenderWindow(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, NewGameBirchSpeech_ClearGenderWindowTilemap);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void NewGameBirchSpeech_ClearWindow(u8 windowId)
{
    u8 bgColor = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    u8 maxCharWidth = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_WIDTH);
    u8 maxCharHeight = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT);
    u8 winWidth = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u8 winHeight = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillWindowPixelRect(windowId, bgColor, 0, 0, maxCharWidth * winWidth, maxCharHeight * winHeight);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, 5, 4, winPalNum, baseBlock);
    CreateYesNoMenuAtPos(&template, 1, 0, 2, baseTileNum, yesNoPalNum, 0);
}

static void NewGameBirchSpeech_ShowDialogueWindow(u8 windowId, u8 copyToVram)
{
    CallWindowFunction(windowId, NewGameBirchSpeech_CreateDialogueWindowBorder);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void NewGameBirchSpeech_CreateDialogueWindowBorder(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palNum)
{
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 1, x - 3, y - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 2, x - 2, y - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 3, x - 1, y - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 4, x, y - 1, width, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 5, x + width, y - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 2, x + width + 1, y - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 6, x + width + 2, y - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 7, x - 3, y, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 13, x - 2, y, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 11, x - 1, y, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 9, x, y, width, 1, palNum);
    {
        u16 tileNum = BG_TILE_H_FLIP(BIRCH_DLG_BASE_TILE_NUM + 11);
        FillBgTilemapBufferRect(bg, tileNum, x + width, y, 1, 1, palNum);
    }
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 13, x + width + 1, y, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 10, x + width + 2, y, 1, 1, palNum);

    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 7, x - 3, y + 1, 1, 2, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 8, x - 2, y + 1, 1, 2, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 9, x - 1, y + 1, width + 2, 2, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 8, x + width + 1, y + 1, 1, 2, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 10, x + width + 2, y + 1, 1, 2, palNum);

    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 7), x - 3, y + height - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 13), x - 2, y + height - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 11), x - 1, y + height - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 9), x, y + height - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_H_FLIP(BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 11)), x + width, y + height - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 13), x + width + 1, y + height - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 10), x + width + 2, y + height - 1, 1, 1, palNum);

    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 1), x - 3, y + height, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 2), x - 2, y + height, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 3), x - 1, y + height, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 4), x, y + height, width, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 5), x + width, y + height, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 2), x + width + 1, y + height, 1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 6), x + width + 2, y + height, 1, 1, palNum);
}

static void Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox(u8 taskId)
{
    if (gTasks[taskId].tTimer-- <= 0)
    {
        NewGameBirchSpeech_ShowDialogueWindow(0, 1);
        gTasks[taskId].func = Task_NewGameBirchSpeech_SoItsPlayerName;
    }
}

#undef tMainTask
#undef tPalIndex
#undef tDelayBefore
#undef tDelay
#undef tDelayTimer

#undef tMenuType
#undef tCurrItem
#undef tItemCount
#undef tScrollArrowTaskId
#undef tIsScrolled
#undef tWirelessAdapterConnected
#undef tArrowTaskIsScrolled

__attribute__((naked)) void Task_MainMenuCheckSaveFile(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r6, r0, #3\n\t"
        "	ldr r0, _0802F5C0\n\t"
        "	mov r8, r0\n\t"
        "	adds r4, r6, r0\n\t"
        "	ldr r0, _0802F5C4\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0802F564\n\t"
        "	b _0802F704\n\t"
        "_0802F564:\n\t"
        "	movs r0, #0x40\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x44\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x48\n\t"
        "	movs r1, #0x11\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x4a\n\t"
        "	movs r1, #0x31\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x50\n\t"
        "	movs r1, #0xc1\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x52\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x54\n\t"
        "	movs r1, #7\n\t"
        "	bl SetGpuReg\n\t"
        "	bl IsWirelessAdapterConnected\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F5AA\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r4, #0x1e]\n\t"
        "_0802F5AA:\n\t"
        "	ldr r0, _0802F5C8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0802F614\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _0802F5CC\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F66C\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0802F5D6\n\t"
        "	b _0802F66C\n\t"
        "	.align 2, 0\n\t"
        "_0802F5C0: .4byte gUnknown_3005B68\n\t"
        "_0802F5C4: .4byte gPaletteFade\n\t"
        "_0802F5C8: .4byte gSaveFileStatus\n\t"
        "_0802F5CC:\n\t"
        "	cmp r0, #4\n\t"
        "	beq _0802F688\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0802F628\n\t"
        "	b _0802F66C\n\t"
        "_0802F5D6:\n\t"
        "	strh r0, [r4]\n\t"
        "	movs r1, #0x1e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0802F5EE\n\t"
        "	bl IsMysteryEventEnabled\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F5EE\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "_0802F5EE:\n\t"
        "	bl IsMysteryGiftEnabled\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F5FC\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "_0802F5FC:\n\t"
        "	ldr r0, _0802F60C\n\t"
        "	lsls r1, r7, #2\n\t"
        "	adds r1, r1, r7\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0802F610\n\t"
        "	str r0, [r1]\n\t"
        "	b _0802F69A\n\t"
        "	.align 2, 0\n\t"
        "_0802F60C: .4byte gTasks\n\t"
        "_0802F610: .4byte 0x0802F76D\n\t"
        "_0802F614:\n\t"
        "	ldr r0, _0802F624\n\t"
        "	bl CreateMainMenuErrorWindow\n\t"
        "	strh r5, [r4]\n\t"
        "	mov r0, r8\n\t"
        "	subs r0, #8\n\t"
        "	adds r0, r6, r0\n\t"
        "	b _0802F696\n\t"
        "	.align 2, 0\n\t"
        "_0802F624: .4byte 0x085C8D6B\n\t"
        "_0802F628:\n\t"
        "	ldr r0, _0802F664\n\t"
        "	bl CreateMainMenuErrorWindow\n\t"
        "	mov r0, r8\n\t"
        "	subs r0, #8\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldr r1, _0802F668\n\t"
        "	str r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "	movs r1, #0x1e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0802F652\n\t"
        "	bl IsMysteryEventEnabled\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0802F652\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "_0802F652:\n\t"
        "	bl IsMysteryGiftEnabled\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0802F69A\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "	b _0802F69A\n\t"
        "	.align 2, 0\n\t"
        "_0802F664: .4byte 0x085C8D44\n\t"
        "_0802F668: .4byte 0x0802F719\n\t"
        "_0802F66C:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4]\n\t"
        "	ldr r1, _0802F680\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0802F684\n\t"
        "	b _0802F698\n\t"
        "	.align 2, 0\n\t"
        "_0802F680: .4byte gTasks\n\t"
        "_0802F684: .4byte 0x0802F76D\n\t"
        "_0802F688:\n\t"
        "	ldr r0, _0802F6BC\n\t"
        "	bl CreateMainMenuErrorWindow\n\t"
        "	mov r0, r8\n\t"
        "	subs r0, #8\n\t"
        "	adds r0, r6, r0\n\t"
        "	strh r5, [r0, #8]\n\t"
        "_0802F696:\n\t"
        "	ldr r1, _0802F6C0\n\t"
        "_0802F698:\n\t"
        "	str r1, [r0]\n\t"
        "_0802F69A:\n\t"
        "	ldr r5, _0802F6C4\n\t"
        "	ldrh r1, [r5]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F6F2\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0802F6D2\n\t"
        "	cmp r0, #2\n\t"
        "	ble _0802F6C8\n\t"
        "	cmp r0, #3\n\t"
        "	beq _0802F6EE\n\t"
        "	b _0802F6F2\n\t"
        "	.align 2, 0\n\t"
        "_0802F6BC: .4byte 0x085C8D80\n\t"
        "_0802F6C0: .4byte 0x0802F719\n\t"
        "_0802F6C4: .4byte sCurrItemAndOptionMenuCheck\n\t"
        "_0802F6C8:\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0802F6F2\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	b _0802F6F0\n\t"
        "_0802F6D2:\n\t"
        "	bl IsMysteryEventEnabled\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0802F6EA\n\t"
        "	movs r1, #0x1e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F6F2\n\t"
        "	bl IsMysteryGiftEnabled\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0802F6F2\n\t"
        "_0802F6EA:\n\t"
        "	movs r0, #3\n\t"
        "	b _0802F6F0\n\t"
        "_0802F6EE:\n\t"
        "	movs r0, #4\n\t"
        "_0802F6F0:\n\t"
        "	strh r0, [r5]\n\t"
        "_0802F6F2:\n\t"
        "	ldr r2, _0802F710\n\t"
        "	ldrh r1, [r2]\n\t"
        "	ldr r0, _0802F714\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #2\n\t"
        "	strh r0, [r4, #0x18]\n\t"
        "_0802F704:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0802F710: .4byte sCurrItemAndOptionMenuCheck\n\t"
        "_0802F714: .4byte 0x00007FFF\n\t"
        ".syntax divided\n\t"
    );
}
