@ PetalburgCity_House1 scripts (JP map g8 m2 @ 0x081FA63D)

PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man:: @ 0x081FA63E
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman:: @ 0x081FA647
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful: @ 0x081FA650
	.string "たびは　いいぞ！\p"
	.string "わしも　わかいときは　あちこちの\n"
	.string "うみや　やまを　わたりあるいた　ものだ！$"

PetalburgCity_House1_Text_GoOnAdventure: @ 0x081FA67F
	.string "あぁ⋯⋯\p"
	.string "わたしも　ポケモンと　いっしょに\n"
	.string "ぼうけんの　たびに　でかけて　みたい⋯⋯\p"
	.string "しめった　くさむらに　もぐったり\n"
	.string "ごつごつの　いわやまを　のぼったり\l"
	.string "うみの　あらなみを　わたったり\l"
	.string "まっくらな　どうくつを　さまよったり⋯⋯\p"
	.string "それでいて　ときには　じぶんの　おうちが\n"
	.string "こいしく　なったりして⋯⋯\p"
	.string "たびって　いいよね！$"
