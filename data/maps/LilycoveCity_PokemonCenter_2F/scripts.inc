@ LilycoveCity_PokemonCenter_2F scripts (JP map g13 m7 @ 0x08208376)

LilycoveCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

LilycoveCity_PokemonCenter_2F_EventScript_Colosseum:: @ 0x0820838B
	call CableClub_EventScript_Colosseum
	end

LilycoveCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 0x08208391
	call CableClub_EventScript_TradeCenter
	end

LilycoveCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 0x08208397
	call CableClub_EventScript_RecordCorner
	end
