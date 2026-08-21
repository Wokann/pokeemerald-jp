#ifndef GUARD_DATA_POKEDEX_H
#define GUARD_DATA_POKEDEX_H

// Pokédex list-page resources retained in original JP ROM order.

#define POKEDEX_LIST_MAIN_PREFIX_DATA __attribute__((section(".rodata.pokedex_list_main_prefix"), aligned(1)))
#define POKEDEX_LIST_MAIN_PREFIX_RESOURCE(symbol, size, path) \
    const u8 symbol[size] POKEDEX_LIST_MAIN_PREFIX_DATA = INCBIN_U8(path)

// 0x08537422-0x08537A10.  The Hoenn palette has a second direct ROM entry
// point at +0x60, used by the list-page palette loader.
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBgPaletteHoenn, 0xC0, "graphics/pokedex/list_bg_palettes_hoenn.gbapal");
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBgPaletteAlt, 0xC0, "graphics/pokedex/list_bg_palettes_alt.gbapal");
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBgPaletteNational, 0xBE, "graphics/pokedex/list_bg_palettes_national.gbapal");
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBg0TilemapHoenn, 0xD0, "graphics/pokedex/list_bg0_hoenn.bin.lz");
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBg0TilemapNational, 0xD4, "graphics/pokedex/list_bg0_national.bin.lz");
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBg1Tilemap, 0x150, "graphics/pokedex/list_bg1.bin.lz");
POKEDEX_LIST_MAIN_PREFIX_RESOURCE(gPokedexListBg3Tilemap, 0xBC, "graphics/pokedex/list_bg3.bin.lz");

#undef POKEDEX_LIST_MAIN_PREFIX_RESOURCE
#undef POKEDEX_LIST_MAIN_PREFIX_DATA

#define POKEDEX_SCREEN_TILEMAPS_DATA __attribute__((section(".rodata.pokedex_screen_tilemaps"), aligned(1)))
#define POKEDEX_SCREEN_TILEMAP_RESOURCE(symbol, size, path) \
    const u8 symbol[size] POKEDEX_SCREEN_TILEMAPS_DATA = INCBIN_U8(path)

// 0x08537A10-0x08537E44.  The sources use the same resource names and
// hierarchy as pokeemerald; gbagfx reproduces every corresponding JP LZ77
// stream exactly.
POKEDEX_SCREEN_TILEMAP_RESOURCE(gPokedexInfoScreen_Tilemap, 0x134, "graphics/pokedex/info_screen.bin.lz");
POKEDEX_SCREEN_TILEMAP_RESOURCE(gPokedexCryScreen_Tilemap, 0xEC, "graphics/pokedex/cry_screen.bin.lz");
POKEDEX_SCREEN_TILEMAP_RESOURCE(gPokedexSizeScreen_Tilemap, 0xF4, "graphics/pokedex/size_screen.bin.lz");
POKEDEX_SCREEN_TILEMAP_RESOURCE(gPokedexScreenSelectBarMain_Tilemap, 0x90, "graphics/pokedex/screen_select_bar_main.bin.lz");
POKEDEX_SCREEN_TILEMAP_RESOURCE(gPokedexScreenSelectBarSubmenu_Tilemap, 0x90, "graphics/pokedex/screen_select_bar_submenu.bin.lz");

#undef POKEDEX_SCREEN_TILEMAP_RESOURCE
#undef POKEDEX_SCREEN_TILEMAPS_DATA

#define POKEDEX_LIST_MAIN_TILES_DATA __attribute__((section(".rodata.pokedex_list_main_tiles"), aligned(1)))

// 0x08537E8C-0x08538FF4.  A separate unreferenced JP LZ77 stream at
// 0x08537E44-0x08537E8C remains in its original assembly section.
const u8 gPokedexListBgTiles[0x1168] POKEDEX_LIST_MAIN_TILES_DATA = INCBIN_U8("graphics/pokedex/list_bg_tiles.4bpp.lz");

#undef POKEDEX_LIST_MAIN_TILES_DATA

// Pokédex Search tables retained in original JP ROM order.

#define POKEDEX_MID55_DATA __attribute__((section(".rodata.pokedex_mid55"), aligned(1)))
#define POKEDEX_MID55_RESOURCE(symbol, size, path) \
    const u8 symbol[size] POKEDEX_MID55_DATA = INCBIN_U8(path)

POKEDEX_MID55_RESOURCE(gUnknown_85441BC, 0x1C, "data/pokedex/jp/search_data_00.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85441D8, 0x1C, "data/pokedex/jp/search_data_01.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85441F4, 0x1C, "data/pokedex/jp/search_data_02.bin");
POKEDEX_MID55_RESOURCE(gUnknown_8544210, 0x18, "data/pokedex/jp/search_data_03.bin");
POKEDEX_MID55_RESOURCE(gUnknown_8544228, 0x38, "data/pokedex/jp/search_data_04.bin");
POKEDEX_MID55_RESOURCE(gUnknown_8544260, 0x58, "data/pokedex/jp/search_data_05.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85442B8, 0x60, "data/pokedex/jp/search_data_06.bin");
POKEDEX_MID55_RESOURCE(gUnknown_8544318, 0x98, "data/pokedex/jp/search_data_07.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85443B0, 0x2, "data/pokedex/jp/search_data_08.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85443B2, 0x6, "data/pokedex/jp/search_data_09.bin");
POKEDEX_MID55_RESOURCE(sDexSearchTypeIds, 0x14, "data/pokedex/jp/search_type_ids.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85443CC, 0x30, "data/pokedex/jp/search_data_10.bin");
POKEDEX_MID55_RESOURCE(gUnknown_85443FC, 0x10, "data/pokedex/jp/search_data_11.bin");
POKEDEX_MID55_RESOURCE(gUnknown_854440C, 0x10, "data/pokedex/jp/search_data_12.bin");

#undef POKEDEX_MID55_RESOURCE
#undef POKEDEX_MID55_DATA

#endif // GUARD_DATA_POKEDEX_H
