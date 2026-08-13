@ EverGrandeCity_DrakesRoom scripts (JP map g16 m3 @ 0x082106BE)

EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_MapScriptTable_002106DD
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_EventScript_002106F4
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, 0x08210223
	.byte 0

	.incbin "baserom_jp.gba", 0x2106ce, 0xf
EverGrandeCity_DrakesRoom_MapScriptTable_002106DD::
	map_script_2 0x409C, 0x3, EverGrandeCity_DrakesRoom_EventScript_002106E7
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_002106E7::
	lockall
	call 0x082434F8
	setvar 0x409C, 0x4
	releaseall
	end

EverGrandeCity_DrakesRoom_EventScript_002106F4::
	checkflag 0x4FE
	call_if 0x1, EverGrandeCity_DrakesRoom_EventScript_00210709
	compare_var_to_value 0x409C, 0x4
	call_if 0x1, EverGrandeCity_DrakesRoom_EventScript_0021070F
	end

EverGrandeCity_DrakesRoom_EventScript_00210709::
	call 0x0824353F
	return

EverGrandeCity_DrakesRoom_EventScript_0021070F::
	call 0x082435E2
	return

	.incbin "baserom_jp.gba", 0x210715, 0x1bb
