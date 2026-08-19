.include "sound/MPlayDef.s"
	.section .rodata.mid100_shared_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85DC21C
gUnknown_85DC21C: @ 0x85DC21C
	.incbin "baserom_jp.gba", 0x5dc21c, 0xc
