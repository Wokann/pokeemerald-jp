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
	.string "にんずうが　そろったら　STARTボタン$　　　シングルバトルを　かいさいする$ダブルバトルを　かいさいする$　マルチバトルを　かいさいする$　ポケモンこうかんを　かいさいする$　　　チャットを　かいさいする$　　　ふしぎなカードをくばる$ふしぎなニュースをくばる$　　　ふしぎなできごとを　かいさいする$　　　なわとびを　かいさいする$　　　きのみマッシャーを　かいさいする$　　　きのみどりを　かいさいする$　　ぐるぐるこうかんを　かいさいする$　　　ぐるぐるショップを　かいさいする$　　　hかわくxかわく{FONT 44}くしきわくみきわくぃきわくざきわくぃきわくタきわくミきわくャきわくャきわくデきわく7きわくあと1にん\n"
	.string "ひつよう$あと2にん\n"
	.string "ひつよう$あと3にん\n"
	.string "ひつよう$あと4にん\n"
	.string "ひつよう$2にん\n"
	.string "プレイ$3にん\n"
	.string "プレイ$4にん\n"
	.string "プレイ$5にん\n"
	.string "プレイ$"
	.globl sPlayersNeededOrModeTexts
sPlayersNeededOrModeTexts: @ 0x82C0840
	.incbin "baserom_jp.gba", 0x2c0840, 0x64

