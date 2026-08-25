@ SootopolisCity_House6 scripts (JP map g15 m10 @ 0x0820F6D0)

SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman:: @ 0x0820F6D1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll:: @ 0x0820F70E
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll:: @ 0x0820F718
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll:: @ 0x0820F722
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll: @ 0x0820F738
	.string "わー　ひさしぶりの　おきゃくさん！\p"
	.string "なんだか　うれしいから\n"
	.string "ホエルコの　おおきい　ぬいぐるみ　あげる！$"

SootopolisCity_House6_Text_TakeGoodCareOfIt: @ 0x0820F76C
	.string "だいじに　してね！$"

SootopolisCity_House6_Text_IllHoldItForYou: @ 0x0820F776
	.string "ほしいけど　いまは　ダメ？\n"
	.string "じゃあ　あずかっておいて　あげるね$"

SootopolisCity_House6_Text_DontWantThisDoll: @ 0x0820F796
	.string "そうなの？\n"
	.string "ぬいぐるみ　ほしくないの？$"

SootopolisCity_House6_Text_LovePlushDolls: @ 0x0820F7AA
	.string "あたし　ぬいぐるみ　だいすき！$"
