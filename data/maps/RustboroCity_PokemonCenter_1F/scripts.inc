@ RustboroCity_PokemonCenter_1F scripts (JP map g11 m5 @ 0x082034B3)

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_EventScript_002034BE
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

RustboroCity_PokemonCenter_1F_EventScript_002034BE::
	setrespawn 0x6
	call 0x08242978
	end

RustboroCity_PokemonCenter_1F_EventScript_002034C7::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_002034D5::
	loadword 0x0, 0x082034F0
	callstd 0x2
	end

RustboroCity_PokemonCenter_1F_EventScript_002034DE::
	loadword 0x0, 0x0820353E
	callstd 0x2
	end

RustboroCity_PokemonCenter_1F_EventScript_002034E7::
	loadword 0x0, 0x08203580
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x2034f0, 0xc9
