@ SlateportCity scripts (JP map g0 m1 @ 0x081DBFD3)

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition::
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame::
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend
SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend
SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend
SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end
SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end
SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end
SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end
SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	@ JP uses SCR_OP_WAITMONCRY (0xAE) for this door-animation wait.
	waitdooranim_jp
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim_jp
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end
SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end
SlateportCity_Text_EnergyGuruSellWhatYouNeed: @ 0x081DC9BE
	.string "わし　がんばりや！\n"
	.string "がんばって　いろいろ　うりますよ！$"

SlateportCity_Text_OhYourPokemon: @ 0x081DC9DA
	.string "あら？\n"
	.string "きみの　{STR_VAR_1}⋯⋯$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon: @ 0x081DC9E7
	.string "ものすごく　がんばったのね！\p"
	.string "ごほうびと　して\n"
	.string "この　がんばリボンを　つけてあげて！$"

SlateportCity_Text_ReceivedEffortRibbon: @ 0x081DCA12
	.string "{PLAYER}は　がんばリボンを　もらった！$"

SlateportCity_Text_PutEffortRibbonOnMon: @ 0x081DCA24
	.string "{PLAYER}は　がんばリボンを\n"
	.string "{STR_VAR_1}に　つけて　あげた！$"

SlateportCity_Text_GoForItLittleHarder: @ 0x081DCA3D
	.string "もっと　がんばってみて！\p"
	.string "がんばれば　わたしが　ポケモンに\n"
	.string "いいもの　あげるから！$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt: @ 0x081DCA67
	.string "あっ！　きみの　{STR_VAR_1}\n"
	.string "がんばリボン　にあってるよ！$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon: @ 0x081DCA81
	.string "とうだいの　あかりは\n"
	.string "すう10キロさき　にも　とどくんだ\p"
	.string "うみの　なかの　ポケモン\n"
	.string "まぶしくて　おどろいて　いないかな？$"

SlateportCity_Text_SeaweedFullOfLife: @ 0x081DCABE
	.string "ほれ　みてみろ！\p"
	.string "このあたりで　とれる　かいそうは\n"
	.string "しんせん　ピチピチ！\p"
	.string "いまにも　おそい　かかって　きそうだ！$"

SlateportCity_Text_HowTownIsBornAndGrows: @ 0x081DCAF7
	.string "みずの　きれいな　ところに\n"
	.string "たくさんの　みのりが　あつまり\p"
	.string "ひとびとが　やってくる　ところに\n"
	.string "いちばが　できる⋯⋯\p"
	.string "こうして　まちは　おおきくなるのさ$"

SlateportCity_Text_SlateportWonderfulPlace: @ 0x081DCB43
	.string "うみの　かおりが　する　ばしょで\n"
	.string "かいものが　できるなんて⋯⋯\p"
	.string "カイナって　すてきな　ところ！$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty: @ 0x081DCB73
	.string "ぬいぐるみや　クッションって\n"
	.string "ゆかに　おくと　よごれちゃうでしょ？\p"
	.string "だから　きれいなまま　かざれるように\n"
	.string "ぬいぐるみや　クッションを　おくための\l"
	.string "レンガを　かいに　きたの！$"

SlateportCity_Text_GoingToCompeteInBattleTent: @ 0x081DCBCA
	.string "うぉー！　バトルテントに\n"
	.string "ぼくも　しゅつじょう　するぞおー！\p"
	.string "と　そのまえに！\n"
	.string "ポケモン　つかまえて　こなくちゃ！$"

SlateportCity_Text_BushedHikingFromMauville: @ 0x081DCC04
	.string "ふぅ　ふぅ⋯⋯\p"
	.string "おれは　キンセツシティ　から\n"
	.string "あるいて　ここまで　きたんだけど\l"
	.string "この　まちって　ひろいなぁ⋯⋯\p"
	.string "こんな　ことなら　じてんしゃに\n"
	.string "のって　くれば　よかったよ！$"

SlateportCity_Text_EveryoneCallsHimCaptStern: @ 0x081DCC5B
	.string "この　はくぶつかんを　つくったのは\n"
	.string "クスノキさん　といって\p"
	.string "かいていを　たんさくする　せんすいていの\n"
	.string "かんちょう　でも　あるんだ！\p"
	.string "せんすいていの　かんちょうで\n"
	.string "はくぶつかんの　かんちょう⋯⋯\p"
	.string "まあ　どっちにせよ\n"
	.string "クスノキかんちょう　と　よんでおけば\l"
	.string "まちがい　ないよな！$"

