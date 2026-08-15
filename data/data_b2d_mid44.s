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

	.globl gUnknown_82F5934
gUnknown_82F5934: @ 0x82F5934
	.incbin "baserom_jp.gba", 0x2f5934, 0x18
	.globl gUnknown_82F594C
gUnknown_82F594C: @ 0x82F594C
	.incbin "baserom_jp.gba", 0x2f594c, 0x16
	.globl gUnknown_82F5962
gUnknown_82F5962: @ 0x82F5962
	.incbin "baserom_jp.gba", 0x2f5962, 0x1c
