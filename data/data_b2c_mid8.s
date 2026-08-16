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

	.globl gUnknown_85F7C98
gUnknown_85F7C98: @ 0x85F7C98
	.incbin "baserom_jp.gba", 0x5f7c98, 0x1e40

	.globl sConditionPokeballPal
sConditionPokeballPal: @ 0x85F9AD8
	.incbin "graphics/pokenav_conditions/sConditionPokeballPal.bin"

	.globl sConditionCancelPal
sConditionCancelPal: @ 0x85F9AF8
	.incbin "graphics/pokenav_conditions/sConditionCancelPal.bin"

	.globl sConditionPokeball_Gfx
sConditionPokeball_Gfx: @ 0x85F9B18
	.incbin "graphics/pokenav_conditions/sConditionPokeballGfx.bin"

	.globl sConditionPokeballPlaceholder_Gfx
sConditionPokeballPlaceholder_Gfx: @ 0x85F9C18
	.incbin "graphics/pokenav_conditions/sConditionPokeballPlaceholderGfx.bin"

	.globl sConditionCancel_Gfx
sConditionCancel_Gfx: @ 0x85F9C38
	.incbin "graphics/pokenav_conditions/sConditionCancelGfx.bin"

	.globl sConditionSparkle_Gfx
sConditionSparkle_Gfx: @ 0x85F9D38
	.incbin "graphics/pokenav_conditions/sConditionSparkleGfx.bin"

	.globl sConditionSparkle_Pal
sConditionSparkle_Pal: @ 0x85F9D58
	.incbin "graphics/pokenav_conditions/sConditionSparklePal.bin"

	.globl gUnknown_85FA0D8
gUnknown_85FA0D8: @ 0x85FA0D8
	.incbin "baserom_jp.gba", 0x5fa0d8, 0x798

	.globl sOam_ConditionMonPic
sOam_ConditionMonPic: @ 0x85FA870
	.4byte 0xC0000000  @ shape=0, size=3 (64x64), rest zeroed
	.hword 0x0400, 0x0000  @ tileNum=0, priority=1, paletteNum=0, affineParam=0

	.globl sOam_ConditionSelectionIcon
sOam_ConditionSelectionIcon: @ 0x85FA878
	.4byte 0x40000000  @ size=1 (16x16), rest zeroed
	.hword 0x0800, 0x0000  @ tileNum=0, priority=2, paletteNum=0, affineParam=0

	.globl sAnim_ConditionSelectionIcon_Selected
sAnim_ConditionSelectionIcon_Selected: @ 0x85FA880
	.hword 0x0000, 0x0005  @ ANIMCMD_FRAME(0, 5)
	.hword 0xFFFF, 0x0000  @ ANIMCMD_END

	.globl sAnim_ConditionSelectionIcon_Unselected
sAnim_ConditionSelectionIcon_Unselected: @ 0x85FA888
	.hword 0x0004, 0x0005  @ ANIMCMD_FRAME(4, 5)
	.hword 0xFFFF, 0x0000  @ ANIMCMD_END

	.globl sAnims_ConditionSelectionIcon
sAnims_ConditionSelectionIcon: @ 0x85FA890
	.4byte sAnim_ConditionSelectionIcon_Selected, sAnim_ConditionSelectionIcon_Unselected

	.globl sConditionMonPicSheetDescriptor
sConditionMonPicSheetDescriptor: @ 0x85FA898
	.4byte 0
	.hword 0x0800, 0x0064

	.globl sConditionMonPicTemplateDescriptor
sConditionMonPicTemplateDescriptor: @ 0x85FA8A0
	.hword 0x0064, 0x0064
	.4byte sOam_ConditionMonPic
	.4byte gDummySpriteAnimTable
	.4byte 0
	.4byte gDummySpriteAffineAnimTable
	.4byte SpriteCallbackDummy

	.globl sConditionMonPicPalDescriptor
sConditionMonPicPalDescriptor: @ 0x85FA8B8
	.4byte 0
	.hword 0x0064, 0x0000

	.globl sConditionSelectionIconsSheets
