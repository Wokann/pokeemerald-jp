@ SlateportCity_BattleTentLobby scripts (JP map g9 m2 @ 0x081FB033)

SlateportCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
	.byte 0

SlateportCity_BattleTentLobby_OnWarp:: @ 0x081FB03E
	map_script_2 VAR_TEMP_1, 0x0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth:: @ 0x081FB048
	setvar VAR_TEMP_1, 0x1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentLobby_OnFrame:: @ 0x081FB052
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x1, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x2, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x3, SlateportCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x4, SlateportCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus:: @ 0x081FB07C
	frontier_getstatus
	end

SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving:: @ 0x081FB085
	lockall
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_WonChallenge:: @ 0x081FB0BA
	lockall
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
	waitmessage
	slateporttent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse

SlateportCity_BattleTentLobby_EventScript_GivePrize:: @ 0x081FB0EC
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
	slateporttent_giveprize
	switch VAR_RESULT
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize:: @ 0x081FB12D
	msgbox SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_LostChallenge:: @ 0x081FB13A
	lockall
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse

SlateportCity_BattleTentLobby_EventScript_EndGivePrize:: @ 0x081FB164
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_ResumeChallenge:: @ 0x081FB174
	lockall
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
	waitmessage
	slateporttent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	setvar VAR_0x8006, 0x2
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge

SlateportCity_BattleTentLobby_EventScript_Attendant:: @ 0x081FB1AD
	lock
	faceplayer
	slateporttent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, SlateportCity_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT

SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge:: @ 0x081FB1CD
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 0x11, 0x6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge:: @ 0x081FB209
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge:: @ 0x081FB253
	setvar VAR_TEMP_CHALLENGE_STATUS, 0x0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	slateporttent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 0x2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	goto_if_eq VAR_RESULT, 0x0, SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0x0

SlateportCity_BattleTentLobby_EventScript_EnterChallenge:: @ 0x081FB2AF
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 0x2, 0x7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0x0
	waitstate
	end

SlateportCity_BattleTentLobby_EventScript_WalkToDoor:: @ 0x081FB2CC
	applymovement LOCALID_SLATEPORT_TENT_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 0x6, 0x1
	waitdooranim_jp
	applymovement LOCALID_SLATEPORT_TENT_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 0x6, 0x1
	waitdooranim_jp
	return

SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_ExplainChallenge:: @ 0x081FB30A
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge

SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed:: @ 0x081FB317
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge:: @ 0x081FB32E
	special LoadPlayerParty

SlateportCity_BattleTentLobby_EventScript_CancelChallenge:: @ 0x081FB331
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_TormentGiver:: @ 0x081FB340
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_TORMENT, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
	giveitem ITEM_TM_TORMENT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_TORMENT
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_ReceivedTorment:: @ 0x081FB377
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_Man:: @ 0x081FB381
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Girl:: @ 0x081FB38A
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Woman:: @ 0x081FB393
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_RulesBoard:: @ 0x081FB39C
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard:: @ 0x081FB3AB
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 0x11, 0x0, MULTI_SLATEPORT_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
	end

SlateportCity_BattleTentLobby_EventScript_RulesBasics:: @ 0x081FB409
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner:: @ 0x081FB417
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber:: @ 0x081FB425
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes:: @ 0x081FB433
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesMons:: @ 0x081FB441
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ExitRules:: @ 0x081FB44F
	releaseall
	end

SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe: @ 0x081FB451
	.string "なかなか　かりたい　ポケモンが\n"
	.string "みつからねぇ　からよぉ\l"
	.string "そこの　にーさんに　もんく　いったけどよぉ\p"
	.string "ちぃっとも　あいて　してくれねぇのさ\n"
	.string "くやしいったら　ありゃ　しねぇぜ！\p"
	.string "おい　おまえ！\n"
	.string "だまって　これを　うけとれよぉ！$"

SlateportCity_BattleTentLobby_Text_ExplainTorment: @ 0x081FB4C1
	.string "わざマシン41は　いちゃもん！\p"
	.string "あいてによぉ　おなじ　わざを　つづけて\n"
	.string "ださせねえように　する　わざ　なんだよぉ！\p"
	.string "いっとくけどなぁ\n"
	.string "おれは　いちゃもん　つけてねぇぞ！$"

SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons: @ 0x081FB516
	.string "たまには　にがてな\n"
	.string "むしタイプの　ポケモンでも\l"
	.string "つかって　みようかな？\l"
	.string "スキに　なるかも　しれないし！$"

SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons: @ 0x081FB54A
	.string "つよい　ポケモン　もってなくても\n"
	.string "ここでなら　いっぱい　しょうぶできるね！$"

SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection: @ 0x081FB570
	.string "ステキな　トレーナーの　おにいさんも\n"
	.string "かしだして　くれれば　いいのにぃ$"
