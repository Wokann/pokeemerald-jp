@ SlateportCity_NameRatersHouse scripts (JP map g9 m5 @ 0x081FBD9D)

SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater:: @ 0x081FBD9E
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate:: @ 0x081FBDBF
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate:: @ 0x081FBDE2
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname:: @ 0x081FBDEC
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg:: @ 0x081FBE3F
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT:: @ 0x081FBE49
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname:: @ 0x081FBE53
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent:: @ 0x081FBE7D
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname: @ 0x081FBE87
	.string "はい　はい！\n"
	.string "わたしは　せいめい　はんだんし\l"
	.string "いうなれば　なまえの　うらないです\p"
	.string "はい　あなたの　ポケモンの\n"
	.string "ニックネームを　うらなって　あげるよ$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname: @ 0x081FBED1
	.string "どの　ポケモンの\n"
	.string "ニックネームを　うらなうかね？$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne: @ 0x081FBEEA
	.string "うーむ　{STR_VAR_1}か⋯⋯\n"
	.string "なかなか　いい　ニックネームを　つけたね\p"
	.string "でもねー\n"
	.string "もう　すこしだけ　いい　なまえを\l"
	.string "わたしが　つけて　あげようか？　どうかな？$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe: @ 0x081FBF35
	.string "そうか　では\n"
	.string "どんな　ニックネームに　しようかな$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName: @ 0x081FBF4E
	.string "よし　これから\n"
	.string "この　ポケモンは　{STR_VAR_1}だ！\p"
	.string "まえより　いい　なまえ　じゃないか\n"
	.string "よかったな！$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain: @ 0x081FBF7D
	.string "そうか\n"
	.string "わかった　また　きなさいよ$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior: @ 0x081FBF8F
	.string "よし　これから\n"
	.string "この　ポケモンは　{STR_VAR_1}だ！\p"
	.string "まえと　おなじように　みえるが\n"
	.string "こっちの　ほうが　だんぜん　いいぞ！\l"
	.string "よかったな！$"

SlateportCity_NameRatersHouse_Text_MagnificentName: @ 0x081FBFCF
	.string "うーむ　{STR_VAR_1}か！\n"
	.string "これは　すばらしい　ニックネームだ！\l"
	.string "けちの　つけようもない！\p"
	.string "これからも　{STR_VAR_1}を\n"
	.string "かわいがって　あげなさいよ！$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg: @ 0x081FC011
	.string "おいおい⋯⋯\n"
	.string "それは　タマゴ　じゃないか！$"
