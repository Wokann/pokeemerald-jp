@ Route114_FossilManiacsTunnel scripts (JP map g20 m1 @ 0x0821228D)

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:: @ 0x08212298
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac:: @ 0x082122A2
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 0x6, 0x5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:: @ 0x082122AE
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass:: @ 0x082122B8
	setmetatile 0x6, 0x1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 0x6, 0x2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn:: @ 0x082122CB
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac:: @ 0x082122EC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil:: @ 0x08212321
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil:: @ 0x0821232B
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils: @ 0x08212335
	.string "ぼく　かせきマニア⋯⋯\n"
	.string "かせき　だいすき　ナイスガイ　さ⋯⋯\p"
	.string "きみも　カセキが　ほしいの⋯⋯？\p"
	.string "ここで　みつかる　カセキは\n"
	.string "ぜんぶ　ぼくの　ものだから　あげないよ⋯⋯\p"
	.string "どうしても　ほしければ\n"
	.string "カセキの　みつかりそうな\l"
	.string "いわや　すなが　おおい　さばくでも\l"
	.string "さがして　みなよ⋯⋯$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils: @ 0x082123BF
	.string "きみも　カセキを　みつけたんだね⋯⋯\n"
	.string "すてき⋯⋯　うっとり　しちゃうよ⋯⋯\p"
	.string "きみ　その　カセキ　どうするの⋯⋯？\p"
	.string "きいた　はなしでは　デボンでは\n"
	.string "カセキを　ポケモンに　いきかえらせる\l"
	.string "けんきゅうを　している　そうだよ⋯⋯\p"
	.string "ぼくは　カセキが　すきだから\n"
	.string "そんなこと　しないけどね⋯⋯$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful: @ 0x0821244C
	.string "カセキって⋯⋯\n"
	.string "すてき⋯⋯　うっとり　しちゃうよ⋯⋯$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay: @ 0x08212467
	.string "あ⋯⋯\n"
	.string "そっちに　いくと　あぶないよ⋯⋯\p"
	.string "ほりまくって　いたら\n"
	.string "カベが　くずれて　しまったんだ⋯⋯\p"
	.string "したに　おおきな　くうどうが\n"
	.string "あるみたい　だけど⋯⋯\l"
	.string "カセキも　なさそう　だから\l"
	.string "そのままに　してあるんだ⋯⋯$"
