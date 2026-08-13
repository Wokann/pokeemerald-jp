@ ShoalCave_LowTideStairsRoom scripts (JP map g24 m48 @ 0x0821A1C5)

ShoalCave_LowTideStairsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideStairsRoom_EventScript_0021A1CB
	.byte 0

ShoalCave_LowTideStairsRoom_EventScript_0021A1CB::
	call ShoalCave_LowTideStairsRoom_EventScript_0021A1D1
	end

ShoalCave_LowTideStairsRoom_EventScript_0021A1D1::
	checkflag 0x3BA
	goto_if 0x1, ShoalCave_LowTideStairsRoom_EventScript_0021A1E4
	setmetatile 0xB, 0xB, 0x358, 0x1
	return

ShoalCave_LowTideStairsRoom_EventScript_0021A1E4::
	return

ShoalCave_LowTideStairsRoom_EventScript_0021A1E5::
	lockall
	checkflag 0x3BA
	goto_if 0x1, ShoalCave_LowTideStairsRoom_EventScript_0021A217
	setorcopyvar 0x8000, 0x2E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0xB, 0xB, 0x35A, 0x0
	special DrawWholeMapView
	setflag 0x3BA
	releaseall
	end

ShoalCave_LowTideStairsRoom_EventScript_0021A217::
	loadword 0x0, 0x0826422C
	callstd 0x4
	releaseall
	end

