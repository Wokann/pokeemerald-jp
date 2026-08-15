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


	.globl gUnknown_82F495E
gUnknown_82F495E: @ 0x82F495E
	.incbin "baserom_jp.gba", 0x2f495e, 0x12
	.globl gUnknown_82F4970
gUnknown_82F4970: @ 0x82F4970
	.incbin "baserom_jp.gba", 0x2f4970, 0x12
	.globl gUnknown_82F4982
