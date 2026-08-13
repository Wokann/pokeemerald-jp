@ Route125 scripts (JP map g0 m40 @ 0x081EE97C)

Route125_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route125_EventScript_001EE98C
	map_script MAP_SCRIPT_ON_LOAD, Route125_EventScript_001EE9B7
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route125_MapScriptTable_001EE9CE
	.byte 0

Route125_EventScript_001EE98C::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0xB
	call_if 0x1, 0x08244741
	compare_var_to_value 0x4037, 0xC
	call_if 0x1, 0x08244741
	end

Route125_EventScript_001EE9B7::
	compare_var_to_value 0x4037, 0xB
	call_if 0x1, 0x082444AF
	compare_var_to_value 0x4037, 0xC
	call_if 0x1, 0x0824451C
	end

Route125_MapScriptTable_001EE9CE::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

	.incbin "baserom_jp.gba", 0x1ee9d8, 0x122
