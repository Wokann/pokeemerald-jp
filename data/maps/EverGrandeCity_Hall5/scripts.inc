@ EverGrandeCity_Hall5 scripts (JP map g16 m9 @ 0x082110BF)

EverGrandeCity_Hall5_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall5_MapScriptTable_002110C5
	.byte 0

EverGrandeCity_Hall5_MapScriptTable_002110C5::
	map_script_2 0x4001, 0x0, EverGrandeCity_Hall5_EventScript_002110CF
	.2byte 0

EverGrandeCity_Hall5_EventScript_002110CF::
	turnobject 0xFF, 0x2
	end

