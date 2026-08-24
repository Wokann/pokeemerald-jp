@ MossdeepCity_PokemonCenter_1F scripts (JP map g14 m3 @ 0x0820C4B2)

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_EventScript_0020C4BD
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

MossdeepCity_PokemonCenter_1F_EventScript_0020C4BD::
	setrespawn 0x9
	end

MossdeepCity_PokemonCenter_1F_EventScript_0020C4C1::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_0020C4CF::
	loadword 0x0, 0x0820C4E1
	callstd 0x2
	end

MossdeepCity_PokemonCenter_1F_EventScript_0020C4D8::
	loadword 0x0, 0x0820C517
	callstd 0x2
	end
