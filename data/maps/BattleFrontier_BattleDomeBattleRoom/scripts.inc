@ BattleFrontier_BattleDomeBattleRoom scripts (JP map g26 m21 @ 0x08228828)

BattleFrontier_BattleDomeBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_EventScript_0022883D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_MapScriptTable_0022888C
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_MapScriptTable_0022900D
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_EventScript_0022907C
	.byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_0022883D::
	setvar 0x8004, 0xA
	special sub_0818E608
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002294A5
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228868
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_00228868::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228880
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228886
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228880::
	setvar 0x4011, 0x64
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228886::
	setvar 0x4011, 0x69
	return

BattleFrontier_BattleDomeBattleRoom_MapScriptTable_0022888C::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleDomeBattleRoom_EventScript_00228896
	.2byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_00228896::
	lockall
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228D49
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002294C4
	applymovement 0x1, 0x08243637
	waitmovement 0x0
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228B61
	loadword 0x0, gJPText_002294FC
	callstd 0x4
	closemessage
	showobject_at 0xD, 0x1A15
	compare_var_to_value 0x400F, 0x3
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_002288DA
	compare_var_to_value 0x400E, 0x0
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_002288E6

BattleFrontier_BattleDomeBattleRoom_EventScript_002288DA::
	applymovement 0xD, 0x08229301
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_002288ED

BattleFrontier_BattleDomeBattleRoom_EventScript_002288E6::
	applymovement 0xD, 0x0822930B

BattleFrontier_BattleDomeBattleRoom_EventScript_002288ED::
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitmovement 0x0
	compare_var_to_value 0x400F, 0x3
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_0022890E
	compare_var_to_value 0x400E, 0x0
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D57

BattleFrontier_BattleDomeBattleRoom_EventScript_0022890E::
	setvar 0x8004, 0x4
	special sub_0818E608
	loadword 0x0, gJPText_0022950D
	callstd 0x4
	closemessage
	applymovement 0xD, 0x08229307
	applymovement 0xF, 0x08229315
	waitmovement 0x0
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special sub_08161E88
	loadword 0x0, 0x2021C7C
	callstd 0x4
	closemessage
	setvar 0x8004, 0x5
	special sub_0818E608
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228FCC
	setvar 0x4002, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228A6C
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002289DB
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002289DB
	setvar 0x4002, 0x1

BattleFrontier_BattleDomeBattleRoom_EventScript_00228983::
	loadword 0x0, gJPText_002295B8
	callstd 0x4
	closemessage
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	delay 0x3C
	applymovement 0x9, 0x082294F0
	waitmovement 0x0
	applymovement 0x1, 0x082294F5
	waitmovement 0x0
	delay 0xB4
	applymovement 0x9, 0x082294F7
	waitmovement 0x0
	compare_var_to_value 0x4002, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002289DB
	setvar 0x8004, 0x13
	special sub_0818E608
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228A6C

BattleFrontier_BattleDomeBattleRoom_EventScript_002289DB::
	applymovement 0x1, 0x08243637
	waitmovement 0x0
	setvar 0x8004, 0x4
	special sub_0818E608
	compare_var_to_value 0x4002, 0x0
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228A3D
	compare_var_to_value 0x4002, 0x1
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228A51
	compare_var_to_value 0x4002, 0x2
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228A65
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	delay 0x3C

BattleFrontier_BattleDomeBattleRoom_EventScript_00228A19::
	setvar 0x8004, 0xC
	setvar 0x8005, 0x2
	special sub_0818E608
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00229481

BattleFrontier_BattleDomeBattleRoom_EventScript_00228A3D::
	setvar 0x8004, 0x14
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	message gJPText_00229547
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228A51::
	setvar 0x8004, 0x14
	setvar 0x8005, 0x0
	special CallFrontierUtilFunc
	message gJPText_00229608
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228A65::
	message gJPText_00229CE6
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228A6C::
	applymovement 0x1, 0x08243637
	waitmovement 0x0
	compare_var_to_value 0x4002, 0x0
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228B4F
	compare_var_to_value 0x4002, 0x1
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228B58
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	delay 0x3C
	setvar 0x8004, 0x3
	special sub_0818E608
	setvar 0x8004, 0xC
	setvar 0x8005, 0x1
	special sub_0818E608
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228AEE
	setvar 0x8006, 0x1
	warp 0x1A14, 0xFF, 0x5, 0x3
	waitstate

