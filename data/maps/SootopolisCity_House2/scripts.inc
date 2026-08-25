@ SootopolisCity_House2 scripts (JP map g15 m6 @ 0x0820F3C6)

SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF:: @ 0x0820F3C7
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs:: @ 0x0820F3E9
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs:: @ 0x0820F3F2
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs: @ 0x0820F3FB
	.string "おくりびやま⋯⋯\p"
	.string "ちょうじょうに　ふたつのたまが\n"
	.string "おかれて　いるのは　ごぞんじ　ですか⋯⋯？$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide: @ 0x0820F42A
	.string "そう⋯⋯　ふたつのたまが\n"
	.string "となりあわせに　おかれている　ようすは\l"
	.string "なにか　こころが　やすらぎますよ⋯⋯$"

SootopolisCity_House2_Text_OughtToVisitAndSee: @ 0x0820F45E
	.string "そうですか⋯⋯\n"
	.string "いちど　いかれては　どうでしょう⋯⋯$"
