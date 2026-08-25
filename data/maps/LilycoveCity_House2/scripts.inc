@ LilycoveCity_House2 scripts (JP map g13 m13 @ 0x08209FDC)

LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_FatMan:: @ 0x08209FDD
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_REST, LilycoveCity_House2_EventScript_ReceivedRest
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_REST
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_ReceivedRest:: @ 0x0820A014
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_Text_NotAwakeYetHaveThis: @ 0x0820A01E
	.string "むにゃむにゃ⋯⋯\p"
	.string "ぼく　ねぼけて　いるから\n"
	.string "これを　あげる⋯⋯$"

LilycoveCity_House2_Text_SleepIsEssential: @ 0x0820A03E
	.string "むにゃむにゃ⋯⋯\p"
	.string "ねる　こは　そだつ⋯⋯\n"
	.string "ねむって　たいりょく　かいふく⋯⋯$"