BattleFrontier_BattleDomeBattleRoom_EventScript_00228AEE::
	applymovement 0xD, 0x08229309
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228B22
	loadword 0x0, gJPText_0022955F
	callstd 0x4
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228B2A

BattleFrontier_BattleDomeBattleRoom_EventScript_00228B22::
	loadword 0x0, gJPText_0022958C
	callstd 0x4

BattleFrontier_BattleDomeBattleRoom_EventScript_00228B2A::
	special sub_08175184
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	delay 0x3C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00229481

BattleFrontier_BattleDomeBattleRoom_EventScript_00228B4F::
	loadword 0x0, gJPText_0022952F
	callstd 0x4
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228B58::
	loadword 0x0, gJPText_0022964E
	callstd 0x4
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228B61::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x6
	special sub_0818E608
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228BAF
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special sub_0818E608
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228C02
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special sub_0818E608
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CF6
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228C55
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228BAF::
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228D49
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228BE6
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228BED
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228BF4
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228BFB
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228BE6::
	message gJPText_00229694
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228BED::
	message gJPText_002296A5
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228BF4::
	message gJPText_002296B5
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228BFB::
	message gJPText_002296D6
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C02::
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228D49
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228C39
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228C40
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228C47
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228C4E
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C39::
	message gJPText_002296F9
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C40::
	message gJPText_0022970A
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C47::
	message gJPText_00229724
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C4E::
	message gJPText_00229742
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C55::
	compare_var_to_value 0x400F, 0x3
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_00228C91
	copyvar 0x8000, 0x400E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CE4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CED
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CE4
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CED

BattleFrontier_BattleDomeBattleRoom_EventScript_00228C91::
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228D49
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CC8
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CCF
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CD6
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228CDD
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CC8::
	message gJPText_00229756
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CCF::
	message gJPText_00229764
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CD6::
	message gJPText_00229787
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CDD::
	message gJPText_002297A7
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CE4::
	loadword 0x0, gJPText_0022981A
	callstd 0x4
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CED::
	loadword 0x0, gJPText_00229A4A
	callstd 0x4
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228CF6::
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228D49
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D2D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D34
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D3B
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D42
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D2D::
	message gJPText_002297B7
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D34::
	message gJPText_002297CD
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D3B::
	message gJPText_002297E0
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D42::
	message gJPText_00229803
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D49::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D57::
	copyvar 0x8000, 0x400E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D88
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D95
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D88
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228D95

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D88::
	loadword 0x0, gJPText_0022982B
	callstd 0x4
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228D9D

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D95::
	loadword 0x0, gJPText_00229A6B
	callstd 0x4

BattleFrontier_BattleDomeBattleRoom_EventScript_00228D9D::
	closemessage
	applymovement 0x2, 0x082294D7
	applymovement 0x1, 0x08229385
	applymovement 0xF, 0x0822931A
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	waitmovement 0x0
	message gJPText_0022988B
	waitmessage
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	copyvar 0x8000, 0x400E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228ED2
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228E45
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228EFF
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_00228E45
	loadword 0x0, gJPText_002298B4
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleDomeBattleRoom_EventScript_00228E45::
	loadword 0x0, gJPText_00229973
	callstd 0x4
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228F8C
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228FAC
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228FAC
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228FC2
	loadword 0x0, gJPText_00229988
	callstd 0x4
	setvar 0x8004, 0xC
	setvar 0x8005, 0x1
	special sub_0818E608
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_00228AEE
	closemessage
	applymovement 0xF, 0x082293B7
	waitmovement 0x0
	loadword 0x0, gJPText_002299DB
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_002299FF
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00229A1C
	callstd 0x4
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228AEE

