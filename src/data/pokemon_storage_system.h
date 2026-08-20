#ifndef GUARD_DATA_POKEMON_STORAGE_SYSTEM_H
#define GUARD_DATA_POKEMON_STORAGE_SYSTEM_H

// This preserves the contiguous JP Pokémon Storage resource stream while
// moving confirmed graphics into the standard pret hierarchy.  The JP-only
// layout and pointer tables remain raw until their owning routines are
// safely converted from naked assembly.
#define POKEMON_STORAGE_MID56_DATA __attribute__((section(".rodata.pokemon_storage_mid56"), aligned(1)))
#define POKEMON_STORAGE_MID57A_DATA __attribute__((section(".rodata.pokemon_storage_mid57a"), aligned(1)))
#define POKEMON_STORAGE_MID56_RESOURCE(symbol, size, path) \
    const u8 symbol[size] POKEMON_STORAGE_MID56_DATA = INCBIN_U8(path)
#define POKEMON_STORAGE_MID57A_RESOURCE(symbol, size, path) \
    const u8 symbol[size] POKEMON_STORAGE_MID57A_DATA = INCBIN_U8(path)

// 0x854B1E4..0x854B258: immediately after Frontier Pass.
// gUnknown_854B1E4 at 0x0854B1E4.
POKEMON_STORAGE_MID56_RESOURCE(gUnknown_854B1E4, 0x28, "data/pokemon_storage/jp/0854B1E4.bin");
// gUnknown_854B20C at 0x0854B20C.
POKEMON_STORAGE_MID56_RESOURCE(gUnknown_854B20C, 0x28, "data/pokemon_storage/jp/0854B20C.bin");
// gUnknown_854B234 at 0x0854B234.
POKEMON_STORAGE_MID56_RESOURCE(gUnknown_854B234, 0x24, "data/pokemon_storage/jp/0854B234.bin");

