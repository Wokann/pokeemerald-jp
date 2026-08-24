@ FortreeCity_Gym scripts (JP map g12 m1 @ 0x0820439E)

FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_EventScript_002043A9
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_MapScriptTable_002043AD
	.byte 0

FortreeCity_Gym_EventScript_002043A9::
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_MapScriptTable_002043AD::
	map_script_2 0x4000, 0x4000, FortreeCity_Gym_EventScript_002043B7
	.2byte 0

FortreeCity_Gym_EventScript_002043B7::
	special RotatingGate_InitPuzzleAndGraphics
	end

	.incbin "baserom_jp.gba", 0x2043bb, 0x16a
FortreeCity_Gym_EventScript_00204525::
	lock
	faceplayer
	checkflag 0x4F5
	goto_if 0x1, FortreeCity_Gym_EventScript_0020453A
	loadword 0x0, 0x08204578
	callstd 0x4
	release
	end

FortreeCity_Gym_EventScript_0020453A::
	loadword 0x0, 0x08204609
	callstd 0x4
	release
	end

FortreeCity_Gym_EventScript_00204544::
	lockall
	checkflag 0x86C
	goto_if 0x1, FortreeCity_Gym_EventScript_00204564
	goto FortreeCity_Gym_EventScript_0020456E
	end

FortreeCity_Gym_EventScript_00204554::
	lockall
	checkflag 0x86C
	goto_if 0x1, FortreeCity_Gym_EventScript_00204564
	goto FortreeCity_Gym_EventScript_0020456E
	end

FortreeCity_Gym_EventScript_00204564::
	loadword 0x0, 0x08204AAF
	callstd 0x4
	releaseall
	end

FortreeCity_Gym_EventScript_0020456E::
	loadword 0x0, 0x08204AA0
	callstd 0x4
	releaseall
	end
