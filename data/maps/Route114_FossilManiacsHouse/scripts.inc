@ Route114_FossilManiacsHouse scripts (JP map g20 m0 @ 0x0821212C)

Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_EventScript_00212132
	.byte 0

Route114_FossilManiacsHouse_EventScript_00212132::
	setflag 0x8B7
	end

Route114_FossilManiacsHouse_EventScript_00212136::
	lock
	faceplayer
	checkflag 0x105
	goto_if 0x1, Route114_FossilManiacsHouse_EventScript_00212165
	loadword 0x0, 0x08212181
	callstd 0x4
	setorcopyvar 0x8000, 0x13C
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x105
	release
	end

Route114_FossilManiacsHouse_EventScript_00212165::
	loadword 0x0, 0x082121F9
	callstd 0x4
	release
	end

Route114_FossilManiacsHouse_EventScript_0021216F::
	loadword 0x0, 0x08212229
	callstd 0x3
	end

Route114_FossilManiacsHouse_EventScript_00212178::
	loadword 0x0, 0x0821224D
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x212181, 0x10c