SlateportCity_Text_WhatsLongLineOverThere: @ 0x081DCCE4
	.string "なんなのかしら\n"
	.string "あの　ぎょうれつ？$"

SlateportCity_Text_VisitedMuseumOften: @ 0x081DCCF6
	.string "この　はくぶつかん　には\n"
	.string "こどもの　ころ　わたしも　よく　きました\p"
	.string "かんないの　てんじひんを　みて\n"
	.string "うみの　しんぴに　あこがれた　ものです$"

SlateportCity_Text_QuitPushing: @ 0x081DCD3C
	.string "ちょっと　あんた！　おさないでよ！\n"
	.string "じゅんばん　なんだから！$"

SlateportCity_Text_AquaHasPolicy: @ 0x081DCD5B
	.string "おれたち　アクアだんの　ポリシーは\n"
	.string "‘げんち　しゅうごう’　そして\l"
	.string "‘げんち　かいさん’　なんだぜ！$"

SlateportCity_Text_BossIsBrilliant: @ 0x081DCD8E
	.string "リーダーほど　あたまの　いい　ひとが\n"
	.string "いまさら　はくぶつかんに\l"
	.string "なんの　ようじが　あるんだ⋯⋯？$"

SlateportCity_Text_WhatsNewSchemeIWonder: @ 0x081DCDBF
	.string "こんどの　さくせんは　なんだろう？\p"
	.string "リーダーを　おこらせると　こわいから\n"
	.string "しっぱい　したくないぜ⋯⋯$"

SlateportCity_Text_ShouldTakeItAll: @ 0x081DCDF2
	.string "はくぶつかんに　ほしいもの　あるなら\n"
	.string "まるごと　うばっちゃえば　いいのに⋯⋯$"

SlateportCity_Text_DontButtIn: @ 0x081DCE19
	.string "おい　こら！\n"
	.string "じゅんばん　ぬかすなよ！$"

SlateportCity_Text_RemindsMeOfLongLineForGames: @ 0x081DCE2D
	.string "ぎょうれつ　というと\n"
	.string "だいにんきの　ゲームを　かったときを\l"
	.string "おもいだすなあ⋯⋯$"

SlateportCity_Text_WhyAreWeLiningUp: @ 0x081DCE55
	.string "まじめに　おかね　はらわずに\n"
	.string "むりやり　はいれば　いいのによ！$"

SlateportCity_Text_WhatDoYouWant: @ 0x081DCE75
	.string "なんだ　なんだ！？$"

SlateportCity_Text_IllReadSignForYou: @ 0x081DCE7F
	.string "おまえ　このカンバンが　よみたいのか？\n"
	.string "なら　オレが　かわりに　よんでやらぁ！$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless: @ 0x081DCEA7
	.string "えーと⋯⋯\p"
	.string "“てしない　それは　の　の”\p"
	.string "⋯⋯って　かいて　あるぜ！$"

SlateportCity_Text_ShouldveBroughtMyGameBoy: @ 0x081DCECA
	.string "ぶつぶつぶつ⋯⋯\p"
	.string "ゲームボーイが　あれば\n"
	.string "ぎょうれつも　たいくつ　しないぜ\p"
	.string "ぶつぶつぶつ⋯⋯$"

SlateportCity_Text_HotSpringsAfterOperation: @ 0x081DCEF9
	.string "このさくせんが　おわったら\n"
	.string "おんせんに　つれていって　やる！\p"
	.string "って　リーダーが　いってたんだ\n"
	.string "たのしみ　だなぁ⋯⋯$"

SlateportCity_Text_SeaIsSoWet: @ 0x081DCF33
	.string "うみって　おおきいなあ⋯⋯\p"
	.string "ひょっとして　うみって\n"
	.string "ポケモンが　ながした　なみだで\l"
	.string "できてるのかなあ⋯⋯$"

SlateportCity_Text_SinkOldBoats: @ 0x081DCF68
	.string "ふるく　なって　のれない　ふねは\n"
	.string "どうするか　しって　いるかね？\p"
	.string "うみの　そこに　しずめて\n"
	.string "ポケモンの　すみかに　してやるのだよ！$"

SlateportCity_Text_BuyTooMuch: @ 0x081DCFAA
	.string "ここに　くると　うれしくて\n"
	.string "つい　たくさん　かいもの　しちゃう！$"

