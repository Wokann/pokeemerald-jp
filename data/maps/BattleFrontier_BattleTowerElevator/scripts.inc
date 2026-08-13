@ BattleFrontier_BattleTowerElevator scripts (JP map g26 m6 @ 0x08221AD4)

BattleFrontier_BattleTowerElevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerElevator_MapScriptTable_00221ADF
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerElevator_MapScriptTable_00221B8F
	.byte 0

BattleFrontier_BattleTowerElevator_MapScriptTable_00221ADF::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerElevator_EventScript_00221AE9
	.2byte 0

BattleFrontier_BattleTowerElevator_EventScript_00221AE9::
	setvar 0x4000, 0x1
	applymovement 0x1, 0x08221B7F
	applymovement 0xFF, 0x08221B83
	waitmovement 0x0
	special sub_0813A0BC
	waitse
	special ShakeScreenInElevator
	waitstate
	delay 0x30
	applymovement 0x1, 0x08221B87
	applymovement 0xFF, 0x08221B8B
	waitmovement 0x0
	call BattleFrontier_BattleTowerElevator_EventScript_00221B21
	end

BattleFrontier_BattleTowerElevator_EventScript_00221B21::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerElevator_EventScript_00221B4E
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerElevator_EventScript_00221B4E
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerElevator_EventScript_00221B58
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerElevator_EventScript_00221B6B
	return

BattleFrontier_BattleTowerElevator_EventScript_00221B4E::
	warp 0x1A07, 0xFF, 0x8, 0x1
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_00221B58::
	checkflag 0x152
	goto_if 0x0, BattleFrontier_BattleTowerElevator_EventScript_00221B75
	warp 0x1A10, 0xFF, 0x7, 0x2
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_00221B6B::
	warp 0x1A10, 0xFF, 0x7, 0x2
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_00221B75::
	warp 0x1A0F, 0xFF, 0xA, 0x1
	waitstate
	return

	.incbin "baserom_jp.gba", 0x221b7f, 0x10
BattleFrontier_BattleTowerElevator_MapScriptTable_00221B8F::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerElevator_EventScript_00221B99
	.2byte 0

BattleFrontier_BattleTowerElevator_EventScript_00221B99::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

