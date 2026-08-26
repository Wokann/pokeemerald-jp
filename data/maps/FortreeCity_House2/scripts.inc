@ FortreeCity_House2 scripts (JP map g12 m5 @ 0x08204E9B)

FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver:: @ 0x08204E9C
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting:: @ 0x08204F33
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower:: @ 0x08204F3F
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess:: @ 0x08204F49
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature: @ 0x08204F53
	.string "ひとも　ポケモンも\n"
	.string "しぜんの　なかで　くらすことで\l"
	.string "もともとの　パワーが　めざめる⋯⋯$"

FortreeCity_House2_Text_CoinInWhichHand: @ 0x08204F7F
	.string "おぬしの　パワーが　めざめているか\n"
	.string "たしかめると　するかの⋯⋯\p"
	.string "どれ⋯⋯　わしの　みぎてと　ひだりて\n"
	.string "どちらに　コインが　はいっておるか\l"
	.string "ちょっかんで　えらんで　みなさい$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand: @ 0x08204FD5
	.string "おお！　せいかい　じゃ！\p"
	.string "つぎは　みぎてと　ひだりて\n"
	.string "どちらに　コインが　はいっておるか\l"
	.string "ちょっかんで　えらんで　みなさい$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2: @ 0x08205013
	.string "おお！　せいかい　じゃ！\p"
	.string "つぎは　みぎてと　ひだりて\n"
	.string "どちらに　コインが　はいっておるか\l"
	.string "ちょっかんで　えらんで　みなさい$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken: @ 0x08205051
	.string "おお！　みごと　じゃ！\n"
	.string "おぬしの　パワーは　めざめているの！\p"
	.string "これを　あげるから\n"
	.string "おぬしの　ポケモンも　パワーを\l"
	.string "めざめさせて　やると　ええぞ！$"

FortreeCity_House2_Text_ExplainHiddenPower: @ 0x0820509A
	.string "めざめるパワーは　ポケモンによって\n"
	.string "いりょくが　かわる　わざ　なんじゃよ！$"

FortreeCity_House2_Text_YouGuessedWrong: @ 0x082050C0
	.string "ざんねん⋯⋯\n"
	.string "はずれ　じゃ⋯⋯$"
