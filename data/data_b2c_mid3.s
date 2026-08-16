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

	.globl sPokenavOptionsSpritePalettes
sPokenavOptionsSpritePalettes: @ 0x85F273C
	.incbin "graphics/pokenav/sPokenavOptionsSpritePalettes.bin"

	.globl sPokenavMenuOptionLabelGfx
sPokenavMenuOptionLabelGfx: @ 0x85F27A8
	.incbin "graphics/pokenav/sPokenavMenuOptionLabelGfx.bin"

	.globl gUnknown_85F27AC
gUnknown_85F27AC: @ 0x85F27AC
	.incbin "baserom_jp.gba", 0x5f27ac, 0x88

	.globl sOptionDescWindowTemplate
sOptionDescWindowTemplate: @ 0x85F2834
	.incbin "baserom_jp.gba", 0x5f2834, 0x8

	.globl sPageDescriptions
sPageDescriptions: @ 0x85F283C
	.incbin "baserom_jp.gba", 0x5f283c, 0x38

	.globl sOptionDescTextColors
sOptionDescTextColors: @ 0x85F2874
	.incbin "baserom_jp.gba", 0x5f2874, 0x3

	.globl sOptionDescTextColors2
sOptionDescTextColors2: @ 0x85F2877
	.incbin "baserom_jp.gba", 0x5f2877, 0x3d

	.globl sMenuOptionSpriteTemplate
sMenuOptionSpriteTemplate: @ 0x85F28B4
	.incbin "baserom_jp.gba", 0x5f28b4, 0x20

	.globl sMatchCallBlueLightSpriteTemplate
sMatchCallBlueLightSpriteTemplate: @ 0x85F28D4
	.incbin "baserom_jp.gba", 0x5f28d4, 0x18

	.globl sPokenavMainMenuScanlineEffectParams
sPokenavMainMenuScanlineEffectParams: @ 0x85F28EC
	.incbin "baserom_jp.gba", 0x5f28ec, 0x10c8

	.globl gMatchCallFlavorTexts
gMatchCallFlavorTexts: @ 0x85F39B4
	.incbin "baserom_jp.gba", 0x5f39b4, 0x4e0
