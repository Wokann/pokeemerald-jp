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
	.globl gUnknown_82D97F9
gUnknown_82D97F9: @ 0x82D97F9
	.incbin "baserom_jp.gba", 0x2D97F9, 0x3B43  @ trailing data

	.globl gUnknown_82DD33C
gUnknown_82DD33C: @ 0x82DD33C
	.incbin "baserom_jp.gba", 0x2dd33c, 0x6e0

	.globl gMonFrontPicTable
gMonFrontPicTable: @ 0x82DDA1C
	.incbin "baserom_jp.gba", 0x2dda1c, 0x5b48



