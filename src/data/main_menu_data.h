#ifndef POKEEMERALD_JP_MAIN_MENU_DATA_H
#define POKEEMERALD_JP_MAIN_MENU_DATA_H

#include "global.h"
#include "bg.h"
#include "constants/characters.h"
#include "list_menu.h"
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


// 0x82D2910 - new-game birch speech text windows (JP layout differs from US).
extern const struct WindowTemplate sNewGameBirchSpeechTextWindows[];
// 0x82D2930
extern const u16 sMainMenuBgPal[];
// 0x82D2950
extern const u16 sMainMenuTextPal[];
// 0x82D2970
extern const u8 sTextColor_Headers[3];
// 0x82D2973 - JP 5-byte variant of US sTextColor_MenuInfo (2 trailing pad bytes).
extern const u8 sTextColor_Savegame[5];
// 0x82D2978
extern const struct BgTemplate sMainMenuBgTemplates[];
// 0x82D2980
extern const struct BgTemplate sBirchBgTemplate;
// 0x82D2984
extern const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu;

#endif // POKEEMERALD_JP_MAIN_MENU_DATA_H
