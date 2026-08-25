@ EverGrandeCity_PokemonCenter_2F scripts (JP map g16 m13 @ 0x082115A2)

EverGrandeCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

EverGrandeCity_PokemonCenter_2F_EventScript_Colosseum:: @ 0x082115B7
	call CableClub_EventScript_Colosseum
	end

EverGrandeCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 0x082115BD
	call CableClub_EventScript_TradeCenter
	end

EverGrandeCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 0x082115C3
	call CableClub_EventScript_RecordCorner
	end
