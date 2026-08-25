@ Route114_FossilManiacsHouse scripts (JP map g20 m0 @ 0x0821212C)

Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:: @ 0x08212132
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother:: @ 0x08212136
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig:: @ 0x08212165
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay:: @ 0x0821216F
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf:: @ 0x08212178
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother: @ 0x08212181
	.string "ぼくの　にいちゃん　かせきマニア⋯⋯\n"
	.string "かせき　だいすき　ナイスガイ　さ⋯⋯\p"
	.string "ちなみに　あなを　ほるのも　だいすきで⋯⋯\n"
	.string "この　あなも　じぶんで　ほったんだ⋯⋯\p"
	.string "これを　あげるから⋯⋯\n"
	.string "きみも　にいちゃん　みたいに\l"
	.string "あなを　ほってみなよ⋯⋯$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance: @ 0x082121F9
	.string "ちなみに　ポケモンが　あなをほると\n"
	.string "どうくつの　いりぐち　まで\l"
	.string "いっしゅんで　もどれるんだ⋯⋯$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase: @ 0x08212229
	.string "ケースのなかに　かわった　かたちの　いしが\n"
	.string "いくつも　かざってある⋯⋯$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks: @ 0x0821224D
	.string "“ちそうが　できるまで”\n"
	.string "“あめ　ふって　じめん　かたまる”\l"
	.string "“いしと　つちと　がんせきと”\p"
	.string "たくさんの　ほんが　ならんでる！$"
