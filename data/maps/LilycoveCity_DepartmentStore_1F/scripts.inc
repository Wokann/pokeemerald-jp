@ LilycoveCity_DepartmentStore_1F scripts (JP map g13 m16 @ 0x0820A5AF)

LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter:: @ 0x0820A5B0
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk:: @ 0x0820A5B9
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	special EndLotteryCornerComputerEffect
	delay 10
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon:: @ 0x0820A698
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon:: @ 0x0820A6A1
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow:: @ 0x0820A6AA
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain:: @ 0x0820A6B4
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch:: @ 0x0820A6BE
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2:: @ 0x0820A6CC
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch:: @ 0x0820A6D6
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch:: @ 0x0820A6DF
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch:: @ 0x0820A6E8
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch:: @ 0x0820A6F1
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom:: @ 0x0820A6FA
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize:: @ 0x0820A70A
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier:: @ 0x0820A714
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF:: @ 0x0820A74C
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl:: @ 0x0820A755
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM:: @ 0x0820A75E
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Azumarill:: @ 0x0820A767
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign:: @ 0x0820A77A
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore: @ 0x0820A783
	.string "いらっしゃいませ！\n"
	.string "ミナモ　デパート　です$"

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings: @ 0x0820A799
	.string "デパートに　くると　たのしくなって\n"
	.string "いろんな　ものを　かっちゃうのよ$"

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture: @ 0x0820A7BC
	.string "きょうは　すてきな　かぐを\n"
	.string "おかあさんに　かって　もらうの$"

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill: @ 0x0820A7DA
	.string "コンテストで　ゆうしょうした　ごほうびに\n"
	.string "マリルリに　なにか　かって　あげるんだよ！$"

LilycoveCity_DepartmentStore_1F_Text_Azumarill: @ 0x0820A805
	.string "マリルリ“まりりるぅー！$"

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign: @ 0x0820A812
	.string "1かい　⋯⋯　サービス　カウンター\n"
	.string "　　　　　　　ちゅうせん　かいじょう\p"
	.string "2かい　⋯⋯　トレーナーズ　ゾーン\p"
	.string "3かい　⋯⋯　バトル　コレクション\p"
	.string "4かい　⋯⋯　わざマシン　コーナー\p"
	.string "5かい　⋯⋯　ぬいぐるみ　フロアー\p"
	.string "おくじょう　⋯⋯　いこいの　ひろば$"

LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun: @ 0x0820A891
	.string "むせん　つうしん　って\n"
	.string "たのしい　よね！\p"
	.string "いままで　できなかった　ことが\n"
	.string "できるようになる　きが　するの！\p"
	.string "むせんで　こうかん　できなかった\n"
	.string "ともだちも　ブーッと　できたり！\p"
	.string "なんだか　とっても\n"
	.string "わくわく　しちゃう！$"

LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm: @ 0x0820A8FE
	.string "むせん　つうしんの　たのしさを\n"
	.string "たくさんの　ひとに　つたえたいなー$"
