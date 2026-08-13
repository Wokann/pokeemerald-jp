@ EverGrandeCity_PhoebesRoom scripts (JP map g16 m1 @ 0x08210371)

EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_EventScript_002103A7
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_MapScriptTable_00210381
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_MapScriptTable_00210390
	.byte 0

EverGrandeCity_PhoebesRoom_MapScriptTable_00210381::
	map_script_2 0x4001, 0x0, EverGrandeCity_PhoebesRoom_EventScript_0021038B
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_0021038B::
	turnobject 0xFF, 0x2
	end

EverGrandeCity_PhoebesRoom_MapScriptTable_00210390::
	map_script_2 0x409C, 0x1, EverGrandeCity_PhoebesRoom_EventScript_0021039A
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_0021039A::
	lockall
	call 0x082434F8
	setvar 0x409C, 0x2
	releaseall
	end

EverGrandeCity_PhoebesRoom_EventScript_002103A7::
	checkflag 0x4FC
	call_if 0x1, EverGrandeCity_PhoebesRoom_EventScript_002103BC
	compare_var_to_value 0x409C, 0x2
	call_if 0x1, EverGrandeCity_PhoebesRoom_EventScript_002103C2
	end

EverGrandeCity_PhoebesRoom_EventScript_002103BC::
	call 0x0824353F
	return

EverGrandeCity_PhoebesRoom_EventScript_002103C2::
	call 0x082435E2
	return

	.incbin "baserom_jp.gba", 0x2103c8, 0x15b
