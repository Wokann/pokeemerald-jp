	.section .rodata.evolution_scene_graphics, "a", %progbits

	.globl sBgAnim_Gfx
sBgAnim_Gfx: @ 0x08593CA0
	.incbin "baserom_jp.gba", 0x593ca0, 0x6f8

	.globl sBgAnim_Inner_Tilemap
sBgAnim_Inner_Tilemap: @ 0x08594398
	.incbin "baserom_jp.gba", 0x594398, 0x4e4

	.globl sBgAnim_Outer_Tilemap
sBgAnim_Outer_Tilemap: @ 0x0859487C
	.incbin "baserom_jp.gba", 0x59487c, 0x4d4

	.globl sBgAnim_Intro_Pal
sBgAnim_Intro_Pal: @ 0x08594D50
	.incbin "baserom_jp.gba", 0x594d50, 0x200

	.globl sUnusedPal2
sUnusedPal2: @ 0x08594F50
	.incbin "baserom_jp.gba", 0x594f50, 0x160

	.globl sUnusedPal3
sUnusedPal3: @ 0x085950B0
	.incbin "baserom_jp.gba", 0x5950b0, 0x1a0

	.globl sUnusedPal4
sUnusedPal4: @ 0x08595250
	.incbin "baserom_jp.gba", 0x595250, 0x1a0

	.globl sBgAnim_Pal
sBgAnim_Pal: @ 0x085953F0
	.incbin "baserom_jp.gba", 0x5953f0, 0x40

	.section .rodata.evolution_scene_palette_tables, "a", %progbits
	.globl sBgAnim_PaletteControl
sBgAnim_PaletteControl: @ 0x08595475
	.incbin "baserom_jp.gba", 0x595475, 0x10

	.globl sBgAnim_PalIndexes
sBgAnim_PalIndexes: @ 0x08595485
	.incbin "baserom_jp.gba", 0x595485, 0x320
