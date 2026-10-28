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




	.section .rodata.data_b2d_after_battle_palace_likelihood

	.incbin "baserom_jp.gba", 0x2ece95, 0x7

	.section .rodata.mid97_prefix

	.globl gText_Red
gText_Red: @ 0x85CD061
	.string "あか$"
	.globl gText_Blue
gText_Blue: @ 0x85CD064
	.string "あお$　"

	.section .rodata.mid76_pokeblock_name_text_prefix

	.globl gUnknown_85C97B5
gUnknown_85C97B5: @ 0x85C97B5
	.string "{NO}{B_COPY_VAR_1}　{B_COPY_VAR_2}$"

	.globl gUnknown_85C97BD
gUnknown_85C97BD: @ 0x85C97BD
	.string "きのみのタグ$"
