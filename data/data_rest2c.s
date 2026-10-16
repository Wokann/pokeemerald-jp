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

	.section .rodata.data_rest2c_after_battle_anim_sandstorm_resources

	.section .rodata.data_rest2c_after_battle_anim_metal_sound_resources

	.section .rodata.data_rest2c_after_battle_anim_ice_resources

	.section .rodata.data_rest2c_after_contest_next_turn_resources
	.globl gBattleAnimSpriteGfx_GlowyRedOrb
gBattleAnimSpriteGfx_GlowyRedOrb: @ 0x08D8EA1C
	.incbin "baserom_jp.gba", 0xd8ea1c, 0x20
	.globl gBattleAnimSpritePal_GlowyRedOrb
gBattleAnimSpritePal_GlowyRedOrb: @ 0x08D8EA3C
	.incbin "baserom_jp.gba", 0xd8ea3c, 0x18
	.globl gBattleAnimSpritePal_GlowyGreenOrb
gBattleAnimSpritePal_GlowyGreenOrb: @ 0x08D8EA54
	.incbin "baserom_jp.gba", 0xd8ea54, 0x18
	.globl gBattleAnimSpritePal_SleepPowder
gBattleAnimSpritePal_SleepPowder: @ 0x08D8EA6C
	.incbin "baserom_jp.gba", 0xd8ea6c, 0x20
	.globl gBattleAnimSpritePal_StunSpore
gBattleAnimSpritePal_StunSpore: @ 0x08D8EA8C
	.incbin "baserom_jp.gba", 0xd8ea8c, 0x20

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

gItemIcon_QuestionMark:: @ 0x08DAB300
	.incbin "baserom_jp.gba", 0xdab300, 0x78

gItemIconPalette_QuestionMark:: @ 0x08DAB378
	.incbin "baserom_jp.gba", 0xdab378, 0x14

	.incbin "baserom_jp.gba", 0xdab38c, 0xc9bc

	.section .rodata.data_rest2c_after_decoration_icons
	.globl gBattleAnimSpritePal_Shock3
gBattleAnimSpritePal_Shock3: @ 0x08DBA3F4
	.incbin "baserom_jp.gba", 0xdba3f4, 0x28
	.globl gBattleAnimSpriteGfx_Shock3
gBattleAnimSpriteGfx_Shock3: @ 0x08DBA41C
	.incbin "baserom_jp.gba", 0xdba41c, 0x1e8
	.globl gBattleAnimSpritePal_WhiteFeather
gBattleAnimSpritePal_WhiteFeather: @ 0x08DBA604
	.incbin "baserom_jp.gba", 0xdba604, 0x1c
	.globl gBattleAnimSpriteGfx_WhiteFeather
gBattleAnimSpriteGfx_WhiteFeather: @ 0x08DBA620
	.incbin "baserom_jp.gba", 0xdba620, 0x128
	.globl gBattleAnimSpritePal_Sparkle6
gBattleAnimSpritePal_Sparkle6: @ 0x08DBA748
	.incbin "baserom_jp.gba", 0xdba748, 0x18
	.globl gBattleAnimSpriteGfx_Sparkle6
gBattleAnimSpriteGfx_Sparkle6: @ 0x08DBA760
	.incbin "baserom_jp.gba", 0xdba760, 0x60

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
