@ LilycoveCity_PokemonCenter_1F scripts (JP map g13 m6 @ 0x0820824A)

LilycoveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_EventScript_00208255
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

LilycoveCity_PokemonCenter_1F_EventScript_00208255::
	setrespawn 0x8
	goto LilycoveCity_PokemonCenter_1F_EventScript_0020825E
	end

LilycoveCity_PokemonCenter_1F_EventScript_0020825E::
	special sub_0818D6EC
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_PokemonCenter_1F_EventScript_00208278
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonCenter_1F_EventScript_0020827C
	end

LilycoveCity_PokemonCenter_1F_EventScript_00208278::
	setflag 0x3E1
	end

LilycoveCity_PokemonCenter_1F_EventScript_0020827C::
	clearflag 0x3E1
	end

LilycoveCity_PokemonCenter_1F_EventScript_00208280::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_0020828E::
	loadword 0x0, 0x082082B6
	callstd 0x2
	end

LilycoveCity_PokemonCenter_1F_EventScript_00208297::
	lock
	faceplayer
	checkflag 0x86D
	goto_if 0x1, LilycoveCity_PokemonCenter_1F_EventScript_002082AC
	loadword 0x0, 0x082082FD
	callstd 0x4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_002082AC::
	loadword 0x0, 0x08208337
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x2082b6, 0xc0