SlateportCity_Text_GetNameRaterToHelpYou: @ 0x081DCFCB
	.string "ポケモンの　ニックネームを　かえたいなら\n"
	.string "せいめい　はんだんしに　たのむんだね！$"

SlateportCity_Text_CantChangeTradeMonName: @ 0x081DCFF4
	.string "ひとと　こうかんした　ポケモンは\n"
	.string "ニックネームを　かえられないわよ！\p"
	.string "だって　つけた　ひとの　きもちが\n"
	.string "こめられて　いるんですもの！$"

SlateportCity_Text_BattleTentBuiltRecently: @ 0x081DD037
	.string "さいきん　カイナには\n"
	.string "バトルテントが　できたんだ\l"
	.string "ジムも　いいけど　バトルテントも　いいぜ！\p"
	.string "おまえも　つよい　ポケモン　さがしに\n"
	.string "いって　みなよ！$"

SlateportCity_Text_CaptSternBeingInterviewed: @ 0x081DD082
	.string "ゆうめいな　スターが　きていたら\n"
	.string "サインを　もらうつもり　だったのに\p"
	.string "インタビュー　されてるのは\n"
	.string "あれ⋯⋯　クスノキさん　でないかい？$"

SlateportCity_Text_InterviewerSoCool: @ 0x081DD0C6
	.string "あの　インタビュアーの　おねえさん\n"
	.string "かっこよくて　びじん！\p"
	.string "あたしも　おおきく　なったら\n"
	.string "こくさい　ジャーナリストに　なるわ！$"

SlateportCity_Text_SternSaysDiscoveredSomething: @ 0x081DD106
	.string "クスノキかんちょうは　うみの　そこで\n"
	.string "なにかを　はっけん　したんだって！\p"
	.string "なんだろなー？　なんだろなー？$"

SlateportCity_Text_CaptainComeBackWithBigFish: @ 0x081DD13B
	.string "なんだ　なんだ！？\p"
	.string "かんちょうは　うみの　そこから\n"
	.string "おおもの　でも　つりあげたのか？$"

SlateportCity_Text_AmIOnTV: @ 0x081DD166
	.string "みんなー！　みてるかー！\n"
	.string "おれも　テレビに　うつってるかー？$"

SlateportCity_Text_CaptainsACelebrity: @ 0x081DD185
	.string "テレビが　しゅざいに　くる　なんて\n"
	.string "かんちょうも　ゆうめいじん　ですなあ！$"

SlateportCity_Text_BigSmileForCamera: @ 0x081DD1AB
	.string "ダイ“はい　クスノキさん\n"
	.string "そこで　えがお！$"

SlateportCity_Text_MostInvaluableExperience: @ 0x081DD1C1
	.string "マリ“なるほど　なるほど　それは\n"
	.string "きちょうな　たいけんを　なさいましたね⋯⋯$"

SlateportCity_Text_SternMoveAheadWithExploration: @ 0x081DD1E8
	.string "クスノキ“⋯⋯というわけで　こんごも\n"
	.string "ちょうさは　つづけて　いきますよ！$"

SlateportCity_Text_GabbyWonderfulThanksForInterview: @ 0x081DD20D
	.string "マリ“そうですか　いやあ　クスノキさん！\n"
	.string "きょうは　おいそがしい　ところ\l"
	.string "どうも　ありがとう　ございました！\p"
	.string "また　なにか　はっけんが　ありましたら\n"
	.string "ぜひ　しゅざい　させて　くださいね！$"

SlateportCity_Text_SternWhewFirstInterview: @ 0x081DD26B
	.string "クスノキ“ふう⋯⋯\p"
	.string "テレビカメラに　うつされる　なんて\n"
	.string "はじめて　だったから　きんちょう　したよ！$"

SlateportCity_Text_OhPlayerWeMadeDiscovery: @ 0x081DD29D
	.string "おっ！　{PLAYER}{KUN}\n"
	.string "げんきそう　だね！\p"
	.string "こんかいの　かいてい　ちょうさで\n"
	.string "すごい　はっけんを　したんだよ！\p"
	.string "128ばん　すいどうで\n"
	.string "おおむかしに　ぜつめつ　したと　いわれる\l"
	.string "ポケモンの　すみかと　おもわれる\l"
	.string "かいてい　どうくつを　みつけた⋯⋯$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine: @ 0x081DD316
	.string "“フフフ⋯⋯\n"
	.string "クスノキかんちょう　とやら\p"
	.string "きみの　せんすいていは\n"
	.string "われわれ　アクアだんが　いただく！\p"
	.string "きみたちは　われわれに　だまって\n"
	.string "きょうりょく　すれば　いいのだよ！\p"
	.string "フフフ⋯⋯\n"
	.string "これから　アクアだんが　なにを　するか\l"
	.string "たのしみに　していたまえ！”$"

