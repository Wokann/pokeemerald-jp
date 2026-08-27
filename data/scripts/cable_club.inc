CableClub_OnTransition:
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CableClub_EventScript_HideOrShowMysteryGiftMan::
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_ShowMysteryGiftMan
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_HideMysteryGiftMan
	goto CableClub_EventScript_ShowMysteryGiftMan
	end

CableClub_EventScript_ShowMysteryGiftMan::
	clearflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_HideMysteryGiftMan::
	setflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_MysteryGiftMan::
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_DistributeEonTicket
	goto CableClub_EventScript_TryWonderCardScript
	end

CableClub_EventScript_TryWonderCardScript::
	.byte 0xCF @ trywondercardscript
CableClub_EventScript_MysteryGiftThankYou::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_EventScript_DistributeEonTicket::
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_TryWonderCardScript
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, CableClub_EventScript_TryWonderCardScript
	msgbox MysteryGift_Text_TheresATicketForYou, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox MysteryGift_Text_TryUsingItAtLilycovePort, MSGBOX_DEFAULT
	release
	end

@ Unused.
CableClub_EventScript_MysteryGiftThankYou2::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_DEFAULT
	release
	end

CableClub_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

CableClub_EventScript_CheckTurnAttendant::
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_DontTurnAttendant
	turnobject VAR_0x8007, DIR_WEST
CableClub_EventScript_DontTurnAttendant::
	end

CableClub_OnLoad:
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_OnLoadFromTradeCenter
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_OnLoadFromRecordCorner
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_OnLoadFromUnionRoom
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_OnLoadFromBerryCrush
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_OnLoadFromGameCorner
	end

CableClub_EventScript_OnLoadFromColosseum::
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromTradeCenter::
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromRecordCorner::
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromUnionRoom::
	call 0x0824789D @ CableClub_EventScript_OpenUnionRoomBarrier
	end

CableClub_EventScript_OnLoadFromBerryCrush::
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromGameCorner::
	call 0x082478E9 @ EventScript_OpenMossdeepGameCornerBarrier
	end

CableClub_OnFrame:
	map_script_2 VAR_CABLE_CLUB_TUTORIAL_STATE, 1, CableClub_EventScript_Tutorial
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_ExitRecordCorner
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

CableClub_EventScript_ExitLinkRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call 0x082478D6 @ CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	drawboxtext 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call 0x082478FC @ EventScript_CloseMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	drawboxtext 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter
	call 0x082478D6 @ CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	drawboxtext 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_ExitRecordCorner::
	lockall
	call CableClub_EventScript_PlayerExitRecordCorner
	call 0x082478D6 @ CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	drawboxtext 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitRecordCorner::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_ExitRecordCornerRet
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
CableClub_EventScript_ExitRecordCornerRet::
	return

CableClub_EventScript_ExitUnionRoom::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom
	call 0x082478B0 @ CableClub_EventScript_CloseUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	drawboxtext 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom::
	setvar VAR_CABLE_CLUB_STATE, 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_TrainerCardDataOverwritten::
	message CableClub_Text_TrainerCardDataOverwritten
	waitmessage
	playse SE_PIN
	@ The JP flow advances immediately after the confirmation sound.
	message CableClub_Text_HopeToSeeYouAgain
	waitmessage
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom::
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, CableClub_Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime, MSGBOX_DEFAULT
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	releaseall
	end

CableClub_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub::
	message 0x08247B80 @ CableClub_Text_WelcomeWhichCableClubService
	waitmessage
	delay 28
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_UnusedWelcomeToCableClub::
	msgbox 0x08247BA4, MSGBOX_DEFAULT @ CableClub_Text_WhichService
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_SelectCableClubRoom::
	setvar VAR_0x8004, 0
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_CableClubUnlockedRecordCorner
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_CableClubUnlockedRecordCorner::
	multichoice 0, 0, MULTI_CABLE_CLUB_WITH_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_RecordCorner
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_Colosseum::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SelectBattleMode::
	message 0x08248500 @ CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode
	case 1, CableClub_EventScript_DoubleBattleMode
	case 2, CableClub_EventScript_MultiBattleMode
	case 3, CableClub_EventScript_BattleModeInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_BattleModeInfo::
	msgbox 0x08248531, MSGBOX_DEFAULT @ CableClub_Text_ExplainBattleModes
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SingleBattleMode::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_DoubleBattleMode::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle::
	msgbox 0x08247C1E, MSGBOX_DEFAULT @ CableClub_Text_NeedTwoMonsForDoubleBattle
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_MultiBattleMode::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_TryEnterColosseum::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message 0x08247C79 @ gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	@ JP retains an explicit waitstate after each wired-link attempt.
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll 0x08247D16 @ CableClub_Text_PleaseEnter
	waitmessage
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim_jp
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim_jp
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P, 6, 8
	special DoCableClubWarp
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight::
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
	case USING_MULTI_BATTLE, CableClub_EventScript_AbortLinkNeedFourPlayers
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	end

