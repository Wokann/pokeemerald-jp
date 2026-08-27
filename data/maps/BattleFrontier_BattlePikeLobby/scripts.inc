BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "トレーナーの　うんを　ためす　ばしょ⋯⋯\n"
	.string "バトルチューブへ　ようこそ⋯⋯\p"
	.string "バトルゲームへの　ごあんないは\n"
	.string "こちらで　ございます⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "バトルゲームに\n"
	.string "ちょうせん　されますか⋯⋯？$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "こちらでは　バトルゲームと　いう\n"
	.string "もよおしを　かいさいして　おります\p"
	.string "バトルゲームの　ルールは　かんたん⋯⋯\p"
	.string "3つの　みちを　えらびながら\n"
	.string "バトルチューブの　いちばん　おくに　ある\l"
	.string "ゴールの　へやを　めざして\l"
	.string "すすんで　いく　だけで　よいのです\p"
	.string "⋯⋯　ただし　えらんだ　みちの　さきで\n"
	.string "なにが　おこるかは　おきゃくさまの\l"
	.string "うん　しだい　ですが⋯⋯\p"
	.string "もしも　ゴールに　つくことが　できたなら\n"
	.string "バトルポイントを　さしあげましょう\p"
	.string "なお　ゲームの　ちょうせんを\n"
	.string "ちゅうだんしたい　ばあいは\l"
	.string "おおべやに　たいき　している　スタッフに\l"
	.string "おもうしつけ　ください⋯⋯\p"
	.string "レポートを　かかないと\n"
	.string "ゲームの　さいかいが　できません⋯⋯\p"
	.string "くれぐれも　ごちゅうい　ください⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "では　またの　きかいを\n"
	.string "おまちして　おります⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "レベル50と　オープンレベルの　ゲーム\n"
	.string "どちらに　ちょうせん　しますか？$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "⋯⋯　おきゃくさま\p"
	.string "バトルゲームに　さんかできる\n"
	.string "ポケモンが　3ひき　おりません⋯⋯\p"
	.string "さんかには　レベルが　50いかで\n"
	.string "すべて　ちがう　しゅるいの　ポケモンを\l"
	.string "3ひき　ごようい　ください\p"
	.string "また　もたせる　どうぐも　すべて\n"
	.string "ちがうもので　なければ　いけません⋯⋯\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させる　ことは　できません\p"
	.string "じゅんびが　ととのいましたら\n"
	.string "また　おこしください⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "⋯⋯　おきゃくさま\p"
	.string "バトルゲームに　さんかできる\n"
	.string "ポケモンが　3ひき　おりません⋯⋯\p"
	.string "さんかには　すべて　ちがう　しゅるいの\n"
	.string "ポケモンを　3ひき　ごようい　ください\p"
	.string "また　もたせる　どうぐも　すべて\n"
	.string "ちがうもので　なければ　いけません⋯⋯\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させる　ことは　できません\p"
	.string "じゅんびが　ととのいましたら\n"
	.string "また　おこしください⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "それでは　ゲームに　ちょうせんする\n"
	.string "ポケモンを　3ひき　おえらび　ください⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "バトルゲームを　かいしする　まえに\n"
	.string "レポートを　かきます⋯⋯　よろしいですか？$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "では　こちらに　どうぞ⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "ゲーム　しゅうりょう　ですね⋯⋯\p"
	.string "せいせきを　レポートに　かきましょう⋯⋯\n"
	.string "しょうしょう　おまちください⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "ゲーム　クリア　ですね⋯⋯\p"
	.string "おきゃくさま⋯⋯　なかなかの　うんを\n"
	.string "おもちの　ようですね⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "せいせきを　レポートに　かきましょう⋯⋯\n"
	.string "しばらく　おまちください⋯⋯$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "ゲーム　クリアを　きねんして\n"
	.string "バトルポイントを　しんてい　します⋯⋯\p"
	.string "どうぞ　おおさめ　ください⋯⋯$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "ポイントが　いっぱいの　ようですね⋯⋯\p"
	.string "ポイントを　せいりしてから\n"
	.string "また　おこしください⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "おきゃくさま⋯⋯\p"
	.string "ぜんかい　きちんと　レポートを　かかずに\n"
	.string "しゅうりょう　されましたね⋯⋯\p"
	.string "もうしわけ　ありませんが　ちょうせんは\n"
	.string "むこうと　させて　いただきます⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "⋯⋯　おめでとう　ございます⋯⋯\n"
	.string "チューブクイーンに　しょうりし\l"
	.string "ゲームを　クリア　されましたね⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "おきゃくさまの　つよき　うんを　たたえ\n"
	.string "バトルポイントを　さしあげます⋯⋯$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "んんー！　ちくしょー！！\n"
	.string "あと　1へやで　ゴールだったのによー！\p"
	.string "おまえ！　ここでは　どくや　こおりには\n"
	.string "ちゅうい　したほうが　いいぞ！$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "あたし　10かいは　クリアしたけど\n"
	.string "いっかいも　トレーナーと\l"
	.string "たたかった　こと　ないんだよぅ！$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "ねえ！　ねえ！\p"
	.string "ここって　ポケモンの　とくせいが\n"
	.string "かつやく　すると　おもわない？$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "なんだよ　ここ！　いみ　わかんないよー！\p"
	.string "なんかい　チャレンジ　しても\n"
	.string "どの　みち　えらんでも\l"
	.string "トレーナーしか　でてこない　じゃないかー！$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "バトルゲームの　ルールが　かかれている！$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "バトルゲームの　あいだは\n"
	.string "バッグと　ポケナビの　しようは\l"
	.string "きんし　されています$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "バトルゲームでは\n"
	.string "ポケモンに　もたせた　きのみや　ハーブは\l"
	.string "いちどしか　こうかを　はっき　しません$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "バトルゲームの　あいだは\n"
	.string "ちょうせんする　ときに　きめた\l"
	.string "ポケモンの　じゅんばんを\l"
	.string "いれかえる　ことは　できません$"
