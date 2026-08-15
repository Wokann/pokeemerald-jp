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

	.globl gUnknown_85ABBC9
gUnknown_85ABBC9: @ 0x85ABBC9
	.string "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}はい\n"
	.string "いいえ$"
	.globl gUnknown_85ABBD8
gUnknown_85ABBD8: @ 0x85ABBD8
	.string "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}いれかえる　わざを\n"
	.string "えらんで　ください${PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}${ESCAPE 3}${ESCAPE 4}$ー$HP　　$こうげき$ぼうぎょ$とくこう$とくぼう$きBコくにBコくしBコくひBコくちBコくヘ⋯コく"

	.globl gText_SafariBalls
