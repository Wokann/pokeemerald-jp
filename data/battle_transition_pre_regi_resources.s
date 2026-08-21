	.section .rodata.battle_transition_pre_regi_resources, "a", %progbits

	.globl sBigPokeball_Tileset
sBigPokeball_Tileset:
	.incbin "graphics/battle_transitions/big_pokeball.4bpp"

	.globl sPokeballTrail_Tileset
sPokeballTrail_Tileset:
	.incbin "graphics/battle_transitions/pokeball_trail.4bpp"

	.globl sPokeball_Gfx
sPokeball_Gfx:
	.incbin "graphics/battle_transitions/pokeball.4bpp"

	.globl sEliteFour_Tileset
sEliteFour_Tileset:
	.incbin "graphics/battle_transitions/elite_four_bg.4bpp"

	.globl sUnusedBrendan_Gfx
sUnusedBrendan_Gfx:
	.incbin "graphics/battle_transitions/unused_brendan.4bpp"

	.globl sUnusedLass_Gfx
sUnusedLass_Gfx:
	.incbin "graphics/battle_transitions/unused_lass.4bpp"

	.globl sShrinkingBoxTileset
sShrinkingBoxTileset:
	.incbin "graphics/battle_transitions/shrinking_box.4bpp"

	.globl sEvilTeam_Palette
sEvilTeam_Palette:
	.incbin "graphics/battle_transitions/evil_team.gbapal"

	.globl sTeamAqua_Tileset
sTeamAqua_Tileset:
	.incbin "graphics/battle_transitions/team_aqua.4bpp.lz"

	.globl sTeamAqua_Tilemap
sTeamAqua_Tilemap:
	.incbin "graphics/battle_transitions/team_aqua.bin.lz"

	.globl sTeamMagma_Tileset
sTeamMagma_Tileset:
	.incbin "graphics/battle_transitions/team_magma.4bpp.lz"

	.globl sTeamMagma_Tilemap
sTeamMagma_Tilemap:
	.incbin "graphics/battle_transitions/team_magma.bin.lz"
