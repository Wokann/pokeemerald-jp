@ BattleFrontier_BattleTowerMultiCorridor scripts (JP map g26 m16 @ 0x08226400)

BattleFrontier_BattleTowerMultiCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226410
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiCorridor_MapScriptTable_0022644B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiCorridor_MapScriptTable_00226468
	.byte 0

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226410::
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226427
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226447
	end

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226427::
	setvar 0x8004, 0xE
	special sub_08161E88
	checkplayergender
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226441
	setvar 0x401F, 0x0
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226441::
	setvar 0x401F, 0x59
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226447::
	special sub_0813A774
	return

BattleFrontier_BattleTowerMultiCorridor_MapScriptTable_0022644B::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226455
	.2byte 0

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226455::
	hideobject_at 0xFF, 0x1A10
	hideobject_at 0x1, 0x1A10
	hideobject_at 0x4, 0x1A10
	special sub_081399F4
	end

BattleFrontier_BattleTowerMultiCorridor_MapScriptTable_00226468::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226472
	.2byte 0

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226472::
	lockall
	setflag 0x4002
	setvar 0x8004, 0xE
	setvar 0x8005, 0x1
	opendoor 0x1, 0x1
	waitmoncry
	clearflag 0x4002
	showobject_at 0x1, 0x1A10
	showobject_at 0x4, 0x1A10
	applymovement 0x1, 0x0822659C
	applymovement 0x4, 0x0822659C
	waitmovement 0x0
	setflag 0x4002
	setvar 0x8004, 0xE
	setvar 0x8005, 0x1
	closedoor 0x1, 0x1
	waitmoncry
	clearflag 0x4002
	applymovement 0x1, 0x08226572
	applymovement 0x4, 0x0822657A
	applymovement 0x3, 0x08226582
	applymovement 0x2, 0x0822658B
	waitmovement 0x0
	delay 0x28
	applymovement 0x3, 0x08243629
	applymovement 0x2, 0x08243629
	waitmovement 0x0
	opendoor 0x7, 0x1
	waitmoncry
	applymovement 0x3, 0x08226599
	applymovement 0x2, 0x08226599
	applymovement 0x1, 0x08226594
	applymovement 0x4, 0x08226594
	waitmovement 0x0
	closedoor 0x7, 0x1
	waitmoncry
	delay 0x1E
	setvar 0x4001, 0x1
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_00226527
	releaseall
	end

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226527::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226554
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226554
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_0022655E
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerMultiCorridor_EventScript_00226568
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226554::
	warp 0x1A08, 0xFF, 0x4, 0x8
	waitstate
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_0022655E::
	warp 0x1A11, 0xFF, 0x4, 0x5
	waitstate
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_00226568::
	warp 0x1A11, 0xFF, 0x4, 0x5
	waitstate
	return

	.incbin "baserom_jp.gba", 0x226572, 0x2c
