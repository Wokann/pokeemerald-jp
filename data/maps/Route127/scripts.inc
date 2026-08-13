@ Route127 scripts (JP map g0 m42 @ 0x081EEC0D)

Route127_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route127_EventScript_001EEC1D
	map_script MAP_SCRIPT_ON_LOAD, Route127_EventScript_001EEC48
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route127_MapScriptTable_001EEC5F
	.byte 0

Route127_EventScript_001EEC1D::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0xD
	call_if 0x1, 0x08244741
	compare_var_to_value 0x4037, 0xE
	call_if 0x1, 0x08244741
	end

Route127_EventScript_001EEC48::
	compare_var_to_value 0x4037, 0xD
	call_if 0x1, 0x08244589
	compare_var_to_value 0x4037, 0xE
	call_if 0x1, 0x082445F6
	end

Route127_MapScriptTable_001EEC5F::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

	.incbin "baserom_jp.gba", 0x1eec69, 0x103
