@ BattleFrontier_BattleFactoryPreBattleRoom scripts (JP map g26 m32 @ 0x08231CA8)

BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_MapScriptTable_00231CDD
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_MapScriptTable_00231CB3
	.byte 0

BattleFrontier_BattleFactoryPreBattleRoom_MapScriptTable_00231CB3::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231CBD
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231CBD::
	setvar 0x4001, 0x1
	compare_var_to_value 0x8006, 0x1
	goto_if 0x5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231CD8
	setobjectxy 0x1, 0x8, 0x7
	turnobject 0x1, 0x1

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231CD8::
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleFactoryPreBattleRoom_MapScriptTable_00231CDD::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231CE7
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231CE7::
	compare_var_to_value 0x8006, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D93
	setvar 0x4000, 0x1
	applymovement 0x1, 0x08232397
	applymovement 0xFF, 0x08232385
	waitmovement 0x0
	compare_var_to_value 0x8006, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232057
	setvar 0x8004, 0xD
	special CallBattleFactoryFunction
	setvar 0x8004, 0xC
	special CallBattleFactoryFunction
	setvar 0x8004, 0xE
	special CallBattleFactoryFunction
	setorcopyvar 0x8005, 0x800D
	setvar 0x8004, 0xF
	special CallBattleFactoryFunction
	setorcopyvar 0x8006, 0x800D
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023207E
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321EF
	loadword 0x0, gJPText_002323B3
	callstd 0x4
	fadescreen 0x1
	setvar 0x8004, 0x8
	special CallBattleFactoryFunction
	setvar 0x8004, 0x6
	special CallBattleFactoryFunction
	waitstate

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62::
	loadword 0x0, gJPText_0023287D
	callstd 0x4
	closemessage
	call 0x082202F8
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232367
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232376
	waitmovement 0x0
	warp 0x1A21, 0xFF, 0x6, 0xB
	waitstate
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D93::
	setvar 0x8004, 0x9
	special CallBattleFactoryFunction
	setvar 0x8004, 0x10
	special CallBattleFactoryFunction
	loadword 0x0, gJPText_002323F8
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E14
	playse 0x107
	waitse
	loadword 0x0, gJPText_002328CF
	callstd 0x4
	closemessage
	applymovement 0x1, 0x082323AA
	waitmovement 0x0
	loadword 0x0, gJPText_002328EC
	callstd 0x4
	closemessage
	applymovement 0x1, 0x082323AE
	waitmovement 0x0
	loadword 0x0, gJPText_00232912
	callstd 0x4
	closemessage
	delay 0x10
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322A4
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322A4

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E14::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023200B
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232012
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232019
	compare_var_to_value 0x800D, 0x4
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232020
	compare_var_to_value 0x800D, 0x5
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232027
	compare_var_to_value 0x800D, 0x6
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023202E
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231EB4
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F86
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231EEA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F26
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F54
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231EB4::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F86
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F26
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F54
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231EEA::
	message gJPText_002328AF
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F1C
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F1C::
	call 0x0821F8F5
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F26::
	loadword 0x0, gJPText_002324CA
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232035
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F54::
	message gJPText_002324E3
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x08232B11
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F86::
	setvar 0x8004, 0xC
	special CallBattleFactoryFunction
	setvar 0x8004, 0xE
	special CallBattleFactoryFunction
	setorcopyvar 0x8005, 0x800D
	setvar 0x8004, 0xF
	special CallBattleFactoryFunction
	setorcopyvar 0x8006, 0x800D
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023207E
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321EF
	loadword 0x0, gJPText_00232839
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231FE0
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231FE0::
	fadescreen 0x1
	setvar 0x8004, 0x7
	special CallBattleFactoryFunction
	waitstate
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62
	setvar 0x8004, 0x8
	special CallBattleFactoryFunction
	loadword 0x0, gJPText_0023285F
	callstd 0x4
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023200B::
	message gJPText_00232415
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232012::
	message gJPText_00232433
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232019::
	message gJPText_00232451
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232020::
	message gJPText_0023246F
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232027::
	message gJPText_0023248D
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023202E::
	message gJPText_002324AB
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232035::
	message gJPText_0023288B
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x2
	special CallBattleFactoryFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232057::
	special SavePlayerParty
	setvar 0x8004, 0xA
	setvar 0x8005, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231E01

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023207E::
	loadword 0x0, gJPText_002324FF
	callstd 0x4
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023214D
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232156
	compare_var_to_value 0x8005, 0x2
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023215F
	compare_var_to_value 0x8005, 0x3
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232168
	compare_var_to_value 0x8005, 0x4
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232171
	compare_var_to_value 0x8005, 0x5
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023217A
	compare_var_to_value 0x8005, 0x6
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232183
	compare_var_to_value 0x8005, 0x7
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023218C
	compare_var_to_value 0x8005, 0x8
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232195
	compare_var_to_value 0x8005, 0xA
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023219E
	compare_var_to_value 0x8005, 0xB
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321A7
	compare_var_to_value 0x8005, 0xC
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321B0
	compare_var_to_value 0x8005, 0xD
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321B9
	compare_var_to_value 0x8005, 0xE
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321C2
	compare_var_to_value 0x8005, 0xF
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321CB
	compare_var_to_value 0x8005, 0x10
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321D4
	compare_var_to_value 0x8005, 0x11
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321DD
	compare_var_to_value 0x8005, 0x12
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321E6
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023214D::
	loadword 0x0, gJPText_00232526
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232156::
	loadword 0x0, gJPText_002325C1
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023215F::
	loadword 0x0, gJPText_0023260F
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232168::
	loadword 0x0, gJPText_002325DC
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232171::
	loadword 0x0, gJPText_002325F5
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023217A::
	loadword 0x0, gJPText_0023265D
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232183::
	loadword 0x0, gJPText_00232644
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023218C::
	loadword 0x0, gJPText_00232676
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232195::
	loadword 0x0, gJPText_002326C5
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023219E::
	loadword 0x0, gJPText_00232541
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321A7::
	loadword 0x0, gJPText_0023255B
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321B0::
	loadword 0x0, gJPText_0023258E
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321B9::
	loadword 0x0, gJPText_00232574
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321C2::
	loadword 0x0, gJPText_00232629
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321CB::
	loadword 0x0, gJPText_002325A7
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321D4::
	loadword 0x0, gJPText_00232691
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321DD::
	loadword 0x0, gJPText_002326AC
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321E6::
	loadword 0x0, gJPText_002326DF
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002321EF::
	compare_var_to_value 0x8006, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232253
	compare_var_to_value 0x8006, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023225C
	compare_var_to_value 0x8006, 0x2
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232265
	compare_var_to_value 0x8006, 0x3
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023226E
	compare_var_to_value 0x8006, 0x4
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232277
	compare_var_to_value 0x8006, 0x5
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232280
	compare_var_to_value 0x8006, 0x6
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232289
	compare_var_to_value 0x8006, 0x7
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232292
	compare_var_to_value 0x8006, 0x8
	call_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023229B
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232253::
	loadword 0x0, gJPText_00232818
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023225C::
	loadword 0x0, gJPText_00232790
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232265::
	loadword 0x0, gJPText_00232702
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023226E::
	loadword 0x0, gJPText_00232726
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232277::
	loadword 0x0, gJPText_00232749
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232280::
	loadword 0x0, gJPText_002327B2
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232289::
	loadword 0x0, gJPText_002327F7
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232292::
	loadword 0x0, gJPText_0023276B
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_0023229B::
	loadword 0x0, gJPText_002327D7
	callstd 0x4
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322A4::
	message gJPText_00232973
	waitmessage
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322FB
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232331
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231EEA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F26
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F54
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322A4

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322FB::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232331
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F26
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231F54
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_002322A4

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232331::
	loadword 0x0, gJPText_00232994
	callstd 0x4
	loadword 0x0, gJPText_00232839
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231FE0
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00231D62

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232367::
	applymovement 0x1, 0x0823239E
	applymovement 0xFF, 0x0823238B
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_00232376::
	applymovement 0x1, 0x082323A4
	applymovement 0xFF, 0x08232391
	return

	.incbin "baserom_jp.gba", 0x232385, 0x2e
	.globl gJPText_002323B3
