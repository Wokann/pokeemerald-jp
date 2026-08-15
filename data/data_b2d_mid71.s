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

	.globl gText_Diploma_NameTemplate
gText_Diploma_NameTemplate: @ 0x85C8C00
	.string "{COLOR 4}{SHADOW 5}$　"

	.globl sDiplomaBgTemplates
sDiplomaBgTemplates: @ 0x85C8C08
	.incbin "baserom_jp.gba", 0x5c8c08, 0x8

	.globl sDiplomaWinTemplates
sDiplomaWinTemplates: @ 0x85C8C10
	.incbin "baserom_jp.gba", 0x5c8c10, 0x10

	.globl sDiplomaTextColors
sDiplomaTextColors: @ 0x85C8C20
	.incbin "baserom_jp.gba", 0x5c8c20, 0x4

	.globl gUnknown_85C8C24
gUnknown_85C8C24: @ 0x85C8C24
	.string "$"

	.globl gUnknown_85C8C25
gUnknown_85C8C25: @ 0x85C8C25
	.string "くん$"
	.globl gUnknown_85C8C28
gUnknown_85C8C28: @ 0x85C8C28
	.string "ちゃん$サファイア$ルビー$"

	.globl gUnknown_85C8C36
