@ Route110 scripts (JP map g0 m25 @ 0x081E8E49)

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume::
	special UpdateCyclingRoadState
	end

Route110_OnTransition::
	call Common_EventScript_SetupRivalGfxId
	call 0x08242F87
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 0x1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame::
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 0x1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 0x2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, 0x0, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0x1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0x0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, 0x0824362B
	waitmovement 0x0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0xA, Route110_EventScript_ChallengeReactionBest
	goto_if_eq VAR_0x8000, 0x9, Route110_EventScript_ChallengeReactionGood
	goto_if_eq VAR_0x8000, 0x8, Route110_EventScript_ChallengeReactionGood
	goto_if_eq VAR_0x8000, 0x7, Route110_EventScript_ChallengeReactionGood
	goto_if_eq VAR_0x8000, 0x6, Route110_EventScript_ChallengeReactionOk
	goto_if_eq VAR_0x8000, 0x5, Route110_EventScript_ChallengeReactionOk
	goto_if_eq VAR_0x8000, 0x4, Route110_EventScript_ChallengeReactionOk
	goto_if_eq VAR_0x8000, 0x3, Route110_EventScript_ChallengeReactionBad
	goto_if_eq VAR_0x8000, 0x2, Route110_EventScript_ChallengeReactionBad
	goto_if_eq VAR_0x8000, 0x1, Route110_EventScript_ChallengeReactionBad
	goto_if_eq VAR_0x8000, 0x0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 0x3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 0x1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 0x2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 0x3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_ROUTE110_RIVAL, 0x0824362D
	waitmovement 0x0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0x0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_Delay48
	waitmovement 0x0
	delay 0x1E
	call_if_eq VAR_0x8008, 0x1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 0x2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 0x3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_STARTER_MON
	goto_if_eq VAR_0x8000, 0x0, Route110_EventScript_MayBattleTreecko
	goto_if_eq VAR_0x8000, 0x1, Route110_EventScript_MayBattleTorchic
	goto_if_eq VAR_0x8000, 0x2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_STARTER_MON
	goto_if_eq VAR_0x8000, 0x0, Route110_EventScript_BrendanBattleTreecko
	goto_if_eq VAR_0x8000, 0x1, Route110_EventScript_BrendanBattleTorchic
	goto_if_eq VAR_0x8000, 0x2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	setorcopyvar VAR_0x8000, ITEM_ITEMFINDER
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 0x1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 0x2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 0x3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE110_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE110_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE110_RIVAL
	addobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	delay 0x2D
	call_if_eq VAR_0x8008, 0x1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 0x2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 0x3, Route110_EventScript_RivalExit3
	removeobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 0x1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0x0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0x0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0x0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0x0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0x0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0x0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 0x21, 0x37
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 0x22, 0x37
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 0x23, 0x37
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 0x1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 0x2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 0x3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 0x4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_ROUTE110_BIRCH
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0x0
	playse SE_PIN
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0x0
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_Delay48
	waitmovement 0x0
	call_if_eq VAR_0x8008, 0x1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 0x2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 0x3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 0x4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 0x14
	applymovement LOCALID_ROUTE110_BIRCH, 0x08243627
	waitmovement 0x0
	delay 0xA
	applymovement LOCALID_ROUTE110_BIRCH, 0x0824362B
	waitmovement 0x0
	delay 0x14
	applymovement LOCALID_ROUTE110_BIRCH, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 0x1E
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 0x1E
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0x1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 0x2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 0x3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 0x4, Route110_EventScript_BirchExit4
	removeobject LOCALID_ROUTE110_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 0x2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0x0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0x0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0x0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0x0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0x0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0x0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0x0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0x0
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities: @ 0x081E973D
	.string "アクアだんの　かつどうは\n"
	.string "いまは　まだ　だれにも　いえないのだ$"

Route110_Text_KickUpARuckus: @ 0x081E975D
	.string "はやく　カイナに　いって\n"
	.string "ひとあばれ　したいんだよな$"

