@ SootopolisCity_House7 scripts (JP map g15 m11 @ 0x0820F7BA)

SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan:: @ 0x0820F7BB
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF:: @ 0x0820F7C4
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano: @ 0x0820F7CD
	.string "かいていに　あった　かざんが　ふんかして\n"
	.string "うみの　うえまで　もりあがる\p"
	.string "そして　ふんかこうに　あめが　たまって\n"
	.string "できたのが　この　ルネシティ　なんだよ$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething: @ 0x0820F819
	.string "ルネと　そとのせかいを　つなぐ　どうくつ\p"
	.string "まるで　なにかを　ここから　ださないように\n"
	.string "つくられた　みたい　だわ⋯⋯\p"
	.string "⋯⋯かんがえすぎ　かしら？$"
