#include "constants/rgb.h"

#define UNUSED_POKENAV_MENU_DATA __attribute__((section(".rodata.unused_pokenav_menu_data"), aligned(4)))

const u16 gUnusedPokenavMenu_Pal[16] UNUSED_POKENAV_MENU_DATA =
{
    RGB(0, 12, 0), RGB(29, 31, 29), RGB(2, 28, 21), RGB(1, 31, 30),
    RGB(23, 18, 0), RGB(24, 24, 25), RGB(9, 31, 25), RGB(4, 26, 13),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(31, 31, 31), RGB(18, 18, 18) | RGB_ALPHA,
};

const u32 gUnusedPokenavMenu_Gfx[] UNUSED_POKENAV_MENU_DATA = INCGFX_U32("graphics/pokenav/unused/menu.png", ".4bpp.lz", "-num_tiles 127");

const u32 gUnusedPokenavMenu_Tilemap[] UNUSED_POKENAV_MENU_DATA = INCGFX_U32("graphics/pokenav/unused/menu.bin", ".lz");

const u16 gUnusedPokenavMenuBlankPrompt_Tilemap[2][17] UNUSED_POKENAV_MENU_DATA =
{
    {0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E},
    {0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},
};

const u16 gUnusedPokenavMenuHints_Tilemaps[8][2][12] UNUSED_POKENAV_MENU_DATA =
{
    {
        {0x101C, 0x101D, 0x103C, 0x103D, 0x103E, 0x103F, 0x1040, 0x1041, 0x103D, 0x1042, 0x1043, 0x1044},
        {0x102C, 0x102D, 0x104D, 0x104E, 0x104F, 0x1050, 0x1051, 0x1052, 0x104E, 0x1053, 0x1054, 0x1055},
    },
    {
        {0x101C, 0x101D, 0x105E, 0x105F, 0x103D, 0x1042, 0x1043, 0x1044, 0x101E, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x1063, 0x1064, 0x104E, 0x1053, 0x1054, 0x1055, 0x1000, 0x1000, 0x1000, 0x1000},
    },
    {
        {0x101C, 0x101D, 0x105E, 0x105F, 0x103D, 0x1042, 0x1049, 0x106B, 0x104B, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x1063, 0x1064, 0x104E, 0x1053, 0x105A, 0x105B, 0x105C, 0x1000, 0x1000, 0x1000},
    },
    {
        {0x101C, 0x101D, 0x1068, 0x1041, 0x1069, 0x103D, 0x106A, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x106C, 0x106D, 0x106E, 0x104E, 0x106F, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},
    },
    {
        {0x101C, 0x101D, 0x1068, 0x1041, 0x1070, 0x1042, 0x1071, 0x1072, 0x1073, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x106C, 0x106D, 0x106F, 0x1053, 0x1078, 0x1079, 0x107A, 0x1000, 0x1000, 0x1000},
    },
    {
        {0x101C, 0x101D, 0x1045, 0x1046, 0x1047, 0x1048, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x1056, 0x1057, 0x1058, 0x1059, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},
    },
    {
        {0x101C, 0x101D, 0x1060, 0x1061, 0x1062, 0x1048, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x1065, 0x1066, 0x1067, 0x1059, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},
    },
    {
        {0x101C, 0x101D, 0x1049, 0x104A, 0x104B, 0x104C, 0x1048, 0x101E, 0x101E, 0x101E, 0x101E, 0x101E},
        {0x102C, 0x102D, 0x105A, 0x105B, 0x105C, 0x105D, 0x1059, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},
    },
};

const u16 gUnusedPokenavMenuBackPrompt_Tilemap[2][5] UNUSED_POKENAV_MENU_DATA =
{
    {0x101F, 0x101D, 0x1074, 0x1075, 0x1044},
    {0x102E, 0x102F, 0x107B, 0x107C, 0x1055},
};

const u16 gUnusedPokenavMenuCancelPrompt_Tilemap[2][5] UNUSED_POKENAV_MENU_DATA =
{
    {0x101F, 0x101D, 0x1076, 0x1077, 0x1044},
    {0x102E, 0x102F, 0x107D, 0x107E, 0x1055},
};

const u16 gUnusedPokenavToolbar_Pal[16] UNUSED_POKENAV_MENU_DATA =
{
    RGB(12, 0, 0), RGB(0, 0, 0), RGB(13, 12, 10), RGB(24, 26, 23),
    RGB(7, 8, 9), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(24, 24, 24), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(28, 30, 31),
};

const u16 gUnusedPokenavToolbar_Gfx[] UNUSED_POKENAV_MENU_DATA = INCGFX_U16("graphics/pokenav/unused/toolbar.png", ".4bpp");

