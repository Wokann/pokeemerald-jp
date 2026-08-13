@ ShoalCave_LowTideInnerRoom scripts (JP map g24 m47 @ 0x08219FC0)

ShoalCave_LowTideInnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideInnerRoom_EventScript_00219FE1
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideInnerRoom_EventScript_00219FCB
	.byte 0

ShoalCave_LowTideInnerRoom_EventScript_00219FCB::
	checkflag 0x89A
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_00219FD9
	goto ShoalCave_LowTideInnerRoom_EventScript_00219FDD

ShoalCave_LowTideInnerRoom_EventScript_00219FD9::
	setmaplayoutindex 0xA9
	end

ShoalCave_LowTideInnerRoom_EventScript_00219FDD::
	setmaplayoutindex 0xA5
	end

ShoalCave_LowTideInnerRoom_EventScript_00219FE1::
	call ShoalCave_LowTideInnerRoom_EventScript_00219FE7
	end

ShoalCave_LowTideInnerRoom_EventScript_00219FE7::
	checkflag 0x3B8
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A008
	checkflag 0x89A
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A008
	setmetatile 0x1F, 0x8, 0x358, 0x1
	goto ShoalCave_LowTideInnerRoom_EventScript_0021A008
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A008::
	checkflag 0x3B9
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A029
	checkflag 0x89A
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A029
	setmetatile 0xE, 0x1A, 0x358, 0x1
	goto ShoalCave_LowTideInnerRoom_EventScript_0021A029
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A029::
	checkflag 0x3BC
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A041
	setmetatile 0x29, 0x14, 0x359, 0x1
	goto ShoalCave_LowTideInnerRoom_EventScript_0021A041
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A041::
	checkflag 0x3BD
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A059
	setmetatile 0x29, 0xA, 0x359, 0x1
	goto ShoalCave_LowTideInnerRoom_EventScript_0021A059
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A059::
	checkflag 0x3BE
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A071
	setmetatile 0x6, 0x9, 0x359, 0x1
	goto ShoalCave_LowTideInnerRoom_EventScript_0021A071
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A071::
	checkflag 0x3BF
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A084
	setmetatile 0x10, 0xD, 0x359, 0x1
	return

ShoalCave_LowTideInnerRoom_EventScript_0021A084::
	return

ShoalCave_LowTideInnerRoom_EventScript_0021A085::
	lockall
	checkflag 0x3BC
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A0B7
	setorcopyvar 0x8000, 0x2F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0x29, 0x14, 0x35B, 0x0
	special DrawWholeMapView
	setflag 0x3BC
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A0B7::
	loadword 0x0, 0x0826424A
	callstd 0x4
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A0C1::
	lockall
	checkflag 0x3BD
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A0B7
	setorcopyvar 0x8000, 0x2F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0x29, 0xA, 0x35B, 0x0
	special DrawWholeMapView
	setflag 0x3BD
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A0F3::
	lockall
	checkflag 0x3BE
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A0B7
	setorcopyvar 0x8000, 0x2F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0x6, 0x9, 0x35B, 0x0
	special DrawWholeMapView
	setflag 0x3BE
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A125::
	lockall
	checkflag 0x3BF
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A0B7
	setorcopyvar 0x8000, 0x2F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0x10, 0xD, 0x35B, 0x0
	special DrawWholeMapView
	setflag 0x3BF
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A157::
	lockall
	checkflag 0x3B8
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A189
	setorcopyvar 0x8000, 0x2E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0x1F, 0x8, 0x35A, 0x0
	special DrawWholeMapView
	setflag 0x3B8
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A189::
	loadword 0x0, 0x0826422C
	callstd 0x4
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_0021A193::
	lockall
	checkflag 0x3B9
	goto_if 0x1, ShoalCave_LowTideInnerRoom_EventScript_0021A189
	setorcopyvar 0x8000, 0x2E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0xE, 0x1A, 0x35A, 0x0
	special DrawWholeMapView
	setflag 0x3B9
	releaseall
	end

