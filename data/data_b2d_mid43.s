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

	.globl gUnknown_82F57C2
gUnknown_82F57C2: @ 0x82F57C2
	.incbin "baserom_jp.gba", 0x2f57c2, 0x18
	.globl gUnknown_82F57DA
gUnknown_82F57DA: @ 0x82F57DA
	.incbin "baserom_jp.gba", 0x2f57da, 0x1e
