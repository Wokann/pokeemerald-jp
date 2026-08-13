@ Route104 scripts (JP map g0 m19 @ 0x081E712E)

Route104_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_MapScriptTable_001E7139
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_EventScript_001E714A
	.byte 0

Route104_MapScriptTable_001E7139::
	map_script_2 0x408E, 0x1, Route104_EventScript_001E7143
	.2byte 0

Route104_EventScript_001E7143::
	lockall
	goto Route104_EventScript_001E7595
	end

Route104_EventScript_001E714A::
	call 0x08242F63
	call Route104_EventScript_001E7174
	call Route104_EventScript_001E715A
	end

Route104_EventScript_001E715A::
	checkflag 0x7F
	goto_if 0x0, Route104_EventScript_001E7170
	checkflag 0x869
	goto_if 0x0, Route104_EventScript_001E7170
	clearflag 0x38A
	return

Route104_EventScript_001E7170::
	setflag 0x38A
	return

Route104_EventScript_001E7174::
	compare_var_to_value 0x408E, 0x1
	goto_if 0x4, Route104_EventScript_001E7199
	checkflag 0x120
	goto_if 0x1, Route104_EventScript_001E7199
	checkflag 0x7C
	goto_if 0x0, Route104_EventScript_001E7199
	setobjectxyperm 0x22, 0x11, 0x34
	return

Route104_EventScript_001E7199::
	return

Route104_EventScript_001E719A::
	lockall
	setvar 0x8008, 0x1
	applymovement 0x22, 0x08243621
	waitmovement 0x0
	goto Route104_EventScript_001E722F

Route104_EventScript_001E71AF::
	lockall
	setflag 0x32E
	setvar 0x405A, 0x8
	setvar 0x4063, 0x2
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	delay 0xA
	addobject 0x22
	clearflag 0x2CF
	applymovement 0xFF, 0x081E7482
	waitmovement 0x0
	applymovement 0x22, 0x081E7486
	waitmovement 0x0
	delay 0x14
	setvar 0x8008, 0x0
	call 0x081DEE0A
	playse 0x15
	applymovement 0x22, 0x0824361B
	waitmovement 0x0
	applymovement 0x22, 0x0824361D
	waitmovement 0x0
	goto Route104_EventScript_001E722F

	.incbin "baserom_jp.gba", 0x1e720d, 0x22
Route104_EventScript_001E722F::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route104_EventScript_001E7247
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route104_EventScript_001E736B
	end

Route104_EventScript_001E7247::
	checkflag 0x7D
	goto_if 0x1, Route104_EventScript_001E7318
	checkflag 0x7C
	goto_if 0x1, Route104_EventScript_001E72CC
	setflag 0x7C
	loadword 0x0, 0x081E7E3B
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x081E7E9E
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0xFD
	applymovement 0xFF, 0x081E72C9
	applymovement 0x22, 0x081E72C4
	loadword 0x0, 0x081E7EB6
	callstd 0x4
	closemessage
	waitmovement 0x0
	applymovement 0x22, 0x081E72C6
	waitmovement 0x0
	moveobjectoffscreen 0x22
	loadword 0x0, 0x081E7ED8
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route104_EventScript_001E72E9
	loadword 0x0, 0x081E7EFD
	callstd 0x4
	call Route104_EventScript_001E732D
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e72c4, 0x8
Route104_EventScript_001E72CC::
	loadword 0x0, 0x081E7F41
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route104_EventScript_001E72E9
	loadword 0x0, 0x081E7EFD
	callstd 0x4
	releaseall
	end

Route104_EventScript_001E72E9::
	loadword 0x0, 0x081E7F62
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E7332
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E7345
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E7358
	end

Route104_EventScript_001E7318::
	loadword 0x0, 0x081E7F9B
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, Route104_EventScript_001E732D
	releaseall
	end

Route104_EventScript_001E732D::
	savebgm 0x0
	fadedefaultbgm
	return

	.incbin "baserom_jp.gba", 0x1e7332, 0x39
Route104_EventScript_001E736B::
	checkflag 0x7D
	goto_if 0x1, Route104_EventScript_001E7434
	checkflag 0x7C
	goto_if 0x1, Route104_EventScript_001E73E8
	setflag 0x7C
	loadword 0x0, 0x081E8001
	callstd 0x4
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x081E805F
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0xFD
	applymovement 0xFF, 0x081E72C9
	applymovement 0x22, 0x081E72C4
	loadword 0x0, 0x081E8077
	callstd 0x4
	closemessage
	waitmovement 0x0
	applymovement 0x22, 0x081E72C6
	waitmovement 0x0
	moveobjectoffscreen 0x22
	loadword 0x0, 0x081E80A2
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route104_EventScript_001E7405
	loadword 0x0, 0x081E80CD
	callstd 0x4
	call Route104_EventScript_001E732D
	releaseall
	end

Route104_EventScript_001E73E8::
	loadword 0x0, 0x081E80EC
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route104_EventScript_001E7405
	loadword 0x0, 0x081E80CD
	callstd 0x4
	releaseall
	end

Route104_EventScript_001E7405::
	loadword 0x0, 0x081E8109
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E7449
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E745C
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E746F
	end

