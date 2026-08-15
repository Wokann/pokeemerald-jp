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


	.globl gUnknown_82F4F2A
gUnknown_82F4F2A: @ 0x82F4F2A
	.incbin "baserom_jp.gba", 0x2f4f2a, 0x16
	.globl gUnknown_82F4F40
gUnknown_82F4F40: @ 0x82F4F40
	.incbin "baserom_jp.gba", 0x2f4f40, 0x16
	.globl gUnknown_82F4F56
gUnknown_82F4F56: @ 0x82F4F56
	.incbin "baserom_jp.gba", 0x2f4f56, 0x14
