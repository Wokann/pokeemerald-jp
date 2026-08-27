BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call 0x082432D3
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "ここは　バトルドーム！\n"
	.string "めざせ！　むてきの　スーパースター！$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "ここは　バトルファクトリー！\n"
	.string "さがせ！　さいきょう　ポケモン！$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "ここは　バトルチューブ！\n"
	.string "えらべ！　3つの　みち！$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "ここは　バトルタワー　さ！\p"
	.string "トレーナーは　きたえあげた　ポケモンで\n"
	.string "ひたすら　かちぬいて　いくのさ！$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "れんらくせんを　ごりよう　ですね！\n"
	.string "チケットは　おもち　でしょうか？$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER}は\n"
	.string "チケットを　もっていない！\p"
	.string "⋯⋯もうしわけ　ありません！\p"
	.string "ふねに　のれるのは\n"
	.string "チケットの　ある　かた　だけです$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER}は\n"
	.string "ふねのチケットを　みせた！\p"
	.string "はい！　けっこう　です！\p"
	.string "いきさきは　どちら　でしょう？$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "カイナシティ　ですね！$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "ミナモシティ　ですね！$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "また　ごりよう　ください！$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "れんらくせんに　のって　おまちください$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "いきさきは　どちら　でしょう？$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "ぼく　ともだちの　なかでは\n"
	.string "いちばん　つよいのに\l"
	.string "ここに　きてみたら　てんで　ダメ！$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "バトルタワーに　いきたいのに\n"
	.string "フロンティアパスの　マップを　みても\l"
	.string "なにが　なんだか⋯⋯　ひろすぎる⋯⋯$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "すぐに　チャレンジ　したいのに\n"
	.string "くる　とちゅうで　ふなよい　して　しまった\p"
	.string "うっぷ⋯⋯$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "ここには　だれでも\n"
	.string "こられるって　わけじゃ　ないんだぜ\p"
	.string "つよさを　みとめられた　トレーナーが\n"
	.string "つれてきて　もらえる　ところなんだ！\p"
	.string "だから⋯⋯　バトルフロンティアの　ことを\n"
	.string "しらない　トレーナーも　おおいんだ$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "なぁなぁ　にいちゃん⋯⋯\p"
	.string "ほんとに　じぶんの　ポケモン　いなくても\n"
	.string "ちょうせん　できるの？　だいじょうぶ？$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "だ　だいじょうぶ　だよ！\p"
	.string "きっと⋯⋯\p"
	.string "なんだか　おっかない　おっさん　だったけど\n"
	.string "‘ポケモン　かして　やるぜ！’　って\l"
	.string "いってた　じゃん　か⋯⋯$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "あそこに　あるのが　バトルファクトリー\n"
	.string "つよいポケモンを　レンタル　できるんだ！\p"
	.string "でもさ　レンタル　ポケモンって\n"
	.string "いったい　だれが　そだてて　いるんだろう？$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "ハブネークが　こわくて\n"
	.string "バトルチューブに　はいれないの⋯⋯\p"
	.string "で　でも　せっかく　きたんだから\n"
	.string "がんばって　せいは　するわ⋯⋯！　ブルブル$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "ね！　わたしと　ジャンケンしよ！\n"
	.string "じゃーん　けーん　ぽん！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "わーい　かっちゃった！\n"
	.string "よし　バトルチューブに　ちょうせん　しよ！$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "あーあ　まけちゃったあ⋯⋯\p"
	.string "いまは　うんが　わるいみたい\n"
	.string "バトルチューブは　また　あしたにしよ$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "この　かいわいで　なぜか　つりを\n"
	.string "たのしもうと　して　いるのは\l"
	.string "おれ　くらいの　ものだろうな！\p"
	.string "⋯⋯　え　なんにも　つれないの？\n"
	.string "がっ　かり$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "きょうは　シンボルを　もらえる　までは\n"
	.string "ぜったいに　あきらめないで　がんばろっと！$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "おや⋯⋯　バトルドームに\n"
	.string "ちょうせん　されますか？\p"
	.string "では　おたがい　かちあがって\n"
	.string "おあい　できるように　がんばりましょう$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "ほら　じいちゃん　こっち　こっち！\n"
	.string "ここが　バトルドームよっ！　がんばって！$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "ほほおぉ　ここが　バトルドームか⋯⋯\n"
	.string "よし　ジェントルマンには　まけんぞ！\p"
	.string "⋯⋯で　いりぐちは　どこ　なんじゃろ？$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "ちょっと　まえ　までは\n"
	.string "なんも　なかった　とち　なのに⋯⋯\p"
	.string "すっげー　ところに　なっちゃったなあ！\n"
	.string "こんど　かーちゃんも　つれて　きてやるか$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "とうとう　バトルフロンティアに　きたわ！\p"
	.string "みんな　あたしの　つよさと　うつくしさに\n"
	.string "くぎづけに　なるわね！$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "もぐ　もぐ\p"
	.string "この　ひろば　には\n"
	.string "つよいひと　いっぱい　らしいねえ\l"
	.string "もぐ　もぐ$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "ぱく　ぱく\p"
	.string "このまえ　バトルチューブで\n"
	.string "めつきが　わるくて　こわそうな\l"
	.string "おねえさんに　あったんだよ\l"
	.string "ぱく　ぱく\p"
	.string "そしたら　‘いつまで　くってるの！’って\n"
	.string "おこられて　ボコボコに　やられちったよ\p"
	.string "いやあ　こわかったなー\p"
	.string "ぱく　ぱく$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "はあっ！？\n"
	.string "あなた　なに　いって　くれちゃってるの？\p"
	.string "わたし　なんか\n"
	.string "こないだ　おうえん　してたら\l"
	.string "ばーーーっちり　めが　あったんだからっ！$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "なんだとぉー！？\p"
	.string "それは　となりに　ぼくが\n"
	.string "いたから　でしょっ！\p"
	.string "あのひとは　ぼくの　おうえんを\n"
	.string "きいて　ふりむいて　くれたんだ　っつーの！$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "ああ　うるさいっ！　うるさいわっ！\p"
	.string "おみゃーら　みたいな　おこさまは\n"
	.string "どこぞの　ジムリーダーでも\l"
	.string "おうえん　しとけっ！！\p"
	.string "ドームスーパースターは　わしだけっ！\n"
	.string "わしだけの　アイドルなのっ！！$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "あそこで　けんか　してる　ひとたち⋯⋯\p"
	.string "あれでも　もともとは　すごく　つよくて\n"
	.string "ゆうめいな　トレーナー　だったんだよ\p"
	.string "だけど　バトルトーナメントで\n"
	.string "あるトレーナーに　ボコボコに　まけてから\l"
	.string "みんな　そのトレーナーの\l"
	.string "だいファンに　なっちゃったんだ\p"
	.string "いまじゃ　まいにち　ちょうせんも　しないで\n"
	.string "バトルドームに　おうえんに　かよってるよ$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "バトルフロンティアの　どっかで\n"
	.string "えらく　しっぽの　ながーい　ポケモンを\l"
	.string "みたって　きいたわー！\p"
	.string "ああ　かわいい　ポケモンに　ちがいない⋯⋯\p"
	.string "もうー　ちょうせん　よりも\n"
	.string "そのこ　さがしに　いきたいわぁー$"
