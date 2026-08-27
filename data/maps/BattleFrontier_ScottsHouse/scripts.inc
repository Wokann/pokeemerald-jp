BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "エニシダ“ああ　いらっしゃい\n"
	.string "へへ⋯⋯　せまい　ところで　ごめんよ\p"
	.string "では　あらためて　{PLAYER}{KUN}\n"
	.string "ようこそ　バトルフロンティアへ！\p"
	.string "ここは　わたしの　ゆめの　けっしょう！\n"
	.string "なんねんも　かかって　やっと\l"
	.string "かたちに　することが　できたんだ！$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "おもえば　ながい　みちのりだった⋯⋯\n"
	.string "つよい　トレーナーを　もとめて\l"
	.string "ただひとり　たびだち⋯⋯\l"
	.string "ここまで　くるのに　どれだけの\l"
	.string "どりょくと　じかんが　ひつようだったか⋯⋯$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "いや　こんな　むかしばなしを\n"
	.string "していても　はじまらないな！\p"
	.string "とにかく　こころ　ゆくまで\n"
	.string "ポケモンしょうぶを　たのしんで　くれ！\p"
	.string "これは　わたしと　{PLAYER}{KUN}が\n"
	.string "なんども　たびさきで　であった\l"
	.string "きねんだよ！$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER}は　バトルポイントを\n"
	.string "{STR_VAR_1}　BP　もらった！$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "エニシダ“バトルポイントは\n"
	.string "フロンティアパスで　みられるからね！\l"
	.string "ポイントは　この　フロンティアで\l"
	.string "かつやく　すれば　するほど\l"
	.string "たまっていく　ものなんだ！\p"
	.string "ほしい　ものと　ひきかえたり\n"
	.string "すきなように　かつようして　くれ！$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "きみの　かつやく\n"
	.string "おおいに　きたい　しているからね！$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "エニシダ“どの　トレーナーにも\n"
	.string "それぞれの　じんせいが　あるだろ？\p"
	.string "でも　たたかう　ときは\n"
	.string "そんなこと　ぜんぜん　かんけいない\l"
	.string "みんな　いっしょ　なんだよね！\p"
	.string "わたしは　そういう\n"
	.string "たたかいの　じゅんすいさ　ってのが\l"
	.string "とても　すきなんだよ\p"
	.string "だから　いろんな　ところに　でかけて\n"
	.string "しんけんに　たたかってる　トレーナーを\l"
	.string "いっぱい　しょうたい　してくるのさ！$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "エニシダ“わが　ブレーンたち　から\n"
	.string "フロンティアパスの　シンボルは\l"
	.string "もう　もらったかな？\p"
	.string "わたしが　みいだした\n"
	.string "さいきょうの　フロンティアブレーンも\l"
	.string "きみの　つよさを　みたら\l"
	.string "おそらく　おどろく　だろうね！$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "エニシダ“きみは　たしか\n"
	.string "しょうぶ　だけでは　なくて\l"
	.string "ポケモンずかんも　つくって　いたね！\p"
	.string "もしかしたら　バトルフロンティア　にも\n"
	.string "ポケモンと　であえる　ばしょが\l"
	.string "あるかも　しれないよ？　うふふ⋯⋯$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "エニシダ“バトルフロンティアを\n"
	.string "たのしんで　くれて　いるかな？\p"
	.string "⋯⋯って　おおっっ！\p"
	.string "きみの　フロンティアパスっ！\n"
	.string "ぎんのシンボルが　すべて\l"
	.string "そろって　いるじゃ　ないか！\p"
	.string "すごいなあ　きみは　おもったとおり\n"
	.string "つよい　トレーナー　だったんだなあ！\p"
	.string "ふつうは　こんな　ことは　しないんだが\n"
	.string "ぜひ　きねんに　これを　もらってくれ！\l"
	.string "きみなら　つかいこなせる　はずだよ⋯⋯！$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "エニシダ“バトルフロンティアは\n"
	.string "まんきつ　してるかな？\p"
	.string "⋯⋯って　うひょおおっっ！\p"
	.string "きみの　フロンティアパスーっ！\n"
	.string "きんのシンボルが　すべて\l"
	.string "そろって　いるじゃ　ないか！\p"
	.string "これはすごいっ！\n"
	.string "やっぱり　きみは　おもったとおり\l"
	.string "すごい　トレーナー　だったんだなあ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "{PLAYER}{KUN}！　ぜひ　きみに\n"
	.string "これを　プレゼント　させて　くれ！\p"
	.string "きみならば　これの　かちを\n"
	.string "わかって　くれると　おもうんだ！$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "いやー　われながら\n"
	.string "トレーナーを　みるめが　さえてるなー\l"
	.string "きみを　つれてきて　ほんと　よかった！\l"
	.string "ほく　ほく$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "きのみポケットが　いっぱい　みたいね$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "エニシダ“おっ　きいたよ！\n"
	.string "バトルタワーでの　かつやく！\l"
	.string "50にん　いじょう　かちぬいたって？\p"
	.string "すごいなあ　きねんに\n"
	.string "これを　うけとって　くれよ！$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "エニシダ“おおうっ　きいたよ！\n"
	.string "バトルタワーでの　だいかつやく！\l"
	.string "100にん　いじょう　かちぬいたって？\p"
	.string "すごすぎるなー！\n"
	.string "ぜひ　これを　きねんに　うけとってくれ！$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "これからも　ますます\n"
	.string "きたい　しているよ！$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "⋯⋯って　にもつが　いっぱいなら\n"
	.string "とって　おくから　またおいで！$"
