@ Route115 scripts (JP map g0 m30 @ 0x081EB804)

Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_EventScript_001EB814
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_EventScript_001EB82B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_MapScriptTable_001EB84D
	.byte 0

Route115_EventScript_001EB814::
	compare_var_to_value 0x4037, 0x3
	call_if 0x1, 0x08244363
	compare_var_to_value 0x4037, 0x4
	call_if 0x1, 0x08244376
	end

Route115_EventScript_001EB82B::
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0x3
	call_if 0x1, 0x08244745
	compare_var_to_value 0x4037, 0x4
	call_if 0x1, 0x08244745
	end

Route115_MapScriptTable_001EB84D::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

Route115_EventScript_001EB857::
	loadword 0x0, 0x081EBA39
	callstd 0x2
	end

Route115_EventScript_001EB860::
	loadword 0x0, 0x081EBA7E
	callstd 0x3
	end

Route115_EventScript_001EB869::
	loadword 0x0, 0x081EBA98
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1eb872, 0x243
