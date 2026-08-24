@ LilycoveCity_House4 scripts (JP map g13 m15 @ 0x0820A51A)

LilycoveCity_House4_MapScripts::
	.byte 0

LilycoveCity_House4_EventScript_Man1::
	msgbox LilycoveCity_House4_Text_MysteriesAtBottomOfSea, MSGBOX_NPC
	end

LilycoveCity_House4_EventScript_Man2::
	msgbox LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis, MSGBOX_NPC
	end

LilycoveCity_House4_Text_MysteriesAtBottomOfSea: @ 0x0820A52D
	.string "この　ほしの　さいだいの　なぞ\n"
	.string "それは　かいていに　あると　おもうんだ！\p"
	.string "⋯⋯というのは\n"
	.string "だれかが　いってた　ことなんだけど$"

LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis: @ 0x0820A56C
	.string "そういや　トクサネと　ルネの　あいだには\n"
	.string "ふかい　ふかい　かいこうが　ある\p"
	.string "⋯⋯そんな　はなしも\n"
	.string "だれかが　いってた　ことなんだけど$"
