@ BattleFrontier_ReceptionGate scripts (JP map g26 m50 @ 0x0823A22C)

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_MapScriptTable_0023A23B
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_EventScript_0023A237
	.byte 0

BattleFrontier_ReceptionGate_EventScript_0023A237::
	setflag 0x8A8
	end

BattleFrontier_ReceptionGate_MapScriptTable_0023A23B::
	map_script_2 0x40D0, 0x0, BattleFrontier_ReceptionGate_EventScript_0023A245
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_0023A245::
	lockall
	setvar 0x40D0, 0x1
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	loadword 0x0, gJPText_0023A5D2
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0823A324
	waitmovement 0x0
	goto BattleFrontier_ReceptionGate_EventScript_0023A27B
	end

BattleFrontier_ReceptionGate_EventScript_0023A27B::
	loadword 0x0, gJPText_0023A5ED
	callstd 0x4
	loadword 0x0, gJPText_0023A60F
	callstd 0x4
	playfanfare 0x172
	message gJPText_0023A65F
	waitfanfare
	waitmessage
	loadword 0x0, gJPText_0023A673
	callstd 0x4
	setflag 0x8D2
	loadword 0x0, gJPText_0023A692
	callstd 0x4
	loadword 0x0, gJPText_0023A6B4
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	applymovement 0x2, 0x08243629
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	playse 0x15
	applymovement 0x1, 0x0824361B
	applymovement 0x2, 0x0824361B
	applymovement 0xFF, 0x0824361B
	waitmovement 0x0
	loadword 0x0, gJPText_0023A6CB
	callstd 0x4
	closemessage
	applymovement 0x1, 0x0823A342
	applymovement 0x2, 0x0823A348
	applymovement 0xFF, 0x0823A329
	applymovement 0x4, 0x0823A332
	waitmovement 0x0
	loadword 0x0, gJPText_0023A6E5
	callstd 0x4
	closemessage
	applymovement 0x4, 0x0823A33A
	waitmovement 0x0
	removeobject 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x23a324, 0x2a
BattleFrontier_ReceptionGate_EventScript_0023A34E::
	lock
	faceplayer
	loadword 0x0, gJPText_0023A5ED
	callstd 0x4
	loadword 0x0, gJPText_0023A692
	callstd 0x4
	release
	end

BattleFrontier_ReceptionGate_EventScript_0023A362::
	lock
	faceplayer
	loadword 0x0, 0x0823A755
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A372::
	message 0x0823A782
	waitmessage
	setvar 0x8004, 0x8
	special sub_0813A164
	waitstate
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A400
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A40E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A41C
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A42A
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A438
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A446
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A454
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A462
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A470
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A47E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A47E
	end

BattleFrontier_ReceptionGate_EventScript_0023A400::
	loadword 0x0, 0x0823A794
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A40E::
	loadword 0x0, 0x0823A7FA
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A41C::
	loadword 0x0, 0x0823A876
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A42A::
	loadword 0x0, 0x0823A8CD
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A438::
	loadword 0x0, 0x0823A92A
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A446::
	loadword 0x0, 0x0823A9AF
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A454::
	loadword 0x0, 0x0823AA0C
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A462::
	loadword 0x0, 0x0823AA59
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A470::
	loadword 0x0, 0x0823AAAF
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A372
	end

BattleFrontier_ReceptionGate_EventScript_0023A47E::
	loadword 0x0, gJPText_0023A692
	callstd 0x4
	release
	end

BattleFrontier_ReceptionGate_EventScript_0023A488::
	lock
	faceplayer
	loadword 0x0, 0x0823AB0E
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A498
	end

BattleFrontier_ReceptionGate_EventScript_0023A498::
	message 0x0823AB58
	waitmessage
	multichoice 0xF, 0x0, 0x5F, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A4F6
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A504
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A512
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A520
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A52E
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A53C
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A53C
	end

BattleFrontier_ReceptionGate_EventScript_0023A4F6::
	loadword 0x0, 0x0823AB6A
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A498
	end

