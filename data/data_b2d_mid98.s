.include "sound/MPlayDef.s"
	.section .rodata.mid98_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85CD19F
gUnknown_85CD19F: @ 0x85CD19F
	.string "エラーがはっせいしました\n"
	.string "しゅうりょうします$Aボタンを　おしてください$つながりました$データを　じゅしんしました$セーブできませんでした$セーブできました$ロードできませんでした$ロードできました$"
	.section .rodata.mid98_between

	.section .rodata.mid98_suffix_before_species_to_back_anim_set

	.section .rodata.mid98_suffix_after_shake_visual_data

	.globl sMatchCallTaskFuncs
sMatchCallTaskFuncs: @ 0x85D79F4
	.4byte MatchCall_LoadGfx @ 0x08195D2D
	.4byte MatchCall_DrawWindow @ 0x08195DF1
	.4byte MatchCall_ReadyIntro @ 0x08195E75
	.4byte MatchCall_SlideWindowIn @ 0x08195EB1
	.4byte MatchCall_PrintIntro @ 0x08195ED9
	.4byte MatchCall_PrintMessage @ 0x08195F31
	.4byte MatchCall_SlideWindowOut @ 0x08195F91
	.4byte MatchCall_EndCall @ 0x08195FF1

	.globl sMatchCallTextWindow
sMatchCallTextWindow: @ 0x85D7A14
	.byte 0 @ bg
	.byte 1 @ tilemapLeft
	.byte 15 @ tilemapTop
	.byte 28 @ width
	.byte 4 @ height
	.byte 15 @ paletteNum
	.hword 0x0200 @ baseBlock

	.globl sMatchCallTextStringVars
sMatchCallTextStringVars: @ 0x85D7A1C
	.4byte gStringVar1
	.4byte gStringVar2
	.4byte gStringVar3

	.globl gUnknown_85D7A28
gUnknown_85D7A28: @ 0x85D7A28
	.string "どニのくベニのくドヌのくヘネのくuネのくけノのくナツ$クミ$ゲン$コウ$マリ$ミホ$　　"

	.globl sMultiTrainerMatchCallTexts
sMultiTrainerMatchCallTexts: @ 0x85D7A54
	.hword 0x0282 @ trainerId (US TRAINER_KIRA_AND_DAN_1)
	.hword 0
	.4byte 0x085D7A40 @ text (gText_* not yet symbolized)
	.hword 0x01E1 @ trainerId (US TRAINER_AMY_AND_LIV_1)
	.hword 0
	.4byte 0x085D7A43 @ text (gText_* not yet symbolized)
	.hword 0x02A9 @ trainerId (US TRAINER_JOHN_AND_JAY_1)
	.hword 0
	.4byte 0x085D7A46 @ text (gText_* not yet symbolized)
	.hword 0x02AF @ trainerId (US TRAINER_LILA_AND_ROY_1)
	.hword 0
	.4byte 0x085D7A49 @ text (gText_* not yet symbolized)
	.hword 0x0033 @ trainerId (US TRAINER_GABBY_AND_TY_1)
	.hword 0
	.4byte 0x085D7A4C @ text (gText_* not yet symbolized)
	.hword 0x011F @ trainerId (US TRAINER_ANNA_AND_MEG_1)
	.hword 0
	.4byte 0x085D7A4F @ text (gText_* not yet symbolized)

	.globl sBattleFrontierFacilityNames
sBattleFrontierFacilityNames: @ 0x85D7A84
	.4byte 0x085CC423 @ FRONTIER_FACILITY_TOWER (US gText_*)
	.4byte 0x085CC42A @ FRONTIER_FACILITY_DOME (US gText_*)
	.4byte 0x085CC431 @ FRONTIER_FACILITY_PALACE (US gText_*)
	.4byte 0x085CC442 @ FRONTIER_FACILITY_ARENA (US gText_*)
	.4byte 0x085CC44A @ MATCH_CALL_PIKE (US gText_*)
	.4byte 0x085CC438 @ MATCH_CALL_FACTORY (US gText_*)
	.4byte 0x085CC452 @ FRONTIER_FACILITY_PYRAMID (US gText_*)

	.globl sBadgeFlags
sBadgeFlags: @ 0x85D7AA0
	.hword 0x867 @ FLAG_BADGE01_GET
	.hword 0x868 @ FLAG_BADGE02_GET
	.hword 0x869 @ FLAG_BADGE03_GET
	.hword 0x86A @ FLAG_BADGE04_GET
	.hword 0x86B @ FLAG_BADGE05_GET
	.hword 0x86C @ FLAG_BADGE06_GET
	.hword 0x86D @ FLAG_BADGE07_GET
	.hword 0x86E @ FLAG_BADGE08_GET

	.globl sBirchDexRatingTexts
