#ifndef GUARD_DATA_FRONTIER_PASS_H
#define GUARD_DATA_FRONTIER_PASS_H

// This is the contiguous Frontier Pass block formerly embedded in
// data_b2d_mid56.s.  Some streams differ from the US build, so JP-specific
// tables remain raw while confirmed assets use the standard pret hierarchy.
#define FRONTIER_PASS_MID56_DATA __attribute__((section(".rodata.frontier_pass_mid56"), aligned(1)))
#define FRONTIER_PASS_MID56_RESOURCE(symbol, size, path) \
    const u8 symbol[size] FRONTIER_PASS_MID56_DATA = INCBIN_U8(path)
#define FRONTIER_PASS_MID56_PADDING(symbol, size) \
    const u8 symbol[size] FRONTIER_PASS_MID56_DATA = {0}

// Graphics.c-owned Frontier Pass resources and the two player-head palettes.
FRONTIER_PASS_MID56_RESOURCE(gUnknown_85467E4, 0x100, "graphics/frontier_pass/bg.gbapal");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56CursorPal, 0x20, "graphics/frontier_pass/cursor.gbapal");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56MapCursorPal, 0x20, "graphics/frontier_pass/map_cursor.gbapal");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56MedalsSilverPal, 0x20, "graphics/frontier_pass/silver.gbapal");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56MedalsGoldPal, 0x20, "graphics/frontier_pass/gold.gbapal");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56MaleHeadPal, 0x20, "graphics/frontier_pass/map_heads.gbapal");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56FemaleHeadPal, 0x20, "graphics/frontier_pass/map_heads_female.gbapal");

FRONTIER_PASS_MID56_RESOURCE(gUnknown_85469A4, 0x17C3, "graphics/frontier_pass/bg.4bpp.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56BgGfxPadding, 0x1);

// Frontier Pass screen and sprite graphics.  Explicit padding reproduces the
// original four-byte boundaries without relying on compiler layout choices.
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8548168, 0xFE9, "graphics/frontier_pass/map_screen.4bpp.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56MapScreenGfxPadding, 0x3);
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56CursorGfx, 0x99, "graphics/frontier_pass/cursor.4bpp.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56CursorGfxPadding, 0x3);
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56MedalsGfx, 0x262, "graphics/frontier_pass/medals.4bpp.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56MedalsGfxPadding, 0x2);
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56HeadsGfx, 0xBC, "graphics/frontier_pass/map_heads.4bpp.lz");
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56MapCursorGfx, 0xFF, "graphics/frontier_pass/map_cursor.4bpp.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56MapCursorGfxPadding, 0x1);
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8549610, 0x2E7, "graphics/frontier_pass/bg.bin.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56BgTilemapPadding, 0x1);

FRONTIER_PASS_MID56_RESOURCE(gUnknown_85498F8, 0x25D, "graphics/frontier_pass/map_screen.bin.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56MapScreenTilemapPadding, 0x3);
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8549B58, 0x237, "graphics/frontier_pass/small_map_and_card.bin.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56SmallMapTilemapPadding, 0x1);
FRONTIER_PASS_MID56_RESOURCE(sFrontierPassMid56CardBallFilledTilemap, 0x28, "graphics/frontier_pass/card_ball_filled.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8549DB8, 0x18, "graphics/frontier_pass/cancel.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8549DD0, 0x18, "graphics/frontier_pass/cancel_highlighted.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8549DE8, 0x38, "graphics/frontier_pass/record_frame.bin.lz");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_8549E20, 0xFFC, "graphics/frontier_pass/map_and_card.8bpp.lz");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AE1C, 0xE6, "graphics/frontier_pass/small_map_and_card_affine.bin.lz");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56AffineTilemapPadding, 0x2);

// JP Frontier Pass layout, sprite and text tables.  These are retained as raw
// data until the matching Frontier Pass routines are safely converted to C.
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF04, 0x8, "data/frontier_pass/jp/bg_affine_coords.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF0C, 0xC, "data/frontier_pass/jp/pass_bg_templates.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF18, 0xC, "data/frontier_pass/jp/map_bg_templates.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF24, 0x28, "data/frontier_pass/jp/pass_window_templates.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF4C, 0x20, "data/frontier_pass/jp/map_window_templates.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF6C, 0x3, "data/frontier_pass/jp/text_colors_00.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF6F, 0x3, "data/frontier_pass/jp/text_colors_01.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF72, 0x3, "data/frontier_pass/jp/text_colors_02.bin");
FRONTIER_PASS_MID56_PADDING(sFrontierPassMid56TextColorsPadding, 0x3);
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AF78, 0x68, "data/frontier_pass/jp/pass_areas_layout.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AFE0, 0x18, "data/frontier_pass/jp/cursor_sprite_sheets.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854AFF8, 0x10, "data/frontier_pass/jp/heads_sprite_sheet.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854B008, 0xD0, "data/frontier_pass/jp/sprite_animation_data.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854B0D8, 0x30, "data/frontier_pass/jp/cursor_sprite_templates.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854B108, 0x18, "data/frontier_pass/jp/medal_sprite_template.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854B120, 0x18, "data/frontier_pass/jp/player_head_sprite_template.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854B138, 0x3C, "data/frontier_pass/jp/pass_area_descriptions.bin");
FRONTIER_PASS_MID56_RESOURCE(gUnknown_854B174, 0x70, "data/frontier_pass/jp/map_landmarks.bin");

#undef FRONTIER_PASS_MID56_PADDING
#undef FRONTIER_PASS_MID56_RESOURCE
#undef FRONTIER_PASS_MID56_DATA

#endif // GUARD_DATA_FRONTIER_PASS_H
