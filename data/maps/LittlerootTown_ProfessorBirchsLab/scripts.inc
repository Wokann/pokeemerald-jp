@ LittlerootTown_ProfessorBirchsLab scripts (JP map g1 m4 @ 0x081F122C)

LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_EventScript_001F123C
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_MapScriptTable_001F12A1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_MapScriptTable_001F1354
	.byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_001F123C::
	call 0x08242F63
	call 0x08243139
	compare_var_to_value 0x40D3, 0x6
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F1292
	compare_var_to_value 0x40D3, 0x4
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F128E
	compare_var_to_value 0x40D3, 0x3
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1268
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1268::
	specialvar 0x800D, HasAllHoennMons
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1284
	setobjectmovementtype 0x3, 0x3
	setobjectxyperm 0x3, 0x5, 0xA
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1284::
	setvar 0x40D3, 0x4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F128E

LittlerootTown_ProfessorBirchsLab_EventScript_001F128E::
	setmaplayoutindex 0x1B0
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1292::
	setmaplayoutindex 0x1B0
	setobjectmovementtype 0x3, 0x3
	setobjectxyperm 0x3, 0x5, 0xA
	end

LittlerootTown_ProfessorBirchsLab_MapScriptTable_001F12A1::
	map_script_2 0x4084, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_001F12DB
	map_script_2 0x40D3, 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F12E0
	map_script_2 0x40D3, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_001F12E0
	map_script_2 0x40D3, 0x3, LittlerootTown_ProfessorBirchsLab_EventScript_001F130C
	map_script_2 0x40D3, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_001F130C
	map_script_2 0x40D3, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F1310
	map_script_2 0x40D3, 0x5, LittlerootTown_ProfessorBirchsLab_EventScript_001F1310
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_001F12DB::
	turnobject 0xFF, 0x2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F12E0::
	turnobject 0xFF, 0x2
	addobject 0x2
	addobject 0x3
	turnobject 0x3, 0x2
	setobjectxy 0x3, 0x5, 0x5
	turnobject 0x2, 0x1
	setobjectxy 0x2, 0x6, 0x4
	turnobject 0x1, 0x4
	setobjectxy 0x1, 0xA, 0xA
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F130C::
	addobject 0x3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1310::
	addobject 0x4
	addobject 0x5
	addobject 0x6
	addobject 0x3
	turnobject 0x4, 0x1
	setobjectxy 0x4, 0x8, 0x4
	turnobject 0x5, 0x1
	setobjectxy 0x5, 0x9, 0x4
	turnobject 0x6, 0x1
	setobjectxy 0x6, 0xA, 0x4
	turnobject 0x2, 0x1
	setobjectxy 0x2, 0x6, 0x4
	turnobject 0x3, 0x4
	setobjectxy 0x3, 0x5, 0x5
	end

LittlerootTown_ProfessorBirchsLab_MapScriptTable_001F1354::
	map_script_2 0x4084, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_001F1376
	map_script_2 0x4084, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F1402
	map_script_2 0x40D3, 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F141B
	map_script_2 0x40D3, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F14FD
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_001F1376::
	lockall
	bufferleadmonspeciesname 0x0
	message gJPText_001F1BAD
	waitmessage
	playfanfare 0x172
	waitfanfare
	loadword 0x0, gJPText_001F1C81
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F13A2
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F13B2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F13A2::
	setvar 0x8004, 0x0
	call 0x08243460
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F13B2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F13B2::
	loadword 0x0, gJPText_001F1CA8
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F13D1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F13E3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F13D1::
	loadword 0x0, gJPText_001F1D1C
	callstd 0x4
	clearflag 0x3DF
	setvar 0x4084, 0x3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F13E3::
	loadword 0x0, gJPText_001F1D52
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F13D1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F13E3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1402::
	lockall
	applymovement 0xFF, 0x081F1413
	waitmovement 0x0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1893
	end

	.incbin "baserom_jp.gba", 0x1f1413, 0x8
