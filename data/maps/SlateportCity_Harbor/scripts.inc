@ SlateportCity_Harbor scripts (JP map g9 m9 @ 0x081FDC6E)

SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition: @ 0x081FDC74
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal:: @ 0x081FDC96
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene:: @ 0x081FDC9A
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0:: @ 0x081FDCAC
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1:: @ 0x081FDCB8
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2:: @ 0x081FDCC4
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3:: @ 0x081FDCD0
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene:: @ 0x081FDCE6
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	moveobjectoffscreen LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0:: @ 0x081FDD7A
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1:: @ 0x081FDD8F
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer:: @ 0x081FDDA4
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant:: @ 0x081FDDE2
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket:: @ 0x081FDDF7
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination:: @ 0x081FDE0B
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier:: @ 0x081FDE41
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_NoTicket:: @ 0x081FDE79
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove:: @ 0x081FDE83
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier:: @ 0x081FDEAB
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination:: @ 0x081FDECE
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry:: @ 0x081FDEDA
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect:: @ 0x081FDF1E
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast:: @ 0x081FDF28
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth:: @ 0x081FDF33
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor:: @ 0x081FDF43
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather:: @ 0x081FDF7A
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary:: @ 0x081FDF84
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan:: @ 0x081FDF8A
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern:: @ 0x081FDF93
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine:: @ 0x081FDFD0
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive:: @ 0x081FDFDA
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive:: @ 0x081FDFE7
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment:: @ 0x081FDFF1
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished:: @ 0x081FE01F
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner:: @ 0x081FE029
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade:: @ 0x081FE035
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth:: @ 0x081FE06C
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale:: @ 0x081FE0AC
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade:: @ 0x081FE0EC
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade:: @ 0x081FE0F6
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner:: @ 0x081FE102
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable: @ 0x081FE111
	.string "えっ？　ふね　ですか？\p"
	.string "もうしわけ　ございません　げんざい\n"
	.string "れんらくせんは　ないんです⋯⋯$"

SlateportCity_Harbor_Text_MayISeeYourTicket: @ 0x081FE13F
	.string "れんらくせんを　ごりよう　ですね！\n"
	.string "チケットは　おもち　でしょうか？$"

SlateportCity_Harbor_Text_YouMustHaveTicket: @ 0x081FE162
	.string "{PLAYER}は\n"
	.string "チケットを　もっていない！\p"
	.string "⋯⋯もうしわけ　ありません！\p"
	.string "ふねに　のれるのは\n"
	.string "チケットの　ある　かた　だけです$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo: @ 0x081FE19E
	.string "{PLAYER}は\n"
	.string "ふねのチケットを　みせた！\p"
	.string "はい！　けっこう　です！\p"
	.string "いきさきは　どちら　でしょう？$"

SlateportCity_Harbor_Text_SailAnotherTime: @ 0x081FE1CD
	.string "また　ごりよう　ください！$"

SlateportCity_Harbor_Text_LilycoveItIs: @ 0x081FE1DB
	.string "ミナモシティ　ですね！$"

SlateportCity_Harbor_Text_BattleFrontierItIs: @ 0x081FE1E7
	.string "バトルフロンティア　ですね！$"

SlateportCity_Harbor_Text_PleaseBoardFerry: @ 0x081FE1F6
	.string "れんらくせんに　のって　おまちください$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo: @ 0x081FE20A
	.string "いきさきは　どちら　でしょう？$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday: @ 0x081FE21A
	.string "うみの　そこ　かあ⋯⋯\n"
	.string "いったい　どんなふう　なのかな？\p"
	.string "おれも　いつか　もぐってみたいぜ！$"

SlateportCity_Harbor_Text_AbnormalWeather: @ 0x081FE249
	.string "ふねを　あんぜんに　すすめる　ためには\n"
	.string "てんきを　りかいする　ひつようが　ある！\p"
	.string "そういえば　てんきけんきゅうじょの\n"
	.string "ひとが　いってたけど\p"
	.string "さいきん　かくちで　いじょうきしょうが\n"
	.string "かんそく　されている　らしいな！\p"
	.string "きみも　けんきゅうじょに　いって\n"
	.string "はなしを　きいてみると　いいぞ！$"

