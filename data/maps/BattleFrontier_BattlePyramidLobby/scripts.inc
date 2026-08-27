BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

@ JP stores the local texts in physical ROM order.
BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "トレーナーの　ゆうきを　ためす　ばしょ！\n"
	.string "バトルピラミッドへ　ようこそ！\p"
	.string "こちらでは　バトルアドベンチャーの\n"
	.string "ごあんないを　しておりますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "バトルアドベンチャーに\n"
	.string "ちょうせん　されますかな？$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "バトルアドベンチャーは\n"
	.string "ピラミッドの　なかへ　はいり\l"
	.string "ちょうじょう　せいはを　めざす\l"
	.string "ぼうけん　イベント　ですぞ！\p"
	.string "ピラミッドの　なかは\n"
	.string "7だんの　めいろで　わかれていて\l"
	.string "うでに　おぼえの　ある　トレーナーと\l"
	.string "やせい　ポケモンが　まって　いますぞ！\p"
	.string "どうぐを　もたせて　いない\n"
	.string "3ひきの　ポケモンと\l"
	.string "おわたしする　バトルバッグを　もって\l"
	.string "ちょうじょうを　めざして　いただきますぞ！\p"
	.string "この　バトルバッグに　いれた　どうぐは\n"
	.string "ぼうけんに　しっぱいすると\l"
	.string "なくなって　しまいますので\l"
	.string "おきをつけ　くだされ！\p"
	.string "また　ぼうけんを　ちゅうだん　するときは\n"
	.string "‘やすむ’を　えらんで　おわらせないと\l"
	.string "ぼうけんは　ちゅうしと　なってしまいます！\l"
	.string "じゅうぶん　おきをつけ　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "ピラミッドには\n"
	.string "レベル50と　オープンレベルと　ありますが\l"
	.string "どちらに　はいられますかな？$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "では　つれていく　ポケモンを\n"
	.string "3ひき　おえらび　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "ぼうけんしゃよ！！\p"
	.string "つれていける　ポケモンが\n"
	.string "3ひき　いないようですぞ！\p"
	.string "また　ポケモンに　もたせている　どうぐは\n"
	.string "すべて　はずしてくだされ！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させる　ことは　できませんぞ！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "ぼうけんしゃよ！！\p"
	.string "つれていける　ポケモンが\n"
	.string "3ひき　いないようですぞ！\p"
	.string "つれていく　ためには　レベルが　50いかで\n"
	.string "すべて　ちがう　しゅるいの　ポケモンを\l"
	.string "3ひき　よういして　くだされ！\p"
	.string "また　ポケモンに　もたせている　どうぐは\n"
	.string "すべて　はずしてくだされ！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させる　ことは　できませんぞ！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "バトルピラミッドへ　はいる　まえに\n"
	.string "レポートを　かきますが　よろしいですかな？$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "では　バトルピラミッドの　なかへ\n"
	.string "おつれいたしますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "{PLAYER}さんの　もっている　バッグは\n"
	.string "こちらで　あずからせて　いただきますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "かわりに　ぜんかい　おつかいになった\n"
	.string "この　バトルバッグを　おもちくだされ！$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "かわりに　こちらの\n"
	.string "バトルバッグを　おもちくだされ！$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER}は　バッグを　あずけて\n"
	.string "バトルバッグを　うけとった！$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "こちらにある　ゆかを　ふんで　いただくと\n"
	.string "ピラミッドの　うえの　だんへと\l"
	.string "すすむことが　できますぞ！\p"
	.string "ぶじ　ぼうけんが　すすむことを\n"
	.string "いのって　おりますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "ぼうけんしゃよ！\p"
	.string "ぜんかい　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたな？\p"
	.string "ざんねんですが　この　ばあい\n"
	.string "ちょうせんは　むこうと　なりますぞ！\p"
	.string "おあずかり　していた\n"
	.string "バッグは　おかえし　いたしますぞ！\p"
	.string "{PLAYER}は\n"
	.string "バッグを　うけとった！$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "おかえりなさいませ！\p"
	.string "みごとに　バトルピラミッドを\n"
	.string "せいは　されましたな！$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "おおっ！\p"
	.string "ポケモンに\n"
	.string "どうぐを　もたせていますな⋯⋯\p"
	.string "もうしわけ　ありませんが\n"
	.string "ピラミッドで　てにいれた　どうぐは\l"
	.string "もっていくことが　できませんぞ！$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "もたせている　どうぐは\n"
	.string "すべて　{PLAYER}さんの　バトルバッグに\l"
	.string "いれておきますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "バトルバッグには\n"
	.string "すべて　はいらない　ようなので\l"
	.string "バトルバッグと　もたせたどうぐを\l"
	.string "せいりして　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "ポケモンに\n"
	.string "まだ　どうぐを　もたせていますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "バトルバッグと　もたせたどうぐを\n"
	.string "せいりして　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER}は　ポケモンに　もたせている\n"
	.string "どうぐを　かえした！$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "おつかいになられた　バトルバッグは\n"
	.string "じかいの　ちょうせんまで\l"
	.string "おあずかり　いたしますぞ！\p"
	.string "{PLAYER}は　バトルバッグを　あずけて\n"
	.string "バッグを　うけとった！$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちくだされ！$"

BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "バトルピラミッド　せいはの　きねんとして\n"
	.string "この　しょうひんを　おうけとり　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "⋯⋯ほう！\n"
	.string "どうぐが　いっぱいの　ようですな\p"
	.string "どうぐを　せいりしてから\n"
	.string "また　おこしくだされ！$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "ざんねんでしたな⋯⋯\p"
	.string "おあずかりしていた\n"
	.string "バッグは　おかえし　いたしますぞ！\p"
	.string "{PLAYER}は\n"
	.string "バッグを　うけとった！$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "おまちしておりましたぞ！\p"
	.string "バトルピラミッド　せいはの　きねんとして\n"
	.string "この　しょうひんを　おうけとり　くだされ！$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "ようこそ⋯⋯\p"
	.string "ピラミッドで　おこる　わざわいを\n"
	.string "うらなって　さしあげましょう⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯\n"
	.string "⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯\p"
	.string "⋯⋯っああっ！$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "でんきが　とびちっています⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "まひにより　おもうように　うごけない\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "どくが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "どくに　おかされ　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "まっかな　ほのおが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "やけどを　おって　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "すさまじい　プレッシャーと　おんねん⋯⋯\n"
	.string "うらみの　ちからが　みえます⋯⋯\p"
	.string "そして⋯⋯\n"
	.string "パワーポイントが　なくなり\l"
	.string "わるあがきを　する\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "ゆるやかに　ふゆうする\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "じめんの　わざを　つかえずに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "あしもとから　わきおこる\n"
	.string "つよい　ちからが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "にげようとしても　にげられない\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "こおりタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "こおりの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "いのちを　かけて\n"
	.string "くりだされる　わざが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "わざを　うけて　たおれていく\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "エスパータイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "エスパーの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "いわタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "いわの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "かくとうタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "かくとうの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "あまごい⋯⋯　にほんばれ⋯⋯\n"
	.string "すなあらし⋯⋯　あられ⋯⋯\p"
	.string "てんこうの　へんかで　つよくなる\n"
	.string "ポケモンたちが　みえます\p"
	.string "⋯⋯そして\n"
	.string "さまざまな　タイプに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "むしタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "さまざまな　こうげきで　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "あく　タイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "あくの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "みずタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "みずの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "ゴーストタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "ゴーストの　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "はがねタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "きょうだいな　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "そらをとぶ\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "きょうだいな　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "いしの　ちからにより\n"
	.string "しんかした　ものたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "ほのお⋯⋯　みず⋯⋯　でんき⋯⋯\p"
	.string "3つの　ちからに　くるしむ\n"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "ノーマルタイプの\n"
	.string "ポケモンたちが　みえます⋯⋯\p"
	.string "⋯⋯そして\n"
	.string "きょうだいな　わざに　くるしむ\l"
	.string "あなたの　ポケモンの　すがたも⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "うらないを　しんじるも　しんじないも\n"
	.string "あなた　しだい⋯⋯\p"
	.string "みらいは　いつでも　かえられます⋯⋯\n"
	.string "どうぞ　ごぶじで⋯⋯$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "あなた　しってた？\p"
	.string "はやく　はしると\n"
	.string "トレーナーが　あしおとに　きづいて\l"
	.string "しょうぶを　しかけて　くるの！\p"
	.string "だから　トレーナーと\n"
	.string "めを　あわせたくない　ときは\l"
	.string "トレーナーの　ようすを　みながら\l"
	.string "ゆっくり　あるいた　ほうが　いいのよ！$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "うおおおおーーーーーーん！\p"
	.string "どうぐを　いっぱい　もってたのに\n"
	.string "まけたら　ぜんぶ　なくなっちゃった⋯⋯\p"
	.string "うおおおおーーーーーーん！$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "おかえりなさいませ！\p"
	.string "ピラミッドキングを　たおし\n"
	.string "みごと　バトルピラミッドを\l"
	.string "せいは　されましたな！$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "ぼうけんしゃよ！\n"
	.string "あなたの　あつい　ゆうきを　たたえ\l"
	.string "バトルポイントを　おおくり　しましょう！$"
