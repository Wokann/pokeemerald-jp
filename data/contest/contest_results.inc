@ Contest Results UI data retained at its original physical address.
@ The Japanese release keeps its title tilemaps here and uses nine window
@ templates. Keep the physical order and JP bytes exact until contest_util.c
@ owns the matching rodata.

	.globl sResultsTextWindow_Pal
sResultsTextWindow_Pal: @ 0x0856915C
	.incbin "baserom_jp.gba", 0x56915c, 0x20

	.globl sResultsTextWindow_Gfx
sResultsTextWindow_Gfx: @ 0x0856917C
	.incbin "baserom_jp.gba", 0x56917c, 0x100

	.globl sMiscBlank_Pal
sMiscBlank_Pal: @ 0x0856927C
	.incbin "baserom_jp.gba", 0x56927c, 0x20

	.globl sOamData_ResultsTextWindow
sOamData_ResultsTextWindow: @ 0x0856929C
	.incbin "baserom_jp.gba", 0x56929c, 0x8

	.globl sSpriteTemplate_ResultsTextWindow
sSpriteTemplate_ResultsTextWindow: @ 0x085692A4
	.incbin "baserom_jp.gba", 0x5692a4, 0x18

	.globl sSpriteSheets_ResultsTextWindow
sSpriteSheets_ResultsTextWindow: @ 0x085692BC
	.incbin "baserom_jp.gba", 0x5692bc, 0x40

	.globl sSpritePalette_ResultsTextWindow
sSpritePalette_ResultsTextWindow: @ 0x085692FC
	.incbin "baserom_jp.gba", 0x5692fc, 0x8

	.globl sOamData_Confetti
sOamData_Confetti: @ 0x08569304
	.incbin "baserom_jp.gba", 0x569304, 0x8

	.globl sSpriteTemplate_Confetti
sSpriteTemplate_Confetti: @ 0x0856930C
	.incbin "baserom_jp.gba", 0x56930c, 0x18

	.globl sSpriteSheet_Confetti
sSpriteSheet_Confetti: @ 0x08569324
	.incbin "baserom_jp.gba", 0x569324, 0x8

	.globl sSpritePalette_Confetti
sSpritePalette_Confetti: @ 0x0856932C
	.incbin "baserom_jp.gba", 0x56932c, 0x8

	.globl gContestResultsTitle_Normal_Tilemap
gContestResultsTitle_Normal_Tilemap: @ 0x08569334
	.incbin "baserom_jp.gba", 0x569334, 0x20

	.globl gContestResultsTitle_Super_Tilemap
gContestResultsTitle_Super_Tilemap: @ 0x08569354
	.incbin "baserom_jp.gba", 0x569354, 0x20

	.globl gContestResultsTitle_Hyper_Tilemap
gContestResultsTitle_Hyper_Tilemap: @ 0x08569374
	.incbin "baserom_jp.gba", 0x569374, 0x20

	.globl gContestResultsTitle_Master_Tilemap
gContestResultsTitle_Master_Tilemap: @ 0x08569394
	.incbin "baserom_jp.gba", 0x569394, 0x20

	.globl gContestResultsTitle_Link_Tilemap
gContestResultsTitle_Link_Tilemap: @ 0x085693B4
	.incbin "baserom_jp.gba", 0x5693b4, 0x20

	.globl gContestResultsTitle_Cool_Tilemap
gContestResultsTitle_Cool_Tilemap: @ 0x085693D4
	.incbin "baserom_jp.gba", 0x5693d4, 0x14

	.globl gContestResultsTitle_Beauty_Tilemap
gContestResultsTitle_Beauty_Tilemap: @ 0x085693E8
	.incbin "baserom_jp.gba", 0x5693e8, 0x14

	.globl gContestResultsTitle_Cute_Tilemap
gContestResultsTitle_Cute_Tilemap: @ 0x085693FC
	.incbin "baserom_jp.gba", 0x5693fc, 0x14

	.globl gContestResultsTitle_Smart_Tilemap
gContestResultsTitle_Smart_Tilemap: @ 0x08569410
	.incbin "baserom_jp.gba", 0x569410, 0x14

	.globl gContestResultsTitle_Tough_Tilemap
gContestResultsTitle_Tough_Tilemap: @ 0x08569424
	.incbin "baserom_jp.gba", 0x569424, 0x14

	.globl gContestResultsTitle_Tilemap
gContestResultsTitle_Tilemap: @ 0x08569438
	.incbin "baserom_jp.gba", 0x569438, 0x14

	.globl sContestResultsBgTemplates
sContestResultsBgTemplates: @ 0x0856944C
	.incbin "baserom_jp.gba", 0x56944c, 0x10

	.globl sContestResultsWindowTemplates
sContestResultsWindowTemplates: @ 0x0856945C
	.incbin "baserom_jp.gba", 0x56945c, 0x48

	.globl sOamData_WirelessIndicatorWindow
sOamData_WirelessIndicatorWindow: @ 0x085694A4
	.incbin "baserom_jp.gba", 0x5694a4, 0x8

	.globl sSpriteTemplate_WirelessIndicatorWindow
sSpriteTemplate_WirelessIndicatorWindow: @ 0x085694AC
	.incbin "baserom_jp.gba", 0x5694ac, 0x18

	.globl sSpriteSheet_WirelessIndicatorWindow
sSpriteSheet_WirelessIndicatorWindow: @ 0x085694C4
	.incbin "baserom_jp.gba", 0x5694c4, 0x8

	.globl sContestLinkTextColors
sContestLinkTextColors: @ 0x085694CC
	.incbin "baserom_jp.gba", 0x5694cc, 0x4
