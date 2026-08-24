@ Route112_CableCarStation scripts (JP map g19 m0 @ 0x08211F0A)

Route112_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_EventScript_00211F15
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_MapScriptTable_00211F35
	.byte 0

Route112_CableCarStation_EventScript_00211F15::
	setescapewarp 0x1B, 0xFF, 0x1C, 0x1C
	compare_var_to_value 0x40A3, 0x2
	call_if 0x1, Route112_CableCarStation_EventScript_00211F29
	end

Route112_CableCarStation_EventScript_00211F29::
	setobjectxyperm 0x1, 0x7, 0x4
	setobjectmovementtype 0x1, 0x9
	return

Route112_CableCarStation_MapScriptTable_00211F35::
	map_script_2 0x40A3, 0x2, Route112_CableCarStation_EventScript_00211F3F
	.2byte 0

Route112_CableCarStation_EventScript_00211F3F::
	lockall
	applymovement 0xFF, 0x08211FCC
	applymovement 0x1, 0x08211FC2
	waitmovement 0x0
	setvar 0x40A3, 0x0
	setobjectxyperm 0x1, 0x6, 0x7
	setobjectmovementtype 0x1, 0x8
	releaseall
	end

Route112_CableCarStation_EventScript_00211F63::
	lock
	faceplayer
	loadword 0x0, 0x08211FD1
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route112_CableCarStation_EventScript_00211F84
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route112_CableCarStation_EventScript_00211FB3
	end

Route112_CableCarStation_EventScript_00211F84::
	loadword 0x0, 0x08211FF8
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08211FBD
	applymovement 0xFF, 0x08211FC7
	waitmovement 0x0
	setvar 0x8004, 0x0
	setvar 0x40A3, 0x1
	incrementgamestat 0x30
	special CableCarWarp
	special CableCar
	release
	end

Route112_CableCarStation_EventScript_00211FB3::
	loadword 0x0, 0x08212005
	callstd 0x4
	release
	end
