.include "sound/MPlayDef.s"
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.section .rodata.mid60_tail_prefix


	.include "data/field_special_scene/truck_and_ss_tidal.inc"

	.section .rodata.easy_chat_unreferenced_palette_data

	.globl gUnknown_85733B0
gUnknown_85733B0: @ 0x85733B0
	@ Unreferenced BGR555 palette; semantic owner has not been established.
	.incbin "baserom_jp.gba", 0x5733b0, 0x20

	.section .rodata.mid60_tail_after_easy_chat_group_names_data
