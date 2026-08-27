@ MagmaHideout_2F_1R scripts (JP map g24 m87 @ 0x0821C286)

MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro::
	.string "むむむ！\p"
	.string "ここに　はいって　これるのは\n"
	.string "マグマだんの　メンバー　だけのはず！\p"
	.string "なのに　あなたは\n"
	.string "マグマだんの　ふくを　きていない⋯⋯\p"
	.string "えーい　あやしい　やつめ！\n"
	.string "わたしと　しょうぶ　しなさい！$"

MagmaHideout_2F_1R_Text_Grunt14Defeat::
	.string "あわわわ⋯⋯\n"
	.string "マグマだんの　プライドが⋯⋯$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle::
	.string "さむがりの　ひとは\n"
	.string "マグマだんに　はいると　いいわよ$"

MagmaHideout_2F_1R_Text_Grunt3Intro::
	.string "こらこら！\p"
	.string "オレの　めのまえを　だまって\n"
	.string "すどおり　させる　わけには　いかねーぞ！$"

MagmaHideout_2F_1R_Text_Grunt3Defeat::
	.string "うはっ！　まけましたっ！$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle::
	.string "こんなことなら　すどおり　していって\n"
	.string "もらうほうが　よかったかも⋯⋯$"

MagmaHideout_2F_1R_Text_Grunt4Intro::
	.string "やや！　あやしい　やつめ！$"

MagmaHideout_2F_1R_Text_Grunt4Defeat::
	.string "ぬおお⋯⋯$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle::
	.string "しょうぶに　まけたのに\n"
	.string "まだ　ここを　ぐるぐる　まわる\l"
	.string "ひつようが　あるんだろうか？$"

MagmaHideout_2F_1R_Text_Grunt5Intro::
	.string "むむ！　あやしい　やつめ！$"

MagmaHideout_2F_1R_Text_Grunt5Defeat::
	.string "うぬぬ⋯⋯$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle::
	.string "オレ　ほんとは　ポケモンしょうぶ\n"
	.string "あんまり　とくいじゃ　ないんだよね$"
