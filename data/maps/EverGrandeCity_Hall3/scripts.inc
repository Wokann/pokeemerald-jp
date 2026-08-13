@ EverGrandeCity_Hall3 scripts (JP map g16 m7 @ 0x08211095)

EverGrandeCity_Hall3_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall3_MapScriptTable_0021109B
	.byte 0

EverGrandeCity_Hall3_MapScriptTable_0021109B::
	map_script_2 0x4001, 0x0, EverGrandeCity_Hall3_EventScript_002110A5
	.2byte 0

EverGrandeCity_Hall3_EventScript_002110A5::
	turnobject 0xFF, 0x2
	end

