@ MossdeepCity_PokemonCenter_2F scripts (JP map g14 m4 @ 0x0820C54A)

MossdeepCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08246939
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, 0x0824686A
	map_script MAP_SCRIPT_ON_LOAD, 0x082468BC
	map_script MAP_SCRIPT_ON_TRANSITION, 0x082467CD
	.byte 0

	.incbin "baserom_jp.gba", 0x20c55f, 0x12
MossdeepCity_PokemonCenter_2F_EventScript_0020C571::
	loadword 0x0, 0x0820C57A
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x20c57a, 0x29c
