@ SouthernIsland_Exterior scripts (JP map g26 m9 @ 0x08222765)

SouthernIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Exterior_EventScript_0022276B
	.byte 0

SouthernIsland_Exterior_EventScript_0022276B::
	setflag 0x8A9
	end

SouthernIsland_Exterior_EventScript_0022276F::
	lock
	faceplayer
	loadword 0x0, 0x0826354C
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SouthernIsland_Exterior_EventScript_002227B4
	loadword 0x0, 0x0826356A
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	hideobject_at 0x1, 0x1A09
	setvar 0x8004, 0x2
	call 0x082432D3
	warp 0xD0A, 0xFF, 0x8, 0xB
	waitstate
	release
	end

SouthernIsland_Exterior_EventScript_002227B4::
	loadword 0x0, 0x08263578
	callstd 0x4
	release
	end

Ferry_EventScript_DepartIslandSouth:
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardSouth
	waitmovement 0
	return

Ferry_EventScript_DepartIslandWest:
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardWest
	waitmovement 0
	return

Ferry_Movement_DepartIslandBoardSouth:
	walk_down
	step_end

Ferry_Movement_DepartIslandBoardWest:
	walk_left
	walk_in_place_faster_down
	step_end

SouthernIsland_Exterior_EventScript_002227D9::
	loadword 0x0, 0x082635AF
	callstd 0x3
	end
