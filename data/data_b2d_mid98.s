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

	.section .rodata.mid98_suffix_after_menu_core_before_hof_pc_topbar_pal

	.globl gUnknown_85D7B40
gUnknown_85D7B40: @ 0x85D7B40
	.incbin "baserom_jp.gba", 0x5d7b40, 0x8

	.section .rodata.mid98_suffix_after_hof_pc_topbar_pal

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