LittlerootTown_ProfessorBirchsLab_EventScript_001F141B::
	lockall
	delay 0x1E
	loadword 0x0, gJPText_001F217C
	callstd 0x4
	closemessage
	applymovement 0x2, 0x081F14E1
	waitmovement 0x0
	delay 0x14
	playse 0x24
	delay 0xA
	playse 0x24
	delay 0xA
	playse 0x24
	delay 0xA
	playse 0x24
	delay 0x14
	applymovement 0x3, 0x0824362B
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F14CD
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F14D7
	playse 0x4
	waitse
	delay 0x14
	applymovement 0x2, 0x081F14F3
	waitmovement 0x0
	applymovement 0x3, 0x08243629
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_001F22FE
	callstd 0x4
	playfanfare 0x172
	message gJPText_001F230C
	waitmessage
	waitfanfare
	setflag 0x896
	special EnableNationalPokedex
	loadword 0x0, gJPText_001F232E
	callstd 0x4
	closemessage
	setflag 0x31B
	setflag 0x31A
	setvar 0x40D3, 0x2
	setvar 0x40F5, 0x0
	setflag 0x72
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F14CD::
	loadword 0x0, gJPText_001F226E
	callstd 0x4
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F14D7::
	loadword 0x0, gJPText_001F22B6
	callstd 0x4
	closemessage
	return

	.incbin "baserom_jp.gba", 0x1f14e1, 0x1c
