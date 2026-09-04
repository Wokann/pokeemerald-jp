.include "sound/MPlayDef.s"
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.section .rodata.data_b2d_mid69_after_battle_message_alignment

	.globl gUnknown_85AC232
gUnknown_85AC232: @ 0x85AC232
	.incbin "baserom_jp.gba", 0x5ac232, 0x2

	.section .rodata.data_b2d_mid69_after_field_effect_helpers
	.incbin "baserom_jp.gba", 0x5aca76, 0x92

	.globl gText_TeachWhichMoveToPkmn
