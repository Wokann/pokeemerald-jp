BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "ひきかえサービス　コーナーへ\n"
	.string "ようこそ！\p"
	.string "こちらでは　おきゃくさまの　ためた\n"
	.string "バトルポイントと　すてきな　けいひんを\l"
	.string "こうかん　いたします！\p"
	.string "では　けいひんを　おえらび　ください！$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "では　けいひんを　おえらび　ください$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "キッスポスターで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "キッスクッションで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "ムチュールドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "トゲピードールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "ニャースドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "ピッピドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "メタモンドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "ヒノアラシドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "チコリータドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "ワニノコドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "ラプラスドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "カビゴンドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "フシギバナドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "リザードンドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "カメックスドールで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "タウリンで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "リゾチウムで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "ブロムヘキシンで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "キトサンで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "インドメタシンで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "マックスアップで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "ひかりのこなで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "しろいハーブで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "せんせいのツメで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "メンタルハーブで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "こだわりハチマキで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "おうじゃのしるしで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "きあいのハチマキで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "ピントレンズで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "たべのこしで　よろしい　ですか？$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "ありがとう　ございます！\p"
	.string "ごじたくの　パソコンに\n"
	.string "おおくりして　おきますね$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "どうぞ　おうけとりください！$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "おきゃくさま⋯⋯\n"
	.string "バトルポイントが　たりません⋯⋯$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "おきゃくさま⋯⋯\n"
	.string "パソコンが　いっぱいの　ようです⋯⋯$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "おきゃくさま⋯⋯\n"
	.string "それいじょう　もつことは　できません⋯⋯$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "ありがとう　ございました\p"
	.string "バトルポイントが　たまりましたら\n"
	.string "また　おこしください$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "いいなぁー　ほしいなぁー\n"
	.string "かわいい　クッションー\l"
	.string "おおきい　ぬいぐるみー\l"
	.string "ちいさい　ぬいぐるみー\l"
	.string "みんな　みんな　ほっしい　なぁー$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "まかせといてって！\p"
	.string "あんたの　ほしいもん　だったら\n"
	.string "なんでも　とって　きたるよ！！$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "ここの　どうぐが　あれば\n"
	.string "おれの　ポケモンも\l"
	.string "もっと　つよくなる！　ん！　まちがいない！$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "あーっ！？　なんだぁーっ？\p"
	.string "なーに　おれの　ぬいぐるみ　みてんだっ！\n"
	.string "ほしければ　じぶんで　てにいれろよっ！\p"
	.string "ねっ　ねっ　ムチュール　ちゃん！$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "しってる？\p"
	.string "どこの　しせつでも　そうだけど\n"
	.string "きろくを　のばしていくと\l"
	.string "もらえる　バトルポイントって\l"
	.string "だんだん　ふえて　いくんだよ！$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "ムチュールが　プリント　されている\n"
	.string "おおきなポスター$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "ムチュールの　クッション\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "ムチュールの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "トゲピーの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "ニャースの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "ピッピの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "メタモンの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "ヒノアラシの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "チコリータの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "ワニノコの　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "おおきな　ぬいぐるみ\n"
	.string "マットや　つくえの　うえに　おくもの$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "こうげきの　きそポイントを　あげる$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "とくこうの　きそポイントを　あげる$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "ぼうぎょの　きそポイントを　あげる$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "とくぼうの　きそポイントを　あげる$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "すばやさの　きそポイントを　あげる$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "たいりょくの　きそポイントを　あげる$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "もたせると　たいりょくが　せんとうの　あいだ\n"
	.string "すこしずつ　かいふくする$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "ポケモンに　もたせると　さがった\n"
	.string "のうりょくを　もとにもどす$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "ポケモンに　もたせると　せんせい　こうげきが\n"
	.string "たまに　できる$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "もたせた　ポケモンが　メロメロに\n"
	.string "なったとき　なおして　くれる$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "もたせると　ひかりが　あいてを　まどわして\n"
	.string "めいちゅうりつを　さげる$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "こうげきの　いりょくが　あがるが\n"
	.string "おなじ　わざしか　だせなくなる$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "ポケモンに　もたせると　ダメージを　うけた\n"
	.string "あいてが　たまに　ひるむ$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "ポケモンに　もたせると　たまに\n"
	.string "ひんしを　ふせぐことが　できる$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "ポケモンに　もたせると\n"
	.string "きゅうしょに　あたりやすくなる$"
