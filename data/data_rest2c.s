.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.section .rodata.data_rest2c_after_battle_anim_sandstorm_resources

	.section .rodata.data_rest2c_after_battle_anim_metal_sound_resources

	.section .rodata.data_rest2c_after_battle_anim_ice_resources

	.section .rodata.data_rest2c_after_contest_applause_resources

	.section .rodata.data_rest2c_after_battle_anim_splash_through_protect_resources

	.section .rodata.data_rest2c_after_battle_anim_muddy_water_resources

	.section .rodata.data_rest2c_after_enemy_shadow

	.section .rodata.data_rest2c_after_battle_interface_ball_status_bar_graphics

	.section .rodata.data_rest2c_after_egg_icon_graphics

	.section .rodata.data_rest2c_after_battle_anim_ghost_and_solarbeam_resources


	.section .rodata.data_rest2c_after_berry_blender_background_graphics
	@ The preceding Berry Blender tilemap stream is 0x311 bytes long; retain its ROM padding.
	.incbin "baserom_jp.gba", 0xD92AB1, 0x3

	.section .rodata.data_rest2c_after_battle_anim_cosmic_and_slam_hit_2_resources

	.section .rodata.data_rest2c_after_battle_anim_fog_through_cross_impact_resources


	.section .rodata.data_rest2c_after_battle_anim_surf_and_white_shadow_resources


	.section .rodata.data_rest2c_after_party_menu_and_status_icon_resources

	.section .rodata.data_rest2c_before_bag_graphics

	.section .rodata.data_rest2c_before_bag_menu_resources


	.section .rodata.data_rest2c_after_bag_menu_resources

	.section .rodata.data_rest2c_after_swap_line_graphics


	.section .rodata.data_rest2c_after_shop_menu_resources

	.section .rodata.data_rest2c_after_chases_away
	.incbin "baserom_jp.gba", 0xdab2fd, 0x3

	.section .rodata.data_rest2c_after_cable_car_bg_palette
	.incbin "baserom_jp.gba", 0xDBC236, 0x2

	.section .rodata.data_rest2c_after_cable_car_sprite_gfx


	.globl gRouletteMenu_Gfx
gRouletteMenu_Gfx: @ 0x8DBC590
	.incbin "graphics/roulette/gRouletteMenu_Gfx.bin"


	.globl gRouletteWheel_Gfx
gRouletteWheel_Gfx: @ 0x8DBCCBC
	.incbin "graphics/misc/gRouletteWheel_Gfx.4bpp.lz"
	.incbin "baserom_jp.gba", 0xDBDD61, 0x24229F
