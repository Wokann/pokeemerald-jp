@ PetalburgCity_Gym scripts (JP map g8 m1 @ 0x081F8520)

PetalburgCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad:: @ 0x081F8535
	goto_if_eq VAR_PETALBURG_GYM_STATE, 0x6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	call_if_ge VAR_PETALBURG_GYM_STATE, 0x7, PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 0x081F854C
	setvar VAR_0x8005, 0x1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors:: @ 0x081F8596
	setvar VAR_0x8005, 0x1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition:: @ 0x081F85C4
	call_if_eq VAR_PETALBURG_GYM_STATE, 0x1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	call_if_lt VAR_PETALBURG_GYM_STATE, 0x6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance:: @ 0x081F85E4
	setobjectxyperm LOCALID_PETALBURG_GYM_WALLY, 0x5, 0x6C
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance:: @ 0x081F85EC
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 0x4, 0x6B
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch:: @ 0x081F85F4
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, 0x10D
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, 0x1, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	goto_if_eq VAR_PETALBURG_GYM_STATE, 0x8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 0x4, 0x6B
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront:: @ 0x081F861C
	setvar VAR_PETALBURG_GYM_STATE, 0x8
	end

PetalburgCity_Gym_OnWarp:: @ 0x081F8622
	map_script_2 VAR_PETALBURG_GYM_STATE, 0x1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth:: @ 0x081F862C
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame:: @ 0x081F8631
	map_script_2 VAR_PETALBURG_GYM_STATE, 0x1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial:: @ 0x081F863B
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 0x1E
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 0x2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman:: @ 0x081F8688
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth:: @ 0x081F8717
	setvar VAR_0x8008, 0x0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth:: @ 0x081F8722
	setvar VAR_0x8008, 0x1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest:: @ 0x081F872D
	setvar VAR_0x8008, 0x2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast:: @ 0x081F8738
	setvar VAR_0x8008, 0x3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial:: @ 0x081F8743
	addobject LOCALID_PETALBURG_GYM_WALLY
	playse SE_DOOR
	call_if_eq VAR_0x8008, 0x0, PetalburgCity_Gym_EventScript_WallyArriveSouth
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_WallyArriveNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0x0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0x0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0x0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	call_if_eq VAR_0x8008, 0x0, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_WallyFaceDown
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 0x0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject LOCALID_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
	setvar VAR_PETALBURG_GYM_STATE, 0x1
	setvar VAR_PETALBURG_CITY_STATE, 0x2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 0xF, 0x8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth:: @ 0x081F88C8
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth:: @ 0x081F88DA
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast:: @ 0x081F88F6
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth:: @ 0x081F890F
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth:: @ 0x081F8928
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest:: @ 0x081F893A
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast:: @ 0x081F894C
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth:: @ 0x081F895E
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth:: @ 0x081F8969
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest:: @ 0x081F897B
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast:: @ 0x081F898D
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth:: @ 0x081F899F
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth:: @ 0x081F89AA
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest:: @ 0x081F89B5
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast:: @ 0x081F89C0
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer:: @ 0x081F89CB
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown:: @ 0x081F89D6
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanNoBadges:: @ 0x081F89E1
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge:: @ 0x081F89EB
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges:: @ 0x081F89F5
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges:: @ 0x081F89FF
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth:: @ 0x081F8A09
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorNorth:: @ 0x081F8A0A
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest:: @ 0x081F8A15
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast:: @ 0x081F8A16
	return

PetalburgCity_Gym_EventScript_NormanPostBattle:: @ 0x081F8A17
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	goto_if_eq VAR_RESULT, 0x1, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2:: @ 0x081F8A43
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch:: @ 0x081F8A4A
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry:: @ 0x081F8A65
	specialvar VAR_RESULT, IsEnigmaBerryValid
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0x0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0x1
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry:: @ 0x081F8AAE
	setvar VAR_RESULT, 0x0
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry:: @ 0x081F8AB4
	giveitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0x0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle:: @ 0x081F8AD2
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 0x7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 0x5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 0x1E
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	closemessage
	delay 0x28
	playse SE_DOOR
	delay 0xA
	addobject LOCALID_PETALBURG_GYM_WALLYS_DAD
	switch VAR_FACING
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
	end