SlateportCity_Harbor_Text_SubTooSmallForMe: @ 0x081FE2D6
	.string "ぼくも　クスノキ　かんちょうと　いっしょに\n"
	.string "かいてい　ちょうさに　いきたかった！\p"
	.string "でも　せんすいていの　なかは　せまいから\n"
	.string "ぼくが　のったら　かんちょうが\l"
	.string "のれなく　なっちゃうんだよね⋯⋯$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum: @ 0x081FE335
	.string "クスノキ“あいつらは⋯⋯\p"
	.string "いぜん　はくぶつかんで\n"
	.string "デボンのにもつを　うばおうと　していた⋯⋯$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove: @ 0x081FE364
	.string "アオギリ“おや？　また　きみか⋯⋯\p"
	.string "わざわざ　ここまで　おいかけて　くるとは\n"
	.string "ごくろうな　ことだな⋯⋯\p"
	.string "だが　もう　だれにも\n"
	.string "われわれを　とめられない\p"
	.string "とめられると　おもうなら\n"
	.string "ミナモの　アジトまで　くるかね？\l"
	.string "フフフ⋯⋯$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine: @ 0x081FE3D4
	.string "クスノキ“なぜ⋯⋯\p"
	.string "アクアだんの　れんちゅうが\n"
	.string "わたしの　せんすいてい\l"
	.string "‘かいえん　1ごう’を　うばうのだろう？\p"
	.string "まさか　かれらも\n"
	.string "かいていに　ねむる　ポケモンを⋯⋯\p"
	.string "だが　わたしが　おいかけても\n"
	.string "あんな　れんちゅうに　かてる　わけない⋯⋯$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive: @ 0x081FE44D
	.string "クスノキ“ああ　{PLAYER}{KUN}⋯⋯\p"
	.string "そうか⋯⋯　アクアだんは\n"
	.string "しゅっぱつ　して　しまったか⋯⋯\p"
	.string "いや　きにしなくて　いいよ\n"
	.string "きみの　せきにん　では　ないからね\p"
	.string "せんすいていを　おいかけるのは\n"
	.string "ふつうの　ひとには　むりな　はなし　だよ\p"
	.string "ポケモンに　ダイビング　といって\n"
	.string "うみに　もぐれる　わざを　おしえないと⋯⋯\p"
	.string "トクサネに　いけば\n"
	.string "ダイビングを　する　ひとが　おおいから\l"
	.string "おしえて　もらえるかも　しれないけどね$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub: @ 0x081FE518
	.string "クスノキ“せんすいていを　おいかけるのは\n"
	.string "ふつうの　ひとには　むりな　はなし　だよ\p"
	.string "ポケモンに　ダイビング　といって\n"
	.string "うみに　もぐれる　わざを　おしえないと⋯⋯\p"
	.string "トクサネに　いけば\n"
	.string "ダイビングを　する　ひとが　おおいから\l"
	.string "おしえて　もらえるかも　しれないけどね$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry: @ 0x081FE59B
	.string "クスノキ“そうだ！　ハギろうじんが\n"
	.string "ぞうせんじょに　きてくれたんだ！\p"
	.string "よーし！　これで　れんらくせんが\n"
	.string "かんせい　するのも　もうすぐ　だぞ！$"

SlateportCity_Harbor_Text_FinishedMakingFerry: @ 0x081FE5E2
	.string "クスノキ“{PLAYER}{KUN}！\p"
	.string "れんらくせん　タイドリップごうが\n"
	.string "ついに　かんせい　したんだ！\p"
	.string "きみの　しりあいの　ハギろうじんが\n"
	.string "てつだって　くれたからだよ\p"
	.string "ぜひ　のってみてよ！$"

SlateportCity_Harbor_Text_WouldYouTradeScanner: @ 0x081FE638
	.string "クスノキ“おや？\n"
	.string "{PLAYER}{KUN}が　もってる　それは⋯⋯\p"
	.string "たんちき　だね！\n"
	.string "それがあると　ちょうさが　はかどりそうだ\p"
	.string "{PLAYER}{KUN}！　ぼくの　もってる\n"
	.string "しんかいのキバか　しんかいのウロコと\l"
	.string "たんちきを　こうかん　してくれないかな？$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow: @ 0x081FE6A7
	.string "クスノキ“そうかい？\n"
	.string "{PLAYER}{KUN}が　もっていても\l"
	.string "つかいみちが　ないと　おもうけどな⋯⋯\p"
	.string "まあ　いいや\n"
	.string "たんちきを　こうかん　したくなったら\l"
	.string "また　はなしかけてよ！$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth: @ 0x081FE6F9
	.string "クスノキ“しんかいのキバが　いいんだね？$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale: @ 0x081FE70E
	.string "クスノキ“しんかいのウロコに　するんだね？$"

SlateportCity_Harbor_Text_WhichOneDoYouWant: @ 0x081FE724
	.string "クスノキ“どっちに　するんだい？$"

SlateportCity_Harbor_Text_HandedScannerToStern: @ 0x081FE735
	.string "{PLAYER}は　クスノキかんちょうに\n"
	.string "たんちきを　わたした！$"

SlateportCity_Harbor_Text_ThisWillHelpResearch: @ 0x081FE750
	.string "クスノキ“{PLAYER}{KUN}　ありがとう！\n"
	.string "これで　けんきゅうが　はかどるよ$"