BattleFrontier_BattleDomeBattleRoom_EventScript_00228ED2::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_00228EFF
	loadword 0x0, gJPText_00229AD4
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattleDomeBattleRoom_EventScript_00228EFF::
	loadword 0x0, gJPText_00229B82
	callstd 0x4
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228F8C
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228FAC
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228FAC
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228FC2
	loadword 0x0, gJPText_00229988
	callstd 0x4
	setvar 0x8004, 0xC
	setvar 0x8005, 0x1
	special sub_0818E608
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00228AEE
	closemessage
	applymovement 0xF, 0x082293B7
	waitmovement 0x0
	loadword 0x0, gJPText_00229BA1
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_00229BEE
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00229C07
	callstd 0x4
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228AEE

BattleFrontier_BattleDomeBattleRoom_EventScript_00228F8C::
	loadword 0x0, gJPText_00229CB7
	callstd 0x4
	closemessage
	applymovement 0xD, 0x08229313
	applymovement 0xF, 0x082293B5
	waitmovement 0x0
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228FCC
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00228FAC::
	loadword 0x0, gJPText_002299B0
	callstd 0x4
	playse 0xDF
	call BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA
	waitse
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228A19

BattleFrontier_BattleDomeBattleRoom_EventScript_00228FC2::
	setvar 0x4002, 0x2
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_00228983

BattleFrontier_BattleDomeBattleRoom_EventScript_00228FCC::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	setvar 0x4009, 0x1
	special DoSpecialTrainerBattle
	setvar 0x4009, 0x0
	setvar 0x8004, 0x11
	special sub_0818E608
	special HealPlayerParty
	setvar 0x8004, 0x10
	special sub_0818E608
	return

BattleFrontier_BattleDomeBattleRoom_MapScriptTable_0022900D::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleDomeBattleRoom_EventScript_00229017
	.2byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_00229017::
	hideobject_at 0xD, 0x1A15
	call BattleFrontier_BattleDomeBattleRoom_EventScript_0022908E
	call BattleFrontier_BattleDomeBattleRoom_EventScript_00228868
	setvar 0x4001, 0x1
	applymovement 0xFF, 0x082292FF
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x3
	goto_if 0x5, BattleFrontier_BattleDomeBattleRoom_EventScript_0022907B
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400E, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_0022907B
	call 0x08222264
	setobjectxyperm 0xF, 0xD, 0x9
	removeobject 0xF
	addobject 0xF
	applymovement 0xF, 0x08229317

