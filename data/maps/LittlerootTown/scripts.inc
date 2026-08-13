@ LittlerootTown scripts (JP map g0 m9 @ 0x081E39F5)

LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_EventScript_001E3A05
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScriptTable_001E3AEB
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScriptTable_001E3C0C
	.byte 0

LittlerootTown_EventScript_001E3A05::
	setflag 0x86F
	call 0x08242F63
	compare_var_to_value 0x4092, 0x2
	call_if 0x1, LittlerootTown_EventScript_001E3A91
	checkflag 0x52
	call_if 0x0, LittlerootTown_EventScript_001E3A99
	compare_var_to_value 0x4050, 0x3
	call_if 0x1, LittlerootTown_EventScript_001E3ABC
	compare_var_to_value 0x4082, 0x4
	call_if 0x1, LittlerootTown_EventScript_001E3A86
	compare_var_to_value 0x408C, 0x4
	call_if 0x1, LittlerootTown_EventScript_001E3A86
	compare_var_to_value 0x40C7, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3A7D
	compare_var_to_value 0x408D, 0x3
	call_if 0x1, LittlerootTown_EventScript_001E3A79
	compare_var_to_value 0x40D3, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3A75
	compare_var_to_value 0x40D3, 0x2
	call_if 0x1, LittlerootTown_EventScript_001E3A6F
	end

LittlerootTown_EventScript_001E3A6F::
	setvar 0x40D3, 0x3
	return

LittlerootTown_EventScript_001E3A75::
	setflag 0x4000
	return

LittlerootTown_EventScript_001E3A79::
	setflag 0x12D
	return

LittlerootTown_EventScript_001E3A7D::
	setvar 0x40C7, 0x2
	setflag 0x3D3
	return

LittlerootTown_EventScript_001E3A86::
	setvar 0x4082, 0x5
	setvar 0x408C, 0x5
	return

LittlerootTown_EventScript_001E3A91::
	setobjectxyperm 0x4, 0xE, 0x8
	return

LittlerootTown_EventScript_001E3A99::
	compare_var_to_value 0x4050, 0x0
	goto_if 0x1, LittlerootTown_EventScript_001E3AB0
	setobjectxyperm 0x1, 0xA, 0x1
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_EventScript_001E3AB0::
	setobjectxyperm 0x1, 0x7, 0x2
	setobjectmovementtype 0x1, 0x8
	return

LittlerootTown_EventScript_001E3ABC::
	clearflag 0x2F0
	setobjectmovementtype 0x4, 0x8
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3ADB
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3AE3
	return

LittlerootTown_EventScript_001E3ADB::
	setobjectxyperm 0x4, 0x5, 0x9
	return

LittlerootTown_EventScript_001E3AE3::
	setobjectxyperm 0x4, 0xE, 0x9
	return

LittlerootTown_MapScriptTable_001E3AEB::
	map_script_2 0x4092, 0x1, LittlerootTown_EventScript_001E3B05
	map_script_2 0x4092, 0x2, LittlerootTown_EventScript_001E3B23
	map_script_2 0x40D3, 0x1, LittlerootTown_EventScript_001E3BDB
	.2byte 0

LittlerootTown_EventScript_001E3B05::
	lockall
	setvar 0x8004, 0x5
	setvar 0x8005, 0x8
	call LittlerootTown_EventScript_001E3B41
	setflag 0x2F9
	warpsilent 0x100, 0xFF, 0x8, 0x8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_001E3B23::
	lockall
	setvar 0x8004, 0xE
	setvar 0x8005, 0x8
	call LittlerootTown_EventScript_001E3B41
	setflag 0x2FA
	warpsilent 0x102, 0xFF, 0x2, 0x8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_001E3B41::
	delay 0xF
	playse 0xA
	applymovement 0xFF, 0x081E3BD6
	waitmovement 0x0
	opendoor 0x8004, 0x8005
	waitmoncry
	addobject 0x4
	applymovement 0x4, 0x081E3BC2
	waitmovement 0x0
	closedoor 0x8004, 0x8005
	waitmoncry
	delay 0xA
	applymovement 0x4, 0x081E3BC4
	waitmovement 0x0
	loadword 0x0, gJPText_001E42E6
	callstd 0x4
	closemessage
	applymovement 0x4, 0x081E3BC7
	applymovement 0xFF, 0x081E3BCE
	waitmovement 0x0
	opendoor 0x8004, 0x8005
	waitmoncry
	applymovement 0x4, 0x081E3BCB
	applymovement 0xFF, 0x081E3BD3
	waitmovement 0x0
	setflag 0x2F0
	setvar 0x4092, 0x3
	hideobject_at 0xFF, 0x0
	closedoor 0x8004, 0x8005
	waitmoncry
	clearflag 0x364
	clearflag 0x4000
	return

	.incbin "baserom_jp.gba", 0x1e3bc2, 0x19