PetalburgCity_Gym_EventScript_GiveFacade:: @ 0x081F8B69
	giveitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_FACADE
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_WallysDadArrivesNorth:: @ 0x081F8B8C
	setvar VAR_0x8008, 0x1
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesEast:: @ 0x081F8B96
	setvar VAR_0x8008, 0x2
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesWest:: @ 0x081F8BA0
	setvar VAR_0x8008, 0x3
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrives:: @ 0x081F8BAA
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_Delay48
	waitmovement 0
	delay 0xA
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 0x14
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 0x1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
	call_if_eq VAR_0x8008, 0x2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
	call_if_eq VAR_0x8008, 0x3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
	removeobject LOCALID_PETALBURG_GYM_WALLYS_DAD
	setvar VAR_PETALBURG_CITY_STATE, 0x4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	warp MAP_PETALBURG_CITY, 0xF, 0x8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth:: @ 0x081F8C63
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast:: @ 0x081F8C6E
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest:: @ 0x081F8C79
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth:: @ 0x081F8C84
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast:: @ 0x081F8CA0
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest:: @ 0x081F8CBC
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth:: @ 0x081F8CD8
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast:: @ 0x081F8CF1
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest:: @ 0x081F8D03
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
	waitmovement 0
	return

PetalburgCity_Gym_Movement_WallysDadExitNorth:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitEast:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_WallysDadEnterGym:
	walk_up
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Movement_Unused:
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

PetalburgCity_Gym_Movement_WallyArriveNorth:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Gym_Movement_WallyArrive:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallyExitNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitEast:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitSouthWest:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough:: @ 0x081F8DC4
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor:: @ 0x081F8DCE
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 0x6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x7
	setvar VAR_0x8009, 0x55
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom:: @ 0x081F8E03
	closemessage
	delay 0x1E
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom:: @ 0x081F8E12
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked:: @ 0x081F8E14
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_AccuracyRoomDoor:: @ 0x081F8E1E
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 0x6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x62
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor:: @ 0x081F8E53
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x7
	setvar VAR_0x8009, 0x2E
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor:: @ 0x081F8E86
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x3B
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor:: @ 0x081F8EB9
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x7
	setvar VAR_0x8009, 0x3B
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor:: @ 0x081F8EEC
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x48
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor:: @ 0x081F8F1F
	lockall
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x14
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor:: @ 0x081F8F52
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x7
	setvar VAR_0x8009, 0x14
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor:: @ 0x081F8F85
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x21
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor:: @ 0x081F8FB8
	lockall
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x7
	setvar VAR_0x8009, 0x21
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor:: @ 0x081F8FEB
	lockall
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor:: @ 0x081F901E
	lockall
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 0x7
	setvar VAR_0x8009, 0x7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall:: @ 0x081F9051
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors:: @ 0x081F9075
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge:: @ 0x081F9084
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker:: @ 0x081F908D
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors:: @ 0x081F90B1
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge:: @ 0x081F90C0
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George:: @ 0x081F90C9
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors:: @ 0x081F90ED
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge:: @ 0x081F90FC
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke:: @ 0x081F9105
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors:: @ 0x081F9129
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge:: @ 0x081F9138
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary:: @ 0x081F9141
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors:: @ 0x081F9165
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge:: @ 0x081F9174
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia:: @ 0x081F917D
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors:: @ 0x081F91A1
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge:: @ 0x081F91B0
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody:: @ 0x081F91B9
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors:: @ 0x081F91DD
	setvar VAR_0x8005, 0x0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge:: @ 0x081F91EC
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_OpenGymEntranceDoors:: @ 0x081F91F5
	setvar VAR_0x8004, 0x1
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors:: @ 0x081F9216
	setvar VAR_0x8004, 0x2
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors:: @ 0x081F9237
	setvar VAR_0x8004, 0x3
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors:: @ 0x081F9258
	setvar VAR_0x8004, 0x4
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors:: @ 0x081F9279
	setvar VAR_0x8004, 0x5
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors:: @ 0x081F929A
	setvar VAR_0x8004, 0x6
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors:: @ 0x081F92BB
	setvar VAR_0x8004, 0x7
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors:: @ 0x081F92DC
	setvar VAR_0x8004, 0x8
	call_if_eq VAR_0x8005, 0x0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 0x1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles:: @ 0x081F92FD
	setmetatile 0x6, 0x55, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x7, 0x55, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 0x1, 0x62, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x2, 0x62, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles:: @ 0x081F9322
	setmetatile 0x6, 0x2E, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x7, 0x2E, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 0x1, 0x3B, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x2, 0x3B, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles:: @ 0x081F9347
	setmetatile 0x6, 0x3B, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x7, 0x3B, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 0x1, 0x48, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x2, 0x48, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles:: @ 0x081F936C
	setmetatile 0x1, 0x14, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x2, 0x14, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles:: @ 0x081F937F
	setmetatile 0x6, 0x14, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x7, 0x14, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 0x1, 0x21, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x2, 0x21, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles:: @ 0x081F93A4
	setmetatile 0x6, 0x21, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x7, 0x21, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles:: @ 0x081F93B7
	setmetatile 0x1, 0x7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x2, 0x7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles:: @ 0x081F93CA
	setmetatile 0x6, 0x7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 0x7, 0x7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors:: @ 0x081F93DD
	special PetalburgGymSlideOpenRoomDoors
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors:: @ 0x081F93E2
	special PetalburgGymUnlockRoomDoors
	return

