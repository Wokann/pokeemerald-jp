@ BattleFrontier_BattleDomeCorridor scripts (JP map g26 m19 @ 0x08227EC9)

BattleFrontier_BattleDomeCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_MapScriptTable_00227ECF
	.byte 0

BattleFrontier_BattleDomeCorridor_MapScriptTable_00227ECF::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleDomeCorridor_EventScript_00227ED9
	.2byte 0

BattleFrontier_BattleDomeCorridor_EventScript_00227ED9::
	delay 0x10
	setvar 0x4000, 0x1
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeCorridor_EventScript_00227F2C
	applymovement 0x1, 0x08227F7D
	applymovement 0xFF, 0x08227F6C
	waitmovement 0x0
	opendoor 0xD, 0x3
	waitmoncry
	applymovement 0x1, 0x08227F89
	applymovement 0xFF, 0x08227F79
	waitmovement 0x0
	closedoor 0xD, 0x3
	waitmoncry
	goto BattleFrontier_BattleDomeCorridor_EventScript_00227F5A

BattleFrontier_BattleDomeCorridor_EventScript_00227F2C::
	applymovement 0x1, 0x08227FA1
	applymovement 0xFF, 0x08227F8C
	waitmovement 0x0
	opendoor 0x25, 0x3
	waitmoncry
	applymovement 0x1, 0x08227FB1
	applymovement 0xFF, 0x08227F9D
	waitmovement 0x0
	closedoor 0x25, 0x3
	waitmoncry

BattleFrontier_BattleDomeCorridor_EventScript_00227F5A::
	waitmovement 0x0
	setvar 0x8006, 0x0
	warp 0x1A14, 0xFF, 0x5, 0x7
	waitstate
	end