LittlerootTown_EventScript_001E3BDB::
	lockall
	playse 0x15
	applymovement 0x8, 0x0824361B
	waitmovement 0x0
	delay 0x50
	loadword 0x0, gJPText_001E46EE
	callstd 0x4
	closemessage
	clearflag 0x31A
	clearflag 0x31B
	delay 0x14
	clearflag 0x4000
	warp 0x104, 0xFF, 0x6, 0x5
	waitstate
	releaseall
	end

LittlerootTown_MapScriptTable_001E3C0C::
	map_script_2 0x40D3, 0x1, LittlerootTown_EventScript_001E3C16
	.2byte 0

LittlerootTown_EventScript_001E3C16::
	addobject 0x8
	addobject 0x7
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_EventScript_001E3C2E
	goto LittlerootTown_EventScript_001E3C3D
	end

LittlerootTown_EventScript_001E3C2E::
	setobjectxy 0x7, 0x6, 0xA
	setobjectxy 0x8, 0x5, 0xA
	end

LittlerootTown_EventScript_001E3C3D::
	setobjectxy 0x7, 0xD, 0xA
	setobjectxy 0x8, 0xE, 0xA
	end

LittlerootTown_EventScript_001E3C4C::
	loadword 0x0, 0x081E452C
	callstd 0x2
	end

LittlerootTown_EventScript_001E3C55::
	loadword 0x0, 0x081E4560
	callstd 0x2
	end

LittlerootTown_EventScript_001E3C5E::
	lock
	faceplayer
	checkflag 0x74
	goto_if 0x1, LittlerootTown_EventScript_001E3CB1
	checkflag 0x52
	goto_if 0x1, LittlerootTown_EventScript_001E3CA4
	compare_var_to_value 0x4050, 0x0
	goto_if 0x5, LittlerootTown_EventScript_001E3C87
	loadword 0x0, 0x081E45BC
	callstd 0x4
	release
	end

LittlerootTown_EventScript_001E3C87::
	special GetPlayerBigGuyGirlString
	loadword 0x0, 0x081E460A
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243625
	waitmovement 0x0
	setvar 0x4050, 0x2
	release
	end

LittlerootTown_EventScript_001E3CA4::
	special GetPlayerBigGuyGirlString
	loadword 0x0, 0x081E4671
	callstd 0x4
	release
	end

LittlerootTown_EventScript_001E3CB1::
	loadword 0x0, 0x081E468B
	callstd 0x4
	release
	end

LittlerootTown_EventScript_001E3CBB::
	lockall
	applymovement 0x1, 0x081E3CFB
	waitmovement 0x0
	call LittlerootTown_EventScript_001E3CD7
	applymovement 0x1, 0x081E3D0B
	waitmovement 0x0
	releaseall
	end

LittlerootTown_EventScript_001E3CD7::
	loadword 0x0, 0x081E45BC
	callstd 0x4
	closemessage
	applymovement 0x1, 0x081E3D09
	applymovement 0xFF, 0x081E3D15
	waitmovement 0x0
	loadword 0x0, 0x081E45F1
	callstd 0x4
	closemessage
	return

	.incbin "baserom_jp.gba", 0x1e3cfb, 0x1e
LittlerootTown_EventScript_001E3D19::
	lockall
	applymovement 0x1, 0x081E3D35
	waitmovement 0x0
	call LittlerootTown_EventScript_001E3CD7
	applymovement 0x1, 0x081E3D42
	waitmovement 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e3d35, 0x14
LittlerootTown_EventScript_001E3D49::
	lockall
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	special GetPlayerBigGuyGirlString
	loadword 0x0, 0x081E460A
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243625
	waitmovement 0x0
	setvar 0x4050, 0x2
	releaseall
	end

