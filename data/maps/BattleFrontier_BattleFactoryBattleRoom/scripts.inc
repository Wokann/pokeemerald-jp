@ BattleFrontier_BattleFactoryBattleRoom scripts (JP map g26 m33 @ 0x082329C4)

BattleFrontier_BattleFactoryBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleFactoryBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnFrame
	.byte 0

BattleFrontier_BattleFactoryBattleRoom_OnTransition::
	setvar 0x8004, 0x5
	special CallFrontierUtilFunc
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj::
	call 0x08222264
	setobjectxyperm 0x2, 0x7, 0x9
	end

BattleFrontier_BattleFactoryBattleRoom_OnWarp::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects::
	setvar 0x4001, 0x1
	hideobject_at 0xFF, 0x1A21
	compare_var_to_value 0x400F, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects
	hideobject_at 0x2, 0x1A21

BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects::
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale::
	setvar 0x401F, 0x64
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale::
	setvar 0x401F, 0x69
	return

BattleFrontier_BattleFactoryBattleRoom_OnFrame::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle::
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn
	callstd 0x4
	closemessage
	applymovement 0x2, BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle
	applymovement 0x8, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	applymovement 0xFF, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0x0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom::
	compare_var_to_value 0x400F, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle
	applymovement 0x8, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	applymovement 0xFF, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0x0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
	setvar 0x8004, 0xB
	special CallBattleFactoryFunction
	removeobject 0x2
	setobjectxyperm 0x2, 0x7, 0x1
	addobject 0x2
	applymovement 0x2, BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter
	waitmovement 0x0

BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent::
	compare_var_to_value 0x400F, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland
	setvar 0x8004, 0x5
	special CallBattlePalaceFunction
	lockall
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent

BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
	addvar 0x800D, 0x1
	setorcopyvar 0x8006, 0x800D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction

BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak::
	call 0x08221FB3

BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
	setvar 0x8006, 0x1
	warp 0x1A20, 0xFF, 0x8, 0x8
	waitstate

BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland::
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver::
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn
	callstd 0x4
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass
	callstd 0x4
	closemessage
	applymovement 0x8, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
	waitmovement 0x0
	playfanfare 0x1D2
	message BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred
	callstd 0x4
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland

BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold::
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn
	callstd 0x4
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass
	callstd 0x4
	waitmessage
	applymovement 0x8, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
	waitmovement 0x0
	playfanfare 0x1D2
	message BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou
	callstd 0x4
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland

BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle::
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
	addvar 0x800D, 0x1
	setorcopyvar 0x8006, 0x800D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallBattleFactoryFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallBattleFactoryFunction
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	addvar 0x800D, 0x1
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
	end

BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom:: @ 0x08232D94
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland:: @ 0x08232D9B
	walk_right
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter:: @ 0x08232D9D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle:: @ 0x08232DA4
	walk_up
	walk_up
	walk_up
	face_left
	step_end
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby::
	copyvar 0x800D, 0x40CE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles
	warp 0x1A1F, 0xFF, 0x4, 0x8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles::
	warp 0x1A1F, 0xFF, 0xE, 0x8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle::
	applymovement 0x1, 0x0824362B
	applymovement 0x3, 0x0824362B
	applymovement 0x4, 0x0824362B
	applymovement 0x5, 0x08243627
	applymovement 0x6, 0x08243627
	applymovement 0x7, 0x08243627
	waitmovement 0x0
	return

BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn: @ 0x08232DFB
	.string "ほらほら！　はやく　きなっ！$"

BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead: @ 0x08232E0A
	.string "おれの　なまえは　ダツラ！\n"
	.string "いちおう　ここの　せきにんしゃで\l"
	.string "ファクトリーヘッド　ってのを　やってる！\p"
	.string "おめえの　バトルトレードの\n"
	.string "データは　みせて　もらったぜ！\p"
	.string "まあまあ　いいスジ　してる　みてぇ　だが\n"
	.string "まだまだ　あたまが　カッテぇ　なぁ！\p"
	.string "イイかー？　ちしき　っつうのは\n"
	.string "ただ　ほんを　よんだり\l"
	.string "つくえに　むかってる　だけじゃ\l"
	.string "なーんにも　みには　ならねぇんだぜ！\p"
	.string "じぶんの　こころと　からだで　じっさいに\n"
	.string "たいけん　して　みねぇと　なあ⋯⋯\p"
	.string "おれも　おめえと　おんなじ　じょうけん！\n"
	.string "レンタルポケモンで　たたかう！！$"

BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn: @ 0x08232F10
	.string "ありったけの　ちしき　ふりしぼって\n"
	.string "かかって　こいやっ！$"

BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass: @ 0x08232F2D
	.string "ダツラ“イイぜ！\n"
	.string "フロンティアパス　かしな！$"

BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol: @ 0x08232F44
	.string "フロンティアパスに\n"
	.string "ノウレッジシンボルが　きざまれた！$"

BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred: @ 0x08232F60
	.string "へっ⋯⋯　おもしれぇじゃ　ねえか⋯⋯\p"
	.string "つぎに　あうときゃー\n"
	.string "おれも　マジで　いく　からな！\p"
	.string "しっかり　べんきょう　しとけよ！！$"

BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime: @ 0x08232FA0
	.string "ダツラ“オース！　どうよー？　ちょうしはー？\n"
	.string "しっかり　べんきょう　してるか？\p"
	.string "⋯⋯　お？\p"
	.string "おめえ　まえに　あった　ときより\n"
	.string "ちょっと　イイ　ツラしてるじゃ　ねえか！\p"
	.string "こりゃ　たのしみ　だねー！\n"
	.string "ワクワクして　きたぜ！　おい！$"

BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn: @ 0x08233012
	.string "よっしゃ！！　バチッと　こい！！$"

BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass: @ 0x08233023
	.string "ダツラ“なんだよ！　おめえー！！\n"
	.string "すっげぇ　ことに　なってんじゃ　ねぇかよ！\p"
	.string "ったく　フロンティアパス　よこしな！$"

BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine: @ 0x0823305D
	.string "ノウレッジシンボルが\n"
	.string "きんいろに　かがやいた！$"

BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou: @ 0x08233075
	.string "ちっくしょー！！\p"
	.string "つぎは　ぜってぇに　まけねぇ　からな！\n"
	.string "また　やろうぜっ！！$"
