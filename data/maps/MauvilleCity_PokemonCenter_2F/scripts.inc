@ MauvilleCity_PokemonCenter_2F scripts (JP map g10 m6 @ 0x08200ECF)

MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08246939
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, 0x0824686A
	map_script MAP_SCRIPT_ON_LOAD, 0x082468BC
	map_script MAP_SCRIPT_ON_TRANSITION, 0x082467CD
	.byte 0

	.incbin "baserom_jp.gba", 0x200ee4, 0x12
MauvilleCity_PokemonCenter_2F_EventScript_00200EF6::
	loadword 0x0, 0x08200EFF
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x200eff, 0x131