gJPText_002323B3: @ 0x082323B3
	.string "では　まず　おきゃくさまの\n"
	.string "ポケモンを　おあずかりして\l"
	.string "ポケモンレンタルを　おこないます！\l"
	.string "よーく　かんがえて　えらんで　くださいよ！！$"

	.globl gJPText_002323F8
gJPText_002323F8: @ 0x082323F8
	.string "おつかれさま　です！\n"
	.string "ポケモンを　かいふく　しましょう！$"

	.globl gJPText_00232415
gJPText_00232415: @ 0x08232415
	.string "つぎは　2せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

	.globl gJPText_00232433
gJPText_00232433: @ 0x08232433
	.string "つぎは　3せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

	.globl gJPText_00232451
gJPText_00232451: @ 0x08232451
	.string "つぎは　4せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

	.globl gJPText_0023246F
gJPText_0023246F: @ 0x0823246F
	.string "つぎは　5せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

	.globl gJPText_0023248D
gJPText_0023248D: @ 0x0823248D
	.string "つぎは　6せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

	.globl gJPText_002324AB
gJPText_002324AB: @ 0x082324AB
	.string "いよいよ　7せんめ　ですよ！\n"
	.string "じゅんびは　よろしい　ですか？$"

	.globl gJPText_002324CA
gJPText_002324CA: @ 0x082324CA
	.string "レポートを　かいて\n"
	.string "しゅうりょう　なさいますか？$"

	.globl gJPText_002324E3
gJPText_002324E3: @ 0x082324E3
	.string "バトルトレードの　ちょうせんを\n"
	.string "ちゅうし　されますか？$"

	.globl gJPText_002324FF
gJPText_002324FF: @ 0x082324FF
	.string "さあさあ！\n"
	.string "こんかいの　たいせんあいて　ですが\l"
	.string "わたしの　ちょうさ　では⋯⋯$"

	.globl gJPText_00232526
gJPText_00232526: @ 0x08232526
	.string "どうやら　ノーマルタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_00232541
