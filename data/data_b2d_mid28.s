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

	.globl gUnknown_84E401C
gUnknown_84E401C: @ 0x84E401C
	.incbin "baserom_jp.gba", 0x4e401c, 0x138

	.globl sObjectEventSpritePalettes
	.set sObjectEventSpritePalettes, gUnknown_84E401C

	.globl gUnknown_84E4154
gUnknown_84E4154: @ 0x84E4154
	.incbin "baserom_jp.gba", 0x4e4154, 0x78

	.globl sPlayerReflectionPaletteSets
	.set sPlayerReflectionPaletteSets, gUnknown_84E4154

	.globl gUnknown_84E41CC
gUnknown_84E41CC: @ 0x84E41CC
	.incbin "baserom_jp.gba", 0x4e41cc, 0xc0

	.globl sSpecialObjectReflectionPaletteSets
	.set sSpecialObjectReflectionPaletteSets, gUnknown_84E41CC

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

	.section .rodata.data_b2d_mid28_after_event_object_movement_direction_composition_data

	.globl gUnknown_84E60A4
gUnknown_84E60A4: @ 0x84E60A4
	.incbin "baserom_jp.gba", 0x4e60a4, 0x298

	.globl gUnknown_84E633C
gUnknown_84E633C: @ 0x84E633C
	.incbin "baserom_jp.gba", 0x4e633c, 0xd4

	.globl gUnknown_84E6410
gUnknown_84E6410: @ 0x84E6410
	.incbin "baserom_jp.gba", 0x4e6410, 0x6

	.globl gUnknown_84E6416
gUnknown_84E6416: @ 0x84E6416
	.incbin "baserom_jp.gba", 0x4e6416, 0x61a

	.globl gUnknown_84E6A30
gUnknown_84E6A30: @ 0x84E6A30
	.incbin "baserom_jp.gba", 0x4e6a30, 0x8

	.globl metatileFuncs
metatileFuncs: @ 0x84E6A38
	.4byte MetatileBehavior_IsTallGrass + 1, MetatileBehavior_IsLongGrass + 1, MetatileBehavior_IsPuddle + 1, MetatileBehavior_IsSurfableWaterOrUnderwater + 1, MetatileBehavior_IsShallowFlowingWater + 1, MetatileBehavior_IsATile + 1

	.globl gUnknown_84E6A50
gUnknown_84E6A50: @ 0x84E6A50
	.incbin "baserom_jp.gba", 0x4e6a50, 0x18

	.globl ledgeBehaviorFuncs
ledgeBehaviorFuncs: @ 0x84E6A68
	.4byte MetatileBehavior_IsJumpSouth + 1, MetatileBehavior_IsJumpNorth + 1, MetatileBehavior_IsJumpWest + 1, MetatileBehavior_IsJumpEast + 1

	.globl gUnknown_84E6A78
gUnknown_84E6A78: @ 0x84E6A78
	.incbin "baserom_jp.gba", 0x4e6a78, 0x10

	.globl gUnknown_84E6A88
gUnknown_84E6A88: @ 0x84E6A88
	.incbin "baserom_jp.gba", 0x4e6a88, 0x10
	.globl sElevationToPriority
	.set sElevationToPriority, gUnknown_84E6A88

	.globl gUnknown_84E6A98
gUnknown_84E6A98: @ 0x84E6A98
	.incbin "baserom_jp.gba", 0x4e6a98, 0x10

	.globl sGroundEffectTracksFuncs
sGroundEffectTracksFuncs: @ 0x84E6AA8
	.4byte DoTracksGroundEffect_None + 1, DoTracksGroundEffect_Footprints + 1, DoTracksGroundEffect_BikeTireTracks + 1

	.globl gUnknown_84E6AB4
gUnknown_84E6AB4: @ 0x84E6AB4
	.incbin "baserom_jp.gba", 0x4e6ab4, 0x4

	.globl gUnknown_84E6AB8
gUnknown_84E6AB8: @ 0x84E6AB8
	.incbin "baserom_jp.gba", 0x4e6ab8, 0x10

	.globl gUnknown_84E6AC8
gUnknown_84E6AC8: @ 0x84E6AC8
	.incbin "baserom_jp.gba", 0x4e6ac8, 0xe0

	.globl gUnknown_84E6BA8
gUnknown_84E6BA8: @ 0x84E6BA8
	.incbin "baserom_jp.gba", 0x4e6ba8, 0x14

	.globl gUnknown_84E6BBC
gUnknown_84E6BBC: @ 0x84E6BBC
	.incbin "baserom_jp.gba", 0x4e6bbc, 0xa

	.section .rodata.data_b2d_mid28_after_field_effect_helpers_figure8
	.incbin "baserom_jp.gba", 0x4e6c56, 0x32

	.globl gUnknown_84E6C88
gUnknown_84E6C88: @ 0x84E6C88
	.incbin "baserom_jp.gba", 0x4e6c88, 0xc

	.globl gUnknown_84E6C94
gUnknown_84E6C94: @ 0x84E6C94
	.incbin "baserom_jp.gba", 0x4e6c94, 0x6

	.globl gUnknown_84E6C9A
gUnknown_84E6C9A: @ 0x84E6C9A
	.incbin "baserom_jp.gba", 0x4e6c9a, 0x4

	.globl gUnknown_84E6C9E
gUnknown_84E6C9E: @ 0x84E6C9E
	.incbin "baserom_jp.gba", 0x4e6c9e, 0x6

	.globl gUnknown_84E6CA4
gUnknown_84E6CA4: @ 0x84E6CA4
	.incbin "baserom_jp.gba", 0x4e6ca4, 0x4

	.globl gUnknown_84E6CA8
gUnknown_84E6CA8: @ 0x84E6CA8
	.incbin "baserom_jp.gba", 0x4e6ca8, 0xc

	.globl gUnknown_84E6CB4
gUnknown_84E6CB4: @ 0x84E6CB4
	.incbin "baserom_jp.gba", 0x4e6cb4, 0x2c

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
