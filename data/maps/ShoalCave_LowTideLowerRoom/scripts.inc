@ ShoalCave_LowTideLowerRoom scripts (JP map g24 m49 @ 0x0821A221)

ShoalCave_LowTideLowerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_EventScript_0021A227
	.byte 0

ShoalCave_LowTideLowerRoom_EventScript_0021A227::
	call ShoalCave_LowTideLowerRoom_EventScript_0021A22D
	end

ShoalCave_LowTideLowerRoom_EventScript_0021A22D::
	checkflag 0x3BB
	goto_if 0x1, ShoalCave_LowTideLowerRoom_EventScript_0021A240
	setmetatile 0x12, 0x2, 0x358, 0x1
	return

ShoalCave_LowTideLowerRoom_EventScript_0021A240::
	return

ShoalCave_LowTideLowerRoom_EventScript_0021A241::
	lockall
	checkflag 0x3BB
	goto_if 0x1, ShoalCave_LowTideLowerRoom_EventScript_0021A273
	setorcopyvar 0x8000, 0x2E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setmetatile 0x12, 0x2, 0x35A, 0x0
	special DrawWholeMapView
	setflag 0x3BB
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_0021A273::
	loadword 0x0, 0x0826422C
	callstd 0x4
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_0021A27D::
	lock
	faceplayer
	checkflag 0x11B
	goto_if 0x1, ShoalCave_LowTideLowerRoom_EventScript_0021A2AC
	loadword 0x0, 0x0821A2B6
	callstd 0x4
	setorcopyvar 0x8000, 0xC4
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x11B
	release
	end

ShoalCave_LowTideLowerRoom_EventScript_0021A2AC::
	loadword 0x0, 0x0821A312
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x21a2b6, 0x70
