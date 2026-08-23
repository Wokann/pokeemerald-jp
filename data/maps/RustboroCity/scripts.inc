@ RustboroCity scripts (JP map g0 m3 @ 0x081DE6F6)

RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_EventScript_001DE701
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_MapScriptTable_001DE744
	.byte 0

RustboroCity_EventScript_001DE701::
	setflag 0x879
	call 0x08242F63
	compare_var_to_value 0x405A, 0x6
	call_if 0x1, RustboroCity_EventScript_001DE740
	getplayerxy 0x4000, 0x4001
	compare_var_to_value 0x405A, 0x6
	goto_if 0x1, RustboroCity_EventScript_001DE725
	end

RustboroCity_EventScript_001DE725::
	compare_var_to_value 0x4000, 0xB
	goto_if 0x1, RustboroCity_EventScript_001DE738
	setobjectxyperm 0xF, 0xC, 0xF
	end

RustboroCity_EventScript_001DE738::
	setobjectxyperm 0xF, 0xB, 0xF
	end

RustboroCity_EventScript_001DE740::
	setflag 0x4000
	return

RustboroCity_MapScriptTable_001DE744::
	map_script_2 0x405A, 0x6, RustboroCity_EventScript_001DE74E
	.2byte 0

RustboroCity_EventScript_001DE74E::
	lockall
	setvar 0x4063, 0x1
	applymovement 0xFF, 0x081DE889
	waitmovement 0x0
	playse 0x9
	delay 0xA
	addobject 0xF
	applymovement 0xF, 0x081DE88B
	waitmovement 0x0
	playse 0x15
	applymovement 0xF, 0x0824361B
	waitmovement 0x0
	applymovement 0xF, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	applymovement 0xF, 0x081DE887
	waitmovement 0x0
	loadword 0x0, gJPText_001DFC14
	callstd 0x4
	closemessage
	setflag 0x12F
	applymovement 0xF, 0x08243627
	waitmovement 0x0
	playse 0x24
	delay 0xA
	playse 0x24
	delay 0xA
	playse 0x24
	delay 0xA
	playse 0x24
	delay 0x14
	applymovement 0xF, 0x0824362D
	waitmovement 0x0
	loadword 0x0, gJPText_001DFC6A
	callstd 0x4
	closemessage
	delay 0x14
	goto RustboroCity_EventScript_001DE7F6

RustboroCity_EventScript_001DE7E5::
	loadword 0x0, gJPText_001DFD2A
	callstd 0x4
	closemessage
	delay 0xA
	goto RustboroCity_EventScript_001DE7F6

RustboroCity_EventScript_001DE7F6::
	setflag 0x130
	special convert_pixel_width_to_tile_width
	waitstate
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, RustboroCity_EventScript_001DE7E5
	special OpenPokenavForTutorial
	waitstate
	delay 0x14
	loadword 0x0, gJPText_001DFD3B
	callstd 0x4
	closemessage
	applymovement 0xF, 0x081DE896
	waitmovement 0x0
	playse 0x9
	removeobject 0xF
	setflag 0x34C
	setvar 0x405A, 0x7
	clearflag 0x4000
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1de887, 0x11
RustboroCity_EventScript_001DE898::
	lock
	faceplayer
	checkflag 0x8E
	goto_if 0x1, RustboroCity_EventScript_001DE8AD
	loadword 0x0, 0x081DF278
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE8AD::
	loadword 0x0, 0x081DF2BF
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE8B7::
	lock
	faceplayer
	loadword 0x0, 0x081DF372
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE8C3::
	loadword 0x0, 0x081DF3AA
	callstd 0x2
	end

RustboroCity_EventScript_001DE8CC::
	lock
	faceplayer
	checkflag 0x867
	goto_if 0x1, RustboroCity_EventScript_001DE8E1
	loadword 0x0, 0x081DF2F2
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE8E1::
	loadword 0x0, 0x081DF339
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE8EB::
	lock
	faceplayer
	checkflag 0xBC
	goto_if 0x1, RustboroCity_EventScript_001DE900
	loadword 0x0, 0x081DF40A
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE900::
	loadword 0x0, 0x081DF43C
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE90A::
	loadword 0x0, 0x081DF498
	callstd 0x2
	end

RustboroCity_EventScript_001DE913::
	loadword 0x0, 0x081DF4C9
	callstd 0x3
	end

RustboroCity_EventScript_001DE91C::
	loadword 0x0, 0x081DFADC
	callstd 0x3
	end

