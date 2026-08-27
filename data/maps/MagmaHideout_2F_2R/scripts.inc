@ MagmaHideout_2F_2R scripts (JP map g24 m88 @ 0x0821C445)

MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro::
	.string "あなたに　うらみは　ないけど\n"
	.string "これも　めいれい　だからね！$"

MagmaHideout_2F_2R_Text_Grunt15Defeat::
	.string "わたしは　まけたけど⋯⋯$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle::
	.string "とんでもないものを　ほりだした！\n"
	.string "あいいろのたまも　てにいれた！\p"
	.string "あとは　リーダーが⋯⋯\n"
	.string "ふふふ⋯⋯　ふはははは！$"

MagmaHideout_2F_2R_Text_Grunt6Intro::
	.string "オレって　あつがり　なんだよ\n"
	.string "もしかして　アクアだんに　はいったほうが\l"
	.string "よかったのかな？$"

MagmaHideout_2F_2R_Text_Grunt6Defeat::
	.string "やっぱり　オレ\n"
	.string "マグマだんには　むいてないかも⋯⋯$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle::
	.string "こんなところに　いると\n"
	.string "うみが　こいしく　なったり　しないか？$"

MagmaHideout_2F_2R_Text_Grunt7Intro::
	.string "ときどき　じひびきが　きこえるんだよ\p"
	.string "それって　かざんの　しんどう　かな？\n"
	.string "それとも　グラ⋯⋯\p"
	.string "おっとっと　なんでもないよ！$"

MagmaHideout_2F_2R_Text_Grunt7Defeat::
	.string "うーむ\n"
	.string "かざんのように　あついな　きみは！$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle::
	.string "オレは　たまたま　おまえに　まけたが\n"
	.string "マグマだんの　もくてきは\l"
	.string "まもなく　たっせい　されるのさ！$"

MagmaHideout_2F_2R_Text_Grunt8Intro::
	.string "マグマのしるしを　どこかに　おとした\n"
	.string "って　おおさわぎ　してるやつが　いたけど\p"
	.string "⋯⋯あ！　もしかして\n"
	.string "それ　ひろったの　おまえ？$"

MagmaHideout_2F_2R_Text_Grunt8Defeat::
	.string "うーん　なんて　やつだ⋯⋯$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle::
	.string "なんか⋯⋯　オレたちの　けいかく\n"
	.string "しっぱい　するような　きが　してきたよ$"
