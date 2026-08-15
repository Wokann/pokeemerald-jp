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


	.globl gUnknown_82F441C
gUnknown_82F441C: @ 0x82F441C
	.incbin "baserom_jp.gba", 0x2f441c, 0x16
	.globl gUnknown_82F4432