RustboroCity_EventScript_001DE925::
	loadword 0x0, 0x081DFB27
	callstd 0x3
	end

RustboroCity_EventScript_001DE92E::
	loadword 0x0, 0x081DFB54
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1de937, 0x9
RustboroCity_EventScript_001DE940::
	loadword 0x0, 0x081DFBB4
	callstd 0x3
	end

RustboroCity_EventScript_001DE949::
	loadword 0x0, 0x081DFBDC
	callstd 0x3
	end

RustboroCity_EventScript_001DE952::
	loadword 0x0, 0x081DFC05
	callstd 0x3
	end

RustboroCity_EventScript_001DE95B::
	lock
	faceplayer
	loadword 0x0, 0x081DF511
	callstd 0x4
	applymovement 0x7, 0x08243625
	waitmovement 0x0
	release
	end

RustboroCity_EventScript_001DE971::
	lock
	faceplayer
	loadword 0x0, 0x081DF545
	callstd 0x4
	applymovement 0x8, 0x08243625
	waitmovement 0x0
	release
	end

RustboroCity_EventScript_001DE987::
	lock
	faceplayer
	loadword 0x0, 0x081DF56D
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DE993::
	lockall
	setobjectxyperm 0x9, 0xE, 0x15
	setobjectmovementtype 0x9, 0xA
	setvar 0x8004, 0x0
	goto RustboroCity_EventScript_001DEA06
	end

RustboroCity_EventScript_001DE9AA::
	lockall
	setobjectxyperm 0x9, 0xE, 0x15
	setobjectmovementtype 0x9, 0xA
	setvar 0x8004, 0x1
	goto RustboroCity_EventScript_001DEA06
	end

RustboroCity_EventScript_001DE9C1::
	lockall
	setobjectxyperm 0x9, 0xE, 0x15
	setobjectmovementtype 0x9, 0xA
	setvar 0x8004, 0x2
	goto RustboroCity_EventScript_001DEA06
	end

RustboroCity_EventScript_001DE9D8::
	lockall
	setobjectxyperm 0x9, 0xE, 0x15
	setobjectmovementtype 0x9, 0xA
	setvar 0x8004, 0x3
	goto RustboroCity_EventScript_001DEA06
	end

RustboroCity_EventScript_001DE9EF::
	lockall
	setobjectxyperm 0x9, 0xE, 0x15
	setobjectmovementtype 0x9, 0xA
	setvar 0x8004, 0x4
	goto RustboroCity_EventScript_001DEA06
	end

RustboroCity_EventScript_001DEA06::
	loadword 0x0, 0x081DF5AE
	callstd 0x4
	closemessage
	playbgm 0x1A3, 0x0
	addobject 0xA
	addobject 0x9
	applymovement 0xA, 0x081DEAD9
	waitmovement 0x0
	removeobject 0xA
	applymovement 0x9, 0x081DEAEA
	waitmovement 0x0
	loadword 0x0, 0x081DF5BB
	callstd 0x4
	closemessage
	applymovement 0x9, 0x081DEAF2
	waitmovement 0x0
	fadedefaultbgm
	removeobject 0x9
	setobjectxyperm 0x9, 0x1E, 0xA
	clearflag 0x2DC
	setflag 0x8E
	setvar 0x405A, 0x2
	setvar 0x409A, 0x2
	setvar 0x406F, 0x1
	clearflag 0x37B
	clearflag 0x370
	clearflag 0x36E
	setflag 0x2E3
	setflag 0x371
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1dea74, 0xa2
RustboroCity_EventScript_001DEB16::
	lock
	faceplayer
	checkflag 0x8F
	goto_if 0x1, RustboroCity_EventScript_001DEB2B
	loadword 0x0, 0x081DF644
	callstd 0x4
	release
	end

RustboroCity_EventScript_001DEB2B::
	waitse
	setvar 0x4001, 0x4
	goto RustboroCity_EventScript_001DEC94
	end

RustboroCity_EventScript_001DEB37::
	lockall
	setvar 0x4001, 0x0
	goto RustboroCity_EventScript_001DEB67
	end

RustboroCity_EventScript_001DEB43::
	lockall
	setvar 0x4001, 0x1
	goto RustboroCity_EventScript_001DEB67
	end

RustboroCity_EventScript_001DEB4F::
	lockall
	setvar 0x4001, 0x2
	goto RustboroCity_EventScript_001DEB67
	end

