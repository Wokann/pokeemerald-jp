@ LavaridgeTown_PokemonCenter_2F scripts (JP map g4 m6 @ 0x081F5071)

LavaridgeTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

LavaridgeTown_PokemonCenter_2F_EventScript_Colosseum:: @ 0x081F5086
	call CableClub_EventScript_Colosseum
	end

LavaridgeTown_PokemonCenter_2F_EventScript_TradeCenter:: @ 0x081F508C
	call CableClub_EventScript_TradeCenter
	end

LavaridgeTown_PokemonCenter_2F_EventScript_RecordCorner:: @ 0x081F5092
	call CableClub_EventScript_RecordCorner
	end
