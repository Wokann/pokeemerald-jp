@ Route110 scripts (JP map g0 m25 @ 0x081E8E49)

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_EventScript_001E8E59
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_EventScript_001E8E5D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_MapScriptTable_001E8E77
	.byte 0

Route110_EventScript_001E8E59::
	special UpdateCyclingRoadState
	end

Route110_EventScript_001E8E5D::
	call 0x08242F63
	call 0x08242F87
	compare_var_to_value 0x40A9, 0x1
	call_if 0x1, Route110_EventScript_001E8E73
	end

Route110_EventScript_001E8E73::
	savebgm 0x193
	return

Route110_MapScriptTable_001E8E77::
	map_script_2 0x40A9, 0x1, Route110_EventScript_001E8E81
	.2byte 0

Route110_EventScript_001E8E81::
	special Special_BeginCyclingRoadChallenge
	setvar 0x40A9, 0x2
	return

Route110_EventScript_001E8E8A::
	lock
	faceplayer
	loadword 0x0, 0x081E973D
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_001E8EA0::
	lock
	faceplayer
	loadword 0x0, 0x081E975D
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_001E8EB6::
	lock
	faceplayer
	loadword 0x0, 0x081E9778
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_001E8ECC::
	lock
	faceplayer
	loadword 0x0, 0x081E9798
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

Route110_EventScript_001E8EE2::
	loadword 0x0, 0x081E99CB
	callstd 0x2
	end

Route110_EventScript_001E8EEB::
	loadword 0x0, 0x081E99FA
	callstd 0x2
	end

Route110_EventScript_001E8EF4::
	loadword 0x0, 0x081E9A24
	callstd 0x2
	end

Route110_EventScript_001E8EFD::
	loadword 0x0, 0x081E9B41
	callstd 0x2
	end

Route110_EventScript_001E8F06::
	loadword 0x0, 0x081E9B80
	callstd 0x2
	end

Route110_EventScript_001E8F0F::
	loadword 0x0, 0x081E9BAC
	callstd 0x2
	end

Route110_EventScript_001E8F18::
	loadword 0x0, 0x081E9BF1
	callstd 0x2
	end

Route110_EventScript_001E8F21::
	loadword 0x0, 0x081E9E44
	callstd 0x3
	end

Route110_EventScript_001E8F2A::
	loadword 0x0, 0x081E9E5D
	callstd 0x3
	end

Route110_EventScript_001E8F33::
	loadword 0x0, 0x081E9E70
	callstd 0x3
	end

Route110_EventScript_001E8F3C::
	loadword 0x0, 0x081E9EC1
	callstd 0x3
	end

Route110_EventScript_001E8F45::
	loadword 0x0, 0x081E9EDD
	callstd 0x3
	end

Route110_EventScript_001E8F4E::
	loadword 0x0, 0x081E9EEB
	callstd 0x3
	end

Route110_EventScript_001E8F57::
	loadword 0x0, 0x081E9F05
	callstd 0x3
	end

Route110_EventScript_001E8F60::
	loadword 0x0, 0x081E9F56
	callstd 0x3
	end

Route110_EventScript_001E8F69::
	loadword 0x0, 0x081E9F95
	callstd 0x3
	end

Route110_EventScript_001E8F72::
	lockall
	specialvar 0x800D, GetRecordedCyclingRoadResults
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route110_EventScript_001E8F8D
	loadword 0x0, 0x081E9FC0
	callstd 0x4
	releaseall
	end

Route110_EventScript_001E8F8D::
	loadword 0x0, 0x081E9FF5
	callstd 0x4
	releaseall
	end

Route110_EventScript_001E8F97::
	lock
	faceplayer
	specialvar 0x800D, GetPlayerAvatarBike
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_EventScript_001E8FC8
	compare_var_to_value 0x40A9, 0x0
	goto_if 0x1, Route110_EventScript_001E8FBE
	loadword 0x0, 0x081E9DAD
	callstd 0x4
	release
	end

Route110_EventScript_001E8FBE::
	loadword 0x0, 0x081E9D56
	callstd 0x4
	release
	end

Route110_EventScript_001E8FC8::
	loadword 0x0, 0x081E9DD5
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1e8fd2, 0x26f
Route110_EventScript_001E9241::
	lockall
	applymovement 0x15, 0x0824362B
	waitmovement 0x0
	call Route110_EventScript_001E9253
	releaseall
	end

Route110_EventScript_001E9253::
	special FinishCyclingRoadChallenge
	loadword 0x0, 0x081E9C26
	callstd 0x4
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0xA
	goto_if 0x1, Route110_EventScript_001E92DD
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, Route110_EventScript_001E92EB
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, Route110_EventScript_001E92EB
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route110_EventScript_001E92EB
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route110_EventScript_001E92F9
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route110_EventScript_001E92F9
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route110_EventScript_001E92F9
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route110_EventScript_001E9307
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_EventScript_001E9307
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_EventScript_001E9307
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_EventScript_001E9315
	end

Route110_EventScript_001E92DD::
	loadword 0x0, 0x081E9C4A
	callstd 0x4
	goto Route110_EventScript_001E9323
	end

Route110_EventScript_001E92EB::
	loadword 0x0, 0x081E9C81
	callstd 0x4
	goto Route110_EventScript_001E9323
	end

