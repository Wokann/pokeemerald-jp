@ BattleFrontier_BattleTowerBattleRoom scripts (JP map g26 m8 @ 0x08221C39)

BattleFrontier_BattleTowerBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_MapScriptTable_00221C5B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_MapScriptTable_00221C44
	.byte 0

BattleFrontier_BattleTowerBattleRoom_MapScriptTable_00221C44::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerBattleRoom_EventScript_00221C4E
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_00221C4E::
	setvar 0x4001, 0x1
	applymovement 0x3, 0x0822228C
	end

BattleFrontier_BattleTowerBattleRoom_MapScriptTable_00221C5B::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerBattleRoom_EventScript_00221C65
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_00221C65::
	setvar 0x4000, 0x1
	applymovement 0xFF, 0x0822226D
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221CBC
	applymovement 0x2, 0x08222281
	waitmovement 0x0
	applymovement 0xFF, 0x08222272
	waitmovement 0x0
	setvar 0x4002, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221CBC::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x1
	applymovement 0x1, 0x08222276
	waitmovement 0x0
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special sub_08161E88
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00222207
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D28

BattleFrontier_BattleTowerBattleRoom_EventScript_00221CFC::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_08161E88
	setvar 0x8004, 0x3
	special sub_0813BFA0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_002222AC

BattleFrontier_BattleTowerBattleRoom_EventScript_00221D28::
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00221FB3
	setvar 0x8004, 0x4
	special sub_08161E88
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EEF
	applymovement 0x1, 0x0822227C
	waitmovement 0x0
	removeobject 0x1
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	call_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_00221FBC
	applymovement 0x2, 0x08222281
	waitmovement 0x0
	applymovement 0xFF, 0x08222272
	waitmovement 0x0
	loadword 0x0, gJPText_0022230B
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_00222003
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00221F3D
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E03
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221ED5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E39
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E75
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EA3
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221E03::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221ED5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E75
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EA3
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221E39::
	message gJPText_002223F2
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E6B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221E6B::
	call 0x0821F8F5
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221E75::
	loadword 0x0, gJPText_0022242F
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221F1B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221EA3::
	message gJPText_00222464
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00222302
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221D88

BattleFrontier_BattleTowerBattleRoom_EventScript_00221ED5::
	closemessage
	applymovement 0xFF, 0x08222274
	waitmovement 0x0
	applymovement 0x2, 0x08222286
	waitmovement 0x0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221CBC

BattleFrontier_BattleTowerBattleRoom_EventScript_00221EEF::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_08161E88
	setvar 0x8004, 0x3
	special sub_0813BFA0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_002222AC

BattleFrontier_BattleTowerBattleRoom_EventScript_00221F1B::
	message gJPText_00222446
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x2
	special sub_08161E88
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_00221F3D::
	copyvar 0x400F, 0x800D
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221F89
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221F90
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221F97
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221F9E
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221FA5
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221FAC

BattleFrontier_BattleTowerBattleRoom_EventScript_00221F89::
	message gJPText_00222344
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221F90::
	message gJPText_00222361
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221F97::
	message gJPText_0022237E
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221F9E::
	message gJPText_0022239B
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221FA5::
	message gJPText_002223B8
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221FAC::
	message gJPText_002223D5
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221FB3::
	setvar 0x8004, 0x11
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00221FBC::
	applymovement 0x3, 0x0822228E
	waitmovement 0x0
	applymovement 0x3, 0x08243639
	waitmovement 0x0
	playse 0x15
	applymovement 0x2, 0x0824361B
	waitmovement 0x0
	applymovement 0x2, 0x0824361D
	waitmovement 0x0
	applymovement 0x3, 0x0822229A
	applymovement 0x2, 0x0822229F
	waitmovement 0x0
	applymovement 0x3, 0x08222295
	waitmovement 0x0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00222003::
	compare_var_to_value 0x4002, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_0022201B
	loadword 0x0, gJPText_00222495
	callstd 0x4
	setvar 0x4002, 0x1

BattleFrontier_BattleTowerBattleRoom_EventScript_0022201B::
	message gJPText_002224E5
	waitmessage
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00222072
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002220A8
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E39
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E75
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EA3
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_0022201B

BattleFrontier_BattleTowerBattleRoom_EventScript_00222072::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002220A8
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221E75
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EA3
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_0022201B

