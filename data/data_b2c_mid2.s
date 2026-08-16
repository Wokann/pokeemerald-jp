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
	.4byte 0x085CB703, 0x085CB714, 0x085CB721, 0x085CB72E
	.4byte 0x085CB741, 0x085CB74F, 0x085CB75F, 0x085CB76C
	.4byte 0x085CB779, 0x085CB77F, 0x085CB78E, 0x085CB79C

	.globl sHelpBarTextColors
sHelpBarTextColors: @ 0x85F140C
	.byte 0x04, 0x01, 0x02, 0x00

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
	.4byte 0x085F0B24, 0x00000001
	.4byte 0x085F0C8C, 0x00000001
	.4byte 0x085F0DEC, 0x00000004
	.4byte 0x085F0F00, 0x00000001
	.4byte 0x085F1034, 0x00000002
	.4byte 0x085F116C, 0x00000000
	.4byte 0x085F1288, 0x00000000

sSpinningPokenavSpriteOam: @ 0x85F1498
	.byte 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

sSpinningPokenavAnims: @ 0x85F14A0
	.hword 0x0000, 0x0008, 0x0010, 0x0008
	.hword 0x0020, 0x0008, 0x0030, 0x0008
	.hword 0x0040, 0x0008, 0x0050, 0x0008
	.hword 0x0060, 0x0008, 0x0070, 0x0008
	.hword 0xFFFE, 0x0000

sSpinningPokenavAnimTable: @ 0x85F14C4
	.4byte sSpinningPokenavAnims

	.globl sSpinningPokenavSpriteTemplate
sSpinningPokenavSpriteTemplate: @ 0x85F14C8
	.hword 0, 0
	.4byte sSpinningPokenavSpriteOam, sSpinningPokenavAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x081C7475

sOamData_LeftHeader: @ 0x85F14E0
	.byte 0x00, 0x40, 0x00, 0xC0, 0x00, 0x04, 0x00, 0x00
sOamData_SubmenuLeftHeader: @ 0x85F14E8
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x04, 0x00, 0x00

	.globl sLeftHeaderSpriteTemplate
sLeftHeaderSpriteTemplate: @ 0x85F14F0
	.hword 0x0002, 0x0001
	.4byte sOamData_LeftHeader, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.globl sSubmenuLeftHeaderSpriteTemplate
sSubmenuLeftHeaderSpriteTemplate: @ 0x85F1508
	.hword 0x0002, 0x0002
	.4byte sOamData_SubmenuLeftHeader, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

gUnknown_85F1520: @ 0x85F1520
	.incbin "baserom_jp.gba", 0x5f1520, 0x88

	.globl sPokenavCheckPageColors
sPokenavCheckPageColors: @ 0x85F15A8
	.byte 0x00, 0x02, 0x05, 0x00

	.globl sPokenavMatchCallFieldNames
sPokenavMatchCallFieldNames: @ 0x85F15AC
	.4byte 0x085CB6EC, 0x085CB6F1, 0x085CB6FB

	.globl sPokenavFieldNameColors
sPokenavFieldNameColors: @ 0x85F15B8
	.byte 0x01, 0x04, 0x05

	.globl lineOffsets
lineOffsets: @ 0x85F15BB
	.byte 0x02, 0x04, 0x06, 0x07, 0x00

	.globl sListArrowSpriteSheets
sListArrowSpriteSheets: @ 0x85F15C0
	.4byte 0x085F1540
	.hword 0x00C0, 0x000A

	.globl sListArrowPalettes
sListArrowPalettes: @ 0x85F15C8
	.incbin "graphics/list_ui/sListArrowPalettes.bin"

	.globl sSpriteTemplate_RightArrow
sSpriteTemplate_RightArrow: @ 0x85F15E0
	.hword 0x000A, 0x0014
	.4byte 0x085F15D8, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x081C8835

sOamData_RightArrow: @ 0x85F15F8
	.byte 0x00, 0x40, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00

	.globl sSpriteTemplate_UpDownArrow
sSpriteTemplate_UpDownArrow: @ 0x85F1600
	.hword 0x000A, 0x0014
	.4byte 0x085F15F8, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

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
