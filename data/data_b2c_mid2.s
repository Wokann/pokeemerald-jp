.include "sound/MPlayDef.s"
	.section .rodata.mid2_suffix
	.include "asm/macros.inc"

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
