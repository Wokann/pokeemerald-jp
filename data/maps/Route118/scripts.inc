@ Route118 scripts (JP map g0 m33 @ 0x081EC7E9)

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_EventScript_001EC7F9
	map_script MAP_SCRIPT_ON_LOAD, Route118_EventScript_001EC820
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_MapScriptTable_001EC837
	.byte 0

Route118_EventScript_001EC7F9::
	call 0x082540DF
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0x7
	call_if 0x1, 0x08244745
	compare_var_to_value 0x4037, 0x8
	call_if 0x1, 0x08244745
	end

Route118_EventScript_001EC820::
	compare_var_to_value 0x4037, 0x7
	call_if 0x1, 0x082443AF
	compare_var_to_value 0x4037, 0x8
	call_if 0x1, 0x082443C2
	end

Route118_MapScriptTable_001EC837::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

Route118_EventScript_001EC841::
	lock
	faceplayer
	checkflag 0xE3
	goto_if 0x1, Route118_EventScript_001EC896
	loadword 0x0, 0x081ECBD8
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route118_EventScript_001EC86B
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route118_EventScript_001EC88C
	end

Route118_EventScript_001EC86B::
	loadword 0x0, 0x081ECBFE
	callstd 0x4
	setorcopyvar 0x8000, 0x107
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0xE3
	loadword 0x0, 0x081ECC21
	callstd 0x4
	release
	end

Route118_EventScript_001EC88C::
	loadword 0x0, 0x081ECC40
	callstd 0x4
	release
	end

Route118_EventScript_001EC896::
	loadword 0x0, 0x081ECC4C
	callstd 0x4
	release
	end

Route118_EventScript_001EC8A0::
	loadword 0x0, 0x081ECC68
	callstd 0x2
	end

Route118_EventScript_001EC8A9::
	loadword 0x0, 0x081ECCAF
	callstd 0x3
	end

Route118_EventScript_001EC8B2::
	loadword 0x0, 0x081ECCC9
	callstd 0x3
	end

Route118_EventScript_001EC8BB::
	lockall
	setvar 0x8008, 0x0
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	applymovement 0x13, 0x081EC98E
	waitmovement 0x0
	goto Route118_EventScript_001EC911
	end

Route118_EventScript_001EC8DB::
	lockall
	setvar 0x8008, 0x1
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	goto Route118_EventScript_001EC911
	end

Route118_EventScript_001EC8F1::
	lockall
	setvar 0x8008, 0x2
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	applymovement 0x13, 0x081EC990
	waitmovement 0x0
	goto Route118_EventScript_001EC911
	end

Route118_EventScript_001EC911::
	playse 0xA
	applymovement 0x13, 0x081EC992
	waitmovement 0x0
	delay 0x1E
	loadword 0x0, 0x081ECAEB
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, Route118_EventScript_001EC955
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, Route118_EventScript_001EC967
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, Route118_EventScript_001EC979
	setvar 0x4071, 0x1
	removeobject 0x13
	releaseall
	end

Route118_EventScript_001EC955::
	applymovement 0xFF, 0x081EC98B
	applymovement 0x13, 0x081EC996
	waitmovement 0x0
	return

Route118_EventScript_001EC967::
	applymovement 0xFF, 0x081EC98B
	applymovement 0x13, 0x081EC9A1
	waitmovement 0x0
	return

Route118_EventScript_001EC979::
	applymovement 0xFF, 0x081EC98B
	applymovement 0x13, 0x081EC9AB
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1ec98b, 0x35a
