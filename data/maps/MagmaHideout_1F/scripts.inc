@ MagmaHideout_1F scripts (JP map g24 m86 @ 0x0821C0F3)

MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition::
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro::
	.string "マグマだんは　ごうれいが　かかったとき\n"
	.string "はやく　せいれつした　じゅんばんで\l"
	.string "じゅうような　ばしょの\l"
	.string "けいびを　まかせて　もらえるんだぜ！\p"
	.string "オレが　こんな　すみっこに　いるのは\n"
	.string "ちこく　ばっかり　してるからさ！$"

MagmaHideout_1F_Text_Grunt1Defeat::
	.string "トレーニングにも　ちこくする　オレだ！\n"
	.string "われながら　よわいぜ⋯⋯$"

MagmaHideout_1F_Text_Grunt1PostBattle::
	.string "わかったよ　こんどから　もうすこし\n"
	.string "がんばって　みるよ⋯⋯$"

MagmaHideout_1F_Text_Grunt2Intro::
	.string "リーダーに　いわれた　とおり\n"
	.string "えんとつやまを　どんどん　ほっていたら\l"
	.string "とんでもねえモンが　でちまった！\p"
	.string "なにが　でたかって？\p"
	.string "ふははは！\n"
	.string "オレを　たおせたら　おしえて　やるよ！$"

MagmaHideout_1F_Text_Grunt2Defeat::
	.string "むぐぅ⋯⋯　たおされちまった！$"

MagmaHideout_1F_Text_Grunt2PostBattle::
	.string "やっぱり　おしえるの　やーめた！\n"
	.string "どうせ　おくまで　いけば　わかることさ！\p"
	.string "おまえも　あとに　おたのしみを\n"
	.string "のこして　おいたほうが　いいだろ？$"