PetalburgCity_Gym_EventScript_GymGuide:: @ 0x081F93E6
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory:: @ 0x081F93FB
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue:: @ 0x081F9405
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue:: @ 0x081F9415
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified:: @ 0x081F9425
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue:: @ 0x081F942F
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon: @ 0x081F9439
	.string "パパ“ん？\p"
	.string "{PLAYER}じゃ　ないか！\n"
	.string "そうか　ひっこしが　おわったんだね\p"
	.string "それにしても\n"
	.string "よく　ここまで　ひとりで　これたな\p"
	.string "なるほど⋯⋯\n"
	.string "ポケモンと　いっしょ　なのか\p"
	.string "ふむ⋯⋯　じゃあ　{PLAYER}も\n"
	.string "わたしの　ように\l"
	.string "ポケモントレーナーに　なるのか\p"
	.string "それは　たのしみ　だな！$"

PetalburgCity_Gym_Text_WallyIdLikeAPokemon: @ 0x081F94BD
	.string "あの⋯⋯　ぼく⋯⋯\n"
	.string "ポケモンが　ほしいん　ですけど⋯⋯$"

PetalburgCity_Gym_Text_DadOhYoureWallyRight: @ 0x081F94D9
	.string "パパ“ん？　きみは⋯⋯　たしか\n"
	.string "ミツルくんと　いったよね$"

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon: @ 0x081F94F6
	.string "ミツル“ぼく　きょうから　シダケタウンの\n"
	.string "しんせきの　うちに　いくんですけど\p"
	.string "ひとりじゃ　さみしいから　ポケモンを\n"
	.string "つれて　いこうかと　おもって⋯⋯\p"
	.string "でも　いままで　じぶんで　ポケモンを\n"
	.string "つかまえた　ことが　ないから\l"
	.string "どう　やったら　いいのか⋯⋯$"

PetalburgCity_Gym_Text_DadHmISee: @ 0x081F9572
	.string "パパ“⋯⋯ふむ　なるほど$"

PetalburgCity_Gym_Text_DadPlayerGoWithWally: @ 0x081F957F
	.string "パパ“{PLAYER}！　はなしは　きいたね\p"
	.string "ミツルくんが　ぶじに\n"
	.string "ポケモンを　つかまえられるか\l"
	.string "みまもって　あげるんだ$"

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon: @ 0x081F95B6
	.string "ミツルくん\n"
	.string "わたしの　ポケモンを　かして　あげよう！\p"
	.string "ミツルは\n"
	.string "ジグザグマを　あずかった！$"

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall: @ 0x081F95E4
	.string "ミツル“わあ⋯⋯\n"
	.string "ポケモンだぁ⋯⋯！\p"
	.string "パパ“うむ⋯⋯\n"
	.string "モンスターボールは　あげるから\l"
	.string "がんばって　みなさい！\p"
	.string "ミツルは\n"
	.string "モンスターボールを　もらった！$"

