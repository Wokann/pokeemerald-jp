#ifndef GUARD_DATA_POKEDEX_H
#define GUARD_DATA_POKEDEX_H

// 0x08538FF4-0x08539932.  This follows pokeemerald's data/pokemon source
// hierarchy while preserving the JP alphabetical order.
#include "pokemon/pokedex_orders.h"

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