// region_texts57 remains at 0x854B258..0x854B25C.
// 0x854B25C..0x85567A4: Pokémon Storage UI, wallpapers and tables.
// gUnknown_854B25C at 0x0854B25C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854B25C, 0x20, "graphics/pokemon_storage/box_selection_popup.pal.gbapal");
// gUnknown_854B27C at 0x0854B27C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854B27C, 0x800, "graphics/pokemon_storage/box_selection_popup_center.png.4bpp");
// gUnknown_854BA7C at 0x0854BA7C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BA7C, 0x180, "graphics/pokemon_storage/box_selection_popup_sides.png.4bpp");
// gUnknown_854BBFC at 0x0854BBFC.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BBFC, 0x98, "graphics/pokemon_storage/scrolling_bg.png.4bpp.lz");
// gUnknown_854BC94 at 0x0854BC94.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BC94, 0x10C, "graphics/pokemon_storage/scrolling_bg.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854BDA0, 0x20, "graphics/pokemon_storage/display_menu.pal.gbapal");
// gUnknown_854BDC0 at 0x0854BDC0.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BDC0, 0xFC, "graphics/pokemon_storage/display_menu.bin.lz");
// gUnknown_854BEBC at 0x0854BEBC.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BEBC, 0x40, "data/pokemon_storage/jp/0854BEBC.bin");
// gUnknown_854BEFC at 0x0854BEFC.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BEFC, 0x20, "graphics/pokemon_storage/interface.pal.gbapal");
// gUnknown_854BF1C at 0x0854BF1C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BF1C, 0x20, "graphics/pokemon_storage/pkmn_data_gray.pal.gbapal");
// gUnknown_854BF3C at 0x0854BF3C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BF3C, 0x20, "graphics/pokemon_storage/party_menu.pal.gbapal");
// gUnknown_854BF5C at 0x0854BF5C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BF5C, 0x20, "graphics/pokemon_storage/scrolling_bg.pal.gbapal");
// gUnknown_854BF7C at 0x0854BF7C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BF7C, 0x20, "graphics/pokemon_storage/scrolling_bg_move_items.pal.gbapal");
// gUnknown_854BF9C at 0x0854BF9C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854BF9C, 0x6C0, "data/pokemon_storage/jp/0854BF9C.bin");
// gUnknown_854C65C at 0x0854C65C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C65C, 0xB0, "data/pokemon_storage/jp/0854C65C.bin");
// gUnknown_854C70C at 0x0854C70C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C70C, 0x48, "data/pokemon_storage/jp/0854C70C.bin");
// gUnknown_854C754 at 0x0854C754.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C754, 0x18, "data/pokemon_storage/jp/0854C754.bin");
// gUnknown_854C76C at 0x0854C76C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C76C, 0x18, "data/pokemon_storage/jp/0854C76C.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854C784, 0x20, "graphics/pokemon_storage/waveform.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854C7A4, 0x1C0, "graphics/pokemon_storage/waveform.png.4bpp");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854C964, 0x40, "graphics/pokemon_storage/unused.pal.gbapal");
// gUnknown_854C9A4 at 0x0854C9A4.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C9A4, 0x20, "graphics/pokemon_storage/text_windows.pal.gbapal");
// sPSSWindowTemplates at 0x0854C9C4.
POKEMON_STORAGE_MID57A_RESOURCE(sPSSWindowTemplates, 0x20, "data/pokemon_storage/jp/0854C9C4.bin");
// gUnknown_854C9E4 at 0x0854C9E4.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C9E4, 0x10, "data/pokemon_storage/jp/0854C9E4.bin");
// sWaveformSpritePalette at 0x0854C9F4.
POKEMON_STORAGE_MID57A_RESOURCE(sWaveformSpritePalette, 0x8, "data/pokemon_storage/jp/0854C9F4.bin");
// gUnknown_854C9FC at 0x0854C9FC.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854C9FC, 0x8, "data/pokemon_storage/jp/0854C9FC.bin");
// gUnknown_854CA04 at 0x0854CA04.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854CA04, 0x18, "data/pokemon_storage/jp/0854CA04.bin");
// gUnknown_854CA1C at 0x0854CA1C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854CA1C, 0xF8, "data/pokemon_storage/jp/0854CA1C.bin");
// gUnknown_854CB14 at 0x0854CB14.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854CB14, 0x58, "data/pokemon_storage/jp/0854CB14.bin");
// gUnknown_854CB6C at 0x0854CB6C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854CB6C, 0x18, "data/pokemon_storage/jp/0854CB6C.bin");
// gUnknown_854CB84 at 0x0854CB84.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854CB84, 0x48, "data/pokemon_storage/jp/0854CB84.bin");
// gUnknown_854CBCC at 0x0854CBCC.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_854CBCC, 0x8, "data/pokemon_storage/jp/0854CBCC.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854CBD4, 0x20, "graphics/pokemon_storage/wallpapers/forest/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854CBF4, 0x20, "graphics/pokemon_storage/wallpapers/forest/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854CC14, 0x484, "graphics/pokemon_storage/wallpapers/forest/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D098, 0xE0, "graphics/pokemon_storage/wallpapers/forest/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D178, 0x20, "graphics/pokemon_storage/wallpapers/city/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D198, 0x20, "graphics/pokemon_storage/wallpapers/city/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D1B8, 0x318, "graphics/pokemon_storage/wallpapers/city/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D4D0, 0xDC, "graphics/pokemon_storage/wallpapers/city/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D5AC, 0x20, "graphics/pokemon_storage/wallpapers/desert/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D5CC, 0x20, "graphics/pokemon_storage/wallpapers/desert/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D5EC, 0x3B4, "graphics/pokemon_storage/wallpapers/desert/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854D9A0, 0xFC, "graphics/pokemon_storage/wallpapers/desert/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854DA9C, 0x20, "graphics/pokemon_storage/wallpapers/savanna/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854DABC, 0x20, "graphics/pokemon_storage/wallpapers/savanna/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854DADC, 0x414, "graphics/pokemon_storage/wallpapers/savanna/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854DEF0, 0x104, "graphics/pokemon_storage/wallpapers/savanna/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854DFF4, 0x20, "graphics/pokemon_storage/wallpapers/crag/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854E014, 0x20, "graphics/pokemon_storage/wallpapers/crag/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854E034, 0x3FC, "graphics/pokemon_storage/wallpapers/crag/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854E430, 0xF0, "graphics/pokemon_storage/wallpapers/crag/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854E520, 0x20, "graphics/pokemon_storage/wallpapers/volcano/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854E540, 0x20, "graphics/pokemon_storage/wallpapers/volcano/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854E560, 0x4F0, "graphics/pokemon_storage/wallpapers/volcano/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854EA50, 0x13C, "graphics/pokemon_storage/wallpapers/volcano/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854EB8C, 0x20, "graphics/pokemon_storage/wallpapers/snow/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854EBAC, 0x20, "graphics/pokemon_storage/wallpapers/snow/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854EBCC, 0x460, "graphics/pokemon_storage/wallpapers/snow/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F02C, 0x10C, "graphics/pokemon_storage/wallpapers/snow/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F138, 0x20, "graphics/pokemon_storage/wallpapers/cave/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F158, 0x20, "graphics/pokemon_storage/wallpapers/cave/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F178, 0x3D8, "graphics/pokemon_storage/wallpapers/cave/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F550, 0xD8, "graphics/pokemon_storage/wallpapers/cave/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F628, 0x20, "graphics/pokemon_storage/wallpapers/beach/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F648, 0x20, "graphics/pokemon_storage/wallpapers/beach/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854F668, 0x3D0, "graphics/pokemon_storage/wallpapers/beach/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FA38, 0x100, "graphics/pokemon_storage/wallpapers/beach/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FB38, 0x20, "graphics/pokemon_storage/wallpapers/seafloor/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FB58, 0x20, "graphics/pokemon_storage/wallpapers/seafloor/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FB78, 0x2FC, "graphics/pokemon_storage/wallpapers/seafloor/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FE74, 0x114, "graphics/pokemon_storage/wallpapers/seafloor/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FF88, 0x20, "graphics/pokemon_storage/wallpapers/river/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FFA8, 0x20, "graphics/pokemon_storage/wallpapers/river/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0854FFC8, 0x3E8, "graphics/pokemon_storage/wallpapers/river/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085503B0, 0xF8, "graphics/pokemon_storage/wallpapers/river/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085504A8, 0x20, "graphics/pokemon_storage/wallpapers/sky/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085504C8, 0x20, "graphics/pokemon_storage/wallpapers/sky/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085504E8, 0x388, "graphics/pokemon_storage/wallpapers/sky/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550870, 0xF0, "graphics/pokemon_storage/wallpapers/sky/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550960, 0x20, "graphics/pokemon_storage/wallpapers/polkadot/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550980, 0x20, "graphics/pokemon_storage/wallpapers/polkadot/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085509A0, 0x2C8, "graphics/pokemon_storage/wallpapers/polkadot/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550C68, 0x100, "graphics/pokemon_storage/wallpapers/polkadot/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550D68, 0x20, "graphics/pokemon_storage/wallpapers/pokecenter/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550D88, 0x20, "graphics/pokemon_storage/wallpapers/pokecenter/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08550DA8, 0x27C, "graphics/pokemon_storage/wallpapers/pokecenter/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551024, 0x100, "graphics/pokemon_storage/wallpapers/pokecenter/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551124, 0x20, "graphics/pokemon_storage/wallpapers/machine/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551144, 0x20, "graphics/pokemon_storage/wallpapers/machine/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551164, 0x254, "graphics/pokemon_storage/wallpapers/machine/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085513B8, 0xC4, "graphics/pokemon_storage/wallpapers/machine/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855147C, 0x20, "graphics/pokemon_storage/wallpapers/plain/frame.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855149C, 0x20, "graphics/pokemon_storage/wallpapers/plain/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085514BC, 0x120, "graphics/pokemon_storage/wallpapers/plain/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085515DC, 0x98, "graphics/pokemon_storage/wallpapers/plain/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551674, 0x1B0, "data/pokemon_storage/jp/08551674.bin");
// gUnknown_8551824 at 0x08551824.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8551824, 0x44, "data/pokemon_storage/jp/08551824.bin");
// gUnknown_8551868 at 0x08551868.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8551868, 0xC0, "data/pokemon_storage/jp/08551868.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551928, 0x80, "graphics/pokemon_storage/arrow.png.4bpp");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085519A8, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame1.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085519C8, 0x20, "graphics/pokemon_storage/wallpapers/zigzagoon/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085519E8, 0x1F4, "graphics/pokemon_storage/wallpapers/zigzagoon/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551BDC, 0x118, "graphics/pokemon_storage/wallpapers/zigzagoon/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551CF4, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame1.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551D14, 0x20, "graphics/pokemon_storage/wallpapers/screen/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551D34, 0x27C, "graphics/pokemon_storage/wallpapers/screen/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08551FB0, 0x12C, "graphics/pokemon_storage/wallpapers/screen/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085520DC, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085520FC, 0x20, "graphics/pokemon_storage/wallpapers/horizontal/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855211C, 0x25C, "data/pokemon_storage/jp/0855211C.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552378, 0x10C, "graphics/pokemon_storage/wallpapers/horizontal/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552484, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame1.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085524A4, 0x20, "graphics/pokemon_storage/wallpapers/diagonal/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085524C4, 0x1EC, "graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085526B0, 0xF0, "graphics/pokemon_storage/wallpapers/diagonal/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085527A0, 0x20, "graphics/pokemon_storage/wallpapers/block/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085527C0, 0x20, "graphics/pokemon_storage/wallpapers/block/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085527E0, 0x1D0, "graphics/pokemon_storage/wallpapers/block/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085529B0, 0xF8, "graphics/pokemon_storage/wallpapers/block/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552AA8, 0x20, "graphics/pokemon_storage/wallpapers/ribbon/frame.pal.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552AC8, 0x20, "graphics/pokemon_storage/wallpapers/ribbon/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552AE8, 0x268, "data/pokemon_storage/jp/08552AE8.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552D50, 0x134, "graphics/pokemon_storage/wallpapers/ribbon/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552E84, 0x20, "graphics/pokemon_storage/wallpapers/pokecenter2/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552EA4, 0x20, "graphics/pokemon_storage/wallpapers/pokecenter2/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08552EC4, 0x240, "graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553104, 0x114, "graphics/pokemon_storage/wallpapers/pokecenter2/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553218, 0x20, "graphics/pokemon_storage/wallpapers/frame/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553238, 0x20, "graphics/pokemon_storage/wallpapers/frame/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553258, 0x210, "graphics/pokemon_storage/wallpapers/frame/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553468, 0x114, "graphics/pokemon_storage/wallpapers/frame/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855357C, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame1.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855359C, 0x20, "graphics/pokemon_storage/wallpapers/zigzagoon/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085535BC, 0x1AC, "graphics/pokemon_storage/wallpapers/blank/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553768, 0xDC, "graphics/pokemon_storage/wallpapers/blank/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553844, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553864, 0x20, "graphics/pokemon_storage/wallpapers/circles/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553884, 0x254, "graphics/pokemon_storage/wallpapers/circles/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553AD8, 0xFC, "graphics/pokemon_storage/wallpapers/circles/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553BD4, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553BF4, 0x20, "graphics/pokemon_storage/wallpapers/azumarill/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553C14, 0x1EC, "graphics/pokemon_storage/wallpapers/azumarill/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553E00, 0xF8, "graphics/pokemon_storage/wallpapers/azumarill/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553EF8, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553F18, 0x20, "graphics/pokemon_storage/wallpapers/pikachu/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08553F38, 0x234, "graphics/pokemon_storage/wallpapers/pikachu/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855416C, 0x128, "graphics/pokemon_storage/wallpapers/pikachu/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554294, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085542B4, 0x20, "graphics/pokemon_storage/wallpapers/legendary/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085542D4, 0x2E0, "graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085545B4, 0x144, "graphics/pokemon_storage/wallpapers/legendary/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085546F8, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554718, 0x20, "graphics/pokemon_storage/wallpapers/dusclops/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554738, 0x24C, "graphics/pokemon_storage/wallpapers/dusclops/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554984, 0xF8, "graphics/pokemon_storage/wallpapers/dusclops/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554A7C, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554A9C, 0x20, "graphics/pokemon_storage/wallpapers/ludicolo/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554ABC, 0x2C0, "graphics/pokemon_storage/wallpapers/ludicolo/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554D7C, 0x120, "graphics/pokemon_storage/wallpapers/ludicolo/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554E9C, 0x20, "graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554EBC, 0x20, "graphics/pokemon_storage/wallpapers/whiscash/bg.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08554EDC, 0x248, "graphics/pokemon_storage/wallpapers/whiscash/tiles.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555124, 0x12C, "graphics/pokemon_storage/wallpapers/whiscash/tilemap.bin.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555250, 0x44, "graphics/pokemon_storage/wallpapers/icons/aqua.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555294, 0x3C, "graphics/pokemon_storage/wallpapers/icons/heart.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085552D0, 0x40, "graphics/pokemon_storage/wallpapers/icons/five_star.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555310, 0x28, "graphics/pokemon_storage/wallpapers/icons/brick.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555338, 0x3C, "graphics/pokemon_storage/wallpapers/icons/four_star.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555374, 0x50, "graphics/pokemon_storage/wallpapers/icons/asterisk.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085553C4, 0x30, "graphics/pokemon_storage/wallpapers/icons/dot.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085553F4, 0x44, "data/pokemon_storage/jp/085553F4.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555438, 0x2C, "graphics/pokemon_storage/wallpapers/icons/line_circle.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555464, 0x4C, "graphics/pokemon_storage/wallpapers/icons/pokeball.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085554B0, 0x44, "graphics/pokemon_storage/wallpapers/icons/maze.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085554F4, 0x48, "graphics/pokemon_storage/wallpapers/icons/footprint.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855553C, 0x44, "graphics/pokemon_storage/wallpapers/icons/big_asterisk.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555580, 0x40, "graphics/pokemon_storage/wallpapers/icons/circle.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085555C0, 0x50, "graphics/pokemon_storage/wallpapers/icons/koffing.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555610, 0x68, "graphics/pokemon_storage/wallpapers/icons/ribbon.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555678, 0x40, "data/pokemon_storage/jp/08555678.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085556B8, 0x30, "graphics/pokemon_storage/wallpapers/icons/four_circles.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085556E8, 0x44, "graphics/pokemon_storage/wallpapers/icons/lotad.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855572C, 0x48, "graphics/pokemon_storage/wallpapers/icons/crystal.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555774, 0x38, "graphics/pokemon_storage/wallpapers/icons/pichu.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085557AC, 0x50, "graphics/pokemon_storage/wallpapers/icons/diglett.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085557FC, 0x44, "graphics/pokemon_storage/wallpapers/icons/luvdisc.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555840, 0x44, "graphics/pokemon_storage/wallpapers/icons/star_in_circle.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555884, 0x54, "graphics/pokemon_storage/wallpapers/icons/spinda.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085558D8, 0x44, "graphics/pokemon_storage/wallpapers/icons/latis.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_0855591C, 0x44, "data/pokemon_storage/jp/0855591C.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555960, 0x48, "graphics/pokemon_storage/wallpapers/icons/minun.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085559A8, 0x5C, "graphics/pokemon_storage/wallpapers/icons/togepi.png.4bpp.lz");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555A04, 0x3C, "graphics/pokemon_storage/wallpapers/icons/magma.png.4bpp.lz");
// gUnknown_8555A40 at 0x08555A40.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8555A40, 0xC0, "data/pokemon_storage/jp/08555A40.bin");
// gUnknown_8555B00 at 0x08555B00.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8555B00, 0x7C, "data/pokemon_storage/jp/08555B00.bin");
// gUnknown_8555B7C at 0x08555B7C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8555B7C, 0x28, "data/pokemon_storage/jp/08555B7C.bin");
// gUnknown_8555BA4 at 0x08555BA4.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8555BA4, 0x38, "data/pokemon_storage/jp/08555BA4.bin");
// gUnknown_8555BDC at 0x08555BDC.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8555BDC, 0x18, "data/pokemon_storage/jp/08555BDC.bin");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555BF4, 0x20, "graphics/pokemon_storage/hand_cursor.png.gbapal");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08555C14, 0x800, "graphics/pokemon_storage/hand_cursor.png.4bpp");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_08556414, 0x80, "graphics/pokemon_storage/hand_cursor_shadow.png.4bpp");
// sPlaceChangeFuncs at 0x08556494.
POKEMON_STORAGE_MID57A_RESOURCE(sPlaceChangeFuncs, 0xC, "data/pokemon_storage/jp/08556494.bin");
// gUnknown_85564A0 at 0x085564A0.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_85564A0, 0x18, "data/pokemon_storage/jp/085564A0.bin");
// gUnknown_85564B8 at 0x085564B8.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_85564B8, 0x28, "data/pokemon_storage/jp/085564B8.bin");
// gUnknown_85564E0 at 0x085564E0.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_85564E0, 0x18, "data/pokemon_storage/jp/085564E0.bin");
// gUnknown_85564F8 at 0x085564F8.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_85564F8, 0x54, "data/pokemon_storage/jp/085564F8.bin");
// gUnknown_855654C at 0x0855654C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_855654C, 0x18, "data/pokemon_storage/jp/0855654C.bin");
// gUnknown_8556564 at 0x08556564.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8556564, 0x18, "data/pokemon_storage/jp/08556564.bin");
// gUnknown_855657C at 0x0855657C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_855657C, 0x9C, "data/pokemon_storage/jp/0855657C.bin");
// gUnknown_8556618 at 0x08556618.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8556618, 0x8, "data/pokemon_storage/jp/08556618.bin");
// gUnknown_8556620 at 0x08556620.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8556620, 0x80, "graphics/pokemon_storage/item_info_frame.png.4bpp");
POKEMON_STORAGE_MID57A_RESOURCE(sPokemonStorage_085566A0, 0xCC, "data/pokemon_storage/jp/085566A0.bin");
// gUnknown_855676C at 0x0855676C.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_855676C, 0x18, "data/pokemon_storage/jp/0855676C.bin");
// gUnknown_8556784 at 0x08556784.
POKEMON_STORAGE_MID57A_RESOURCE(gUnknown_8556784, 0x20, "data/pokemon_storage/jp/08556784.bin");

#undef POKEMON_STORAGE_MID57A_RESOURCE
#undef POKEMON_STORAGE_MID56_RESOURCE
#undef POKEMON_STORAGE_MID57A_DATA
#undef POKEMON_STORAGE_MID56_DATA

#endif // GUARD_DATA_POKEMON_STORAGE_SYSTEM_H
