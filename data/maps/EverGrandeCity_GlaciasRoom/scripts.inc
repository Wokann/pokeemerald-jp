@ EverGrandeCity_GlaciasRoom scripts (JP map g16 m2 @ 0x08210523)

EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_MapScriptTable_00210542
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_EventScript_00210559
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_MapScriptTable_00210533
	.byte 0

EverGrandeCity_GlaciasRoom_MapScriptTable_00210533::
	map_script_2 0x4001, 0x0, EverGrandeCity_GlaciasRoom_EventScript_0021053D
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_0021053D::
	turnobject 0xFF, 0x2
	end

EverGrandeCity_GlaciasRoom_MapScriptTable_00210542::
	map_script_2 0x409C, 0x2, EverGrandeCity_GlaciasRoom_EventScript_0021054C
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_0021054C::
	lockall
	call 0x082434F8
	setvar 0x409C, 0x3
	releaseall
	end

EverGrandeCity_GlaciasRoom_EventScript_00210559::
	checkflag 0x4FD
	call_if 0x1, EverGrandeCity_GlaciasRoom_EventScript_0021056E
	compare_var_to_value 0x409C, 0x3
	call_if 0x1, EverGrandeCity_GlaciasRoom_EventScript_00210574
	end

EverGrandeCity_GlaciasRoom_EventScript_0021056E::
	call 0x0824353F
	return

EverGrandeCity_GlaciasRoom_EventScript_00210574::
	call 0x082435E2
	return

	.incbin "baserom_jp.gba", 0x21057a, 0x144
