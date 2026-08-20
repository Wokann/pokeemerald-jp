#include "global.h"
#include "main.h"
#include "battle_pyramid.h"
#include "palette.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "string_util.h"
#include "event_data.h"
#include "fieldmap.h"
#include "bg.h"
#include "task.h"
#include "menu.h"
#include "overworld.h"
#include "script.h"
#include "start_menu.h"
#include "map_name_popup.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "constants/weather.h"

extern u8 sPopupTaskId;
extern const u8 *const sBattlePyramid_MapHeaderStrings[];

enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,
};

#define MAP_NAME_POPUP_DATA __attribute__((section(".rodata.map_name_popup_mid57a")))

MAP_NAME_POPUP_DATA static const u8 sMapPopUp_Table[][960] = INCBIN_U8(
    "graphics/map_popup/wood.4bpp",
    "graphics/map_popup/marble.4bpp",
    "graphics/map_popup/stone.4bpp",
    "graphics/map_popup/brick.4bpp",
    "graphics/map_popup/underwater.4bpp",
    "graphics/map_popup/stone2.4bpp");

MAP_NAME_POPUP_DATA static const u8 sMapPopUp_OutlineTable[][960] = INCBIN_U8(
    "graphics/map_popup/wood_outline.4bpp",
    "graphics/map_popup/marble_outline.4bpp",
    "graphics/map_popup/stone_outline.4bpp",
    "graphics/map_popup/brick_outline.4bpp",
    "graphics/map_popup/underwater_outline.4bpp",
    "graphics/map_popup/stone2_outline.4bpp");

MAP_NAME_POPUP_DATA static const u16 sMapPopUp_PaletteTable[][16] = INCBIN_U16(
    "graphics/map_popup/wood.gbapal",
    "graphics/map_popup/marble.gbapal",
    "graphics/map_popup/stone.gbapal",
    "graphics/map_popup/brick.gbapal",
    "graphics/map_popup/underwater.gbapal",
    "graphics/map_popup/stone2.gbapal");

MAP_NAME_POPUP_DATA static const u16 sMapPopUp_Palette_Underwater[16] = INCBIN_U16("graphics/map_popup/underwater_override.gbapal");

// The JP map-section ordering differs from the US table, but the six theme IDs match.
MAP_NAME_POPUP_DATA static const u8 sMapSectionToThemeId[] =
{
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_BRICK, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_UNDERWATER, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_MARBLE, MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_WOOD, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2, MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_STONE, MAPPOPUP_THEME_MARBLE,
};

#undef MAP_NAME_POPUP_DATA

// JP ROM uses different map section indices than the US-derived constants.
#define KANTO_MAPSEC_START_JP 0x57
#define KANTO_MAPSEC_END_JP   0xC4
#define KANTO_MAPSEC_COUNT_JP 0x6D

// JP ROM font 1 (8x16) is used for the map name popup text.  The JP
// enum order matches the ROM for fonts 0-5, so FONT_NORMAL (1) is right;
// the US-derived FONT_NARROW (7) does not exist in the JP ROM font table.

static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

enum {
    STATE_SLIDE_IN,
    STATE_WAIT,
    STATE_SLIDE_OUT,
    STATE_UNUSED,
    STATE_ERASE,
    STATE_END,
    STATE_PRINT,
};

#define POPUP_OFFSCREEN_Y  40
#define POPUP_SLIDE_SPEED  2

#define tState         data[0]
#define tOnscreenTimer data[1]
#define tYOffset       data[2]
#define tIncomingPopUp data[3]
#define tPrintTimer    data[4]

