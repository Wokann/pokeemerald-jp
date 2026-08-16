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
	.byte 0x01, 0x04, 0x11, 0x16, 0x02, 0x01, 0x08, 0x00

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
	.hword 0x0003, 0x0004
	.4byte 0x085F287C, gDummySpriteAnimTable
	.4byte 0, 0x085F28AC, 0x08007141

sOamData_MatchCallBlueLight: @ 0x85F28CC
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.globl sMatchCallBlueLightSpriteTemplate
sMatchCallBlueLightSpriteTemplate: @ 0x85F28D4
	.hword 0x0001, 0x0003
	.4byte sOamData_MatchCallBlueLight, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.globl sPokenavMainMenuScanlineEffectParams
sPokenavMainMenuScanlineEffectParams: @ 0x85F28EC
	.incbin "baserom_jp.gba", 0x5f28ec, 0x10c8

	.globl gMatchCallFlavorTexts
gMatchCallFlavorTexts: @ 0x85F39B4
	.incbin "baserom_jp.gba", 0x5f39b4, 0x4e0
