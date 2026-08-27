BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "⋯⋯　なんだぁ？\p"
	.string "おれたちゃ　いま　いそがしいの！\n"
	.string "また　こんどに　してくれや！$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "⋯⋯　ん？\n"
	.string "あんた　つよそうだねぇ⋯⋯\p"
	.string "へっへ⋯⋯　⋯⋯\n"
	.string "ちょっと　ィイはなしが\l"
	.string "あるから　きいてけよ！\p"
	.string "じつは　おれたち　グループはな\n"
	.string "バトルフロンティアの　なかで\l"
	.string "ちょっとした　ゲームを　してんのよ⋯⋯\p"
	.string "ルールは　かんたん　だぜー\n"
	.string "まずは　まいかい　どこかの　しせつを\l"
	.string "ひとつ　えらぶ！\p"
	.string "つぎに　そこに　ちょうせん　してる\n"
	.string "トレーナーの　だれか　ひとりを　えらんで\l"
	.string "じぶんの　バトルポイントを　かけるのよ！\p"
	.string "んで　いちばん　いい　せいせきを\n"
	.string "だした　トレーナーに　かけてた　やつが\l"
	.string "バトルポイントを　ひとりじめ　すんの！\p"
	.string "なあっ？　かんたん　だろ？\n"
	.string "んで⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルタワーの　シングル　バトルルームに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルタワーの　ダブル　バトルルームに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルタワーの　マルチ　バトルルームに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルドームで　やってる\l"
	.string "シングル　バトルトーナメントに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルドームで　やってる\l"
	.string "ダブル　バトルトーナメントに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルファクトリーで　やってる\l"
	.string "バトルトレード　シングルに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルファクトリーで　やってる\l"
	.string "バトルトレード　ダブルに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルパレスの\l"
	.string "シングル　バトルホールに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルパレスの\l"
	.string "ダブル　バトルホールに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルアリーナで　やってる\l"
	.string "かちぬきチームバトルに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルチューブで　やってる\l"
	.string "バトルゲームに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "ちょうど　いまは　よぉ\n"
	.string "バトルピラミッドで　やってる\l"
	.string "バトルアドベンチャーに\l"
	.string "ちょうせんする　トレーナーを\l"
	.string "さがしてん　だけどよ⋯⋯\p"
	.string "ピンとくる　トレーナーが　いなくてなぁ⋯⋯\n"
	.string "なぁ⋯⋯$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "あんたにも　もうけさせて　やるからよぅー\n"
	.string "サクっと　ちょうせん　してきて　くんねぇ？$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "じゃあよ⋯⋯　あんたの\n"
	.string "バトルポイント　ちょーっとで　いいから\l"
	.string "おれに　あずけて　くんねぇ？\p"
	.string "ちゃーんと　おれいは　するからよ！$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "ィイね！　ィイね！\n"
	.string "で？　で？　で？　いくら　かして　くれます？$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "いやいやいやー！！\p"
	.string "バトルポイントが　たらない　じゃない！\n"
	.string "つまんない　じょうだん　やめましょうや！$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "へっへっへっ⋯⋯　あんがとよ！\n"
	.string "そんじゃー$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "サクサクッと\n"
	.string "バトルタワーの　シングル　バトルルームに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "サクサクッと\n"
	.string "バトルタワーの　ダブル　バトルルームに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "サクサクッと\n"
	.string "バトルタワーの　マルチ　バトルルームに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "サクサクッと　バトルドームの\n"
	.string "シングル　バトルトーナメントに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "サクサクッと　バトルドームの\n"
	.string "ダブル　バトルトーナメントに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "サクサクッと　バトルファクトリーの\n"
	.string "バトルトレード　シングルに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "サクサクッと　バトルファクトリーの\n"
	.string "バトルトレード　ダブルに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "サクサクッと　バトルパレスの\n"
	.string "シングル　バトルホールに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "サクサクッと　バトルパレスの\n"
	.string "ダブル　バトルホールに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "サクサクッと　バトルアリーナの\n"
	.string "かちぬきチームバトルに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "サクサクッと　バトルチューブの\n"
	.string "バトルゲームに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "サクサクッと　バトルピラミッドの\n"
	.string "バトルアドベンチャーに\l"
	.string "いってきて　ちょーだいっ！\p"
	.string "がんばれ　よぉー！\n"
	.string "まちがえんな　よぉー！\l"
	.string "おれと　あんたの　みらいの　ためだかんな！$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "あぁ　あんた⋯⋯　ごくろう　さん⋯⋯\p"
	.string "わりーけど　バトルポイントは\n"
	.string "かえせねぇよ⋯⋯\p"
	.string "⋯⋯　まぁ　おたがい　つぎの　きかいに\n"
	.string "がんばり　ましょうや⋯⋯$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "ぃよおっ！！　せんせい！！\p"
	.string "さすが！　さすが　ですねぇー！！\n"
	.string "わたくし　おおもうけで　ございますよぉ！\p"
	.string "バトルポイント　おかえし　しますよっ！\n"
	.string "しっかり　のしつけて　さしあげますよぉ！$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER}は　バトルポイントを\n"
	.string "{STR_VAR_1}BP　てにいれた！$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "また　なんか　あったら\n"
	.string "よろしく　たのみますよっ！！$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "そりゃ　ないぜー！\n"
	.string "せちがれぇ　おこさま　だなぁ！！$"

BattleFrontier_Lounge3_Text_Oh::
	.string "おっ⋯⋯$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "まーたー　はーずーれー？\p"
	.string "あたし　ふつうに\n"
	.string "たたかった　ほうが　いいの　かなぁー$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "あの　トレーナー⋯⋯　つよいけど\n"
	.string "バトルドームだと　すごく　きんちょう\l"
	.string "しちゃうん　だよなぁ⋯⋯$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "うふふっ！\n"
	.string "ボロもうけ！　ボロもうけなのよ！$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "あいつら　トレーナーの　くせに\n"
	.string "ちょうせんも　しないで\l"
	.string "なに　してるん　だろうな？$"
