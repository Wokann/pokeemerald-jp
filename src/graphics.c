#include "global.h"

#define SUMMARY_EFFECT_DATA __attribute__((section(".rodata.summary_screen_effect_data")))

SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Battle_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_battle.bin");
SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Contest_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_contest.bin");
SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Cancel_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_cancel.bin");

#define POKENAV_MAIN_GFX __attribute__((section(".rodata.pokenav_main_graphics")))

POKENAV_MAIN_GFX const u16 gPokenavHeader_Pal[] = INCBIN_U16("graphics/pokenav/header.gbapal");
POKENAV_MAIN_GFX const u32 gPokenavHeader_Gfx[] = INCBIN_U32("graphics/pokenav/header.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavHeader_Tilemap[] = INCBIN_U32("graphics/pokenav/header.bin.lz");
POKENAV_MAIN_GFX const u16 sSpinningPokenav_Pal[] = INCBIN_U16("graphics/pokenav/nav_icon.gbapal");
POKENAV_MAIN_GFX const u32 sSpinningPokenav_Gfx[] = INCBIN_U32("graphics/pokenav/nav_icon.4bpp.lz");
POKENAV_MAIN_GFX const u16 gPokenavLeftHeader_Pal[] = INCBIN_U16("graphics/pokenav/left_headers/palette.gbapal");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderMainMenu_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/main_menu.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderMatchCall_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/match_call.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderRibbons_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/ribbons.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderCondition_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/condition.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderHoennMap_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/hoenn_map.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderParty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/party.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderSearch_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/search.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderCool_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cool.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderBeauty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/beauty.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderCute_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cute.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderSmart_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/smart.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderTough_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/tough.4bpp.lz");

// JP-only unused graphics retained in the original ROM. No pointers to these
// resources exist anywhere in the ROM, so their original purpose is unknown.
#define UNUSED_JP_MENU_SPECIALIZED_PREFIX __attribute__((section(".rodata.unused_jp_menu_specialized_prefix")))
#define UNUSED_JP_MENU_SPECIALIZED_MIDDLE __attribute__((section(".rodata.unused_jp_menu_specialized_middle")))

UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal01[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_01.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles01[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_01.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal02[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_02.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles02[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_02.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal03[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_03.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles03[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_03.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal04[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_04.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles04[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_04.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal05[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_05.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles05[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_05.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles06[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_06.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles07[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_07.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles08[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_08.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles09[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_09.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles10[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_10.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles11[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_11.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_MIDDLE static const u8 sUnusedJpMenuSpecializedSpriteData[] = INCBIN_U8("graphics/unused/jp/menu_specialized/sprite_data.bin");
