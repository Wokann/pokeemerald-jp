@ SootopolisCity_Gym_1F scripts (JP map g15 m0 @ 0x0820E224)

SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_MapScriptTable_0020E2A3
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_EventScript_0020E23F
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_EventScript_0020E242
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_EventScript_0020E239
	.byte 0

SootopolisCity_Gym_1F_EventScript_0020E239::
	setvar 0x4022, 0x1
	end

SootopolisCity_Gym_1F_EventScript_0020E23F::
	setstepcallback 0x4
	end

SootopolisCity_Gym_1F_EventScript_0020E242::
	call SootopolisCity_Gym_1F_EventScript_0020E24B
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_0020E24B::
	compare_var_to_value 0x4022, 0x8
	goto_if 0x0, SootopolisCity_Gym_1F_EventScript_0020E2A2
	compare_var_to_value 0x4022, 0x1C
	goto_if 0x0, SootopolisCity_Gym_1F_EventScript_0020E290
	compare_var_to_value 0x4022, 0x43
	goto_if 0x0, SootopolisCity_Gym_1F_EventScript_0020E27E
	setmetatile 0x8, 0x4, 0x207, 0x0
	setmetatile 0x8, 0x5, 0x207, 0x0

SootopolisCity_Gym_1F_EventScript_0020E27E::
	setmetatile 0x8, 0xA, 0x207, 0x0
	setmetatile 0x8, 0xB, 0x207, 0x0

SootopolisCity_Gym_1F_EventScript_0020E290::
	setmetatile 0x8, 0xF, 0x207, 0x0
	setmetatile 0x8, 0x10, 0x207, 0x0

SootopolisCity_Gym_1F_EventScript_0020E2A2::
	return

SootopolisCity_Gym_1F_MapScriptTable_0020E2A3::
	map_script_2 0x4022, 0x8, SootopolisCity_Gym_1F_EventScript_0020E2C5
	map_script_2 0x4022, 0x1C, SootopolisCity_Gym_1F_EventScript_0020E2D9
	map_script_2 0x4022, 0x43, SootopolisCity_Gym_1F_EventScript_0020E2ED
	map_script_2 0x4022, 0x0, SootopolisCity_Gym_1F_EventScript_0020E301
	.2byte 0

SootopolisCity_Gym_1F_EventScript_0020E2C5::
	addvar 0x4022, 0x1
	delay 0x28
	playse 0x28
	call SootopolisCity_Gym_1F_EventScript_0020E24B
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_0020E2D9::
	addvar 0x4022, 0x1
	delay 0x28
	playse 0x28
	call SootopolisCity_Gym_1F_EventScript_0020E24B
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_0020E2ED::
	addvar 0x4022, 0x1
	delay 0x28
	playse 0x28
	call SootopolisCity_Gym_1F_EventScript_0020E24B
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_0020E301::
	lockall
	delay 0x14
	applymovement 0xFF, 0x0820E31A
	waitmovement 0x0
	playse 0x2B
	delay 0x3C
	warphole 0xF01
	waitstate
	end

	.incbin "baserom_jp.gba", 0x20e31a, 0xfe
SootopolisCity_Gym_1F_EventScript_0020E418::
	lock
	faceplayer
	checkflag 0x4F7
	goto_if 0x1, SootopolisCity_Gym_1F_EventScript_0020E42D
	loadword 0x0, 0x0820E46B
	callstd 0x4
	release
	end

SootopolisCity_Gym_1F_EventScript_0020E42D::
	loadword 0x0, 0x0820E50B
	callstd 0x4
	release
	end

SootopolisCity_Gym_1F_EventScript_0020E437::
	lockall
	checkflag 0x86E
	goto_if 0x1, SootopolisCity_Gym_1F_EventScript_0020E457
	goto SootopolisCity_Gym_1F_EventScript_0020E461
	end

SootopolisCity_Gym_1F_EventScript_0020E447::
	lockall
	checkflag 0x86E
	goto_if 0x1, SootopolisCity_Gym_1F_EventScript_0020E457
	goto SootopolisCity_Gym_1F_EventScript_0020E461
	end

SootopolisCity_Gym_1F_EventScript_0020E457::
	loadword 0x0, 0x0820E8F2
	callstd 0x4
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_0020E461::
	loadword 0x0, 0x0820E8E5
	callstd 0x4
	releaseall
	end
