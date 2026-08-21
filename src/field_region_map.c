#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "region_map.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"

enum {
    WIN_MAPSEC_NAME,
    WIN_TITLE,
};

enum {
    TAG_PLAYER_ICON,
    TAG_CURSOR,
};

#define FIELD_REGION_MAP_STATIC_DATA __attribute__((section(".rodata.field_region_map_static_data")))

// The JP handler pointer remains in its original EWRAM location.
extern EWRAM_DATA struct {
    MainCallback callback;
    u32 unused;
    struct RegionMap regionMap;
    u16 state;
} *sFieldRegionMapHandler;

// This is a normal, EOS-terminated UI string with no fixed-size padding.
FIELD_REGION_MAP_STATIC_DATA
const u8 gText_Hoenn[] = _("ホウエンちほう");

FIELD_REGION_MAP_STATIC_DATA static const struct BgTemplate sFieldRegionMapBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 2,
        .baseTile = 0,
    },
};

FIELD_REGION_MAP_STATIC_DATA static const struct WindowTemplate sFieldRegionMapWindowTemplates[] =
{
    [WIN_MAPSEC_NAME] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 17,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 1,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 21,
    },
    DUMMY_WIN_TEMPLATE,
};

static void MCB2_InitRegionMapRegisters(void);
static void VBCB_FieldUpdateRegionMap(void);
static void MCB2_FieldUpdateRegionMap(void);
static void FieldUpdateRegionMap(void);
static void PrintRegionMapSecName(void);

void FieldInitRegionMap(MainCallback callback)
{
    SetVBlankCallback(NULL);
    sFieldRegionMapHandler = Alloc(sizeof(*sFieldRegionMapHandler));
    sFieldRegionMapHandler->state = 0;
    sFieldRegionMapHandler->callback = callback;
    SetMainCallback2(MCB2_InitRegionMapRegisters);
}

static void MCB2_InitRegionMapRegisters(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sFieldRegionMapBgTemplates, ARRAY_COUNT(sFieldRegionMapBgTemplates));
    InitWindows(sFieldRegionMapWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x23, BG_PLTT_ID(13)); // JP variant: tile 0x23
    ClearScheduledBgCopiesToVram();
    SetMainCallback2(MCB2_FieldUpdateRegionMap);
    SetVBlankCallback(VBCB_FieldUpdateRegionMap);
}

static void VBCB_FieldUpdateRegionMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MCB2_FieldUpdateRegionMap(void)
{
    FieldUpdateRegionMap();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    DoScheduledBgTilemapCopiesToVram();
}

static void FieldUpdateRegionMap(void)
{
    switch (sFieldRegionMapHandler->state)
    {
        case 0:
            InitRegionMap(&sFieldRegionMapHandler->regionMap, FALSE);
            CreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
            CreateRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
            sFieldRegionMapHandler->state++;
            break;
        case 1:
            DrawStdFrameWithCustomTileAndPalette(WIN_TITLE, FALSE, 0x23, 0xd); // JP variant: tile 0x23
            AddTextPrinterParameterized(WIN_TITLE, FONT_NORMAL, gText_Hoenn, 0, 2, 0, NULL); // JP variant: x=0, y=2
            ScheduleBgCopyTilemapToVram(0);
            DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 0x23, 0xd); // JP variant: tile 0x23
            PrintRegionMapSecName();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            sFieldRegionMapHandler->state++;
            break;
        case 2:
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(2);
            sFieldRegionMapHandler->state++;
            break;
        case 3:
            if (!gPaletteFade.active)
            {
                sFieldRegionMapHandler->state++;
            }
            break;
        case 4:
            switch (DoRegionMapInputCallback())
            {
                case MAP_INPUT_MOVE_END:
                    PrintRegionMapSecName();
                    break;
                case MAP_INPUT_A_BUTTON:
                case MAP_INPUT_B_BUTTON:
                    sFieldRegionMapHandler->state++;
                    break;
            }
            break;
        case 5:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sFieldRegionMapHandler->state++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                FreeRegionMapIconResources();
                SetMainCallback2(sFieldRegionMapHandler->callback);
                TRY_FREE_AND_SET_NULL(sFieldRegionMapHandler);
                FreeAllWindowBuffers();
            }
            break;
    }
}

static void PrintRegionMapSecName(void)
{
    if (sFieldRegionMapHandler->regionMap.mapSecType != MAPSECTYPE_NONE)
    {
        // JP variant: no FillWindowPixelBuffer before printing the name
        AddTextPrinterParameterized(WIN_MAPSEC_NAME, FONT_NORMAL, sFieldRegionMapHandler->regionMap.mapSecName, 0, 2, 0, NULL); // JP variant: y=2
        ScheduleBgCopyTilemapToVram(WIN_MAPSEC_NAME);
    }
    else
    {
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        CopyWindowToVram(WIN_MAPSEC_NAME, COPYWIN_FULL);
    }
}
