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

	.globl sText_AwaitingLinkPressStart
sText_AwaitingLinkPressStart: @ 0x82C06B8
	.string "{B_COPY_VAR_1}！　れんらくまち！\n"
	.string "にんずうが　そろったら　STARTボタン$　　　シングルバトルを　かいさいする$ダブルバトルを　かいさいする$　マルチバトルを　かいさいする$　ポケモンこうかんを　かいさいする$　　　チャットを　かいさいする$　　　ふしぎなカードをくばる$ふしぎなニュースをくばる$　　　ふしぎなできごとを　かいさいする$　　　なわとびを　かいさいする$　　　きのみマッシャーを　かいさいする$　　　きのみどりを　かいさいする$　　ぐるぐるこうかんを　かいさいする$　　　ぐるぐるショップを　かいさいする$　　　hかわくxかわく{FONT 44}くしきわくみきわくぃきわくざきわくぃきわくタきわくミきわくャきわくャきわくデきわく7きわく"

	.globl sText_1PlayerNeeded
sText_1PlayerNeeded: @ 0x82C07F4
	.string "あと1にん\n"
	.string "ひつよう$"

	.globl sText_2PlayersNeeded
sText_2PlayersNeeded: @ 0x82C07FF
	.string "あと2にん\n"
	.string "ひつよう$"

	.globl sText_3PlayersNeeded
sText_3PlayersNeeded: @ 0x82C080A
	.string "あと3にん\n"
	.string "ひつよう$"

	.globl sText_4PlayersNeeded
sText_4PlayersNeeded: @ 0x82C0815
	.string "あと4にん\n"
	.string "ひつよう$"

	.globl sText_2PlayerMode
sText_2PlayerMode: @ 0x82C0820
	.string "2にん\n"
	.string "プレイ$"

	.globl sText_3PlayerMode
sText_3PlayerMode: @ 0x82C0828
	.string "3にん\n"
	.string "プレイ$"

	.globl sText_4PlayerMode
sText_4PlayerMode: @ 0x82C0830
	.string "4にん\n"
	.string "プレイ$"

	.globl sText_5PlayerMode
sText_5PlayerMode: @ 0x82C0838
	.string "5にん\n"
	.string "プレイ$"

