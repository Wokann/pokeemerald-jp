@ SeafloorCavern_Room1 scripts (JP map g24 m28 @ 0x0821865E)

SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1:: @ 0x0821865F
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2:: @ 0x08218676
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro: @ 0x0821868D
	.string "こどもに　ようは　ねーんだ\n"
	.string "ほら　さっさと　かえれよ！$"

SeafloorCavern_Room1_Text_Grunt1Defeat: @ 0x082186A9
	.string "おれが　かえりたいよー！$"

SeafloorCavern_Room1_Text_Grunt1PostBattle: @ 0x082186B6
	.string "はやく　かんぶに　なって\n"
	.string "したっぱを　しごいて　やりたい⋯⋯$"

SeafloorCavern_Room1_Text_Grunt2Intro: @ 0x082186D5
	.string "せんすいてい　ちっちゃいからよー\n"
	.string "からだの　あちこちが　いたい　じゃねーか！$"

SeafloorCavern_Room1_Text_Grunt2Defeat: @ 0x082186FC
	.string "まけたら\n"
	.string "いたい　じゃねーか！$"

SeafloorCavern_Room1_Text_Grunt2PostBattle: @ 0x0821870C
	.string "うばった　せんすいていの　のりごこち\n"
	.string "ありゃ　さいあく　だな！\l"
	.string "とにかく　せますぎ　じゃねーか！$"