static bool8 UNUSED StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            sPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
            SetGpuReg(REG_OFFSET_BG0VOFS, POPUP_OFFSCREEN_Y);
            gTasks[sPopupTaskId].tState = STATE_PRINT;
            gTasks[sPopupTaskId].tYOffset = POPUP_OFFSCREEN_Y;
        }
        else
        {
            if (gTasks[sPopupTaskId].tState != STATE_SLIDE_OUT)
                gTasks[sPopupTaskId].tState = STATE_SLIDE_OUT;
            gTasks[sPopupTaskId].tIncomingPopUp = TRUE;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_PRINT:
        if (++task->tPrintTimer > 30)
        {
            task->tState = STATE_SLIDE_IN;
            task->tPrintTimer = 0;
            ShowMapNamePopUpWindow();
        }
        break;
    case STATE_SLIDE_IN:
        task->tYOffset -= POPUP_SLIDE_SPEED;
        if (task->tYOffset <= 0 )
        {
            task->tYOffset = 0;
            task->tState = STATE_WAIT;
            gTasks[sPopupTaskId].data[1] = 0;
        }
        break;
    case STATE_WAIT:
        if (++task->tOnscreenTimer > 120)
        {
            task->tOnscreenTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;
    case STATE_SLIDE_OUT:
        task->tYOffset += POPUP_SLIDE_SPEED;
        if (task->tYOffset >= POPUP_OFFSCREEN_Y)
        {
            task->tYOffset = POPUP_OFFSCREEN_Y;
            if (task->tIncomingPopUp)
            {
                task->tState = STATE_PRINT;
                task->tPrintTimer = 0;
                task->tIncomingPopUp = FALSE;
            }
            else
            {
                task->tState = STATE_ERASE;
                return;
            }
        }
        break;
    case STATE_ERASE:
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        task->tState = STATE_END;
        break;
    case STATE_END:
        HideMapNamePopUpWindow();
        return;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->tYOffset);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        RemoveStartMenuWindow();
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(sPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u16 textLength;
    u8 x;

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            StringCopy(&(mapDisplayHeader[3]), sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE]);
        }
        else
        {
            StringCopy(&(mapDisplayHeader[3]), sBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
        }
    }
    else
    {
        GetMapName(&(mapDisplayHeader[3]), gMapHeader.regionMapSectionId, 0);
    }
    AddMapNamePopUpWindow();
    LoadMapNamePopUpWindowBg();
    textLength = StringLength(&(mapDisplayHeader[3]));
    x = (10 - textLength) << 2;
    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    AddTextPrinterParameterized(GetMapNamePopUpWindowId(), FONT_NORMAL, mapDisplayHeader, x, 4, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(GetMapNamePopUpWindowId(), COPYWIN_FULL);
}

#define TILE_TOP_EDGE_START 0x21D
#define TILE_TOP_EDGE_END   0x228
#define TILE_LEFT_EDGE_TOP  0x229
#define TILE_RIGHT_EDGE_TOP 0x22A
#define TILE_LEFT_EDGE_MID  0x22B
#define TILE_RIGHT_EDGE_MID 0x22C
#define TILE_LEFT_EDGE_BOT  0x22D
#define TILE_RIGHT_EDGE_BOT 0x22E
#define TILE_BOT_EDGE_START 0x22F
#define TILE_BOT_EDGE_END   0x23A

static void DrawMapNamePopUpFrame(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    for (i = 0; i < 1 + TILE_TOP_EDGE_END - TILE_TOP_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_TOP_EDGE_START + i, i - 1 + x, y - 1, 1, 1, 14);

    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_TOP,       x - 1,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_TOP, deltaX + x,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_MID,       x - 1, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_MID, deltaX + x, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_BOT,       x - 1, y + 2, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_BOT, deltaX + x, y + 2, 1, 1, 14);

    for (i = 0; i < 1 + TILE_BOT_EDGE_END - TILE_BOT_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_BOT_EDGE_START + i, i - 1 + x, y + deltaY, 1, 1, 14);
}

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popUpThemeId;
    u8 popupWindowId = GetMapNamePopUpWindowId();
    mapsec_u16_t regionMapSectionId = gMapHeader.regionMapSectionId;

    if (regionMapSectionId > KANTO_MAPSEC_START_JP)
    {
        if (regionMapSectionId > KANTO_MAPSEC_END_JP)
            regionMapSectionId -= KANTO_MAPSEC_COUNT_JP;
        else
            regionMapSectionId = 0;
    }
    popUpThemeId = sMapSectionToThemeId[regionMapSectionId];

    LoadBgTiles(GetWindowAttribute(popupWindowId, WINDOW_BG), sMapPopUp_OutlineTable[popUpThemeId], 0x400, 0x21D);
    CallWindowFunction(popupWindowId, DrawMapNamePopUpFrame);
    PutWindowTilemap(popupWindowId);
    if (gMapHeader.weather == WEATHER_UNDERWATER_BUBBLES)
        LoadPalette(&sMapPopUp_Palette_Underwater, BG_PLTT_ID(14), sizeof(sMapPopUp_Palette_Underwater));
    else
        LoadPalette(sMapPopUp_PaletteTable[popUpThemeId], BG_PLTT_ID(14), sizeof(sMapPopUp_PaletteTable[0]));
    BlitBitmapToWindow(popupWindowId, sMapPopUp_Table[popUpThemeId], 0, 0, 80, 24);
}
