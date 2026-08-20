#ifndef GUARD_DATA_SLOT_MACHINE_H
#define GUARD_DATA_SLOT_MACHINE_H

// JP Slot Machine data retained in its original per-section ROM order.
// Structured pointer tables remain raw while their referenced C functions and
// assets are still being independently decompiled.

#define SLOT_MACHINE_DATA(sectionName) __attribute__((section(sectionName), aligned(1)))
#define SLOT_MACHINE_RESOURCE(symbol, size, sectionName, path) \
    const u8 symbol[size] SLOT_MACHINE_DATA(sectionName) = INCBIN_U8(path)

SLOT_MACHINE_RESOURCE(sDigitalDisplayRegBonusDelays, 0x10, ".rodata", "data/slot_machine/jp/digital_display_reg_bonus_delays.bin");
SLOT_MACHINE_RESOURCE(sDigitalDisplayBigBonusOffsets, 0x10, ".rodata", "data/slot_machine/jp/digital_display_big_bonus_offsets.bin");

SLOT_MACHINE_RESOURCE(sInitialReelPositions, 0xC, ".rodata.8584638", "data/slot_machine/jp/initial_reel_positions.bin");
SLOT_MACHINE_RESOURCE(sSpecialDrawOdds, 0x12, ".rodata.8584638", "data/slot_machine/jp/special_draw_odds.bin");
SLOT_MACHINE_RESOURCE(sBiasProbabilities_Special, 0x12, ".rodata.8584638", "data/slot_machine/jp/bias_probabilities_special.bin");
SLOT_MACHINE_RESOURCE(sBiasProbabilities_Regular, 0x1E, ".rodata.8584638", "data/slot_machine/jp/bias_probabilities_regular.bin");
SLOT_MACHINE_RESOURCE(sReelTimeProbabilities_NormalGame, 0x66, ".rodata.8584638", "data/slot_machine/jp/reel_time_probabilities_normal_game.bin");
SLOT_MACHINE_RESOURCE(sReelTimeProbabilities_LuckyGame, 0x66, ".rodata.8584638", "data/slot_machine/jp/reel_time_probabilities_lucky_game.bin");

SLOT_MACHINE_RESOURCE(sReelTimeSpeed_Probabilities, 0x14, ".rodata.858475C", "data/slot_machine/jp/reel_time_speed_probabilities.bin");
SLOT_MACHINE_RESOURCE(sQuarterSpeed_ProbabilityBoost, 0xA, ".rodata.858475C", "data/slot_machine/jp/quarter_speed_probability_boost.bin");

SLOT_MACHINE_RESOURCE(sBiasesSpecial, 0x6, ".rodata.8584782", "data/slot_machine/jp/biases_special.bin");
SLOT_MACHINE_RESOURCE(sBiasesRegular, 0xA, ".rodata.8584782", "data/slot_machine/jp/biases_regular.bin");

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