BattleFrontier_BattleDomeBattleRoom_EventScript_0022907B::
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_0022907C::
	compare_var_to_value 0x4009, 0x1
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00229088
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_00229088::
	call BattleFrontier_BattleDomeBattleRoom_EventScript_0022908E
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_0022908E::
	compare_var_to_value 0x400F, 0x0
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002290BB
	compare_var_to_value 0x400F, 0x1
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002290BC
	compare_var_to_value 0x400F, 0x2
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_00229120
	compare_var_to_value 0x400F, 0x3
	call_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_002291DE
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_002290BB::
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_002290BC::
	createvobject 0x2E, 0x1, 0x3, 0x0, 0x3, 0x1
	createvobject 0x16, 0x4, 0x6, 0x0, 0x3, 0x1
	createvobject 0x5, 0x6, 0x8, 0x0, 0x3, 0x1
	createvobject 0xC, 0x9, 0xB, 0x0, 0x3, 0x1
	createvobject 0x2E, 0xB, 0xD, 0x0, 0x3, 0x1
	createvobject 0x42, 0xD, 0xF, 0x0, 0x3, 0x1
	createvobject 0x2D, 0x13, 0x7, 0x1, 0x3, 0x1
	createvobject 0x22, 0x16, 0xB, 0x1, 0x3, 0x1
	createvobject 0xB, 0x19, 0xF, 0x1, 0x3, 0x1
	createvobject 0x23, 0x1A, 0x2, 0x2, 0x3, 0x1
	createvobject 0x26, 0x1D, 0x5, 0x1, 0x3, 0x1
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00229120::
	createvobject 0x2E, 0x1, 0x3, 0x0, 0x3, 0x1
	createvobject 0x16, 0x4, 0x6, 0x0, 0x3, 0x1
	createvobject 0x5, 0x6, 0x8, 0x0, 0x3, 0x1
	createvobject 0x14, 0x7, 0x9, 0x0, 0x3, 0x1
	createvobject 0xC, 0x9, 0xB, 0x0, 0x3, 0x1
	createvobject 0x2F, 0xA, 0xC, 0x0, 0x3, 0x1
	createvobject 0x2E, 0xB, 0xD, 0x0, 0x3, 0x1
	createvobject 0x42, 0xD, 0xF, 0x0, 0x3, 0x1
	createvobject 0x30, 0xF, 0x2, 0x1, 0x3, 0x1
	createvobject 0x5, 0x10, 0x3, 0x1, 0x3, 0x1
	createvobject 0x14, 0x11, 0x4, 0x1, 0x3, 0x1
	createvobject 0x2D, 0x13, 0x7, 0x1, 0x3, 0x1
	createvobject 0x16, 0x14, 0x9, 0x1, 0x3, 0x1
	createvobject 0x22, 0x16, 0xB, 0x1, 0x3, 0x1
	createvobject 0x2E, 0x17, 0xD, 0x1, 0x3, 0x1
	createvobject 0xB, 0x19, 0xF, 0x1, 0x3, 0x1
	createvobject 0x23, 0x1A, 0x2, 0x2, 0x3, 0x1
	createvobject 0x28, 0x1C, 0x5, 0x2, 0x3, 0x1
	createvobject 0x26, 0x1D, 0x5, 0x1, 0x3, 0x1
	createvobject 0x53, 0x1E, 0x6, 0x2, 0x3, 0x1
	createvobject 0x22, 0x1F, 0x8, 0x2, 0x3, 0x1
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_002291DE::
	createvobject 0x5, 0x0, 0x2, 0x0, 0x3, 0x1
	createvobject 0x2E, 0x1, 0x3, 0x0, 0x3, 0x1
	createvobject 0x2D, 0x2, 0xF, 0x0, 0x3, 0x1
	createvobject 0x42, 0x3, 0x5, 0x0, 0x3, 0x1
	createvobject 0x16, 0x4, 0x6, 0x0, 0x3, 0x1
	createvobject 0x2E, 0x5, 0x7, 0x0, 0x3, 0x1
	createvobject 0x5, 0x6, 0x8, 0x0, 0x3, 0x1
	createvobject 0x14, 0x7, 0x9, 0x0, 0x3, 0x1
	createvobject 0x18, 0x8, 0xA, 0x0, 0x3, 0x1
	createvobject 0xC, 0x9, 0xB, 0x0, 0x3, 0x1
	createvobject 0x2F, 0xA, 0xC, 0x0, 0x3, 0x1
	createvobject 0x2E, 0xB, 0xD, 0x0, 0x3, 0x1
	createvobject 0x2D, 0xC, 0xE, 0x0, 0x3, 0x1
	createvobject 0x42, 0xD, 0xF, 0x2, 0x3, 0x1
	createvobject 0x37, 0xE, 0xC, 0x2, 0x3, 0x1
	createvobject 0x30, 0xF, 0x2, 0x1, 0x3, 0x1
	createvobject 0x5, 0x10, 0x3, 0x1, 0x3, 0x1
	createvobject 0x14, 0x11, 0x4, 0x1, 0x3, 0x1
	createvobject 0x18, 0x12, 0x6, 0x1, 0x3, 0x1
	createvobject 0x2D, 0x13, 0x7, 0x1, 0x3, 0x1
	createvobject 0x16, 0x14, 0x9, 0x1, 0x3, 0x1
	createvobject 0x17, 0x15, 0xA, 0x1, 0x3, 0x1
	createvobject 0x22, 0x16, 0xB, 0x1, 0x3, 0x1
	createvobject 0x2E, 0x17, 0xD, 0x1, 0x3, 0x1
	createvobject 0x30, 0x18, 0xE, 0x1, 0x3, 0x1
	createvobject 0xB, 0x19, 0xF, 0x1, 0x3, 0x1
	createvobject 0x23, 0x1A, 0x2, 0x2, 0x3, 0x1
	createvobject 0x11, 0x1B, 0x3, 0x2, 0x3, 0x1
	createvobject 0x28, 0x1C, 0x5, 0x2, 0x3, 0x1
	createvobject 0x26, 0x1D, 0x5, 0x1, 0x3, 0x1
	createvobject 0x53, 0x1E, 0x6, 0x2, 0x3, 0x1
	createvobject 0x22, 0x1F, 0x8, 0x2, 0x3, 0x1
	return

	.incbin "baserom_jp.gba", 0x2292ff, 0xbb
