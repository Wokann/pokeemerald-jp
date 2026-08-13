@ Route104_MrBrineysHouse scripts (JP map g17 m0 @ 0x082115F0)

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_EventScript_002115F6
	.byte 0

Route104_MrBrineysHouse_EventScript_002115F6::
	setflag 0x89D
	compare_var_to_value 0x4090, 0x1
	call_if 0x1, Route104_MrBrineysHouse_EventScript_00211612
	checkflag 0xBC
	call_if 0x1, Route104_MrBrineysHouse_EventScript_0021160E
	end

Route104_MrBrineysHouse_EventScript_0021160E::
	setflag 0x32E
	return

Route104_MrBrineysHouse_EventScript_00211612::
	setobjectxyperm 0x1, 0x9, 0x3
	setobjectmovementtype 0x1, 0x32
	setobjectxyperm 0x2, 0x9, 0x6
	setobjectmovementtype 0x2, 0x33
	return

Route104_MrBrineysHouse_EventScript_00211629::
	lock
	faceplayer
	checkflag 0x93
	call_if 0x0, Route104_MrBrineysHouse_EventScript_0021164C
	checkflag 0xBD
	goto_if 0x0, Route104_MrBrineysHouse_EventScript_002116A3
	checkflag 0x95
	goto_if 0x0, Route104_MrBrineysHouse_EventScript_002116BC
	goto Route104_MrBrineysHouse_EventScript_00211670
	end

Route104_MrBrineysHouse_EventScript_0021164C::
	setflag 0x93
	loadword 0x0, 0x08211732
	callstd 0x4
	loadword 0x0, 0x08211749
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route104_MrBrineysHouse_EventScript_002116D5
	goto Route104_MrBrineysHouse_EventScript_002116E9
	end

Route104_MrBrineysHouse_EventScript_00211670::
	message 0x0821192C
	waitmessage
	multichoicedefault 0x14, 0x8, 0xE, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route104_MrBrineysHouse_EventScript_002116E9
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route104_MrBrineysHouse_EventScript_002116DF
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, Route104_MrBrineysHouse_EventScript_002116DF
	end

Route104_MrBrineysHouse_EventScript_002116A3::
	loadword 0x0, 0x0821185C
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route104_MrBrineysHouse_EventScript_002116D5
	goto Route104_MrBrineysHouse_EventScript_002116E9
	end

Route104_MrBrineysHouse_EventScript_002116BC::
	loadword 0x0, 0x082118C7
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route104_MrBrineysHouse_EventScript_002116D5
	goto Route104_MrBrineysHouse_EventScript_002116E9
	end

Route104_MrBrineysHouse_EventScript_002116D5::
	loadword 0x0, 0x0821181B
	callstd 0x4
	release
	end

Route104_MrBrineysHouse_EventScript_002116DF::
	loadword 0x0, 0x0821195C
	callstd 0x4
	release
	end

Route104_MrBrineysHouse_EventScript_002116E9::
	loadword 0x0, 0x082117FE
	callstd 0x4
	call 0x08242F21
	setvar 0x408E, 0x1
	clearflag 0x2E2
	setflag 0x2E3
	setflag 0x371
	setvar 0x405A, 0x8
	setvar 0x4063, 0x2
	setflag 0x32E
	setflag 0x2CF
	warp 0x13, 0xFF, 0xD, 0x33
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_0021171F::
	lock
	faceplayer
	waitse
	playmoncry 0x135, 0x0
	loadword 0x0, 0x082119A3
	callstd 0x4
	waitdooranim
	release
	end

	.incbin "baserom_jp.gba", 0x211732, 0x282
