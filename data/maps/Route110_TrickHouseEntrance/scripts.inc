@ Route110_TrickHouseEntrance scripts (JP map g29 m0 @ 0x0823C821)

Route110_TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_EventScript_0023C831
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_MapScriptTable_0023CABF
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_MapScriptTable_0023C9A4
	.byte 0

Route110_TrickHouseEntrance_EventScript_0023C831::
	setflag 0x8A2
	compare_var_to_value 0x40B5, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C8C4
	compare_var_to_value 0x40C1, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C8A8
	compare_var_to_value 0x40A6, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C984
	compare_var_to_value 0x40A7, 0x5
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C8D4
	compare_var_to_value 0x40A7, 0x3
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C8D4
	compare_var_to_value 0x40A7, 0x0
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C8D4
	copyvar 0x8000, 0x40A7
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C98C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C992
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C998
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C99E
	end

Route110_TrickHouseEntrance_EventScript_0023C8A8::
	setvar 0x40A5, 0x1
	compare_var_to_value 0x4044, 0x8
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C8BE
	setvar 0x40A7, 0x2
	end

Route110_TrickHouseEntrance_EventScript_0023C8BE::
	setvar 0x40A7, 0x6
	end

Route110_TrickHouseEntrance_EventScript_0023C8C4::
	setvar 0x40B5, 0x0
	setvar 0x40A7, 0x5
	setvar 0x40A5, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023C8D4::
	setvar 0x40A7, 0x0
	compare_var_to_value 0x4044, 0x1
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C932
	compare_var_to_value 0x4044, 0x2
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C93C
	compare_var_to_value 0x4044, 0x3
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C946
	compare_var_to_value 0x4044, 0x4
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C950
	compare_var_to_value 0x4044, 0x5
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C95A
	compare_var_to_value 0x4044, 0x6
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C964
	compare_var_to_value 0x4044, 0x7
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C96E
	compare_var_to_value 0x4044, 0x8
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023C978
	return

Route110_TrickHouseEntrance_EventScript_0023C932::
	checkflag 0x869
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C93C::
	checkflag 0x86A
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C946::
	checkflag 0x86B
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C950::
	checkflag 0x86C
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C95A::
	checkflag 0x86D
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C964::
	checkflag 0x86E
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C96E::
	checkflag 0x864
	call_if 0x0, Route110_TrickHouseEntrance_EventScript_0023C97E
	return

Route110_TrickHouseEntrance_EventScript_0023C978::
	setvar 0x40A7, 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023C97E::
	setvar 0x40A7, 0x3
	return

Route110_TrickHouseEntrance_EventScript_0023C984::
	setobjectxyperm 0x1, 0x5, 0x2
	end

Route110_TrickHouseEntrance_EventScript_0023C98C::
	setvar 0x40A5, 0x0
	end

Route110_TrickHouseEntrance_EventScript_0023C992::
	setvar 0x40A5, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023C998::
	setvar 0x40A5, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023C99E::
	setvar 0x40A5, 0x1
	end

Route110_TrickHouseEntrance_MapScriptTable_0023C9A4::
	map_script_2 0x40A6, 0x1, Route110_TrickHouseEntrance_EventScript_0023C9E6
	map_script_2 0x40A7, 0x0, Route110_TrickHouseEntrance_EventScript_0023C9F7
	map_script_2 0x40A7, 0x1, Route110_TrickHouseEntrance_EventScript_0023CA9D
	map_script_2 0x40A7, 0x2, Route110_TrickHouseEntrance_EventScript_0023CAA1
	map_script_2 0x40A7, 0x3, Route110_TrickHouseEntrance_EventScript_0023CAA1
	map_script_2 0x40A7, 0x4, Route110_TrickHouseEntrance_EventScript_0023CA9D
	map_script_2 0x40A7, 0x5, Route110_TrickHouseEntrance_EventScript_0023CA9D
	map_script_2 0x40A7, 0x6, Route110_TrickHouseEntrance_EventScript_0023CAB0
	.2byte 0

Route110_TrickHouseEntrance_EventScript_0023C9E6::
	addobject 0x1
	showobject_at 0x1, 0x1D00
	turnobject 0x1, 0x4
	turnobject 0xFF, 0x3
	end

Route110_TrickHouseEntrance_EventScript_0023C9F7::
	addobject 0x1
	hideobject_at 0x1, 0x1D00
	copyvar 0x8000, 0x4044
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA5D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA65
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA6D
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA75
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA7D
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA85
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA8D
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CA95
	end

Route110_TrickHouseEntrance_EventScript_0023CA5D::
	setobjectxy 0x1, 0x6, 0x3
	end

Route110_TrickHouseEntrance_EventScript_0023CA65::
	setobjectxy 0x1, 0xB, 0x5
	end

Route110_TrickHouseEntrance_EventScript_0023CA6D::
	setobjectxy 0x1, 0x9, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023CA75::
	setobjectxy 0x1, 0x3, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023CA7D::
	setobjectxy 0x1, 0x0, 0x5
	end

