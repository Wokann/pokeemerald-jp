@ VerdanturfTown_BattleTentLobby scripts (JP map g6 m0 @ 0x081F6365)

VerdanturfTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentLobby_MapScriptTable_001F6384
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentLobby_MapScriptTable_001F6370
	.byte 0

VerdanturfTown_BattleTentLobby_MapScriptTable_001F6370::
	map_script_2 0x4001, 0x0, VerdanturfTown_BattleTentLobby_EventScript_001F637A
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_001F637A::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

VerdanturfTown_BattleTentLobby_MapScriptTable_001F6384::
	map_script_2 0x4000, 0x0, VerdanturfTown_BattleTentLobby_EventScript_001F63AE
	map_script_2 0x4000, 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F63B7
	map_script_2 0x4000, 0x2, VerdanturfTown_BattleTentLobby_EventScript_001F64CC
	map_script_2 0x4000, 0x3, VerdanturfTown_BattleTentLobby_EventScript_001F63EC
	map_script_2 0x4000, 0x4, VerdanturfTown_BattleTentLobby_EventScript_001F6492
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_001F63AE::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

VerdanturfTown_BattleTentLobby_EventScript_001F63B7::
	lockall
	loadword 0x0, gJPText_0022A7B5
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_001F63EC::
	lockall
	loadword 0x0, gJPText_002752A6
	callstd 0x4
	message gJPText_002752D8
	waitmessage
	setvar 0x8004, 0x6
	special CallVerdanturfTentFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x5
	setvar 0x8005, 0x0
	special CallVerdanturfTentFunction
	playse 0x37
	waitse

VerdanturfTown_BattleTentLobby_EventScript_001F6426::
	loadword 0x0, gJPText_002752ED
	callstd 0x4
	setvar 0x8004, 0x7
	special CallVerdanturfTentFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6472
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	message gJPText_00227865
	waitmessage
	playfanfare 0x172
	waitfanfare
	loadword 0x0, gJPText_002750A3
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6472::
	loadword 0x0, gJPText_0022A766
	callstd 0x4
	waitmessage
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6483::
	lockall
	loadword 0x0, gJPText_002752A6
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F6426
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6492::
	lockall
	message gJPText_0027527B
	waitmessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x5
	setvar 0x8005, 0x0
	special CallVerdanturfTentFunction
	playse 0x37
	waitse
	loadword 0x0, gJPText_002750A3
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_001F64CC::
	lockall
	loadword 0x0, gJPText_0022A790
	callstd 0x4
	message gJPText_0022A79A
	waitmessage
	setvar 0x8004, 0x5
	setvar 0x8005, 0x1
	special CallVerdanturfTentFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	goto VerdanturfTown_BattleTentLobby_EventScript_001F6643

VerdanturfTown_BattleTentLobby_EventScript_001F6508::
	lock
	faceplayer
	setvar 0x8004, 0x1
	special CallVerdanturfTentFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, VerdanturfTown_BattleTentLobby_EventScript_001F6483
	special SavePlayerParty
	loadword 0x0, 0x08274F21
	callstd 0x4

VerdanturfTown_BattleTentLobby_EventScript_001F6528::
	message 0x08274F55
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6564
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6670
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66CC
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66CC

VerdanturfTown_BattleTentLobby_EventScript_001F6564::
	setvar 0x40CF, 0x2
	setvar 0x40CE, 0x0
	setvar 0x800D, 0x2
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F667D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x2
	special CallFrontierUtilFunc
	loadword 0x0, 0x0827522E
	callstd 0x4
	fadescreen 0x1
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66C9
	loadword 0x0, 0x0827524A
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66C9
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F65E9
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66C9

VerdanturfTown_BattleTentLobby_EventScript_001F65E9::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special CallVerdanturfTentFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66B2

VerdanturfTown_BattleTentLobby_EventScript_001F6643::
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0027526A
	callstd 0x4
	closemessage
	call VerdanturfTown_BattleTentLobby_EventScript_001F66D6
	warp 0x601, 0xFF, 0x2, 0x7
	setvar 0x4000, 0x0
	waitstate
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6670::
	loadword 0x0, 0x08274F71
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F6528

VerdanturfTown_BattleTentLobby_EventScript_001F667D::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6698
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F66A5

VerdanturfTown_BattleTentLobby_EventScript_001F6698::
	loadword 0x0, 0x082750F0
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F66D4

VerdanturfTown_BattleTentLobby_EventScript_001F66A5::
	loadword 0x0, 0x0827518F
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F66D4

VerdanturfTown_BattleTentLobby_EventScript_001F66B2::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto VerdanturfTown_BattleTentLobby_EventScript_001F66CC

VerdanturfTown_BattleTentLobby_EventScript_001F66C9::
	special LoadPlayerParty

VerdanturfTown_BattleTentLobby_EventScript_001F66CC::
	loadword 0x0, gJPText_002750A3
	callstd 0x4

VerdanturfTown_BattleTentLobby_EventScript_001F66D4::
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F66D6::
	applymovement 0x1, 0x081F6705
	applymovement 0xFF, 0x081F6705
	waitmovement 0x0
	opendoor 0x6, 0x1
	waitmoncry
	applymovement 0x1, 0x081F6709
	applymovement 0xFF, 0x081F670C
	waitmovement 0x0
	closedoor 0x6, 0x1
	waitmoncry
	return

	.incbin "baserom_jp.gba", 0x1f6705, 0xb
VerdanturfTown_BattleTentLobby_EventScript_001F6710::
	lock
	faceplayer
	checkflag 0xEB
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6747
	loadword 0x0, 0x081F696C
	callstd 0x4
	setorcopyvar 0x8000, 0x14D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xEB
	loadword 0x0, 0x081F69C3
	callstd 0x4
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6747::
	loadword 0x0, 0x081F69C3
	callstd 0x4
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6751::
	loadword 0x0, 0x081F6A08
	callstd 0x2
	end

VerdanturfTown_BattleTentLobby_EventScript_001F675A::
	lock
	loadword 0x0, 0x081F6869
	callstd 0x4
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6765::
	lock
	faceplayer
	checkflag 0x1CC
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6782
	loadword 0x0, 0x081F6A5B
	callstd 0x4
	addvar 0x40D1, 0x1
	setflag 0x1CC
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6782::
	loadword 0x0, 0x081F6ADD
	callstd 0x4
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F678C::
	lock
	loadword 0x0, 0x081F6909
	callstd 0x4
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6797::
	lockall
	loadword 0x0, 0x08275C42
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F67A6::
	message 0x0822AC54
	waitmessage
	setvar 0x8004, 0xC
	special sub_0813A164
	waitstate
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6813
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6821
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F682F
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F683D
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F684B
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6859
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6867
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, VerdanturfTown_BattleTentLobby_EventScript_001F6867
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6813::
	loadword 0x0, 0x08275BCD
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6821::
	loadword 0x0, 0x0822AC64
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F682F::
	loadword 0x0, 0x0822ACC9
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F683D::
	loadword 0x0, 0x0822AD4C
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F684B::
	loadword 0x0, 0x0822AE0B
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6859::
	loadword 0x0, 0x0822AEA7
	callstd 0x4
	goto VerdanturfTown_BattleTentLobby_EventScript_001F67A6
	end

VerdanturfTown_BattleTentLobby_EventScript_001F6867::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f6869, 0x2a9
