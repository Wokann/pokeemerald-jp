@ SeafloorCavern_Room4 scripts (JP map g24 m31 @ 0x0821892E)

SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3:: @ 0x0821892F
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4:: @ 0x08218946
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro: @ 0x0821895D
	.string "だれだ　おまえ？\n"
	.string "どこから　はいってきた？$"

SeafloorCavern_Room4_Text_Grunt3Defeat: @ 0x08218973
	.string "まけた⋯⋯！$"

SeafloorCavern_Room4_Text_Grunt3PostBattle: @ 0x0821897A
	.string "でぐちが　わかんねーんだよ\p"
	.string "こわがってる　わけじゃ　ねーぞ\n"
	.string "かんちがい　すんなよ！$"

SeafloorCavern_Room4_Text_Grunt4Intro: @ 0x082189A4
	.string "あなた　だれ？\n"
	.string "どこへ　いこうってのよ！？$"

SeafloorCavern_Room4_Text_Grunt4Defeat: @ 0x082189BA
	.string "かてなかった⋯⋯！$"

SeafloorCavern_Room4_Text_Grunt4PostBattle: @ 0x082189C4
	.string "このひとったら　せんすいていに\n"
	.string "ちずを　わすれて　きちゃったの！\p"
	.string "まったく　たよりに　なんないんだから！$"
