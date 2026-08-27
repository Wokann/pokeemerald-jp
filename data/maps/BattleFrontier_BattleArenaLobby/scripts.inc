BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim_jp
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim_jp
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim_jp
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim_jp
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "トレーナーの　とうしを　ためす　ばしょ！！\p"
	.string "バトルアリーナへ\n"
	.string "ようこそ　おいでなされた！\p"
	.string "こちらでは　かちぬきチームバトルの\n"
	.string "あんないを　しておりますぞ！$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "バトルアリーナに\n"
	.string "ちょうせん　されますかな？$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "バトルアリーナは　かちぬきチームバトルを\n"
	.string "おこなう　しせつですぞ！\p"
	.string "さんかする　かたには　しゅつじょう　させる\n"
	.string "3ひきの　ポケモンと　たたかいに　だす\l"
	.string "じゅんばんを　きめて　いただきますぞ！\p"
	.string "たたかいの　あいだは\n"
	.string "この　じゅんばん　どおりに\l"
	.string "ポケモンを　だすことに　なりますな！\p"
	.string "たたかいに　いちど　だした　ポケモンは\n"
	.string "けっちゃくが　つくまで\l"
	.string "こうたい　させる　ことが　できませぬ！\p"
	.string "さらに　3ターン　いないに\n"
	.string "たたかいの　けっちゃくが　つかなければ\l"
	.string "はんていと　なりますぞ！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだんしたい　ばあいは\l"
	.string "レポートを　かかないと\l"
	.string "つづけて　ちょうせんが　できないので\l"
	.string "おきをつけ　くだされ！\p"
	.string "みごと　7にんぬきを　なされた　あかつきには\n"
	.string "バトルポイントを　おおくり　いたしますぞ！$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "バトルアリーナへ　おつれする　まえに\n"
	.string "レポートを　かきますが　よろしいですかな？$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "バトルアリーナには\n"
	.string "レベル50と　オープンレベルと　ありますが\l"
	.string "どちらに　まいられますかな？$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "では　さんかする　ポケモンを\n"
	.string "3ひき　おえらび　くだされ！$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "おきゃくじん！！\p"
	.string "さんかできる　ポケモンが\n"
	.string "3ひき　おりませぬ！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがう　しゅるいの　ポケモンを\l"
	.string "3ひき　よういして　くだされ！\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してくだされ！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させる　ことは　できませぬ！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　くだされ！$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "おきゃくじん！！\p"
	.string "さんかできる　ポケモンが\n"
	.string "3ひき　おりませぬ！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがう　しゅるいの　ポケモンを\l"
	.string "3ひき　よういして　くだされ！\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してくだされ！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させる　ことは　できませぬ！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　くだされ！$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "では　バトルアリーナへ\n"
	.string "おつれいたしますぞ！$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "おきゃくじん！\p"
	.string "ぜんかい　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたな？\p"
	.string "ざんねんですが　その　ばあい\n"
	.string "ちょうせんは　むこうと　なりますぞ！\p"
	.string "また　はじめから\n"
	.string "ちょうせん　してくだされ！！$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "7にんぬき　たっせい\n"
	.string "おみごとで　ございました！$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちくだされ！$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "7にんぬきを　たっせい　されましたので\n"
	.string "この　しょうひんを　おうけとり　くだされ！$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "⋯⋯おおっ！\n"
	.string "どうぐが　いっぱいの　ようですな！\p"
	.string "どうぐを　せいりしてから\n"
	.string "また　おこしくだされ！$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "おつかれさまでした！\p"
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちくだされ！$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "おまちしておりました！\p"
	.string "バトルアリーナに　おつれする　まえに\n"
	.string "レポートを　かきますので　おまちくだされ！$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "バトルアリーナで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　されますかな？$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "はんていで　まけちゃった⋯⋯\p"
	.string "まもる　ばっかりで\n"
	.string "せめなかったのが　よくなかった　みたい⋯⋯$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "はんていで　かったぜ！\p"
	.string "あいての　ポケモンに\n"
	.string "わざを　かくじつに　あてたのが　よかったぜ！$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "はんていで　ひきわけ　だったよ\p"
	.string "じかんぎれに　なったときに\n"
	.string "あいて　ポケモンと　のこりの　HPが\l"
	.string "おなじ　くらい　だったからねぇ⋯⋯$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "バトルアリーナでは　ポケモンの　じゅんばんが\n"
	.string "とっても　だいじ　なのよ！\p"
	.string "たとえば　1ばんめの　ポケモンの\n"
	.string "じゃくてん　となる　タイプに　たいして\p"
	.string "こうかばつぐんの　わざを　もっている\n"
	.string "ポケモンを　2ばんめに　いれておけば\l"
	.string "いいチームに　なると　おもうわ！$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "かちぬきチームバトルの\n"
	.string "ルールが　かかれている！$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "かちぬきチームバトルは　ふつうの　たたかいと\n"
	.string "ちがい　とくべつな　ルールが　あります\p"
	.string "まず　1かいの　たたかいは\n"
	.string "3ターンで　しゅうりょうと　なります\p"
	.string "3ターンで　しょうぶが　つかないときは\n"
	.string "しんぱんに　よる　はんていに　なります\p"
	.string "はんていは　ポケモンの　たたかいかたを\n"
	.string "みて　しょうはいを　けってい　します\p"
	.string "また　しょうぶの　けっちゃくが　つくまで\n"
	.string "ポケモンの　こうたいは　できません$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "1つめの　はんてい　ポイントである\n"
	.string "‘こころ’は\l"
	.string "せめる　きもちを　みられます\p"
	.string "どれだけ　トレーナーが　こうげきする　わざを\n"
	.string "めいれい　したかに　よって\l"
	.string "ひょうかが　かわります$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "2つめの　はんてい　ポイントである\n"
	.string "‘わざ’は　ポケモンの　わざが\l"
	.string "うまく　できたかを　みられます\p"
	.string "わざが　せいこう　すると\n"
	.string "ひょうかは　あがります\p"
	.string "わざが　しっぱい　すると\n"
	.string "ひょうかは　さがります\p"
	.string "さらに　あいてに　わざを　あてたときは\n"
	.string "‘こうかはばつぐん’で　あがり\l"
	.string "‘こうかはいまひとつ’などで　さがります\p"
	.string "また　‘まもる’や　‘みきり’は\n"
	.string "だしても　ひょうかは　あがりません\p"
	.string "あいての　‘まもる’や　‘みきり’で\n"
	.string "わざを　だせなくても\l"
	.string "ひょうかは　さがりません$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "3つめの　はんてい　ポイントである\n"
	.string "‘からだ’は　たいせん　したあとの\l"
	.string "ポケモンの　HPを　みられます\p"
	.string "たいせんが　はじまる　まえの\n"
	.string "HPと　くらべて\l"
	.string "たいせんごの　HPが　どれだけ　あるかで\l"
	.string "ひょうかが　かわります$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "アリーナキャプテンからの　きんぼし！\n"
	.string "ならびに　7にんぬき　たっせい！\l"
	.string "まこと　みごとで　ございました！$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "おきゃくじんの　ふくつの　とうしを　たたえ\n"
	.string "バトルポイントを　さしあげましょう！$"
