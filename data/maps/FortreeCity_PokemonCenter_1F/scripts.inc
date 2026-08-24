@ FortreeCity_PokemonCenter_1F scripts (JP map g12 m2 @ 0x08204C5D)

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_EventScript_00204C68
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

FortreeCity_PokemonCenter_1F_EventScript_00204C68::
	setrespawn 0x7
	end

FortreeCity_PokemonCenter_1F_EventScript_00204C6C::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_00204C7A::
	loadword 0x0, 0x08204C95
	callstd 0x2
	end

FortreeCity_PokemonCenter_1F_EventScript_00204C83::
	loadword 0x0, 0x08204CCE
	callstd 0x2
	end

FortreeCity_PokemonCenter_1F_EventScript_00204C8C::
	loadword 0x0, 0x08204D21
	callstd 0x2
	end