PetalburgCity_Gym_Text_WallyOhWowThankYou: @ 0x081F9630
	.string "ミツル“おじさん　ありがとう！$"

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe: @ 0x081F9640
	.string "{PLAYER}さん⋯⋯\n"
	.string "ぼくと　いっしょに　きてくれますよね$"

PetalburgCity_Gym_Text_DadSoDidItWorkOut: @ 0x081F965A
	.string "パパ“うまく　いったかい？$"

PetalburgCity_Gym_Text_WallyThankYouBye: @ 0x081F9668
	.string "ミツル“おじさん\n"
	.string "おかりした　ポケモン　おかえし　します\p"
	.string "{PLAYER}さん　いっしょに　きてくれて\n"
	.string "どうも　ありがとう⋯⋯\p"
	.string "ポケモンを　つかまえることが　できたのは\n"
	.string "ふたりの　おかげです！\l"
	.string "つかまえた　ポケモン　たいせつに　しますね\p"
	.string "⋯⋯あ！　おかあさんが　まってるから\n"
	.string "ぼくは　もう　いかなきゃ！\p"
	.string "じゃあね　{PLAYER}さん！$"

PetalburgCity_Gym_Text_DadGoCollectBadges: @ 0x081F9705
	.string "パパ“さて⋯⋯\p"
	.string "{PLAYER}！　ポケモントレーナー　として\n"
	.string "つよく　なりたいのなら\l"
	.string "わたしの　アドバイスを　ききなさい\p"
	.string "まずは　この　さきにある\n"
	.string "カナズミシティに　いくんだ\p"
	.string "そこで　ツツジ　という　ジムリーダーと\n"
	.string "たたかうと　いい！\p"
	.string "そうやって　かくちの　ポケモンジムで\n"
	.string "ジムリーダーを　たおして\l"
	.string "ジムバッジを　あつめて　いくんだ\p"
	.string "もちろん　わたしも　ジムリーダーだ\n"
	.string "いずれ　{PLAYER}と　しょうぶ　するだろう\p"
	.string "だが　それは　{PLAYER}が\n"
	.string "つよくなってからの　はなし　だよ$"

PetalburgCity_Gym_Text_NormanGoToRustboro: @ 0x081F97E8
	.string "パパ“ん？　カナズミの\n"
	.string "ポケモンジムには　いかないのか？\p"
	.string "まだまだ　かけだしの　トレーナーと\n"
	.string "たたかっても　おもしろく　ないからな\p"
	.string "{PLAYER}には　もっと　つよくなって\n"
	.string "わたしの　まえに　あらわれて　ほしいんだ\p"
	.string "そうだな　ジムバッジを\n"
	.string "4つ　あつめられたら　そのときは\l"
	.string "{PLAYER}と　しょうぶ　しよう！$"

PetalburgCity_Gym_Text_NormanGoToDewford: @ 0x081F987A
	.string "パパ“なるほど⋯⋯\n"
	.string "カナズミの　ジムリーダーに　かったのか\p"
	.string "だが　まだまだ　{PLAYER}より\n"
	.string "つよい　トレーナーは　いっぱい　いる\p"
	.string "うみの　むこう　ムロタウンには\n"
	.string "トウキ　という　ジムリーダーが　いる\l"
	.string "かれとも　しょうぶ　してみると　いい$"

PetalburgCity_Gym_Text_YouHaveGottenStronger: @ 0x081F98EE
	.string "パパ“ふむ⋯⋯\n"
	.string "{PLAYER}は　つよくなって　いるな\p"
	.string "その　バッジの　かずを　みれば　わかるよ$"