LittlerootTown_EventScript_001E3D7B::
	loadword 0x0, 0x081E46A4
	callstd 0x3
	end

LittlerootTown_EventScript_001E3D84::
	loadword 0x0, 0x081E46C2
	callstd 0x3
	end

LittlerootTown_EventScript_001E3D8D::
	lockall
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3DA7
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3DB0
	releaseall
	end

LittlerootTown_EventScript_001E3DA7::
	loadword 0x0, 0x081E46D6
	callstd 0x4
	return

LittlerootTown_EventScript_001E3DB0::
	loadword 0x0, 0x081E46DF
	callstd 0x4
	return

LittlerootTown_EventScript_001E3DB9::
	lockall
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3DD3
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3DDC
	releaseall
	end

LittlerootTown_EventScript_001E3DD3::
	loadword 0x0, 0x081E46DF
	callstd 0x4
	return

LittlerootTown_EventScript_001E3DDC::
	loadword 0x0, 0x081E46D6
	callstd 0x4
	return

LittlerootTown_EventScript_001E3DE5::
	lockall
	setvar 0x8008, 0x0
	setobjectxy 0x4, 0xA, 0x9
	goto LittlerootTown_EventScript_001E3E3B
	end

LittlerootTown_EventScript_001E3DF8::
	lockall
	setvar 0x8008, 0x1
	setobjectxy 0x4, 0xB, 0x9
	goto LittlerootTown_EventScript_001E3E3B
	end

LittlerootTown_EventScript_001E3E0B::
	lockall
	setvar 0x8008, 0x2
	goto LittlerootTown_EventScript_001E3E3B
	end

LittlerootTown_EventScript_001E3E17::
	lockall
	setvar 0x8008, 0x3
	goto LittlerootTown_EventScript_001E3E3B
	end

LittlerootTown_EventScript_001E3E23::
	lockall
	setvar 0x8008, 0x4
	goto LittlerootTown_EventScript_001E3E3B
	end

LittlerootTown_EventScript_001E3E2F::
	lockall
	setvar 0x8008, 0x5
	goto LittlerootTown_EventScript_001E3E3B
	end

LittlerootTown_EventScript_001E3E3B::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3EC1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3ECC
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3EAB
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3EB6
	loadword 0x0, 0x081E437D
	callstd 0x4
	closemessage
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3ED7
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3F1A
	call LittlerootTown_EventScript_001E42BD
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E402F
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E4072
	goto LittlerootTown_EventScript_001E42B0
	end

LittlerootTown_EventScript_001E3EAB::
	setvar 0x8009, 0x5
	setvar 0x800A, 0x8
	return

LittlerootTown_EventScript_001E3EB6::
	setvar 0x8009, 0xE
	setvar 0x800A, 0x8
	return

LittlerootTown_EventScript_001E3EC1::
	applymovement 0x4, 0x0824362B
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3ECC::
	applymovement 0x4, 0x08243627
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3ED7::
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3F5D
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3F72
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_EventScript_001E3F87
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, LittlerootTown_EventScript_001E3F9C
	compare_var_to_value 0x8008, 0x4
	call_if 0x1, LittlerootTown_EventScript_001E3FB1
	compare_var_to_value 0x8008, 0x5
	call_if 0x1, LittlerootTown_EventScript_001E3FC6
	return

LittlerootTown_EventScript_001E3F1A::
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3F5D
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3F72
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_EventScript_001E3FDB
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, LittlerootTown_EventScript_001E3FF0
	compare_var_to_value 0x8008, 0x4
	call_if 0x1, LittlerootTown_EventScript_001E4005
	compare_var_to_value 0x8008, 0x5
	call_if 0x1, LittlerootTown_EventScript_001E401A
	return

