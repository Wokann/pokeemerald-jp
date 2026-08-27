@ FarawayIsland_Entrance scripts (JP map g26 m56 @ 0x0823B35C)

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_EventScript_0023B362
	.byte 0

FarawayIsland_Entrance_EventScript_0023B362::
	setflag 0x8D8
	end

FarawayIsland_Entrance_EventScript_0023B366::
	setweather 0x1
	resetweather
	end

FarawayIsland_Entrance_EventScript_0023B36B::
	setweather 0x0
	resetweather
	end

FarawayIsland_Entrance_EventScript_0023B370::
	lock
	faceplayer
	loadword 0x0, 0x08275DA5
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, FarawayIsland_Entrance_EventScript_0023B3B5
	loadword 0x0, 0x0826356A
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	hideobject_at 0x1, 0x1A38
	setvar 0x8004, 0x2
	call Common_EventScript_FerryDepartIsland
	warp 0xD0A, 0xFF, 0x8, 0xB
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_0023B3B5::
	loadword 0x0, 0x08263578
	callstd 0x4
	release
	end

FarawayIsland_Entrance_EventScript_0023B3BF::
	loadword 0x0, 0x08275ED9
	callstd 0x3
	end
