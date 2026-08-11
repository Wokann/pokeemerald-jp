#include "global.h"
#include "reset_rtc_screen.h"
#include "event_data.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "rtc.h"
#include "save.h"
#include "sprite.h"
#include "constants/songs.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "scanline_effect.h"
#include "bg.h"
#include "window.h"
#include "gpu_regs.h"
#include "constants/rgb.h"

#define PALTAG_ARROW 0x1000

// Task data for the Task_ResetRtc_* series of tasks, when setting the time on the clock
// Data from these tasks is also used by the cursors and the main task (Task_ResetRtcScreen)
enum {
    DATAIDX_DAYS = 3,
    DATAIDX_HOURS,
    DATAIDX_MINS,
    DATAIDX_SECS,
    DATAIDX_CONFIRM,
};
#define tFinished  data[0]
#define tSetTime   data[1]
#define tSelection data[2]
#define tDays      data[DATAIDX_DAYS]
#define tHours     data[DATAIDX_HOURS]
#define tMinutes   data[DATAIDX_MINS]
#define tSeconds   data[DATAIDX_SECS]
#define tConfirm   data[DATAIDX_CONFIRM]
#define tWindowId  data[8]

enum {
    SELECTION_DAYS = 1,
    SELECTION_HOURS,
    SELECTION_MINS,
    SELECTION_SECS,
    SELECTION_CONFIRM,
    SELECTION_NONE
};

enum {
    WIN_TIME,
    WIN_MSG,
};

enum {
    ARROW_DOWN,
    ARROW_UP,
    ARROW_RIGHT,
};

struct ResetRtcInputMap
{
    /*0x0*/ u8 dataIndex;
    /*0x2*/ u16 minVal;
    /*0x4*/ u16 maxVal;
    /*0x6*/ u8 left;
    /*0x7*/ u8 right;
    /*0x8*/ u8 unk; // never read
};

static void CB2_ResetRtcScreen(void);
static void VBlankCB(void);
static void Task_ResetRtcScreen(u8 taskId);
static void InitResetRtcScreenBgAndWindows(void);

// JP data tables live in data/data.s (0x084E8A48..0x084E8B5C); the JP
// BgTemplate is a packed bitfield (4 bytes) unlike the US byte struct.
extern const struct BgTemplate gResetRtcBgTemplates[];
extern const struct WindowTemplate gResetRtcWindowTemplates[];
extern const struct WindowTemplate gResetRtcInputTimeWindow;
// JP indexes sInputMap directly by selection (1..5); ld_script_jp.txt aliases
// sInputMap to the same address as the "にち$"/":$" strings (index 0 unused).
extern const struct ResetRtcInputMap sInputMap[];
extern const u8 gUnknown_84E8A6C[]; // "にち$" (day suffix)
extern const u8 gUnknown_84E8A6F[]; // ":$" (colon separator)
extern const u8 gUnknown_84E8A71[]; // Confirm label
extern const struct SpritePalette gResetRtcArrowPalette;
extern const struct SpriteTemplate gResetRtcArrowSpriteTemplate;

// JP message texts (data/data.s)
extern const u8 gUnknown_85CBECB[]; // Reset RTC confirm / cancel
extern const u8 gUnknown_85CBEE9[]; // Present time
extern const u8 gUnknown_85CBEF9[]; // Previous time
extern const u8 gUnknown_85CBF09[]; // Please reset time
extern const u8 gUnknown_85CBF1C[]; // Clock has been reset
extern const u8 gUnknown_85CBF43[]; // Save completed
extern const u8 gUnknown_85CBF52[]; // Save failed
extern const u8 gUnknown_85CBF69[]; // No save file, can't set time

#define sTaskId data[0]
#define sState  data[1]

static void SpriteCB_Cursor_UpOrRight(struct Sprite *sprite)
{
    int state = gTasks[sprite->sTaskId].tSelection;
    if (state != sprite->sState)
    {
        sprite->sState = state;
        switch (state)
        {
        case SELECTION_DAYS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_UP;
            sprite->animDelayCounter = 0;
            sprite->x = 64;
            sprite->y = 68;
            break;
        case SELECTION_HOURS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_UP;
            sprite->animDelayCounter = 0;
            sprite->x = 96;
            sprite->y = 68;
            break;
        case SELECTION_MINS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_UP;
            sprite->animDelayCounter = 0;
            sprite->x = 120;
            sprite->y = 68;
            break;
        case SELECTION_SECS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_UP;
            sprite->animDelayCounter = 0;
            sprite->x = 144;
            sprite->y = 68;
            break;
        case SELECTION_CONFIRM:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_RIGHT;
            sprite->animDelayCounter = 0;
            sprite->x = 155;
            sprite->y = 80;
            break;
        case SELECTION_NONE:
            DestroySprite(sprite);
            break;
        }
    }
}

