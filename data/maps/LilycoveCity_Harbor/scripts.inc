@ LilycoveCity_Harbor scripts (JP map g13 m10 @ 0x082094D4)

LilycoveCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_EventScript_002094DA
	.byte 0

LilycoveCity_Harbor_EventScript_002094DA::
	setescapewarp 0x5, 0xFF, 0xC, 0x21
	end

LilycoveCity_Harbor_EventScript_002094E3::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x0, LilycoveCity_Harbor_EventScript_00209A21
	call LilycoveCity_Harbor_EventScript_00209668
	call LilycoveCity_Harbor_EventScript_0020969A
	call LilycoveCity_Harbor_EventScript_002096CC
	call LilycoveCity_Harbor_EventScript_002096FE
	call LilycoveCity_Harbor_EventScript_00209730
	call LilycoveCity_Harbor_EventScript_0020977A
	compare_var_to_value 0x400C, 0x2
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209824
	compare_var_to_value 0x400B, 0x1
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002097C4
	compare_var_to_value 0x400B, 0x2
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002097F4
	compare_var_to_value 0x400B, 0x4
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209824
	compare_var_to_value 0x400B, 0x8
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002098F1
	compare_var_to_value 0x400B, 0x0
	goto_if 0x5, LilycoveCity_Harbor_EventScript_00209921
	goto LilycoveCity_Harbor_EventScript_00209554
	end

LilycoveCity_Harbor_EventScript_00209554::
	compare_var_to_value 0x400A, 0x0
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209A2B
	loadword 0x0, 0x08209BF3
	callstd 0x4
	message 0x08209C52
	waitmessage
	goto LilycoveCity_Harbor_EventScript_00209573
	end

LilycoveCity_Harbor_EventScript_00209573::
	setvar 0x8004, 0x0
	special display_text_and_get_width_internal
	waitstate
	special sub_080E1D6C
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_Harbor_EventScript_0020961D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209645
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002095DD
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002095ED
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002095FD
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, LilycoveCity_Harbor_EventScript_0020960D
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209AFA
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209AFA
	end

LilycoveCity_Harbor_EventScript_002095DD::
	call LilycoveCity_Harbor_EventScript_00209AA0
	warp 0x1A09, 0xFF, 0xD, 0x16
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_002095ED::
	call LilycoveCity_Harbor_EventScript_00209AA0
	warp 0x1A43, 0xFF, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_002095FD::
	call LilycoveCity_Harbor_EventScript_00209AA0
	warp 0x1A3B, 0xFF, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_0020960D::
	call LilycoveCity_Harbor_EventScript_00209AA0
	warp 0x1A38, 0xFF, 0xD, 0x26
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_0020961D::
	loadword 0x0, 0x08209C8F
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209A94
	setvar 0x40B4, 0x5
	call LilycoveCity_Harbor_EventScript_00209AA0
	warp 0x1929, 0xFF, 0x1, 0xA
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_00209645::
	loadword 0x0, 0x08209C9B
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209A94
	call LilycoveCity_Harbor_EventScript_00209AA0
	warp 0x1A04, 0xFF, 0x13, 0x43
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_00209668::
	setvar 0x400E, 0x0
	checkflag 0x8B3
	goto_if 0x0, 0x08244178
	checkitem 0x113, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x08244178
	setvar 0x400E, 0x1
	checkflag 0x1AE
	goto_if 0x1, 0x08244178
	setvar 0x400E, 0x2
	return

LilycoveCity_Harbor_EventScript_0020969A::
	setvar 0x400D, 0x0
	checkflag 0x8D5
	goto_if 0x0, 0x08244178
	checkitem 0x173, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x08244178
	setvar 0x400D, 0x1
	checkflag 0x1AF
	goto_if 0x1, 0x08244178
	setvar 0x400D, 0x2
	return

LilycoveCity_Harbor_EventScript_002096CC::
	setvar 0x400C, 0x0
	checkflag 0x8D6
	goto_if 0x0, 0x08244178
	checkitem 0x178, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x08244178
	setvar 0x400C, 0x1
	checkflag 0x1B0
	goto_if 0x1, 0x08244178
	setvar 0x400C, 0x2
	return

