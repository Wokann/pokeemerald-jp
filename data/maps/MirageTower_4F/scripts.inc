@ MirageTower_4F scripts (JP map g24 m97 @ 0x0821CE0C)

MirageTower_4F_MapScripts::
	.byte 0

MirageTower_4F_EventScript_RootFossil:: @ 0x0821CE0D
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
	giveitem ITEM_ROOT_FOSSIL
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	removeobject LOCALID_MIRAGE_ROOT_FOSSIL
	delay 30
	setflag FLAG_CHOSE_ROOT_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveRootFossil:: @ 0x0821CE44
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil:: @ 0x0821CE4E
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
	giveitem ITEM_CLAW_FOSSIL
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_MIRAGE_CLAW_FOSSIL
	delay 30
	setflag FLAG_CHOSE_CLAW_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveClawFossil:: @ 0x0821CE85
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower:: @ 0x0821CE8F
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 32 @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	warp MAP_ROUTE111, 19, 59
	waitstate
	release
	end

MirageTower_4F_Text_TakeRootFossil:: @ 0x0821CEBE
	.string "ねっこのカセキを　みつけた！\p"
	.string "この　カセキを　とると\n"
	.string "あしもとが　くずれて　しまいそうだ⋯⋯\p"
	.string "ねっこのカセキを　とりますか？$"

MirageTower_4F_Text_LeftRootFossilAlone:: @ 0x0821CEFD
	.string "{PLAYER}は　ねっこのカセキを\n"
	.string "そのままに　しておいた$"

MirageTower_4F_Text_TakeClawFossil:: @ 0x0821CF16
	.string "ツメのカセキを　みつけた！\p"
	.string "この　カセキを　とると\n"
	.string "あしもとが　くずれて　しまいそうだ⋯⋯\p"
	.string "ツメのカセキを　とりますか？$"

MirageTower_4F_Text_LeaveClawFossilAlone:: @ 0x0821CF53
	.string "{PLAYER}は　ツメのカセキを\n"
	.string "そのままに　しておいた$"