RustboroCity_EventScript_001DEB5B::
	lockall
	setvar 0x4001, 0x3
	goto RustboroCity_EventScript_001DEB67
	end

RustboroCity_EventScript_001DEB67::
	compare_var_to_value 0x4001, 0x0
	call_if 0x1, RustboroCity_EventScript_001DEBA8
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RustboroCity_EventScript_001DEBD4
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RustboroCity_EventScript_001DEC00
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RustboroCity_EventScript_001DEC2C
	setflag 0x9F
	setvar 0x405A, 0x3
	moveobjectoffscreen 0x9
	loadword 0x0, 0x081DF5D5
	callstd 0x4
	releaseall
	end

RustboroCity_EventScript_001DEBA8::
	applymovement 0x9, 0x08243629
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

RustboroCity_EventScript_001DEBD4::
	applymovement 0x9, 0x08243627
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x0824362F
	waitmovement 0x0
	return

RustboroCity_EventScript_001DEC00::
	applymovement 0x9, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

RustboroCity_EventScript_001DEC2C::
	applymovement 0x9, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0x9, 0x081DEC62
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1dec62, 0x2
RustboroCity_EventScript_001DEC64::
	lockall
	setvar 0x4001, 0x0
	goto RustboroCity_EventScript_001DEC94
	end

RustboroCity_EventScript_001DEC70::
	lockall
	setvar 0x4001, 0x1
	goto RustboroCity_EventScript_001DEC94
	end

RustboroCity_EventScript_001DEC7C::
	lockall
	setvar 0x4001, 0x2
	goto RustboroCity_EventScript_001DEC94
	end

RustboroCity_EventScript_001DEC88::
	lockall
	setvar 0x4001, 0x3
	goto RustboroCity_EventScript_001DEC94
	end

RustboroCity_EventScript_001DEC94::
	compare_var_to_value 0x4001, 0x0
	call_if 0x1, RustboroCity_EventScript_001DED15
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RustboroCity_EventScript_001DED41
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RustboroCity_EventScript_001DED6D
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RustboroCity_EventScript_001DED99
	compare_var_to_value 0x4001, 0x4
	call_if 0x1, RustboroCity_EventScript_001DEDCF
	loadword 0x0, 0x081DF671
	callstd 0x4
	setorcopyvar 0x8000, 0x3
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, RustboroCity_EventScript_001DED0C
	loadword 0x0, 0x081DF6F2
	callstd 0x4
	closemessage
	setflag 0x90
	setflag 0x2DC
	setvar 0x405A, 0x5
	delay 0x1E
	warp 0xB02, 0xFF, 0x2, 0x2
	waitstate
	releaseall
	end

RustboroCity_EventScript_001DED0C::
	loadword 0x0, 0x081DF6D8
	callstd 0x4
	return

RustboroCity_EventScript_001DED15::
	applymovement 0x9, 0x08243629
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

RustboroCity_EventScript_001DED41::
	applymovement 0x9, 0x0824362B
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x08243631
	waitmovement 0x0
	return

RustboroCity_EventScript_001DED6D::
	applymovement 0x9, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

RustboroCity_EventScript_001DED99::
	applymovement 0x9, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0x9, 0x081DEC62
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

RustboroCity_EventScript_001DEDCF::
	applymovement 0x9, 0x08243627
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	return

RustboroCity_EventScript_001DEDF1::
	lockall
	checkflag 0x120
	call_if 0x0, RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x08243621
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_PlayRivalMusic:: @ 0x081DEE0A
RustboroCity_EventScript_001DEE0A::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_EventScript_001DEE22
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DEE27
	return

RustboroCity_EventScript_001DEE22::
	playbgm 0x19F, 0x1
	return

RustboroCity_EventScript_001DEE27::
	playbgm 0x1A5, 0x1
	return

RustboroCity_EventScript_001DEE2C::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF247
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEE6C::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF24E
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEEAC::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF254
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEEEC::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF259
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEF2C::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF25D
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEF6C::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF260
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEFAC::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF264
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DEFEC::
	lockall
	call RustboroCity_EventScript_001DEE0A
	applymovement 0xE, 0x0824362D
	waitmovement 0x0
	playse 0x15
	applymovement 0xE, 0x0824361B
	waitmovement 0x0
	applymovement 0xE, 0x0824361D
	waitmovement 0x0
	applymovement 0xE, 0x081DF269
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	goto RustboroCity_EventScript_001DF02C

RustboroCity_EventScript_001DF02C::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_EventScript_001DF044
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DF14D
	end

