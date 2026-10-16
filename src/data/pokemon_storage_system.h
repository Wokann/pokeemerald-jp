#ifndef GUARD_DATA_POKEMON_STORAGE_SYSTEM_H
#define GUARD_DATA_POKEMON_STORAGE_SYSTEM_H

// Remaining JP Storage cursor and menu resources.
// Wallpapers are defined in data/wallpapers.h at pokemon_storage_system.c.
#define POKEMON_STORAGE_MID57A_DATA __attribute__((section(".rodata.pokemon_storage_mid57a"), aligned(1)))
#define POKEMON_STORAGE_MID57A_RESOURCE(symbol, size, path) \
    const u8 symbol[size] POKEMON_STORAGE_MID57A_DATA = INCBIN_U8(path)

// 0x08555B7C..0x085567A4: remaining Storage cursor and menu tables.
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
#undef POKEMON_STORAGE_MID57A_DATA

#endif // GUARD_DATA_POKEMON_STORAGE_SYSTEM_H
