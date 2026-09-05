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

	.section .rodata.mid98_suffix_battle_factory_menu_between

	.globl gUnknown_85DB978
gUnknown_85DB978: @ 0x85DB978
	.incbin "baserom_jp.gba", 0x5db978, 0x100

	.globl gUnknown_85DBA78
gUnknown_85DBA78: @ 0x85DBA78
	.incbin "baserom_jp.gba", 0x5dba78, 0x60

	.section .rodata.mid98_suffix_after_battle_factory_menu

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
