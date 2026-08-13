@ SlateportCity_PokemonCenter_1F scripts (JP map g9 m11 @ 0x081FE809)

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_EventScript_001FE814
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

SlateportCity_PokemonCenter_1F_EventScript_001FE814::
	setrespawn 0x4
	call 0x08242978
	end

SlateportCity_PokemonCenter_1F_EventScript_001FE81D::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_001FE82B::
	loadword 0x0, 0x081FE83D
	callstd 0x2
	end

SlateportCity_PokemonCenter_1F_EventScript_001FE834::
	loadword 0x0, 0x081FE89A
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1fe83d, 0x95