LilycoveCity_Harbor_EventScript_002096FE::
	setvar 0x4009, 0x0
	checkflag 0x8E0
	goto_if 0x0, 0x08244178
	checkitem 0x172, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x08244178
	setvar 0x4009, 0x1
	checkflag 0x1DB
	goto_if 0x1, 0x08244178
	setvar 0x4009, 0x2
	return

LilycoveCity_Harbor_EventScript_00209730::
	setvar 0x400B, 0x0
	compare_var_to_value 0x400E, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209762
	compare_var_to_value 0x400D, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209768
	compare_var_to_value 0x400C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_0020976E
	compare_var_to_value 0x4009, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209774
	return

LilycoveCity_Harbor_EventScript_00209762::
	addvar 0x400B, 0x1
	return

LilycoveCity_Harbor_EventScript_00209768::
	addvar 0x400B, 0x2
	return

LilycoveCity_Harbor_EventScript_0020976E::
	addvar 0x400B, 0x4
	return

LilycoveCity_Harbor_EventScript_00209774::
	addvar 0x400B, 0x8
	return

LilycoveCity_Harbor_EventScript_0020977A::
	setvar 0x400A, 0x0
	compare_var_to_value 0x400E, 0x1
	call_if 0x1, LilycoveCity_Harbor_EventScript_002097AC
	compare_var_to_value 0x400D, 0x1
	call_if 0x1, LilycoveCity_Harbor_EventScript_002097B2
	compare_var_to_value 0x400C, 0x1
	call_if 0x1, LilycoveCity_Harbor_EventScript_002097B8
	compare_var_to_value 0x4009, 0x1
	call_if 0x1, LilycoveCity_Harbor_EventScript_002097BE
	return

LilycoveCity_Harbor_EventScript_002097AC::
	addvar 0x400A, 0x1
	return

LilycoveCity_Harbor_EventScript_002097B2::
	addvar 0x400A, 0x2
	return

LilycoveCity_Harbor_EventScript_002097B8::
	addvar 0x400A, 0x4
	return

LilycoveCity_Harbor_EventScript_002097BE::
	addvar 0x400A, 0x8
	return

LilycoveCity_Harbor_EventScript_002097C4::
	setflag 0x1AE
	loadword 0x0, 0x082634B6
	callstd 0x4
	closemessage
	call LilycoveCity_Harbor_EventScript_002099C2
	loadword 0x0, 0x082634D5
	callstd 0x4
	goto LilycoveCity_Harbor_EventScript_002097E3
	end

LilycoveCity_Harbor_EventScript_002097E3::
	closemessage
	call LilycoveCity_Harbor_EventScript_002099E8
	warp 0x1A09, 0xFF, 0xD, 0x16
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_002097F4::
	setflag 0x1AF
	loadword 0x0, 0x082634B6
	callstd 0x4
	closemessage
	call LilycoveCity_Harbor_EventScript_002099C2
	loadword 0x0, 0x08275D2A
	callstd 0x4
	goto LilycoveCity_Harbor_EventScript_00209813
	end

LilycoveCity_Harbor_EventScript_00209813::
	closemessage
	call LilycoveCity_Harbor_EventScript_002099E8
	warp 0x1A3B, 0xFF, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_00209824::
	setflag 0x1B0
	loadword 0x0, 0x08263476
	callstd 0x4
	closemessage
	call LilycoveCity_Harbor_EventScript_002099C2
	loadword 0x0, 0x08275C60
	callstd 0x4
	closemessage
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	playse 0x15
	applymovement 0x4, 0x0824361B
	waitmovement 0x0
	applymovement 0x4, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B2A
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B35
	addobject 0x5
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B49
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B54
	loadword 0x0, 0x08275CB6
	callstd 0x4
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B5F
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B6A
	loadword 0x0, 0x08275CDA
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B75
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209B8E
	setvar 0x8004, 0x2
	call 0x08243265
	warp 0x1A38, 0xFF, 0xD, 0x26
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_002098E0::
	closemessage
	call LilycoveCity_Harbor_EventScript_002099E8
	warp 0x1A38, 0xFF, 0xD, 0x26
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_002098F1::
	setflag 0x1DB
	loadword 0x0, 0x082634B6
	callstd 0x4
	closemessage
	call LilycoveCity_Harbor_EventScript_002099C2
	loadword 0x0, 0x08275D2A
	callstd 0x4
	goto LilycoveCity_Harbor_EventScript_00209910
	end