SlateportCity_Text_SternWhatWasAllThat: @ 0x081DD395
	.string "クスノキ“いまの　こえは⋯⋯？\p"
	.string "だれかが　かくせいきを　つかって⋯⋯\p"
	.string "どこから　はなしてるんだ⋯⋯？$"

SlateportCity_Text_FromHarborTryingToTakeSub: @ 0x081DD3C8
	.string "ふねのりばの　なか！\p"
	.string "せんすいていが⋯⋯　うばわれる⋯⋯？$"

SlateportCity_Text_PleaseComeWithMe: @ 0x081DD3E6
	.string "{PLAYER}{KUN}！\n"
	.string "いっしょに　きてくれ！$"

SlateportCity_Text_BattleTentSign: @ 0x081DD3F8
	.string "バトルテント　カイナシティ　かいじょう\n"
	.string "さがせ！　さいきょう　ポケモン$"

SlateportCity_Text_SternsShipyardWantedSign: @ 0x081DD41C
	.string "‘クスノキ　ぞうせんじょ’\p"
	.string "なみを　じざいに　あやつる　ふなのり\n"
	.string "だいぼしゅう　してます！$"

SlateportCity_Text_SternsShipyardNearsCompletion: @ 0x081DD44A
	.string "‘クスノキ　ぞうせんじょ’\p"
	.string "カイナと　ミナモを　むすぶ\n"
	.string "れんらくせん　タイドリップごうは\l"
	.string "かんせい　まで　あと　わずか！$"

SlateportCity_Text_SternsShipyardFerryComplete: @ 0x081DD487
	.string "‘クスノキ　ぞうせんじょ’\p"
	.string "れんらくせん　タイドリップごうに\n"
	.string "じょうせんを　きぼう　される　かたは\l"
	.string "ふねのりば　うけつけ　まで　どうぞ！$"

SlateportCity_Text_PokemonFanClubSign: @ 0x081DD4CC
	.string "‘ポケモン　だいすきクラブ’\n"
	.string "ポケモンが　すきなひと　みんな　あつまれ！$"

SlateportCity_Text_OceanicMuseumSign: @ 0x081DD4F1
	.string "はてしない　うみ⋯⋯\n"
	.string "それは　いのちの　みなもと⋯⋯\p"
	.string "‘うみの　かがく　はくぶつかん’$"

SlateportCity_Text_CitySign: @ 0x081DD51D
	.string "ここは　カイナ　シティ\n"
	.string "ヒトと　ポケモンが　いきかう　みなと$"

SlateportCity_Text_MarketSign: @ 0x081DD53C
	.string "‘カイナ　いちば’\n"
	.string "ここでしか　かえない　もの　たくさん！$"

SlateportCity_Text_HarborFerryUnderConstruction: @ 0x081DD55A
	.string "‘カイナ　シティ　ふねのりば’\p"
	.string "れんらくせん　タイドリップごう　は\n"
	.string "ぞうせんじょ　にて　けんぞう　ちゅう！\p"
	.string "もう　しばらく　おまちください！$"

SlateportCity_Text_HarborSign: @ 0x081DD5A1
	.string "‘カイナ　シティ　ふねのりば’\p"
	.string "れんらくせん　タイドリップごうで\n"
	.string "ふねの　たびを　おたのしみ　ください！$"

SlateportCity_Text_NameRatersHouseSign: @ 0x081DD5D6
	.string "‘せいめい　はんだんし　の　いえ’\n"
	.string "ポケモンの　なまえ　うらないます$"

SlateportCity_Text_ExplainBerries: @ 0x081DD5F9
	.string "きずついた　やせいの　ポケモンは\n"
	.string "きのみを　かじって　けがを　なおすの\p"
	.string "しってた？\p"
	.string "それを　もくげきした　だれかが\n"
	.string "きのみから　くすりを　つくることを\l"
	.string "おもいついたの\p"
	.string "しってた？\p"
	.string "きのみを　くすりに　するためには\n"
	.string "こなごなに　くだいて　こなにするの\p"
	.string "しってた？\p"
	.string "あなた⋯⋯\n"
	.string "きのみに　きょうみが　ありそうね！\p"
	.string "いいものを　あげるわ$"

