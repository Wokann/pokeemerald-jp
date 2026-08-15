@ LittlerootTown_BrendansHouse_2F scripts (JP map g1 m1 @ 0x081EFF92)

LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_EventScript_001EFF9D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_MapScriptTable_001F0019
	.byte 0

LittlerootTown_BrendansHouse_2F_EventScript_001EFF9D::
	compare_var_to_value 0x408D, 0x2
	call_if 0x0, LittlerootTown_BrendansHouse_2F_EventScript_001F0006
	compare_var_to_value 0x408D, 0x3
	call_if 0x4, LittlerootTown_BrendansHouse_2F_EventScript_001EFFC9
	compare_var_to_value 0x4092, 0x4
	call_if 0x1, 0x08257EE8
	call 0x08245D90
	setvar 0x4089, 0x0
	end

LittlerootTown_BrendansHouse_2F_EventScript_001EFFC9::
	checkflag 0x124
	goto_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001EFFE2
	compare_var_to_value 0x4084, 0x2
	goto_if 0x4, LittlerootTown_BrendansHouse_2F_EventScript_001F0005
	goto LittlerootTown_BrendansHouse_2F_EventScript_001EFFE2

LittlerootTown_BrendansHouse_2F_EventScript_001EFFE2::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F0005
	compare_var_to_value 0x40D3, 0x2
	goto_if 0x4, 0x081F0B55
	setobjectxyperm 0x1, 0x0, 0x2
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_BrendansHouse_2F_EventScript_001F0005::
	return

LittlerootTown_BrendansHouse_2F_EventScript_001F0006::
	checkplayergender
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F0013
	return

LittlerootTown_BrendansHouse_2F_EventScript_001F0013::
	setvar 0x408D, 0x2
	return

LittlerootTown_BrendansHouse_2F_MapScriptTable_001F0019::
	map_script_2 0x4089, 0x0, LittlerootTown_BrendansHouse_2F_EventScript_001F0023
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_001F0023::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x08245DBB
	end

LittlerootTown_BrendansHouse_2F_EventScript_001F0030::
	lockall
	compare_var_to_value 0x408D, 0x2
	goto_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F0046
	loadword 0x0, 0x081F10B0
	callstd 0x4
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_001F0046::
	delay 0xA
	addobject 0x1
	applymovement 0x1, 0x081F016B
	waitmovement 0x0
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	delay 0xA
	playbgm 0x1A5, 0x1
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F00B6
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F00E5
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F0114
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F0143
	setvar 0x408D, 0x3
	setflag 0x331
	clearflag 0x2F8
	setvar 0x4050, 0x1
	savebgm 0x0
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_001F00B6::
	applymovement 0x1, 0x081F016F
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, 0x081F0F62
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F017E
	applymovement 0x1, 0x081F0175
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_2F_EventScript_001F00E5::
	applymovement 0x1, 0x081F0186
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, 0x081F0F62
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F0191
	applymovement 0x1, 0x081F018A
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_2F_EventScript_001F0114::
	applymovement 0x1, 0x081F0197
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, 0x081F0F62
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F01A5
	applymovement 0x1, 0x081F019C
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_2F_EventScript_001F0143::
	applymovement 0x1, 0x081F01AC
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, 0x081F0F62
	callstd 0x4
	closemessage
	applymovement 0x1, 0x081F01B3
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1f016b, 0x51
LittlerootTown_BrendansHouse_2F_EventScript_PC:: @ 0x081F01BC
LittlerootTown_BrendansHouse_2F_EventScript_001F01BC::
	lockall
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F01D5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_BrendansHouse_2F_EventScript_001F01FB
	end

LittlerootTown_BrendansHouse_2F_EventScript_001F01D5::
	setvar 0x8004, 0x1
	special DoLotteryCornerComputerEffect
	playse 0x4
	loadword 0x0, 0x08243B10
	callstd 0x4
	special BedroomPC
	releaseall
	end

gUnknown_81F01EE:: @ 0x081F01EE
	.incbin "baserom_jp.gba", 0x1f01ee, 0xd
LittlerootTown_BrendansHouse_2F_EventScript_001F01FB::
	loadword 0x0, 0x08243AA2
	callstd 0x4
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_001F0205::
	loadword 0x0, 0x081F02A6
	callstd 0x3
	end

LittlerootTown_BrendansHouse_2F_EventScript_001F020E::
	loadword 0x0, 0x081F0328
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1f0217, 0x141
