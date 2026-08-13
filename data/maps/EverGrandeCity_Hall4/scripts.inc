@ EverGrandeCity_Hall4 scripts (JP map g16 m8 @ 0x082110AA)

EverGrandeCity_Hall4_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall4_MapScriptTable_002110B0
	.byte 0

EverGrandeCity_Hall4_MapScriptTable_002110B0::
	map_script_2 0x4001, 0x0, EverGrandeCity_Hall4_EventScript_002110BA
	.2byte 0

EverGrandeCity_Hall4_EventScript_002110BA::
	turnobject 0xFF, 0x2
	end