Route110_Text_MyFirstJobInAqua: @ 0x081E9778
	.string "アクアだんに　はいって\n"
	.string "はじめての　しごと　だぜ⋯⋯　どきどき$"

Route110_Text_AquaActionsBringSmiles: @ 0x081E9798
	.string "アクアだんの　かつどうは\n"
	.string "きっと　みんなを　えがおに　するだろう$"

Route110_Text_MayLetsBattle: @ 0x081E97B9
	.string "ハルカ“{STRING 0x01}{STRING 0x05}　ひさしぶり！\p"
	.string "いろいろ　ポケモン　さがしてる　あいだに\n"
	.string "あたしの　ポケモンも　つよくなったんだ！\p"
	.string "だから⋯⋯\n"
	.string "ちょっと　しょうぶ　しようよ！$"

Route110_Text_MayDefeated: @ 0x081E9809
	.string "あっちゃー！\n"
	.string "おもってたより　つよいよ！$"

Route110_Text_MayTakeThis: @ 0x081E981E
	.string "ハルカ“{STRING 0x01}{STRING 0x05}も\n"
	.string "ポケモン　そだててるんだね！\p"
	.string "うん　じゃあ　これは\n"
	.string "あたしからの　プレゼントよ！$"

Route110_Text_MayExplainItemfinder: @ 0x081E9851
	.string "ハルカ“それは　ダウジングマシン！\p"
	.string "ダウジングマシンを　つかうと\n"
	.string "めには　みえなくても　おちている\l"
	.string "どうぐが　あると　はんのう　して\l"
	.string "おとで　おしえて　くれるのよ！\p"
	.string "じゃあ　{STRING 0x01}{STRING 0x05}\n"
	.string "また　どこかで　あおうね！\p"
	.string "まけた　あたしが　いうのも　なんだけど\n"
	.string "そのときまでに　もっと　ポケモン\l"
	.string "そだてて　おいた　ほうが　いいかもよ！$"

Route110_Text_BrendanLetsBattle: @ 0x081E98F4
	.string "ユウキ“{STRING 0x01}か\n"
	.string "こんなところに　いたんだ\l"
	.string "ちょうしは　どう？\p"
	.string "ポケモン　そだててるか　どうか\n"
	.string "オレが　たしかめて　やるよ$"

Route110_Text_BrendanDefeated: @ 0x081E9931
	.string "ふうん⋯⋯\n"
	.string "なかなか　やるね$"

Route110_Text_BrendanTakeThis: @ 0x081E9940
	.string "ユウキ“{STRING 0x01}も　いつのまにか\n"
	.string "ポケモン　そだててたのか⋯⋯\p"
	.string "よし！\n"
	.string "これを　やるよ$"

Route110_Text_BrendanExplainItemfinder: @ 0x081E996A
	.string "ユウキ“そいつは　ダウジングマシン\p"
	.string "つかうと　めには　みえなくても\n"
	.string "おちている　どうぐが　あると\l"
	.string "はんのう　して　おとで　おしえてくれる\p"
	.string "じゃ　オレ　あたらしい\n"
	.string "ポケモンを　さがしに　いくから$"

Route110_Text_RideBikeAtFullSpeed: @ 0x081E99CB
	.string "この　サイクリング　ロードを\n"
	.string "じてんしゃで　はしりぬけたら\l"
	.string "だんぜん　きもち　よさそうだね！$"

Route110_Text_HairStreamsBehindMe: @ 0x081E99FA
	.string "どう？　かぜになびく　わたしの　くろかみ！\p"
	.string "このため　だけに　かみを　のばしたの！$"

Route110_Text_YouGotBikeFromRydel: @ 0x081E9A24
	.string "おっ！　その　じてんしゃ\n"
	.string "ミスターカゼノに　もらったんだね！\p"
	.string "みれば　わかるよ\n"
	.string "だって　きみの　じてんしゃに⋯⋯\p"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\n"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\p"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\n"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\p"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\n"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\p"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\n"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\p"
	.string "カゼノ　カゼノ　カゼノ　カゼノ　カゼノ\n"
	.string "⋯⋯って　かいて　あるんだもん！\p"
	.string "あっちこっち　のりまわして\n"
	.string "せんでん　してあげると　いいね！$"

