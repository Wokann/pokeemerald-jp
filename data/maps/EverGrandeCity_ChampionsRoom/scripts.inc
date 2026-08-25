@ EverGrandeCity_ChampionsRoom scripts (JP map g16 m4 @ 0x082108D0)

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:: @ 0x082108E0
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:: @ 0x082108E6
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth:: @ 0x082108F0
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:: @ 0x082108F5
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom:: @ 0x082108FF
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 0x28
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace:: @ 0x08210926
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated:: @ 0x08210942
	playse SE_DOOR
	setmetatile 0x6, 0x1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 0x6, 0x2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic:: @ 0x0821099D
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic:: @ 0x082109A2
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice:: @ 0x082109A7
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 0x28
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice:: @ 0x082109DC
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 0x28
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF:: @ 0x08210A11
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x14
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 0x1E
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 0x14
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 0x7, 0x10
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations:: @ 0x08210ACC
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations:: @ 0x08210AD5
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer:: @ 0x08210ADE
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth:: @ 0x08210AF3
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech: @ 0x08210B2D
	.string "ミクリ“ようこそ　{PLAYER}{KUN}\p"
	.string "ルネシティで　おこった　だいじけんを\n"
	.string "きみが　ひとりで　かいけつ　したのは\l"
	.string "なかなか　みごと　だったよ\p"
	.string "⋯⋯おっと！\p"
	.string "きみひとりの　ちからで\n"
	.string "かいけつ　したわけでは　なかったな\p"
	.string "きみと⋯⋯　きみの　ポケモンが\n"
	.string "ちからを　あわせたからこそ\l"
	.string "こんなんを　のりこえ　られたんだ\p"
	.string "わたしたち　トレーナーは\n"
	.string "いろんな　どうぐを　あたえたり\l"
	.string "いろんな　わざを　おしえたり　して\l"
	.string "ポケモンを　そだてている⋯⋯\p"
	.string "けれど　わたしたち　じしんも\n"
	.string "ポケモンから　たくさんの　ことを\l"
	.string "おしえられて　いるのさ\p"
	.string "そして　ここは⋯⋯\n"
	.string "その　せいかを　ぶつけあう　ばしょ\p"
	.string "さあ！\p"
	.string "ホウエンで　いちばん　かれいに\n"
	.string "ポケモンと　おどれるのは　だれなのか！\p"
	.string "いま　ここで　みせて　もらおう！$"

EverGrandeCity_ChampionsRoom_Text_Defeat: @ 0x08210C82
	.string "チャンピオンである\n"
	.string "わたしを　うちまかす　とは⋯⋯\p"
	.string "なんと　ワンダフル！\n"
	.string "にくらしいほど　エレガント！\l"
	.string "だけど　とっても　グロリアス！\p"
	.string "さすがだよ　{PLAYER}{KUN}！\p"
	.string "きみは　ほんとうに　すばらしい\n"
	.string "ポケモン　トレーナーだ！$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech: @ 0x08210CEF
	.string "ミクリ“きみが　くりだしてきた\n"
	.string "ポケモンの　かずかず⋯⋯\p"
	.string "ときに　はるかぜの　ように　まい\n"
	.string "あるいは　いなづまの　ように　さす\p"
	.string "そんな　ポケモンたちを\n"
	.string "かろやかに　あやつる　きみの　すがた\p"
	.string "この　わたしで　さえも\n"
	.string "ほれぼれ　するほど　だったよ！\p"
	.string "この　ポケモンリーグで\n"
	.string "みごと　ちょうてんに　たった　きみこそ\l"
	.string "ホウエンちほうの　あたらしい⋯⋯$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice: @ 0x08210D9B
	.string "ハルカ“{PLAYER}{KUN}！\p"
	.string "チャンピオンに　ちょうせん　するまえに\n"
	.string "アドバイス⋯⋯！$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver: @ 0x08210DC2
	.string "ハルカ“あれ？　あれれ？\p"
	.string "{PLAYER}{KUN}⋯⋯\n"
	.string "ひょっとして⋯⋯\l"
	.string "もう　おわっちゃった⋯⋯？$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice: @ 0x08210DED
	.string "ユウキ“{PLAYER}！\p"
	.string "チャンピオンに　ちょうせん　するまえに\n"
	.string "オレが　アドバイス　してやろうか⋯⋯$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon: @ 0x08210E1C
	.string "ユウキ“{PLAYER}⋯⋯\p"
	.string "おまえ　ひょっとして\n"
	.string "チャンピオンに　かったのか？$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex: @ 0x08210E3F
	.string "オダマキ“ほれみろ　{RIVAL}！\p"
	.string "{PLAYER}{KUN}なら　しんぱい　いらんと\n"
	.string "わたしが　いったとおり　だろう！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "{PLAYER}{KUN}　とうとう　やりとげたな\p"
	.string "きみが　トウカ　ジムの　おとうさんに\n"
	.string "かちぬいたと　きいた　ときに\l"
	.string "もしや⋯⋯　とは　おもったが\p"
	.string "まさか　ほんとうに　チャンピオンに\n"
	.string "なってしまうとは　な！\p"
	.string "⋯⋯おお　そうだ！\p"
	.string "きみの　ポケモンずかんは　どうなった？\n"
	.string "わたしに　みせて　ごらん！$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations: @ 0x08210F04
	.string "オダマキ“とにかく　おめでとう！\p"
	.string "さあ　むねをはって　おくの　へやに\n"
	.string "いってくるが　いいよ！$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe: @ 0x08210F33
	.string "ミクリ“{PLAYER}{KUN}\p"
	.string "⋯⋯いや　あらためて　よびなおそう\p"
	.string "あたらしい　チャンピオン！\p"
	.string "さあ　わたしに　ついて　きたまえ$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside: @ 0x08210F6D
	.string "ミクリ“もうしわけ　ないが⋯⋯\p"
	.string "ここから　さきの　へやは\n"
	.string "チャンピオンに　なった　トレーナー　だけが\l"
	.string "はいることの　できる　ばしょ\p"
	.string "きみは　そこで　オダマキはかせと\n"
	.string "いっしょに　まっていて　くれたまえ$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations: @ 0x08210FD2
	.string "ハルカ“⋯⋯がーん！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "なーんてね　いいの　いいの！\n"
	.string "だって　そういう　きまり　だもんね！\p"
	.string "{PLAYER}{KUN}！\n"
	.string "ほんとうに　おめでとう！！$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations: @ 0x08211025
	.string "ユウキ“⋯⋯えーっ！\n"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ま　しかたないか\n"
	.string "そういう　きまり　だもんな\p"
	.string "{PLAYER}！　よかったな\n"
	.string "おめでとう！！$"
