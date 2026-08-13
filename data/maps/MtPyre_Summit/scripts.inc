@ MtPyre_Summit scripts (JP map g24 m22 @ 0x08216B74)

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_EventScript_00216B7A
	.byte 0

MtPyre_Summit_EventScript_00216B7A::
	compare_var_to_value 0x40B9, 0x2
	call_if 0x1, MtPyre_Summit_EventScript_00216B86
	end

MtPyre_Summit_EventScript_00216B86::
	setobjectxyperm 0x8, 0x17, 0x6
	setobjectxyperm 0x2, 0x16, 0x6
	end

MtPyre_Summit_EventScript_00216B95::
	lockall
	setvar 0x8008, 0x0
	goto MtPyre_Summit_EventScript_00216BB9
	end

MtPyre_Summit_EventScript_00216BA1::
	lockall
	setvar 0x8008, 0x1
	goto MtPyre_Summit_EventScript_00216BB9
	end

MtPyre_Summit_EventScript_00216BAD::
	lockall
	setvar 0x8008, 0x2
	goto MtPyre_Summit_EventScript_00216BB9
	end

MtPyre_Summit_EventScript_00216BB9::
	playbgm 0x1A3, 0x0
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	applymovement 0x2, 0x0824362D
	waitmovement 0x0
	delay 0x32
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216C5D
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216C68
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, MtPyre_Summit_EventScript_00216C69
	loadword 0x0, 0x0821720D
	callstd 0x4
	closemessage
	fadescreen 0x1
	removeobject 0x2
	removeobject 0x4
	removeobject 0x5
	removeobject 0x6
	removeobject 0x7
	setflag 0x394
	setflag 0x395
	fadedefaultbgm
	fadescreen 0x0
	delay 0x14
	setvar 0x40B9, 0x1
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216C74
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216C89
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, MtPyre_Summit_EventScript_00216C94
	loadword 0x0, 0x082172A1
	callstd 0x4
	setorcopyvar 0x8000, 0x177
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0xD4
	setflag 0x34F
	releaseall
	end

MtPyre_Summit_EventScript_00216C5D::
	applymovement 0x2, 0x08216CB3
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216C68::
	return

MtPyre_Summit_EventScript_00216C69::
	applymovement 0x2, 0x08216CB6
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216C74::
	applymovement 0x3, 0x08216CA9
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216C89::
	applymovement 0x3, 0x08216CAD
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216C94::
	applymovement 0x3, 0x08216CAF
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x216ca9, 0x10
MtPyre_Summit_EventScript_00216CB9::
	lock
	faceplayer
	checkflag 0x9E
	goto_if 0x1, MtPyre_Summit_EventScript_00216CE4
	loadword 0x0, 0x082175A3
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216D04
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216D0D
	release
	end

MtPyre_Summit_EventScript_00216CE4::
	loadword 0x0, 0x082177A2
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216D16
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216D0D
	release
	end

MtPyre_Summit_EventScript_00216D04::
	loadword 0x0, 0x08217647
	callstd 0x4
	return

MtPyre_Summit_EventScript_00216D0D::
	loadword 0x0, 0x0821776F
	callstd 0x4
	return

MtPyre_Summit_EventScript_00216D16::
	loadword 0x0, 0x08217814
	callstd 0x4
	return

MtPyre_Summit_EventScript_00216D1F::
	lock
	faceplayer
	checkflag 0x103
	goto_if 0x1, MtPyre_Summit_EventScript_00216D5F
	compare_var_to_value 0x40B9, 0x3
	call_if 0x4, MtPyre_Summit_EventScript_00216D48
	checkflag 0x81
	goto_if 0x1, MtPyre_Summit_EventScript_00216D55
	loadword 0x0, 0x082173D9
	callstd 0x4
	release
	end

MtPyre_Summit_EventScript_00216D48::
	loadword 0x0, 0x082174D8
	callstd 0x4
	setflag 0x103
	release
	end

MtPyre_Summit_EventScript_00216D55::
	loadword 0x0, 0x08217423
	callstd 0x4
	release
	end

MtPyre_Summit_EventScript_00216D5F::
	loadword 0x0, 0x0821751A
	callstd 0x4
	release
	end

MtPyre_Summit_EventScript_00216D69::
	lockall
	setvar 0x8008, 0x0
	goto MtPyre_Summit_EventScript_00216D8D
	end

MtPyre_Summit_EventScript_00216D75::
	lockall
	setvar 0x8008, 0x1
	goto MtPyre_Summit_EventScript_00216D8D
	end

MtPyre_Summit_EventScript_00216D81::
	lockall
	setvar 0x8008, 0x2
	goto MtPyre_Summit_EventScript_00216D8D
	end

MtPyre_Summit_EventScript_00216D8D::
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	delay 0x3C
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216E41
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216E5A
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, MtPyre_Summit_EventScript_00216E73
	playse 0x15
	applymovement 0x8, 0x0824361B
	waitmovement 0x0
	applymovement 0x8, 0x0824361D
	waitmovement 0x0
	delay 0x1E
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216E8C
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216EA5
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, MtPyre_Summit_EventScript_00216EBE
	loadword 0x0, 0x08217786
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, MtPyre_Summit_EventScript_00216ED7
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, MtPyre_Summit_EventScript_00216EF3
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, MtPyre_Summit_EventScript_00216F0F
	delay 0x1E
	applymovement 0x2, 0x08216F33
	applymovement 0x8, 0x08216F3A
	waitmovement 0x0
	removeobject 0x2
	removeobject 0x8
	setvar 0x40B9, 0x3
	releaseall
	end

MtPyre_Summit_EventScript_00216E41::
	applymovement 0xFF, 0x08216F41
	applymovement 0x2, 0x08216F33
	applymovement 0x8, 0x08216F3A
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216E5A::
	applymovement 0xFF, 0x08216F48
	applymovement 0x2, 0x08216F33
	applymovement 0x8, 0x08216F3A
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216E73::
	applymovement 0xFF, 0x08216F4F
	applymovement 0x2, 0x08216F33
	applymovement 0x8, 0x08216F3A
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216E8C::
	applymovement 0xFF, 0x08216F2B
	applymovement 0x2, 0x08216F64
	applymovement 0x8, 0x08216F55
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216EA5::
	applymovement 0xFF, 0x08216F2F
	applymovement 0x2, 0x08216F64
	applymovement 0x8, 0x08216F5A
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216EBE::
	applymovement 0xFF, 0x08216F2F
	applymovement 0x2, 0x08216F64
	applymovement 0x8, 0x08216F5F
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216ED7::
	applymovement 0xFF, 0x08216F67
	applymovement 0x8, 0x08216F6A
	waitmovement 0x0
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216EF3::
	applymovement 0xFF, 0x08216F67
	applymovement 0x8, 0x08216F70
	waitmovement 0x0
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	return

MtPyre_Summit_EventScript_00216F0F::
	applymovement 0xFF, 0x08216F67
	applymovement 0x8, 0x08216F75
	waitmovement 0x0
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x216f2b, 0xd85
