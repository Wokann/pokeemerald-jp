#ifndef GUARD_DATA_SLOT_MACHINE_H
#define GUARD_DATA_SLOT_MACHINE_H

#include "bg.h"
#include "window.h"

// JP Slot Machine data retained in its original per-section ROM order.
// Structured pointer tables remain raw while their referenced C functions and
// assets are still being independently decompiled.

#define SLOT_MACHINE_DATA(sectionName) __attribute__((section(sectionName), aligned(1)))
#define SLOT_MACHINE_RESOURCE(symbol, size, sectionName, path) \
    const u8 symbol[size] SLOT_MACHINE_DATA(sectionName) = INCBIN_U8(path)

const struct BgTemplate sSlotMachineBgTemplates[4] SLOT_MACHINE_DATA(".rodata.85843A8") =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

const struct WindowTemplate sSlotMachineWindowTemplates[] SLOT_MACHINE_DATA(".rodata.85843A8") =
{
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1A8,
    },
    DUMMY_WIN_TEMPLATE,
};

const u8 sReelTimeAuraColors[] SLOT_MACHINE_DATA(".rodata.8584598") =
{
    16, 0,
};

const u16 sReelTimeDuckOffsets[] SLOT_MACHINE_DATA(".rodata.8584598") =
{
    0, 0x40, 0x80, 0xC0,
};

const s16 sDigitalDisplaySmokeXOffsets[] SLOT_MACHINE_DATA(".rodata.8584598") =
{
    4, -4, 4, -4,
};

const s16 sDigitalDisplaySmokeYOffsets[] SLOT_MACHINE_DATA(".rodata.8584598") =
{
    4, 4, -4, -4,
};

const s16 sDigitalDisplayRegBonusXOffsets[] SLOT_MACHINE_DATA(".rodata.85845B2") =
{
     0, -40, 0, 0, 48, 0, 24, 0,
};

const s16 sDigitalDisplayRegBonusYOffsets[] SLOT_MACHINE_DATA(".rodata.85845B2") =
{
    -32, 0, -32, -48, 0, -48, 0, -48,
};

const s16 sDigitalDisplayRegBonusDelays[] SLOT_MACHINE_DATA(".rodata") =
{
    16, 12, 16, 0, 0, 4, 8, 8,
};

const s16 sDigitalDisplayBigBonusOffsets[] SLOT_MACHINE_DATA(".rodata") =
{
    160, 192, 224, 104, 80, 64, 48, 24,
};

const s16 sInitialReelPositions[][2] SLOT_MACHINE_DATA(".rodata.8584638") =
{
    {0, 6},
    {0, 10},
    {0, 2},
};

const u8 sSpecialDrawOdds[][3] SLOT_MACHINE_DATA(".rodata.8584638") =
{
    {1, 1, 12},
    {1, 1, 14},
    {2, 2, 14},
    {2, 2, 14},
    {2, 3, 16},
    {3, 3, 16},
};

const u8 sBiasProbabilities_Special[][6] SLOT_MACHINE_DATA(".rodata.8584638") =
{
    {25, 25, 30, 40, 40, 50},
    {25, 25, 30, 30, 35, 35},
    {25, 25, 30, 25, 25, 30},
};

const u8 sBiasProbabilities_Regular[][6] SLOT_MACHINE_DATA(".rodata.8584638") =
{
    {20, 25, 25, 20, 25, 25},
    {12, 15, 15, 18, 19, 22},
    {25, 25, 25, 30, 30, 40},
    {25, 25, 20, 20, 15, 15},
    {40, 40, 35, 35, 40, 40},
};

const u8 sReelTimeProbabilities_NormalGame[][17] SLOT_MACHINE_DATA(".rodata.8584638") =
{
    {243, 243, 243, 80, 80, 80, 80, 40, 40, 40, 40, 40, 40, 5, 5, 5, 5},
    {5, 5, 5, 150, 150, 150, 150, 130, 130, 130, 130, 130, 130, 100, 100, 100, 5},
    {4, 4, 4, 20, 20, 20, 20, 80, 80, 80, 80, 80, 80, 100, 100, 100, 40},
    {2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 45, 45, 45, 100},
    {1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 100},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6},
};

