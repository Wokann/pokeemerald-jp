@ BattleFrontier_BattleTowerCorridor scripts (JP map g26 m7 @ 0x08221BA3)

BattleFrontier_BattleTowerCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BattleFrontier_BattleTowerCorridor_EventScript_00221BAE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerCorridor_MapScriptTable_00221BDF
	.byte 0

BattleFrontier_BattleTowerCorridor_EventScript_00221BAE::
	compare_var_to_value 0x8006, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerCorridor_EventScript_00221BCC
	setmetatile 0xC, 0x0, 0x207, 0x0
	setmetatile 0xC, 0x1, 0x20F, 0x0
	end

BattleFrontier_BattleTowerCorridor_EventScript_00221BCC::
	setmetatile 0xF, 0x0, 0x207, 0x0
	setmetatile 0xF, 0x1, 0x20F, 0x0
	end

BattleFrontier_BattleTowerCorridor_MapScriptTable_00221BDF::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerCorridor_EventScript_00221BE9
	.2byte 0

BattleFrontier_BattleTowerCorridor_EventScript_00221BE9::
	setvar 0x4000, 0x1
	compare_var_to_value 0x8006, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerCorridor_EventScript_00221C0F
	applymovement 0x1, 0x08221C33
	applymovement 0xFF, 0x08221C32
	waitmovement 0x0
	goto BattleFrontier_BattleTowerCorridor_EventScript_00221C20

BattleFrontier_BattleTowerCorridor_EventScript_00221C0F::
	applymovement 0x1, 0x08221C30
	applymovement 0xFF, 0x08221C2F
	waitmovement 0x0

BattleFrontier_BattleTowerCorridor_EventScript_00221C20::
	setvar 0x4000, 0x0
	warp 0x1A08, 0xFF, 0x4, 0x8
	waitstate
	end
