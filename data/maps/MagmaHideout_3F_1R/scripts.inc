@ MagmaHideout_3F_1R scripts (JP map g24 m89 @ 0x0821C668)

MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9:: @ 0x0821C669
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16:: @ 0x0821C680
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:: @ 0x0821C697
	.string "なんで　オレは　こんなところの\n"
	.string "たんとう　なんだよ！\p"
	.string "ひだりのみみ　が　あつい　じゃねーか！$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:: @ 0x0821C6C6
	.string "あつくて　ヘロヘロ⋯⋯$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:: @ 0x0821C6D2
	.string "こんな　マグマだらけの　かざんの　なかで\n"
	.string "フードを　かぶってる　オレたち　へん？$"

MagmaHideout_3F_1R_Text_Grunt16Intro:: @ 0x0821C6FB
	.string "アタシたちは　リーダーが　めざしている\n"
	.string "すばらしい　もくてきを\l"
	.string "じつげん　するために　あつまったの！\p"
	.string "アクアだん　だろうが\n"
	.string "とおりすがりの　おこさま　だろうが\l"
	.string "じゃまを　するなら　ゆるさないわ！$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:: @ 0x0821C75D
	.string "ひえー　あなどれない　ひと！$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:: @ 0x0821C76C
	.string "いい？　ただしいのは　マグマだんよ！\n"
	.string "アクアだんの　いうことなんか\l"
	.string "うそ　ばっかりだから　しんじちゃ　ダメよ！$"
