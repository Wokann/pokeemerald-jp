@ AbandonedShip_CaptainsOffice scripts (JP map g24 m63 @ 0x0821B22D)

AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide:: @ 0x0821B22E
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner:: @ 0x0821B25C
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus:: @ 0x0821B266
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner: @ 0x0821B270
	.string "クスノキ　かんちょうに　たのまれてね\n"
	.string "このふねの　ちょうさを　しているんだ\p"
	.string "ついでに　たんちきを　さがしてきて\n"
	.string "ほしいって　いわれたんだけど\l"
	.string "みあたらないなあ⋯⋯$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner: @ 0x0821B2C2
	.string "あ！　たんちき　じゃないか！\p"
	.string "⋯⋯よかったら　それ\n"
	.string "クスノキ　かんちょうに\l"
	.string "わたしてきて　くれないかなあ\p"
	.string "もうすこし　このふね　しらべたいんだ$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus: @ 0x0821B30A
	.string "この　ふねは　カクタスごうと　いってね\n"
	.string "ちょいと　むかしの　ふね　らしいんだ$"
