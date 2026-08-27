@ MagmaHideout_3F_2R scripts (JP map g24 m90 @ 0x0821C7A4)

MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro::
	.string "あのな　リーダーの　いうことは\n"
	.string "オレにも　よく　わかるんだけど　な\p"
	.string "ちょうこだいポケモンを　ほりだしたり\n"
	.string "ひとの　いんせきを　よこどりしたり\l"
	.string "なんか　それって　ちょっと　やりすぎ\l"
	.string "のような　きもするんだよ　な\p"
	.string "おまえ　どう　おもう？$"

MagmaHideout_3F_2R_Text_Grunt10Defeat::
	.string "やっぱり　なんか　まちがってる　よなあ？$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle::
	.string "しょうぶに　まけて　スッキリしたよ！\p"
	.string "オレも　こんど　リーダーに　あったら\n"
	.string "じっさい　どうなのか　きいて　みるよ！$"