PetalburgCity_Gym_Text_NormanIntro: @ 0x081F991A
	.string "パパ“そうか⋯⋯\n"
	.string "ジムバッジを　4つ　あつめたのか\p"
	.string "では　やくそく　どおり\n"
	.string "ポケモンしょうぶ　だな⋯⋯\p"
	.string "{PLAYER}⋯⋯\p"
	.string "わたしは　いま　こうして\n"
	.string "じぶんの　こどもと\l"
	.string "しんけん　しょうぶ　できることが\l"
	.string "うれしくて　たまらない！\p"
	.string "だが　しょうぶは　しょうぶ！\p"
	.string "わたしは　ジムリーダーとして\n"
	.string "ぜんりょくを　つくす！\l"
	.string "{PLAYER}も　ほんきで　かかってくるんだ！$"

PetalburgCity_Gym_Text_NormanDefeat: @ 0x081F99C5
	.string "⋯⋯！\p"
	.string "まさか⋯⋯\p"
	.string "まさか　{PLAYER}に⋯⋯\p"
	.string "{PLAYER}に　まける　とは⋯⋯\p"
	.string "⋯⋯わかった！　きまりは　きまりだ！\n"
	.string "これを　わたそう$"

PetalburgCity_Gym_Text_ReceivedBalanceBadge: @ 0x081F9A02
	.string "{PLAYER}は　パパから\n"
	.string "バランスバッジを　もらった！$"

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis: @ 0x081F9A1A
	.string "パパ“その　バランスバッジで\n"
	.string "{PLAYER}の　ポケモンの\l"
	.string "ぼうぎょりょくが　たかくなる\p"
	.string "ひでんわざの　なみのり　を\n"
	.string "おぼえた　ポケモンが　いるなら\l"
	.string "みずのうえを　すすめるように　なる\p"
	.string "これは　わたしからの　おくりもの\n"
	.string "{PLAYER}なら　つかいこなせるだろう！$"

PetalburgCity_Gym_Text_ExplainFacade: @ 0x081F9A94
	.string "パパ“わざマシン42は　からげんき\p"
	.string "どくや　まひ　やけどに　なると\n"
	.string "わざの　いりょくが　ばいに　なる！\p"
	.string "ピンチを　チャンスに\n"
	.string "かえることが　できるかも　しれないな$"

PetalburgCity_Gym_Text_DadHappyAndSad: @ 0x081F9AE6
	.string "パパ“ジムリーダーとして\n"
	.string "いいようが　ないくらい　くやしい⋯⋯\p"
	.string "だが　おや　としては\n"
	.string "うれしいような　さびしいような\l"
	.string "ふしぎな　きもち　だ⋯⋯$"

PetalburgCity_Gym_Text_PleaseComeWithMe: @ 0x081F9B2E
	.string "おお　いたいた　{PLAYER}{KUN}！\p"
	.string "ちょっと　きてくれないか\n"
	.string "きみに　わたしたい　ものが　あるんだ！$"

PetalburgCity_Gym_Text_LetMeBorrowPlayer: @ 0x081F9B5D
	.string "なあ　センリさん　いいだろう？\p"
	.string "おたくの　{PLAYER}{KUN}を\n"
	.string "ちょっと　おかりして　いくよ！$"

PetalburgCity_Gym_Text_DadGoingToKeepTraining: @ 0x081F9B88
	.string "パパ“{PLAYER}！　たまには　ママにも\n"
	.string "あいに　いって　あげるんだぞ！\p"
	.string "わたしは　ここで\n"
	.string "じぶんを　きたえなおす！\p"
	.string "{PLAYER}に　まけた　ままでは\n"
	.string "トレーナーとして　くやしすぎる　からな$"

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough: @ 0x081F9BE0
	.string "パパ“{PLAYER}！\n"
	.string "ちょうしは　どうだ？\p"
	.string "ポケモンは　おくが　ふかい！\n"
	.string "わたしは　いくら　しゅぎょう　しても\l"
	.string "たりなく　おもっている　ところだよ$"

