@ SootopolisCity_House5 scripts (JP map g15 m9 @ 0x0820F657)

SootopolisCity_House5_MapScripts::
	.byte 0

SootopolisCity_House5_EventScript_Maniac:: @ 0x0820F658
	msgbox SootopolisCity_House5_Text_SootopolisMtPyreConnection, MSGBOX_NPC
	end

SootopolisCity_House5_EventScript_Girl:: @ 0x0820F661
	msgbox SootopolisCity_House5_Text_BrotherUsedToStudySea, MSGBOX_NPC
	end

SootopolisCity_House5_Text_SootopolisMtPyreConnection: @ 0x0820F66A
	.string "この　ルネシティと　おくりびやまは\n"
	.string "なにかの　かんけいが　あるらしい⋯⋯\p"
	.string "むかし　いた　けんきゅうじょで\n"
	.string "そんなことを　ともだちと　しらべていたよ$"

SootopolisCity_House5_Text_BrotherUsedToStudySea: @ 0x0820F6B4
	.string "おにいちゃん\n"
	.string "むかし　うみの　けんきゅうを　してたんだ$"
