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

	.globl gUnknown_846FA13
gUnknown_846FA13: @ 0x846FA13
	.incbin "baserom_jp.gba", 0x46fa13, 0x5

	.section .rodata.data_b2d_mid28_after_reflection_data

	.globl gUnknown_846FA40
gUnknown_846FA40: @ 0x846FA40
	.incbin "baserom_jp.gba", 0x46fa40, 0x120c

	.globl gUnknown_8470C4C
gUnknown_8470C4C: @ 0x8470C4C
	.incbin "baserom_jp.gba", 0x470c4c, 0x1220

	.globl gUnknown_8471E6C
gUnknown_8471E6C: @ 0x8471E6C
	.incbin "baserom_jp.gba", 0x471e6c, 0xa860

	.globl gUnknown_847C6CC
gUnknown_847C6CC: @ 0x847C6CC
	.incbin "baserom_jp.gba", 0x47c6cc, 0x1240

	.globl gUnknown_847D90C
gUnknown_847D90C: @ 0x847D90C
	.incbin "baserom_jp.gba", 0x47d90c, 0x519a0

	.section .rodata.data_b2d_mid28_after_cut_grass_graphics

	.incbin "baserom_jp.gba", 0x4cf30c, 0x900

	.section .rodata.data_b2d_mid28_after_field_effect_general_palettes

	.incbin "baserom_jp.gba", 0x4cfc4c, 0xdc40

	.section .rodata.data_b2d_mid28_after_event_object_movement_core_data

	.globl gUnknown_84DDA74
gUnknown_84DDA74: @ 0x84DDA74
	.incbin "baserom_jp.gba", 0x4dda74, 0x3bc

	.globl gUnknown_84DDE30
gUnknown_84DDE30: @ 0x84DDE30
	.incbin "baserom_jp.gba", 0x4dde30, 0x1c

	.globl gFieldEffectObjectTemplatePointers
gFieldEffectObjectTemplatePointers: @ 0x84DDE4C
	.incbin "baserom_jp.gba", 0x4dde4c, 0x3ab4

	.globl gUnknown_84E1900
gUnknown_84E1900: @ 0x84E1900
	.incbin "baserom_jp.gba", 0x4e1900, 0x271c

	.section .rodata.data_b2d_mid28_after_event_object_movement_action_function_tables_tail

	.globl gTextWindowFrame1_Gfx
gTextWindowFrame1_Gfx: @ 0x84E6CE0
	.incbin "graphics/text_window/gTextWindowFrame1_Gfx.bin"

	.globl gTextWindowFrame1_Pal
gTextWindowFrame1_Pal: @ 0x84E8360
	.incbin "graphics/text_window/gTextWindowFrame1_Pal.bin"

	.section .rodata.data_b2d_mid28_after_text_window_resources

	.section .rodata.data_b2d_mid28_after_script_command_static_data

	.section .rodata.data_b2d_mid28_after_field_tasks_static_data

	.section .rodata.data_b2d_mid28_after_reset_rtc_templates
