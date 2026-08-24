@ MauvilleCity_PokemonCenter_2F scripts (JP map g10 m6 @ 0x08200ECF)

MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

	.incbin "baserom_jp.gba", 0x200ee4, 0x12
MauvilleCity_PokemonCenter_2F_EventScript_00200EF6::
	loadword 0x0, 0x08200EFF
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x200eff, 0x131