Route110_Text_TwoRoads: @ 0x081E9B41
	.string "うえと　した　2つの　どうろ⋯⋯\p"
	.string "にんげんと　ポケモン\n"
	.string "それぞれの　どうろ　だと　おもえば\l"
	.string "これもあり　なのかも　しれんのう$"

Route110_Text_WalkOnTheLowRoad: @ 0x081E9B80
	.string "あたしは　じてんしゃ　もってない　からねえ\n"
	.string "したの　みちを　のんびり　あるいて　いくよ$"

Route110_Text_BikeTechniques: @ 0x081E9BAC
	.string "いろんな　テクニックを　おぼえると\n"
	.string "ますます　じてんしゃが　たのしくなる！\p"
	.string "テクニックを　つかわないと\n"
	.string "すすめない　ばしょも　あるしね！$"

Route110_Text_WhichShouldIChoose: @ 0x081E9BF1
	.string "サイクリングロードで　キンセツを　めざすか\n"
	.string "したの　みちで　ポケモンを　さがすか\l"
	.string "どっちに　しようかな？$"

Route110_Text_CyclingChallengeResultSummary: @ 0x081E9C26
	.string "ぶつかった　かいすう\n"
	.string "　⋯⋯　{STRING 0x02}！\p"
	.string "かかった　タイム\n"
	.string "　⋯⋯　{STRING 0x03}！$"

Route110_Text_ChallengeReactionBest: @ 0x081E9C4A
	.string "ブラボー！！　すばらしい！！\p"
	.string "きみは　じてんしゃを　こころから\n"
	.string "あいしている！　たましいを　ゆさぶられたよ！$"

Route110_Text_ChallengeReactionGood: @ 0x081E9C81
	.string "なかなかの　テクニックを　もってるな！\p"
	.string "まあ　スピードを　だしすぎて\n"
	.string "アクシデントを　おこさないように　しなよ！$"

Route110_Text_ChallengeReactionOk: @ 0x081E9CBA
	.string "まだ　みじゅくな　ぶぶんも　あるようだが\n"
	.string "せっかくの　じてんしゃを\l"
	.string "たのしむ　きもちを　わすれないで　くれよ$"

Route110_Text_ChallengeReactionBad: @ 0x081E9CF1
	.string "おいおい　なんだか\n"
	.string "あぶなっかしい　うんてん　してるなあ\l"
	.string "もっと　れんしゅう　しろよな$"

Route110_Text_ChallengeReactionWorst: @ 0x081E9D1D
	.string "うむむ⋯⋯　うむむむ⋯⋯\p"
	.string "きみには　じてんしゃは　むいていない　かもな\n"
	.string "ミスターカゼノに　かえしたら　どうだね？$"

Route110_Text_RatedForNumberOfCollisions: @ 0x081E9D56
	.string "この　サイクリングロード！\p"
	.string "キンセツから　カイナに　むかって\n"
	.string "マッハじてんしゃで　はしりぬける\l"
	.string "レーサーの　ぶつかった　かいすうと\l"
	.string "かかった　タイムを　はかって　いるんだ！$"

Route110_Text_AlwaysAimHigher: @ 0x081E9DAD
	.string "どんな　けっか　だろうが　さらに\n"
	.string "うえを　めざしての　チャレンジ　まってるよ！$"

Route110_Text_AcroBikesDoNotQualify: @ 0x081E9DD5
	.string "この　サイクリング　ロードでは\n"
	.string "マッハじてんしゃ　で　はしりぬけた\l"
	.string "レーサーの　ぶつかった　かいすうと\l"
	.string "かかった　タイムを　はかって　いるんだ！\p"
	.string "ダートじてんしゃ　だと　まがりやすいから\n"
	.string "きろくは　はかって　あげないよ！$"

Route110_Text_SlateportCitySign: @ 0x081E9E44
	.string "ここは　110ばん　どうろ\n"
	.string "{DOWN_ARROW}　カイナシティ$"

