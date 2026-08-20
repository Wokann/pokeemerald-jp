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
	.globl gUnknown_8C02308
gUnknown_8C02308: @ 0x8C02308
	.incbin "baserom_jp.gba", 0xc02308, 0x70f0


	.globl gUnknown_8C093F8
gUnknown_8C093F8: @ 0x8C093F8
	.incbin "baserom_jp.gba", 0xc093f8, 0x87ec


	.globl gHealthboxElementsGfxTable
gHealthboxElementsGfxTable: @ 0x8C11BE4
	.incbin "baserom_jp.gba", 0xc11be4, 0x52b4


	.globl gUnknown_8C16E98
gUnknown_8C16E98: @ 0x8C16E98
	.incbin "baserom_jp.gba", 0xc16e98, 0x118


	.globl gUnknown_8C16FB0
gUnknown_8C16FB0: @ 0x8C16FB0
	.incbin "baserom_jp.gba", 0xc16fb0, 0x1c8


	.globl gUnknown_8C17178
gUnknown_8C17178: @ 0x8C17178
	.incbin "baserom_jp.gba", 0xc17178, 0x810


	.globl gUnknown_8C17988
gUnknown_8C17988: @ 0x8C17988
	.incbin "baserom_jp.gba", 0xc17988, 0x130


	.globl gUnknown_8C17AB8
gUnknown_8C17AB8: @ 0x8C17AB8
	.incbin "baserom_jp.gba", 0xc17ab8, 0xb98


	.globl gUnknown_8C18650
gUnknown_8C18650: @ 0x8C18650
	.incbin "baserom_jp.gba", 0xc18650, 0x107c


	.globl gUnknown_8C196CC
gUnknown_8C196CC: @ 0x8C196CC
	.incbin "baserom_jp.gba", 0xc196cc, 0x868


	.globl gUnknown_8C19F34
gUnknown_8C19F34: @ 0x8C19F34
	.incbin "baserom_jp.gba", 0xc19f34, 0x114


	.globl gUnknown_8C1A048
gUnknown_8C1A048: @ 0x8C1A048
	.incbin "baserom_jp.gba", 0xc1a048, 0x12c


	.globl gUnknown_8C1A174
gUnknown_8C1A174: @ 0x8C1A174
	.incbin "baserom_jp.gba", 0xc1a174, 0x188


	.globl gUnknown_8C1A2FC
gUnknown_8C1A2FC: @ 0x8C1A2FC
	.incbin "baserom_jp.gba", 0xc1a2fc, 0x2404


	.globl gUnknown_8C1C700
gUnknown_8C1C700: @ 0x8C1C700
	.incbin "baserom_jp.gba", 0xc1c700, 0x9f4


	.globl gMetalShineGfx
gMetalShineGfx: @ 0x8C1D0F4
	.incbin "graphics/misc/gMetalShineGfx.bin"


	.globl gMetalShinePalette
gMetalShinePalette: @ 0x8C1D230
	.4byte 0x00002010, 0xFF7EAA00, 0x0C46547F, 0x226F0016, 0x3B352ED2, 0xFB004798, 0xCC02AA53, 0x001B0F0E, 0x33752752, 0x4BFB3FB8


	.globl gMetalShineTilemap
gMetalShineTilemap: @ 0x8C1D258
	.incbin "graphics/misc/gMetalShineTilemap.bin"


	.globl gBattleAnimMaskImage_Curse
gBattleAnimMaskImage_Curse: @ 0x8C2070C
	.incbin "graphics/battle_anims/gBattleAnimMaskImage_Curse.bin"


	.globl gBattleAnimMaskTilemap_Curse
gBattleAnimMaskTilemap_Curse: @ 0x8C20728
	.incbin "graphics/battle_anims/gBattleAnimMaskTilemap_Curse.bin"


	.globl gBattleAnimSpritePal_MusicNotes2
gBattleAnimSpritePal_MusicNotes2: @ 0x8C226B4
	.incbin "graphics/battle_anims/gBattleAnimSpritePal_MusicNotes2.bin"


	.globl gBattleAnimBgImage_Attract
gBattleAnimBgImage_Attract: @ 0x8C23384
	.incbin "graphics/battle_anims/gBattleAnimBgImage_Attract.bin"


	.globl gBattleAnimBgPalette_Attract
gBattleAnimBgPalette_Attract: @ 0x8C23DF4
	.incbin "graphics/battle_anims/gBattleAnimBgPalette_Attract.bin"


	.globl gBattleAnimBgTilemap_Attract
gBattleAnimBgTilemap_Attract: @ 0x8C23E1C
	.incbin "graphics/battle_anims/gBattleAnimBgTilemap_Attract.bin"


	.globl gBattleAnimBgPalette_ScaryFace
gBattleAnimBgPalette_ScaryFace: @ 0x8C24A74
	.incbin "graphics/battle_anims/gBattleAnimBgPalette_ScaryFace.bin"


	.globl gBattleAnimBgImage_ScaryFace
gBattleAnimBgImage_ScaryFace: @ 0x8C24A9C
	.incbin "graphics/battle_anims/gBattleAnimBgImage_ScaryFace.bin"


	.globl gBattleAnimMaskImage_LightBeam
gBattleAnimMaskImage_LightBeam: @ 0x8C2A6D8
	.incbin "graphics/battle_anims/gBattleAnimMaskImage_LightBeam.bin"


	.globl gBattleAnimMaskPalette_LightBeam
gBattleAnimMaskPalette_LightBeam: @ 0x8C2A778
	.incbin "graphics/battle_anims/gBattleAnimMaskPalette_LightBeam.bin"


	.globl gBattleAnimMaskTilemap_LightBeam
gBattleAnimMaskTilemap_LightBeam: @ 0x8C2A790
	.incbin "graphics/battle_anims/gBattleAnimMaskTilemap_LightBeam.bin"


	.globl gUnknown_8C2CF60
gUnknown_8C2CF60: @ 0x8C2CF60
	.incbin "baserom_jp.gba", 0xc2cf60, 0x24


	.globl gUnknown_8C2CF84
gUnknown_8C2CF84: @ 0x8C2CF84
	.incbin "baserom_jp.gba", 0xc2cf84, 0x240


	.globl gUnknown_8C2D1C4
gUnknown_8C2D1C4: @ 0x8C2D1C4
	.incbin "baserom_jp.gba", 0xc2d1c4, 0x600


	.section .rodata.data_rest2b_after_stat_change
	.globl gUnknown_8C2EAF4
gUnknown_8C2EAF4: @ 0x8C2EAF4
	.incbin "baserom_jp.gba", 0xc2eaf4, 0x4c


	.globl gUnknown_8C2EB40
gUnknown_8C2EB40: @ 0x8C2EB40
	.incbin "baserom_jp.gba", 0xc2eb40, 0xf6c
