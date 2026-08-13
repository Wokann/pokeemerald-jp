@ FortreeCity scripts (JP map g0 m4 @ 0x081DFDEE)

FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_EventScript_001DFDF9
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_EventScript_001DFDFD
	.byte 0

FortreeCity_EventScript_001DFDF9::
	setflag 0x87A
	end

FortreeCity_EventScript_001DFDFD::
	setstepcallback 0x2
	end

FortreeCity_EventScript_001DFE00::
	loadword 0x0, 0x081DFEC0
	callstd 0x2
	end

FortreeCity_EventScript_001DFE09::
	lock
	faceplayer
	checkflag 0x127
	goto_if 0x1, FortreeCity_EventScript_001DFE1E
	loadword 0x0, 0x081DFF3B
	callstd 0x4
	release
	end

FortreeCity_EventScript_001DFE1E::
	loadword 0x0, 0x081DFF7D
	callstd 0x4
	release
	end

FortreeCity_EventScript_001DFE28::
	loadword 0x0, 0x081DFFA2
	callstd 0x2
	end

FortreeCity_EventScript_001DFE31::
	loadword 0x0, 0x081DFFEA
	callstd 0x2
	end

FortreeCity_EventScript_001DFE3A::
	loadword 0x0, 0x081E0049
	callstd 0x2
	end

FortreeCity_EventScript_001DFE43::
	loadword 0x0, 0x081E008B
	callstd 0x2
	end

FortreeCity_EventScript_001DFE4C::
	loadword 0x0, 0x081E0126
	callstd 0x3
	end

FortreeCity_EventScript_001DFE55::
	loadword 0x0, 0x081E0148
	callstd 0x3
	end

FortreeCity_EventScript_001DFE5E::
	lock
	faceplayer
	checkitem 0x120, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FortreeCity_EventScript_001DFE7A
	loadword 0x0, 0x081E00B0
	callstd 0x4
	release
	end

FortreeCity_EventScript_001DFE7A::
	loadword 0x0, 0x081E00C0
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FortreeCity_EventScript_001DFE8F
	release
	end

FortreeCity_EventScript_001DFE8F::
	loadword 0x0, 0x081E00E1
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x0824344A
	waitmovement 0x0
	waitse
	playmoncry 0x13D, 0x2
	delay 0x28
	waitdooranim
	applymovement 0x800F, 0x081DFEBE
	waitmovement 0x0
	removeobject 0x800F
	setflag 0x127
	release
	end

	.incbin "baserom_jp.gba", 0x1dfebe, 0x2b3
