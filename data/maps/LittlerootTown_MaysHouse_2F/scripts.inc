@ LittlerootTown_MaysHouse_2F scripts (JP map g1 m3 @ 0x081F0AE2)

LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_EventScript_001F0AED
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_MapScriptTable_001F0B69
	.byte 0

LittlerootTown_MaysHouse_2F_EventScript_001F0AED::
	compare_var_to_value 0x408D, 0x2
	call_if 0x0, LittlerootTown_MaysHouse_2F_EventScript_001F0B56
	compare_var_to_value 0x408D, 0x3
	call_if 0x4, LittlerootTown_MaysHouse_2F_EventScript_001F0B19
	compare_var_to_value 0x4092, 0x4
	call_if 0x1, 0x08257EE8
	call 0x08245D90
	setvar 0x4089, 0x0
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0B19::
	checkflag 0x124
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0B32
	compare_var_to_value 0x4084, 0x2
	goto_if 0x4, LittlerootTown_MaysHouse_2F_EventScript_001F0B55
	goto LittlerootTown_MaysHouse_2F_EventScript_001F0B32

LittlerootTown_MaysHouse_2F_EventScript_001F0B32::
	checkplayergender
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0B55
	compare_var_to_value 0x40D3, 0x2
	goto_if 0x4, LittlerootTown_MaysHouse_2F_EventScript_001F0B55
	setobjectxyperm 0x1, 0x8, 0x2
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0B55::
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0B56::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0B63
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0B63::
	setvar 0x408D, 0x2
	return

LittlerootTown_MaysHouse_2F_MapScriptTable_001F0B69::
	map_script_2 0x4089, 0x0, LittlerootTown_MaysHouse_2F_EventScript_001F0B73
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_001F0B73::
	checkplayergender
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x08245DBB
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0B80::
	lockall
	compare_var_to_value 0x408D, 0x2
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0B96
	loadword 0x0, 0x081F10B0
	callstd 0x4
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0B96::
	delay 0xA
	addobject 0x1
	applymovement 0x1, 0x081F0CBB
	waitmovement 0x0
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	delay 0xA
	playbgm 0x19F, 0x1
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0C06
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0C35
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0C64
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0C8C
	setvar 0x408D, 0x3
	setflag 0x332
	clearflag 0x2D2
	setvar 0x4050, 0x1
	savebgm 0x0
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0C06::
	applymovement 0x1, 0x081F0CBF
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, 0x081F0DE8
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F0CCF
	applymovement 0x1, 0x081F0CC5
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0C35::
	applymovement 0x1, 0x081F0CD7
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, 0x081F0DE8
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F0CE3
	applymovement 0x1, 0x081F0CDB
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0C64::
	applymovement 0x1, 0x081F0CE9
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, 0x081F0DE8
	callstd 0x4
	closemessage
	applymovement 0x1, 0x081F0CF0
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0C8C::
	applymovement 0x1, 0x081F0CF9
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, 0x081F0DE8
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F0D07
	applymovement 0x1, 0x081F0CFE
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1f0cbb, 0x52
LittlerootTown_MaysHouse_2F_EventScript_001F0D0D::
	lockall
	checkflag 0x124
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D43
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D2F
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D39
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0D2F::
	loadword 0x0, 0x081F0F40
	callstd 0x4
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0D39::
	loadword 0x0, 0x081F108B
	callstd 0x4
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0D43::
	applymovement 0x800F, 0x08243621
	waitmovement 0x0
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D69
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D7B
	setflag 0x125
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0D69::
	checkflag 0x125
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D8D
	loadword 0x0, 0x081F10CD
	callstd 0x4
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0D7B::
	checkflag 0x125
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0D96
	loadword 0x0, 0x081F117C
	callstd 0x4
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0D8D::
	loadword 0x0, 0x081F1142
	callstd 0x4
	return

LittlerootTown_MaysHouse_2F_EventScript_001F0D96::
	loadword 0x0, 0x081F11E3
	callstd 0x4
	return

LittlerootTown_MaysHouse_2F_EventScript_PC:: @ 0x081F0D9F
LittlerootTown_MaysHouse_2F_EventScript_001F0D9F::
	lockall
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0DB8
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_MaysHouse_2F_EventScript_001F0DC2
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0DB8::
	loadword 0x0, 0x08243AA2
	callstd 0x4
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_001F0DC2::
	setvar 0x8004, 0x2
	special DoLotteryCornerComputerEffect
	playse 0x4
	loadword 0x0, 0x08243B10
	callstd 0x4
	special BedroomPC
	releaseall
	end

gUnknown_81F0DDB:: @ 0x081F0DDB
	.incbin "baserom_jp.gba", 0x1f0ddb, 0x451
