@ Route105 scripts (JP map g0 m20 @ 0x081E819E)

Route105_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route105_EventScript_001E81AE
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_EventScript_001E81E1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_MapScriptTable_001E8203
	.byte 0

Route105_EventScript_001E81AE::
	checkflag 0xE4
	call_if 0x0, Route105_EventScript_001E81CE
	compare_var_to_value 0x4037, 0x9
	call_if 0x1, 0x082443D5
	compare_var_to_value 0x4037, 0xA
	call_if 0x1, 0x08244442
	end

Route105_EventScript_001E81CE::
	setmetatile 0x9, 0x13, 0x7C, 0x1
	setmetatile 0x9, 0x14, 0x91, 0x1
	return

Route105_EventScript_001E81E1::
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0x9
	call_if 0x1, 0x08244741
	compare_var_to_value 0x4037, 0xA
	call_if 0x1, 0x08244741
	end

Route105_MapScriptTable_001E8203::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

	.incbin "baserom_jp.gba", 0x1e820d, 0x1a6
	.globl gJPText_001E83B3
gJPText_001E83B3: @ 0x081E83B3
	.string "パパ　センリを\n"
	.string "ポケナビに　とうろく　した！$"

	.incbin "baserom_jp.gba", 0x1e83ca, 0xa7f
