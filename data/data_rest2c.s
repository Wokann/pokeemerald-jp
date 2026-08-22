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
	.globl gBattleVSFrame_Gfx
gBattleVSFrame_Gfx: @ 0x8D77994
	.incbin "graphics/misc/gBattleVSFrame_Gfx.bin"


	.globl gBattleVSFrame_Tilemap
gBattleVSFrame_Tilemap: @ 0x8D77A7C
	.incbin "graphics/misc/gBattleVSFrame_Tilemap.bin"


	.globl gBattleVSFrame_Pal
gBattleVSFrame_Pal: @ 0x8D77B88
	.incbin "graphics/misc/gBattleVSFrame_Pal.bin"


	.globl gVsLettersGfx
gVsLettersGfx: @ 0x8D77BB0
	.incbin "graphics/battle_transitions/vs.4bpp.lz"

	.section .rodata.data_rest2c_after_battle_environment_graphics

	.globl gUnknown_8D82FB4
gUnknown_8D82FB4: @ 0x8D82FB4
	.incbin "graphics/misc/gUnknown_8D82FB4.4bpp.lz"


	.globl gUnknown_8D835A0
gUnknown_8D835A0: @ 0x8D835A0
	.incbin "graphics/misc/gUnknown_8D835A0.4bpp.lz"


	.globl gUnknown_8D839A4
gUnknown_8D839A4: @ 0x8D839A4
	.incbin "graphics/misc/gUnknown_8D839A4.4bpp.lz"


	.globl gUnknown_8D83BD0
gUnknown_8D83BD0: @ 0x8D83BD0
	.incbin "graphics/misc/gUnknown_8D83BD0.4bpp.lz"


	.globl gUnknown_8D83CE0
gUnknown_8D83CE0: @ 0x8D83CE0
	.incbin "graphics/misc/gUnknown_8D83CE0.4bpp.lz"


	.globl gUnknown_8D83DF4
gUnknown_8D83DF4: @ 0x8D83DF4
	.incbin "graphics/misc/gUnknown_8D83DF4.4bpp.lz"


	.globl gUnknown_8D84A08
gUnknown_8D84A08: @ 0x8D84A08
	.incbin "graphics/misc/gUnknown_8D84A08.4bpp.lz"


	.globl gUnknown_8D84F98
gUnknown_8D84F98: @ 0x8D84F98
	.incbin "graphics/misc/gUnknown_8D84F98.4bpp.lz"
	.incbin "baserom_jp.gba", 0xD850F0, 0x24C


	.globl gUnknown_8D8533C
gUnknown_8D8533C: @ 0x8D8533C
	.incbin "graphics/misc/gUnknown_8D8533C.4bpp.lz"


	.globl gUnknown_8D85428
gUnknown_8D85428: @ 0x8D85428
	.incbin "graphics/misc/gUnknown_8D85428.4bpp.lz"


	.globl gUnknown_8D854AC
gUnknown_8D854AC: @ 0x8D854AC
	.incbin "graphics/misc/gUnknown_8D854AC.4bpp.lz"
	.incbin "baserom_jp.gba", 0xD854C9, 0x103


	.globl gUnknown_8D855CC
gUnknown_8D855CC: @ 0x8D855CC
	.incbin "graphics/misc/gUnknown_8D855CC.4bpp.lz"


	.globl gBattleWindowTextPalette
gBattleWindowTextPalette: @ 0x8D855E4
	.incbin "graphics/misc/gBattleWindowTextPalette.bin"


	.globl gUnknown_8D85604
gUnknown_8D85604: @ 0x8D85604
	.incbin "baserom_jp.gba", 0xd85604, 0x2


	.globl gUnknown_8D85606
gUnknown_8D85606: @ 0x8D85606
	.incbin "baserom_jp.gba", 0xd85606, 0xa6


	.globl gUnknown_8D856AC
gUnknown_8D856AC: @ 0x8D856AC
	.incbin "baserom_jp.gba", 0xd856ac, 0xe0


	.globl gMultiBattleIntroBg_Opponent_Tilemap
gMultiBattleIntroBg_Opponent_Tilemap: @ 0x8D8578C
	.incbin "graphics/misc/gMultiBattleIntroBg_Opponent_Tilemap.bin"


	.globl gMultiBattleIntroBg_Player_Tilemap
gMultiBattleIntroBg_Player_Tilemap: @ 0x8D85A00
	.incbin "graphics/misc/gMultiBattleIntroBg_Player_Tilemap.bin"


	.globl gUnknown_8D85C34
gUnknown_8D85C34: @ 0x8D85C34
	.incbin "baserom_jp.gba", 0xd85c34, 0x20

	.section .rodata.data_rest2c_after_intro_scene_2_player_palette


	.globl gUnknown_8D85C74
gUnknown_8D85C74: @ 0x8D85C74
	.incbin "baserom_jp.gba", 0xd85c74, 0x40


	.globl gUnknown_8D85CB4
gUnknown_8D85CB4: @ 0x8D85CB4
	.incbin "baserom_jp.gba", 0xd85cb4, 0x182


	.globl gUnknown_8D85E36
gUnknown_8D85E36: @ 0x8D85E36
	.incbin "baserom_jp.gba", 0xd85e36, 0xa


	.globl gUnknown_8D85E40
gUnknown_8D85E40: @ 0x8D85E40
	.incbin "baserom_jp.gba", 0xd85e40, 0x16


	.globl gUnknown_8D85E56
gUnknown_8D85E56: @ 0x8D85E56
	.incbin "baserom_jp.gba", 0xd85e56, 0xa


	.globl gUnknown_8D85E60
gUnknown_8D85E60: @ 0x8D85E60
	.incbin "baserom_jp.gba", 0xd85e60, 0x54


	.section .rodata.data_rest2c_after_intro_scene_2_character_graphics


	.section .rodata.data_rest2c_after_intro_scene_3_graphics


	.section .rodata.data_rest2c_after_intro_scene_3_lightning_graphics

	.section .rodata.data_rest2c_after_intro_scene_3_rayquaza_graphics

	.globl gUnknown_8D8CF26
gUnknown_8D8CF26: @ 0x8D8CF26
	.incbin "baserom_jp.gba", 0xD8CF26, 0x2


	.section .rodata.data_rest2c_after_intro_scene_3_bubbles_graphics


	.section .rodata.data_rest2c_after_intro_scene_1_effects_graphics


	.section .rodata.data_rest2c_after_battle_anim_sandstorm_resources

	.section .rodata.data_rest2c_after_battle_anim_metal_sound_resources

	.section .rodata.data_rest2c_after_battle_anim_ice_resources

	.section .rodata.data_rest2c_after_contest_next_turn_resources
	.incbin "baserom_jp.gba", 0xD8EA1C, 0x90

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
	.incbin "baserom_jp.gba", 0xDAB2FD, 0xF4C3

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
