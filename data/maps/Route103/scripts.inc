@ Route103 scripts (JP map g0 m18 @ 0x081E6A59)

Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_EventScript_001E6A64
	map_script MAP_SCRIPT_ON_LOAD, Route103_EventScript_001E6A6F
	.byte 0

Route103_EventScript_001E6A64::
	call 0x08242F63
	call 0x08243139
	end

Route103_EventScript_001E6A6F::
	checkflag 0x864
	call_if 0x1, Route103_EventScript_001E6A79
	end

Route103_EventScript_001E6A79::
	setmetatile 0x2D, 0x5, 0x9F, 0x1
	setmetatile 0x2D, 0x6, 0xA7, 0x0
	return

Route103_EventScript_001E6A8C::
	lockall
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route103_EventScript_001E6AA5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route103_EventScript_001E6AFF
	end

Route103_EventScript_001E6AA5::
	loadword 0x0, 0x081E6E71
	callstd 0x4
	closemessage
	playbgm 0x19F, 0x1
	applymovement 0x2, 0x08243621
	waitmovement 0x0
	applymovement 0x2, 0x0824361B
	waitmovement 0x0
	applymovement 0x2, 0x0824361D
	waitmovement 0x0
	loadword 0x0, 0x081E6E97
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E6B59
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E6B69
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E6B79
	end

Route103_EventScript_001E6AFF::
	loadword 0x0, 0x081E6FA8
	callstd 0x4
	closemessage
	playbgm 0x1A5, 0x1
	applymovement 0x2, 0x08243621
	waitmovement 0x0
	applymovement 0x2, 0x0824361B
	waitmovement 0x0
	applymovement 0x2, 0x0824361D
	waitmovement 0x0
	loadword 0x0, 0x081E6FD0
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E6B89
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E6B99
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E6BA9
	end

	.incbin "baserom_jp.gba", 0x1e6b59, 0x14b
Route103_EventScript_001E6CA4::
	loadword 0x0, 0x081E70B5
	callstd 0x2
	end

Route103_EventScript_001E6CAD::
	loadword 0x0, 0x081E70DC
	callstd 0x2
	end

Route103_EventScript_001E6CB6::
	loadword 0x0, 0x081E7115
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1e6cbf, 0x46f
