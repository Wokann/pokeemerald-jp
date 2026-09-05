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

	.globl gStandardMenuPalette
gStandardMenuPalette: @ 0x85D7B04
	.incbin "graphics/misc/gStandardMenuPalette.bin"

	.section .rodata.mid98_suffix_after_battle_factory_menu

	.globl sSelect_BallGfx
sSelect_BallGfx: @ 0x85DBB60
	.incbin "baserom_jp.gba", 0x5dbb60, 0x10