LittlerootTown_ProfessorBirchsLab_EventScript_001F14FD::
	lockall
	applymovement 0xFF, 0x081F1517
	waitmovement 0x0
	loadword 0x0, gJPText_001F2402
	callstd 0x4
	setvar 0x40D3, 0x5
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f1517, 0x8
LittlerootTown_ProfessorBirchsLab_EventScript_001F151F::
	lock
	faceplayer
	compare_var_to_value 0x4084, 0x3
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F154C
	checkflag 0x58
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1542
	loadword 0x0, 0x081F1A7D
	callstd 0x4
	setflag 0x58
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1542::
	loadword 0x0, 0x081F1B1D
	callstd 0x4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F154C::
	loadword 0x0, 0x081F1B5B
	callstd 0x4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1556::
	release
	compare_var_to_value 0x40D3, 0x6
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F15F2
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	showmonpic 0x9B, 0xA, 0x3
	loadword 0x0, 0x081F2532
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F15FC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1607
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F158A::
	release
	compare_var_to_value 0x40D3, 0x6
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F15F2
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	showmonpic 0x9E, 0xA, 0x3
	loadword 0x0, 0x081F256E
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F15FC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F16A8
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F15BE::
	release
	compare_var_to_value 0x40D3, 0x6
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F15F2
	applymovement 0x2, 0x0824362B
	waitmovement 0x0
	showmonpic 0x98, 0xA, 0x3
	loadword 0x0, 0x081F25A6
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F15FC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1749
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F15F2::
	loadword 0x0, 0x081F26B5
	callstd 0x4
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F15FC::
	hidemonpic
	loadword 0x0, 0x081F25DC
	callstd 0x4
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1607::
	buffermovename 0x0, 0x9B
	setvar 0x4001, 0x9B
	givemon 0x9B, 0x5, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F163C
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1667
	hidemonpic
	goto 0x0824423B
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F163C::
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA
	removeobject 0x4
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1698
	call 0x082441B5
	call 0x08243460
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1698
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1667::
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA
	removeobject 0x4
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F168D
	call 0x082441C1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F168D
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F168D::
	call 0x082441CA
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1698
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1698::
	hidemonpic
	loadword 0x0, 0x081F2655
	callstd 0x4
	setvar 0x40D3, 0x6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F16A8::
	buffermovename 0x0, 0x9E
	setvar 0x4001, 0x9E
	givemon 0x9E, 0x5, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F16DD
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1708
	hidemonpic
	goto 0x0824423B
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F16DD::
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA
	removeobject 0x5
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1739
	call 0x082441B5
	call 0x08243460
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1739
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1708::
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA
	removeobject 0x5
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F172E
	call 0x082441C1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F172E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F172E::
	call 0x082441CA
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1739
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1739::
	hidemonpic
	loadword 0x0, 0x081F2655
	callstd 0x4
	setvar 0x40D3, 0x6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1749::
	buffermovename 0x0, 0x98
	setvar 0x4001, 0x98
	givemon 0x98, 0x5, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F177E
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F17A9
	hidemonpic
	goto 0x0824423B
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F177E::
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA
	removeobject 0x6
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F17DA
	call 0x082441B5
	call 0x08243460
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F17DA
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F17A9::
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA
	removeobject 0x6
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F17CF
	call 0x082441C1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F17CF
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F17CF::
	call 0x082441CA
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F17DA
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F17DA::
	hidemonpic
	loadword 0x0, 0x081F2655
	callstd 0x4
	setvar 0x40D3, 0x6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F17EA::
	playfanfare 0x172
	message 0x081F2624
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F17F5::
	lock
	faceplayer
	compare_var_to_value 0x40D3, 0x5
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1825
	compare_var_to_value 0x40D3, 0x2
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F182F
	checkflag 0x12F
	goto_if 0x0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1839
	checkflag 0x119
	goto_if 0x0, LittlerootTown_ProfessorBirchsLab_EventScript_001F186D
	goto LittlerootTown_ProfessorBirchsLab_EventScript_001F1839
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1825::
	loadword 0x0, 0x081F24F0
	callstd 0x4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F182F::
	loadword 0x0, gJPText_001F232E
	callstd 0x4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1839::
	checkflag 0x380
	goto_if 0x0, 0x082431CD
	compare_var_to_value 0x40D3, 0x3
	goto_if 0x1, 0x082431CD
	compare_var_to_value 0x40D3, 0x6
	goto_if 0x4, 0x082431CD
	compare_var_to_value 0x4084, 0x5
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F195F
	loadword 0x0, 0x081F1D72
	callstd 0x4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F186D::
	loadword 0x0, 0x0826C1AF
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x0826C23E
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0x119
	setvar 0x40DA, 0x2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1893::
	loadword 0x0, gJPText_001F1DDC
	callstd 0x4
	call LittlerootTown_ProfessorBirchsLab_EventScript_001F1947
	loadword 0x0, gJPText_001F1E7F
	callstd 0x4
	closemessage
	applymovement 0x3, 0x081F197B
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F18ED
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F191A
	setvar 0x4084, 0x5
	setflag 0x74
	setvar 0x4051, 0x1
	setvar 0x408D, 0x4
	setvar 0x4050, 0x3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F18ED::
	loadword 0x0, gJPText_001F1F72
	callstd 0x4
	setorcopyvar 0x8000, 0x4
	setorcopyvar 0x8001, 0x5
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1969
	loadword 0x0, gJPText_001F1FB3
	callstd 0x4
	setvar 0x800D, 0x0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F191A::
	loadword 0x0, gJPText_001F2048
	callstd 0x4
	setorcopyvar 0x8000, 0x4
	setorcopyvar 0x8001, 0x5
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1972
	loadword 0x0, gJPText_001F2072
	callstd 0x4
	setvar 0x800D, 0x1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1947::
	playfanfare 0x172
	message gJPText_001F1E6C
	waitfanfare
	setflag 0x861
	special SetUnlockedPokedexFlags
	setflag 0x8E4
	setvar 0x40CD, 0x1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F195F::
	loadword 0x0, 0x081F1F31
	callstd 0x4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1969::
	loadword 0x0, gJPText_001F2019
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1972::
	loadword 0x0, gJPText_001F20D5
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x1f197b, 0x3
LittlerootTown_ProfessorBirchsLab_EventScript_001F197E::
	loadword 0x0, 0x081F2103
	callstd 0x3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1987::
	lock
	faceplayer
	compare_var_to_value 0x40D3, 0x5
	goto_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F19D5
	compare_var_to_value 0x40D3, 0x6
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A00
	compare_var_to_value 0x40D3, 0x2
	goto_if 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A2B
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F19C3
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F19CC
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F19C3::
	loadword 0x0, 0x081F2028
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F19CC::
	loadword 0x0, 0x081F20E4
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F19D5::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F19EE
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F19F7
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F19EE::
	loadword 0x0, 0x081F26F8
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F19F7::
	loadword 0x0, 0x081F275E
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A00::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A19
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A22
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A19::
	loadword 0x0, 0x081F2796
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A22::
	loadword 0x0, 0x081F27C2
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A2B::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A44
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A4D
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A44::
	loadword 0x0, 0x081F2388
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A4D::
	loadword 0x0, 0x081F23C6
	callstd 0x4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56::
	loadword 0x0, 0x081F2127
	callstd 0x3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A5F::
	loadword 0x0, 0x081F214D
	callstd 0x3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_001F1A68::
	loadword 0x0, 0x081F2169
	callstd 0x3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall:: @ 0x081F1A71
	.incbin "baserom_jp.gba", 0x1f1a71, 0x13c
	.globl gJPText_001F1BAD
gJPText_001F1BAD: @ 0x081F1BAD
	.string "オダマキ“⋯⋯さて　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\p"
	.string "きみのことは　おとうさん　から\n"
	.string "いつも　きかされていたよ！\p"
	.string "きみは　まだ　じぶんの　ポケモンを\n"
	.string "もったことが　ないんだって？\p"
	.string "それにしては　さっきの　たたかいぶり\n"
	.string "なかなか　みごと　だったよ！\p"
	.string "やっぱり　きみには　おとうさんの\n"
	.string "ちが　ながれて　いるんだな！\p"
	.string "そうそう！　たすけてくれた　おれいに\n"
	.string "さっきの　ポケモンは　わたしから\l"
	.string "きみへの　プレゼントに　しよう！\p"
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "{B_COPY_VAR_1}を　もらった！$"

	.globl gJPText_001F1C81
