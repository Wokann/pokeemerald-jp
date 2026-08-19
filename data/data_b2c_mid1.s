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