LittlerootTown_EventScript_001E3F5D::
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	applymovement 0x4, 0x081E41FB
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3F72::
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	applymovement 0x4, 0x081E4202
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3F87::
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	applymovement 0x4, 0x081E4209
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3F9C::
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	applymovement 0x4, 0x081E420E
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3FB1::
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	applymovement 0x4, 0x081E4214
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3FC6::
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	applymovement 0x4, 0x081E4217
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3FDB::
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	applymovement 0x4, 0x081E421B
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E3FF0::
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	applymovement 0x4, 0x081E421F
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E4005::
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	applymovement 0x4, 0x081E4222
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E401A::
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	applymovement 0x4, 0x081E4228
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E402F::
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E40B5
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E40C0
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_EventScript_001E40CB
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, LittlerootTown_EventScript_001E40F1
	compare_var_to_value 0x8008, 0x4
	call_if 0x1, LittlerootTown_EventScript_001E4117
	compare_var_to_value 0x8008, 0x5
	call_if 0x1, LittlerootTown_EventScript_001E413D
	return

LittlerootTown_EventScript_001E4072::
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E40B5
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E40C0
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_EventScript_001E4163
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, LittlerootTown_EventScript_001E4189
	compare_var_to_value 0x8008, 0x4
	call_if 0x1, LittlerootTown_EventScript_001E41AF
	compare_var_to_value 0x8008, 0x5
	call_if 0x1, LittlerootTown_EventScript_001E41D5
	return

LittlerootTown_EventScript_001E40B5::
	applymovement 0x4, 0x081E422D
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E40C0::
	applymovement 0x4, 0x081E4233
	waitmovement 0x0
	return

LittlerootTown_EventScript_001E40CB::
	applymovement 0x4, 0x081E4239
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E40F1::
	applymovement 0x4, 0x081E423F
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E4117::
	applymovement 0x4, 0x081E4246
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E413D::
	applymovement 0x4, 0x081E424A
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E4163::
	applymovement 0x4, 0x081E424F
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E4189::
	applymovement 0x4, 0x081E4254
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E41AF::
	applymovement 0x4, 0x081E4258
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

LittlerootTown_EventScript_001E41D5::
	applymovement 0x4, 0x081E425F
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	return

	.incbin "baserom_jp.gba", 0x1e41fb, 0x6c
LittlerootTown_EventScript_001E4267::
	lock
	faceplayer
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_EventScript_001E3EAB
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_EventScript_001E3EB6
	call LittlerootTown_EventScript_001E42BD
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	opendoor 0x8009, 0x800A
	waitmoncry
	applymovement 0x4, 0x081E4265
	waitmovement 0x0
	hideobject_at 0x4, 0x9
	closedoor 0x8009, 0x800A
	waitmoncry
	goto LittlerootTown_EventScript_001E42B0
	end

LittlerootTown_EventScript_001E42B0::
	removeobject 0x4
	setflag 0x8C0
	setvar 0x4050, 0x4
	release
	end

LittlerootTown_EventScript_001E42BD::
	loadword 0x0, 0x081E4388
	callstd 0x4
	playfanfare 0x172
	message 0x081E4432
	waitfanfare
	setflag 0x112
	loadword 0x0, 0x081E4448
	callstd 0x4
	loadword 0x0, 0x081E44B3
	callstd 0x4
	closemessage
	delay 0x1E
	return

	.globl gJPText_001E42E6
gJPText_001E42E6: @ 0x081E42E6
	.string "ママ“{MUS_RG_VS_TRAINER}　おつかれさま！\p"
	.string "ながいあいだ　トラックに　ゆられて\n"
	.string "たいへん　だったでしょ？\p"
	.string "ここが　ミシロタウンよ！\p"
	.string "どう？　これが　わたしたちの\n"
	.string "あたらしい　おうち！\p"
	.string "ちょっと　こふうな　かんじで\n"
	.string "すみやすそうな　ところ　でしょ？\p"
	.string "こんどは　{MUS_RG_VS_TRAINER}の　おへやも　あるのよ！\n"
	.string "さあ　なかに　はいりましょ！$"

	.incbin "baserom_jp.gba", 0x1e437d, 0x371
	.globl gJPText_001E46EE
gJPText_001E46EE: @ 0x081E46EE
	.string "オダマキ“いやー　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\n"
	.string "それにしても　みごと　だったね\p"
	.string "さいしょに　きみを　みたときから\n"
	.string "ただもの　ではないと　おもったけど\l"
	.string "まさか　これほど　とはねえ\p"
	.string "そうそう！\n"
	.string "きみに　あげた　ポケモンずかん\l"
	.string "まだ　もってるよね？\p"
	.string "ちょっと　はなしが　あるから\n"
	.string "いっしょに　けんきゅうじょまで　おいで$"

