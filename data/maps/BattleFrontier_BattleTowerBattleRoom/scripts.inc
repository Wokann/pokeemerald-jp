BattleFrontier_BattleTowerBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleTowerBattleRoom_OnWarp:
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects::
	setvar 0x4001, 0x1
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattleTowerBattleRoom_OnFrame:
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom::
	setvar 0x4000, 0x1
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0x0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0x0
	setvar 0x4002, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x1
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
	waitmovement 0x0
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special sub_08161E88
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent

BattleFrontier_BattleTower_EventScript_WarpToLobbyLost::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_08161E88
	setvar 0x8004, 0x3
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent::
	call BattleFrontier_EventScript_IncrementWinStreak
	setvar 0x8004, 0x4
	special sub_08161E88
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
	waitmovement 0x0
	removeobject 0x1
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	call_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0x0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0x0
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle::
	call 0x0821F8F5
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge::
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0x0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0x0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_08161E88
	setvar 0x8004, 0x3
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x2
	special sub_08161E88
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent::
	copyvar 0x400F, 0x800D
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_EventScript_IncrementWinStreak::
	setvar 0x8004, 0x11
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter::
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
	waitmovement 0x0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
	waitmovement 0x0
	playse 0x15
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_ExclamationMark
	waitmovement 0x0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_Delay48
	waitmovement 0x0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
	waitmovement 0x0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
	waitmovement 0x0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext::
	compare_var_to_value 0x4002, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay
	callstd 0x4
	setvar 0x4002, 0x1

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
	waitmessage
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel::
	call BattleFrontier_EventScript_SetBrainObjectGfx
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0x0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0x0
	addobject 0x1
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
	waitmovement 0x0
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver::
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent
	callstd 0x4
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver::
	call BattleFrontier_EventScript_IncrementWinStreak
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized
	callstd 0x4
	playfanfare 0x1D2
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime
	callstd 0x4
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold::
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe
	callstd 0x4
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold::
	call BattleFrontier_EventScript_IncrementWinStreak
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease
	callstd 0x4
	playfanfare 0x1D2
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain
	callstd 0x4
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle::
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x0
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	copyvar 0x8004, 0x40CE
	compare_var_to_value 0x8004, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
	setvar 0x8004, 0x12
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x15
	special CallFrontierUtilFunc

BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle::
	setvar 0x8004, 0xF
	special sub_08161E88
	setvar 0x8004, 0x1
	setvar 0x8005, 0x5
	special CallFrontierUtilFunc
	return

BattleFrontier_EventScript_SetBrainObjectGfx::
	setvar 0x8004, 0x16
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant:
	face_down
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle:
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter:
	set_visible
	delay_16
	walk_up
	walk_left
	walk_left
	delay_8
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit:
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay:
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant:
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby::
	copyvar 0x800D, 0x40CE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
	warp 0x1A05, 0xFF, 0x6, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles::
	warp 0x1A05, 0xFF, 0xA, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis::
	warp 0x1A05, 0xFF, 0xE, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis::
	setvar 0x8004, 0xD
	special sub_08161E88
	warp 0x1A05, 0xFF, 0x12, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge::
	setflag 0x77
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth:
	.string "ポケモンの　たいりょくを\n"
	.string "かいふくして　さしあげます$"

@ Unused
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent:
	.string "つぎは　{STRING 0x02}にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent:
	.string "つぎは　2にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent:
	.string "つぎは　3にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent:
	.string "つぎは　4にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent:
	.string "つぎは　5にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent:
	.string "つぎは　6にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent:
	.string "つぎは　7にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle:
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　しますか？$"

BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass:
	.string "{MUS_RG_VS_TRAINER}の　たたかいが\n"
	.string "フロンティアパスに　きろく　された！$"

BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame:
	.string "レポートを　かいて　しゅうりょう　しますか？$"

BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait:
	.string "レポートを　かいています！\n"
	.string "しばらく　おまちくださいませ！$"

BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge:
	.string "バトルルームの　ちょうせんを\n"
	.string "ちゅうし　しますか？$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved::
	.string "ふぐあいに　より\n"
	.string "きろく　できませんでした！$"

BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay:
	.string "⋯⋯　おきゃくさま\p"
	.string "じつは　わたくしどもの　しゅじんで　ある\n"
	.string "タワータイクーンが\l"
	.string "あなたと　たたかう　ために　まもなく\l"
	.string "バトルルームに　いらっしゃる　そうです$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden:
	.string "タワータイクーンとの　たたかい　です！\n"
	.string "かくごは　よろしい　ですか？$"

BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel:
	.string "はじめまして⋯⋯\p"
	.string "ぼくの　なまえは　リラ\n"
	.string "バトルタワーを　かんりする　もの⋯⋯\l"
	.string "タワータイクーンだ⋯⋯\p"
	.string "あなたの　うわさは\n"
	.string "いろいろと　きいて　いるよ\p"
	.string "しょうじき　ぼくには　みりょくを\n"
	.string "かんじない　こと　ばかり　だけどね⋯⋯\p"
	.string "ぼくが　あなたに　あいに　きた　りゆう⋯⋯\n"
	.string "それは　ただ　ひとつ⋯⋯$"

BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent:
	.string "あなたの　さいのうを\n"
	.string "ここに　しめしなさい⋯⋯$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized:
	.string "リラ“ふふふ　いいね⋯⋯\p"
	.string "では　フロンティアパスを⋯⋯\n"
	.string "あなたの　さいのうの　あかしを　きざもう$"

BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol:
	.string "フロンティアパスに\n"
	.string "アビリティシンボルが　きざまれた！$"

BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime:
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "あなたは　ポケモンバトルに\n"
	.string "じしんが　あるのだろ？\p"
	.string "だったら　もっと　もっと　たたかって\n"
	.string "もっと　もっと　かちぬいて　おいでよ\p"
	.string "また　あえる　そのときを\n"
	.string "ぼくは　まってる　から⋯⋯$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack:
	.string "リラ“ほんとに　きて　くれたんだね⋯⋯\p"
	.string "⋯⋯　⋯⋯　⋯⋯　⋯⋯\p"
	.string "ここまで　かちぬいた　あなた⋯⋯\n"
	.string "⋯⋯　あなたが　あいて　だったら\l"
	.string "ぼくも　てかげん　せずに　たたかえる⋯⋯\p"
	.string "ひさしぶり⋯⋯\p"
	.string "なんにも　かんがえずに\n"
	.string "たたかう　ことが　できる　なんて⋯⋯$"

BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe:
	.string "さあ　はじめようよ！$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease:
	.string "リラ“ふふっ　おめでとう⋯⋯\n"
	.string "さあ　あなたの　フロンティアパスを⋯⋯$"

BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine:
	.string "アビリティシンボルが\n"
	.string "きんいろに　かがやいた！$"

BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain:
	.string "たのしかった⋯⋯\p"
	.string "こんなに　ポケモンバトルが\n"
	.string "たのしい　なんて　はじめて⋯⋯\p"
	.string "また　あなたと　たたかえると　いいな⋯⋯$"
