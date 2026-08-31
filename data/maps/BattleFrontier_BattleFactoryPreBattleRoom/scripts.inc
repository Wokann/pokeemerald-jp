@ BattleFrontier_BattleFactoryPreBattleRoom scripts (JP map g26 m32 @ 0x08231CA8)

BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleFactoryPreBattleRoom_OnWarp::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects::
	setvar 0x4001, 0x1
	compare_var_to_value 0x8006, 0x1
	goto_if 0x5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
	setobjectxy 0x1, 0x8, 0x7
	turnobject 0x1, 0x1

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth::
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleFactoryPreBattleRoom_OnFrame::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom::
	compare_var_to_value 0x8006, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
	setvar 0x4000, 0x1
	applymovement 0x1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
	applymovement 0xFF, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0x0
	compare_var_to_value 0x8006, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
	setvar 0x8004, 0xD
	special CallBattleFactoryFunction
	setvar 0x8004, 0xC
	special CallBattleFactoryFunction
	setvar 0x8004, 0xE
	special CallBattleFactoryFunction
	setorcopyvar 0x8005, 0x800D
	setvar 0x8004, 0xF
	special CallBattleFactoryFunction
	setorcopyvar 0x8006, 0x800D
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection
	callstd 0x4
	fadescreen 0x1
	setvar 0x8004, 0x8
	special CallBattleFactoryFunction
	setvar 0x8004, 0x6
	special CallBattleFactoryFunction
	waitstate

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay
	callstd 0x4
	closemessage
	call 0x082202F8
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
	waitmovement 0x0
	warp 0x1A21, 0xFF, 0x6, 0xB
	waitstate
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle::
	setvar 0x8004, 0x9
	special CallBattleFactoryFunction
	setvar 0x8004, 0x10
	special CallBattleFactoryFunction
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
	playse 0x107
	waitse
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments
	callstd 0x4
	closemessage
	applymovement 0x1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
	waitmovement 0x0
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo
	callstd 0x4
	closemessage
	applymovement 0x1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
	waitmovement 0x0
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow
	callstd 0x4
	closemessage
	delay 0x10
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
	compare_var_to_value 0x800D, 0x4
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
	compare_var_to_value 0x800D, 0x5
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
	compare_var_to_value 0x800D, 0x6
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle::
	call 0x0821F8F5
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x08232B11
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon::
	setvar 0x8004, 0xC
	special CallBattleFactoryFunction
	setvar 0x8004, 0xE
	special CallBattleFactoryFunction
	setorcopyvar 0x8005, 0x800D
	setvar 0x8004, 0xF
	special CallBattleFactoryFunction
	setorcopyvar 0x8006, 0x800D
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons::
	fadescreen 0x1
	setvar 0x8004, 0x7
	special CallBattleFactoryFunction
	waitstate
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	setvar 0x8004, 0x8
	special CallBattleFactoryFunction
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete
	callstd 0x4
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x2
	special CallBattleFactoryFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge::
	special SavePlayerParty
	setvar 0x8004, 0xA
	setvar 0x8005, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent
	callstd 0x4
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
	compare_var_to_value 0x8005, 0x2
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
	compare_var_to_value 0x8005, 0x3
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
	compare_var_to_value 0x8005, 0x4
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
	compare_var_to_value 0x8005, 0x5
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
	compare_var_to_value 0x8005, 0x6
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
	compare_var_to_value 0x8005, 0x7
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
	compare_var_to_value 0x8005, 0x8
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
	compare_var_to_value 0x8005, 0xA
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
	compare_var_to_value 0x8005, 0xB
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
	compare_var_to_value 0x8005, 0xC
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
	compare_var_to_value 0x8005, 0xD
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
	compare_var_to_value 0x8005, 0xE
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
	compare_var_to_value 0x8005, 0xF
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
	compare_var_to_value 0x8005, 0x10
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
	compare_var_to_value 0x8005, 0x11
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
	compare_var_to_value 0x8005, 0x12
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle::
	compare_var_to_value 0x8006, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
	compare_var_to_value 0x8006, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
	compare_var_to_value 0x8006, 0x2
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
	compare_var_to_value 0x8006, 0x3
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
	compare_var_to_value 0x8006, 0x4
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
	compare_var_to_value 0x8006, 0x5
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
	compare_var_to_value 0x8006, 0x6
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
	compare_var_to_value 0x8006, 0x7
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
	compare_var_to_value 0x8006, 0x8
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
	waitmessage
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead::
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead
	callstd 0x4
	loadword 0x0, BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50::
	applymovement 0x1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
	applymovement 0xFF, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen::
	applymovement 0x1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
	applymovement 0xFF, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
	return

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom:: @ 0x08232385
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50:: @ 0x0823238B
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen:: @ 0x08232391
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom:: @ 0x08232397
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50:: @ 0x0823239E
	walk_left
	walk_left
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen:: @ 0x082323A4
	walk_right
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall:: @ 0x082323AA
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer:: @ 0x082323AE
	walk_right
	walk_right
	walk_right
	face_down
	step_end
BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection: @ 0x082323B3
	.string "では　まず　おきゃくさまの\n"
	.string "ポケモンを　おあずかりして\l"
	.string "ポケモンレンタルを　おこないます！\l"
	.string "よーく　かんがえて　えらんで　くださいよ！！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons: @ 0x082323F8
	.string "おつかれさま　です！\n"
	.string "ポケモンを　かいふく　しましょう！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent: @ 0x08232415
	.string "つぎは　2せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent: @ 0x08232433
	.string "つぎは　3せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent: @ 0x08232451
	.string "つぎは　4せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent: @ 0x0823246F
	.string "つぎは　5せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent: @ 0x0823248D
	.string "つぎは　6せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent: @ 0x082324AB
	.string "いよいよ　7せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame: @ 0x082324CA
	.string "レポートを　かいて\n"
	.string "しゅうりょう　なさいますか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge: @ 0x082324E3
	.string "バトルトレードの　ちょうせんを\n"
	.string "ちゅうし　されますか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent: @ 0x082324FF
	.string "さあさあ！\n"
	.string "こんかいの　たいせんあいて　ですが\l"
	.string "わたしの　ちょうさ　では⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType: @ 0x08232526
	.string "どうやら　ノーマルタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType: @ 0x08232541
	.string "どうやら　ほのおタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType: @ 0x0823255B
	.string "どうやら　みずタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType: @ 0x08232574
	.string "どうやら　でんきタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType: @ 0x0823258E
	.string "どうやら　くさタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType: @ 0x082325A7
	.string "どうやら　こおりタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType: @ 0x082325C1
	.string "どうやら　かくとうタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType: @ 0x082325DC
	.string "どうやら　どくタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType: @ 0x082325F5
	.string "どうやら　じめんタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType: @ 0x0823260F
	.string "どうやら　ひこうタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType: @ 0x08232629
	.string "どうやら　エスパータイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType: @ 0x08232644
	.string "どうやら　むしタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType: @ 0x0823265D
	.string "どうやら　いわタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType: @ 0x08232676
	.string "どうやら　ゴーストタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType: @ 0x08232691
	.string "どうやら　ドラゴンタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType: @ 0x082326AC
	.string "どうやら　あくタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType: @ 0x082326C5
	.string "どうやら　はがねタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite: @ 0x082326DF
	.string "どうやら　ポケモンの　タイプには\n"
	.string "とくに　こだわりが　ないようで⋯⋯$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady: @ 0x08232702
	.string "“じっくり　じわじわ”とした　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance: @ 0x08232726
	.string "“まだまだ　これから！”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk: @ 0x08232749
	.string "“けんこん　いってき”の　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow: @ 0x0823276B
	.string "“くもゆき　しだい”の　バトルを\n"
	.string "こころがけている　かたの　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation: @ 0x08232790
	.string "“じゅんび　ばんたん”の　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe: @ 0x082327B2
	.string "“まずは　よわらせて⋯”という　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible: @ 0x082327D7
	.string "“りんきおうへん”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict: @ 0x082327F7
	.string "“よそく　ふかのう”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained: @ 0x08232818
	.string "“じゆう　ほんぽう”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon: @ 0x08232839
	.string "では　バトルを　はじめる　まえに\n"
	.string "ポケモンの　こうかんを　おこないますか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete: @ 0x0823285F
	.string "おつかれさまです！\n"
	.string "ポケモンこうかん　かんりょう　ですね！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay: @ 0x0823287D
	.string "それでは　おくに　どうぞ！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait: @ 0x0823288B
	.string "ただいま　レポートを　かいて　います⋯⋯\n"
	.string "しょうしょう　おまちください$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle: @ 0x082328AF
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　しますか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments: @ 0x082328CF
	.string "もうしわけ　ありません！\n"
	.string "しょうしょう　おまちください！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo: @ 0x082328EC
	.string "⋯⋯　えっ　⋯⋯　？　⋯⋯ひぃっ！\n"
	.string "わっかりましたっ！！　りょうかいです！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow: @ 0x08232912
	.string "やはは⋯⋯　おまたせ　しました！\p"
	.string "このしせつの　しょちょうで　ある\n"
	.string "ファクトリーヘッドからの　でんごんが\l"
	.string "ありますので　おつたえ　します！\p"
	.string "“やるぞっ！　いますぐ　こいっ！”\n"
	.string "との　ことです！$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead: @ 0x08232973
	.string "ファクトリーヘッドが　およびです！\n"
	.string "かくごは　よろしい　ですか？$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead: @ 0x08232994
	.string "もうしわけ　ありませんが\n"
	.string "ファクトリーヘッドに　ついての\l"
	.string "じょうほうは　おおしえ　できません！$"