sBirchDexRatingTexts: @ 0x85D7AB0
	.4byte gBirchDexRatingText_LessThan10
	.4byte gBirchDexRatingText_LessThan20
	.4byte gBirchDexRatingText_LessThan30
	.4byte gBirchDexRatingText_LessThan40
	.4byte gBirchDexRatingText_LessThan50
	.4byte gBirchDexRatingText_LessThan60
	.4byte gBirchDexRatingText_LessThan70
	.4byte gBirchDexRatingText_LessThan80
	.4byte gBirchDexRatingText_LessThan90
	.4byte gBirchDexRatingText_LessThan100
	.4byte gBirchDexRatingText_LessThan110
	.4byte gBirchDexRatingText_LessThan120
	.4byte gBirchDexRatingText_LessThan130
	.4byte gBirchDexRatingText_LessThan140
	.4byte gBirchDexRatingText_LessThan150
	.4byte gBirchDexRatingText_LessThan160
	.4byte gBirchDexRatingText_LessThan170
	.4byte gBirchDexRatingText_LessThan180
	.4byte gBirchDexRatingText_LessThan190
	.4byte gBirchDexRatingText_LessThan200
	.4byte gBirchDexRatingText_DexCompleted

	.globl gStandardMenuPalette
gStandardMenuPalette: @ 0x85D7B04
	.incbin "graphics/misc/gStandardMenuPalette.bin"

	.globl gUnknown_85D7B24
gUnknown_85D7B24: @ 0x85D7B24
	.incbin "baserom_jp.gba", 0x5d7b24, 0x4

	.globl gUnknown_85D7B28
gUnknown_85D7B28: @ 0x85D7B28
	.incbin "baserom_jp.gba", 0x5d7b28, 0x10

	.globl gUnknown_85D7B38
gUnknown_85D7B38: @ 0x85D7B38
	.incbin "baserom_jp.gba", 0x5d7b38, 0x8

	.globl gUnknown_85D7B40
gUnknown_85D7B40: @ 0x85D7B40
	.incbin "baserom_jp.gba", 0x5d7b40, 0x8

	.globl gUnknown_85D7B48
gUnknown_85D7B48: @ 0x85D7B48
	.incbin "baserom_jp.gba", 0x5d7b48, 0x20

	.globl gUnknown_85D7B68
gUnknown_85D7B68: @ 0x85D7B68
	.incbin "baserom_jp.gba", 0x5d7b68, 0x4

	.globl gUnknown_85D7B6C
gUnknown_85D7B6C: @ 0x85D7B6C
	.incbin "baserom_jp.gba", 0x5d7b6c, 0x4

	.globl gUnknown_85D7B70
gUnknown_85D7B70: @ 0x85D7B70
	.incbin "baserom_jp.gba", 0x5d7b70, 0x68

	.globl gUnknown_85D7BD8
gUnknown_85D7BD8: @ 0x85D7BD8
	.incbin "baserom_jp.gba", 0x5d7bd8, 0x20

	.globl gUnknown_85D7BF8
gUnknown_85D7BF8: @ 0x85D7BF8
	.incbin "baserom_jp.gba", 0x5d7bf8, 0x20

	.globl gUnknown_85D7C18
gUnknown_85D7C18: @ 0x85D7C18
	.incbin "baserom_jp.gba", 0x5d7c18, 0x20

	.globl gUnknown_85D7C38
gUnknown_85D7C38: @ 0x85D7C38
	.incbin "baserom_jp.gba", 0x5d7c38, 0x2000

	.globl gUnknown_85D9C38
gUnknown_85D9C38: @ 0x85D9C38
	.incbin "baserom_jp.gba", 0x5d9c38, 0x1100

	.globl gUnknown_85DAD38
gUnknown_85DAD38: @ 0x85DAD38
	.incbin "baserom_jp.gba", 0x5dad38, 0x440

	.globl gUnknown_85DB178
gUnknown_85DB178: @ 0x85DB178
	.incbin "baserom_jp.gba", 0x5db178, 0x800

	.globl gUnknown_85DB978
gUnknown_85DB978: @ 0x85DB978
	.incbin "baserom_jp.gba", 0x5db978, 0x100

	.globl gUnknown_85DBA78
gUnknown_85DBA78: @ 0x85DBA78
	.incbin "baserom_jp.gba", 0x5dba78, 0x60

	.globl gUnknown_85DBAD8
gUnknown_85DBAD8: @ 0x85DBAD8
	.incbin "baserom_jp.gba", 0x5dbad8, 0x40

	.globl gUnknown_85DBB18
gUnknown_85DBB18: @ 0x85DBB18
	.incbin "baserom_jp.gba", 0x5dbb18, 0x20

	.globl gUnknown_85DBB38
gUnknown_85DBB38: @ 0x85DBB38
	.incbin "baserom_jp.gba", 0x5dbb38, 0x28

	.globl gUnknown_85DBB60
gUnknown_85DBB60: @ 0x85DBB60
	.incbin "baserom_jp.gba", 0x5dbb60, 0x10

	.globl gUnknown_85DBB70
gUnknown_85DBB70: @ 0x85DBB70
	.incbin "baserom_jp.gba", 0x5dbb70, 0x28

	.globl gUnknown_85DBB98
