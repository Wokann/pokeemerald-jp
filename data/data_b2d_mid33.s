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

	.section .rodata.data_b2d_mid33_gym_raw_suffix, "a", %progbits

	.globl gUnknown_85925B4
gUnknown_85925B4: @ 0x85925B4
	.incbin "baserom_jp.gba", 0x5925b4, 0x10

	.globl gUnknown_85925C4
gUnknown_85925C4: @ 0x85925C4
	.incbin "baserom_jp.gba", 0x5925c4, 0x6

	.globl gUnknown_85925CA
gUnknown_85925CA: @ 0x85925CA
	.incbin "baserom_jp.gba", 0x5925ca, 0xa

	.section .rodata.data_b2d_mid33_field_specials_raw_suffix, "a", %progbits

	.globl gUnknown_85925F8
gUnknown_85925F8: @ 0x85925F8
	.incbin "baserom_jp.gba", 0x5925f8, 0xc

	.globl gUnknown_8592604
gUnknown_8592604: @ 0x8592604
	.incbin "baserom_jp.gba", 0x592604, 0x4
