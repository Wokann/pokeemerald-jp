	.section .rodata.battle_transition_frontier_resources, "a", %progbits

	.globl sFrontierLogo_Palette
sFrontierLogo_Palette:
	.incbin "graphics/battle_transitions/frontier_logo.gbapal"

	.globl sFrontierLogo_Tileset
sFrontierLogo_Tileset:
	.incbin "graphics/battle_transitions/frontier_logo.4bpp.lz"

	.globl sFrontierLogo_Tilemap
sFrontierLogo_Tilemap:
	.incbin "graphics/battle_transitions/frontier_logo.bin.lz"

	.globl sFrontierSquares_Palette
sFrontierSquares_Palette:
	.incbin "graphics/battle_transitions/frontier_squares_blanktiles.gbapal"

	.globl sFrontierSquares_FilledBg_Tileset
sFrontierSquares_FilledBg_Tileset:
	.incbin "graphics/battle_transitions/frontier_square_1.4bpp.lz"

	.globl sFrontierSquares_EmptyBg_Tileset
sFrontierSquares_EmptyBg_Tileset:
	.incbin "graphics/battle_transitions/frontier_square_2.4bpp.lz"

	.globl sFrontierSquares_Shrink1_Tileset
sFrontierSquares_Shrink1_Tileset:
	.incbin "graphics/battle_transitions/frontier_square_3.4bpp.lz"

	.globl sFrontierSquares_Shrink2_Tileset
sFrontierSquares_Shrink2_Tileset:
	.incbin "graphics/battle_transitions/frontier_square_4.4bpp.lz"

	.globl sFrontierSquares_Tilemap
sFrontierSquares_Tilemap:
	.incbin "graphics/battle_transitions/frontier_squares.bin"
