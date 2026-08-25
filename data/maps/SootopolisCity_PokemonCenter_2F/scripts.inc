@ SootopolisCity_PokemonCenter_2F scripts (JP map g15 m3 @ 0x0820F190)

SootopolisCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

SootopolisCity_PokemonCenter_2F_EventScript_Colosseum:: @ 0x0820F1A5
	call CableClub_EventScript_Colosseum
	end

SootopolisCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 0x0820F1AB
	call CableClub_EventScript_TradeCenter
	end

SootopolisCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 0x0820F1B1
	call CableClub_EventScript_RecordCorner
	end
