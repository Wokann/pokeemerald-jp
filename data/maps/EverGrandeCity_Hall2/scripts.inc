@ EverGrandeCity_Hall2 scripts (JP map g16 m6 @ 0x08211080)

EverGrandeCity_Hall2_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall2_MapScriptTable_00211086
	.byte 0

EverGrandeCity_Hall2_MapScriptTable_00211086::
	map_script_2 0x4001, 0x0, EverGrandeCity_Hall2_EventScript_00211090
	.2byte 0

EverGrandeCity_Hall2_EventScript_00211090::
	turnobject 0xFF, 0x2
	end

