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

	.section .rodata.data_b_after_wireless_ascii_tables

	.section .rodata.data_b_after_link_rfu_2_core_tables


	.section .rodata.data_b_tail
gUnknown_82E383A: @ 0x82E383A
	.incbin "baserom_jp.gba", 0x2e383a, 0x2