BattleFrontier_BattleDomeBattleRoom_EventScript_002293BA::
	turnvobject 0x0, 0x4
	turnvobject 0x2, 0x4
	turnvobject 0x4, 0x4
	turnvobject 0x6, 0x4
	turnvobject 0x8, 0x4
	turnvobject 0xA, 0x3
	turnvobject 0xC, 0x3
	turnvobject 0xE, 0x3
	turnvobject 0x10, 0x3
	turnvobject 0x12, 0x3
	turnvobject 0x14, 0x4
	turnvobject 0x16, 0x4
	turnvobject 0x18, 0x4
	turnvobject 0x1A, 0x4
	turnvobject 0x1C, 0x4
	turnvobject 0x1E, 0x4
	delay 0x14
	turnvobject 0x0, 0x1
	turnvobject 0x2, 0x1
	turnvobject 0x4, 0x1
	turnvobject 0x6, 0x1
	turnvobject 0x8, 0x1
	turnvobject 0xA, 0x1
	turnvobject 0xC, 0x1
	turnvobject 0xE, 0x1
	turnvobject 0x10, 0x1
	turnvobject 0x12, 0x1
	turnvobject 0x14, 0x1
	turnvobject 0x16, 0x1
	turnvobject 0x18, 0x1
	turnvobject 0x1A, 0x1
	turnvobject 0x1C, 0x1
	turnvobject 0x1E, 0x1
	delay 0x14
	turnvobject 0x1, 0x4
	turnvobject 0x3, 0x4
	turnvobject 0x5, 0x4
	turnvobject 0x7, 0x4
	turnvobject 0x9, 0x4
	turnvobject 0xB, 0x3
	turnvobject 0xD, 0x3
	turnvobject 0xF, 0x3
	turnvobject 0x11, 0x3
	turnvobject 0x13, 0x3
	turnvobject 0x15, 0x4
	turnvobject 0x17, 0x4
	turnvobject 0x19, 0x4
	turnvobject 0x1B, 0x3
	turnvobject 0x1F, 0x3
	delay 0x14
	turnvobject 0x1, 0x1
	turnvobject 0x3, 0x1
	turnvobject 0x5, 0x1
	turnvobject 0x7, 0x1
	turnvobject 0x9, 0x1
	turnvobject 0xB, 0x1
	turnvobject 0xD, 0x1
	turnvobject 0xF, 0x1
	turnvobject 0x11, 0x1
	turnvobject 0x13, 0x1
	turnvobject 0x15, 0x1
	turnvobject 0x17, 0x1
	turnvobject 0x19, 0x1
	turnvobject 0x1B, 0x1
	turnvobject 0x1F, 0x1
	delay 0x14
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_00229481::
	copyvar 0x800D, 0x40CE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeBattleRoom_EventScript_0022949B
	warp 0x1A12, 0xFF, 0x5, 0xB
	waitstate
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_0022949B::
	warp 0x1A12, 0xFF, 0x11, 0xB
	waitstate
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_002294A5::
	random 0x2
	copyvar 0x400D, 0x800D
	compare_var_to_value 0x400D, 0x0
	goto_if 0x1, 0x08244178
	setobjectxyperm 0x6, 0x2, 0x0
	setobjectmovementtype 0x6, 0xA
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_002294C4::
	compare_var_to_value 0x400D, 0x0
	goto_if 0x1, 0x08244178
	applymovement 0x6, 0x082294EA
	return

	.incbin "baserom_jp.gba", 0x2294d7, 0x25
	.globl gJPText_002294FC