PetalburgCity_Gym_Text_GymGuideAdvice: @ 0x081F9C26
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "この　ジムは　へやにいる　トレーナーを\n"
	.string "たおせば　おくの　とびらが　ひらくッ！\p"
	.string "⋯⋯おっと！　この　へやは　すでに\n"
	.string "とびらが　ひらく　ように　なってるから\l"
	.string "ぼくを　たおしたり　しないで　くれよ！\p"
	.string "この　トウカジムの　トレーナーたちは\n"
	.string "いろんな　わざを　つかってくるぞ！\p"
	.string "ちなみに　ここから　いけるのは\n"
	.string "ひだり⋯⋯　すばやさの　へや\l"
	.string "みぎ⋯⋯　めいちゅうの　へや　だ！\p"
	.string "とびらにも　かいてあるから　それを\n"
	.string "よんでから　すすむんだ\p"
	.string "さあ！　すきな　ほうを　えらんだら\n"
	.string "きばってこォー！！$"

PetalburgCity_Gym_Text_GymGuidePostVictory: @ 0x081F9D34
	.string "{PLAYER}は　じぶんの　パパさえも\n"
	.string "のりこえて　しまったのか！？\p"
	.string "こらァ　びっくり　たまげたッ！！$"

PetalburgCity_Gym_Text_RandallIntro: @ 0x081F9D63
	.string "あいてよりも　さきに　こうげき　できる⋯⋯\p"
	.string "それだけで　しょうぶは\n"
	.string "かなり　ゆうりに　なるだろう？$"

PetalburgCity_Gym_Text_RandallDefeat: @ 0x081F9D95
	.string "すばらしい　しょうぶ　だった⋯⋯！$"

PetalburgCity_Gym_Text_RandallPostBattle: @ 0x081F9DA7
	.string "おくの　へやに　すすみたまえ！\n"
	.string "さらなる　しれんが　きみを　まっている\p"
	.string "ひだりは　こんらんの　へや！\n"
	.string "みぎは　まもりの　へや　だ！$"

PetalburgCity_Gym_Text_RandallPostBadge: @ 0x081F9DE9
	.string "だれに　かとうとも\n"
	.string "だれに　まけようとも\l"
	.string "おのれと　ポケモンを　きたえつづける⋯⋯\p"
	.string "それが　ジムリーダー　なのさ$"

PetalburgCity_Gym_Text_ParkerIntro: @ 0x081F9E22
	.string "ここは　こんらんの　へや！\p"
	.string "きみと　ポケモンの　きずな\n"
	.string "みせて　もらうよ！$"

PetalburgCity_Gym_Text_ParkerDefeat: @ 0x081F9E48
	.string "こんらん　させきれなかった\n"
	.string "ふかい　きずなを　もっているね⋯⋯$"

PetalburgCity_Gym_Text_ParkerPostBattle: @ 0x081F9E68
	.string "つぎは　ちからの　へや！\n"
	.string "その　こうげきりょくに　たえられるかい？$"

PetalburgCity_Gym_Text_ParkerPostBadge: @ 0x081F9E8A
	.string "ジムリーダーが　きみに　まけてから\n"
	.string "くんれんが　さらに　きびしく　なったよ！$"

PetalburgCity_Gym_Text_GeorgeIntro: @ 0x081F9EB1
	.string "あとすこしで　たおせると　おもったとき\n"
	.string "あいての　たいりょくが　かいふく　する\l"
	.string "それが　どんなに　つらい　ことか⋯⋯\p"
	.string "その　つらさ　あじわってもらうよ！$"

PetalburgCity_Gym_Text_GeorgeDefeat: @ 0x081F9EFE
	.string "かいふく　しきれなかった⋯⋯\n"
	.string "すごい　こうげきりょく　だ⋯⋯$"

PetalburgCity_Gym_Text_GeorgePostBattle: @ 0x081F9F1D
	.string "さすがは　ジムリーダーの　こども⋯⋯\p"
	.string "いや！　トレーナーの　さいのうは\n"
	.string "どりょくで　つちかわれる　もの⋯⋯\p"
	.string "きみに　まけたのは　ぼくの　どりょくが\n"
	.string "たりなかった　から　なんだ⋯⋯！\p"
	.string "さあ　つぎは　いちげきの　へや　だ！$"

PetalburgCity_Gym_Text_GeorgePostBadge: @ 0x081F9F8B
	.string "ポケモンジムで　しゅぎょうを　かさね\n"
	.string "いつかは　ジムリーダーに　なってみせるよ$"

