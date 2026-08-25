@ MossdeepCity_GameCorner_1F scripts (JP map g14 m11 @ 0x0820E01E)

MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:: @ 0x0820E02E
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:: @ 0x0820E038
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

MossdeepCity_GameCorner_1F_EventScript_InfoMan:: @ 0x0820E042
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

MossdeepCity_GameCorner_1F_EventScript_OldMan:: @ 0x0820E04B
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end

RS_MysteryEventsHouse_EventScript_Door:: @ 0x0820E054
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting: @ 0x0820E05D
	.string "わしも　わかいころは\n"
	.string "ポケモン　トレーナーとして\l"
	.string "せかいじゅうを　たび　していたのじゃ\p"
	.string "ジジイとなった　いまでは\n"
	.string "わかい　トレーナーの　しょうぶを　みるのが\l"
	.string "ゆいいつの　たのしみ　じゃ$"

RS_MysteryEventsHouse_Text_DoorIsLocked: @ 0x0820E0BA
	.string "とびらには　かぎが　かかって　いるようだ！$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer: @ 0x0820E0D0
	.string "いまは　{STR_VAR_1}　という　トレーナーが\n"
	.string "わしの　いえに　きておる！\p"
	.string "{STR_VAR_1}と　しょうぶ　してみたいのじゃな？$"

RS_MysteryEventsHouse_Text_YouWontBattle: @ 0x0820E104
	.string "しょうぶ　せんのか⋯⋯\n"
	.string "しょうぶを　みられなくて　ガッカリ⋯⋯$"

RS_MysteryEventsHouse_Text_KeepItToA3On3: @ 0x0820E124
	.string "おお　そうか　そうか！\p"
	.string "じゃが　この　いえは\n"
	.string "あんまり　がんじょう　じゃないから\p"
	.string "せめて　3たい3の\n"
	.string "しょうぶに　して　くれんかのう？$"

RS_MysteryEventsHouse_Text_SaveYourProgress: @ 0x0820E168
	.string "じゃあ　しょうぶの　まえに\n"
	.string "レポートを　かいて　おいたほうが　よいぞ$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch: @ 0x0820E18B
	.string "よい　しょうぶを　きたい　しておるぞ！$"

RS_MysteryEventsHouse_Text_BattleTie: @ 0x0820E19F
	.string "ひきわけ　じゃったか！\p"
	.string "おたがい　いっぽも　ゆずらぬ\n"
	.string "すばらしい　しょうぶ　じゃったぞ！$"

RS_MysteryEventsHouse_Text_BattleWon: @ 0x0820E1CC
	.string "みごと　じゃったぞ！\p"
	.string "まるで　わしの　わかい　ころを\n"
	.string "みている　ようじゃわい！$"

RS_MysteryEventsHouse_Text_BattleLost: @ 0x0820E1F4
	.string "ざんねん　じゃったのう\n"
	.string "じゃが　よい　しょうぶ　じゃったぞ！\l"
	.string "つぎこそは　かてると　よいのう$"
