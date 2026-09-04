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

	.section .rodata.data_b2d_mid28_after_reflection_data

	.section .rodata.data_b2d_mid28_after_camera_function_data

	.section .rodata.data_b2d_mid28_after_player_graphics

	.section .rodata.data_b2d_mid28_after_player_extended_graphics

	.section .rodata.data_b2d_mid28_after_may_base_graphics

	.section .rodata.data_b2d_mid28_after_may_action_graphics

	.section .rodata.data_b2d_mid28_after_npc_people_graphics

	.section .rodata.data_b2d_mid28_after_npc_people_extended_graphics

	.section .rodata.data_b2d_mid28_after_special_object_graphics

	.section .rodata.data_b2d_mid28_after_dolls_graphics

	.section .rodata.data_b2d_mid28_after_misc_graphics

	.section .rodata.data_b2d_mid28_after_opening_graphics

	.section .rodata.data_b2d_mid28_after_transport_graphics
	.incbin "baserom_jp.gba", 0x4c1fec, 0x300

	.section .rodata.data_b2d_mid28_after_berry_tree_graphics
	.incbin "baserom_jp.gba", 0x4cd86c, 0x1a40

	.section .rodata.data_b2d_mid28_after_cut_grass_graphics

	.section .rodata.data_b2d_mid28_after_field_effect_general_palettes

	.incbin "baserom_jp.gba", 0x4cfc4c, 0xdc40

	.section .rodata.data_b2d_mid28_after_event_object_movement_core_data

	.section .rodata.data_b2d_mid28_after_field_effect_object_template_pointers

	.section .rodata.data_b2d_mid28_after_event_object_movement_action_function_tables_tail

	.section .rodata.data_b2d_mid28_after_text_window_resources

	.section .rodata.data_b2d_mid28_after_script_command_static_data

	.section .rodata.data_b2d_mid28_after_field_tasks_static_data

	.section .rodata.data_b2d_mid28_after_reset_rtc_templates
