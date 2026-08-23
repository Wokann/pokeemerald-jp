@ GraniteCave_StevensRoom scripts (JP map g24 m10 @ 0x08214027)

GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_00214028::
	lock
	faceplayer
	loadword 0x0, gJPText_00214107
	callstd 0x4
	setvar 0x8004, 0x112
	call 0x08243467
	setflag 0xBD
	loadword 0x0, gJPText_00214146
	callstd 0x4
	setorcopyvar 0x8000, 0x14F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, GraniteCave_StevensRoom_EventScript_002140E9
	loadword 0x0, gJPText_002141A7
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, gJPText_00214235
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0x131
	loadword 0x0, gJPText_00214249
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, GraniteCave_StevensRoom_EventScript_002140BA
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, GraniteCave_StevensRoom_EventScript_002140D7
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, GraniteCave_StevensRoom_EventScript_002140C5
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, GraniteCave_StevensRoom_EventScript_002140C5
	playse 0x9
	removeobject 0x1
	release
	end

GraniteCave_StevensRoom_EventScript_002140BA::
	applymovement 0x1, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0x0
	return

GraniteCave_StevensRoom_EventScript_002140C5::
	applymovement 0xFF, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement 0x1, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0x0
	return

GraniteCave_StevensRoom_EventScript_002140D7::
	applymovement 0xFF, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement 0x1, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0x0
	return

GraniteCave_StevensRoom_EventScript_002140E9::
	loadword 0x0, gJPText_0021425D
	callstd 0x4
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

	.globl gJPText_00214107
gJPText_00214107: @ 0x08214107
	.string "ボクの　なまえは　ダイゴ\p"
	.string "めずらしい　いしに　きょうみが　あって\n"
	.string "あちこち　たび　してるんだよ\p"
	.string "えっ？\n"
	.string "ボクに　てがみ⋯⋯？$"

	.globl gJPText_00214146
gJPText_00214146: @ 0x08214146
	.string "ダイゴ“うん　ありがとう\p"
	.string "わざわざ　とどけて　くれたんだ\n"
	.string "なにか　おれいを　させてもらうよ\p"
	.string "そうだね\n"
	.string "この　わざマシンを　あげよう\p"
	.string "はがねのつばさ　といって\n"
	.string "ボクの　おきにいりの　わざ　だから$"

	.globl gJPText_002141A7
gJPText_002141A7: @ 0x082141A7
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

	.globl gJPText_00214235
gJPText_00214235: @ 0x08214235
	.string "ダイゴを\n"
	.string "ポケナビに　とうろく　した！$"

	.globl gJPText_00214249
gJPText_00214249: @ 0x08214249
	.string "⋯⋯じゃあ\n"
	.string "ボクは　さきを　いそぐから$"

	.globl gJPText_0021425D
gJPText_0021425D: @ 0x0821425D
	.string "バッグが　いっぱい　なのか⋯⋯\n"
	.string "じゃあ　しかたないね$"
