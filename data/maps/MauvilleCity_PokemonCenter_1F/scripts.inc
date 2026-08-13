@ MauvilleCity_PokemonCenter_1F scripts (JP map g10 m5 @ 0x08200DD4)

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_EventScript_00200DDF
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

MauvilleCity_PokemonCenter_1F_EventScript_00200DDF::
	setrespawn 0x5
	call 0x08242978
	goto MauvilleCity_PokemonCenter_1F_EventScript_00200DED
	end

MauvilleCity_PokemonCenter_1F_EventScript_00200DED::
	special ScrSpecial_SetMauvilleOldManEventObjGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_00200DF1::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_00200DFF::
	loadword 0x0, 0x08200E1A
	callstd 0x2
	end

MauvilleCity_PokemonCenter_1F_EventScript_00200E08::
	loadword 0x0, 0x08200E54
	callstd 0x2
	end

MauvilleCity_PokemonCenter_1F_EventScript_00200E11::
	loadword 0x0, 0x08200E8A
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x200e1a, 0xb5