Route110_EventScript_001E92F9::
	loadword 0x0, 0x081E9CBA
	callstd 0x4
	goto Route110_EventScript_001E9323
	end

Route110_EventScript_001E9307::
	loadword 0x0, 0x081E9CF1
	callstd 0x4
	goto Route110_EventScript_001E9323
	end

Route110_EventScript_001E9315::
	loadword 0x0, 0x081E9D1D
	callstd 0x4
	goto Route110_EventScript_001E9323
	end

Route110_EventScript_001E9323::
	setvar 0x40A9, 0x3
	savebgm 0x0
	fadedefaultbgm
	return

Route110_EventScript_001E932D::
	setvar 0x8008, 0x1
	goto Route110_EventScript_001E934E
	end

Route110_EventScript_001E9338::
	setvar 0x8008, 0x2
	goto Route110_EventScript_001E934E
	end

Route110_EventScript_001E9343::
	setvar 0x8008, 0x3
	goto Route110_EventScript_001E934E
	end

Route110_EventScript_001E934E::
	lockall
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_EventScript_001E93C1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route110_EventScript_001E93C6
	applymovement 0x1C, 0x0824362D
	waitmovement 0x0
	applymovement 0x1C, 0x0824361B
	waitmovement 0x0
	applymovement 0x1C, 0x0824361D
	waitmovement 0x0
	delay 0x1E
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, Route110_EventScript_001E952E
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, Route110_EventScript_001E9539
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, Route110_EventScript_001E9544
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route110_EventScript_001E93CB
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_EventScript_001E9445
	releaseall
	end

Route110_EventScript_001E93C1::
	playbgm 0x19F, 0x1
	return

Route110_EventScript_001E93C6::
	playbgm 0x1A5, 0x1
	return

Route110_EventScript_001E93CB::
	loadword 0x0, 0x081E97B9
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E93FA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E940A
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E941A
	end

	.incbin "baserom_jp.gba", 0x1e93fa, 0x4b
Route110_EventScript_001E9445::
	loadword 0x0, 0x081E98F4
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E9474
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E9484
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E9494
	end

	.incbin "baserom_jp.gba", 0x1e9474, 0xba
Route110_EventScript_001E952E::
	applymovement 0x1C, 0x081E9588
	waitmovement 0x0
	return

Route110_EventScript_001E9539::
	applymovement 0x1C, 0x081E958C
	waitmovement 0x0
	return

Route110_EventScript_001E9544::
	applymovement 0x1C, 0x081E958E
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1e954f, 0x5c
Route110_EventScript_001E95AB::
	lockall
	setvar 0x8008, 0x1
	goto Route110_EventScript_001E95D7

Route110_EventScript_001E95B6::
	lockall
	setvar 0x8008, 0x2
	goto Route110_EventScript_001E95D7

Route110_EventScript_001E95C1::
	lockall
	setvar 0x8008, 0x3
	goto Route110_EventScript_001E95D7

Route110_EventScript_001E95CC::
	lockall
	setvar 0x8008, 0x4
	goto Route110_EventScript_001E95D7

Route110_EventScript_001E95D7::
	addobject 0x24
	applymovement 0x24, 0x081E9710
	waitmovement 0x0
	playse 0x15
	applymovement 0x24, 0x0824361B
	waitmovement 0x0
	applymovement 0x24, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, Route110_EventScript_001E96B8
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, Route110_EventScript_001E96C3
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, Route110_EventScript_001E96CE
	compare_var_to_value 0x8008, 0x4
	call_if 0x1, Route110_EventScript_001E96D9
	loadword 0x0, 0x081EA02B
	callstd 0x4
	closemessage
	delay 0x14
	applymovement 0x24, 0x08243627
	waitmovement 0x0
	delay 0xA
	applymovement 0x24, 0x0824362B
	waitmovement 0x0
	delay 0x14
	applymovement 0x24, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	loadword 0x0, 0x081EA057
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x081EA0F2
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0x119
	loadword 0x0, 0x081EA10A
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, Route110_EventScript_001E96E4
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, Route110_EventScript_001E96EF
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, Route110_EventScript_001E96FA
	compare_var_to_value 0x8008, 0x4
	call_if 0x1, Route110_EventScript_001E9705
	removeobject 0x24
	setvar 0x40DA, 0x2
	releaseall
	end

Route110_EventScript_001E96B8::
	applymovement 0x24, 0x081E9714
	waitmovement 0x0
	return

Route110_EventScript_001E96C3::
	applymovement 0x24, 0x081E9719
	waitmovement 0x0
	return

Route110_EventScript_001E96CE::
	applymovement 0x24, 0x081E971D
	waitmovement 0x0
	return

Route110_EventScript_001E96D9::
	applymovement 0x24, 0x081E9720
	waitmovement 0x0
	return

Route110_EventScript_001E96E4::
	applymovement 0x24, 0x081E9724
	waitmovement 0x0
	return

Route110_EventScript_001E96EF::
	applymovement 0x24, 0x081E972B
	waitmovement 0x0
	return

Route110_EventScript_001E96FA::
	applymovement 0x24, 0x081E9731
	waitmovement 0x0
	return

Route110_EventScript_001E9705::
	applymovement 0x24, 0x081E9737
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1e9710, 0xa3d
