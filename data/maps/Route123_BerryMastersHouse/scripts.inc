@ Route123_BerryMastersHouse scripts (JP map g31 m0 @ 0x08240F98)

Route123_BerryMastersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_BerryMastersHouse_EventScript_00240F9E
	.byte 0

Route123_BerryMastersHouse_EventScript_00240F9E::
	setflag 0x8C3
	end

Route123_BerryMastersHouse_EventScript_00240FA2::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x92D
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_00241013
	loadword 0x0, 0x08263AE4
	callstd 0x4
	random 0xA
	addvar 0x800D, 0x14
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x92D
	loadword 0x0, 0x08263B47
	callstd 0x4
	random 0xA
	addvar 0x800D, 0x14
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	loadword 0x0, 0x08263B5B
	callstd 0x4
	release
	end

Route123_BerryMastersHouse_EventScript_00241013::
	loadword 0x0, 0x08263B94
	callstd 0x4
	release
	end

Route123_BerryMastersHouse_EventScript_0024101D::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x931
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002411CC
	loadword 0x0, 0x08263BBC
	callstd 0x4
	setvar 0x8004, 0xD
	call 0x08242F08
	lock
	faceplayer
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_00241066
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_00241054
	end

Route123_BerryMastersHouse_EventScript_00241054::
	loadword 0x0, 0x08263C99
	callstd 0x4
	loadword 0x0, 0x08263C63
	callstd 0x4
	release
	end

Route123_BerryMastersHouse_EventScript_00241066::
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410A9
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410D7
	compare_var_to_value 0x8004, 0x2
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_00241108
	compare_var_to_value 0x8004, 0x3
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_00241139
	compare_var_to_value 0x8004, 0x4
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_0024116A
	compare_var_to_value 0x8004, 0x5
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_0024119B
	end

Route123_BerryMastersHouse_EventScript_002410A9::
	loadword 0x0, 0x08263C33
	callstd 0x4
	random 0xA
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	goto Route123_BerryMastersHouse_EventScript_002411D6

	.incbin "baserom_jp.gba", 0x2410d5, 0x2
Route123_BerryMastersHouse_EventScript_002410D7::
	checkflag 0xF8
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410A9
	loadword 0x0, 0x08263C07
	callstd 0x4
	setorcopyvar 0x8000, 0xA3
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xF8
	goto Route123_BerryMastersHouse_EventScript_002411D6
	end

Route123_BerryMastersHouse_EventScript_00241108::
	checkflag 0xF9
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410A9
	loadword 0x0, 0x08263C07
	callstd 0x4
	setorcopyvar 0x8000, 0xA4
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xF9
	goto Route123_BerryMastersHouse_EventScript_002411D6
	end

Route123_BerryMastersHouse_EventScript_00241139::
	checkflag 0xFA
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410A9
	loadword 0x0, 0x08263C07
	callstd 0x4
	setorcopyvar 0x8000, 0xA5
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xFA
	goto Route123_BerryMastersHouse_EventScript_002411D6
	end

Route123_BerryMastersHouse_EventScript_0024116A::
	checkflag 0xFB
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410A9
	loadword 0x0, 0x08263C07
	callstd 0x4
	setorcopyvar 0x8000, 0xA6
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xFB
	goto Route123_BerryMastersHouse_EventScript_002411D6
	end

Route123_BerryMastersHouse_EventScript_0024119B::
	checkflag 0xFC
	goto_if 0x1, Route123_BerryMastersHouse_EventScript_002410A9
	loadword 0x0, 0x08263C07
	callstd 0x4
	setorcopyvar 0x8000, 0xA7
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xFC
	goto Route123_BerryMastersHouse_EventScript_002411D6
	end

Route123_BerryMastersHouse_EventScript_002411CC::
	loadword 0x0, 0x08263C63
	callstd 0x4
	release
	end

Route123_BerryMastersHouse_EventScript_002411D6::
	setflag 0x931
	loadword 0x0, 0x08263C63
	callstd 0x4
	release
	end

