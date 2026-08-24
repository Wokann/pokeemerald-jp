@ BattleFrontier_PokemonCenter_1F scripts (JP map g26 m53 @ 0x0823B134)

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_EventScript_0023B13F
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

BattleFrontier_PokemonCenter_1F_EventScript_0023B13F::
	setrespawn 0x16
	end

BattleFrontier_PokemonCenter_1F_EventScript_0023B143::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_0023B151::
	loadword 0x0, 0x0823B17F
	callstd 0x2
	end

BattleFrontier_PokemonCenter_1F_EventScript_0023B15A::
	loadword 0x0, 0x0823B1C4
	callstd 0x2
	end

BattleFrontier_PokemonCenter_1F_EventScript_0023B163::
	loadword 0x0, 0x0823B1F8
	callstd 0x2
	end

BattleFrontier_PokemonCenter_1F_EventScript_0023B16C::
	lock
	faceplayer
	waitse
	playmoncry 0x13B, 0x0
	loadword 0x0, 0x0823B216
	callstd 0x4
	waitdooranim
	release
	end
