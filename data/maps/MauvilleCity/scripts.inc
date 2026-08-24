@ MauvilleCity scripts (JP map g0 m2 @ 0x081DD9BE)

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_EventScript_001DD9C4
	.byte 0

MauvilleCity_EventScript_001DD9C4::
	setflag 0x878
	clearflag 0x9D
	clearflag 0x3C1
	setflag 0x892
	clearflag 0x63
	setvar 0x4093, 0x0
	checkflag 0xD1
	call_if 0x1, MauvilleCity_EventScript_001DD9E2
	end

MauvilleCity_EventScript_001DD9E2::
	clearflag 0x391
	setflag 0x390
	setflag 0x5B
	return

MauvilleCity_EventScript_001DD9EC::
	loadword 0x0, 0x081DE4C1
	callstd 0x2
	end

MauvilleCity_EventScript_001DD9F5::
	loadword 0x0, 0x081DE509
	callstd 0x2
	end

MauvilleCity_EventScript_001DD9FE::
	loadword 0x0, 0x081DE53B
	callstd 0x2
	end

MauvilleCity_EventScript_001DDA07::
	loadword 0x0, 0x081DE578
	callstd 0x2
	end

MauvilleCity_EventScript_001DDA10::
	loadword 0x0, 0x081DE59B
	callstd 0x3
	end

MauvilleCity_EventScript_001DDA19::
	loadword 0x0, 0x081DE5BA
	callstd 0x3
	end

MauvilleCity_EventScript_001DDA22::
	loadword 0x0, 0x081DE5E4
	callstd 0x3
	end

MauvilleCity_EventScript_001DDA2B::
	loadword 0x0, 0x081DE608
	callstd 0x3
	end

MauvilleCity_EventScript_001DDA34::
	lock
	faceplayer
	checkflag 0x62
	goto_if 0x1, MauvilleCity_EventScript_001DDA4C
	loadword 0x0, 0x081DE62C
	callstd 0x4
	setflag 0x62
	release
	end

MauvilleCity_EventScript_001DDA4C::
	loadword 0x0, 0x081DE6DE
	callstd 0x4
	release
	end

MauvilleCity_EventScript_001DDA56::
	lock
	faceplayer
	checkflag 0x11C
	goto_if 0x1, MauvilleCity_EventScript_001DDA76
	loadword 0x0, 0x081DDE15
	callstd 0x4
	closemessage
	applymovement 0x7, 0x08243625
	waitmovement 0x0
	release
	end

MauvilleCity_EventScript_001DDA76::
	loadword 0x0, 0x081DDFD3
	callstd 0x4
	closemessage
	applymovement 0x7, 0x08243625
	waitmovement 0x0
	release
	end

MauvilleCity_EventScript_001DDA8B::
	lockall
	checkflag 0x11C
	goto_if 0x1, MauvilleCity_EventScript_001DDCC9
	applymovement 0x6, 0x0824362B
	waitmovement 0x0
	loadword 0x0, 0x081DDE51
	callstd 0x4
	loadword 0x0, 0x081DDE96
	callstd 0x4
	loadword 0x0, 0x081DDF00
	callstd 0x4
	applymovement 0x6, 0x08243621
	waitmovement 0x0
	playse 0x15
	applymovement 0x6, 0x0824361B
	waitmovement 0x0
	applymovement 0x6, 0x0824361D
	waitmovement 0x0
	loadword 0x0, 0x081DDF37
	callstd 0x5
	goto MauvilleCity_EventScript_001DDAE6
	end

MauvilleCity_EventScript_001DDAE6::
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, 0x081DDC73
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MauvilleCity_EventScript_001DDCBC
	closemessage
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, MauvilleCity_EventScript_001DDB19
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, MauvilleCity_EventScript_001DDB76
	end

