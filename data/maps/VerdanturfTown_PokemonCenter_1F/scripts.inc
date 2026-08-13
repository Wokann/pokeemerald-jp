@ VerdanturfTown_PokemonCenter_1F scripts (JP map g6 m4 @ 0x081F7021)

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_EventScript_001F702C
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

VerdanturfTown_PokemonCenter_1F_EventScript_001F702C::
	setrespawn 0x12
	call 0x08242978
	end

VerdanturfTown_PokemonCenter_1F_EventScript_001F7035::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_001F7043::
	loadword 0x0, 0x081F7055
	callstd 0x2
	end

VerdanturfTown_PokemonCenter_1F_EventScript_001F704C::
	loadword 0x0, 0x081F70A5
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1f7055, 0x89
