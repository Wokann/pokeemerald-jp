@ BattleFrontier_ReceptionGate scripts (JP map g26 m50 @ 0x0823A22C)

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:: @ 0x0823A237
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:: @ 0x0823A23B
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, FALSE, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering:: @ 0x0823A245
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, TRUE
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene:: @ 0x0823A27B
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter:: @ 0x0823A34E
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide:: @ 0x0823A362
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout:: @ 0x0823A372
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	goto_if_eq VAR_0x8000, 0x4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	goto_if_eq VAR_0x8000, 0x5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	goto_if_eq VAR_0x8000, 0x6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	goto_if_eq VAR_0x8000, 0x7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	goto_if_eq VAR_0x8000, 0x8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	goto_if_eq VAR_0x8000, 0x9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower:: @ 0x0823A400
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome:: @ 0x0823A40E
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace:: @ 0x0823A41C
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena:: @ 0x0823A42A
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory:: @ 0x0823A438
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike:: @ 0x0823A446
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid:: @ 0x0823A454
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall:: @ 0x0823A462
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner:: @ 0x0823A470
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide:: @ 0x0823A47E
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide:: @ 0x0823A488
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout:: @ 0x0823A498
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_ReceptionGate_EventScript_Level50
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	goto_if_eq VAR_0x8000, 0x4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	goto_if_eq VAR_0x8000, 0x5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode:: @ 0x0823A4F6
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50:: @ 0x0823A504
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel:: @ 0x0823A512
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry:: @ 0x0823A520
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems:: @ 0x0823A52E
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide:: @ 0x0823A53C
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide:: @ 0x0823A546
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout:: @ 0x0823A556
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_ReceptionGate_EventScript_Symbols
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols:: @ 0x0823A59E
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle:: @ 0x0823A5AC
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints:: @ 0x0823A5BA
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide:: @ 0x0823A5C8
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "はじめての　おきゃくさまですね！\n"
	.string "こちらへ　どうぞ！$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "ポケモンバトルの　さいぜんせん！\n"
	.string "バトルフロンティアへ　ようこそ！$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "はじめての　おきゃくさまには\n"
	.string "バトルフロンティアの　なかで\l"
	.string "ごりよう　いただける　フロンティアパスを\l"
	.string "はっこうして　おります！\p"
	.string "どうぞ　おうけとり　ください！$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER}は\n"
	.string "フロンティアパスを　もらった！$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER}は　トレーナーカードを\n"
	.string "フロンティアパスに　いれかえた！$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "それでは　バトルフロンティアを\n"
	.string "ぞんぶんに　おたのしみ　ください！$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "？？？“やあ　きて　くれたんだね\n"
	.string "{PLAYER}{KUN}！$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "うけつけ“あっ　エニシダさま！\n"
	.string "おつかれさまです！$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "エニシダ“きみが　きてくれて\n"
	.string "とっても　うれしいよ！\p"
	.string "ぜひ　ゆっくりと　そして　じっくりと\n"
	.string "ポケモンしょうぶの　しんずいを\l"
	.string "あじわって　いって　くれ！\p"
	.string "わたしの　へやも　あるから\n"
	.string "ひまが　あるときに　たずねて　きてくれよ！$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "こちらでは　バトルフロンティアに　ある\n"
	.string "さまざまな　しせつの\l"
	.string "ごあんないを　いたします！$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "どの　せつめいが　ききたいですか？$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "バトルフロンティアの　シンボル　とも\n"
	.string "いえる　きょだいな　とう　です\p"
	.string "こちらの　たてもの　では　シングル\n"
	.string "ダブル　マルチ　つうしんマルチの\l"
	.string "4つの　バトルルームで　たたかいを\l"
	.string "たのしむことが　できます！$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "バトルドームは　たまごの　ような\n"
	.string "かたちをした　おおきな　たてものです\p"
	.string "こちらでは　バトルトーナメント　という\n"
	.string "イベントが　かいさいされて　います\p"
	.string "なお　バトルトーナメントには\n"
	.string "シングルバトルよう　ダブルバトルようの\l"
	.string "2つの　コースが　あります！$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "バトルパレスは　バトルフロンティアの\n"
	.string "みぎはじに　ある　あかい　たてものです\p"
	.string "こちらの　たてもの　では\n"
	.string "シングル　ダブルの　2つの\l"
	.string "バトルホールへの　ちょうせんが　できます$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "バトルアリーナは　バトルフロンティアの\n"
	.string "ちゅうおう　みぎに　いちする\l"
	.string "どうじょうの　ような　たてものです\p"
	.string "こちらでは　かちぬきチームバトル　という\n"
	.string "イベントを　かいさい　しております！$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "バトルファクトリーは　ここをでて　いちばん\n"
	.string "ちかくにある　おおきな　ビルに　なります\p"
	.string "こちらでは　バトルトレード　という\n"
	.string "イベントを　かいさいして　おります\p"
	.string "なお　バトルトレードには\n"
	.string "シングルバトルよう　ダブルバトルようの\l"
	.string "2つの　コースが　ようい　されています！$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "バトルチューブは　バトルフロンティアの\n"
	.string "ちゅうおう　ひだりに　いちする\l"
	.string "ポケモンの　かたちを　した　たてものです\p"
	.string "こちらでは　バトルゲーム　という\n"
	.string "イベントを　かいさい　しております！$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "バトルピラミッドは　きょだいな\n"
	.string "ピラミッドの　かたちをした　たてものです\p"
	.string "こちらでは　バトルアドベンチャー　という\n"
	.string "イベントを　かいさい　しております！$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "ランキングホールは\n"
	.string "バトルタワーの　ちかくに　あります\p"
	.string "こちらは　バトルフロンティアで\n"
	.string "たたかった　トレーナーたちの\l"
	.string "もっとも　すばらしい　きろくを\l"
	.string "みることが　できます$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "ひきかえサービス　コーナーは\n"
	.string "バトルタワーの　ちかくに　あります\p"
	.string "こちらでは　バトルフロンティアの\n"
	.string "なかで　ためた　バトルポイントを\l"
	.string "すてきな　けいひんと\l"
	.string "こうかんする　ことが　できます！$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "こちらでは　バトルフロンティアに　ある\n"
	.string "すべての　しせつに　きょうつう　した\l"
	.string "ちょうせんの　ための　きほんてきな\l"
	.string "ルールを　せつめい　いたします！$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "どの　せつめいが　ききたいですか？$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "バトルフロンティアに　ある\n"
	.string "すべての　しせつの　ちょうせんは\l"
	.string "おおきく　レベル50の　コースと\l"
	.string "オープンレベルの　コースに　わかれています$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "レベル50の　コースでは　なまえの　とおり\n"
	.string "レベル50までの　ポケモンを\l"
	.string "ちょうせん　させることが　できます\p"
	.string "ただし　レベル50より　ひくい　レベルの\n"
	.string "ポケモンを　つれた　トレーナーが\l"
	.string "とうじょう　することは　ありません\l"
	.string "くれぐれも　ごちゅうい　ください\p"
	.string "なお　このコースが　バトルフロンティアの\n"
	.string "たたかいの　きほんと　なって　いますので\l"
	.string "ぜひ　チャレンジして　みてください$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "オープンレベルの　コースでは\n"
	.string "ちょうせんに　さんかする　ポケモンの\l"
	.string "レベルに　せいげんが　ありません\p"
	.string "あなたの　ポケモンの　レベルに　あわせて\n"
	.string "たいせんする　トレーナーの　ポケモンの\l"
	.string "レベルが　かわります\p"
	.string "ただし　レベル60より　ひくい　レベルの\n"
	.string "ポケモンを　つれた　トレーナーが\l"
	.string "とうじょう　することは　ありません$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "タマゴや　いちぶの　れいがいを\n"
	.string "のぞいて　ほとんどの　ポケモンが\l"
	.string "すべての　しせつに　ちょうせん　できます\p"
	.string "ちょうせんの　ために\n"
	.string "ひつような　ポケモンの　かずは\l"
	.string "しせつに　よって　ちがいます\p"
	.string "ただし　どの　しせつでも\n"
	.string "おなじ　しゅるいの　ポケモンを\l"
	.string "2ひき　いじょう　さんか　させることは\l"
	.string "できませんので　ごちゅうい　ください$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "バトルフロンティアの　しせつに\n"
	.string "ポケモンを　ちょうせん　させるとき\p"
	.string "それぞれの　ポケモンが\n"
	.string "おなじ　どうぐを　もつことは　できません\p"
	.string "ちょうせん　させる　ポケモンには\n"
	.string "すべて　ちがう　どうぐを\l"
	.string "もたせて　おくように　してください$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "こちらでは　フロンティアパスの\n"
	.string "せつめいを　いたします！$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "どの　せつめいが　ききたいですか？$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "バトルフロンティアの　7つの　しせつで\n"
	.string "つよさを　みとめられた　トレーナーが\l"
	.string "それぞれの　しせつの　シンボルを\l"
	.string "もらえることが　あります\p"
	.string "シンボルを　もらう　ためには\n"
	.string "なんにんも　トレーナーを　かちぬいたり\l"
	.string "なんども　せいは　したり⋯⋯\p"
	.string "なかなか　たいへんな　みちのりですが\n"
	.string "ぜひ　がんばって　くださいね！$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "あなたの　たいせんを　ひとつだけ\n"
	.string "パスに　きろくする　ことが　できます\p"
	.string "おともだち　との　たいせんか\n"
	.string "バトルチューブ　バトルピラミッド　いがいの\l"
	.string "バトルフロンティアでの\l"
	.string "たいせんが　きろくできます\p"
	.string "たいせんが　おわった　ときに\n"
	.string "きろく　するか　どうかを　きめられます$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "バトルポイントは\n"
	.string "バトルフロンティアで　すばらしい\l"
	.string "たたかいを　した　トレーナーに\l"
	.string "あたえられる　ごほうびです\p"
	.string "ためた　ポイントは　ひきかえサービスで\n"
	.string "しょうひんと　ひきかえることが　できます$"