BattleFrontier_ReceptionGate_EventScript_0023A504::
	loadword 0x0, 0x0823ABB0
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A498
	end

BattleFrontier_ReceptionGate_EventScript_0023A512::
	loadword 0x0, 0x0823AC6C
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A498
	end

BattleFrontier_ReceptionGate_EventScript_0023A520::
	loadword 0x0, 0x0823AD0B
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A498
	end

BattleFrontier_ReceptionGate_EventScript_0023A52E::
	loadword 0x0, 0x0823ADAF
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A498
	end

BattleFrontier_ReceptionGate_EventScript_0023A53C::
	loadword 0x0, gJPText_0023A692
	callstd 0x4
	release
	end

BattleFrontier_ReceptionGate_EventScript_0023A546::
	lock
	faceplayer
	loadword 0x0, 0x0823AE22
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A556
	end

BattleFrontier_ReceptionGate_EventScript_0023A556::
	message 0x0823AE3F
	waitmessage
	multichoice 0x10, 0x4, 0xB, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A59E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A5AC
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A5BA
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A5C8
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_ReceptionGate_EventScript_0023A5C8
	end

BattleFrontier_ReceptionGate_EventScript_0023A59E::
	loadword 0x0, 0x0823AE51
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A556
	end

BattleFrontier_ReceptionGate_EventScript_0023A5AC::
	loadword 0x0, 0x0823AEEB
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A556
	end

BattleFrontier_ReceptionGate_EventScript_0023A5BA::
	loadword 0x0, 0x0823AF71
	callstd 0x4
	goto BattleFrontier_ReceptionGate_EventScript_0023A556
	end

BattleFrontier_ReceptionGate_EventScript_0023A5C8::
	loadword 0x0, gJPText_0023A692
	callstd 0x4
	release
	end

	.globl gJPText_0023A5D2
gJPText_0023A5D2: @ 0x0823A5D2
	.string "はじめての　おきゃくさまですね！\n"
	.string "こちらへ　どうぞ！$"

	.globl gJPText_0023A5ED
gJPText_0023A5ED: @ 0x0823A5ED
	.string "ポケモンバトルの　さいぜんせん！\n"
	.string "バトルフロンティアへ　ようこそ！$"

	.globl gJPText_0023A60F
gJPText_0023A60F: @ 0x0823A60F
	.string "はじめての　おきゃくさまには\n"
	.string "バトルフロンティアの　なかで\l"
	.string "ごりよう　いただける　フロンティアパスを\l"
	.string "はっこうして　おります！\p"
	.string "どうぞ　おうけとり　ください！$"

	.globl gJPText_0023A65F
gJPText_0023A65F: @ 0x0823A65F
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "フロンティアパスを　もらった！$"

	.globl gJPText_0023A673
gJPText_0023A673: @ 0x0823A673
	.string "{MUS_RG_VS_TRAINER}は　トレーナーカードを\n"
	.string "フロンティアパスに　いれかえた！$"

	.globl gJPText_0023A692
gJPText_0023A692: @ 0x0823A692
	.string "それでは　バトルフロンティアを\n"
	.string "ぞんぶんに　おたのしみ　ください！$"

	.globl gJPText_0023A6B4
gJPText_0023A6B4: @ 0x0823A6B4
	.string "？？？“やあ　きて　くれたんだね\n"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！$"

	.globl gJPText_0023A6CB
gJPText_0023A6CB: @ 0x0823A6CB
	.string "うけつけ“あっ　エニシダさま！\n"
	.string "おつかれさまです！$"

	.globl gJPText_0023A6E5
gJPText_0023A6E5: @ 0x0823A6E5
	.string "エニシダ“きみが　きてくれて\n"
	.string "とっても　うれしいよ！\p"
	.string "ぜひ　ゆっくりと　そして　じっくりと\n"
	.string "ポケモンしょうぶの　しんずいを\l"
	.string "あじわって　いって　くれ！\p"
	.string "わたしの　へやも　あるから\n"
	.string "ひまが　あるときに　たずねて　きてくれよ！$"

	.incbin "baserom_jp.gba", 0x23a755, 0x9df
