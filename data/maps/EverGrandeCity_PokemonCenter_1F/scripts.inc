@ EverGrandeCity_PokemonCenter_1F scripts (JP map g16 m12 @ 0x082113FC)

EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_EventScript_00211407
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

EverGrandeCity_PokemonCenter_1F_EventScript_00211407::
	setrespawn 0xB
	checkflag 0x1CF
	call_if 0x0, EverGrandeCity_PokemonCenter_1F_EventScript_00211414
	end

EverGrandeCity_PokemonCenter_1F_EventScript_00211414::
	checkflag 0x86C
	goto_if 0x0, 0x08244178
	clearflag 0x319
	return

EverGrandeCity_PokemonCenter_1F_EventScript_00211421::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_0021142F::
	loadword 0x0, 0x082114A2
	callstd 0x2
	end

EverGrandeCity_PokemonCenter_1F_EventScript_00211438::
	loadword 0x0, 0x082114D6
	callstd 0x2
	end

EverGrandeCity_PokemonCenter_1F_EventScript_00211441::
	lock
	faceplayer
	loadword 0x0, 0x08211531
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, EverGrandeCity_PokemonCenter_1F_EventScript_0021147E
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, EverGrandeCity_PokemonCenter_1F_EventScript_00211489
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, EverGrandeCity_PokemonCenter_1F_EventScript_00211489
	addvar 0x40D1, 0x1
	setflag 0x1CF
	playse 0x9
	waitse
	removeobject 0x4
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_0021147E::
	applymovement 0x4, 0x08211494
	waitmovement 0x0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_00211489::
	applymovement 0x4, 0x0821149B
	waitmovement 0x0
	return
