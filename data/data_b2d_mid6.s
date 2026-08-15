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


	.globl gUnknown_82F414E
gUnknown_82F414E: @ 0x82F414E
	.incbin "baserom_jp.gba", 0x2f414e, 0x14
	.globl gUnknown_82F4162
gUnknown_82F4162: @ 0x82F4162
	.incbin "baserom_jp.gba", 0x2f4162, 0x18
