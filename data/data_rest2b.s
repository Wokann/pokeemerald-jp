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
	.incbin "baserom_jp.gba", 0xc1b558, 0x11a8


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