gJPText_002294FC: @ 0x082294FC
	.string "{MUS_RG_VS_TRAINER}さんの\n"
	.string "にゅうじょう　です！$"

	.globl gJPText_0022950D
gJPText_0022950D: @ 0x0822950D
	.string "{B_COPY_VAR_1}せん！\p"
	.string "{MUS_RG_VS_TRAINER}さん　VS\n"
	.string "{B_COPY_VAR_2}さん\p"
	.string "ただいま　より　はじめます！$"

	.globl gJPText_0022952F
gJPText_0022952F: @ 0x0822952F
	.string "{MUS_RG_VS_TRAINER}さんの　かちです\n"
	.string "おめでとう　ございます！$"

	.globl gJPText_00229547
gJPText_00229547: @ 0x08229547
	.string "{B_COPY_VAR_2}さんの　かちです\n"
	.string "おめでとう　ございます！$"

	.globl gJPText_0022955F
gJPText_0022955F: @ 0x0822955F
	.string "バトルトーナメント　レベル50\n"
	.string "ゆうしょうは　{MUS_RG_VS_TRAINER}さん　です！\l"
	.string "おめでとう　ございます！$"

	.globl gJPText_0022958C
gJPText_0022958C: @ 0x0822958C
	.string "バトルトーナメント　オープンレベル\n"
	.string "ゆうしょうは　{MUS_RG_VS_TRAINER}さん！\l"
	.string "おめでとう　ございます！$"

	.globl gJPText_002295B8
gJPText_002295B8: @ 0x082295B8
	.string "たいへんな　ことに　なりました！\p"
	.string "ダブルノックアウトの　ばあい\n"
	.string "バトルトーナメントの　ルールに　のっとり\l"
	.string "はんていと　なります\p"
	.string "しばらく　おまちください⋯⋯！$"

	.globl gJPText_00229608
gJPText_00229608: @ 0x08229608
	.string "しんぱんいん　より\n"
	.string "はんていの　けっかが　でました！\p"
	.string "しょうしゃは\n"
	.string "なんと！　なんと！　なんと！\l"
	.string "{B_COPY_VAR_1}さん　です！\l"
	.string "おめでとうございます！$"

	.globl gJPText_0022964E
gJPText_0022964E: @ 0x0822964E
	.string "しんぱんいん　より\n"
	.string "はんていの　けっかが　でました！\p"
	.string "しょうしゃは\n"
	.string "なんと！　なんと！　なんと！\l"
	.string "{MUS_RG_VS_TRAINER}さん　です！\l"
	.string "おめでとうございます！$"

	.globl gJPText_00229694
gJPText_00229694: @ 0x08229694
	.string "きたいの　おおがた　しんじん！\p"
	.string "$"

	.globl gJPText_002296A5
gJPText_002296A5: @ 0x082296A5
	.string "さらなる　うえを　めざして！\p"
	.string "$"

	.globl gJPText_002296B5
gJPText_002296B5: @ 0x082296B5
	.string "いっきに　ゆうしょうまで\n"
	.string "のぼりつめて　しまうのでしょうか！？\p"
	.string "$"

	.globl gJPText_002296D6
gJPText_002296D6: @ 0x082296D6
	.string "はつしゅつじょう　はつゆうしょうの\n"
	.string "いぎょう　たっせい　なるか！？\p"
	.string "$"

	.globl gJPText_002296F9
gJPText_002296F9: @ 0x082296F9
	.string "ぜんかいの　リベンジなるか！？\p"
	.string "$"

	.globl gJPText_0022970A
gJPText_0022970A: @ 0x0822970A
	.string "はじめての　ゆうしょうへ　むけて\n"
	.string "もえています！\p"
	.string "$"

	.globl gJPText_00229724
