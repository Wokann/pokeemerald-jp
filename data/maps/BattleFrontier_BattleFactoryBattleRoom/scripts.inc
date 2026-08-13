@ BattleFrontier_BattleFactoryBattleRoom scripts (JP map g26 m33 @ 0x082329C4)

BattleFrontier_BattleFactoryBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleFactoryBattleRoom_EventScript_002329D4
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryBattleRoom_MapScriptTable_00232A19
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryBattleRoom_MapScriptTable_00232A4A
	.byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_002329D4::
	setvar 0x8004, 0x5
	special CallFrontierUtilFunc
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A3E
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A44
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A0C
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A0C::
	call 0x08222264
	setobjectxyperm 0x2, 0x7, 0x9
	end

BattleFrontier_BattleFactoryBattleRoom_MapScriptTable_00232A19::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A23
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A23::
	setvar 0x4001, 0x1
	hideobject_at 0xFF, 0x1A21
	compare_var_to_value 0x400F, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A3D
	hideobject_at 0x2, 0x1A21

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A3D::
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A3E::
	setvar 0x401F, 0x64
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A44::
	setvar 0x401F, 0x69
	return

BattleFrontier_BattleFactoryBattleRoom_MapScriptTable_00232A4A::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A80
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A54::
	loadword 0x0, gJPText_00232DFB
	callstd 0x4
	closemessage
	applymovement 0x2, 0x08232DA4
	applymovement 0x8, 0x08232D94
	applymovement 0xFF, 0x08232D94
	waitmovement 0x0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DCD
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232AC0
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A80::
	compare_var_to_value 0x400F, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232A54
	applymovement 0x8, 0x08232D94
	applymovement 0xFF, 0x08232D94
	waitmovement 0x0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DCD
	setvar 0x8004, 0xB
	special CallBattleFactoryFunction
	removeobject 0x2
	setobjectxyperm 0x2, 0x7, 0x1
	addobject 0x2
	applymovement 0x2, 0x08232D9D
	waitmovement 0x0

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232AC0::
	compare_var_to_value 0x400F, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232BB5
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
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B28

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B11::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DA9

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B28::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B57
	addvar 0x800D, 0x1
	setorcopyvar 0x8006, 0x800D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B57::
	call 0x08221FB3

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B5C::
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
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B9E
	setvar 0x8006, 0x1
	warp 0x1A20, 0xFF, 0x8, 0x8
	waitstate

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B9E::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DA9

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232BB5::
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C6A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C08
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C97
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C08
	loadword 0x0, gJPText_00232E0A
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C08::
	loadword 0x0, gJPText_00232F10
	callstd 0x4
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_00232CF9
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C25
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B11

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C25::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232D1E
	loadword 0x0, gJPText_00232F2D
	callstd 0x4
	closemessage
	applymovement 0x8, 0x08232D9B
	waitmovement 0x0
	playfanfare 0x1D2
	message gJPText_00232F44
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00232F60
	callstd 0x4
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232D1E

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C6A::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C97
	loadword 0x0, gJPText_00232FA0
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232C97::
	loadword 0x0, gJPText_00233012
	callstd 0x4
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_00232CF9
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232CB4
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B11

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232CB4::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232D1E
	loadword 0x0, gJPText_00233023
	callstd 0x4
	waitmessage
	applymovement 0x8, 0x08232D9B
	waitmovement 0x0
	playfanfare 0x1D2
	message gJPText_0023305D
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00233075
	callstd 0x4
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232D1E

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232CF9::
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

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232D1E::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B57
	addvar 0x800D, 0x1
	setorcopyvar 0x8006, 0x800D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special CallBattleFactoryFunction
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallBattleFactoryFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B5C
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallBattleFactoryFunction
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	addvar 0x800D, 0x1
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_00232B9E
	end

	.incbin "baserom_jp.gba", 0x232d94, 0x15
BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DA9::
	copyvar 0x800D, 0x40CE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DC3
	warp 0x1A1F, 0xFF, 0x4, 0x8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DC3::
	warp 0x1A1F, 0xFF, 0xE, 0x8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_00232DCD::
	applymovement 0x1, 0x0824362B
	applymovement 0x3, 0x0824362B
	applymovement 0x4, 0x0824362B
	applymovement 0x5, 0x08243627
	applymovement 0x6, 0x08243627
	applymovement 0x7, 0x08243627
	waitmovement 0x0
	return

	.globl gJPText_00232DFB
gJPText_00232DFB: @ 0x08232DFB
	.string "ほらほら！　はやく　きなっ！$"

	.globl gJPText_00232E0A
gJPText_00232E0A: @ 0x08232E0A
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

	.globl gJPText_00232F10
gJPText_00232F10: @ 0x08232F10
	.string "ありったけの　ちしき　ふりしぼって\n"
	.string "かかって　こいやっ！$"

	.globl gJPText_00232F2D
gJPText_00232F2D: @ 0x08232F2D
	.string "ダツラ“イイぜ！\n"
	.string "フロンティアパス　かしな！$"

	.globl gJPText_00232F44
gJPText_00232F44: @ 0x08232F44
	.string "フロンティアパスに\n"
	.string "ノウレッジシンボルが　きざまれた！$"

	.globl gJPText_00232F60
gJPText_00232F60: @ 0x08232F60
	.string "へっ⋯⋯　おもしれぇじゃ　ねえか⋯⋯\p"
	.string "つぎに　あうときゃー\n"
	.string "おれも　マジで　いく　からな！\p"
	.string "しっかり　べんきょう　しとけよ！！$"

	.globl gJPText_00232FA0
gJPText_00232FA0: @ 0x08232FA0
	.string "ダツラ“オース！　どうよー？　ちょうしはー？\n"
	.string "しっかり　べんきょう　してるか？\p"
	.string "⋯⋯　お？\p"
	.string "おめえ　まえに　あった　ときより\n"
	.string "ちょっと　イイ　ツラしてるじゃ　ねえか！\p"
	.string "こりゃ　たのしみ　だねー！\n"
	.string "ワクワクして　きたぜ！　おい！$"

	.globl gJPText_00233012
gJPText_00233012: @ 0x08233012
	.string "よっしゃ！！　バチッと　こい！！$"

	.globl gJPText_00233023
gJPText_00233023: @ 0x08233023
	.string "ダツラ“なんだよ！　おめえー！！\n"
	.string "すっげぇ　ことに　なってんじゃ　ねぇかよ！\p"
	.string "ったく　フロンティアパス　よこしな！$"

	.globl gJPText_0023305D
gJPText_0023305D: @ 0x0823305D
	.string "ノウレッジシンボルが\n"
	.string "きんいろに　かがやいた！$"

	.globl gJPText_00233075
gJPText_00233075: @ 0x08233075
	.string "ちっくしょー！！\p"
	.string "つぎは　ぜってぇに　まけねぇ　からな！\n"
	.string "また　やろうぜっ！！$"

