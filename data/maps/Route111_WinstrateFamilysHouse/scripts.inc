@ Route111_WinstrateFamilysHouse scripts (JP map g18 m0 @ 0x08211AF4)

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor:: @ 0x08211AF5
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria:: @ 0x08211B0A
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace:: @ 0x08211B42
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi:: @ 0x08211B50
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky:: @ 0x08211B65
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo:: @ 0x08211B86
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection:: @ 0x08211B94
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou: @ 0x08211BA1
	.string "きみほど　ポケモンを　じょうずに\n"
	.string "つかいこなす　トレーナーは　はじめてだ！\p"
	.string "だが　きみよりも\n"
	.string "わたしの　むすこの　ほうが　つよいぞ！\p"
	.string "なんたって　ポケモン　リーグへ\n"
	.string "ちょうせんに　いった　ぐらい　だからな！$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace: @ 0x08211C09
	.string "この　きょうせいギプスを　つかって\n"
	.string "わたしたち　かぞくは\l"
	.string "ポケモンを　きたえて　います！\p"
	.string "わたしたち　かぞく　ぜんいんに　かった\n"
	.string "あなたには　ひつようない　かもしれませんが\l"
	.string "ぜひ　うけとって　くださいな！$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles: @ 0x08211C70
	.string "わたしたちは　ポケモンでの　しょうぶに\n"
	.string "じょうねつを　そそいで　います！$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers: @ 0x08211C95
	.string "パパより　ママが　つよくて\p"
	.string "ママより　あたしが　つよくて\p"
	.string "あたしより　おばあちゃんが　つよくて\p"
	.string "でも　おばあちゃんより　つよかったのが\n"
	.string "あたしの　あにき　なの！$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong: @ 0x08211CE6
	.string "あんたが　いくら　つよくても\n"
	.string "わしの　まごに　あったら\l"
	.string "かてなくて　なきだすこと　じゃろう⋯⋯\p"
	.string "わしら　かぞくが　しってる　トレーナーの\n"
	.string "だれよりも　つよかった　からのう！\p"
	.string "まごの　やつも　いまごろは\n"
	.string "ポケモンリーグの　チャンピオンに\l"
	.string "ちょうせん　しているの　じゃろうか？\p"
	.string "それとも　わしの　まご　じゃから\n"
	.string "もう　チャンピオン　かもな⋯⋯　ウヒヒ！$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort: @ 0x08211D95
	.string "まごの　やつも　いまごろは\n"
	.string "ポケモンリーグの　チャンピオンに\l"
	.string "ちょうせん　しているの　じゃろうか？\p"
	.string "それとも　わしの　まご　じゃから\n"
	.string "もう　チャンピオン　かもな⋯⋯　ウヒヒ！$"