const u32 gUnusedPokenavToolbar_Tilemap[] UNUSED_POKENAV_MENU_DATA = INCGFX_U32("graphics/pokenav/unused/toolbar.bin", ".lz");

const u16 gUnusedPokenavBackdrop_Pal[16] UNUSED_POKENAV_MENU_DATA =
{
    RGB(0, 0, 0), RGB(29, 31, 29), RGB(25, 31, 25), RGB(29, 28, 31),
    RGB(26, 24, 31), RGB(31, 27, 26), RGB(31, 23, 22), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
};

const u16 gUnusedPokenavBackdrop_Gfx[] UNUSED_POKENAV_MENU_DATA = INCGFX_U16("graphics/pokenav/unused/backdrop.png", ".4bpp");

const u32 gUnusedPokenavBackdrop_Tilemap[] UNUSED_POKENAV_MENU_DATA = INCGFX_U32("graphics/pokenav/unused/backdrop.bin", ".lz");

#undef UNUSED_POKENAV_MENU_DATA

#define UNUSED_POKENAV_MON_FRAME_PALETTE __attribute__((section(".rodata.unused_pokenav_mon_frame_palette"), aligned(4)))

const u16 gUnusedPokenavMonFrame_Pal[16] UNUSED_POKENAV_MON_FRAME_PALETTE =
{
    RGB(0, 0, 0), RGB(30, 9, 9), RGB(14, 12, 12), RGB(31, 31, 31) | RGB_ALPHA,
    RGB(30, 30, 30), RGB(30, 23, 23), RGB(30, 26, 26) | RGB_ALPHA, RGB(17, 15, 15) | RGB_ALPHA,
    RGB(23, 22, 22), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
};

#undef UNUSED_POKENAV_MON_FRAME_PALETTE

#define UNUSED_POKENAV_CONDITION_FRAME __attribute__((section(".rodata.unused_pokenav_condition_frame"), aligned(4)))

const u16 gUnusedPokenavConditionFrame_Tilemap[4][9] UNUSED_POKENAV_CONDITION_FRAME =
{
    {0x22F5, 0x22F6, 0x22F6, 0x22F6, 0x22F6, 0x22F6, 0x22F6, 0x22F6, 0x26F5},
    {0x22F9, 0x2285, 0x2285, 0x2285, 0x2285, 0x2285, 0x2285, 0x2285, 0x22FA},
    {0x22F9, 0x2285, 0x2285, 0x2285, 0x2285, 0x2285, 0x2285, 0x2285, 0x22FA},
    {0x22FB, 0x22FC, 0x22FC, 0x22FC, 0x22FC, 0x22FC, 0x22FC, 0x22FC, 0x26FB},
};

#undef UNUSED_POKENAV_CONDITION_FRAME

#define UNUSED_POKENAV_GRAPH_PALETTE __attribute__((section(".rodata.unused_pokenav_graph_palette"), aligned(4)))

const u16 gUnusedPokenavGraph_Pal[16] UNUSED_POKENAV_GRAPH_PALETTE =
{
    RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0),
    RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0),
    RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0),
    RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0), RGB(0, 31, 0),
};

#undef UNUSED_POKENAV_GRAPH_PALETTE

#define UNUSED_POKENAV_OUTLINE_GRAPHICS __attribute__((section(".rodata.unused_pokenav_outline_graphics"), aligned(4)))

const u16 gUnusedPokenavOutline_Pal[16] UNUSED_POKENAV_OUTLINE_GRAPHICS =
{
    RGB(31, 31, 31), RGB(25, 25, 26), RGB(21, 21, 23), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
    RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 0),
};

const u32 gUnusedPokenavOutline_Gfx[] UNUSED_POKENAV_OUTLINE_GRAPHICS = INCGFX_U32("graphics/pokenav/unused/outline.png", ".4bpp.lz", "-num_tiles 43");

const u32 gUnusedPokenavOutline_Tilemap[] UNUSED_POKENAV_OUTLINE_GRAPHICS = INCGFX_U32("graphics/pokenav/unused/outline.bin", ".lz");

#undef UNUSED_POKENAV_OUTLINE_GRAPHICS

#define UNUSED_POKENAV_INTERFACE_DATA(symbol) __attribute__((section(".rodata.pokenav_interface." #symbol)))

// JP retains an unreferenced second copy of the Match Call light tiles.
UNUSED_POKENAV_INTERFACE_DATA(gUnusedPokenavBlueLight_Gfx) const u32 gUnusedPokenavBlueLight_Gfx[] = INCGFX_U32("graphics/pokenav/blue_light.png", ".4bpp.lz");

#undef UNUSED_POKENAV_INTERFACE_DATA
