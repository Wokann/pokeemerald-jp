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

	.globl sGiftRibbonsMonDataIds
sGiftRibbonsMonDataIds: @ 0x8569552
	.byte 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x00, 0x00, 0x00

	.include "data/field_effects/secret_power.inc"

	.section .rodata.mid60_tail_prefix
	.include "data/field_effects/secret_power_descriptors.inc"

	.include "data/field_effects/record_mix_lights.inc"

	.include "data/field_special_scene/truck_and_ss_tidal.inc"

	.section .rodata.easy_chat_unreferenced_palette_data

	.globl gUnknown_85733B0
gUnknown_85733B0: @ 0x85733B0
	@ Unreferenced BGR555 palette; semantic owner has not been established.
	.incbin "baserom_jp.gba", 0x5733b0, 0x20

	.section .rodata.easy_chat_unclassified_ui_aux_data

	.globl gUnknown_85743B4
gUnknown_85743B4: @ 0x85743B4
	@ This auxiliary UI data has no verified semantic owner yet.
	.incbin "baserom_jp.gba", 0x5743b4, 0x8

	.section .rodata.mid60_tail_after_easy_chat_group_speech_data

	.globl gUnknown_85763A4
gUnknown_85763A4: @ 0x85763A4
	.incbin "baserom_jp.gba", 0x5763a4, 0x2970

	.globl gUnknown_8578D14
gUnknown_8578D14: @ 0x8578D14
	.incbin "baserom_jp.gba", 0x578d14, 0xff0

	.globl gUnknown_8579D04
gUnknown_8579D04: @ 0x8579D04
	.incbin "baserom_jp.gba", 0x579d04, 0x1d4

	.globl gUnknown_8579ED8
gUnknown_8579ED8: @ 0x8579ED8
	.incbin "baserom_jp.gba", 0x579ed8, 0x58
	.globl sEasyChatGroupNamePointers
	.set sEasyChatGroupNamePointers, gUnknown_8579ED8