SlateportCity_Text_ExplainBerryPowder: @ 0x081DD69F
	.string "さいきん　ポケモンセンターの　2かいの\n"
	.string "ダイレクト　コーナー　というところに\l"
	.string "きのみを　つぶす　きかいを\l"
	.string "おいて　もらったの\p"
	.string "しってた？\p"
	.string "そこで　きのみの　こなを　つくってきて！\p"
	.string "きのみの　こなを\n"
	.string "たくさん　つくって　きてくれたら\l"
	.string "いろいろな　くすりを　あげるわ$"

SlateportCity_Text_BroughtMeSomeBerryPowder: @ 0x081DD723
	.string "きのみの　こなを　もってきたの？$"

SlateportCity_Text_ExchangeWhatWithIt: @ 0x081DD734
	.string "なにと　こうかん　しましょ？$"

SlateportCity_Text_ExchangeBerryPowderForItem: @ 0x081DD743
	.string "{STR_VAR_1}　と\n"
	.string "こうかん　するのね？$"

SlateportCity_Text_DontHaveEnoughBerryPowder: @ 0x081DD753
	.string "あれま！？\n"
	.string "こなが　たりない　じゃないの！$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse: @ 0x081DD769
	.string "まあ　いいこな　だこと！\p"
	.string "あなたが　くれた　こなで\n"
	.string "また　いいくすりを　つくれるわ！\p"
	.string "ほかにも　なにか　こうかんする？$"

SlateportCity_Text_WhenYouGetMoreBringItToMe: @ 0x081DD7A5
	.string "そう\n"
	.string "こなが　できたら　また　よろしくね！$"

SlateportCity_Text_ComeBackToTradeBerryPowder: @ 0x081DD7BB
	.string "くすりと　こうかん　したくなったら\n"
	.string "また　ここに　くるのよ\p"
	.string "わたしが　いつも\n"
	.string "おみせ　だしてるから　ね\p"
	.string "しってた？$"

SlateportCity_Text_YouDroveTeamAquaAway: @ 0x081DD7F5
	.string "エニシダ“⋯⋯あれ？\n"
	.string "きみとは　まえに　どこかで　あったよね\p"
	.string "じこしょうかい　したっけ？\n"
	.string "わたしは　エニシダ　って　いうんだ\p"
	.string "いま　ここから　アクアだんが\n"
	.string "にげだして　いったけど\l"
	.string "もしかして　きみが　やっつけたの　かい？$"

SlateportCity_Text_MaybeThisTrainer: @ 0x081DD864
	.string "エニシダ“うーむ　これは\n"
	.string "ひょっとして　ひょっとすると⋯⋯$"

SlateportCity_Text_LetsRegisterEachOther: @ 0x081DD882
	.string "エニシダ“⋯⋯よっし！\n"
	.string "きみとは　なかよく　なれそう　だから\l"
	.string "おたがい　ポケナビに\l"
	.string "なまえを　とうろく　しておこう！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

SlateportCity_Text_RegisteredScott: @ 0x081DD8C6
	.string "エニシダ　という　ひとを\n"
	.string "ポケナビに　とうろく　した！$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou: @ 0x081DD8E2
	.string "エニシダ“ホントは　きみに\n"
	.string "くっついて　いきたい　ところ　だけど\l"
	.string "ほかのひとの　さいのうも　きになるし\p"
	.string "もうすこし　いろんな　まちを\n"
	.string "たずね　あるいて　みるよ！\p"
	.string "じゃあね　{PLAYER}{KUN}！$"

SlateportCity_Text_TakingBattleTentChallenge: @ 0x081DD93E
	.string "エニシダ“お　おおっと\n"
	.string "{PLAYER}{KUN}か！\p"
	.string "⋯⋯もしかして　{PLAYER}{KUN}\n"
	.string "バトルテントに　ちょうせん　するのかい？\p"
	.string "うん！　それは　いいことだな！\n"
	.string "ものすごく　いいことだ！\l"
	.string "バトルテントには　つよい　トレーナーが\l"
	.string "とっても　ふさわしい　からね\p"
	.string "じゃ　がんばってね！$"