CableClub_EventScript_AbortLinkNeedFourPlayers::
	special CloseLink
	msgbox 0x08247E02, MSGBOX_DEFAULT @ CableClub_Text_NeedFourPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle::
	special CloseLink
	msgbox 0x08247DE5, MSGBOX_DEFAULT @ CableClub_Text_CantDoubleBattleWithXPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle::
	special CloseLink
	msgbox 0x08247DC8, MSGBOX_DEFAULT @ CableClub_Text_CantSingleBattleWithXPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_ConfirmNumberAndRestart::
	special CloseLink @ Redundant
	msgbox 0x08247E27, MSGBOX_DEFAULT @ CableClub_Text_PleaseConfirmNumberAndRestart
	release
	end

CableClub_EventScript_TradeCenter::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message 0x08247C79 @ gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

CableClub_EventScript_EnterTradeCenter::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll 0x08247D16 @ CableClub_Text_PleaseEnter
	waitmessage
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim_jp
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim_jp
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsToTrade::
	msgbox 0x08247C3E, MSGBOX_DEFAULT @ CableClub_Text_NeedTwoMonsToTrade
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_CantTradeEnigmaBerry::
	msgbox 0x08247C5B, MSGBOX_DEFAULT @ CableClub_Text_CantTradeEnigmaBerry
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_RecordCorner::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message 0x08247C79 @ gText_PleaseWaitForLink
	waitmessage
	special TryRecordMixLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterRecordCorner
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterRecordCorner::
	setvar VAR_0x8004, USING_RECORD_CORNER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll 0x08247D16 @ CableClub_Text_PleaseEnter
	waitmessage
	call 0x082478C3 @ CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim_jp
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim_jp
	release
	special SetCableClubWarp
	setwarp MAP_RECORD_CORNER, 8, 9
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkPlayerNotReady::
	special CloseLink
	msgbox 0x08247F3C, MSGBOX_DEFAULT @ CableClub_Text_NotSetUpForFarAwayRegion
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady::
	special CloseLink
	msgbox 0x08247F78, MSGBOX_DEFAULT @ CableClub_Text_OtherTrainerNotReady
	release
	end

CableClub_EventScript_AbortLinkConnectionError::
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady::
	special CloseLink
	msgbox 0x08247D35, MSGBOX_DEFAULT @ Text_SomeoneIsNotReadyToLink
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	msgbox 0x08247D84, MSGBOX_DEFAULT @ Text_PlayersMadeDifferentSelections
	release
	end

CableClub_EventScript_AbortLink::
	special CloseLink
	msgbox 0x08247D9F, MSGBOX_DEFAULT @ CableClub_Text_PleaseVisitAgain
	release
	end

MossdeepCity_GameCorner_1F_EventScript_AbortMinigame::
	special CloseLink
	msgbox 0x08248356, MSGBOX_DEFAULT @ MossdeepCity_GameCorner_1F_Text_ComeAgain
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp::
	special SetCableClubWarp
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants::
	special CloseLink
	msgbox 0x08247DAF, MSGBOX_DEFAULT @ CableClub_Text_IncorrectNumberOfParticipants
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg::
	special CloseLink
	msgbox 0x08247F8B, MSGBOX_DEFAULT @ CableClub_Text_YouHaveAMonThatCantBeTaken
	release
	end

CableClub_EventScript_WirelessClubAdjustements::
	msgbox 0x08243CEE, MSGBOX_DEFAULT @ gText_SorryWirelessClubAdjustments
	release
	end

CableClub_EventScript_NotReadyYet::
	msgbox 0x08243D1C, MSGBOX_DEFAULT @ gText_UndergoingAdjustments
	releaseall
	end

Movement_AttendantFaceDown:
	face_down
	step_end

@ Unused.
Movement_AttendantFaceRight:
	face_right
	step_end

Movement_AttendantFaceLeft:
	face_left
	step_end

Movement_PlayerExitLinkRoom:
	walk_down
	walk_down
	step_end

@ Unused.
Movement_PlayerApproachLinkRoomRight:
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft:
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom:
	walk_up
	step_end

@ Unused.
Movement_PlayerFaceAttendantLeft:
	face_left
	step_end

Movement_PlayerFaceAttendantRight:
	face_right
	step_end

Movement_PlayerEnterMinigameRoom:
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

EventScript_CableBoxResults::
	lockall
	setvar VAR_0x8004, 0
	special ShowLinkBattleRecords
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

EventScript_BattleColosseum_2P_PlayerSpot0::
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	end

EventScript_BattleColosseum_2P_PlayerSpot1::
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	end

EventScript_BattleColosseum_4P_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	end

EventScript_BattleColosseum_4P_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	end

EventScript_BattleColosseum_4P_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 2
	special ColosseumPlayerSpotTriggered
	end

EventScript_BattleColosseum_4P_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 3
	special ColosseumPlayerSpotTriggered
	end

EventScript_BattleColosseum_4P_CancelSpotTrigger::
	end

EventScript_TradeCenter_Chair0::
	setvar VAR_0x8005, 0
	special PlayerEnteredTradeSeat
	end

EventScript_TradeCenter_Chair1::
	setvar VAR_0x8005, 1
	special PlayerEnteredTradeSeat
	end

