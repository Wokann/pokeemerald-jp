@ ShoalCave_LowTideEntranceRoom scripts (JP map g24 m46 @ 0x08219E85)

ShoalCave_LowTideEntranceRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideEntranceRoom_EventScript_00219E8B
	.byte 0

ShoalCave_LowTideEntranceRoom_EventScript_00219E8B::
	special UpdateShoalTideFlag
	checkflag 0x89A
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219E9C
	goto ShoalCave_LowTideEntranceRoom_EventScript_00219EA0

ShoalCave_LowTideEntranceRoom_EventScript_00219E9C::
	setmaplayoutindex 0xA8
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219EA0::
	setmaplayoutindex 0xA4
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219EA4::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x8BF
	call_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219FA4
	checkitem 0x2E, 0x4
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F66
	checkitem 0x2F, 0x4
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F66
	loadword 0x0, 0x08264111
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F9A
	checkitemspace 0xDB, 0x1
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F34
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F5C
	loadword 0x0, 0x0826414B
	callstd 0x4
	removeitem 0x2E, 0x4
	removeitem 0x2F, 0x4
	setorcopyvar 0x8000, 0xDB
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	loadword 0x0, 0x0826417E
	callstd 0x4
	setflag 0x2
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219F34::
	checkitem 0x2E, 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F45
	return

ShoalCave_LowTideEntranceRoom_EventScript_00219F45::
	checkitem 0x2F, 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F56
	return

ShoalCave_LowTideEntranceRoom_EventScript_00219F56::
	setvar 0x800D, 0x2
	return

ShoalCave_LowTideEntranceRoom_EventScript_00219F5C::
	loadword 0x0, 0x082641FE
	callstd 0x4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219F66::
	checkitem 0x2E, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F90
	checkitem 0x2F, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, ShoalCave_LowTideEntranceRoom_EventScript_00219F90
	loadword 0x0, 0x0826406F
	callstd 0x4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219F90::
	loadword 0x0, 0x082640C5
	callstd 0x4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219F9A::
	loadword 0x0, 0x082641E5
	callstd 0x4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_00219FA4::
	clearflag 0x3B8
	clearflag 0x3B9
	clearflag 0x3BA
	clearflag 0x3BB
	clearflag 0x3BC
	clearflag 0x3BD
	clearflag 0x3BE
	clearflag 0x3BF
	clearflag 0x8BF
	return

