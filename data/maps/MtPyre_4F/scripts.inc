@ MtPyre_4F scripts (JP map g24 m18 @ 0x08216880)

MtPyre_4F_MapScripts::
	.byte 0

MtPyre_5F_EventScript_Atsushi:: @ 0x08216881
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro: @ 0x08216898
	.string "おししょうさま⋯⋯\n"
	.string "いまの　わたしの　じつりょく\l"
	.string "みていて　ください！$"

MtPyre_5F_Text_AtsushiDefeat: @ 0x082168BC
	.string "おししょうさま⋯⋯\n"
	.string "すんません⋯⋯$"

MtPyre_5F_Text_AtsushiPostBattle: @ 0x082168CE
	.string "もっと　つよくならないと\n"
	.string "ここに　ねむる　おししょうさまも\l"
	.string "あんしん　できないよな⋯⋯$"
