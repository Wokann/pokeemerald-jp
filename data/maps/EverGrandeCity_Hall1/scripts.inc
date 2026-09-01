@ EverGrandeCity_Hall1 scripts (JP map g16 m5 @ 0x0821106B)

EverGrandeCity_Hall1_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall1_OnWarp
	.byte 0

EverGrandeCity_Hall1_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall1_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall1_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end
