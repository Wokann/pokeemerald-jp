@ LilycoveCity_LilycoveMuseum_1F scripts (JP map g13 m2 @ 0x08205BE2)

LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter:: @ 0x08205BE3
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator:: @ 0x08205BEC
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet:: @ 0x08205C16
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings:: @ 0x08205C1F
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested:: @ 0x08205C3E
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings:: @ 0x08205C48
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth:: @ 0x08205C84
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest:: @ 0x08205C99
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast:: @ 0x08205CAE
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting:: @ 0x08205CCE
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting:: @ 0x08205CD7
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting:: @ 0x08205CE0
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting:: @ 0x08205CE9
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting:: @ 0x08205CF2
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting:: @ 0x08205CFB
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture:: @ 0x08205D04
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture:: @ 0x08205D0D
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet:: @ 0x08205D16
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM:: @ 0x08205D1F
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1:: @ 0x08205D28
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy:: @ 0x08205D31
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1:: @ 0x08205D3A
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2:: @ 0x08205D43
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM:: @ 0x08205D4C
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2:: @ 0x08205D55
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan:: @ 0x08205D6C
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum: @ 0x08205D75
	.string "ミナモ　びじゅつかん　へ　ようこそ！\p"
	.string "ポケモンたちを　えがいた\n"
	.string "すばらしい　めいがの　かずかずを\l"
	.string "ゆっくり　ごらんに　なって　くださいね！$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings: @ 0x08205DBB
	.string "わたしは　この　びじゅつかんの\n"
	.string "かんちょう　です！\p"
	.string "あなたは　おわかいのに　びじゅつかんに\n"
	.string "いらっしゃる　とは　かんしん　ですね！\p"
	.string "もう　えは　ごらんに　なりましたか？$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime: @ 0x08205E10
	.string "では　おじゃま　いたしません　から\n"
	.string "ゆっくり　みていって　ください！$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings: @ 0x08205E33
	.string "おや？　あなたは\n"
	.string "ポケモントレーナーさん　みたい　ですね\p"
	.string "えにも　きょうみが　おあり　ですか？$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat: @ 0x08205E63
	.string "そうですか⋯⋯\p"
	.string "それなのに　わざわざ　おいで　くださって\n"
	.string "こうえい　ですよ$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe: @ 0x08205E89
	.string "そうですか！　えが　おすき　ですか！\p"
	.string "では　ちょっと　わたしに\n"
	.string "ついてきて　ください　ませんか？$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting: @ 0x08205EBA
	.string "むかしの　ひとが　かいた　えだ！\n"
	.string "ところどころ　えのぐが　はがれてる$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery: @ 0x08205EDD
	.string "みたことも　ないような　ふしぎな\n"
	.string "けしきが　えがかれている$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman: @ 0x08205EFB
	.string "ひざに　ポケモンを　のせて　ほほえむ\n"
	.string "うつくしい　じょせいが　えがかれている$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon: @ 0x08205F22
	.string "むかしの　ひとが　そうぞうで　かいた\n"
	.string "でんせつの　ポケモンの　えだ！$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon: @ 0x08205F45
	.string "かぜに　なびいて　きもち　よさそうに\n"
	.string "ゆれている　くさポケモンが　えがかれている$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries: @ 0x08205F6E
	.string "おいしそうな　きのみが　えがかれている\n"
	.string "おなかが　すいて　きそう！$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica: @ 0x08205F90
	.string "こだいの　とりポケモンを　ほった\n"
	.string "ゆうめいな　ちょうこくの　レプリカだ！$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone: @ 0x08205FB5
	.string "くろい　いしで　つくられた\n"
	.string "おおきい　モンスターボールだ！\l"
	.string "むかし　おまつりに　つかって　いたらしい$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText: @ 0x08205FE8
	.string "ポケモンの　すがたと　しらない　もじが\n"
	.string "こまかく　ほられてある　せきばんだ！$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence: @ 0x0820600F
	.string "うーん　すばらしい　さくひんだ⋯⋯$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts: @ 0x08206021
	.string "ポケモン　しょうぶも　いいけど\p"
	.string "げいじゅつを　あいする　きもちも\n"
	.string "わすれずに　いないとね！$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration: @ 0x0820604F
	.string "この　びじゅつかんは\n"
	.string "すごい　えが　たくさん　みられるし\l"
	.string "かんちょうも　すばらしい　ひとだし\l"
	.string "ぼくたち　がかの　あいだ　でも\l"
	.string "あこがれの　ばしょ　なんだよ$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty: @ 0x0820609D
	.string "この　おんなの　ひと　きれーい！\n"
	.string "ママみたーい！$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable: @ 0x082060B6
	.string "この　ポケモン　かわいいわ！\n"
	.string "うちの　ぼうや　みたい！$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings: @ 0x082060D2
	.string "この　びじゅつかんに　あたらしい　えが\n"
	.string "はいったって　きいたから\l"
	.string "さっそく　みにきて　みたの！\p"
	.string "あたらしい　えは　2かい　かな？$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful: @ 0x08206113
	.string "さいきん　かんちょうの　ごきげんが\n"
	.string "とても　いいみたい\p"
	.string "いいこと　あったんだね　きっと$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings: @ 0x0820613F
	.string "ここで　いい　えを　たくさん　みて\n"
	.string "べんきょう　しないとな！\p"
	.string "ここに　いつか　じぶんの　さくひんを\n"
	.string "かざって　もらうのが　ゆめ　なんだ！$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination: @ 0x08206184
	.string "この　びじゅつかんも　すっかり　ミナモの\n"
	.string "⋯⋯いや　ホウエンちほうの\l"
	.string "かんこう　めいしょに　なったねえ！\p"
	.string "きいた　はなしだと\n"
	.string "ひとりの　トレーナーが　2かいの　えを\l"
	.string "そろえて　くれた　らしいよ！$"
