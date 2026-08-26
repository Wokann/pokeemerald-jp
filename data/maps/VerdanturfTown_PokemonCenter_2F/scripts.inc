@ VerdanturfTown_PokemonCenter_2F scripts (JP map g6 m5 @ 0x081F70DE)

VerdanturfTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

VerdanturfTown_PokemonCenter_2F_EventScript_Colosseum:: @ 0x081F70F3
	call CableClub_EventScript_Colosseum
	end

VerdanturfTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 0x081F70F9
	call CableClub_EventScript_TradeCenter
	end

VerdanturfTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 0x081F70FF
	call CableClub_EventScript_RecordCorner
	end
