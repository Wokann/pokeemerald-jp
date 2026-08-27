BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim_jp
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim_jp
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "トレーナーの　こころを　ためす　ばしょ\n"
	.string "バトルパレスへ　ようこそ\p"
	.string "ここでは　シングル　バトルホールへの\n"
	.string "ちょうせんを　うけつけて　おる⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "シングル　バトルホールに\n"
	.string "ちょうせん　するか？$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "ここには　シングル　バトルホールと\n"
	.string "よばれる　シングルバトルの　ための\l"
	.string "ひろまを　いくつか　ようい　しておる\p"
	.string "ここでの　たたかいには\n"
	.string "まもらなければ　ならない\l"
	.string "ひとつの　おきてが　ある\p"
	.string "ここでは　ポケモンは\n"
	.string "いれかえ　しか　できない！\p"
	.string "それいがいの　めいれいは\n"
	.string "いっさい　きんし　して　おるのだ！\p"
	.string "ポケモンには　せいかくの　ままに\n"
	.string "かんがえ　こうどう　して　もらう！\p"
	.string "おぬしは　じぶんの\n"
	.string "ポケモンたちを　しんじて\l"
	.string "たたかいを　みまもって　やれ\p"
	.string "みごと　7にんの　トレーナーを\n"
	.string "うちやぶることが　できれば\l"
	.string "バトルポイントを　さしあげよう\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ときは\l"
	.string "きちんと　レポートを　かかないと\l"
	.string "つづけて　ちょうせん　できんからな\l"
	.string "きを　つけてくれ⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "おのれの　こころと　ポケモンを　きたえたら\n"
	.string "また　くるがよい⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "レベル50のへや　オープンレベルのへやが\n"
	.string "あるが　どちらに　ちょうせん　するのだ？$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "おぬし⋯⋯\p"
	.string "ちょうせん　できる　ポケモンが\n"
	.string "3ひき　おらんぞ！\p"
	.string "ちょうせん　するには　レベルが　50いかで\n"
	.string "すべて　ちがう　しゅるいの　ポケモンを\p"
	.string "3ひき　ようい　してくれ\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　もので　なければ　いかん\p"
	.string "そして　タマゴ{STR_VAR_1}ちょうせん　させる　ことは　できん！\p"
	.string "じゅんびを　ととのえてから　また　きなさい$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "おぬし⋯⋯\p"
	.string "ちょうせん　できる　ポケモンが\n"
	.string "3ひき　おらんぞ！\p"
	.string "ちょうせん　するには\n"
	.string "すべて　ちがう　しゅるいの　ポケモンを\p"
	.string "3ひき　ようい　してくれ\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　もので　なければ　いかん\p"
	.string "そして　タマゴ{STR_VAR_1}ちょうせん　させる　ことは　できん！\p"
	.string "じゅんびを　ととのえてから　また　きなさい$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "では　ちょうせんする　ポケモンを\n"
	.string "3ひき　えらんでくれ$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "バトルホールへ　むかうまえに\n"
	.string "レポートを　かくが　よろしいか？$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "それでは\n"
	.string "わしに　ついてこい⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "よいものを　みせて　もらった\p"
	.string "それでは　せいせきを　レポートに　かくぞ\n"
	.string "しばし　またれよ⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "7にんぬき　たっせい　とは⋯⋯\p"
	.string "おぬしと　ポケモンの　こころの　きずなは\n"
	.string "まことの　ようじゃな⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "せいせきを　レポートに　かくぞ\n"
	.string "しばし　またれよ⋯⋯$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "7にんぬきの　あかしに\n"
	.string "バトルポイントを　さしあげよう⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "どうぐが　いっぱいの　ようだな⋯⋯\p"
	.string "どうぐを　せいりしてから\n"
	.string "また　くるがよい⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "まっておったぞ⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "バトルホールへ　むかうまえに\n"
	.string "レポートを　かくぞ⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "おぬし⋯⋯\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しなかったな？\p"
	.string "ざんねんだが　そのばあい\n"
	.string "ちょうせんは　むこうと　なる⋯⋯$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "ウス！　ウス！　がんばりやの　わしには\n"
	.string "がんばりやの　ポケモンが　ぴったりっス！\p"
	.string "こうげき　こそ　さいだいの　ぼうぎょ！\n"
	.string "ガンガン　せめまくって　さいこうっス！\p"
	.string "ところで　きいて　くださいッスよー\p"
	.string "ときどき　ここに　とっても\n"
	.string "かわいい　おじょうちゃんが\l"
	.string "あそびに　くるッスけど\l"
	.string "そのこったら　ポケモンの　きもちが\l"
	.string "わかるとか　いうんスよー\p"
	.string "いやー　ほんと　かわいいッスよねー⋯⋯\p"
	.string "⋯⋯　ん　なんスか？　そのめは？$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "うーん⋯⋯\p"
	.string "どうやら　ここでは　ポケモンの　せいかくと\n"
	.string "おぼえさせている　わざとの　あいしょうが\l"
	.string "たたかいの　カギを　にぎってる　ようだ\p"
	.string "そう⋯⋯　もし　きみの　ポケモンが\n"
	.string "じぶんの　ちからが　はっき　できなくて\l"
	.string "こまっている　ようす　だったら\l"
	.string "おぼえさせている　わざから\l"
	.string "かんがえ　なおす　ひつようが　あるかもな$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "あたしの　ポケモン\n"
	.string "ふだんは　とーっても　おとなしいのよ\p"
	.string "だけど　バトルホールで　たたかってると\n"
	.string "ときどき　めつきが\l"
	.string "ガラッと　かわっちゃうの！\p"
	.string "すっごい　はくりょくで　びっくりしちゃう！$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "あいてを　よわらせたり⋯⋯\n"
	.string "じわじわ　せめて　くれるのは\l"
	.string "どんな　せいかくかな⋯⋯\p"
	.string "⋯⋯　いがいに　のうてんき　とか？\p"
	.string "⋯⋯　まさかねぇ⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "トレーナーの　こころを　ためす　ばしょ\n"
	.string "バトルパレスへ　ようこそ\p"
	.string "ここでは　ダブル　バトルホールへの\n"
	.string "ちょうせんを　うけつけておる⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "ダブル　バトルホールに\n"
	.string "ちょうせん　するか？$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "ここには　ダブル　バトルホールと\n"
	.string "よばれる　ダブルバトルの　ための\l"
	.string "ひろまを　いくつか　ようい　しておる\p"
	.string "ここでの　たたかいには\n"
	.string "まもらなければ　ならない\l"
	.string "ひとつの　おきてが　ある\p"
	.string "ここでは　ポケモンは\n"
	.string "いれかえ　しか　できない！\p"
	.string "それいがいの　めいれいは\n"
	.string "いっさい　きんし　して　おるのだ！\p"
	.string "ポケモンには　せいかくの　ままに\n"
	.string "かんがえ　こうどう　して　もらう！\p"
	.string "おぬしは　じぶんの\n"
	.string "ポケモンたちを　しんじて\l"
	.string "たたかいを　みまもって　やれ\p"
	.string "みごと　7にんの　トレーナーを\n"
	.string "うちやぶることが　できれば\l"
	.string "バトルポイントを　さしあげよう\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ときは\l"
	.string "きちんと　レポートを　かかないと\l"
	.string "つづけて　ちょうせん　できんからな\l"
	.string "きを　つけてくれ⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "パレスガーディアンを　たおし\n"
	.string "7にんぬきを　たっせいするとは⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "おぬしと　ポケモンの　きずなを　たたえ\n"
	.string "バトルポイントを　おくろう⋯⋯$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "バトルパレスで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　するか？$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "バトルホールの　ルールが　かかれている！$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "ここでは　ポケモンたちが\n"
	.string "じぶんで　かんがえ　たたかいます\p"
	.string "じゅんすいな　やせいの　ときとは　ちがって\n"
	.string "ひとと　くらしている　ポケモンは\l"
	.string "せいかくに　よって　どんな　こうどうを\l"
	.string "するかが　かわるのです$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "とにかく　こうげきが\n"
	.string "すきな　せいかく\p"
	.string "じぶんの　からだを　まもる　ことが\n"
	.string "すきな　せいかく\p"
	.string "あいてを　こまらせたり　かわった　ことを\n"
	.string "するのが　すきな　せいかく\p"
	.string "ポケモンは　せいかくに　よって\n"
	.string "すきで　とくいな　わざと\l"
	.string "きらいで　にがてな　わざが　ちがいます$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "あいてに　むかって　じぶんから\n"
	.string "ちょくせつ　ダメージを　あたえる\l"
	.string "こうげきの　わざ\p"
	.string "たたかいの　じゅんびや　キズついた　からだの\n"
	.string "かいふくを　する　ぼうぎょの　わざ\p"
	.string "あいての　のうりょくを　さげたり\n"
	.string "どくや　まひに　したり　などの\l"
	.string "すこし　かわった　ことを　する　わざ\p"
	.string "ポケモンは　すべての　わざを\n"
	.string "おおきく　3つの　しゅるいに　わけて\l"
	.string "どんな　わざを　だすか　かんがえて　います$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "トレーナーの　めいれいを　うけて　いない\n"
	.string "ポケモンは　うまく　わざを\l"
	.string "だせない　ことが　あります\p"
	.string "ポケモンは　きらいな　わざを\n"
	.string "つかうのは　とくいでは　ありません\p"
	.string "せいかくに　あわない　わざ　ばかりを\n"
	.string "おぼえさせて　いると　たたかいで\l"
	.string "ポケモンが　じぶんの　ちからを　はっき\l"
	.string "できない　ことが　おおく　なります$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "ポケモンの　せいかくの　なかには\n"
	.string "ピンチに　なることで　もともとの\l"
	.string "せいかくとは　ちがう　タイプの\l"
	.string "わざを　つかう　ように\l"
	.string "なるものが　あります\p"
	.string "ピンチに　なって　すこし　かわった\n"
	.string "こうどうを　はじめた　ポケモンには\l"
	.string "じゅうぶん　ちゅうい　しましょう$"
