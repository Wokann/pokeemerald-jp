@ DewfordTown_PokemonCenter_1F scripts (JP map g3 m1 @ 0x081F2CCF)

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_EventScript_001F2CDA
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

DewfordTown_PokemonCenter_1F_EventScript_001F2CDA::
	setrespawn 0xF
	call 0x08242978
	end

DewfordTown_PokemonCenter_1F_EventScript_001F2CE3::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_001F2CF1::
	loadword 0x0, 0x081F2D03
	callstd 0x2
	end

DewfordTown_PokemonCenter_1F_EventScript_001F2CFA::
	loadword 0x0, 0x081F2D2B
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1f2d03, 0x5d
