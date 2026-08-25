@ Route111_OldLadysRestStop scripts (JP map g18 m1 @ 0x08211DED)

Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:: @ 0x08211DF3
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady:: @ 0x08211DF7
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest:: @ 0x08211E18
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest:: @ 0x08211E45
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere: @ 0x08211E4F
	.string "あらあら　あなたの　ポケモン\n"
	.string "つかれてるんじゃ　ないかえ？\p"
	.string "よかったら　やすんで　おいき！\n"
	.string "そうだ　それがいい！　そうしなさい！$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp: @ 0x08211E90
	.string "そうそう\n"
	.string "ここで　ゆっくり　して　おいき！$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest: @ 0x08211EA6
	.string "あらあら\n"
	.string "まだ　つかれてるんじゃ　ないかえ？\p"
	.string "もういちど　やすんで　おいき！\n"
	.string "そうだ　それがいい！　そうしなさい！$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy: @ 0x08211EE0
	.string "そうかね⋯⋯\n"
	.string "ほんとうに　だいじょうぶ　かえ？\l"
	.string "えんりょ　しなくたって　いいんだよ$"