static void SpriteCB_Cursor_Down(struct Sprite *sprite)
{
    int state = gTasks[sprite->sTaskId].tSelection;
    if (state != sprite->sState)
    {
        sprite->sState = state;
        switch (state)
        {
        case SELECTION_DAYS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_DOWN;
            sprite->animDelayCounter = 0;
            sprite->x = 64;
            sprite->y = 92;
            break;
        case SELECTION_HOURS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_DOWN;
            sprite->animDelayCounter = 0;
            sprite->x = 96;
            sprite->y = 92;
            break;
        case SELECTION_MINS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_DOWN;
            sprite->animDelayCounter = 0;
            sprite->x = 120;
            sprite->y = 92;
            break;
        case SELECTION_SECS:
            sprite->invisible = FALSE;
            sprite->animNum = ARROW_DOWN;
            sprite->animDelayCounter = 0;
            sprite->x = 144;
            sprite->y = 92;
            break;
        case SELECTION_CONFIRM:
            // The up arrow is used as a right arrow when Confirm is selected
            // Hide the down arrow
            sprite->invisible = TRUE;
            break;
        case SELECTION_NONE:
            DestroySprite(sprite);
            break;
        }
    }
}

static void CreateCursor(u8 taskId)
{
    u32 spriteId;

    LoadSpritePalette(&gResetRtcArrowPalette);

    spriteId = CreateSpriteAtEnd(&gResetRtcArrowSpriteTemplate, 64, 68, 0);
    gSprites[spriteId].callback = SpriteCB_Cursor_UpOrRight;
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sState = -1;

    spriteId = CreateSpriteAtEnd(&gResetRtcArrowSpriteTemplate, 64, 68, 0);
    gSprites[spriteId].callback = SpriteCB_Cursor_Down;
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sState = -1;
}

static void FreeCursorPalette(void)
{
    FreeSpritePaletteByTag(gResetRtcArrowPalette.tag);
}

static void HideChooseTimeWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, FALSE);
    RemoveWindow(windowId);
    ScheduleBgCopyTilemapToVram(0);
}

static void PrintTime(u8 windowId, u8 x, u8 y, u16 days, u8 hours, u8 minutes, u8 seconds)
{
    u8 *dest = gStringVar4;

    // Print days
    ConvertIntToDecimalStringN(gStringVar1, days, STR_CONV_MODE_RIGHT_ALIGN, 4);
    dest = StringCopy(dest, gStringVar1);
    dest = StringCopy(dest, gUnknown_84E8A6C);

    // Print hours
    ConvertIntToDecimalStringN(gStringVar1, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
    dest = StringCopy(dest, gStringVar1);
    dest = StringCopy(dest, gUnknown_84E8A6F);

    // Print minutes
    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    dest = StringCopy(dest, gStringVar1);
    dest = StringCopy(dest, gUnknown_84E8A6F);

    // Print seconds
    ConvertIntToDecimalStringN(gStringVar1, seconds, STR_CONV_MODE_LEADING_ZEROS, 2);
    dest = StringCopy(dest, gStringVar1);

    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, x, y, TEXT_SKIP_DRAW, NULL);
}

static void ShowChooseTimeWindow(u8 windowId, u16 days, u8 hours, u8 minutes, u8 seconds)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x214, 0xE);
    PrintTime(windowId, 0, 2, days, hours, minutes, seconds);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gUnknown_84E8A71, 128, 2, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
}