gJPText_001F1C81: @ 0x081F1C81
	.string "オダマキ“せっかく　だから　{B_COPY_VAR_1}に\n"
	.string "ニックネームを　つけてみては　どうだい？$"

	.globl gJPText_001F1CA8
gJPText_001F1CA8: @ 0x081F1CA8
	.string "オダマキ“これから　さらに\n"
	.string "けいけんを　つんで　いけば\l"
	.string "いい　トレーナーに　なれそうだ！\p"
	.string "ちょうど　うちの　{B_OPPONENT_MON1_NAME}も\n"
	.string "わたしを　てつだい　ながら\l"
	.string "ポケモンの　ちょうさを　しているんだ\p"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　いちど\n"
	.string "あいに　いったら　どうだろう？$"

	.globl gJPText_001F1D1C
gJPText_001F1D1C: @ 0x081F1D1C
	.string "オダマキ“そうか！\n"
	.string "それは　{B_OPPONENT_MON1_NAME}も　よろこぶぞ！\p"
	.string "トレーナーが　どんな　ものか\n"
	.string "おしえてもらうと　いいぞ！$"

	.globl gJPText_001F1D52
gJPText_001F1D52: @ 0x081F1D52
	.string "オダマキ“そんなこと　いわずに\n"
	.string "あいに　いったら　どうだろう？$"

	.incbin "baserom_jp.gba", 0x1f1d72, 0x6a
	.globl gJPText_001F1DDC
gJPText_001F1DDC: @ 0x081F1DDC
	.string "オダマキ“おっ　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\p"
	.string "はじめてで　{B_OPPONENT_MON1_NAME}に\n"
	.string "かつ　だなんて　すごいじゃないか！\p"
	.string "{B_OPPONENT_MON1_NAME}は　かなり　まえから\n"
	.string "わたしの　けんきゅうを　てつだっていて\l"
	.string "トレーナーれきは　けっこう　ながいんだよ！\p"
	.string "うむ！　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　にも\n"
	.string "けんきゅうの　ために　とりよせた\l"
	.string "この　ポケモンずかんを　あげよう！$"

	.globl gJPText_001F1E6C
gJPText_001F1E6C: @ 0x081F1E6C
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "ポケモンずかんを　もらった！$"

	.globl gJPText_001F1E7F
gJPText_001F1E7F: @ 0x081F1E7F
	.string "オダマキ“その　ポケモンずかんは\n"
	.string "きみが　であった　ポケモンを\p"
	.string "じどうてきに　きろく　していってくれる\n"
	.string "ハイテクな　どうぐ　なんだ！\p"
	.string "{B_OPPONENT_MON1_NAME}も　その　ずかんを　もっていて\n"
	.string "あちこちに　あそびに　いくんだな\p"
	.string "で　めずらしい　ポケモンを　つかまえて\n"
	.string "ずかんに　きろく　できるとだね\p"
	.string "フィールドワークを　している　わたしを\n"
	.string "さがしだしては　みせて　くれるんだよ！$"

	.incbin "baserom_jp.gba", 0x1f1f31, 0x41
	.globl gJPText_001F1F72
gJPText_001F1F72: @ 0x081F1F72
	.string "ハルカ“{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}も\n"
	.string "ポケモンずかん　もらったんだね！\p"
	.string "よかったね！　あたしと　いっしょだよ！\n"
	.string "じゃあ　あたしは　これを　あげる！$"

	.globl gJPText_001F1FB3
gJPText_001F1FB3: @ 0x081F1FB3
	.string "ハルカ“ポケモンが\n"
	.string "たくさん　いると　たのしいよ！\p"
	.string "あたし　いろんな　ポケモン　さがしたいから\n"
	.string "いろんな　ところを　さがすわ！\p"
	.string "そして　かわいい　ポケモンが　いたら\n"
	.string "モンスターボールで　つかまえちゃう！$"

	.globl gJPText_001F2019
gJPText_001F2019: @ 0x081F2019
	.string "あら？　バッグ　いっぱいだよ$"

	.incbin "baserom_jp.gba", 0x1f2028, 0x20
	.globl gJPText_001F2048