@ Never used
EventScript_TradeCenter_Chair2::
	setvar VAR_0x8005, 2
	special PlayerEnteredTradeSeat
	end

@ Never used
EventScript_TradeCenter_Chair3::
	setvar VAR_0x8005, 3
	special PlayerEnteredTradeSeat
	end

EventScript_RecordCenter_Spot0::
	setvar VAR_0x8005, 0
	special RecordMixingPlayerSpotTriggered
	goto_if_ne VAR_TEMP_RECORD_MIX_GIFT_ITEM, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot1::
	setvar VAR_0x8005, 1
	special RecordMixingPlayerSpotTriggered
	goto_if_ne VAR_TEMP_RECORD_MIX_GIFT_ITEM, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot2::
	setvar VAR_0x8005, 2
	special RecordMixingPlayerSpotTriggered
	goto_if_ne VAR_TEMP_RECORD_MIX_GIFT_ITEM, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot3::
	setvar VAR_0x8005, 3
	special RecordMixingPlayerSpotTriggered
	goto_if_ne VAR_TEMP_RECORD_MIX_GIFT_ITEM, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

RecordCorner_EventScript_ReceivedGiftItem::
	bufferitemname STR_VAR_2, VAR_TEMP_RECORD_MIX_GIFT_ITEM
	message 0x08247FB9 @ RecordCorner_Text_PlayerSentOverOneX
	waitmessage
	waitbuttonpress
	releaseall
	end

CableClub_EventScript_ReadTrainerCard::
	msgbox 0x08247E95, MSGBOX_DEFAULT @ CableClub_Text_GotToLookAtTrainerCard
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	@ JP waits for the trainer-card screen before ending this script.
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored::
	msgbox 0x08247EAC, MSGBOX_DEFAULT @ CableClub_Text_GotToLookAtColoredTrainerCard
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice::
	msgbox 0x08247E87, MSGBOX_DEFAULT @ CableClub_Text_TooBusyToNotice
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant::
	special Script_FacePlayer
	msgbox 0x08247ECC, MSGBOX_DEFAULT @ BattleColosseum_2P_Text_TakePlaceStartBattle
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant::
	special Script_FacePlayer
	msgbox 0x08247EEA, MSGBOX_DEFAULT @ TradeCenter_Text_TakeSeatStartTrade
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_Attendant::
	goto_if_ne VAR_TEMP_MIXED_RECORDS, 0, RecordCorner_EventScript_AlreadyMixed
	special Script_FacePlayer
	message 0x08247FA2 @ RecordCorner_Text_TakeSeatAndWait
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_AlreadyMixed::
	special Script_FacePlayer
	message 0x08247F08 @ RecordCorner_Text_ThanksForComing
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

EventScript_ConfirmLeaveCableClubRoom::
	msgbox 0x08247E4B, MSGBOX_YESNO @ Text_TerminateLinkConfirmation
	goto_if_eq VAR_RESULT, YES, EventScript_TerminateLink
	@ JP redraws the whole text box here rather than using erasebox.
	drawboxtext 0, 0, 29, 19
	releaseall
	end

EventScript_TerminateLink::
	messageautoscroll 0x08247E69 @ Text_TerminateLinkPleaseWait
	waitmessage
	special ExitLinkRoom
	end

EventScript_DoLinkRoomExit::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	@ JP waits for the return callback before ending the script.
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FACILITY_UNION_ROOM
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected
	message 0x08248690 @ CableClub_Text_WelcomeUnionRoomEnter
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_UnionRoomSelect::
	multichoice 17, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom
	case 1, CableClub_EventScript_AbortLink
	case 2, CableClub_EventScript_UnionRoomInfo
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_UnionRoomInfo::
	message 0x082486D6 @ CableClub_Text_UnionRoomInfo
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_EnterUnionRoom::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	msgbox 0x0824877D, MSGBOX_DEFAULT @ CableClub_Text_EnjoyUnionRoom
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call 0x0824789D @ CableClub_EventScript_OpenUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim_jp
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 5, 1
	waitdooranim_jp
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom::
	msgbox 0x082480DF, MSGBOX_DEFAULT @ CableClub_Text_NeedTwoMonsForUnionRoom
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom::
	msgbox 0x0824810A, MSGBOX_DEFAULT @ CableClub_Text_NoEnigmaBerryInUnionRoom
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_UnionRoomAdapterNotConnected::
	msgbox 0x08248137, MSGBOX_DEFAULT @ CableClub_Text_UnionRoomAdapterNotConnected
	release
	return

CableClub_EventScript_WirelessClubAttendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox 0x08248916, MSGBOX_YESNO @ CableClub_Text_AskAboutLinking
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking
	msgbox 0x08248951, MSGBOX_DEFAULT @ CableClub_Text_ExplainWirelessClub
	release
	return

CableClub_EventScript_DontAskAboutLinking::
	msgbox 0x08248AD9, MSGBOX_DEFAULT @ CableClub_Text_HopeYouEnjoyWirelessSystem
	release
	return
