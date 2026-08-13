@ LilycoveCity scripts (JP map g0 m5 @ 0x081E0171)

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_EventScript_001E017C
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_EventScript_001E0196
	.byte 0

LilycoveCity_EventScript_001E017C::
	setflag 0x87B
	setvar 0x4086, 0x0
	setflag 0x322
	checkflag 0x88A
	call_if 0x1, 0x08243106
	call 0x08242F63
	end

LilycoveCity_EventScript_001E0196::
	checkflag 0x70
	call_if 0x0, LilycoveCity_EventScript_001E01A0
	end

LilycoveCity_EventScript_001E01A0::
	setmetatile 0x4C, 0xC, 0x290, 0x1
	setmetatile 0x4D, 0xC, 0x291, 0x1
	setmetatile 0x4C, 0xD, 0x2A0, 0x1
	setmetatile 0x4D, 0xD, 0x2A1, 0x1
	setmetatile 0x4C, 0xE, 0x298, 0x1
	setmetatile 0x4D, 0xE, 0x299, 0x1
	setmetatile 0x4C, 0xF, 0x2A0, 0x1
	setmetatile 0x4D, 0xF, 0x2A1, 0x1
	setmetatile 0x4D, 0x10, 0x298, 0x1
	setmetatile 0x4E, 0x10, 0x299, 0x1
	setmetatile 0x4D, 0x11, 0x2A0, 0x1
	setmetatile 0x4E, 0x11, 0x2A1, 0x1
	return

LilycoveCity_EventScript_001E020D::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x92F
	goto_if 0x1, LilycoveCity_EventScript_001E024D
	loadword 0x0, 0x08263A58
	callstd 0x4
	random 0xA
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x92F
	loadword 0x0, 0x08263A9E
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E024D::
	loadword 0x0, 0x08263ABA
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E0257::
	loadword 0x0, 0x081E0DD4
	callstd 0x2
	end

LilycoveCity_EventScript_001E0260::
	lock
	faceplayer
	checkflag 0x86D
	goto_if 0x1, LilycoveCity_EventScript_001E0275
	loadword 0x0, 0x081E0E2F
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E0275::
	loadword 0x0, 0x081E0E50
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E027F::
	loadword 0x0, 0x081E0EA8
	callstd 0x2
	end

LilycoveCity_EventScript_001E0288::
	lock
	faceplayer
	checkflag 0x70
	goto_if 0x1, LilycoveCity_EventScript_001E029D
	loadword 0x0, 0x081E0F11
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E029D::
	loadword 0x0, 0x081E0F57
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E02A7::
	lock
	faceplayer
	checkflag 0x70
	goto_if 0x1, LilycoveCity_EventScript_001E02BC
	loadword 0x0, 0x081E0FA2
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E02BC::
	loadword 0x0, 0x081E0FFF
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E02C6::
	loadword 0x0, 0x081E1021
	callstd 0x2
	end

LilycoveCity_EventScript_001E02CF::
	loadword 0x0, 0x081E1092
	callstd 0x3
	end

LilycoveCity_EventScript_001E02D8::
	loadword 0x0, 0x081E10D3
	callstd 0x3
	end

LilycoveCity_EventScript_001E02E1::
	lock
	faceplayer
	checkflag 0x86D
	goto_if 0x1, LilycoveCity_EventScript_001E02F6
	loadword 0x0, 0x081E111B
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E02F6::
	loadword 0x0, 0x081E11AF
	callstd 0x4
	release
	end

LilycoveCity_EventScript_001E0300::
	loadword 0x0, 0x081E1431
	callstd 0x2
	end

LilycoveCity_EventScript_001E0309::
	loadword 0x0, 0x081E145A
	callstd 0x2
	end

LilycoveCity_EventScript_001E0312::
	lockall
	loadword 0x0, 0x081E148D
	callstd 0x2
	applymovement 0x14, 0x08243625
	end

LilycoveCity_EventScript_001E0323::
	lockall
	loadword 0x0, 0x081E14F9
	callstd 0x2
	applymovement 0x13, 0x08243625
	end

LilycoveCity_EventScript_001E0334::
	loadword 0x0, 0x081E11F4
	callstd 0x3
	end

LilycoveCity_EventScript_001E033D::
	loadword 0x0, 0x081E1213
	callstd 0x3
	end

LilycoveCity_EventScript_001E0346::
	loadword 0x0, 0x081E1234
	callstd 0x3
	end