gJPText_001F2048: @ 0x081F2048
	.string "ユウキ“ふうん　{MUS_RG_VS_TRAINER}も\n"
	.string "ポケモンずかん　もらったのか\p"
	.string "じゃあ　オレは　これ　やるよ$"

	.globl gJPText_001F2072
gJPText_001F2072: @ 0x081F2072
	.string "ユウキ“ポケモンが\n"
	.string "たくさん　いると　たのしいからな\p"
	.string "オレ　いろんな　ポケモン　さがすため\n"
	.string "いろんな　ところに　いくんだ\p"
	.string "そして　かっこいい　ポケモンが　いたら\n"
	.string "モンスターボールで　つかまえるんだ$"

	.globl gJPText_001F20D5
gJPText_001F20D5: @ 0x081F20D5
	.string "おや？　バッグ　いっぱいだよ$"

	.incbin "baserom_jp.gba", 0x1f20e4, 0x98
	.globl gJPText_001F217C
gJPText_001F217C: @ 0x081F217C
	.string "オダマキ“⋯⋯さて\p"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}と　{B_OPPONENT_MON1_NAME}に　ポケモンの\n"
	.string "ちょうさを　おねがい　していた　わけだが\p"
	.string "きみたちの　どりょくの　おかげで\n"
	.string "いろんな　ことが　わかってきた！\p"
	.string "どうやら　ホウエンちほう　には\n"
	.string "それいがいの　ちほうの　ポケモンも\l"
	.string "せいそく　している　らしいんだ！\p"
	.string "それだけ　ホウエンちほうは\n"
	.string "ゆたかな　しぜんに　めぐまれている\l"
	.string "という　ことなんだろうな！\p"
	.string "というわけで　きみたちの　ずかんを\n"
	.string "ぜんこくばんに　バージョンアップ\l"
	.string "してあげようと　おもう！\p"
	.string "さあ　ずかんを　かしておくれ！$"

	.globl gJPText_001F226E
gJPText_001F226E: @ 0x081F226E
	.string "ハルカ“えへへー！\p"
	.string "あたしの　ずかんまで\n"
	.string "ぜんこくばんに　してもらえる　なんて\p"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}が　たくさん　ポケモンを\n"
	.string "しらべてくれた　おかげだね！$"

	.globl gJPText_001F22B6
gJPText_001F22B6: @ 0x081F22B6
	.string "ユウキ“オレ　はりきって　ホウエンじゅうの\n"
	.string "ポケモンのこと　しらべたからな\p"
	.string "{MUS_RG_VS_TRAINER}も　ずかんを　ぜんこくばんに\n"
	.string "してもらえて　ラッキーだったな！$"

	.globl gJPText_001F22FE
gJPText_001F22FE: @ 0x081F22FE
	.string "オダマキ“ホイ　できたぞ！$"

	.globl gJPText_001F230C
gJPText_001F230C: @ 0x081F230C
	.string "{MUS_RG_VS_TRAINER}の　ポケモンずかんが\n"
	.string "ぜんこくばんに　バージョンアップ　した！$"

	.globl gJPText_001F232E
gJPText_001F232E: @ 0x081F232E
	.string "オダマキ“いいかい？\n"
	.string "チャンピオンに　なったから　といって\l"
	.string "ポケモンの　みちに　おわりは　ないんだ\p"
	.string "まだ　あしを　ふみいれていない　くさむらは\n"
	.string "いつまでも　きみを　まっているよ！$"

	.incbin "baserom_jp.gba", 0x1f2388, 0x7a
	.globl gJPText_001F2402
gJPText_001F2402: @ 0x081F2402
	.string "オダマキ“おお　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\n"
	.string "ちょっと　ずかんを　みせて　もらうよ\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "⋯⋯うむ　やはり　まちがいない！\n"
	.string "キミは　ほんとうに　ホウエンちほうの\l"
	.string "ずかんを　かんせい　させたんだな！\p"
	.string "いやー　たいしたもんだ！\p"
	.string "きみの　その　すばらしい　はたらきに\n"
	.string "かんしゃの　きもちを　こめて\l"
	.string "わたしから　プレゼントを　おくろう！\p"
	.string "それは⋯⋯\p"
	.string "ほかの　ちほうでしか　みつからない\n"
	.string "めずらしい　ポケモンだよ！\p"
	.string "3ひきの　なかから\n"
	.string "すきなものを　1ひきだけ　あげよう！$"

	.incbin "baserom_jp.gba", 0x1f24f0, 0x4b2
