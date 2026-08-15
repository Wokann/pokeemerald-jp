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

	.globl gText_Yes
gText_Yes: @ 0x85CAAD8
	.string "はい$"
	.globl gText_No
gText_No: @ 0x85CAADB
	.string "いいえ$せつめい$シングルバトル$ダブルバトル$マルチバトル$ハギ$ちょうせんする$せつめいをきく$"
	.globl gUnknown_85CAB0D
gUnknown_85CAB0D: @ 0x85CAB0D
	.string "レベル50$"

	.globl gUnknown_85CAB13
gUnknown_85CAB13: @ 0x85CAB13
	.string "オープンレベル$おいしいみず　200¥$サイコソーダ　300¥$ミックスオレ　350¥$はしりかた$まがるコツ$すなのさか$ウイリー$ダニエル$ジャンプ$まんぞく$ふまん$しんかいのキバ$しんかいのウロコ$あおいビードロ$きいろビードロ$あかいビードロ$しろいビードロ$くろいビードロ$ガラスのいす$ガラスのつくえ$キモリドール　　　1000まい$アチャモドール　　1000まい$ミズゴロウドール　1000まい$　50まい　　1000¥$500まい　10000¥$ばつぐん$あんまり$あかいかけら$きいろいかけら$あおいかけら$みどりのかけら$バトルフロンティア$みぎ$ひだり$わざマシン32　　1500まい$わざマシン29　　3500まい$わざマシン35　　4000まい$わざマシン24　　4000まい$わざマシン13　　4000まい$"
	.globl gUnknown_85CAC84