static bool32 MoveTimeUpDown(s16 *val, int minVal, int maxVal, u16 keys)
{
    if (keys & DPAD_DOWN)
    {
        *val -= 1;
        if (*val < minVal)
            *val = maxVal;
    }
    else if (keys & DPAD_UP)
    {
        *val += 1;
        if (*val > maxVal)
            *val = minVal;
    }
    else if (keys & DPAD_LEFT)
    {
        *val -= 10;
        if (*val < minVal)
            *val = maxVal;
    }
    else if (keys & DPAD_RIGHT)
    {
        *val += 10;
        if (*val > maxVal)
            *val = minVal;
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

static void Task_ResetRtc_SetFinished(u8 taskId)
{
    gTasks[taskId].tFinished = TRUE;
}

static void Task_ResetRtc_Exit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    HideChooseTimeWindow(tWindowId);
    FreeCursorPalette();
    gTasks[taskId].func = Task_ResetRtc_SetFinished;
}

static void Task_ResetRtc_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 selection = tSelection;
    // JP indexes the table directly by selection (index 0 is unused).
    const struct ResetRtcInputMap *selectionInfo = &sInputMap[selection];

    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_ResetRtc_Exit;
        tSetTime = FALSE;
        tSelection = SELECTION_NONE;
        PlaySE(SE_SELECT);
        return;
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selectionInfo->right)
        {
            tSelection = selectionInfo->right;
            PlaySE(SE_SELECT);
            return;
        }
    }

    if (JOY_NEW(DPAD_LEFT))
    {
        if (selectionInfo->left)
        {
            tSelection = selectionInfo->left;
            PlaySE(SE_SELECT);
            return;
        }
    }

    if (selection == SELECTION_CONFIRM)
    {
        if (JOY_NEW(A_BUTTON))
        {
            gLocalTime.days = tDays;
            gLocalTime.hours = tHours;
            gLocalTime.minutes = tMinutes;
            gLocalTime.seconds = tSeconds;
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_ResetRtc_Exit;
            tSetTime = TRUE;
            tSelection = SELECTION_NONE;
        }
    }
    else if (MoveTimeUpDown(&data[selectionInfo->dataIndex], selectionInfo->minVal, selectionInfo->maxVal, JOY_REPEAT(DPAD_UP | DPAD_DOWN)))
    {
        PlaySE(SE_SELECT);
        PrintTime(tWindowId, 0, 2, tDays, tHours, tMinutes, tSeconds);
        CopyWindowToVram(tWindowId, COPYWIN_GFX);
    }
}

static void Task_ResetRtc_Init(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tFinished = FALSE;
    tDays = gLocalTime.days;
    tHours = gLocalTime.hours;
    tMinutes = gLocalTime.minutes;
    tSeconds = gLocalTime.seconds;
    tWindowId = AddWindow(&gResetRtcInputTimeWindow);
    ShowChooseTimeWindow(tWindowId, tDays, tHours, tMinutes, tSeconds);
    CreateCursor(taskId);
    tSelection = SELECTION_HOURS;
    gTasks[taskId].func = Task_ResetRtc_HandleInput;
}

void CB2_InitResetRtcScreen(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetVBlankCallback(NULL);
    DmaClear16(3, PLTT, PLTT_SIZE);
    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    ResetOamRange(0, 128);
    LoadOam();
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    ResetSpriteData();
    ResetTasks();
    ResetPaletteFade();
    InitResetRtcScreenBgAndWindows();
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(CB2_ResetRtcScreen);
    CreateTask(Task_ResetRtcScreen, 80);
}