sConditionSelectionIconsSheets: @ 0x85FA8C0
	.4byte sConditionPokeball_Gfx
	.hword 0x0100, 0x0065
	.4byte sConditionPokeballPlaceholder_Gfx
	.hword 0x0020, 0x0067
	.4byte sConditionCancel_Gfx
	.hword 0x0100, 0x0066
	.4byte 0, 0

	.globl sConditionSelectionIconsPals
sConditionSelectionIconsPals: @ 0x85FA8E0
	.4byte sConditionPokeballPal
	.hword 0x0065, 0x0000
	.4byte sConditionCancelPal
	.hword 0x0066, 0x0000
	.4byte 0
	.hword 0x0000, 0x0000

	.globl sConditionSelectionIconsTemplate
sConditionSelectionIconsTemplate: @ 0x85FA8F8
	.hword 0x0065, 0x0065
	.4byte sOam_ConditionSelectionIcon
	.4byte sAnims_ConditionSelectionIcon
	.4byte 0
	.4byte gDummySpriteAffineAnimTable
	.4byte SpriteCallbackDummy

	.globl sConditionSparkleSheetDescriptor
sConditionSparkleSheetDescriptor: @ 0x85FA910
	.4byte sConditionSparkle_Pal
	.hword 0x0380, 0x0068

	.globl sConditionSparklePalDescriptor
sConditionSparklePalDescriptor: @ 0x85FA918
	.4byte sConditionSparkle_Gfx
	.hword 0x0068, 0x0000

	.globl sOam_ConditionSparkle
sOam_ConditionSparkle: @ 0x85FA920
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

	.globl sAnim_ConditionSparkle
sAnim_ConditionSparkle: @ 0x85FA928
	.hword 0x0000, 0x0005, 0x0004, 0x0005
	.hword 0x0008, 0x0005, 0x000C, 0x0005
	.hword 0x0010, 0x0005, 0x0014, 0x0005
	.hword 0x0018, 0x0005, 0xFFFF, 0x0000

	.globl sAnims_ConditionSparkle
sAnims_ConditionSparkle: @ 0x85FA948
	.4byte 0x085FA928, 0x085FA930, 0x085FA938, 0x085FA940
	.4byte 0x085FA948, 0x085FA950, 0x085FA958

	.globl sSpriteTemplate_ConditionSparkle
sSpriteTemplate_ConditionSparkle: @ 0x85FA964
	.hword 0x0068, 0x0068
	.4byte sOam_ConditionSparkle
	.4byte sAnims_ConditionSparkle
	.4byte 0
	.4byte gDummySpriteAffineAnimTable
	.4byte 0x081D2B95  @ JP sparkle callback (function not yet decompiled)

	.globl sConditionSparkleCoords
sConditionSparkleCoords: @ 0x85FA97C
	.hword 0, -35, 20, -28, 33, -10, 33, 10, 20, 28, 0, 35, -20, 28, -33, 10, -33, -10, -20, -28

	.globl gText_MaxHP
gText_MaxHP: @ 0x85FA9A4
	.string "さいだいHP$"
	.globl gText_Attack
gText_Attack: @ 0x85FA9AB
	.string "こうげき$"
	.globl gText_Defense
gText_Defense: @ 0x85FA9B0
	.string "ぼうぎょ$"
	.globl gText_Speed
gText_Speed: @ 0x85FA9B5
	.string "すばやさ$"
	.globl gText_SpAtk
gText_SpAtk: @ 0x85FA9BA
	.string "とくこう$"
	.globl gText_SpDef
gText_SpDef: @ 0x85FA9BF
	.string "とくぼう$"
	.globl gText_Plus
gText_Plus: @ 0x85FA9C4
	.string "{PLUS}$"

	.globl gText_Dash
gText_Dash: @ 0x85FA9C7
	.string "ー$"
	.byte 0, 0, 0

	.globl sLvlUpStatStrings
sLvlUpStatStrings: @ 0x85FA9CC
	.4byte gText_MaxHP, gText_Attack, gText_Defense, gText_SpAtk, gText_SpDef, gText_Speed

