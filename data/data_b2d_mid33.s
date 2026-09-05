.include "sound/MPlayDef.s"
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.section .rodata.data_b2d_mid33_pokeblock_case_favorite_suffix, "a", %progbits

	.globl gUnknown_85921F4
gUnknown_85921F4: @ 0x85921F4
	.incbin "baserom_jp.gba", 0x5921f4, 0x8

	.globl gUnknown_85921FC
gUnknown_85921FC: @ 0x85921FC
	.incbin "baserom_jp.gba", 0x5921fc, 0x18