gJPText_00232541: @ 0x08232541
	.string "どうやら　ほのおタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_0023255B
gJPText_0023255B: @ 0x0823255B
	.string "どうやら　みずタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_00232574
gJPText_00232574: @ 0x08232574
	.string "どうやら　でんきタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_0023258E
gJPText_0023258E: @ 0x0823258E
	.string "どうやら　くさタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002325A7
gJPText_002325A7: @ 0x082325A7
	.string "どうやら　こおりタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002325C1
gJPText_002325C1: @ 0x082325C1
	.string "どうやら　かくとうタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002325DC
gJPText_002325DC: @ 0x082325DC
	.string "どうやら　どくタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002325F5
gJPText_002325F5: @ 0x082325F5
	.string "どうやら　じめんタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_0023260F
gJPText_0023260F: @ 0x0823260F
	.string "どうやら　ひこうタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_00232629
gJPText_00232629: @ 0x08232629
	.string "どうやら　エスパータイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_00232644
gJPText_00232644: @ 0x08232644
	.string "どうやら　むしタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_0023265D
gJPText_0023265D: @ 0x0823265D
	.string "どうやら　いわタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_00232676
gJPText_00232676: @ 0x08232676
	.string "どうやら　ゴーストタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_00232691
gJPText_00232691: @ 0x08232691
	.string "どうやら　ドラゴンタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002326AC
gJPText_002326AC: @ 0x082326AC
	.string "どうやら　あくタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002326C5
gJPText_002326C5: @ 0x082326C5
	.string "どうやら　はがねタイプを\n"
	.string "とくいと　して　いて⋯⋯$"

	.globl gJPText_002326DF
gJPText_002326DF: @ 0x082326DF
	.string "どうやら　ポケモンの　タイプには\n"
	.string "とくに　こだわりが　ないようで⋯⋯$"

	.globl gJPText_00232702
gJPText_00232702: @ 0x08232702
	.string "“じっくり　じわじわ”とした　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_00232726
gJPText_00232726: @ 0x08232726
	.string "“まだまだ　これから！”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_00232749
gJPText_00232749: @ 0x08232749
	.string "“けんこん　いってき”の　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_0023276B
gJPText_0023276B: @ 0x0823276B
	.string "“くもゆき　しだい”の　バトルを\n"
	.string "こころがけている　かたの　ようですよ！$"

	.globl gJPText_00232790
gJPText_00232790: @ 0x08232790
	.string "“じゅんび　ばんたん”の　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_002327B2
gJPText_002327B2: @ 0x082327B2
	.string "“まずは　よわらせて⋯”という　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_002327D7
gJPText_002327D7: @ 0x082327D7
	.string "“りんきおうへん”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_002327F7
gJPText_002327F7: @ 0x082327F7
	.string "“よそく　ふかのう”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_00232818
gJPText_00232818: @ 0x08232818
	.string "“じゆう　ほんぽう”な　バトルを\n"
	.string "こころがけている　ようですよ！$"

	.globl gJPText_00232839
gJPText_00232839: @ 0x08232839
	.string "では　バトルを　はじめる　まえに\n"
	.string "ポケモンの　こうかんを　おこないますか？$"

	.globl gJPText_0023285F
gJPText_0023285F: @ 0x0823285F
	.string "おつかれさまです！\n"
	.string "ポケモンこうかん　かんりょう　ですね！$"

	.globl gJPText_0023287D
gJPText_0023287D: @ 0x0823287D
	.string "それでは　おくに　どうぞ！$"

	.globl gJPText_0023288B
gJPText_0023288B: @ 0x0823288B
	.string "ただいま　レポートを　かいて　います⋯⋯\n"
	.string "しょうしょう　おまちください$"

	.globl gJPText_002328AF
gJPText_002328AF: @ 0x082328AF
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　しますか？$"

	.globl gJPText_002328CF
gJPText_002328CF: @ 0x082328CF
	.string "もうしわけ　ありません！\n"
	.string "しょうしょう　おまちください！$"

	.globl gJPText_002328EC
gJPText_002328EC: @ 0x082328EC
	.string "⋯⋯　えっ　⋯⋯　？　⋯⋯ひぃっ！\n"
	.string "わっかりましたっ！！　りょうかいです！$"

	.globl gJPText_00232912
gJPText_00232912: @ 0x08232912
	.string "やはは⋯⋯　おまたせ　しました！\p"
	.string "このしせつの　しょちょうで　ある\n"
	.string "ファクトリーヘッドからの　でんごんが\l"
	.string "ありますので　おつたえ　します！\p"
	.string "“やるぞっ！　いますぐ　こいっ！”\n"
	.string "との　ことです！$"

	.globl gJPText_00232973
gJPText_00232973: @ 0x08232973
	.string "ファクトリーヘッドが　およびです！\n"
	.string "かくごは　よろしい　ですか？$"

	.globl gJPText_00232994
gJPText_00232994: @ 0x08232994
	.string "もうしわけ　ありませんが\n"
	.string "ファクトリーヘッドに　ついての\l"
	.string "じょうほうは　おおしえ　できません！$"

