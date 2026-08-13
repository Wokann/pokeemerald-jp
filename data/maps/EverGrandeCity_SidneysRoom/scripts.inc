@ EverGrandeCity_SidneysRoom scripts (JP map g16 m0 @ 0x082101E6)

EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_EventScript_00210202
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_MapScriptTable_00210223
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_EventScript_002101FB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_MapScriptTable_00210232
	.byte 0

EverGrandeCity_SidneysRoom_EventScript_002101FB::
	setflag 0x1CF
	setflag 0x319
	end

EverGrandeCity_SidneysRoom_EventScript_00210202::
	checkflag 0x4FB
	call_if 0x1, EverGrandeCity_SidneysRoom_EventScript_00210217
	compare_var_to_value 0x409C, 0x1
	call_if 0x1, EverGrandeCity_SidneysRoom_EventScript_0021021D
	end

EverGrandeCity_SidneysRoom_EventScript_00210217::
	call 0x0824353F
	return

EverGrandeCity_SidneysRoom_EventScript_0021021D::
	call 0x082435E2
	return

EverGrandeCity_SidneysRoom_MapScriptTable_00210223::
	map_script_2 0x4001, 0x0, EverGrandeCity_SidneysRoom_EventScript_0021022D
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_0021022D::
	turnobject 0xFF, 0x2
	end

EverGrandeCity_SidneysRoom_MapScriptTable_00210232::
	map_script_2 0x409C, 0x0, EverGrandeCity_SidneysRoom_EventScript_0021023C
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_0021023C::
	lockall
	call 0x082434F8
	setvar 0x409C, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x210249, 0x128