LilycoveCity_Harbor_EventScript_00209910::
	closemessage
	call LilycoveCity_Harbor_EventScript_002099E8
	warp 0x1A43, 0xFF, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_00209921::
	loadword 0x0, 0x082634B6
	callstd 0x4
	closemessage
	call LilycoveCity_Harbor_EventScript_002099C2
	message 0x08275DF2
	waitmessage
	setvar 0x8004, 0x1
	special display_text_and_get_width_internal
	waitstate
	special sub_080E1D6C
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002097E3
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209910
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209813
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, LilycoveCity_Harbor_EventScript_002098E0
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, LilycoveCity_Harbor_EventScript_0020998A
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_Harbor_EventScript_0020998A
	release
	end

LilycoveCity_Harbor_EventScript_0020998A::
	loadword 0x0, 0x08263578
	callstd 0x4
	closemessage
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	delay 0x1E
	removeobject 0x4
	delay 0x1E
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	showobject_at 0x1, 0xD0A
	delay 0x1E
	loadword 0x0, 0x08209C81
	callstd 0x4
	release
	end

LilycoveCity_Harbor_EventScript_002099C2::
	applymovement 0x800F, 0x08243629
	waitmovement 0x0
	delay 0x1E
	hideobject_at 0x800F, 0xD0A
	delay 0x3C
	addobject 0x4
	delay 0x1E
	applymovement 0x4, 0x08243621
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_002099E8::
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	delay 0x1E
	removeobject 0x4
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209AEF
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209AE4
	delay 0x1E
	hideobject_at 0xFF, 0x0
	setvar 0x8004, 0x2
	call 0x08243265
	return

LilycoveCity_Harbor_EventScript_00209A21::
	loadword 0x0, 0x08209BC5
	callstd 0x4
	release
	end

LilycoveCity_Harbor_EventScript_00209A2B::
	loadword 0x0, 0x08209BF3
	callstd 0x4
	message 0x08209C52
	waitmessage
	goto LilycoveCity_Harbor_EventScript_00209573
	end

	.incbin "baserom_jp.gba", 0x209a3f, 0x55
LilycoveCity_Harbor_EventScript_00209A94::
	message 0x08209CBE
	waitmessage
	goto LilycoveCity_Harbor_EventScript_00209573
	end

LilycoveCity_Harbor_EventScript_00209AA0::
	loadword 0x0, 0x08209CAA
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243629
	waitmovement 0x0
	delay 0x1E
	hideobject_at 0x800F, 0xD0A
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209AEF
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, LilycoveCity_Harbor_EventScript_00209AE4
	delay 0x1E
	hideobject_at 0xFF, 0x0
	setvar 0x8004, 0x2
	call 0x08243265
	return

LilycoveCity_Harbor_EventScript_00209AE4::
	applymovement 0xFF, 0x08209B04
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209AEF::
	applymovement 0xFF, 0x08209B07
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209AFA::
	loadword 0x0, 0x08209C81
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x209b04, 0x7
LilycoveCity_Harbor_EventScript_00209B0B::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, LilycoveCity_Harbor_EventScript_00209B20
	loadword 0x0, 0x08209CCE
	callstd 0x4
	release
	end

LilycoveCity_Harbor_EventScript_00209B20::
	loadword 0x0, 0x08209D18
	callstd 0x4
	release
	end

LilycoveCity_Harbor_EventScript_00209B2A::
	applymovement 0x4, 0x08209B40
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209B35::
	applymovement 0x4, 0x08209B45
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x209b40, 0x9
LilycoveCity_Harbor_EventScript_00209B49::
	applymovement 0x5, 0x08243627
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209B54::
	applymovement 0x5, 0x0824362D
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209B5F::
	applymovement 0x5, 0x0824362D
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209B6A::
	applymovement 0x5, 0x08243627
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209B75::
	applymovement 0x5, 0x08209BA7
	applymovement 0xFF, 0x08209BAB
	applymovement 0x4, 0x08209BB0
	waitmovement 0x0
	return

LilycoveCity_Harbor_EventScript_00209B8E::
	applymovement 0x5, 0x08209BA7
	applymovement 0xFF, 0x08209BB8
	applymovement 0x4, 0x08209BBE
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x209ba7, 0x4be