Route110_Text_CyclingRoadSign: @ 0x081E9E5D
	.string "‘シーサイド　サイクリング　ロード’$"

Route110_Text_AquaWasHere: @ 0x081E9E70
	.string "‘アクアだん　さんじょう！’\p"
	.string "⋯⋯と　かんばんに　らくがき　されているが\n"
	.string "そのもじの　うえに　べつのペンキで\p"
	.string "‘マグマだん　さんじょう！’\n"
	.string "⋯⋯と　かかれている$"

Route110_Text_Route103Sign: @ 0x081E9EC1
	.string "ここは　110ばん　どうろ\n"
	.string "{LEFT_ARROW}　103ばん　どうろ$"

Route110_Text_SeasideParkingSign: @ 0x081E9EDD
	.string "‘シーサイド　パーキング’$"

Route110_Text_MauvilleCitySign: @ 0x081E9EEB
	.string "ここは　110ばん　どうろ\n"
	.string "{UP_ARROW}　キンセツシティ$"

Route110_Text_TrainerTipsPrlzSleep: @ 0x081E9F05
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンを　ねむらせたり　まひさせると\n"
	.string "あいての　じゆうを　うばえます！\p"
	.string "これは　ポケモンしょうぶの\n"
	.string "じゅうような　テクニック　です！$"

Route110_Text_TrainerTipsRegisterItems: @ 0x081E9F56
	.string "おとくな　けいじばん！！\p"
	.string "バッグに　いれた　どうぐは\n"
	.string "セレクトボタンを　おすと　じゅんばんを\l"
	.string "いれかえる　ことが　できます！$"

Route110_Text_TrickHouseSign: @ 0x081E9F95
	.string "ここより　{RIGHT_ARROW}へ3ぽ　{UP_ARROW}へ2ほ　ゆけば\n"
	.string "そこは　すてきな　‘カラクリやしき’！$"

Route110_Text_BestRecord: @ 0x081E9FC0
	.string "いままでの　さいこう　きろく⋯⋯\p"
	.string "ぶつかった　かいすう\n"
	.string "　⋯⋯　{STRING 0x02}！\p"
	.string "かかった　タイム\n"
	.string "　⋯⋯　{STRING 0x03}！$"

Route110_Text_ThereIsNoRecord: @ 0x081E9FF5
	.string "いままでの　さいこう　きろく⋯⋯\p"
	.string "⋯⋯　だれも　ちょうせん　していないのか\n"
	.string "なにも　きろく　されていない！$"

Route110_Text_ImagineSeeingYouHere: @ 0x081EA02B
	.string "オダマキ“おお　{STRING 0x01}{STRING 0x05}！\n"
	.string "こんな　ところに　いたのかい！\p"
	.string "えーと　うちの　{STRING 0x06}は⋯⋯$"

Route110_Text_HeardYouInstallMatchCall: @ 0x081EA057
	.string "そうか！\n"
	.string "きみたちは　べつこうどう　なんだね\p"
	.string "まあ　それは　いいとして⋯⋯\n"
	.string "そうそう！　きみの　ポケナビに\l"
	.string "エントリーコールが　セットされたって？\p"
	.string "ならば　わたしも　とうろく　しておこう！\p"
	.string "そうすれば　きみと　はなれていても\n"
	.string "いつでも　ポケモンずかんの　ひょうかを\l"
	.string "してあげられる　からね！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

Route110_Text_RegisteredBirchInPokenav: @ 0x081EA0F2
	.string "オダマキはかせを\n"
	.string "ポケナビに　とうろく　した！$"

Route110_Text_KeepAnEyeOutForRival: @ 0x081EA10A
	.string "オダマキ“{STRING 0x01}{STRING 0x05}⋯⋯\p"
	.string "{STRING 0x06}のこと　よろしく　たのむよ\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "じゃあ　わたしは　これで　しつれいする\n"
	.string "またな　{STRING 0x01}{STRING 0x05}！$"
