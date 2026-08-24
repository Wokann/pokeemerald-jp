@ BattleFrontier_BattlePyramidTop scripts (JP map g26 m27 @ 0x0822E9A2)

BattleFrontier_BattlePyramidTop_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_EventScript_0022E9F5
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_MapScriptTable_0022EA6F
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_EventScript_0022E9B7
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_MapScriptTable_0022E9CF
	.byte 0

BattleFrontier_BattlePyramidTop_EventScript_0022E9B7::
	setvar 0x8004, 0xD
	setvar 0x8005, 0xC8
	setvar 0x8006, 0x0
	special CallBattlePyramidFunction
	setvar 0x400F, 0x1
	end

BattleFrontier_BattlePyramidTop_MapScriptTable_0022E9CF::
	map_script_2 0x4001, 0x0, BattleFrontier_BattlePyramidTop_EventScript_0022E9D9
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_0022E9D9::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	compare_var_to_value 0x400C, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidTop_EventScript_0022E9F4
	setobjectxyperm 0x2, 0x0, 0x0

BattleFrontier_BattlePyramidTop_EventScript_0022E9F4::
	end

BattleFrontier_BattlePyramidTop_EventScript_0022E9F5::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EA0D
	call 0x08222264

BattleFrontier_BattlePyramidTop_EventScript_0022EA0D::
	copyvar 0x400C, 0x800D
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x4000
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EA94
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x0822D62F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EA94
	setvar 0x8004, 0x1
	setvar 0x8005, 0x5
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x0822D60B
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, 0x0822D60B
	compare_var_to_value 0x800D, 0x9
	goto_if 0x1, 0x0822D60B
	end

BattleFrontier_BattlePyramidTop_MapScriptTable_0022EA6F::
	map_script_2 0x400E, 0x0, BattleFrontier_BattlePyramidTop_EventScript_0022EA81
	map_script_2 0x400F, 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EA8B
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_0022EA81::
	playbgm 0x1CE, 0x0
	setvar 0x400E, 0x1
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EA8B::
	special ShowMapNamePopup
	setvar 0x400F, 0x0
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EA94::
	setvar 0x8004, 0x3
	setvar 0x8005, 0x1
	special CallBattlePyramidFunction
	special SavePlayerParty
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x9
	special CallBattlePyramidFunction
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	setvar 0x400F, 0x1
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EAD1::
	lock
	faceplayer
	compare_var_to_value 0x400D, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidTop_EventScript_0022EB37
	compare_var_to_value 0x400C, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidTop_EventScript_0022EB41
	loadword 0x0, 0x0822ED11
	callstd 0x4
	closemessage
	applymovement 0x1, 0x0822ECFE
	waitmovement 0x0
	applymovement 0xFF, 0x0822ED04
	waitmovement 0x0
	applymovement 0x1, 0x0822ED01
	waitmovement 0x0
	message 0x0822ED8A
	waitmessage
	playfanfare 0x1CB
	waitfanfare
	closemessage

BattleFrontier_BattlePyramidTop_EventScript_0022EB1B::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	warp 0x1A19, 0xFF, 0x7, 0xD
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EB37::
	loadword 0x0, 0x0822F1A5
	callstd 0x4
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EB41::
	loadword 0x0, 0x0822EDA6
	callstd 0x4
	applymovement 0x1, 0x0822ECFE
	setvar 0x400D, 0x1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EB57::
	lockall
	copyvar 0x8000, 0x400C
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EC36
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EBD1
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EC89
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidTop_EventScript_0022EBD1
	special SpawnCameraObject
	applymovement 0x7F, 0x0822ED0D
	waitmovement 0x0
	loadword 0x0, 0x0822EE63
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	applymovement 0x2, 0x0822ED0B
	waitmovement 0x0
	loadword 0x0, 0x0822EECD
	callstd 0x4
	goto BattleFrontier_BattlePyramidTop_EventScript_0022EBDB
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EBD1::
	applymovement 0x2, 0x0822ED0B
	waitmovement 0x0

BattleFrontier_BattlePyramidTop_EventScript_0022EBDB::
	loadword 0x0, 0x0822EF6A
	callstd 0x4
	call BattleFrontier_BattlePyramidTop_EventScript_0022ECEE
	playbgm 0x1CE, 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EBFC
	goto 0x0822D60B

BattleFrontier_BattlePyramidTop_EventScript_0022EBFC::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidTop_EventScript_0022EB1B
	loadword 0x0, 0x0822EF86
	callstd 0x4
	playfanfare 0x1D2
	message 0x0822EFC9
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822EFE4
	callstd 0x4
	goto BattleFrontier_BattlePyramidTop_EventScript_0022EB1B

BattleFrontier_BattlePyramidTop_EventScript_0022EC36::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidTop_EventScript_0022EC89
	special SpawnCameraObject
	applymovement 0x7F, 0x0822ED0D
	waitmovement 0x0
	loadword 0x0, 0x0822F005
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	applymovement 0x2, 0x0822ED0B
	waitmovement 0x0
	loadword 0x0, 0x0822F0B0
	callstd 0x4
	goto BattleFrontier_BattlePyramidTop_EventScript_0022EC93
	end

BattleFrontier_BattlePyramidTop_EventScript_0022EC89::
	applymovement 0x2, 0x0822ED0B
	waitmovement 0x0

BattleFrontier_BattlePyramidTop_EventScript_0022EC93::
	loadword 0x0, 0x0822F0D1
	callstd 0x4
	call BattleFrontier_BattlePyramidTop_EventScript_0022ECEE
	playbgm 0x1CE, 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022ECB4
	goto 0x0822D60B

BattleFrontier_BattlePyramidTop_EventScript_0022ECB4::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidTop_EventScript_0022EB1B
	loadword 0x0, 0x0822F0EE
	callstd 0x4
	playfanfare 0x1D2
	message 0x0822F14D
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822F164
	callstd 0x4
	goto BattleFrontier_BattlePyramidTop_EventScript_0022EB1B

BattleFrontier_BattlePyramidTop_EventScript_0022ECEE::
	closemessage
	setvar 0x8004, 0xA
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	return
