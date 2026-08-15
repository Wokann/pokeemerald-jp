#ifndef POKEEMERALD_JP_BERRY_CRUSH1_H
#define POKEEMERALD_JP_BERRY_CRUSH1_H

#include "global.h"
#include "bg.h"
#include "link.h"
#include "window.h"
#include "constants/characters.h"

// Berry-crush data (0x82C5E74..0x82C5F84)

extern const u8 gUnknown_85CC888[]; // JP text region; the sMessages pointers target it until the text region is converted to C

// 0x82C5E74
const u8 sBitTable[8] =
{
    1 << 0,
    1 << 1,
    1 << 2,
    1 << 3,
    1 << 4,
    1 << 5,
    1 << 6,
    1 << 7
};

// 0x82C5E7C - JP pads the US 5-entry table to 8 bytes.
const u8 sSyncPressBonus[8] =
{
    0, 1, 2, 3, 5, 0, 0, 0
};

// 0x82C5E84
ALIGNED(4) const s8 sIntroOutroVibrationData[5][7] =
{
    {  4,  1,  0, -1,  0,  0,  0 },
    {  4,  2,  0, -1,  0,  0,  0 },
    {  4,  2,  0, -2,  0,  0,  0 },
    {  6,  3,  1, -1, -3, -1,  0 },
    {  6,  4,  1, -2, -4, -2,  0 },
};

// 0x82C5EA8
ALIGNED(4) const u8 sVibrationData[MAX_RFU_PLAYERS][4] =
{
    { 3, 2, 1, 0 },
    { 3, 3, 1, 0 },
    { 3, 3, 2, 0 },
    { 3, 4, 2, 0 },
    { 3, 5, 3, 0 },
};

// 0x82C5EBC - JP berry-crush messages.  The texts still live in the asm text
// region at 0x85CC888 (gUnknown_85CC888 + offset); they will get gText_*
// names when that region is converted to C.
const u8 *const sMessages[] =
{
    gUnknown_85CC888 + 0x18,  // MSG_PICK_BERRY
    gUnknown_85CC888 + 0x3C,  // MSG_WAIT_PICK
    gUnknown_85CC888 + 0x5C,  // MSG_POWDER
    gUnknown_85CC888 + 0x90,  // MSG_SAVING
    gUnknown_85CC888 + 0xBC,  // MSG_PLAY_AGAIN
    gUnknown_85CC888 + 0xD4,  // MSG_NO_BERRIES
    gUnknown_85CC888 + 0xF4,  // MSG_DROPPED
    gUnknown_85CC888 + 0x114, // MSG_TIMES_UP
    gUnknown_85CC888 + 0x134, // MSG_COMM_STANDBY
};

// 0x82C5EE0
const struct BgTemplate sBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 11,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

// sWindowTemplates_Results is an overlapping symbol at 0x82C5EE4
// (sBgTemplates + 4); src/berry_crush.c reaches it as
// sWindowTemplates_PlayerNames - 40 so the compiled address stays
// byte-identical, landing on the results window templates embedded below.

// 0x82C5EF0 - JP rows are 4 bytes (the 4th byte is unused); berry_crush.c
// declares the extern with [][3] stride, matching the ROM code's access.
const u8 sTextColorTable[5][4] =
{
    { TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY,  0 },
    { TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY,  0,                      TEXT_COLOR_LIGHT_GRAY },
    { TEXT_COLOR_RED,         TEXT_COLOR_WHITE,      TEXT_COLOR_BLUE,        TEXT_COLOR_LIGHT_BLUE },
    { TEXT_COLOR_WHITE,       TEXT_COLOR_GREEN,      TEXT_COLOR_LIGHT_GREEN, TEXT_COLOR_WHITE },
    { TEXT_COLOR_RED,         TEXT_COLOR_LIGHT_RED,  0,                      0 },
};

// 0x82C5F04 - unreferenced bytes.
const u8 gUnknown_82C5F04[] =
{
    0x00, 0x03, 0x04, 0x18, 0x0D, 0x0F, 0x01, 0x00
};

// 0x82C5F0C - JP layout: 5 player-name windows, a DUMMY, the 3 results
// windows (STATE_RESULTS_PRESSES/RANDOM/CRUSHING, also reached through the
// overlapping sWindowTemplates_Results symbol) and a closing DUMMY.
const struct WindowTemplate sWindowTemplates_PlayerNames[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 9,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 1005,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 3,
        .width = 9,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 987,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 6,
        .width = 9,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 969,
    },
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 3,
        .width = 9,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 951,
    },
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 6,
        .width = 9,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 933,
    },
    DUMMY_WIN_TEMPLATE,
    {   // sWindowTemplates_Results[STATE_RESULTS_PRESSES]
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 20,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {   // sWindowTemplates_Results[STATE_RESULTS_RANDOM]
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 20,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {   // sWindowTemplates_Results[STATE_RESULTS_CRUSHING]
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 2,
        .width = 22,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE,
};

// 0x82C5F5C
const u8 sResultsWindowHeights[2][MAX_RFU_PLAYERS - 1] =
{
    { 6,  8,  9,  11 },
    { 12, 14, 15, 16 },
};

// 0x82C5F64
const u32 sPressingSpeedConversionTable[] =
{
    50000000,
    25000000,
    12500000,
    6250000,
    3125000,
    1562500,
    781250,
    390625,
};

#endif // POKEEMERALD_JP_BERRY_CRUSH1_H
