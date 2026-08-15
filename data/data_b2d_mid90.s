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

	.globl gUnknown_85CC341
gUnknown_85CC341: @ 0x85CC341
	.string "プレイじかん$ゲームポイント$"
	.globl gUnknown_85CC350
gUnknown_85CC350: @ 0x85CC350
	.string "のトレーナーカード$"

	.globl gUnknown_85CC35A
gUnknown_85CC35A: @ 0x85CC35A
	.string "はじめてのでんどういり　$つうしんたいせん$ケーブルたいせん$"
	.globl gUnknown_85CC379
