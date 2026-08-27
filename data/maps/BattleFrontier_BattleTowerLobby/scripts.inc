BattleFrontier_BattleTowerLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_OnWarp
	.byte 0

BattleFrontier_BattleTowerLobby_OnResume:
	special sub_08165248
	end

BattleFrontier_BattleTowerLobby_OnTransition:
	call 0x0825409C
	apprentice_shouldcheckgone
	goto_if_eq VAR_0x8004, FALSE, BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice  @ VAR_0x8004 always TRUE here
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventScript_HideApprentice
BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice::
	clearflag FLAG_HIDE_APPRENTICE
	apprentice_setgfx
BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice::
	end

BattleFrontier_BattleTowerLobby_EventScript_HideApprentice::
	setflag FLAG_HIDE_APPRENTICE
	goto BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice

BattleFrontier_BattleTowerLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleTowerLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_WonChallenge::
	lock
	faceplayer
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons

BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden::
	msgbox BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons::
	tower_giveribbons
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 49, BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_LostChallenge::
	goto_if_ne VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
	waitmessage
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle::
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	tower_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	case 0, BattleFrontier_EventScript_SaveBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle

BattleFrontier_EventScript_SaveBattle::
	frontier_savebattle
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_EventScript_BattleSaveFailed
	playse SE_SAVE
	msgbox 0x08222412, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle

BattleFrontier_EventScript_BattleSaveFailed::
	msgbox 0x0822247E, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle::
	return

BattleFrontier_EventScript_GetCantRecordBattle::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	return

BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge::
	lock
	faceplayer
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn::
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	return

BattleFrontier_BattleTowerLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge::
	setvar 0x40CE, 0x0
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_SelectThreeMons
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat 0x1E
	setvar 0x40BC, 0x1
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge::
	setvar 0x40CE, 0x1
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x4
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_MultisAttendant::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	clearflag 0x152
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge::
	setvar 0x40CE, 0x2
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_LinkMultisAttendant::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge::
	setvar 0x40CE, 0x3
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special sub_08161E88
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat 0x1E
	specialvar 0x800D, IsWirelessAdapterConnected
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower
	waitmessage
	multichoice 0x10, 0x4, 0x6D, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin
	callstd 0x4
	setvar 0x8004, 0x1
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon
	callstd 0x4
	setvar 0x8004, 0x2
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost
	callstd 0x4
	setvar 0x8004, 0x3
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings::
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ChangedYourMind
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_Woman::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded
	callstd 0x2
	end

BattleFrontier_BattleTowerLobby_EventScript_Boy::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins
	callstd 0x2
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowSinglesResults::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowDoublesResults::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowMultisResults::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x2
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowLinkMultisResults::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50::
	copyvar 0x8000, 0x40CE
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen::
	copyvar 0x8000, 0x40CE
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty

BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge::
	special CloseLink
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_EnterElevator::
	special SavePlayerParty
	setvar 0x8004, 0x3
	call BattleFrontier_BattleTowerLobby_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar 0x800D, 0x0

BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad::
	setvar 0x8004, 0xC
	special sub_08161E88
	delay 0x1
	compare_var_to_value 0x800D, 0x6
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad
	call BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom
	clearflag 0x77
	warp 0x1A06, 0xFF, 0x1, 0x6
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom::
	call BattleFrontier_BattleTowerLobby_EventScript_BufferModeText
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator

BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom::
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
	waitmessage
	delay 0x30

BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator::
	closemessage
	call BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo
	call BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord
	applymovement 0x800F, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	applymovement 0xFF, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	waitmovement 0x0
	opendoor 0x8004, 0x1
	waitmoncry
	applymovement 0x800F, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
	applymovement 0xFF, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
	waitmovement 0x0
	closedoor 0x8004, 0x1
	waitmoncry
	return

BattleFrontier_BattleTowerLobby_Movement_WalkToElevator:
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Unused
BattleFrontier_BattleTowerLobby_Movement_UnusedEnterElevator:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end
BattleFrontier_BattleTowerLobby_EventScript_BufferModeText::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle::
	bufferstdstring 0x0, 0x13
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble::
	bufferstdstring 0x0, 0x14
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti::
	bufferstdstring 0x0, 0x15
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti::
	bufferstdstring 0x0, 0x16
	return

BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant::
	setvar 0x800F, 0x1
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant::
	setvar 0x800F, 0x7
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant::
	setvar 0x800F, 0x8
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant::
	setvar 0x800F, 0x9
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles::
	setvar 0x8004, 0x6
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles::
	setvar 0x8004, 0xA
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis::
	setvar 0x8004, 0xE
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis::
	setvar 0x8004, 0x12
	return

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize
	return

BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize::
	setvar 0x8005, 0x3
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize::
	setvar 0x8005, 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize::
	setvar 0x8005, 0x2
	return

BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize::
	setvar 0x8005, 0x2
	return

BattleFrontier_EventScript_GetLvlMode::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink::
	setvar 0x8004, 0x9
	message 0x08247C79
	waitmessage
	setvar 0x8005, 0x0
	special TryBattleLinkup
	waitstate
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x08246FBE
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x08246FB1
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	compare_var_to_value 0x8005, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection
	loadword 0x0, 0x08247D84
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode
	callstd 0x4
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers
	callstd 0x4
	special CloseLink
	loadword 0x0, 0x08247DAF
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLink::
	special CloseLink
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon
	compare_var_to_value 0x8005, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful::
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	special sub_080A0194
	waitstate
	playse 0x37
	waitse
	special TrySetBattleTowerLinkType
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink::
	setvar 0x8004, 0x14
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	end

BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader::
	message 0x082485D7
	waitmessage
	multichoice 0x10, 0x6, 0x51, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader::
	call 0x0824780F
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup::
	call 0x08247814
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful::
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	special sub_080A0194
	waitstate
	playse 0x37
	waitse
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesBoard::
	lockall
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_RulesAreListed
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 0x11, 0x2, 0x61, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_RulesTower
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_RulesMons
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_RulesSalon
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesTower::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesMons::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainMonRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesSalon::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleTowerLobby_Text_DirectYouToBattleRoom: @ 0x0822059B
	.string "それでは　バトルルームへ\n"
	.string "ごあんない　します！$"

BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting: @ 0x082205B3
	.string "おきゃくさま！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたね？\p"
	.string "もうしわけ　ありませんが　そのばあい\n"
	.string "ちょうせんは　むこうと　なります$"

BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven: @ 0x08220604
	.string "おめでとう　ございます！\n"
	.string "みごと　7にんぬき　されましたね！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_EarnedFabulousPrize: @ 0x08220624
	.string "7にんぬきを　たっせい　されましたので\n"
	.string "この　しょうひんを　さしあげます！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ReceivedPrize: @ 0x0822064B
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

BattleFrontier_BattleTowerLobby_Text_BagFullMakeRoom: @ 0x08220659
	.string "⋯あら　どうぐが　いっぱいですね\p"
	.string "どうぐを　せいりしてから\n"
	.string "またおこしください$"

BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying: @ 0x08220681
	.string "おつかれさまでした！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved: @ 0x0822068D
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちください$"

BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou: @ 0x082206A8
	.string "おまちしておりました！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved: @ 0x082206B5
	.string "バトルルームに　ごあんないする　まえに\n"
	.string "レポートを　かきますので　おまちください$"

BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer: @ 0x082206DE
	.string "いよいよ　つぎは　50にんめの\n"
	.string "トレーナー　ですね！\p"
	.string "これからは　7にんを　かちぬく　たびに\n"
	.string "あなたの　ポケモンに　きねんリボンが\l"
	.string "おくられますので　がんばって　くださいね！$"

BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons: @ 0x08220736
	.string "つよい　トレーナー　7にんを\n"
	.string "かちぬいた　きねんの　リボンを　どうぞ！\p"
	.string "{PLAYER}は　リボンを　もらった！$"

BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons: @ 0x08220769
	.string "{PLAYER}は　ポケモンに\n"
	.string "リボンを　つけて　あげた！$"

BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower: @ 0x08220781
	.string "ねえねえ！\p"
	.string "バトルタワーで　これから　しょうぶだ！\n"
	.string "⋯⋯ってとき　とか\p"
	.string "かったり　まけたり　したときって\n"
	.string "どんな　きもち　なのか　おしえてよ！$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin: @ 0x082207C9
	.string "じゃあ　さっそく\n"
	.string "しょうぶに　いどむときの　きもちを⋯⋯$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon: @ 0x082207E6
	.string "じゃあ　しょうぶに　かったときの\n"
	.string "きもちを　きかせて　もらおうかなー$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost: @ 0x08220809
	.string "しょうぶに　まけちゃったとき\n"
	.string "どんな　きもちを　なるか　きかせて！$"

BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt: @ 0x0822082B
	.string "とくに　なにも　おもわないって　こと？\n"
	.string "きみって　クールなんだね$"

BattleFrontier_BattleTowerLobby_Text_ChangedYourMind: @ 0x0822084C
	.string "あれ？　やっぱり　やめたの？\n"
	.string "きみって　きまぐれ　なんだね$"

BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel: @ 0x0822086A
	.string "へえ　そんな　きぶんに　なるんだ！\n"
	.string "なかなか　こせいてき　だね⋯⋯\p"
	.string "どうも　ありがと！$"

BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded: @ 0x08220896
	.string "かちぬいた　トレーナーの　にんずうは\n"
	.string "きろく　されて　いるのよ！\p"
	.string "はずかしく　ない　たたかいを\n"
	.string "しなきゃ⋯⋯！$"

BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins: @ 0x082208CE
	.string "いちど　バトルタワーに　はいれば\n"
	.string "とちゅうで　まけちゃうか\l"
	.string "7にん　かちぬくまでは\l"
	.string "でられなく　なっちゃうんだ！\p"
	.string "かくごして　チャレンジ　しないとね！$"

BattleFrontier_BattleTowerLobby_Text_DoubleBattleRoomConstruction: @ 0x0822091A
	.string "バトルタワー　ダブルバトルコーナーへ\n"
	.string "ようこそ！\p"
	.string "げんざい　バトルルームは　こうじちゅうです\n"
	.string "かんせいまで　しばらく　おまちください$"

BattleFrontier_BattleTowerLobby_Text_MultiBattleRoomConstruction: @ 0x0822095D
	.string "バトルタワー　マルチバトルコーナーへ\n"
	.string "ようこそ！\p"
	.string "げんざい　バトルルームは　こうじちゅうです\n"
	.string "かんせいまで　しばらく　おまちください$"

BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge: @ 0x082209A0
	.string "またの　ちょうせんを\n"
	.string "おまちして　おります！$"

BattleFrontier_BattleTowerLobby_Text_WhichLevelMode: @ 0x082209B7
	.string "バトルルームには\n"
	.string "レベル50と　オープンレベルと　ありますが\l"
	.string "どちらに　はいりますか？$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectMons: @ 0x082209E3
	.string "では　さんかする　ポケモンを\n"
	.string "おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering: @ 0x082209FD
	.string "ごあんないする　まえに\n"
	.string "レポートを　かきますが　よろしいですか？$"

BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom: @ 0x08220A1E
	.string "それでは　{STR_VAR_1}　バトルルームに\n"
	.string "ごあんない　いたします！$"

