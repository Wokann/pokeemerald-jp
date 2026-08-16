#ifndef POKEEMERALD_JP_MAIN_MENU_DATA_H
#define POKEEMERALD_JP_MAIN_MENU_DATA_H

#include "global.h"
#include "window.h"

// Main-menu const data (0x82D2588..)

extern const u16 sBirchSpeechBgPals[][16];


// 0x82D25C8 - birch-speech shadow gfx (LZ, decompresses to 0x600).
extern const u32 sBirchSpeechShadowGfx[];
// 0x82D277C - birch-speech bg tilemap (LZ, decompresses to 0x500).
extern const u8 sBirchSpeechBgMap[]; // 0x12A bytes, not 4-aligned in ROM
// 0x82D28A6
extern const u16 sBirchSpeechBgGradientPal[];
// 0x82D28C6 - 2-byte pad between gradient pal and window templates.
extern const u16 gUnknown_82D28C6;
// 0x82D28C8
extern const struct WindowTemplate sWindowTemplates_MainMenu[];

#endif // POKEEMERALD_JP_MAIN_MENU_DATA_H