static void InitResetRtcScreenBgAndWindows(void)
{
    ClearScheduledBgCopiesToVram();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gResetRtcBgTemplates, 1);
    ScheduleBgCopyTilemapToVram(0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    InitWindows(gResetRtcWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void CB2_ResetRtcScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

static void ShowMessage(const u8 *str)
{
    DrawDialogFrameWithCustomTileAndPalette(WIN_MSG, FALSE, 0x200, 0xF);
    AddTextPrinterParameterized(WIN_MSG, FONT_NORMAL, str, 0, 2, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
}

#define tState data[0]

static void Task_ShowResetRtcPrompt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        DrawStdFrameWithCustomTileAndPalette(WIN_TIME, FALSE, 0x214, 0xE);

        AddTextPrinterParameterized(WIN_TIME, FONT_NORMAL, gUnknown_85CBEE9, 0, 2, TEXT_SKIP_DRAW, 0);
        PrintTime(
            WIN_TIME,
            0,
            18,
            gLocalTime.days,
            gLocalTime.hours,
            gLocalTime.minutes,
            gLocalTime.seconds);

        AddTextPrinterParameterized(WIN_TIME, FONT_NORMAL, gUnknown_85CBEF9, 0, 34, TEXT_SKIP_DRAW, 0);
        PrintTime(
            WIN_TIME,
            0,
            50,
            gSaveBlock2Ptr->lastBerryTreeUpdate.days,
            gSaveBlock2Ptr->lastBerryTreeUpdate.hours,
            gSaveBlock2Ptr->lastBerryTreeUpdate.minutes,
            gSaveBlock2Ptr->lastBerryTreeUpdate.seconds);

        ShowMessage(gUnknown_85CBECB);
        CopyWindowToVram(WIN_TIME, COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
        tState++;
    case 1:
        if (JOY_NEW(B_BUTTON))
        {
            // Cancel, exit without resetting RTC
            DestroyTask(taskId);
            DoSoftReset();
        }
        else if (JOY_NEW(A_BUTTON))
        {
            // Confirm
            PlaySE(SE_SELECT);
            DestroyTask(taskId);
        }
        break;
    }
}

#undef tState

// Task states for Task_ResetRtcScreen
enum {
    MAINSTATE_FADE_IN,
    MAINSTATE_CHECK_SAVE,
    MAINSTATE_START_SET_TIME,
    MAINSTATE_WAIT_SET_TIME,
    MAINSTATE_SAVE,
    MAINSTATE_WAIT_EXIT,
    MAINSTATE_EXIT,
};

#define tState data[0]
#define tSubTaskId data[1]

static void Task_ResetRtcScreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case MAINSTATE_FADE_IN:
        BeginNormalPaletteFade(PALETTES_ALL, 1, 0x10, 0, RGB_WHITEALPHA);
        tState = MAINSTATE_CHECK_SAVE;
        break;
    case MAINSTATE_CHECK_SAVE:
        if (!gPaletteFade.active)
        {
            if (gSaveFileStatus == SAVE_STATUS_EMPTY
             || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            {
                ShowMessage(gUnknown_85CBF69);
                tState = MAINSTATE_WAIT_EXIT;
            }
            else
            {
                RtcCalcLocalTime();
                tSubTaskId = CreateTask(Task_ShowResetRtcPrompt, 80);
                tState = MAINSTATE_START_SET_TIME;
            }
        }
        break;
    case MAINSTATE_START_SET_TIME:
        // Wait for A or B press on prompt first
        if (gTasks[tSubTaskId].isActive != TRUE)
        {
            ClearStdWindowAndFrameToTransparent(WIN_TIME, FALSE);
            ShowMessage(gUnknown_85CBF09);
            gLocalTime = gSaveBlock2Ptr->lastBerryTreeUpdate;
            tSubTaskId = CreateTask(Task_ResetRtc_Init, 80);
            tState = MAINSTATE_WAIT_SET_TIME;
        }
        break;
    case MAINSTATE_WAIT_SET_TIME:
        if (gTasks[tSubTaskId].tFinished)
        {
            if (!gTasks[tSubTaskId].tSetTime)
            {
                // Exited without setting time, return to "Please reset time"
                DestroyTask(tSubTaskId);
                tState = MAINSTATE_START_SET_TIME;
            }
            else
            {
                // Time has been chosen, reset rtc and save
                DestroyTask(tSubTaskId);
                RtcReset();
                RtcCalcLocalTimeOffset(
                    gLocalTime.days,
                    gLocalTime.hours,
                    gLocalTime.minutes,
                    gLocalTime.seconds);
                gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
                VarSet(VAR_DAYS, gLocalTime.days);
                DisableResetRTC();
                ShowMessage(gUnknown_85CBF1C);
                tState = MAINSTATE_SAVE;
            }
        }
        break;
    case MAINSTATE_SAVE:
        if (TrySavingData(SAVE_NORMAL) == SAVE_STATUS_OK)
        {
            ShowMessage(gUnknown_85CBF43);
            PlaySE(SE_DING_DONG);
        }
        else
        {
            ShowMessage(gUnknown_85CBF52);
            PlaySE(SE_BOO);
        }
        tState = MAINSTATE_WAIT_EXIT;
        // fallthrough
    case MAINSTATE_WAIT_EXIT:
        if (JOY_NEW(A_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 0x10, RGB_WHITEALPHA);
            tState = MAINSTATE_EXIT;
            // fallthrough
        }
        else
        {
            break;
        }
    case MAINSTATE_EXIT:
        if (!gPaletteFade.active)
        {
            DestroyTask(taskId);
            FreeAllWindowBuffers();
            DoSoftReset();
        }
    }
}

#undef tState
#undef tSubTaskId
