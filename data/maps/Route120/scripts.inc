@ Route120 scripts (JP map g0 m35 @ 0x081ED864)

Route120_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route120_EventScript_001ED874
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_EventScript_001ED945
	map_script MAP_SCRIPT_ON_LOAD, Route120_EventScript_001ED8EC
	.byte 0

Route120_EventScript_001ED874::
	checkflag 0x8C1
	call_if 0x1, Route120_EventScript_001ED87E
	end

Route120_EventScript_001ED87E::
	compare_var_to_value 0x8009, 0x0
	call_if 0x1, Route120_EventScript_001ED8C1
	compare_var_to_value 0x8009, 0x1
	call_if 0x1, Route120_EventScript_001ED8D8
	compare_var_to_value 0x8009, 0x2
	call_if 0x1, Route120_EventScript_001ED8D8
	compare_var_to_value 0x8009, 0x3
	call_if 0x1, Route120_EventScript_001ED8D8
	compare_var_to_value 0x8009, 0x4
	call_if 0x1, Route120_EventScript_001ED8D8
	compare_var_to_value 0x8009, 0x5
	call_if 0x1, Route120_EventScript_001ED8D8
	return

Route120_EventScript_001ED8C1::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x1E
	removeobject 0x24
	return

Route120_EventScript_001ED8D8::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

Route120_EventScript_001ED8EC::
	checkflag 0xE4
	call_if 0x0, Route120_EventScript_001ED908
	checkflag 0x11D
	call_if 0x1, Route120_EventScript_001ED91B
	checkflag 0x11D
	call_if 0x0, Route120_EventScript_001ED940
	end

Route120_EventScript_001ED908::
	setmetatile 0x7, 0x36, 0x7C, 0x1
	setmetatile 0x7, 0x37, 0x91, 0x1
	return

Route120_EventScript_001ED91B::
	setmetatile 0xD, 0xF, 0x297, 0x0
	setmetatile 0xC, 0x10, 0x29F, 0x0
	setmetatile 0xC, 0x11, 0xA1, 0x0
	setmetatile 0xD, 0x11, 0xA1, 0x0
	return

Route120_EventScript_001ED940::
	setobjectmovementtype 0x24, 0xA
	return

Route120_EventScript_001ED945::
	call 0x082540DF
	call Route120_EventScript_001ED950
	end

Route120_EventScript_001ED950::
	getplayerxy 0x4000, 0x4001
	compare_var_to_value 0x4001, 0xE
	goto_if 0x3, Route120_EventScript_001ED97B
	compare_var_to_value 0x4001, 0x3C
	goto_if 0x3, Route120_EventScript_001ED97F
	compare_var_to_value 0x4001, 0x3D
	goto_if 0x4, Route120_EventScript_001ED977
	return

Route120_EventScript_001ED977::
	setweather 0x1
	return

Route120_EventScript_001ED97B::
	setweather 0x2
	return

Route120_EventScript_001ED97F::
	compare_var_to_value 0x4000, 0x7
	goto_if 0x3, Route120_EventScript_001ED99B
	compare_var_to_value 0x4000, 0x13
	goto_if 0x3, Route120_EventScript_001ED97B
	goto Route120_EventScript_001ED99B
	end

Route120_EventScript_001ED99B::
	setweather 0x3
	return

Route120_EventScript_001ED99F::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x92E
	goto_if 0x1, Route120_EventScript_001EDA9D
	loadword 0x0, 0x0826398A
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route120_EventScript_001EDAA7
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route120_EventScript_001EDAB0
	specialvar 0x800D, GetPlayerTrainerIdOnesDigit
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route120_EventScript_001EDA42
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route120_EventScript_001EDA42
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route120_EventScript_001EDA4D
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route120_EventScript_001EDA4D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route120_EventScript_001EDA58
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route120_EventScript_001EDA58
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route120_EventScript_001EDA63
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, Route120_EventScript_001EDA63
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route120_EventScript_001EDA6E
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, Route120_EventScript_001EDA6E
	end

Route120_EventScript_001EDA42::
	setvar 0x8004, 0x8F
	goto Route120_EventScript_001EDA79
	end