PetalburgCity_Gym_Text_BerkeIntro: @ 0x081F9FB3
	.string "ジムリーダーの　こども　だからって\n"
	.string "てかげんは　しない！\p"
	.string "きゅうしょに　あたる　こわさ\n"
	.string "とくと　あじわって　もらうよ！$"

PetalburgCity_Gym_Text_BerkeDefeat: @ 0x081F9FEF
	.string "きみの　つよさは　ほんものだ⋯⋯！$"

PetalburgCity_Gym_Text_BerkePostBattle: @ 0x081FA001
	.string "きみの　パパは　ほんとうに　つよい\n"
	.string "そんけいに　あたいする　トレーナーだ！\p"
	.string "そして　きみにも\n"
	.string "きみの　パパと　おなじ\l"
	.string "かがやきを　かんじる⋯⋯\p"
	.string "おやこ　ふたりが　のうりょくを　きそう\n"
	.string "さいこうの　めいしょうぶを　みせてくれ！$"

PetalburgCity_Gym_Text_BerkePostBadge: @ 0x081FA072
	.string "きみの　パパが　ジムリーダーに　なってから\n"
	.string "トウカの　トレーナーたちも　つよくなった$"

PetalburgCity_Gym_Text_MaryIntro: @ 0x081FA09D
	.string "ふふふ⋯⋯\n"
	.string "ここは　めいちゅうの　へや！\p"
	.string "すべての　こうげきが　あたるのって\n"
	.string "けっこう　いやな　ものよ$"

PetalburgCity_Gym_Text_MaryDefeat: @ 0x081FA0D1
	.string "あなたの　ほうが　いちまい　うわてね⋯⋯$"

PetalburgCity_Gym_Text_MaryPostBattle: @ 0x081FA0E6
	.string "おくで　さらに　てごわい　トレーナーが\n"
	.string "あなたを　まっている\p"
	.string "ひだりは　まもりの　へや\n"
	.string "みぎは　かいふくの　へや　よ\p"
	.string "あなたの　ポケモンの\n"
	.string "こうげきりょくが　とわれるわ$"

PetalburgCity_Gym_Text_MaryPostBadge: @ 0x081FA13B
	.string "あなたは　わたしたち　トレーナーが\n"
	.string "なにを　めざしているか　しってる？\p"
	.string "⋯⋯それはね　ポケモンと\n"
	.string "こころを　ひとつに　する　ことよ！$"

PetalburgCity_Gym_Text_AlexiaIntro: @ 0x081FA17E
	.string "まもりが　かたければ　かたいほど\n"
	.string "おもいきった　こうげきが　できるのよ$"

PetalburgCity_Gym_Text_AlexiaDefeat: @ 0x081FA1A2
	.string "まもりきれなかった⋯⋯$"

PetalburgCity_Gym_Text_AlexiaPostBattle: @ 0x081FA1AE
	.string "あなたには　たいせつな　ことを\n"
	.string "おしえて　もらった　きが　するわ⋯⋯\p"
	.string "さあ　すすみなさい！\n"
	.string "ひだりは　ちからの　へや\l"
	.string "みぎは　いちげきの　へや\p"
	.string "ともに　こうげきを　とくいと　しているわ！$"

PetalburgCity_Gym_Text_AlexiaPostBadge: @ 0x081FA20C
	.string "どう？　なみのりは　つかってる？$"

PetalburgCity_Gym_Text_JodyIntro: @ 0x081FA21D
	.string "ぜんりょくで　あなたを　たおせと\n"
	.string "ジムリーダーから　いわれている⋯⋯\p"
	.string "たとえ　その　あいてが\n"
	.string "リーダーの　こども　だとしても！$"

PetalburgCity_Gym_Text_JodyDefeat: @ 0x081FA25D
	.string "ぜんりょくを　だしたのに⋯⋯！$"

PetalburgCity_Gym_Text_JodyPostBattle: @ 0x081FA26D
	.string "あなたの　ポケモンの　つかいかた⋯⋯\n"
	.string "どことなく　おとうさんに　にているわ\p"
	.string "さあ！　この　おくには　ジムリーダー\n"
	.string "あなたの　おとうさんが　まっているわ！$"

