@ MtPyre_1F scripts (JP map g24 m15 @ 0x08216119)

MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman:: @ 0x0821611A
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag:: @ 0x08216149
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF:: @ 0x08216153
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man:: @ 0x0821615C
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood: @ 0x08216165
	.string "この　おくりびやま　には\n"
	.string "いろんな　ものが　さまよっておる⋯⋯\p"
	.string "なにが　おきるか　わからん\n"
	.string "ねんのため　これを　もっていきなされ$"

MtPyre_1F_Text_ExplainCleanseTag: @ 0x082161A6
	.string "きよめのおふだ　をな\n"
	.string "ポケモンに　もたせて　おく\p"
	.string "すると　やせいの　ポケモンが\n"
	.string "あんまり　とびだして　こなくなるぞよ$"

MtPyre_1F_Text_ComeToPayRespects: @ 0x082161E1
	.string "あなたも　おはか　まいりに　きたの？\n"
	.string "ずいぶんと　ポケモン　おもい　なのね$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon: @ 0x08216207
	.string "ここには　ぼくが　たいせつに　していた\n"
	.string "ジグザグマが　やすらかに　ねむってる⋯⋯$"
