#ifndef POKEEMERALD_JP_TRAINER_BACK_PIC_TABLES_H
#define POKEEMERALD_JP_TRAINER_BACK_PIC_TABLES_H

#include "data.h"
#include "graphics.h"
#include "constants/trainers.h"

// These JP back-picture palettes have not yet been split from the raw trainer
// graphics block.  Keep local semantic aliases for the standard table.
extern const u32 gUnknown_82D961C_2_Pal[];
extern const u32 gUnknown_82D961C_3_Pal[];
#define gTrainerBackPicPalette_Red gUnknown_82D961C_2_Pal
#define gTrainerBackPicPalette_Leaf gUnknown_82D961C_3_Pal

// This table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway.
const struct CompressedSpriteSheet gTrainerBackPicTable[] TRAINER_BACK_PIC_TABLE_DATA =
{
    [TRAINER_BACK_PIC_BRENDAN] = {
        .data = (const u32 *)gTrainerBackPic_Brendan,
        .size = TRAINER_PIC_SIZE * 4,
        .tag = TRAINER_BACK_PIC_BRENDAN,
    },
    [TRAINER_BACK_PIC_MAY] = {
        .data = (const u32 *)gTrainerBackPic_May,
        .size = TRAINER_PIC_SIZE * 4,
        .tag = TRAINER_BACK_PIC_MAY,
    },
    [TRAINER_BACK_PIC_RED] = {
        .data = (const u32 *)gTrainerBackPic_Red,
        .size = TRAINER_PIC_SIZE * 5,
        .tag = TRAINER_BACK_PIC_RED,
    },
    [TRAINER_BACK_PIC_LEAF] = {
        .data = (const u32 *)gTrainerBackPic_Leaf,
        .size = TRAINER_PIC_SIZE * 5,
        .tag = TRAINER_BACK_PIC_LEAF,
    },
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN] = {
        .data = (const u32 *)gTrainerBackPic_RubySapphireBrendan,
        .size = TRAINER_PIC_SIZE * 4,
        .tag = TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
    },
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY] = {
        .data = (const u32 *)gTrainerBackPic_RubySapphireMay,
        .size = TRAINER_PIC_SIZE * 4,
        .tag = TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY,
    },
    [TRAINER_BACK_PIC_WALLY] = {
        .data = (const u32 *)gTrainerBackPic_Wally,
        .size = TRAINER_PIC_SIZE * 4,
        .tag = TRAINER_BACK_PIC_WALLY,
    },
    [TRAINER_BACK_PIC_STEVEN] = {
        .data = (const u32 *)gTrainerBackPic_Steven,
        .size = TRAINER_PIC_SIZE * 4,
        .tag = TRAINER_BACK_PIC_STEVEN,
    },
};

#define TRAINER_BACK_PAL(trainerPic, pal) [TRAINER_BACK_PIC_##trainerPic] = {pal, TRAINER_BACK_PIC_##trainerPic}

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] TRAINER_BACK_PIC_TABLE_DATA =
{
    TRAINER_BACK_PAL(BRENDAN, gTrainerPalette_Brendan),
    TRAINER_BACK_PAL(MAY, gTrainerPalette_May),
    TRAINER_BACK_PAL(RED, gTrainerBackPicPalette_Red),
    TRAINER_BACK_PAL(LEAF, gTrainerBackPicPalette_Leaf),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_BRENDAN, gTrainerPalette_RubySapphireBrendan),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_MAY, gTrainerPalette_RubySapphireMay),
    TRAINER_BACK_PAL(WALLY, gTrainerPalette_Wally),
    TRAINER_BACK_PAL(STEVEN, gTrainerPalette_Steven),
};

#undef TRAINER_BACK_PAL
#undef gTrainerBackPicPalette_Leaf
#undef gTrainerBackPicPalette_Red

#endif // POKEEMERALD_JP_TRAINER_BACK_PIC_TABLES_H
