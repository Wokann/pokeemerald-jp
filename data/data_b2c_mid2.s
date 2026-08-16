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

	.globl gPokenavHeader_Pal
gPokenavHeader_Pal: @ 0x85EF9E0
	.incbin "graphics/pokenav/gPokenavHeader_Pal.bin"

	.globl gPokenavHeader_Gfx
gPokenavHeader_Gfx: @ 0x85EFA00
	.incbin "graphics/pokenav/gPokenavHeader_Gfx.bin"

	.globl gPokenavHeader_Tilemap
gPokenavHeader_Tilemap: @ 0x85EFC2C
	.incbin "graphics/pokenav/gPokenavHeader_Tilemap.bin"

	.globl gPokenavLeftHeader_Pal
gPokenavLeftHeader_Pal: @ 0x85F021C
	.incbin "graphics/pokenav/gPokenavLeftHeader_Pal.bin"

	.globl gPokenavMainMenuBgTemplates
gPokenavMainMenuBgTemplates: @ 0x85F13C8
	.byte 0x50, 0x00, 0x00, 0x00

	.globl sHelpBarWindowTemplate
sHelpBarWindowTemplate: @ 0x85F13CC
	.byte 0x00, 0x01, 0x16, 0x10, 0x02, 0x00, 0x36, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sHelpBarTexts
sHelpBarTexts: @ 0x85F13DC
	.incbin "baserom_jp.gba", 0x5f13dc, 0x30

	.globl sHelpBarTextColors
sHelpBarTextColors: @ 0x85F140C
	.incbin "baserom_jp.gba", 0x5f140c, 0x4

	.globl sSpinningPokenavSpriteSheet
sSpinningPokenavSpriteSheet: @ 0x85F1410
	.4byte 0x085EFDC8
	.hword 0x1000, 0

	.globl sSpinningNavgearPalettes
sSpinningNavgearPalettes: @ 0x85F1418
	.incbin "graphics/misc/sSpinningNavgearPalettes.bin"

	.globl sMenuLeftHeaderSpriteSheet
sMenuLeftHeaderSpriteSheet: @ 0x85F1428
	.4byte 0x085F08B0
	.hword 0x0C00, 0x0002

	.globl sMenuLeftHeaderSpriteSheets
sMenuLeftHeaderSpriteSheets: @ 0x85F1430
	.4byte 0x085F02BC
	.hword 0x0020, 0x0003
	.4byte 0x085F073C
	.hword 0x0020, 0x0001
	.4byte 0x085F0598
	.hword 0x0020, 0x0002
	.4byte 0x085F0428
	.hword 0x0020, 0x0004
	.4byte 0x085F08B0
	.hword 0x0020, 0x0000
	.4byte 0x085F08B0
	.hword 0x0040, 0x0000

	.globl sPokenavSubMenuLeftHeaderSpriteSheets
sPokenavSubMenuLeftHeaderSpriteSheets: @ 0x85F1460
	.incbin "baserom_jp.gba", 0x5f1460, 0x68

	.globl sSpinningPokenavSpriteTemplate
sSpinningPokenavSpriteTemplate: @ 0x85F14C8
	.incbin "baserom_jp.gba", 0x5f14c8, 0x28

	.globl sLeftHeaderSpriteTemplate
sLeftHeaderSpriteTemplate: @ 0x85F14F0
	.incbin "baserom_jp.gba", 0x5f14f0, 0x18

	.globl sSubmenuLeftHeaderSpriteTemplate
sSubmenuLeftHeaderSpriteTemplate: @ 0x85F1508
	.incbin "baserom_jp.gba", 0x5f1508, 0xa0

	.globl sPokenavCheckPageColors
sPokenavCheckPageColors: @ 0x85F15A8
	.byte 0x00, 0x02, 0x05, 0x00

	.globl sPokenavMatchCallFieldNames
sPokenavMatchCallFieldNames: @ 0x85F15AC
	.incbin "baserom_jp.gba", 0x5f15ac, 0xc

	.globl sPokenavFieldNameColors
sPokenavFieldNameColors: @ 0x85F15B8
	.byte 0x01, 0x04, 0x05

	.globl lineOffsets
lineOffsets: @ 0x85F15BB
	.byte 0x02, 0x04, 0x06, 0x07, 0x00

	.globl sListArrowSpriteSheets