LilycoveCity_EventScript_001E034F::
	lockall
	specialvar 0x8004, CountPlayerContestPaintings
	copyvar 0x8000, 0x8004
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_EventScript_001E036F
	loadword 0x0, 0x081E1276
	callstd 0x4
	releaseall
	end

LilycoveCity_EventScript_001E036F::
	loadword 0x0, 0x081E1254
	callstd 0x4
	releaseall
	end

LilycoveCity_EventScript_001E0379::
	lockall
	checkflag 0x864
	goto_if 0x1, LilycoveCity_EventScript_001E038D
	loadword 0x0, 0x081E129D
	callstd 0x4
	releaseall
	end

LilycoveCity_EventScript_001E038D::
	loadword 0x0, 0x081E12E3
	callstd 0x4
	releaseall
	end

LilycoveCity_EventScript_001E0397::
	loadword 0x0, 0x081E1318
	callstd 0x3
	end

LilycoveCity_EventScript_001E03A0::
	loadword 0x0, 0x081E1350
	callstd 0x3
	end

LilycoveCity_EventScript_001E03A9::
	loadword 0x0, 0x081E1383
	callstd 0x3
	end

LilycoveCity_EventScript_001E03B2::
	lockall
	checkflag 0xDA
	goto_if 0x1, LilycoveCity_EventScript_001E03E5
	loadword 0x0, 0x081E0D86
	callstd 0x4
	applymovement 0x800F, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x081E0DA6
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	setflag 0xDA
	releaseall
	end

LilycoveCity_EventScript_001E03E5::
	loadword 0x0, 0x081E0D86
	callstd 0x4
	releaseall
	end

LilycoveCity_EventScript_001E03EF::
	loadword 0x0, 0x081E0C6D
	callstd 0x2
	end

LilycoveCity_EventScript_001E03F8::
	loadword 0x0, 0x081E0CAE
	callstd 0x2
	end

LilycoveCity_EventScript_001E0401::
	loadword 0x0, 0x081E0D08
	callstd 0x2
	end

LilycoveCity_EventScript_001E040A::
	loadword 0x0, 0x081E0D4E
	callstd 0x2
	end

LilycoveCity_EventScript_001E0413::
	lock
	faceplayer
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_EventScript_001E042D
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_EventScript_001E04A0
	end

LilycoveCity_EventScript_001E042D::
	playbgm 0x19F, 0x1
	checkflag 0x11E
	call_if 0x1, LilycoveCity_EventScript_001E047D
	checkflag 0x11E
	call_if 0x0, LilycoveCity_EventScript_001E0486
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_EventScript_001E048F
	loadword 0x0, 0x081E078B
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E0513
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E0523
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E0533
	end

LilycoveCity_EventScript_001E047D::
	loadword 0x0, 0x081E0769
	callstd 0x5
	return

LilycoveCity_EventScript_001E0486::
	loadword 0x0, 0x081E0696
	callstd 0x5
	return

LilycoveCity_EventScript_001E048F::
	setflag 0x11E
	loadword 0x0, 0x081E0733
	callstd 0x4
	savebgm 0x0
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_001E04A0::
	playbgm 0x1A5, 0x1
	checkflag 0x11E
	call_if 0x1, LilycoveCity_EventScript_001E04F0
	checkflag 0x11E
	call_if 0x0, LilycoveCity_EventScript_001E04F9
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_EventScript_001E0502
	loadword 0x0, 0x081E0A56
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081E0543
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081E0553
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081E0563
	end

LilycoveCity_EventScript_001E04F0::
	loadword 0x0, 0x081E0A2F
	callstd 0x5
	return

LilycoveCity_EventScript_001E04F9::
	loadword 0x0, 0x081E09A9
	callstd 0x5
	return

LilycoveCity_EventScript_001E0502::
	setflag 0x11E
	loadword 0x0, 0x081E0A1B
	callstd 0x4
	savebgm 0x0
	fadedefaultbgm
	release
	end

	.incbin "baserom_jp.gba", 0x1e0513, 0x14f
LilycoveCity_EventScript_001E0662::
	lock
	faceplayer
	loadword 0x0, 0x081E13A5
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LilycoveCity_EventScript_001E0684
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_EventScript_001E068D
	release
	end

LilycoveCity_EventScript_001E0684::
	loadword 0x0, 0x081E13C0
	callstd 0x4
	return

LilycoveCity_EventScript_001E068D::
	loadword 0x0, 0x081E13F5
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x1e0696, 0xecf