BattleFrontier_BattleTowerLobby_Text_RecordLastMatch: @ 0x08220A3B
	.string "バトルタワーで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　しますか？$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50: @ 0x08220A68
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　{STR_VAR_2}ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "{STR_VAR_2}ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpen: @ 0x08220B16
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　{STR_VAR_2}ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "{STR_VAR_2}ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles: @ 0x08220BB9
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　3ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "3ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles: @ 0x08220C65
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　3ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "3ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles: @ 0x08220D06
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　4ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "4ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles: @ 0x08220DB2
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　4ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "4ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis: @ 0x08220E53
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　2ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "2ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis: @ 0x08220EFF
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　2ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "2ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle: @ 0x08220FA0
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは　シングル　バトルルームの\n"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge: @ 0x08220FE6
	.string "シングル　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge: @ 0x08221000
	.string "バトルタワー　シングル　バトルルームは\n"
	.string "3ひきの　ポケモンで\l"
	.string "シングルバトルを　おこなう　しせつです！\p"
	.string "タワーには　シングル　バトルルーム　という\n"
	.string "たいせんの　ための　へやが\l"
	.string "たくさん　ようい　されています！\p"
	.string "それぞれの　シングル　バトルルームには\n"
	.string "7にんの　トレーナーが　いて\l"
	.string "あなたの　チャレンジを　まっています！\p"
	.string "みごと　その　7にんを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは　しっかりと\l"
	.string "レポートに　かいて　おわらせないと\l"
	.string "ちょうせんは　むこうに　なってしまうので\l"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_SelectThreeMons: @ 0x08221126
	.string "では　さんかする　ポケモンを\n"
	.string "3ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle: @ 0x08221144
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは　ダブル　バトルルームの\n"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge: @ 0x08221189
	.string "ダブル　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge: @ 0x082211A2
	.string "バトルタワー　ダブル　バトルルームは\n"
	.string "4ひきの　ポケモンで\l"
	.string "ダブルバトルを　おこなう　しせつです！\p"
	.string "タワーには　ダブル　バトルルーム　という\n"
	.string "たいせんの　ための　へやが\l"
	.string "たくさん　ようい　されています！\p"
	.string "それぞれの　ダブル　バトルルームには\n"
	.string "7にんの　トレーナーが　いて\l"
	.string "あなたの　チャレンジを　まっています！\p"
	.string "みごと　その　7にんを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは　しっかりと\l"
	.string "レポートに　かいて　おわらせないと\l"
	.string "ちょうせんは　むこうに　なってしまうので\l"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons: @ 0x082212C4
	.string "では　さんかする　ポケモンを\n"
	.string "4ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle: @ 0x082212E2
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは　マルチ　バトルルームの\n"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge: @ 0x08221327
	.string "マルチ　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge: @ 0x08221340
	.string "マルチ　バトルルームは　タワーに　いる\n"
	.string "トレーナーと　きょうりょくして\l"
	.string "ポケモンを　2ひきずつ　もちより\l"
	.string "マルチバトルで　たたかう　しせつです！\p"
	.string "タワーないには　バトルサロン　という\n"
	.string "トレーナーの　あつまる　へやが\l"
	.string "ようい　されています！\p"
	.string "ここで　いっしょに　タッグを　くみたい\n"
	.string "トレーナーを　みつけて　ください！\p"
	.string "タッグが　くめたところで\n"
	.string "マルチ　バトルルームへ　おつれします！\p"
	.string "この　マルチ　バトルルームには\n"
	.string "7くみの　タッグ　トレーナーが　いて\l"
	.string "あなたの　チャレンジを　まっています！\p"
	.string "みごと　その　7くみを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは　しっかりと\l"
	.string "レポートに　かいて　おわらせないと\l"
	.string "ちょうせんは　むこうに　なってしまうので\l"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons: @ 0x082214BC
	.string "では　さんかする　ポケモンを\n"
	.string "2ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle: @ 0x082214DA
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは\n"
	.string "つうしんマルチ　バトルルームの\l"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge: @ 0x08221523
	.string "つうしんマルチ　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge: @ 0x08221540
	.string "つうしんマルチ　バトルルームは\n"
	.string "ワイヤレスアダプタや　つうしんケーブルを\l"
	.string "つないだ　ともだちと　ふたりで\l"
	.string "ちがう　しゅるいの　ポケモンを\l"
	.string "2ひきずつ　もちより\l"
	.string "マルチバトルで　たたかう　しせつです！\p"
	.string "タワーないには　マルチ　バトルルームという\n"
	.string "たいせんの　ための　へやが\l"
	.string "たくさん　ようい　されています！\p"
	.string "それぞれ　マルチ　バトルルームには\n"
	.string "7くみの　タッグ　トレーナーが　いて\l"
	.string "あなたと　ともだちの　タッグでの\l"
	.string "チャレンジを　まっています！\p"
	.string "みごと　その　7くみを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　ほかの　しせつと　ちがって\n"
	.string "ここでは　とちゅうで　ちょうせんを\l"
	.string "ちゅうだん　できません！\p"
	.string "7かい　れんぞくで　たたかうことに　なるので\n"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2: @ 0x0822169F
	.string "では　さんかする　ポケモンを\n"
	.string "2ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_ChoseSameMonAsFriend: @ 0x082216BD
	.string "ともだちと\n"
	.string "おなじ　ポケモンを　えらんでいます！\p"
	.string "ともだちの　ポケモンと\n"
	.string "ちがう　しゅるいの　ポケモンを\l"
	.string "2ひき　えらび\l"
	.string "さんかする　レベルを　あわせて\l"
	.string "とうろくを　やりなおして　ください！$"

BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers: @ 0x0822171D
	.string "つうしんマルチ　バトルルームは\n"
	.string "{STR_VAR_1}にん　では　ちょうせん　できません！$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon: @ 0x08221742
	.string "ともだちも\n"
	.string "{STR_VAR_1}を　えらんでいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons: @ 0x08221755
	.string "ともだちも\n"
	.string "{STR_VAR_1}と　{STR_VAR_2}を\l"
	.string "えらんでいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode: @ 0x0822176C
	.string "ともだちと\n"
	.string "えらんだ　レベルが　ちがいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMon: @ 0x08221783
	.string "ともだちと\n"
	.string "えらんだ　レベルが　ちがいます！\p"
	.string "ともだちも\n"
	.string "{STR_VAR_1}を　えらんでいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMons: @ 0x082217AD
	.string "ともだちと\n"
	.string "えらんだ　レベルが　ちがいます！\p"
	.string "ともだちも\n"
	.string "{STR_VAR_1}と　{STR_VAR_2}を\l"
	.string "えらんでいます$"

BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode: @ 0x082217DA
	.string "ともだちの　ポケモンと\n"
	.string "ちがう　しゅるいの　ポケモンを\l"
	.string "2ひき　えらび\l"
	.string "さんかする　レベルを　あわせて\l"
	.string "とうろくを　やりなおして　ください！$"

BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn: @ 0x08221821
	.string "ごあんないする　まえに　レポートを　かきます\n"
	.string "しばらく　おまちください！$"

BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden: @ 0x08221846
	.string "おめでとう　ございます！\n"
	.string "タワータイクーンを　たおし\l"
	.string "みごと　7にんぬき　されましたね！$"

BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints: @ 0x08221873
	.string "おきゃくさまの\n"
	.string "かぎりない　さいのうを　たたえ\l"
	.string "バトルポイントを　しんてい　します！$"

BattleFrontier_Text_ObtainedXBattlePoints: @ 0x0822189E
	.string "{PLAYER}は　バトルポイントを\n"
	.string "{STR_VAR_1}　BP　てにいれた！$"

BattleFrontier_BattleTowerLobby_Text_RulesAreListed: @ 0x082218B8
	.string "バトルタワーの\n"
	.string "ルールが　かかれている！$"

BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading: @ 0x082218CD
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules: @ 0x082218DD
	.string "バトルタワーは\n"
	.string "シングルバトル　ダブルバトル　マルチバトル\l"
	.string "つうしんマルチバトル　というように\l"
	.string "4つの　たたかいが\l"
	.string "おこなわれる　しせつです\p"
	.string "それぞれの　たたかい　ごとに\n"
	.string "バトルルームと　よばれる\l"
	.string "たいせんの　へやが　ようい　されています\p"
	.string "ちょうせん　したい　たたかいの　うけつけに\n"
	.string "はなしかけて　いどみましょう$"

BattleFrontier_BattleTowerLobby_Text_ExplainMonRules: @ 0x0822197A
	.string "ちょうせんする　バトルルーム　ごとに\n"
	.string "つれていく　ポケモンの　かずが　かわります\p"
	.string "シングルでは　3ひき\n"
	.string "ダブルでは　4ひき\l"
	.string "マルチでは　2ひき　と　なっています$"

BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules: @ 0x082219CB
	.string "バトルサロンは　マルチバトルで\n"
	.string "タッグを　くむ　あいてを　さがす　へやです\p"
	.string "トレーナーの　ポケモンや　わざなどを　みて\n"
	.string "ベストな　あいてを　えらびましょう\p"
	.string "また　タッグを　くむ　あいては\n"
	.string "7れんしょう　ごとに　えらび　なおします$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules: @ 0x08221A3E
	.string "つうしんマルチ　では\n"
	.string "ワイヤレスアダプタや　つうしんケーブルを\l"
	.string "つないだ　ともだちと　ふたりで\l"
	.string "ちょうせん　することが　できます\p"
	.string "うけつけで　2ひきを　えらびますが\n"
	.string "ともだちと　おなじ　ポケモンでは\l"
	.string "さんかする　ことが　できません\p"
	.string "また　ここでは　たたかいの　とちゅうで\n"
	.string "やすむ　ことは　できません$"
