@ Route129 scripts (JP map g0 m44 @ 0x081EF2B4)

Route129_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route129_EventScript_001EF2DB
	map_script MAP_SCRIPT_ON_LOAD, Route129_EventScript_001EF2C4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route129_MapScriptTable_001EF312
	.byte 0

Route129_EventScript_001EF2C4::
	compare_var_to_value 0x4037, 0xF
	call_if 0x1, 0x08244663
	compare_var_to_value 0x4037, 0x10
	call_if 0x1, 0x082446D0
	end

Route129_EventScript_001EF2DB::
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x405E, 0x4
	call_if 0x4, Route129_EventScript_001EF308
	compare_var_to_value 0x4037, 0xF
	call_if 0x1, 0x08244741
	compare_var_to_value 0x4037, 0x10
	call_if 0x1, 0x08244741
	end

Route129_EventScript_001EF308::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	return

Route129_MapScriptTable_001EF312::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

	.incbin "baserom_jp.gba", 0x1ef31c, 0x73
