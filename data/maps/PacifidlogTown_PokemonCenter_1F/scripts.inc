@ PacifidlogTown_PokemonCenter_1F scripts (JP map g7 m0 @ 0x081F782A)

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_EventScript_001F7835
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

PacifidlogTown_PokemonCenter_1F_EventScript_001F7835::
	setrespawn 0x13
	end

PacifidlogTown_PokemonCenter_1F_EventScript_001F7839::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_001F7847::
	loadword 0x0, 0x081F7862
	callstd 0x2
	end

PacifidlogTown_PokemonCenter_1F_EventScript_001F7850::
	loadword 0x0, 0x081F7887
	callstd 0x2
	end

PacifidlogTown_PokemonCenter_1F_EventScript_001F7859::
	loadword 0x0, 0x081F78C3
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1f7862, 0xb5
