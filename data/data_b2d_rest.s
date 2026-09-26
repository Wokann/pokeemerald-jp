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


	.globl gUnknown_85AB057
gUnknown_85AB057: @ 0x85AB057
	.incbin "baserom_jp.gba", 0x5ab057, 0x35

	.globl gUnknown_85AB08C
gUnknown_85AB08C: @ 0x85AB08C
	.string "キ⋯コくス⋯コくナ⋯コくヘ⋯コくメ⋯コくラ⋯コくワ⋯コくャ⋯コくからすぎた！$しぶすぎた！$あますぎた！$にがすぎた！$すっぱすぎた！$"
	.globl gUnknown_85AB0D0
gUnknown_85AB0D0: @ 0x85AB0D0
	.string "？⋯コく‘⋯コく/⋯コくG⋯コくN⋯コく{B_PLAYER_NAME}は　\n"
	.string "{B_LAST_ITEM}を　つかった！$ミツルは　\n"
	.string "{B_LAST_ITEM}を　つかった！${B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
	.string "{B_LAST_ITEM}を　つかった！$トレーナーに　ボールを　はじかれた！$ひとの　ものを　とったら　どろぼう！$よけられた！\n"
	.string "こいつは　つかまりそうにないぞ！$ポケモンに\n"
	.string "うまく　あたらなかった！$だめだ！　ポケモンが\n"
	.string "ボールから　でてしまった！$ああ！\n"
	.string "つかまえたと　おもったのに！$ざんねん！\n"
	.string "もうすこしで　つかまえられたのに！$おしい！\n"
	.string "あと　ちょっとの　ところだったのに！$やったー！\n"
	.string "{B_OPPONENT_MON1_NAME}を　つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"
	.string "$やったー！\n"
	.string "{B_OPPONENT_MON1_NAME}を　つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}$つかまえた　{B_OPPONENT_MON1_NAME}に\n"
	.string "ニックネームを　つけますか？${B_OPPONENT_MON1_NAME}は　{B_PC_CREATOR_NAME}　パソコンに\n"
	.string "てんそうされた！$"
	.globl gUnknown_85AB225
gUnknown_85AB225: @ 0x85AB225
	.string "だれかの$"
	.globl gUnknown_85AB22A
gUnknown_85AB22A: @ 0x85AB22A
	.string "マユミの${B_OPPONENT_MON1_NAME}の　データが　あたらしく\n"
	.string "ポケモンずかんに　セーブされます！\p"
	.string "$あめが　ふっている$すなあらしが　ふきあれている$ボックスが　いっぱいで\n"
	.string "これいじょう　つかまえられない！\p$"
	.globl gUnknown_85AB288
gUnknown_85AB288: @ 0x85AB288
	.string "ナゾのみ$"

	.globl gUnknown_85AB28D
gUnknown_85AB28D: @ 0x85AB28D
	.string "のみ${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "まひが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "どくが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "やけどが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "こおりじょうたいが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "ねむりから　さめた！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "こんらんが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "{B_BUFF1}じょうたいが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "じょうたいいじょうが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "たいりょくを　かいふくした！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "{B_BUFF1}の　わざポイントを　かいふくした！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "ステータスを　もとに　もどした！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "すこし　かいふく${B_LAST_ITEM}の　こうかで\n"
	.string "{B_CURRENT_MOVE}しか　だすことができない！\p"
	.string "${B_DEF_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "もちこたえた！$"
	.globl gUnknown_85AB3BD
gUnknown_85AB3BD: @ 0x85AB3BD
	.string "　$ここで　ボールを　なげるんだね\n"
	.string "ぼく⋯⋯　やってみるよ！$"
	.globl gUnknown_85AB3DC
gUnknown_85AB3DC: @ 0x85AB3DC
	.incbin "baserom_jp.gba", 0x5ab3dc, 0x5c4

	.section .rodata.battle_message_suffix,"a",%progbits
	.globl gUnknown_85ABAEE
gUnknown_85ABAEE: @ 0x85ABAEE
	.string "と　も　ウ　ィ　\l"
	.string "　ぶあ$$"
