#ifndef GUARD_DATA_TRAINER_CARD_H
#define GUARD_DATA_TRAINER_CARD_H

// JP Trainer Card resources retained in original ROM order.  Standard assets
// use their pret paths; only the JP-specific FRLG-style background remains
// explicitly named as such pending a pixel-level semantic audit.

#define TRAINER_CARD_MID55_DATA __attribute__((section(".rodata.trainer_card_mid55"), aligned(1)))
#define TRAINER_CARD_MID55_RESOURCE(symbol, size, path) \
    const u8 symbol[size] TRAINER_CARD_MID55_DATA = INCBIN_U8(path)

TRAINER_CARD_MID55_RESOURCE(gUnknown_854441C, 0x740, "graphics/trainer_card/tiles.4bpp.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8544B5C, 0x6C0, "graphics/trainer_card/frlg/tiles.4bpp.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854521C, 0x174, "graphics/trainer_card/frlg/stickers.4bpp.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8545390, 0x1A0, "graphics/trainer_card/front.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8545530, 0x1B8, "graphics/trainer_card/frlg/front.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85456E8, 0xDC, "graphics/trainer_card/back.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85457C4, 0x12C, "graphics/trainer_card/frlg/back.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85458F0, 0x180, "graphics/trainer_card/front_link.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8545A70, 0x18C, "graphics/trainer_card/frlg/front_link.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8545BFC, 0x98, "graphics/trainer_card/bg.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8545C94, 0x478, "graphics/trainer_card/frlg/bg_jp.bin.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854610C, 0x20, "graphics/trainer_card/female_bg.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854612C, 0x20, "graphics/trainer_card/frlg/female_bg.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854614C, 0x20, "graphics/trainer_card/badges.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854616C, 0x20, "graphics/trainer_card/frlg/badges.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854618C, 0x20, "graphics/trainer_card/star.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85461AC, 0x20, "graphics/trainer_card/frlg/stickers1.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85461CC, 0x20, "graphics/trainer_card/frlg/stickers2.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85461EC, 0x20, "graphics/trainer_card/frlg/stickers3.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854620C, 0x20, "graphics/trainer_card/frlg/stickers4.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854622C, 0x248, "graphics/trainer_card/badges.4bpp.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546474, 0x2A0, "graphics/trainer_card/frlg/badges.4bpp.lz");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546714, 0x10, "data/trainer_card/jp/trainer_card_data_00.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546724, 0x20, "graphics/trainer_card/jp/palette_09.gbapal");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546744, 0x14, "data/trainer_card/jp/trainer_card_data_01.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546758, 0x14, "data/trainer_card/jp/trainer_card_data_02.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854676C, 0x3, "data/trainer_card/jp/trainer_card_data_03.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_854676F, 0x6, "data/trainer_card/jp/trainer_card_data_04.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546775, 0x3, "data/trainer_card/jp/trainer_card_data_05.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546778, 0x8, "data/trainer_card/jp/trainer_card_data_06.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546780, 0x8, "data/trainer_card/jp/trainer_card_data_07.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_8546788, 0x18, "data/trainer_card/jp/trainer_card_data_08.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467A0, 0x2, "data/trainer_card/jp/trainer_card_data_09.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467A2, 0x2, "data/trainer_card/jp/trainer_card_data_10.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467A4, 0x8, "data/trainer_card/jp/trainer_card_data_11.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467AC, 0x2, "data/trainer_card/jp/trainer_card_data_12.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467AE, 0x2, "data/trainer_card/jp/trainer_card_data_13.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467B0, 0x2, "data/trainer_card/jp/trainer_card_data_14.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467B2, 0x2, "data/trainer_card/jp/trainer_card_data_15.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467B4, 0x2, "data/trainer_card/jp/trainer_card_data_16.bin");
TRAINER_CARD_MID55_RESOURCE(gUnknown_85467B6, 0x2, "data/trainer_card/jp/trainer_card_data_17.bin");

#undef TRAINER_CARD_MID55_RESOURCE
#undef TRAINER_CARD_MID55_DATA

// These tables follow the Trainer Card text block immediately before the
// Frontier Pass data. They use external linkage because the still-naked
// Trainer Card implementation resides in a separate object.
#define TRAINER_CARD_MID56_TEXT_COLORS_DATA __attribute__((section(".rodata.trainer_card_mid56_text_colors"), aligned(1)))
#define TRAINER_CARD_MID56_LINK_TEXTS_DATA __attribute__((section(".rodata.trainer_card_mid56_link_texts")))
#define TRAINER_CARD_MID56_SUFFIX_DATA __attribute__((section(".rodata.trainer_card_mid56_suffix"), aligned(1)))

const u8 sTrainerCardTextColors[] TRAINER_CARD_MID56_TEXT_COLORS_DATA =
{
    0x0A, 0x10, 0x00,
};

const u8 *const sLinkBattleTexts[] TRAINER_CARD_MID56_LINK_TEXTS_DATA =
{
    gText_LinkBattles,
    gText_LinkCableBattles,
    gText_LinkBattles,
};

const u8 sTrainerCardIconPaletteSlots[] TRAINER_CARD_MID56_SUFFIX_DATA =
{
    5, 6, 7, 8, 9, 10,
};

const u8 sTrainerCardIconXOffsets[] TRAINER_CARD_MID56_SUFFIX_DATA =
{
    0, 4, 8, 12, 16, 20,
};

const u8 sTrainerCardStickerPaletteSlots[] TRAINER_CARD_MID56_SUFFIX_DATA =
{
    11, 12, 13, 14,
};

// The first two bytes are the card-type offsets. The explicit trailing zeros
// retain the original four-byte boundary before the Frontier Pass section.
const u8 sTrainerCardStarYOffsets[4] TRAINER_CARD_MID56_SUFFIX_DATA =
{
    7, 7, 0, 0,
};

__asm__(".global gUnknown_85467C1\n"
        ".set gUnknown_85467C1, sTrainerCardTextColors\n"
        ".global gUnknown_85467C4\n"
        ".set gUnknown_85467C4, sLinkBattleTexts\n"
        ".global gUnknown_85467D0\n"
        ".set gUnknown_85467D0, sTrainerCardIconPaletteSlots\n"
        ".global gUnknown_85467D6\n"
        ".set gUnknown_85467D6, sTrainerCardIconXOffsets\n"
        ".global gUnknown_85467DC\n"
        ".set gUnknown_85467DC, sTrainerCardStickerPaletteSlots\n"
        ".global gUnknown_85467E0\n"
        ".set gUnknown_85467E0, sTrainerCardStarYOffsets");

#undef TRAINER_CARD_MID56_SUFFIX_DATA
#undef TRAINER_CARD_MID56_LINK_TEXTS_DATA
#undef TRAINER_CARD_MID56_TEXT_COLORS_DATA

#endif // GUARD_DATA_TRAINER_CARD_H
