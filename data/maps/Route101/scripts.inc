@ Route101 scripts (JP map g0 m16 @ 0x081E64B6)

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_EventScript_001E64C1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScriptTable_001E64C7
	.byte 0

Route101_EventScript_001E64C1::
	call 0x08243139
	end

Route101_MapScriptTable_001E64C7::
	map_script_2 0x4060, 0x0, Route101_EventScript_001E64D1
	.2byte 0

Route101_EventScript_001E64D1::
	setflag 0x4000
	setvar 0x4060, 0x1
	end

Route101_EventScript_001E64DA::
	lockall
	playbgm 0x19A, 0x1
	loadword 0x0, 0x081E668B
	callstd 0x4
	closemessage
	setobjectxy 0x2, 0x0, 0xF
	setobjectxy 0x4, 0x0, 0x10
	applymovement 0xFF, 0x081E65BE
	applymovement 0x2, 0x081E65E3
	applymovement 0x4, 0x081E65B1
	waitmovement 0x0
	applymovement 0x4, 0x081E6592
	applymovement 0x2, 0x081E65C4
	waitmovement 0x0
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	applymovement 0x4, 0x081E65B9
	applymovement 0x2, 0x081E65EB
	waitmovement 0x0
	loadword 0x0, 0x081E669A
	callstd 0x4
	closemessage
	setvar 0x4060, 0x2
	releaseall
	end

Route101_EventScript_001E654A::
	lockall
	loadword 0x0, 0x081E66D1
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081E658C
	waitmovement 0x0
	releaseall
	end

Route101_EventScript_001E6560::
	lockall
	loadword 0x0, 0x081E66D1
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081E658E
	waitmovement 0x0
	releaseall
	end

Route101_EventScript_001E6576::
	lockall
	loadword 0x0, 0x081E66D1
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081E6590
	waitmovement 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e658c, 0x6b
Route101_EventScript_001E65F7::
	loadword 0x0, 0x081E6782
	callstd 0x2
	end

Route101_EventScript_001E6600::
	loadword 0x0, 0x081E67C3
	callstd 0x2
	end

Route101_EventScript_001E6609::
	loadword 0x0, 0x081E680B
	callstd 0x3
	end

Route101_EventScript_001E6612::
	lock
	faceplayer
	setflag 0x860
	setflag 0x52
	fadescreen 0x1
	removeobject 0x4
	setobjectxy 0xFF, 0x6, 0xD
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	special ChooseStarter
	applymovement 0x2, 0x081E6689
	waitmovement 0x0
	loadword 0x0, 0x081E66F2
	callstd 0x4
	special HealPlayerParty
	setflag 0x2D0
	clearflag 0x2D1
	setflag 0x2BC
	setvar 0x4084, 0x2
	setvar 0x4060, 0x3
	clearflag 0x4000
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route101_EventScript_001E6681
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route101_EventScript_001E6685
	warp 0x104, 0xFF, 0x6, 0x5
	waitstate
	release
	end

Route101_EventScript_001E6681::
	setflag 0x2D2
	return

Route101_EventScript_001E6685::
	setflag 0x2F8
	return