RustboroCity_EventScript_001DF044::
	checkflag 0xD3
	goto_if 0x1, RustboroCity_EventScript_001DF0FA
	checkflag 0x120
	goto_if 0x1, RustboroCity_EventScript_001DF0A9
	setflag 0x120
	loadword 0x0, 0x081DF70B
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x081DF769
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0xFD
	setvar 0x405A, 0x8
	setvar 0x4063, 0x2
	setvar 0x8008, 0x0
	loadword 0x0, 0x081DF77D
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DF0CB
	loadword 0x0, 0x081DF80B
	callstd 0x4
	call RustboroCity_EventScript_001DF10F
	releaseall
	end

RustboroCity_EventScript_001DF0A9::
	setvar 0x8008, 0x1
	loadword 0x0, 0x081DF84F
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DF0CB
	loadword 0x0, 0x081DF80B
	callstd 0x4
	releaseall
	end

RustboroCity_EventScript_001DF0CB::
	loadword 0x0, 0x081DF870
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081DF114
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081DF127
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081DF13A
	end

RustboroCity_EventScript_001DF0FA::
	loadword 0x0, 0x081DF8A9
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, RustboroCity_EventScript_001DF10F
	releaseall
	end

RustboroCity_EventScript_001DF10F::
	savebgm 0x0
	fadedefaultbgm
	return

	.incbin "baserom_jp.gba", 0x1df114, 0x39
RustboroCity_EventScript_001DF14D::
	checkflag 0xD3
	goto_if 0x1, RustboroCity_EventScript_001DF1F9
	checkflag 0x120
	goto_if 0x1, RustboroCity_EventScript_001DF1AD
	setflag 0x120
	loadword 0x0, 0x081DF903
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x081DF95F
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0xFD
	setvar 0x405A, 0x8
	setvar 0x4063, 0x2
	loadword 0x0, 0x081DF973
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DF1CA
	loadword 0x0, 0x081DFA17
	callstd 0x4
	call RustboroCity_EventScript_001DF10F
	releaseall
	end

RustboroCity_EventScript_001DF1AD::
	loadword 0x0, 0x081DFA36
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_EventScript_001DF1CA
	loadword 0x0, 0x081DFA17
	callstd 0x4
	releaseall
	end

RustboroCity_EventScript_001DF1CA::
	loadword 0x0, 0x081DFA53
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081DF20E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081DF221
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081DF234
	end

RustboroCity_EventScript_001DF1F9::
	loadword 0x0, 0x081DFA87
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, RustboroCity_EventScript_001DF10F
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1df20e, 0x61
RustboroCity_EventScript_001DF26F::
	loadword 0x0, 0x081DFD5D
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1df278, 0x99c
	.globl gJPText_001DFC14
gJPText_001DFC14: @ 0x081DFC14
	.string "いま　ポケナビの　ついかきのうを\n"
	.string "かいはつ　していたのですが⋯⋯\p"
	.string "うまく　いきましたよ！\p"
	.string "{MUS_RG_VS_TRAINER}さん！\p"
	.string "しゃちょうに　いただいた　そのポケナビ\n"
	.string "ちょっと　かしてくださいね！$"

	.globl gJPText_001DFC6A
gJPText_001DFC6A: @ 0x081DFC6A
	.string "はい！　{MUS_RG_VS_TRAINER}さんの　ポケナビに\n"
	.string "エントリーコール　という　きのうを\l"
	.string "ついか　しました！\p"
	.string "ポケナビに　とうろく　されていれば\n"
	.string "とおく　はなれた　ところの　ひとと\l"
	.string "エントリーコールを　つうじて\l"
	.string "かいわが　できて　しまうんです！\p"
	.string "{MUS_RG_VS_TRAINER}さんの　ポケナビには\n"
	.string "うちの　ツワブキ　しゃちょうの　なまえが\l"
	.string "とうろく　してある　はずです\p"
	.string "ためしに　ちょっと　しゃちょうを\n"
	.string "よびだして　みてください！$"

	.globl gJPText_001DFD2A
gJPText_001DFD2A: @ 0x081DFD2A
	.string "ポケナビを　えらんで　ください！$"

	.globl gJPText_001DFD3B
gJPText_001DFD3B: @ 0x081DFD3B
	.string "⋯⋯では　わたしは　しごとに　もどります\p"
	.string "{MUS_RG_VS_TRAINER}さん　おきをつけて！$"

	.incbin "baserom_jp.gba", 0x1dfd5d, 0x91
