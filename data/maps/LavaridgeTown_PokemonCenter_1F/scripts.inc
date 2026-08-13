@ LavaridgeTown_PokemonCenter_1F scripts (JP map g4 m5 @ 0x081F4F85)

LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_EventScript_001F4F90
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

LavaridgeTown_PokemonCenter_1F_EventScript_001F4F90::
	setrespawn 0x10
	call 0x08242978
	end

LavaridgeTown_PokemonCenter_1F_EventScript_001F4F99::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_001F4FA7::
	loadword 0x0, 0x081F4FF9
	callstd 0x2
	end

LavaridgeTown_PokemonCenter_1F_EventScript_001F4FB0::
	loadword 0x0, 0x081F4FC2
	callstd 0x2
	end

LavaridgeTown_PokemonCenter_1F_EventScript_001F4FB9::
	loadword 0x0, 0x081F502B
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1f4fc2, 0xaf
