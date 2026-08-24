@ MossdeepCity_PokemonCenter_2F scripts (JP map g14 m4 @ 0x0820C54A)

MossdeepCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

	.incbin "baserom_jp.gba", 0x20c55f, 0x12
MossdeepCity_PokemonCenter_2F_EventScript_0020C571::
	loadword 0x0, 0x0820C57A
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x20c57a, 0x29c
