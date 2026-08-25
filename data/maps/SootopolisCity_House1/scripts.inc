@ SootopolisCity_House1 scripts (JP map g15 m5 @ 0x0820F300)

SootopolisCity_House1_MapScripts::
	.byte 0

SootopolisCity_House1_EventScript_BrickBreakBlackBelt:: @ 0x0820F301
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_ReceivedBrickBreak:: @ 0x0820F338
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_Kecleon:: @ 0x0820F342
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

SootopolisCity_House1_Text_DevelopedThisTM: @ 0x0820F355
	.string "うむう⋯⋯\n"
	.string "ルネシティに　こもること　30ねん⋯⋯\p"
	.string "わしが　あみだした　ひっさつの　わざマシン！\n"
	.string "おまえに　ゆずろう！$"

SootopolisCity_House1_Text_ExplainBrickBreak: @ 0x0820F391
	.string "わざマシン31は　かわらわり！\n"
	.string "せつめい　するのも　おそろしい　わざよ⋯⋯$"

SootopolisCity_House1_Text_Kecleon: @ 0x0820F3B7
	.string "カクレオン“ぷー　ぷひゃあー$"