const u8 sReelTimeProbabilities_LuckyGame[][17] SLOT_MACHINE_DATA(".rodata.8584638") =
{
    {243, 243, 243, 200, 200, 200, 200, 160, 160, 160, 160, 160, 160, 70, 70, 70, 5},
    {5, 5, 5, 25, 25, 25, 25, 5, 5, 5, 5, 5, 5, 2, 2, 2, 6},
    {4, 4, 4, 25, 25, 25, 25, 30, 30, 30, 30, 30, 30, 40, 40, 40, 35},
    {2, 2, 2, 3, 3, 3, 3, 30, 30, 30, 30, 30, 30, 100, 100, 100, 50},
    {1, 1, 1, 2, 2, 2, 2, 30, 30, 30, 30, 30, 30, 40, 40, 40, 100},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 60},
};

const u16 sReelTimeSpeed_Probabilities[][2] SLOT_MACHINE_DATA(".rodata.858475C") =
{
    {10, 5},
    {10, 10},
    {10, 15},
    {10, 25},
    {10, 35},
};

const u16 sQuarterSpeed_ProbabilityBoost[] SLOT_MACHINE_DATA(".rodata.858475C") =
{
    0, 5, 10, 15, 20,
};

const u16 sBiasesSpecial[] SLOT_MACHINE_DATA(".rodata.8584782") =
{
    0x80, // BIAS_STRAIGHT_7
    0x20, // BIAS_REELTIME
    0x40, // BIAS_MIXED_7
};

const u16 sBiasesRegular[] SLOT_MACHINE_DATA(".rodata.8584782") =
{
    0x10, // BIAS_POWER
    0x08, // BIAS_AZURILL
    0x04, // BIAS_LOTAD
    0x02, // BIAS_CHERRY
    0x01, // BIAS_REPLAY
};

SLOT_MACHINE_RESOURCE(sDigitalDisplay_SpriteCoords, 0x8E, ".rodata.85847BE", "data/slot_machine/jp/digital_display_sprite_coords.bin");
SLOT_MACHINE_RESOURCE(sDigitalDisplay_SpriteCallbacks, 0x8C, ".rodata.85847BE", "data/slot_machine/jp/digital_display_sprite_callbacks.bin");