MauvilleCity_EventScript_001DDB19::
	applymovement 0xFF, 0x081DDD18
	applymovement 0x6, 0x081DDCE1
	applymovement 0x7, 0x081DDD1B
	waitmovement 0x0
	applymovement 0x6, 0x0824362B
	waitmovement 0x0
	delay 0x1E
	applymovement 0xFF, 0x081DDD27
	applymovement 0x7, 0x081DDD2C
	waitmovement 0x0
	loadword 0x0, 0x081DE142
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081DDD05
	applymovement 0x7, 0x081DDD33
	applymovement 0x6, 0x081DDCED
	waitmovement 0x0
	goto MauvilleCity_EventScript_001DDBCC
	end

MauvilleCity_EventScript_001DDB76::
	applymovement 0xFF, 0x081DDD15
	applymovement 0x6, 0x081DDCE7
	applymovement 0x7, 0x081DDD21
	waitmovement 0x0
	applymovement 0x6, 0x0824362B
	waitmovement 0x0
	delay 0x1E
	applymovement 0x7, 0x081DDD30
	waitmovement 0x0
	loadword 0x0, 0x081DE142
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081DDD09
	applymovement 0x7, 0x081DDD3C
	applymovement 0x6, 0x081DDCF9
	waitmovement 0x0
	goto MauvilleCity_EventScript_001DDBCC
	end

MauvilleCity_EventScript_001DDBCC::
	removeobject 0x6
	removeobject 0x7
	clearflag 0x326
	clearflag 0x329
	setflag 0xBE
	setvar 0x40F2, 0x0
	setflag 0x88
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, MauvilleCity_EventScript_001DDC2C
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, MauvilleCity_EventScript_001DDC3A
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	loadword 0x0, 0x081DE235
	callstd 0x4
	closemessage
	addvar 0x40D1, 0x1
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, MauvilleCity_EventScript_001DDC4F
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, MauvilleCity_EventScript_001DDC61
	removeobject 0xB
	releaseall
	end

MauvilleCity_EventScript_001DDC2C::
	addobject 0xB
	applymovement 0xB, 0x081DDD46
	waitmovement 0x0
	return

MauvilleCity_EventScript_001DDC3A::
	setobjectxyperm 0xB, 0xC, 0xD
	addobject 0xB
	applymovement 0xB, 0x081DDD52
	waitmovement 0x0
	return

MauvilleCity_EventScript_001DDC4F::
	applymovement 0xFF, 0x081DDD0E
	applymovement 0xB, 0x081DDD5E
	waitmovement 0x0
	return

MauvilleCity_EventScript_001DDC61::
	applymovement 0xFF, 0x081DDD11
	applymovement 0xB, 0x081DDD68
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1ddc73, 0x49
MauvilleCity_EventScript_001DDCBC::
	setflag 0x11C
	loadword 0x0, 0x081DDF95
	callstd 0x4
	release
	end

MauvilleCity_EventScript_001DDCC9::
	applymovement 0x6, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x081DE01F
	callstd 0x5
	goto MauvilleCity_EventScript_001DDAE6
	end

	.incbin "baserom_jp.gba", 0x1ddce1, 0x92
MauvilleCity_EventScript_001DDD73::
	lock
	faceplayer
	checkflag 0xD1
	goto_if 0x1, MauvilleCity_EventScript_001DDDE9
	compare_var_to_value 0x40BA, 0x2
	goto_if 0x1, MauvilleCity_EventScript_001DDDBD
	checkflag 0xD0
	goto_if 0x1, MauvilleCity_EventScript_001DDDB3
	loadword 0x0, 0x081DE2EE
	callstd 0x4
	setorcopyvar 0x8000, 0x10F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0xD0
	loadword 0x0, 0x081DE3C9
	callstd 0x4
	release
	end

MauvilleCity_EventScript_001DDDB3::
	loadword 0x0, 0x081DE3C9
	callstd 0x4
	release
	end

MauvilleCity_EventScript_001DDDBD::
	loadword 0x0, 0x081DE432
	callstd 0x4
	setorcopyvar 0x8000, 0x138
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xD1
	loadword 0x0, 0x081DE48F
	callstd 0x4
	release
	end

MauvilleCity_EventScript_001DDDE9::
	loadword 0x0, 0x081DE48F
	callstd 0x4
	release
	end

MauvilleCity_EventScript_RegisterWallyCall:: @ 0x081DDDF3
