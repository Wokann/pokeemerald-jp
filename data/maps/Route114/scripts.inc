@ Route114 scripts (JP map g0 m29 @ 0x081EB474)

Route114_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_EventScript_001EB484
	map_script MAP_SCRIPT_ON_LOAD, Route114_EventScript_001EB4A6
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_MapScriptTable_001EB4BD
	.byte 0

Route114_EventScript_001EB484::
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0x1
	call_if 0x1, 0x08244745
	compare_var_to_value 0x4037, 0x2
	call_if 0x1, 0x08244745
	end

Route114_EventScript_001EB4A6::
	compare_var_to_value 0x4037, 0x1
	call_if 0x1, 0x0824433D
	compare_var_to_value 0x4037, 0x2
	call_if 0x1, 0x08244350
	end

Route114_MapScriptTable_001EB4BD::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

Route114_EventScript_001EB4C7::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x92B
	goto_if 0x1, Route114_EventScript_001EB50C
	loadword 0x0, 0x08263908
	callstd 0x4
	random 0x5
	addvar 0x800D, 0xF
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x92B
	loadword 0x0, 0x0826393D
	callstd 0x4
	release
	end

Route114_EventScript_001EB50C::
	loadword 0x0, 0x08263958
	callstd 0x4
	release
	end

Route114_EventScript_001EB516::
	lock
	faceplayer
	checkflag 0xE7
	goto_if 0x1, Route114_EventScript_001EB54D
	loadword 0x0, 0x081EB74E
	callstd 0x4
	setorcopyvar 0x8000, 0x125
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xE7
	loadword 0x0, 0x081EB78B
	callstd 0x4
	release
	end

Route114_EventScript_001EB54D::
	loadword 0x0, 0x081EB78B
	callstd 0x4
	release
	end

Route114_EventScript_001EB557::
	lock
	faceplayer
	waitse
	playmoncry 0x11E, 0x2
	loadword 0x0, 0x081EB7B3
	callstd 0x4
	waitdooranim
	release
	end

Route114_EventScript_001EB56A::
	loadword 0x0, 0x081EB7C0
	callstd 0x3
	end

Route114_EventScript_001EB573::
	loadword 0x0, 0x081EB7DD
	callstd 0x3
	end

Route114_EventScript_001EB57C::
	loadword 0x0, 0x081EB7FA
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1eb585, 0x27f