BattleFrontier_BattleTowerBattleRoom_EventScript_002220A8::
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00222264
	closemessage
	applymovement 0xFF, 0x08222274
	waitmovement 0x0
	applymovement 0x2, 0x08222286
	waitmovement 0x0
	addobject 0x1
	applymovement 0x1, 0x082222A6
	waitmovement 0x0
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_0022217E
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00222122
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002221AB
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_00222122
	loadword 0x0, gJPText_00222508
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleTowerBattleRoom_EventScript_00222122::
	loadword 0x0, gJPText_0022259C
	callstd 0x4
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00222207
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_0022213F
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221CFC

BattleFrontier_BattleTowerBattleRoom_EventScript_0022213F::
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00221FB3
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EEF
	loadword 0x0, gJPText_002225B4
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_002225E5
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00222601
	callstd 0x4
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221EEF

BattleFrontier_BattleTowerBattleRoom_EventScript_0022217E::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerBattleRoom_EventScript_002221AB
	loadword 0x0, gJPText_00222665
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleTowerBattleRoom_EventScript_002221AB::
	loadword 0x0, gJPText_002226E3
	callstd 0x4
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00222207
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002221C8
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221CFC

BattleFrontier_BattleTowerBattleRoom_EventScript_002221C8::
	call BattleFrontier_BattleTowerBattleRoom_EventScript_00221FB3
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_00221EEF
	loadword 0x0, gJPText_002226EE
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_00222711
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00222729
	callstd 0x4
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221EEF

BattleFrontier_BattleTowerBattleRoom_EventScript_00222207::
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x0
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	copyvar 0x8004, 0x40CE
	compare_var_to_value 0x8004, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_0022224E
	setvar 0x8004, 0x12
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x15
	special CallFrontierUtilFunc

BattleFrontier_BattleTowerBattleRoom_EventScript_0022224E::
	setvar 0x8004, 0xF
	special sub_08161E88
	setvar 0x8004, 0x1
	setvar 0x8005, 0x5
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_00222264::
	setvar 0x8004, 0x16
	special CallFrontierUtilFunc
	return

	.incbin "baserom_jp.gba", 0x22226d, 0x3f
BattleFrontier_BattleTowerBattleRoom_EventScript_002222AC::
	copyvar 0x800D, 0x40CE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002222DC
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002222E6
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerBattleRoom_EventScript_002222F0
	warp 0x1A05, 0xFF, 0x6, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_002222DC::
	warp 0x1A05, 0xFF, 0xA, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_002222E6::
	warp 0x1A05, 0xFF, 0xE, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_002222F0::
	setvar 0x8004, 0xD
	special sub_08161E88
	warp 0x1A05, 0xFF, 0x12, 0x6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_00222302::
	setflag 0x77
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_00221CFC
	end

	.globl gJPText_0022230B
gJPText_0022230B: @ 0x0822230B
	.string "ポケモンの　たいりょくを\n"
	.string "かいふくして　さしあげます$"

	.incbin "baserom_jp.gba", 0x222326, 0x1e
	.globl gJPText_00222344
gJPText_00222344: @ 0x08222344
	.string "つぎは　2にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_00222361
gJPText_00222361: @ 0x08222361
	.string "つぎは　3にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_0022237E
gJPText_0022237E: @ 0x0822237E
	.string "つぎは　4にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_0022239B
gJPText_0022239B: @ 0x0822239B
	.string "つぎは　5にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_002223B8
gJPText_002223B8: @ 0x082223B8
	.string "つぎは　6にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_002223D5
gJPText_002223D5: @ 0x082223D5
	.string "つぎは　7にんめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_002223F2
gJPText_002223F2: @ 0x082223F2
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　しますか？$"

	.globl gJPText_00222412
gJPText_00222412: @ 0x08222412
	.string "{MUS_RG_VS_TRAINER}の　たたかいが\n"
	.string "フロンティアパスに　きろく　された！$"

	.globl gJPText_0022242F
gJPText_0022242F: @ 0x0822242F
	.string "レポートを　かいて　しゅうりょう　しますか？$"

	.globl gJPText_00222446
gJPText_00222446: @ 0x08222446
	.string "レポートを　かいています！\n"
	.string "しばらく　おまちくださいませ！$"

	.globl gJPText_00222464