Route120_EventScript_001EDA4D::
	setvar 0x8004, 0x90
	goto Route120_EventScript_001EDA79
	end

Route120_EventScript_001EDA58::
	setvar 0x8004, 0x91
	goto Route120_EventScript_001EDA79
	end

Route120_EventScript_001EDA63::
	setvar 0x8004, 0x92
	goto Route120_EventScript_001EDA79
	end

Route120_EventScript_001EDA6E::
	setvar 0x8004, 0x93
	goto Route120_EventScript_001EDA79
	end

Route120_EventScript_001EDA79::
	setorcopyvar 0x8000, 0x8004
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x92E
	loadword 0x0, 0x08263A1E
	callstd 0x4
	release
	end

Route120_EventScript_001EDA9D::
	loadword 0x0, 0x08263A41
	callstd 0x4
	release
	end

Route120_EventScript_001EDAA7::
	loadword 0x0, 0x082639DA
	callstd 0x4
	return

Route120_EventScript_001EDAB0::
	loadword 0x0, 0x082639FA
	callstd 0x4
	return

Route120_EventScript_001EDAB9::
	lock
	faceplayer
	checkflag 0x122
	goto_if 0x1, Route120_EventScript_001EDAEA
	loadword 0x0, 0x081EDE10
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route120_EventScript_001EDADD
	goto Route120_EventScript_001EDB03
	end

Route120_EventScript_001EDADD::
	loadword 0x0, 0x081EDEA6
	callstd 0x4
	setflag 0x122
	release
	end

Route120_EventScript_001EDAEA::
	loadword 0x0, 0x081EDECC
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route120_EventScript_001EDADD
	goto Route120_EventScript_001EDB03
	end

Route120_EventScript_001EDB03::
	loadword 0x0, 0x081EDEF4
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, Route120_EventScript_001EDC1B
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, Route120_EventScript_001EDC26
	applymovement 0x1F, 0x08243627
	waitmovement 0x0
	delay 0x14
	loadword 0x0, 0x081EDF1B
	callstd 0x4
	closemessage
	applymovement 0x1E, 0x0824362B
	waitmovement 0x0
	applymovement 0x1E, 0x0824344A
	waitmovement 0x0
	waitse
	playmoncry 0x13D, 0x2
	delay 0x28
	waitdooranim
	setwildbattle 0x13D, 0x1E, 0x0
	setvar 0x8009, 0x0
	setflag 0x8C1
	dowildbattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route120_EventScript_001EDB94
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, Route120_EventScript_001EDB94
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, Route120_EventScript_001EDB94
	goto Route120_EventScript_001EDBA4
	end

Route120_EventScript_001EDB94::
	fadescreenswapbuffers 0x1
	removeobject 0x1E
	removeobject 0x24
	fadescreenswapbuffers 0x0
	goto Route120_EventScript_001EDBA4
	end

Route120_EventScript_001EDBA4::
	applymovement 0x1F, 0x0824362D
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, 0x081EDF65
	callstd 0x4
	setorcopyvar 0x8000, 0x120
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x11D
	loadword 0x0, 0x081EDFE1
	callstd 0x4
	closemessage
	applymovement 0x1F, 0x0824362D
	waitmovement 0x0
	delay 0x32
	setfieldeffectarg 0x0, 0x1
	dofieldeffect 0x1E
	delay 0xF
	removeobject 0x1F
	waitfieldeffect 0x1E
	setmetatile 0xD, 0xF, 0x297, 0x0
	setmetatile 0xC, 0x10, 0x29F, 0x0
	setmetatile 0xC, 0x11, 0xA1, 0x0
	setmetatile 0xD, 0x11, 0xA1, 0x0
	special DrawWholeMapView
	release
	end

Route120_EventScript_001EDC1B::
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	return

Route120_EventScript_001EDC26::
	applymovement 0xFF, 0x081EDC31
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1edc31, 0x3
Route120_EventScript_001EDC34::
	loadword 0x0, 0x081EE029
	callstd 0x2
	end

Route120_EventScript_001EDC3D::
	loadword 0x0, 0x081EE0A3
	callstd 0x3
	end

Route120_EventScript_001EDC46::
	loadword 0x0, 0x081EE0BD
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1edc4f, 0x787
