	.section .rodata.battle_transition_tilemap_data, "a", %progbits

	.globl sBigPokeball_Tilemap
sBigPokeball_Tilemap: @ 0x85A8AD0
	.incbin "graphics/battle_transitions/big_pokeball_map.bin"

	.globl sMugshotsTilemap
sMugshotsTilemap: @ 0x85A8F80
	.incbin "graphics/battle_transitions/elite_four_bg_map.bin"