Route104_EventScript_001E7434::
	loadword 0x0, 0x081E813D
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, Route104_EventScript_001E732D
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e7449, 0x3f
Route104_EventScript_001E7488::
	lock
	faceplayer
	checkflag 0xF6
	goto_if 0x1, Route104_EventScript_001E74BF
	loadword 0x0, 0x082637EB
	callstd 0x4
	setorcopyvar 0x8000, 0x86
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xF6
	loadword 0x0, 0x08263847
	callstd 0x4
	release
	end

Route104_EventScript_001E74BF::
	loadword 0x0, 0x08263847
	callstd 0x4
	release
	end

Route104_EventScript_001E74C9::
	lock
	faceplayer
	checkflag 0x117
	goto_if 0x1, Route104_EventScript_001E74F8
	loadword 0x0, 0x081E7CC1
	callstd 0x4
	setorcopyvar 0x8000, 0xB4
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x117
	release
	end

Route104_EventScript_001E74F8::
	loadword 0x0, 0x081E7D17
	callstd 0x4
	release
	end

Route104_EventScript_001E7502::
	loadword 0x0, 0x081E7AE8
	callstd 0x2
	end

Route104_EventScript_001E750B::
	loadword 0x0, 0x081E7B35
	callstd 0x3
	end

Route104_EventScript_001E7514::
	loadword 0x0, 0x081E7D58
	callstd 0x3
	end

Route104_EventScript_001E751D::
	loadword 0x0, 0x081E7D65
	callstd 0x3
	end

Route104_EventScript_001E7526::
	loadword 0x0, 0x081E7D7E
	callstd 0x3
	end

Route104_EventScript_001E752F::
	loadword 0x0, 0x081E7D98
	callstd 0x3
	end

Route104_EventScript_001E7538::
	loadword 0x0, 0x081E7DAA
	callstd 0x3
	end

Route104_EventScript_001E7541::
	loadword 0x0, 0x081E7B5C
	callstd 0x2
	end

Route104_EventScript_001E754A::
	loadword 0x0, 0x081E7B96
	callstd 0x2
	end

Route104_EventScript_001E7553::
	lock
	faceplayer
	checkflag 0x106
	goto_if 0x1, Route104_EventScript_001E7582
	loadword 0x0, 0x081E7C2A
	callstd 0x4
	setorcopyvar 0x8000, 0x129
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x106
	release
	end

Route104_EventScript_001E7582::
	loadword 0x0, 0x081E7C88
	callstd 0x4
	release
	end

Route104_EventScript_001E758C::
	loadword 0x0, 0x081E7BCB
	callstd 0x2
	end

Route104_EventScript_001E7595::
	setobjectsubpriority 0x8, 0x13, 0x0
	setobjectsubpriority 0xFF, 0x13, 0x0
	applymovement 0x8, 0x081E7855
	waitmovement 0x0
	removeobject 0x8
	applymovement 0xFF, 0x081E784B
	waitmovement 0x0
	hideobject_at 0xFF, 0x13
	call 0x0824312C
	checkflag 0x132
	goto_if 0x1, Route104_EventScript_001E75D5
	checkflag 0x132
	goto_if 0x0, Route104_EventScript_001E75EB
	end

Route104_EventScript_001E75D5::
	applymovement 0x7, 0x081E7788
	applymovement 0xFF, 0x081E7788
	waitmovement 0x0
	goto Route104_EventScript_001E7635

Route104_EventScript_001E75EB::
	applymovement 0x7, 0x081E76C4
	applymovement 0xFF, 0x081E76C4
	waitmovement 0x0
	pokenavcall 0x081E82F9
	waitmessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, gJPText_001E83B3
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0x132
	applymovement 0xFF, 0x081E7726
	applymovement_at 0x7, 0x081E7726, 0x13
	waitmovement_at 0x7, 0x13
	waitmovement 0x0
	goto Route104_EventScript_001E7635

Route104_EventScript_001E7635::
	delay 0x32
	applymovement 0xFF, 0x081E784F
	waitmovement 0x0
	call 0x08243134
	showobject_at 0xFF, 0xB
	applymovement 0xFF, 0x081E7851
	waitmovement 0x0
	setobjectxyperm 0x2, 0xC, 0x8
	addobject 0x2
	setobjectsubpriority 0x2, 0xB, 0x0
	clearflag 0x2E4
	applymovement 0x2, 0x081E7858
	waitmovement 0x0
	addobject 0x4
	clearflag 0x2E7
	call 0x08243134
	setflag 0x2E6
	hideobject_at 0x7, 0x13
	copyvar 0x4096, 0x8008
	resetobjectsubpriority 0xFF, 0x13
	resetobjectsubpriority 0x2, 0xB
	moveobjectoffscreen 0x2
	setvar 0x408E, 0x0
	checkflag 0xBD
	goto_if 0x0, Route104_EventScript_001E76B0
	checkflag 0xBD
	goto_if 0x1, Route104_EventScript_001E76BA
	end

Route104_EventScript_001E76B0::
	loadword 0x0, gJPText_001E5191
	callstd 0x4
	releaseall
	end

Route104_EventScript_001E76BA::
	loadword 0x0, gJPText_001E522C
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e76c4, 0xada
