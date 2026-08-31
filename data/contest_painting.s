	.section .rodata

	.globl sContestPaintingFramePalettes
sContestPaintingFramePalettes: @ 0x85886AC
	.incbin "baserom_jp.gba", 0x5886ac, 0x200

	.globl sContestPaintingFrameTiles_Cool
sContestPaintingFrameTiles_Cool: @ 0x85888AC
	.incbin "baserom_jp.gba", 0x5888ac, 0x1084

	.globl sContestPaintingFrameTiles_Beauty
sContestPaintingFrameTiles_Beauty: @ 0x8589930
	.incbin "baserom_jp.gba", 0x589930, 0xc30

	.globl sContestPaintingFrameTiles_Cute
sContestPaintingFrameTiles_Cute: @ 0x858A560
	.incbin "baserom_jp.gba", 0x58a560, 0xb38

	.globl sContestPaintingFrameTiles_Smart
sContestPaintingFrameTiles_Smart: @ 0x858B098
	.incbin "baserom_jp.gba", 0x58b098, 0xfb8

	.globl sContestPaintingFrameTiles_Tough
sContestPaintingFrameTiles_Tough: @ 0x858C050
	.incbin "baserom_jp.gba", 0x58c050, 0x1130

	.globl sContestPaintingFrameTiles_HallLobby
sContestPaintingFrameTiles_HallLobby: @ 0x858D180
	.incbin "baserom_jp.gba", 0x58d180, 0x604

	.globl sContestPaintingFrameTilemap_Cool
sContestPaintingFrameTilemap_Cool: @ 0x858D784
	.incbin "baserom_jp.gba", 0x58d784, 0x50c

	.globl sContestPaintingFrameTilemap_Beauty
sContestPaintingFrameTilemap_Beauty: @ 0x858DC90
	.incbin "baserom_jp.gba", 0x58dc90, 0x50c

	.globl sContestPaintingFrameTilemap_Cute
sContestPaintingFrameTilemap_Cute: @ 0x858E19C
	.incbin "baserom_jp.gba", 0x58e19c, 0x50c

	.globl sContestPaintingFrameTilemap_Smart
sContestPaintingFrameTilemap_Smart: @ 0x858E6A8
	.incbin "baserom_jp.gba", 0x58e6a8, 0x50c

	.globl sContestPaintingFrameTilemap_Tough
sContestPaintingFrameTilemap_Tough: @ 0x858EBB4
	.incbin "baserom_jp.gba", 0x58ebb4, 0x50c

	.globl sContestPaintingFrameTilemap_HallLobby
sContestPaintingFrameTilemap_HallLobby: @ 0x858F0C0
	.incbin "baserom_jp.gba", 0x58f0c0, 0x510

	.globl sContestPaintingCategoryNames_Unused
sContestPaintingCategoryNames_Unused: @ 0x858F5D0
	.4byte gContestCoolness, gContestBeauty, gContestCuteness, gContestSmartness, gContestToughness

	.globl sContestPaintingRankNames
sContestPaintingRankNames: @ 0x858F5E4
	.4byte gContestRankNormal, gContestRankSuper, gContestRankHyper, gContestRankMaster, gContestLink

	.globl sContestPaintingBgTemplates
sContestPaintingBgTemplates: @ 0x858F5F8
	.incbin "baserom_jp.gba", 0x58f5f8, 0x4

	.globl sContestPaintingWindowTemplate
sContestPaintingWindowTemplate: @ 0x858F5FC
	.incbin "baserom_jp.gba", 0x58f5fc, 0x8

	.globl sContestPaintingMuseumCaptions
sContestPaintingMuseumCaptions: @ 0x858F604
	.4byte gContestPaintingCool1, gContestPaintingCool2, gContestPaintingCool3
	.4byte gContestPaintingBeauty1, gContestPaintingBeauty2, gContestPaintingBeauty3
	.4byte gContestPaintingCute1, gContestPaintingCute2, gContestPaintingCute3
	.4byte gContestPaintingSmart1, gContestPaintingSmart2, gContestPaintingSmart3
	.4byte gContestPaintingTough1, gContestPaintingTough2, gContestPaintingTough3

	.globl sContestPaintingMonOamData
sContestPaintingMonOamData: @ 0x858F640
	.incbin "baserom_jp.gba", 0x58f640, 0x8

	.globl sContestPaintingBgPalette
sContestPaintingBgPalette: @ 0x858F648
	.incbin "baserom_jp.gba", 0x58f648, 0x4
