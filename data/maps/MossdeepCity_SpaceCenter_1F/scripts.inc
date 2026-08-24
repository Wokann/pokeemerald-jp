@ MossdeepCity_SpaceCenter_1F scripts (JP map g14 m9 @ 0x0820CD5D)

MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_EventScript_0020CDDE
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_EventScript_0020CD68
	.byte 0

MossdeepCity_SpaceCenter_1F_EventScript_0020CD68::
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CD74
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CD74::
	setobjectxyperm 0x3, 0x1, 0x9
	setobjectmovementtype 0x3, 0xA
	setobjectxyperm 0x5, 0x0, 0x8
	setobjectmovementtype 0x5, 0xA
	setobjectxyperm 0x4, 0x1, 0x6
	setobjectmovementtype 0x4, 0xA
	setobjectxyperm 0x1, 0x3, 0x4
	setobjectmovementtype 0x1, 0xA
	setobjectmovementtype 0x2, 0xA
	compare_var_to_value 0x409E, 0x1
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CDC6
	compare_var_to_value 0x409E, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CDCE
	compare_var_to_value 0x409E, 0x3
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CDD6
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CDC6::
	setobjectxyperm 0x9, 0xC, 0x2
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CDCE::
	setobjectxyperm 0x9, 0xD, 0x3
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CDD6::
	setobjectxyperm 0x9, 0xE, 0x2
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CDDE::
	compare_var_to_value 0x405D, 0x2
	goto_if 0x3, MossdeepCity_SpaceCenter_1F_EventScript_0020CDEA
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CDEA::
	setmetatile 0x2, 0x5, 0x3E4, 0x1
	return

MossdeepCity_SpaceCenter_1F_EventScript_0020CDF4::
	lock
	faceplayer
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CE40
	dotimebasedevents
	specialvar 0x800D, GetWeekCount
	buffernumberstring 0x0, 0x800D
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CE2E
	compare_var_to_value 0x800D, 0x1
	call_if 0x4, MossdeepCity_SpaceCenter_1F_EventScript_0020CE37
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CE2E::
	loadword 0x0, 0x0820D0C3
	callstd 0x4
	return

MossdeepCity_SpaceCenter_1F_EventScript_0020CE37::
	loadword 0x0, 0x0820D0D8
	callstd 0x4
	return

MossdeepCity_SpaceCenter_1F_EventScript_0020CE40::
	dotimebasedevents
	specialvar 0x800D, GetWeekCount
	buffernumberstring 0x0, 0x800D
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CE6D
	compare_var_to_value 0x800D, 0x1
	call_if 0x4, MossdeepCity_SpaceCenter_1F_EventScript_0020CE76
	closemessage
	applymovement 0x800F, 0x0824362B
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CE6D::
	loadword 0x0, 0x0820D0FD
	callstd 0x4
	return

MossdeepCity_SpaceCenter_1F_EventScript_0020CE76::
	loadword 0x0, 0x0820D126
	callstd 0x4
	return

MossdeepCity_SpaceCenter_1F_EventScript_0020CE7F::
	lock
	faceplayer
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CE96
	loadword 0x0, 0x0820D15F
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CE96::
	loadword 0x0, 0x0820D1DB
	callstd 0x4
	applymovement 0x800F, 0x0824362B
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CEAA::
	lock
	faceplayer
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CEF6
	checkflag 0xC0
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CEEC
	loadword 0x0, 0x0820D225
	callstd 0x4
	setorcopyvar 0x8000, 0x5D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xC0
	loadword 0x0, 0x0820D255
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CEEC::
	loadword 0x0, 0x0820D255
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CEF6::
	checkflag 0xC0
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CF35
	loadword 0x0, 0x0820D281
	callstd 0x4
	setorcopyvar 0x8000, 0x5D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xC0
	loadword 0x0, 0x0820D2C2
	callstd 0x4
	applymovement 0x800F, 0x0824362B
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CF35::
	loadword 0x0, 0x0820D2C2
	callstd 0x4
	applymovement 0x800F, 0x0824362B
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CF49::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CF70
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CF7A
	compare_var_to_value 0x405D, 0x2
	goto_if 0x0, MossdeepCity_SpaceCenter_1F_EventScript_0020CF70
	goto MossdeepCity_SpaceCenter_1F_EventScript_0020CF7A
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CF70::
	loadword 0x0, 0x0820D2E6
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CF7A::
	loadword 0x0, 0x0820D316
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CF84::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CFAB
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_1F_EventScript_0020CFC0
	compare_var_to_value 0x405D, 0x2
	goto_if 0x0, MossdeepCity_SpaceCenter_1F_EventScript_0020CFAB
	goto MossdeepCity_SpaceCenter_1F_EventScript_0020CFC0
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CFAB::
	loadword 0x0, 0x0820D357
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CFC0::
	loadword 0x0, 0x0820D38D
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CFD5::
	lock
	faceplayer
	loadword 0x0, 0x0820D3DA
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_0020CFEB::
	lockall
	loadword 0x0, 0x0820D5FC
	callstd 0x4
	releaseall
	end
