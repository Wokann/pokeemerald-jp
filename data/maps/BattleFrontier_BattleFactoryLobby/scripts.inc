BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "トレーナーの　ちしきを　はかる　ばしょ！！\n"
	.string "バトルファクトリーに　ようこそ！\p"
	.string "バトルトレード　シングルへの\n"
	.string "ごあんないは　こちらです！$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "バトルトレード　シングルに\n"
	.string "ちょうせん　しますか？$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "こちらでは　レンタルポケモンを　つかった\n"
	.string "バトルトレード　シングル　という\l"
	.string "イベントを　おこなって　います！\p"
	.string "まずは　バトルトレード　せんようの\n"
	.string "ポケモン　3ひきを　おかし　します！\p"
	.string "つぎに　そちらの　ポケモンを\n"
	.string "つかって　シングルバトルを\l"
	.string "おこなって　いただきます！\p"
	.string "たたかいに　しょうりすると　いちど　だけ\n"
	.string "ポケモンを　トレード　できます！\p"
	.string "トレードと　たたかいを　くりかえし\n"
	.string "みごと　7れんしょう　したら\l"
	.string "バトルポイントを　さしあげます！\p"
	.string "なお　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは\l"
	.string "きちんと　レポートを　かかないと\l"
	.string "つづけて　ちょうせんが　できません！\p"
	.string "くれぐれも　きをつけて　くださいね！$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "またの　ごりようを　おまちしていますよ！$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "レベル50と　オープンレベルの　イベント\n"
	.string "どちらに　ちょうせん　しますか？$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "では　ちょうせんを　はじめる　まえに\n"
	.string "レポートを　かきますが　よろしいですか？$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "それでは　ポケモンを\n"
	.string "おあずかり　します！$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "さあさあ　こちらに　どうぞ！$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "おつかれさまでした！\p"
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　します！\p"
	.string "せいせきを　レポートに　かきますので\n"
	.string "しょうしょう　おまちください！$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　します！$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "バトルトレード　7せん　とっぱ\n"
	.string "おめでとう　ございます！$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "7れんしょうを　きねんして\n"
	.string "バトルポイントを　さしあげます！$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "おやや？\p"
	.string "バトルポイントが　いっぱい　ですねー\p"
	.string "ポイントを　ごりようしてから\n"
	.string "また　きてください！$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "おまちしておりましたよ！\p"
	.string "ちょうせんを　さいかいする　まえに\n"
	.string "レポートを　かきます！$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "おきゃくさまー！！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しません　でしたね！\p"
	.string "ざんねんですが\n"
	.string "ちょうせんは　むこうと　なります！$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "おきゃくさまの　ポケモンを\n"
	.string "おかえしします！$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "トレーナーの　ちしきを　はかる　ばしょ！！\n"
	.string "バトルファクトリーに　ようこそ！\p"
	.string "バトルトレード　ダブルの\n"
	.string "ごあんないは　こちらです！$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "バトルトレード　ダブルに\n"
	.string "ちょうせん　しますか？$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "こちらでは　レンタルポケモンを　つかった\n"
	.string "バトルトレード　ダブル　という\l"
	.string "イベントを　おこなって　います\p"
	.string "まずは　バトルトレード　せんようの\n"
	.string "ポケモン　3ひきを　おかし　します！\p"
	.string "つぎに　そちらの　ポケモンを\n"
	.string "つかって　ダブルバトルを\l"
	.string "おこなって　いただきます！\p"
	.string "たたかいに　しょうりすると　いちど　だけ\n"
	.string "ポケモンを　トレード　できます！\p"
	.string "トレードと　たたかいを　くりかえし\n"
	.string "みごと　7れんしょうを　したら\l"
	.string "バトルポイントを　さしあげます！\p"
	.string "なお　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ときには\l"
	.string "きちんと　レポートを　かかないと\l"
	.string "つづけて　ちょうせんが　できません！\p"
	.string "くれぐれも　きをつけて　くださいね！$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "ファクトリーヘッドへの　しょうり！\n"
	.string "ならびに　7れんしょう　たっせい\l"
	.string "おめでとう　ございます！$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "おきゃくさまの　ふかい　ちしきを　たたえ\n"
	.string "バトルポイントを　さしあげます！$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　しましょう！\p"
	.string "せいせきを　レポートに　かきますので\n"
	.string "しょうしょう　おまちください！$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "バトルファクトリーで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　いたしますか？$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "ちょっと！　キミ！\p"
	.string "ポケモンを　そだてなくても\n"
	.string "ちょうせん　できる　から　らくしょうー！\p"
	.string "とか　おもってない？\p"
	.string "ここは　ポケモンと　そのわざに\n"
	.string "かんする　ちしきが　ないと\l"
	.string "かちぬけない　ひじょうに　きびしー\l"
	.string "ところ　なのよ！！$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "しゅるいに　だまされて　よわいポケモンと\n"
	.string "こうかん　しちゃった⋯⋯\p"
	.string "ボロまけ⋯⋯$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "ダメダメねー！\p"
	.string "トレーナーが　いいポケモン　もってたら\n"
	.string "たたかいの　あいだに\l"
	.string "チェック　しとかなきゃ！$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "ここの　スタッフさぁ　たたかいの　まえに\n"
	.string "つぎに　たたかう　トレーナーのこと\l"
	.string "ちょっとだけ　おしえて　くれるだろー？\p"
	.string "でも　オレ　いい　おとな　なのに\n"
	.string "あいつらの　せつめいの　いみが\l"
	.string "ぜんぜん　わからないんだ　よう$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "ぼくってー　バッチリー　つよいけどー\n"
	.string "すっごくー　あきっぽい　からさー\l"
	.string "とりあえずー\l"
	.string "ばんばん　トレード　しながらー\l"
	.string "たたかってたのさー\l"
	.string "そしたらさー\l"
	.string "つづけてー　バトルトレードにー\l"
	.string "ちょうせん　したときー\l"
	.string "レンタル　してくれるー\l"
	.string "ポケモンのー\l"
	.string "しゅるいがさー\l"
	.string "なんかさー\l"
	.string "ちょっとさー\l"
	.string "ちがったんだよねー$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "バトルトレードの　ルールが　かかれている！$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "バトルトレードで　つかうことの　できる\n"
	.string "ポケモンは　3ひき　まで　です\p"
	.string "レンタルするとき　トレードするとき\n"
	.string "どちらの　とき　でも\l"
	.string "おなじ　しゅるいの　ポケモンを\l"
	.string "2ひき　いじょう　もつことは　できません$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "トレードが　できる　あいては\n"
	.string "あなたが　たたかいで\l"
	.string "たおした　トレーナーです\p"
	.string "トレードで　うけとる　ことが　できるのは\n"
	.string "トレーナーが　つかっていた　ポケモンです$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "いちど　たたかいに　かつ　たびに\n"
	.string "1かい　1ひき　だけ　ポケモンを\l"
	.string "トレード　することが　できます\p"
	.string "1かいの　ちょうせんで\n"
	.string "トレードが　できるのは\l"
	.string "6にんめの　トレーナーまで　です$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "トレードを　おこなう　ときには\n"
	.string "2つ　ちゅういする　ことが　あります\p"
	.string "その1　トレードを　おこなう　ときは\n"
	.string "あいてから　うけとる　ポケモンの\l"
	.string "つよさは　かくにん　できません\p"
	.string "その2　ちょうせんを　はじめた　ときに\n"
	.string "かりた　レンタルポケモンの　じゅんばんが\l"
	.string "トレードの　あとの　たたかいにも\l"
	.string "ひきつがれます$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "オープンレベルの　ちょうせんでは\n"
	.string "レンタルできる　ポケモンも\l"
	.string "あいての　トレーナーが　つかう　ポケモンも\l"
	.string "すべて　レベル100に　なります$"
