.include "sound/MPlayDef.s"
	.section .rodata.mid1_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.globl gUnknown_85ECE88
gUnknown_85ECE88: @ 0x85ECE88
	.incbin "baserom_jp.gba", 0x5ece88, 0x134

	.globl gUnknown_85ECFBC
gUnknown_85ECFBC: @ 0x85ECFBC
	.incbin "baserom_jp.gba", 0x5ecfbc, 0x78

	.section .rodata.mid1_sprite_data

	.globl gUnknown_85ED2EF
gUnknown_85ED2EF: @ 0x85ED2EF
	.incbin "baserom_jp.gba", 0x5ed2ef, 0x11d

	.globl gUnknown_85ED40C
gUnknown_85ED40C: @ 0x85ED40C
	.incbin "baserom_jp.gba", 0x5ed40c, 0x8

	.globl gUnknown_85ED414
gUnknown_85ED414: @ 0x85ED414
	.incbin "baserom_jp.gba", 0x5ed414, 0x18

	.globl gUnknown_85ED42C
gUnknown_85ED42C: @ 0x85ED42C
	.incbin "baserom_jp.gba", 0x5ed42c, 0x98

	.globl gUnknown_85ED4C4
gUnknown_85ED4C4: @ 0x85ED4C4
	.incbin "baserom_jp.gba", 0x5ed4c4, 0x8

	.globl gUnknown_85ED4CC
gUnknown_85ED4CC: @ 0x85ED4CC
	.incbin "baserom_jp.gba", 0x5ed4cc, 0x8

	.globl gUnknown_85ED4D4
gUnknown_85ED4D4: @ 0x85ED4D4
	.incbin "baserom_jp.gba", 0x5ed4d4, 0x74

	.globl gUnknown_85ED548
gUnknown_85ED548: @ 0x85ED548
	.incbin "baserom_jp.gba", 0x5ed548, 0x8

	.globl gUnknown_85ED550
gUnknown_85ED550: @ 0x85ED550
	.incbin "baserom_jp.gba", 0x5ed550, 0x8

	.globl gUnknown_85ED558
gUnknown_85ED558: @ 0x85ED558
	.incbin "baserom_jp.gba", 0x5ed558, 0x18

	.globl gUnknown_85ED570
gUnknown_85ED570: @ 0x85ED570
	.incbin "baserom_jp.gba", 0x5ed570, 0x20

