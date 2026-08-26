@ MauvilleCity_House2 scripts (JP map g10 m4 @ 0x08200C5A)

MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman:: @ 0x08200C5B
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail:: @ 0x08200C80
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade:: @ 0x08200CB6
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase:: @ 0x08200CD8
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade:: @ 0x08200CE2
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport: @ 0x08200CEC
	.string "あたしが　じてんしゃに　のれたら\n"
	.string "カイナに　いくのも　すぐなのに⋯⋯\p"
	.string "そして　カイナの　フレンドリィショップで\n"
	.string "ハーバーメールを　かえるのに⋯⋯$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase: @ 0x08200D35
	.string "それ！　ハーバーメールでしょ！\n"
	.string "コインケースと　こうかん　してくれない？$"

MauvilleCity_House2_Text_IllTradeYouCoinCase: @ 0x08200D5A
	.string "うれしい！\n"
	.string "じゃ　コインケースと　こうかんね！$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner: @ 0x08200D72
	.string "コインケースが　あれば　ゲームコーナーで\n"
	.string "ルーレットや　スロットを　たのしめるわ！$"

MauvilleCity_House2_Text_ThatsDisappointing: @ 0x08200D9C
	.string "そう⋯⋯　ざんねん　ね\p"
	.string "コインケースが　あれば　ゲームコーナーで\n"
	.string "ルーレットや　スロットを　たのしめるのに⋯⋯$"