sListArrowSpriteSheets: @ 0x85F15C0
	.incbin "baserom_jp.gba", 0x5f15c0, 0x8

	.globl sListArrowPalettes
sListArrowPalettes: @ 0x85F15C8
	.incbin "graphics/list_ui/sListArrowPalettes.bin"

	.globl sSpriteTemplate_RightArrow
sSpriteTemplate_RightArrow: @ 0x85F15E0
	.incbin "baserom_jp.gba", 0x5f15e0, 0x20

	.globl sSpriteTemplate_UpDownArrow
sSpriteTemplate_UpDownArrow: @ 0x85F1600
	.incbin "baserom_jp.gba", 0x5f1600, 0x18

	.globl sLastCursorPositions
sLastCursorPositions: @ 0x85F1618
	.byte 0x02, 0x03, 0x04, 0x02, 0x05

	.globl sMenuItems
sMenuItems: @ 0x85F161D
	.byte 0x00, 0x01, 0x04, 0x04, 0x04, 0x04, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x04, 0x05, 0x06, 0x07, 0x04, 0x04, 0x04
	.byte 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00

	.globl sPokenavBgDotsPal
sPokenavBgDotsPal: @ 0x85F163C
	.hword 0x0000

	.globl gUnknown_85F163E
gUnknown_85F163E: @ 0x85F163E
	.incbin "baserom_jp.gba", 0x5f163e, 0xc

	.globl gUnknown_85F164A
gUnknown_85F164A: @ 0x85F164A
	.incbin "baserom_jp.gba", 0x5f164a, 0x12

	.globl sPokenavBgDotsTiles
sPokenavBgDotsTiles: @ 0x85F165C
	.incbin "graphics/pokenav/sPokenavBgDotsTiles.bin"

	.globl sPokenavBgDotsTilemap
sPokenavBgDotsTilemap: @ 0x85F1670
	.incbin "graphics/pokenav/sPokenavBgDotsTilemap.bin"

	.globl gPokenavMessageBox_Pal
gPokenavMessageBox_Pal: @ 0x85F1710
	.incbin "graphics/pokenav/gPokenavMessageBox_Pal.bin"

	.globl gPokenavMessageBox_Gfx
gPokenavMessageBox_Gfx: @ 0x85F1730
	.incbin "graphics/pokenav/gPokenavMessageBox_Gfx.bin"

	.globl gPokenavMessageBox_Tilemap
gPokenavMessageBox_Tilemap: @ 0x85F1780
	.incbin "graphics/pokenav/gPokenavMessageBox_Tilemap.bin"

	.globl sPokenavDeviceBgPal
sPokenavDeviceBgPal: @ 0x85F1838
	.hword 0x7FFF, 0x1595, 0x4A55, 0x56B6, 0x3B1F, 0x31FE, 0x6694, 0x798C, 0x7FFF, 0x7EC1, 0x0000, 0x0000
	.hword 0x0000, 0x0000, 0x6B39, 0x5EB5

	.globl sPokenavDeviceBgTiles
sPokenavDeviceBgTiles: @ 0x85F1858
	.incbin "graphics/pokenav/sPokenavDeviceBgTiles.bin"

	.globl sPokenavDeviceBgTilemap
sPokenavDeviceBgTilemap: @ 0x85F1AE0
	.incbin "graphics/pokenav/sPokenavDeviceBgTilemap.bin"
	.balign 4

	.globl gPokenavOptions_Pal
gPokenavOptions_Pal: @ 0x85F1BF0
	.incbin "graphics/pokenav/gPokenavOptions_Pal.bin"

	.globl gPokenavOptions_Gfx
gPokenavOptions_Gfx: @ 0x85F1C90
	.incbin "graphics/pokenav/gPokenavOptions_Gfx.bin"
	.balign 4

	.globl sMatchCallBlueLightPal
sMatchCallBlueLightPal: @ 0x85F266C
	.incbin "graphics/pokenav/sMatchCallBlueLightPal.bin"

	.globl sMatchCallBlueLightTiles
sMatchCallBlueLightTiles: @ 0x85F268C
	.incbin "graphics/pokenav/sMatchCallBlueLightTiles.bin"
