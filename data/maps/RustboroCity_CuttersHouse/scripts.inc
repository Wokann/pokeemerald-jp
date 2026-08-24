@ RustboroCity_CuttersHouse scripts (JP map g11 m11 @ 0x08203D7C)

RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse: @ 0x08203DBC
	.string "その　めつき\n"
	.string "しなやかな　みの　こなし⋯⋯\l"
	.string "そして　きたえられた　ポケモン⋯⋯\p"
	.string "きみは　できる　トレーナーだな！\p"
	.string "なにも　いわなくて　いい\n"
	.string "わたしには　わかる　わかるのだよ！\p"
	.string "きみならば　この　ひでんマシン\n"
	.string "うまく　つかえるだろう\l"
	.string "さあ　えんりょ　せずに　もっていきたまえ！$"

RustboroCity_CuttersHouse_Text_ExplainCut: @ 0x08203E46
	.string "その　ひでんマシンは　いあいぎり！\p"
	.string "ひでんは　たたかっていない　ときでも\n"
	.string "ポケモンが　つかえる　わざ！\p"
	.string "いあいぎりを　おぼえた　ポケモンは\n"
	.string "ストーンバッジを　もっていれば\l"
	.string "ほそい　きを　きれるように　なるのだよ！\p"
	.string "しかも　ひでんマシンは　わざマシンと　ちがい\n"
	.string "つかっても　なくならないぞ！$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees: @ 0x08203ED7
	.string "この　カナズミが　おおきくなるとき\n"
	.string "おとうさん　みんなの　ために\l"
	.string "いあいぎりを　つかって\l"
	.string "あたりを　きりひらいたんだって！$"
