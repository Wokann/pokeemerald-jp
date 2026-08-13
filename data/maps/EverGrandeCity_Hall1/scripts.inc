@ EverGrandeCity_Hall1 scripts (JP map g16 m5 @ 0x0821106B)

EverGrandeCity_Hall1_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall1_MapScriptTable_00211071
	.byte 0

EverGrandeCity_Hall1_MapScriptTable_00211071::
	map_script_2 0x4001, 0x0, EverGrandeCity_Hall1_EventScript_0021107B
	.2byte 0

EverGrandeCity_Hall1_EventScript_0021107B::
	turnobject 0xFF, 0x2
	end