SLOT_MACHINE_RESOURCE(gUnknown_85849C0, 0x2A4, ".rodata.85849C0", "data/slot_machine/jp/digital_display_scene_data.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelSymbol, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_symbol_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_CoinNumber, 0x18, ".rodata.85849C0", "data/slot_machine/jp/coin_number_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelBackground, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_background_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimePikachu, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_pikachu_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeMachineAntennae, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_machine_antennae_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeMachine, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_machine_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_BrokenReelTimeMachine, 0x18, ".rodata.85849C0", "data/slot_machine/jp/broken_reel_time_machine_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeNumbers, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_numbers_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeShadow, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_shadow_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeNumberGap, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_number_gap_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeBolt, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_bolt_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimePikachuAura, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_pikachu_aura_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeExplosion, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_explosion_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeDuck, 0x18, ".rodata.85849C0", "data/slot_machine/jp/reel_time_duck_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_ReelTimeSmoke, 0x168, ".rodata.85849C0", "data/slot_machine/jp/reel_time_smoke_sprite_data.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplate_PikaPowerBolt, 0x28, ".rodata.85849C0", "data/slot_machine/jp/pika_power_bolt_sprite_template.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTable_ReelBackground, 0x20, ".rodata.85849C0", "data/slot_machine/jp/reel_background_subsprite_table.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTable_ReelTimeMachineAntennae, 0x14, ".rodata.85849C0", "data/slot_machine/jp/reel_time_machine_antennae_subsprite_table.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTable_ReelTimeMachine, 0x1C, ".rodata.85849C0", "data/slot_machine/jp/reel_time_machine_subsprite_table.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTable_BrokenReelTimeMachine, 0x18, ".rodata.85849C0", "data/slot_machine/jp/broken_reel_time_machine_subsprite_table.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTable_ReelTimeShadow, 0x14, ".rodata.85849C0", "data/slot_machine/jp/reel_time_shadow_subsprite_table.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTable_ReelTimeNumberGap, 0x228, ".rodata.85849C0", "data/slot_machine/jp/reel_time_number_gap_sprite_data.bin");
SLOT_MACHINE_RESOURCE(sSpriteTemplates_DigitalDisplay, 0x68, ".rodata.85849C0", "data/slot_machine/jp/digital_display_sprite_templates.bin");
SLOT_MACHINE_RESOURCE(sSubspriteTables_DigitalDisplay, 0x68, ".rodata.85849C0", "data/slot_machine/jp/digital_display_subsprite_tables.bin");
SLOT_MACHINE_RESOURCE(sSlotMachineSpriteSheets, 0xB0, ".rodata.85849C0", "data/slot_machine/jp/sprite_sheets.bin");
SLOT_MACHINE_RESOURCE(sReelBackground_Tilemap, 0xE4, ".rodata.85849C0", "data/slot_machine/jp/reel_background_runtime_data.bin");
SLOT_MACHINE_RESOURCE(gSlotMachineMenu_Pal, 0x94, ".rodata.85849C0", "graphics/slot_machine/menu.gbapal");

SLOT_MACHINE_RESOURCE(sUnusedColors, 0x14, ".rodata.85854EC", "graphics/slot_machine/unused_colors.gbapal");

SLOT_MACHINE_RESOURCE(sFlashingLightsInside_Pal, 0x20, ".rodata.8585542", "graphics/slot_machine/flashing_lights_inside.gbapal");
SLOT_MACHINE_RESOURCE(sFlashingLightsMiddle_Pal, 0x20, ".rodata.8585542", "graphics/slot_machine/flashing_lights_middle.gbapal");
SLOT_MACHINE_RESOURCE(sFlashingLightsOutside_Pal, 0x20, ".rodata.8585542", "graphics/slot_machine/flashing_lights_outside.gbapal");
SLOT_MACHINE_RESOURCE(sFlashingLightsPadding, 0x2, ".rodata.8585542", "data/slot_machine/jp/flashing_lights_padding.bin");

SLOT_MACHINE_RESOURCE(sPokeballShining0_Pal, 0x20, ".rodata.85855B4", "graphics/slot_machine/pokeball_shining_0.gbapal");
SLOT_MACHINE_RESOURCE(sPokeballShining1_Pal, 0x20, ".rodata.85855B4", "graphics/slot_machine/pokeball_shining_1.gbapal");
SLOT_MACHINE_RESOURCE(sPokeballShining2_Pal, 0x20, ".rodata.85855B4", "graphics/slot_machine/pokeball_shining_2.gbapal");
SLOT_MACHINE_RESOURCE(sPokeballShiningPalTable, 0x10, ".rodata.85855B4", "data/slot_machine/jp/pokeball_shining_palette_table.bin");
SLOT_MACHINE_RESOURCE(sDigitalDisplay_Pal, 0x4, ".rodata.85855B4", "data/slot_machine/jp/digital_display_palette_pointer.bin");
SLOT_MACHINE_RESOURCE(sUnkPalette, 0x20, ".rodata.85855B4", "data/slot_machine/jp/unknown_palette.gbapal");
SLOT_MACHINE_RESOURCE(sSlotMachineSpritePalettes, 0x48, ".rodata.85855B4", "data/slot_machine/jp/sprite_palettes.bin");
SLOT_MACHINE_RESOURCE(gSlotMachineDigitalDisplay_Gfx, 0x768, ".rodata.85855B4", "graphics/slot_machine/digital_display.4bpp.lz");
SLOT_MACHINE_RESOURCE(sReelTimeGfx, 0x1154, ".rodata.85855B4", "graphics/slot_machine/reel_time_gfx.4bpp.lz");
SLOT_MACHINE_RESOURCE(gSlotMachineMenu_Gfx, 0xBA0, ".rodata.85855B4", "graphics/slot_machine/menu.4bpp.lz");
SLOT_MACHINE_RESOURCE(gSlotMachineMenu_Tilemap, 0x4B0, ".rodata.85855B4", "graphics/slot_machine/menu.bin");

SLOT_MACHINE_RESOURCE(gSlotMachineInfoBox_Tilemap, 0x4B0, ".rodata.8588154", "graphics/slot_machine/info_box.bin");

#undef SLOT_MACHINE_RESOURCE
#undef SLOT_MACHINE_DATA

// Preserve JP labels used by still-naked Slot Machine code.
__asm__(
    ".global gUnknown_85854EC\n"
    ".set gUnknown_85854EC, sUnusedColors\n"
    ".global gUnknown_8585542\n"
    ".set gUnknown_8585542, sFlashingLightsInside_Pal\n"
    ".global gUnknown_85855B4\n"
    ".set gUnknown_85855B4, sPokeballShining0_Pal\n"
);

#endif // GUARD_DATA_SLOT_MACHINE_H