Route110_TrickHouseEntrance_EventScript_0023CA85::
	setobjectxy 0x1, 0xB, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023CA8D::
	setobjectxy 0x1, 0x8, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023CA95::
	setobjectxy 0x1, 0x4, 0x4
	end

Route110_TrickHouseEntrance_EventScript_0023CA9D::
	removeobject 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023CAA1::
	addobject 0x1
	setobjectxy 0x1, 0x5, 0x2
	turnobject 0x1, 0x2
	end

Route110_TrickHouseEntrance_EventScript_0023CAB0::
	addobject 0x1
	setobjectxy 0x1, 0x5, 0x2
	turnobject 0x1, 0x1
	end

Route110_TrickHouseEntrance_MapScriptTable_0023CABF::
	map_script_2 0x40A6, 0x1, Route110_TrickHouseEntrance_EventScript_0023CAC9
	.2byte 0

Route110_TrickHouseEntrance_EventScript_0023CAC9::
	lockall
	delay 0x14
	compare_var_to_value 0x4044, 0x0
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CC19
	loadword 0x0, gJPText_0023D407
	callstd 0x4
	closemessage
	delay 0x14
	applymovement 0x1, 0x0823CC07
	waitmovement 0x0
	playse 0xB2
	applymovement 0x1, 0x0823CC10
	waitmovement 0x0
	removeobject 0x1
	setvar 0x40A7, 0x1
	setvar 0x40A6, 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x23cb0a, 0x2
Route110_TrickHouseEntrance_EventScript_0023CB0C::
	lockall
	copyvar 0x8000, 0x40A7
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CB3F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CC60
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CC22
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CE0A
	end

Route110_TrickHouseEntrance_EventScript_0023CB3F::
	playse 0x15
	applymovement 0xFF, 0x0824361B
	waitmovement 0x0
	applymovement 0xFF, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x4044, 0x0
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBBF
	compare_var_to_value 0x4044, 0x1
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBC8
	compare_var_to_value 0x4044, 0x2
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBD1
	compare_var_to_value 0x4044, 0x3
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBDA
	compare_var_to_value 0x4044, 0x4
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBE3
	compare_var_to_value 0x4044, 0x5
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBEC
	compare_var_to_value 0x4044, 0x6
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBF5
	compare_var_to_value 0x4044, 0x7
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CBFE
	closemessage
	setvar 0x40A6, 0x1
	warpsilent 0x1D00, 0xFF, 0x6, 0x2
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CBBF::
	loadword 0x0, 0x0823D255
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBC8::
	loadword 0x0, 0x0823D283
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBD1::
	loadword 0x0, 0x0823D2B0
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBDA::
	loadword 0x0, 0x0823D2DE
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBE3::
	loadword 0x0, 0x0823D30C
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBEC::
	loadword 0x0, 0x0823D33C
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBF5::
	loadword 0x0, 0x0823D36A
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CBFE::
	loadword 0x0, 0x0823D397
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x23cc07, 0x12
Route110_TrickHouseEntrance_EventScript_0023CC19::
	loadword 0x0, gJPText_0023D3C6
	callstd 0x4
	return

Route110_TrickHouseEntrance_EventScript_0023CC22::
	loadword 0x0, 0x0823D4DC
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	loadword 0x0, 0x0823D50F
	callstd 0x4
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CC60::
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x0823D574
	callstd 0x4
	compare_var_to_value 0x4044, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CCC0
	compare_var_to_value 0x4044, 0x2
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CCEC
	compare_var_to_value 0x4044, 0x3
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CD18
	compare_var_to_value 0x4044, 0x4
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CD44
	compare_var_to_value 0x4044, 0x5
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CD70
	compare_var_to_value 0x4044, 0x6
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CD9C
	compare_var_to_value 0x4044, 0x7
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDC8
	end

Route110_TrickHouseEntrance_EventScript_0023CCC0::
	setorcopyvar 0x8000, 0x44
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CCEC::
	setorcopyvar 0x8000, 0xA
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CD18::
	setorcopyvar 0x8000, 0xCC
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CD44::
	setorcopyvar 0x8000, 0xC2
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CD70::
	setorcopyvar 0x8000, 0x12C
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CD9C::
	setorcopyvar 0x8000, 0xD0
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CDC8::
	setorcopyvar 0x8000, 0x47
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CDF4
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430EA
	loadword 0x0, 0x0823D5AA
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CDF4::
	setvar 0x40C1, 0x0
	setvar 0x40A7, 0x3
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CE0A::
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x0823D5BE
	callstd 0x4
	call Route110_TrickHouseEntrance_EventScript_0023CE41
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CE6B
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x082430FD
	loadword 0x0, 0x0823D62A
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CE41::
	multichoice 0x0, 0x0, 0x58, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CE5B
	goto Route110_TrickHouseEntrance_EventScript_0023CE63

Route110_TrickHouseEntrance_EventScript_0023CE5B::
	setorcopyvar 0x8000, 0x1F
	callstd 0x7
	return

