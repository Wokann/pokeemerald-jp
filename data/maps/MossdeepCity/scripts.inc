@ MossdeepCity scripts (JP map g0 m6 @ 0x081E1565)

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_EventScript_001E156B
	.byte 0

MossdeepCity_EventScript_001E156B::
	clearflag 0x64
	clearflag 0x65
	clearflag 0x66
	clearflag 0x67
	checkflag 0x88A
	call_if 0x1, 0x08243106
	end

MossdeepCity_EventScript_001E1581::
	lock
	faceplayer
	checkflag 0x7B
	goto_if 0x1, MossdeepCity_EventScript_001E1596
	loadword 0x0, 0x081E18C3
	callstd 0x4
	release
	end

MossdeepCity_EventScript_001E1596::
	loadword 0x0, 0x081E1917
	callstd 0x4
	release
	end

MossdeepCity_EventScript_001E15A0::
	lock
	faceplayer
	checkflag 0x7B
	goto_if 0x1, MossdeepCity_EventScript_001E15B5
	loadword 0x0, 0x081E193A
	callstd 0x4
	release
	end

MossdeepCity_EventScript_001E15B5::
	loadword 0x0, 0x081E19B8
	callstd 0x4
	release
	end

MossdeepCity_EventScript_001E15BF::
	loadword 0x0, 0x081E1865
	callstd 0x2
	end

MossdeepCity_EventScript_001E15C8::
	loadword 0x0, 0x081E1A2A
	callstd 0x2
	end

MossdeepCity_EventScript_001E15D1::
	loadword 0x0, 0x081E19FB
	callstd 0x2
	end

MossdeepCity_EventScript_001E15DA::
	loadword 0x0, 0x081E1AEE
	callstd 0x2
	end

MossdeepCity_EventScript_001E15E3::
	loadword 0x0, 0x081E1B7D
	callstd 0x3
	end

MossdeepCity_EventScript_001E15EC::
	loadword 0x0, 0x081E1B87
	callstd 0x3
	end

MossdeepCity_EventScript_001E15F5::
	loadword 0x0, 0x081E1BB2
	callstd 0x3
	end

MossdeepCity_EventScript_001E15FE::
	loadword 0x0, 0x081E1BD5
	callstd 0x3
	end

MossdeepCity_EventScript_001E1607::
	setflag 0x87C
	setvar 0x4001, 0x1
	end

MossdeepCity_EventScript_001E1610::
	lockall
	applymovement 0xE, 0x081E167C
	waitmovement 0x0
	applymovement 0xA, 0x081E1686
	applymovement 0xB, 0x081E1686
	applymovement 0xC, 0x081E1686
	applymovement 0xD, 0x081E1686
	waitmovement 0x0
	applymovement 0xE, 0x081E168B
	applymovement 0xA, 0x081E1699
	applymovement 0xB, 0x081E16AC
	applymovement 0xC, 0x081E16BE
	applymovement 0xD, 0x081E16CF
	waitmovement 0x0
	removeobject 0xE
	removeobject 0xA
	removeobject 0xB
	removeobject 0xC
	removeobject 0xD
	delay 0x1E
	setvar 0x405D, 0x2
	setflag 0x337
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e167c, 0x63
MossdeepCity_EventScript_001E16DF::
	lock
	faceplayer
	loadword 0x0, 0x081E1A9E
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

MossdeepCity_EventScript_001E16F5::
	lock
	faceplayer
	checkflag 0x114
	goto_if 0x1, MossdeepCity_EventScript_001E1737
	loadword 0x0, 0x081E17BC
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MossdeepCity_EventScript_001E1741
	loadword 0x0, 0x081E17FC
	callstd 0x4
	setorcopyvar 0x8000, 0xBB
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x114
	release
	end

MossdeepCity_EventScript_001E1737::
	loadword 0x0, 0x081E1831
	callstd 0x4
	release
	end

MossdeepCity_EventScript_001E1741::
	loadword 0x0, 0x081E1845
	callstd 0x4
	release
	end

MossdeepCity_EventScript_001E174B::
	loadword 0x0, 0x081E1C8D
	callstd 0x2
	end

MossdeepCity_EventScript_001E1754::
	lock
	faceplayer
	loadword 0x0, 0x081E1BF8
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, MossdeepCity_EventScript_001E177F
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, MossdeepCity_EventScript_001E1791
	addvar 0x40D1, 0x1
	removeobject 0x10
	release
	end

MossdeepCity_EventScript_001E177F::
	applymovement 0xFF, 0x081E17A3
	applymovement 0x10, 0x081E17A7
	waitmovement 0x0
	return

MossdeepCity_EventScript_001E1791::
	applymovement 0xFF, 0x081E17A3
	applymovement 0x10, 0x081E17B1
	waitmovement 0x0
	return
