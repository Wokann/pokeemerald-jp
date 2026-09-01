@ EverGrandeCity_Hall3 scripts (JP map g16 m7 @ 0x08211095)

EverGrandeCity_Hall3_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall3_OnWarp
	.byte 0

EverGrandeCity_Hall3_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall3_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall3_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end
