@ PetalburgCity_House2 scripts (JP map g8 m3 @ 0x081FA720)

PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader: @ 0x081FA733
	.string "この　まちの　あたらしい\n"
	.string "ジムリーダーに　なった　センリさん\p"
	.string "とおくに　すんでいた　ごかぞくを\n"
	.string "こっちに　よびよせた　らしいのよね$"

PetalburgCity_House2_Text_BattledNormanOnce: @ 0x081FA775
	.string "まえに　いちど　しょうぶ　してみたけど\n"
	.string "さすがに　センリさんは　つよいね！\p"
	.string "なんというか　こう⋯⋯\p"
	.string "‘ポケモン　ひとすじに　いきる！’\n"
	.string "っていうのを　ヒシヒシと　かんじたよ！$"
