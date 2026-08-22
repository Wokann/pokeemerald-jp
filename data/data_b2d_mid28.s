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

	.globl gReflectionEffectPaletteMap
gReflectionEffectPaletteMap: @ 0x846FA18
	.incbin "graphics/field_effects/gReflectionEffectPaletteMap.bin"

	.globl gUnknown_846FA28
gUnknown_846FA28: @ 0x846FA28
	.incbin "baserom_jp.gba", 0x46fa28, 0x18

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

	.incbin "baserom_jp.gba", 0x4cf30c, 0xe580

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

	.section .rodata.data_b2d_mid28_after_event_object_movement_palette_data

	.globl gUnknown_84E423C
gUnknown_84E423C: @ 0x84E423C
	.incbin "baserom_jp.gba", 0x4e423c, 0x50

	.globl gUnknown_84E428C
gUnknown_84E428C: @ 0x84E428C
	.incbin "baserom_jp.gba", 0x4e428c, 0x978

	.globl gUnknown_84E4C04
gUnknown_84E4C04: @ 0x84E4C04
	.incbin "baserom_jp.gba", 0x4e4c04, 0xac

	.globl gUnknown_84E4CB0
gUnknown_84E4CB0: @ 0x84E4CB0
	.incbin "baserom_jp.gba", 0x4e4cb0, 0xac

	.globl gUnknown_84E4D5C
gUnknown_84E4D5C: @ 0x84E4D5C
	.incbin "baserom_jp.gba", 0x4e4d5c, 0xc0

	.globl gSpritePalette_GeneralFieldEffect1
gSpritePalette_GeneralFieldEffect1: @ 0x84E4E1C
	.incbin "graphics/misc/gSpritePalette_GeneralFieldEffect1.bin"

	.section .rodata.data_b2d_mid28_after_event_object_movement_action_function_tables_tail

	.globl gTextWindowFrame1_Gfx
gTextWindowFrame1_Gfx: @ 0x84E6CE0
	.incbin "graphics/text_window/gTextWindowFrame1_Gfx.bin"

	.globl gTextWindowFrame1_Pal
gTextWindowFrame1_Pal: @ 0x84E8360
	.incbin "graphics/text_window/gTextWindowFrame1_Pal.bin"

	.globl gMessageBox_Gfx
gMessageBox_Gfx: @ 0x84E85E0
	.incbin "graphics/text_window/message_box_jp.4bpp"

	.globl sTextWindowPalettes
sTextWindowPalettes: @ 0x84E87A0
	.incbin "graphics/text_window/sTextWindowPalettes.bin"

	.globl gUnknown_84E8840
gUnknown_84E8840: @ 0x84E8840
	.incbin "baserom_jp.gba", 0x4e8840, 0x20

	.globl sWindowFrames
sWindowFrames: @ 0x84E8860
	.incbin "graphics/text_window/sWindowFrames.bin"

	.globl gNullScriptPtr
gNullScriptPtr: @ 0x84E8900
	.4byte 0

	.globl sScriptConditionTable
sScriptConditionTable: @ 0x84E8904
	.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
	.byte 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00

	.globl sScriptStringVars
sScriptStringVars: @ 0x84E8918
	.4byte 0x02021C40, 0x02021C54, 0x02021C68

	.section .rodata.data_b2d_mid28_after_field_tasks_static_data

	.globl gResetRtcBgTemplates
gResetRtcBgTemplates: @ 0x84E8A48
	.byte 0xF0, 0x01, 0x00, 0x00

	.globl gResetRtcWindowTemplates
gResetRtcWindowTemplates: @ 0x84E8A4C
	.byte 0x00, 0x01, 0x01, 0x13, 0x09, 0x0F, 0x55, 0x01
	.byte 0x00, 0x04, 0x0F, 0x16, 0x04, 0x0F, 0xFD, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl gResetRtcInputTimeWindow
gResetRtcInputTimeWindow: @ 0x84E8A64
	.incbin "graphics/misc/gResetRtcInputTimeWindow.bin"
