@ VerdanturfTown_PokemonCenter_2F scripts (JP map g6 m5 @ 0x081F70DE)

VerdanturfTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

	.incbin "baserom_jp.gba", 0x1f70f3, 0x737