PetalburgCity_Gym_Text_JodyPostBadge: @ 0x081FA2BA
	.string "ポケモンを　つよく　するのも　いいけど\p"
	.string "しょうぶの　ゆくえを　きめるのは\n"
	.string "そのひと　じしんの　ポケモンに　たいする\l"
	.string "きもち　なのよね⋯⋯！$"

PetalburgCity_Gym_Text_DoorAppearsLocked: @ 0x081FA300
	.string "いまは　まだ　この　とびらは\n"
	.string "とざされて　いる　ようだ⋯⋯$"

PetalburgCity_Gym_Text_EnterSpeedRoom: @ 0x081FA31E
	.string "このさき　すばやさの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_DoorAppearsLocked2: @ 0x081FA342
	.string "いまは　まだ　この　とびらは\n"
	.string "とざされて　いる　ようだ⋯⋯$"

PetalburgCity_Gym_Text_EnterAccuracyRoom: @ 0x081FA360
	.string "このさき　めいちゅうの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_EnterConfusionRoom: @ 0x081FA385
	.string "このさき　こんらんの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_EnterDefenseRoom: @ 0x081FA3A9
	.string "このさき　まもりの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_EnterRecoveryRoom: @ 0x081FA3CC
	.string "このさき　かいふくの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_EnterStrengthRoom: @ 0x081FA3F0
	.string "このさき　ちからの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_EnterOHKORoom: @ 0x081FA413
	.string "このさき　いちげきの　へや\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_EnterGymLeadersRoom: @ 0x081FA437
	.string "このさき　ジムリーダー\p"
	.string "どんな　ポケモンが　まっているか　は\n"
	.string "じぶんの　めで　たしかめよ！\p"
	.string "⋯⋯と　かいてある\n"
	.string "おくに　すすみますか？$"

PetalburgCity_Gym_Text_GymStatue: @ 0x081FA47B
	.string "トウカシティ　ポケモンジム$"

PetalburgCity_Gym_Text_GymStatueCertified: @ 0x081FA489
	.string "トウカシティ　ポケモンジム\p"
	.string "センリ　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

PetalburgCity_Gym_Text_NormanPreRematch: @ 0x081FA4AA
	.string "パパ“{PLAYER}⋯⋯\n"
	.string "やはり　あらわれたな⋯⋯\p"
	.string "おまえに　しょうぶを　いどまれて\n"
	.string "この　わたしが　ことわる　はずがない\p"
	.string "わかっているな？\p"
	.string "ジムの　なかでは　おたがいに\n"
	.string "おやこで　あることなど　かんけいない\p"
	.string "⋯⋯いや　おやこ　だからこそ\n"
	.string "ぜんりょくで　ぶつかるんだ\l"
	.string "そうだろ？　{PLAYER}！$"

PetalburgCity_Gym_Text_NormanRematchDefeat: @ 0x081FA535
	.string "はは　はは⋯⋯\n"
	.string "ぜんりょくを　だしすぎた⋯⋯　かな？$"

PetalburgCity_Gym_Text_NormanPostRematch: @ 0x081FA550
	.string "パパ“{PLAYER}⋯⋯\n"
	.string "おまえの　ゆめは　なんだ？\p"
	.string "わたしの　ゆめは⋯⋯\n"
	.string "ははは⋯⋯\l"
	.string "じつは　もう　かなったんだよ$"

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons: @ 0x081FA586
	.string "パパ“{PLAYER}⋯⋯\n"
	.string "やはり　あらわれたな⋯⋯\p"
	.string "おまえに　しょうぶを　いどまれて\n"
	.string "この　わたしが　ことわる　はずがない\p"
	.string "わかっているな？\p"
	.string "ジムの　なかでは　おたがいに\n"
	.string "おやこで　あることなど　かんけいない⋯⋯\p"
	.string "⋯⋯うん？　なんだ　{PLAYER}\n"
	.string "おまえは　たたかえる　ポケモンを\l"
	.string "1ひきしか　もっていないのか\p"
	.string "わるいけれど　2ひき　いじょうの\n"
	.string "ポケモンを　もって　また　きておくれ$"