Route110_TrickHouseEntrance_EventScript_0023CE63::
	setorcopyvar 0x8000, 0x20
	callstd 0x7
	return

Route110_TrickHouseEntrance_EventScript_0023CE6B::
	loadword 0x0, 0x0823D620
	callstd 0x4
	closemessage
	applymovement 0x1, 0x0823F823
	waitmovement 0x0
	applymovement 0x1, 0x0823CC07
	waitmovement 0x0
	playse 0xB2
	applymovement 0x1, 0x0823CC10
	waitmovement 0x0
	removeobject 0x1
	setvar 0x40C1, 0x0
	setvar 0x40A7, 0x5
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CEA4::
	lockall
	copyvar 0x8000, 0x40A7
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CED7
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CEE1
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFD2
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFDC
	end

Route110_TrickHouseEntrance_EventScript_0023CED7::
	loadword 0x0, 0x0823D478
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CEE1::
	loadword 0x0, 0x0823D47F
	callstd 0x5
	closemessage
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CEF7
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CEF7::
	setmetatile 0x5, 0x1, 0x219, 0x0
	special DrawWholeMapView
	delay 0x14
	applymovement 0xFF, 0x0824364C
	waitmovement 0x0
	applymovement 0xFF, 0x0823CF78
	waitmovement 0x0
	copyvar 0x8000, 0x4044
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CF7A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CF85
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CF90
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CF9B
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFA6
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFB1
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFBC
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFC7
	end

	.incbin "baserom_jp.gba", 0x23cf78, 0x2
Route110_TrickHouseEntrance_EventScript_0023CF7A::
	warp 0x1D03, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CF85::
	warp 0x1D04, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CF90::
	warp 0x1D05, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CF9B::
	warp 0x1D06, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFA6::
	warp 0x1D07, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFB1::
	warp 0x1D08, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFBC::
	warp 0x1D09, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFC7::
	warp 0x1D0A, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFD2::
	loadword 0x0, 0x0823D4AB
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFDC::
	compare_var_to_value 0x4044, 0x8
	goto_if 0x1, Route110_TrickHouseEntrance_EventScript_0023CFF1
	loadword 0x0, 0x0823D478
	callstd 0x4
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_0023CFF1::
	loadword 0x0, 0x0823D4AB
	callstd 0x4
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_Door:: @ 0x0823CFFB
	.incbin "baserom_jp.gba", 0x23cffb, 0x1ce
Route110_TrickHouseEntrance_EventScript_0023D1C9::
	lockall
	loadword 0x0, 0x0823D245
	callstd 0x4
	releaseall
	compare_var_to_value 0x4044, 0x0
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023D1FA
	compare_var_to_value 0x4044, 0x1
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023D20A
	compare_var_to_value 0x4044, 0x2
	call_if 0x1, Route110_TrickHouseEntrance_EventScript_0023D21A
	setvar 0x40A5, 0x1
	end

Route110_TrickHouseEntrance_EventScript_0023D1FA::
	setvar 0x8004, 0x6
	setvar 0x8005, 0x3
	call Route110_TrickHouseEntrance_EventScript_0023D22A
	return

Route110_TrickHouseEntrance_EventScript_0023D20A::
	setvar 0x8004, 0xB
	setvar 0x8005, 0x5
	call Route110_TrickHouseEntrance_EventScript_0023D22A
	return

Route110_TrickHouseEntrance_EventScript_0023D21A::
	setvar 0x8004, 0x9
	setvar 0x8005, 0x2
	call Route110_TrickHouseEntrance_EventScript_0023D22A
	return

Route110_TrickHouseEntrance_EventScript_0023D22A::
	setvar 0x8006, 0x0
	setfieldeffectarg 0x0, 0x8004
	setfieldeffectarg 0x1, 0x8005
	setfieldeffectarg 0x2, 0x8006
	dofieldeffect 0x36
	waitfieldeffect 0x36
	delay 0xA
	return

	.incbin "baserom_jp.gba", 0x23d245, 0x181
	.globl gJPText_0023D3C6
gJPText_0023D3C6: @ 0x0823D3C6
	.string "わがはい　こそ！\p"
	.string "ホウエンちほう　さいだいの\n"
	.string "なぞの　じんぶつ\l"
	.string "ひと　よんで⋯⋯\p"
	.string "カラクリだいおう！\n"
	.string "わははは！　はじめまして！$"

	.globl gJPText_0023D407
gJPText_0023D407: @ 0x0823D407
	.string "あんた　わがはいの　カラクリやしきに\n"
	.string "ちょうせんしに　きたって\l"
	.string "わけだろう　そうだろう！\l"
	.string "よしっ　ちょうせんを　みとめよう！\p"
	.string "そこの　かけじくから　はいって\n"
	.string "ちょうせん　するがいい！\l"
	.string "わがはいは　おくの　へやで　まってるぞ！$"

	.incbin "baserom_jp.gba", 0x23d478, 0x248
