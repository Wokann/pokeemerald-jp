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
	.incbin "baserom_jp.gba", 0xc093f8, 0x87ac


	.section .rodata.data_rest2b_after_healthbox
	.incbin "baserom_jp.gba", 0xc12aa4, 0x2588

	.section .rodata.data_rest2b_after_jp_contest
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


	.section .rodata.data_rest2b_after_battle_anim_masks
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
