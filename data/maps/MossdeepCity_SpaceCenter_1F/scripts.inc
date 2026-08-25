@ MossdeepCity_SpaceCenter_1F scripts (JP map g14 m9 @ 0x0820CD5D)

MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:: @ 0x0820CD68
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma:: @ 0x0820CD74
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SAILOR, 0x1, 0x9
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_WOMAN, 0x0, 0x8
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_OLD_MAN, 0x1, 0x6
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 0x3, 0x4
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 0x1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 0x3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft:: @ 0x0820CDC6
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 0xC, 0x2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown:: @ 0x0820CDCE
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 0xD, 0x3
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight:: @ 0x0820CDD6
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 0xE, 0x2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:: @ 0x0820CDDE
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote:: @ 0x0820CDEA
	setmetatile 0x2, 0x5, METATILE_Facility_DataPad, TRUE
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter:: @ 0x0820CDF4
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet:: @ 0x0820CE2E
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber:: @ 0x0820CE37
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma:: @ 0x0820CE40
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma:: @ 0x0820CE6D
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma:: @ 0x0820CE76
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist:: @ 0x0820CE7F
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma:: @ 0x0820CE96
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan:: @ 0x0820CEAA
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone:: @ 0x0820CEEC
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma:: @ 0x0820CEF6
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma:: @ 0x0820CF35
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman:: @ 0x0820CF49
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal:: @ 0x0820CF70
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma:: @ 0x0820CF7A
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan:: @ 0x0820CF84
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal:: @ 0x0820CFAB
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma:: @ 0x0820CFC0
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven:: @ 0x0820CFD5
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote:: @ 0x0820CFEB
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3:: @ 0x0820CFF6
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1:: @ 0x0820D00D
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4:: @ 0x0820D024
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2:: @ 0x0820D03B
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 0x2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated:: @ 0x0820D08A
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest:: @ 0x0820D094
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 0x1
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast:: @ 0x0820D0A5
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 0x3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent: @ 0x0820D0C3
	.string "もうすぐ　ロケットが　はっしゃ　するぞ！$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber: @ 0x0820D0D8
	.string "ロケットが　はっしゃ　したよ！\n"
	.string "これで　{STR_VAR_1}かい　うちあげ　せいこうだ！$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent: @ 0x0820D0FD
	.string "こんな　さわぎの　とちゅう　だけど⋯⋯\p"
	.string "もうすぐ　ロケットが　はっしゃ　するぞ！$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber: @ 0x0820D126
	.string "こんな　さわぎの　とちゅう　だけど⋯⋯\p"
	.string "ロケットが　はっしゃ　したよ！\n"
	.string "これで　{STR_VAR_1}かい　うちあげ　せいこうだ！$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection: @ 0x0820D15F
	.string "ロケットを　はっしゃ　するには\n"
	.string "1パーセントの　ミスも　ゆるされない\p"
	.string "99パーセント　だいじょうぶ　でも\n"
	.string "1パーセント　ダメなら\l"
	.string "すべてが　ダメになる　きびしい　ものだ\p"
	.string "それでも　やりとげようと　するのは\n"
	.string "そこに　ロマンが　つまっている　からだな$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter: @ 0x0820D1DB
	.string "マグマだんの　やつらが\n"
	.string "この　うちゅうセンターを　ねらっている\p"
	.string "だが　そんなこと　ぐらいで\n"
	.string "ロケットの　はっしゃを\l"
	.string "やめるわけには　いかないんだ！$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt: @ 0x0820D225
	.string "かいがんを　さんぽ　していて\n"
	.string "これを　みつけたんだけど\l"
	.string "ぼくは　いらないから　きみに　あげる！$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers: @ 0x0820D255
	.string "むかしから　ホウエンちほうは\n"
	.string "いんせきの　おおい　ばしょ　として\l"
	.string "ゆうめい　なんだよね$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis: @ 0x0820D281
	.string "マグマだんに　ロケットねんりょうを\n"
	.string "うばわれる　わけには　いかない！\p"
	.string "でも　かいがんで　みつけた　このいしは\n"
	.string "きみに　あげるよ！$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma: @ 0x0820D2C2
	.string "マグマだんを　おっぱらわなきゃ\n"
	.string "かいがんの　さんぽ　どころじゃないね！$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace: @ 0x0820D2E6
	.string "ひとに　よっては\n"
	.string "ポケモンは　うちゅうから　やってきた！\l"
	.string "って　いうよね！　ほんとう　かなー？$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma: @ 0x0820D316
	.string "マグマだん　なんて\n"
	.string "アクアだんが　やっつければ　いいのよ！\p"
	.string "でも　そうすると　こんどは\n"
	.string "アクアだんが　おおきなかおを　するのよね$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind: @ 0x0820D357
	.string "でっかい　てつの　かたまりが\n"
	.string "おおぞらを　つきぬけ\l"
	.string "うちゅうまで　とんで　いく⋯⋯\p"
	.string "たまげた　もん　だわい$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream: @ 0x0820D38D
	.string "でっかい　てつの　かたまりが\n"
	.string "おおぞらを　つきぬけ\l"
	.string "うちゅうまで　とんで　いく⋯⋯\p"
	.string "そんな　わしのゆめを　ジャマする\n"
	.string "マグマだんめ！　ぬぬぬ　ゆるさん！$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel: @ 0x0820D3DA
	.string "ダイゴ“{PLAYER}{KUN}　そこにある\n"
	.string "よこくじょうは　もう　よんだかい？\p"
	.string "マグマだんは　このしまに　ある\n"
	.string "ロケットねんりょうを　ねらっている！\p"
	.string "なにに　つかうのか　しらないけど\n"
	.string "かれらに　わたす　わけには　いかないよ！\p"
	.string "ボクは　もうすこし　ここで\n"
	.string "みはって　いるから　きみは　まちでも\l"
	.string "けんぶつ　してきたら　どうかな$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro: @ 0x0820D475
	.string "やくそく　どおり　ロケットねんりょうを\n"
	.string "ちょうだいしに　きたわよ！$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat: @ 0x0820D497
	.string "ねんりょうぎれ⋯⋯$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle: @ 0x0820D4A1
	.string "わたしに　かった　ぐらいで\n"
	.string "ちょうしに　のってちゃ　ダメよ！$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro: @ 0x0820D4C0
	.string "ちゃんと　よこく　してから　きたんだ！\n"
	.string "オレたちゃ　ひきょうものじゃ　ないぜ！$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat: @ 0x0820D4E8
	.string "うーむ⋯⋯　ひきょうな　てを\n"
	.string "つかえば　よかった⋯⋯$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle: @ 0x0820D503
	.string "わかったよ　こんど　くるときは\n"
	.string "いきなり　くるように　するよ⋯⋯$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro: @ 0x0820D524
	.string "うちゅうセンターに　ちょぞう　してある\n"
	.string "ロケットの　ねんりょうは\l"
	.string "ぜんぶ　オレたちが　いただいて　いくぜ！$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat: @ 0x0820D55A
	.string "コップいっぱいで　いいから\n"
	.string "ねんりょう　くれない？$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle: @ 0x0820D574
	.string "ねんりょうの　つかいみち？\n"
	.string "そんなこと　オレは　しらん！\l"
	.string "2かいに　いる　リーダーに　きいてくれ！$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro: @ 0x0820D5A6
	.string "リーダーから　だれも　ここを　とおすな\n"
	.string "って　いわれてるんだよ！$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat: @ 0x0820D5C7
	.string "あっ　あっ　あっ$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle: @ 0x0820D5D0
	.string "リーダーには　オレが　さいごまで\n"
	.string "もちばを　はなれなかった　って\l"
	.string "いっといて　くれよ！$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice: @ 0x0820D5FC
	.string "これは⋯⋯\n"
	.string "はんこう　よこくじょう？\p"
	.string "‘うちゅうセンターの　みなさん\n"
	.string "　いかが　おすごしで　しょうか\p"
	.string "　ロケットの　ねんりょうは\n"
	.string "　まもなく　われわれが　いただきます\l"
	.string "　イヤだと　いっても　ムダなのでーす\p"
	.string "　もっと　りくちを！\n"
	.string "　　　　　　　　　　　　　　マグマだん$"
