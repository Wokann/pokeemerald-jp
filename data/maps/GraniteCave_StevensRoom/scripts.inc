@ GraniteCave_StevensRoom scripts (JP map g24 m10 @ 0x08214027)

GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven:: @ 0x08214028
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth:: @ 0x082140BA
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast:: @ 0x082140C5
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth:: @ 0x082140D7
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull:: @ 0x082140E9
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe: @ 0x08214107
	.string "ボクの　なまえは　ダイゴ\p"
	.string "めずらしい　いしに　きょうみが　あって\n"
	.string "あちこち　たび　してるんだよ\p"
	.string "えっ？\n"
	.string "ボクに　てがみ⋯⋯？$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis: @ 0x08214146
	.string "ダイゴ“うん　ありがとう\p"
	.string "わざわざ　とどけて　くれたんだ\n"
	.string "なにか　おれいを　させてもらうよ\p"
	.string "そうだね\n"
	.string "この　わざマシンを　あげよう\p"
	.string "はがねのつばさ　といって\n"
	.string "ボクの　おきにいりの　わざ　だから$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister: @ 0x082141A7
	.string "ダイゴ“きみの　ポケモン\n"
	.string "なかなか　いい　かんじ　だね\p"
	.string "しゅぎょうを　つづければ\n"
	.string "いつかは　ポケモンリーグの\l"
	.string "チャンピオンに　だって　なれる\l"
	.string "ボクは　そう　おもうな\p"
	.string "そうだ！\n"
	.string "せっかく　きみと　しりあえたんだ\l"
	.string "おたがい　ポケナビに\l"
	.string "なまえを　とうろく　しておこう！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

GraniteCave_StevensRoom_Text_RegisteredSteven: @ 0x08214235
	.string "ダイゴを\n"
	.string "ポケナビに　とうろく　した！$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong: @ 0x08214249
	.string "⋯⋯じゃあ\n"
	.string "ボクは　さきを　いそぐから$"

GraniteCave_StevensRoom_Text_OhBagIsFull: @ 0x0821425D
	.string "バッグが　いっぱい　なのか⋯⋯\n"
	.string "じゃあ　しかたないね$"