gJPText_00222464: @ 0x08222464
	.string "バトルルームの　ちょうせんを\n"
	.string "ちゅうし　しますか？$"

	.globl gJPText_0022247E
gJPText_0022247E: @ 0x0822247E
	.globl gUnknown_822247E
gUnknown_822247E:
	.string "ふぐあいに　より\n"
	.string "きろく　できませんでした！$"

	.globl gJPText_00222495
gJPText_00222495: @ 0x08222495
	.string "⋯⋯　おきゃくさま\p"
	.string "じつは　わたくしどもの　しゅじんで　ある\n"
	.string "タワータイクーンが\l"
	.string "あなたと　たたかう　ために　まもなく\l"
	.string "バトルルームに　いらっしゃる　そうです$"

	.globl gJPText_002224E5
gJPText_002224E5: @ 0x082224E5
	.string "タワータイクーンとの　たたかい　です！\n"
	.string "かくごは　よろしい　ですか？$"

	.globl gJPText_00222508
gJPText_00222508: @ 0x08222508
	.string "はじめまして⋯⋯\p"
	.string "ぼくの　なまえは　リラ\n"
	.string "バトルタワーを　かんりする　もの⋯⋯\l"
	.string "タワータイクーンだ⋯⋯\p"
	.string "あなたの　うわさは\n"
	.string "いろいろと　きいて　いるよ\p"
	.string "しょうじき　ぼくには　みりょくを\n"
	.string "かんじない　こと　ばかり　だけどね⋯⋯\p"
	.string "ぼくが　あなたに　あいに　きた　りゆう⋯⋯\n"
	.string "それは　ただ　ひとつ⋯⋯$"

	.globl gJPText_0022259C
gJPText_0022259C: @ 0x0822259C
	.string "あなたの　さいのうを\n"
	.string "ここに　しめしなさい⋯⋯$"

	.globl gJPText_002225B4
gJPText_002225B4: @ 0x082225B4
	.string "リラ“ふふふ　いいね⋯⋯\p"
	.string "では　フロンティアパスを⋯⋯\n"
	.string "あなたの　さいのうの　あかしを　きざもう$"

	.globl gJPText_002225E5
gJPText_002225E5: @ 0x082225E5
	.string "フロンティアパスに\n"
	.string "アビリティシンボルが　きざまれた！$"

	.globl gJPText_00222601
gJPText_00222601: @ 0x08222601
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "あなたは　ポケモンバトルに\n"
	.string "じしんが　あるのだろ？\p"
	.string "だったら　もっと　もっと　たたかって\n"
	.string "もっと　もっと　かちぬいて　おいでよ\p"
	.string "また　あえる　そのときを\n"
	.string "ぼくは　まってる　から⋯⋯$"

	.globl gJPText_00222665
gJPText_00222665: @ 0x08222665
	.string "リラ“ほんとに　きて　くれたんだね⋯⋯\p"
	.string "⋯⋯　⋯⋯　⋯⋯　⋯⋯\p"
	.string "ここまで　かちぬいた　あなた⋯⋯\n"
	.string "⋯⋯　あなたが　あいて　だったら\l"
	.string "ぼくも　てかげん　せずに　たたかえる⋯⋯\p"
	.string "ひさしぶり⋯⋯\p"
	.string "なんにも　かんがえずに\n"
	.string "たたかう　ことが　できる　なんて⋯⋯$"

	.globl gJPText_002226E3
gJPText_002226E3: @ 0x082226E3
	.string "さあ　はじめようよ！$"

	.globl gJPText_002226EE
gJPText_002226EE: @ 0x082226EE
	.string "リラ“ふふっ　おめでとう⋯⋯\n"
	.string "さあ　あなたの　フロンティアパスを⋯⋯$"

	.globl gJPText_00222711
gJPText_00222711: @ 0x08222711
	.string "アビリティシンボルが\n"
	.string "きんいろに　かがやいた！$"

	.globl gJPText_00222729
gJPText_00222729: @ 0x08222729
	.string "たのしかった⋯⋯\p"
	.string "こんなに　ポケモンバトルが\n"
	.string "たのしい　なんて　はじめて⋯⋯\p"
	.string "また　あなたと　たたかえると　いいな⋯⋯$"

