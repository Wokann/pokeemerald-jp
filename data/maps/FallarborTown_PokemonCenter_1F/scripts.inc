@ FallarborTown_PokemonCenter_1F scripts (JP map g5 m4 @ 0x081F5C4E)

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_EventScript_001F5C59
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

FallarborTown_PokemonCenter_1F_EventScript_001F5C59::
	setrespawn 0x11
	call 0x08242978
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5C62::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5C70::
	loadword 0x0, 0x081F5DD8
	callstd 0x2
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5C79::
	loadword 0x0, 0x081F5E18
	callstd 0x2
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5C82::
	lock
	faceplayer
	loadword 0x0, 0x081F5CEC
	callstd 0x4
	closemessage
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, FallarborTown_PokemonCenter_1F_EventScript_001F5CA9
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, FallarborTown_PokemonCenter_1F_EventScript_001F5CB9
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5CA9::
	applymovement 0x4, 0x081F5CD4
	waitmovement 0x0
	goto FallarborTown_PokemonCenter_1F_EventScript_001F5CC9
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5CB9::
	applymovement 0x4, 0x081F5CE1
	waitmovement 0x0
	goto FallarborTown_PokemonCenter_1F_EventScript_001F5CC9
	end

FallarborTown_PokemonCenter_1F_EventScript_001F5CC9::
	playse 0x12
	removeobject 0x4
	clearflag 0x366
	release
	end

	.incbin "baserom_jp.gba", 0x1f5cd4, 0x17d
