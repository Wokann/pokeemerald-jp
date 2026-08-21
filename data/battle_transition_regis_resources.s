	.section .rodata.battle_transition_regis_resources, "a", %progbits

	.globl sRegis_Tileset
sRegis_Tileset: @ 0x859B6C4
	.incbin "graphics/battle_transitions/regis.4bpp"

	.globl sRegice_Palette
sRegice_Palette: @ 0x859BD64
	.incbin "graphics/battle_transitions/regice.gbapal"

	.globl sRegisteel_Palette
sRegisteel_Palette: @ 0x859BD84
	.incbin "graphics/battle_transitions/registeel.gbapal"

	.globl sRegirock_Palette
sRegirock_Palette: @ 0x859BDA4
	.incbin "graphics/battle_transitions/regirock.gbapal"

	.globl sRegice_Tilemap
sRegice_Tilemap: @ 0x859BDC4
	.incbin "graphics/battle_transitions/regice.bin"

	.globl sRegisteel_Tilemap
sRegisteel_Tilemap: @ 0x859C5C4
	.incbin "graphics/battle_transitions/registeel.bin"

	.globl sRegirock_Tilemap
sRegirock_Tilemap: @ 0x859CDC4
	.incbin "graphics/battle_transitions/regirock.bin"

	.globl sUnused_Palette
sUnused_Palette: @ 0x859D5C4
	.incbin "graphics/battle_transitions/unused.gbapal"
