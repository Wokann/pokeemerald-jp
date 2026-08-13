@ PetalburgCity_PokemonCenter_1F scripts (JP map g8 m4 @ 0x081FA7CD)

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_EventScript_001FA7D8
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

PetalburgCity_PokemonCenter_1F_EventScript_001FA7D8::
	setrespawn 0x3
	call 0x08242978
	end

PetalburgCity_PokemonCenter_1F_EventScript_001FA7E1::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_001FA7EF::
	loadword 0x0, 0x081FA85B
	callstd 0x2
	end

PetalburgCity_PokemonCenter_1F_EventScript_001FA7F8::
	loadword 0x0, 0x081FA894
	callstd 0x2
	end

PetalburgCity_PokemonCenter_1F_EventScript_001FA801::
	lock
	faceplayer
	loadword 0x0, 0x081FA8BC
	callstd 0x4
	specialvar 0x800D, IsStarterInParty
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_PokemonCenter_1F_EventScript_001FA81D
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_001FA81D::
	compare_var_to_value 0x4023, 0x0
	call_if 0x1, PetalburgCity_PokemonCenter_1F_EventScript_001FA840
	compare_var_to_value 0x4023, 0x1
	call_if 0x1, PetalburgCity_PokemonCenter_1F_EventScript_001FA849
	compare_var_to_value 0x4023, 0x2
	call_if 0x1, PetalburgCity_PokemonCenter_1F_EventScript_001FA852
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_001FA840::
	loadword 0x0, 0x081FA907
	callstd 0x4
	return

PetalburgCity_PokemonCenter_1F_EventScript_001FA849::
	loadword 0x0, 0x081FA946
	callstd 0x4
	return

PetalburgCity_PokemonCenter_1F_EventScript_001FA852::
	loadword 0x0, 0x081FA984
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x1fa85b, 0x167
