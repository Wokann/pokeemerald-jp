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

	.globl gUnknown_82F551C
gUnknown_82F551C: @ 0x82F551C
	.incbin "baserom_jp.gba", 0x2f551c, 0x1c
	.globl gUnknown_82F5538
gUnknown_82F5538: @ 0x82F5538
	.incbin "baserom_jp.gba", 0x2f5538, 0x20