gJPText_00229724: @ 0x08229724
	.string "この　しあいに　かてば\n"
	.string "いよいよ　けっしょうせん　です！\p"
	.string "$"

	.globl gJPText_00229742
gJPText_00229742: @ 0x08229742
	.string "ひがんの　はつゆうしょう　なるか！？\p"
	.string "$"

	.globl gJPText_00229756
gJPText_00229756: @ 0x08229756
	.string "むてきの　チャンピオン！\p"
	.string "$"

	.globl gJPText_00229764
gJPText_00229764: @ 0x08229764
	.string "この　ひとに　かてる　トレーナーは\n"
	.string "はたして　いるのでしょうか！？\p"
	.string "$"

	.globl gJPText_00229787
gJPText_00229787: @ 0x08229787
	.string "この　ひとの　ために\n"
	.string "この　たいかいは　あるのでしょうか！？\p"
	.string "$"

	.globl gJPText_002297A7
gJPText_002297A7: @ 0x082297A7
	.string "はたして　れんぱ　なるか！？\p"
	.string "$"

	.globl gJPText_002297B7
gJPText_002297B7: @ 0x082297B7
	.string "かえってきました！\n"
	.string "もと　チャンピオン！\p"
	.string "$"

	.globl gJPText_002297CD
gJPText_002297CD: @ 0x082297CD
	.string "あの　つよさが　もどってきました！\p"
	.string "$"

	.globl gJPText_002297E0
gJPText_002297E0: @ 0x082297E0
	.string "けっしょうに　すすむのは\n"
	.string "やっぱり　この　ひと　なんでしょうか！？\p"
	.string "$"

	.globl gJPText_00229803
gJPText_00229803: @ 0x08229803
	.string "みごとに　ふっかつ　ゆうしょう　なるか！？\p"
	.string "$"

	.globl gJPText_0022981A
gJPText_0022981A: @ 0x0822981A
	.string "おうじゃの　ふうかく　ただよう！$"

	.globl gJPText_0022982B
gJPText_0022982B: @ 0x0822982B
	.string "そして⋯⋯　{MUS_RG_VS_TRAINER}さんの\n"
	.string "きろくを　はばむ　トレーナーは⋯⋯\p"
	.string "そう⋯⋯　そのなは！！\n"
	.string "バトルドームの　コミッショナーに　して！！\l"
	.string "われらが　ドームスーパースター！！\l"
	.string "ヒース　だぁーーーーーー！$"

	.globl gJPText_0022988B
gJPText_0022988B: @ 0x0822988B
	.string "かんきゃく“ヒースっ！！　ヒースっ！！\n"
	.string "ヒースっ！！　ヒースっ！！　ヒースっ！！$"

	.globl gJPText_002298B4
gJPText_002298B4: @ 0x082298B4
	.string "ヒース“アッハッハッ！！\p"
	.string "きこえるっ？　この　だいかんせい！\n"
	.string "わたしたちの　しあいを　まえに\l"
	.string "みんな　ウズウズ　してるよっ！！\p"
	.string "アッハッハッ！！\p"
	.string "キミは　わたしと　たたかえる\n"
	.string "こうふんと　きんちょうで\l"
	.string "ピクピク　ビクビク　してるねっ！！\p"
	.string "でも　だいじょうぶっ！！\p"
	.string "バトルドームの　いちばんぼしっ！！\n"
	.string "ドームスーパースター　ヒースの　かがやきで\l"
	.string "きみを　てらして　あげる　からっ！！$"

	.globl gJPText_00229973
gJPText_00229973: @ 0x08229973
	.string "キミの　せんりゃく！　みせて　ごらんっ！$"

	.globl gJPText_00229988
gJPText_00229988: @ 0x08229988
	.string "なんとーーー！　なんとーーーっ！\n"
	.string "たたかいに　かったのは\l"
	.string "{MUS_RG_VS_TRAINER}さんだぁーーー！$"

	.globl gJPText_002299B0
gJPText_002299B0: @ 0x082299B0
	.string "ドームスーパースター！！\n"
	.string "ヒースの　しょうりです！\p"
	.string "おめでとうーーーー！　ヒース！！$"

	.globl gJPText_002299DB
gJPText_002299DB: @ 0x082299DB
	.string "ヒース“きまり　だからねっ！\n"
	.string "キミの　フロンティアパスを　かしてっ！！$"

	.globl gJPText_002299FF
gJPText_002299FF: @ 0x082299FF
	.string "フロンティアパスに\n"
	.string "タクティクスシンボルが　きざまれた！$"

	.globl gJPText_00229A1C
gJPText_00229A1C: @ 0x08229A1C
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "わたしは　キミを　ごかい　してたよ\n"
	.string "つぎは　こうは　いかない　からね⋯⋯$"

	.globl gJPText_00229A4A
gJPText_00229A4A: @ 0x08229A4A
	.string "どこまで　かちつづける　つもり　なのか？\n"
	.string "かんろく　じゅうぶん！$"

	.globl gJPText_00229A6B
gJPText_00229A6B: @ 0x08229A6B
	.string "⋯⋯　そして　みなさーーーーん！！\p"
	.string "ついに！　ついに　あのトレーナーが\n"
	.string "かえって　きたぞーーー！\p"
	.string "そう⋯⋯　その　トレーナーの　なはーーー\n"
	.string "われらが　ドームスーパースターーーー！！\l"
	.string "ヒース　だぁーーーーーー！$"

	.globl gJPText_00229AD4
gJPText_00229AD4: @ 0x08229AD4
	.string "ヒース“われるような　かんせい⋯⋯\n"
	.string "むせかえる　ような　ねっき⋯⋯\l"
	.string "やっぱり　ここは　すばらしいよ⋯⋯\p"
	.string "⋯⋯　わたしは　ドームスーパースター⋯⋯\n"
	.string "みんなの　きたいと　あこがれの　ほし⋯⋯\l"
	.string "ながれ　きえさる　ことなど　できない⋯⋯\p"
	.string "もっと　ひかりっ！　もっと　かがやいてっ！\n"
	.string "ここに　やってくる　すべての　ひとびとを\l"
	.string "てらさなければ　いけないっ！！$"

	.globl gJPText_00229B82
gJPText_00229B82: @ 0x08229B82
	.string "さあっ！　わたしの　すべてっ！\n"
	.string "ここに　ひろう　するよっ！！$"

	.globl gJPText_00229BA1
gJPText_00229BA1: @ 0x08229BA1
	.string "ヒース“ほーんと　ステキっ！　キミはっ！！\p"
	.string "すべてを　だしきった　わたしが\n"
	.string "かなわない　なんて　はじめてっ！！\p"
	.string "さあっ！　キミの　フロンティアパスを！！$"

	.globl gJPText_00229BEE
gJPText_00229BEE: @ 0x08229BEE
	.string "タクティクスシンボルが\n"
	.string "きんいろに　かがやいた！$"

	.globl gJPText_00229C07
gJPText_00229C07: @ 0x08229C07
	.string "つよく！　なにより　かわいい　キミっ！！\p"
	.string "キミには　わたしの　ような\n"
	.string "スーパースターに　なれる\l"
	.string "かのうせいを　かんじるよっ！\l"
	.string "また　あえるときを　たのしみに　しようっ！！$"

	.incbin "baserom_jp.gba", 0x229c5d, 0x5a
	.globl gJPText_00229CB7
gJPText_00229CB7: @ 0x08229CB7
	.string "けっしょうせん！\p"
	.string "{MUS_RG_VS_TRAINER}さん　VS\n"
	.string "ドームスーパースター　ヒース\p"
	.string "ただいま　より　はじめます！$"

	.globl gJPText_00229CE6
gJPText_00229CE6: @ 0x08229CE6
	.string "しんぱんいん　より\n"
	.string "はんていの　けっかが　でました！\p"
	.string "しょうしゃは\n"
	.string "なんと！　なんと！　なんと！\l"
	.string "われらの　スーパースター！　ヒース　です！\p"
	.string "おめでとう！　そして　ありがとう！！\n"
	.string "われらの　ドームスーパースター　ヒース！！$"

