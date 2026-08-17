@ BattleFrontier_BattleTowerLobby scripts (JP map g26 m5 @ 0x0821F6BC)

BattleFrontier_BattleTowerLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_EventScript_0021F6D1
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_EventScript_0021F6D5
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_MapScriptTable_0021F71E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_MapScriptTable_0021F70A
	.byte 0

BattleFrontier_BattleTowerLobby_EventScript_0021F6D1::
	special sub_08165248
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F6D5::
	call 0x0825409C
	setvar 0x8004, 0xA
	special CallApprenticeFunction
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F6F6
	checkflag 0x934
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F702

BattleFrontier_BattleTowerLobby_EventScript_0021F6F6::
	clearflag 0x2BD
	setvar 0x8004, 0x17
	special CallApprenticeFunction

BattleFrontier_BattleTowerLobby_EventScript_0021F701::
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F702::
	setflag 0x2BD
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F701

BattleFrontier_BattleTowerLobby_MapScriptTable_0021F70A::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerLobby_EventScript_0021F714
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_0021F714::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleTowerLobby_MapScriptTable_0021F71E::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerLobby_EventScript_0021F748
	map_script_2 0x4000, 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F751
	map_script_2 0x4000, 0x2, BattleFrontier_BattleTowerLobby_EventScript_0021F92F
	map_script_2 0x4000, 0x3, BattleFrontier_BattleTowerLobby_EventScript_0021F799
	map_script_2 0x4000, 0x4, BattleFrontier_BattleTowerLobby_EventScript_0021F833
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_0021F748::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F751::
	lock
	faceplayer
	loadword 0x0, gJPText_002205B3
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F799::
	lock
	faceplayer
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F7B9
	message gJPText_00220604
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F7C1

BattleFrontier_BattleTowerLobby_EventScript_0021F7B9::
	loadword 0x0, gJPText_00221846
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F7C1::
	setvar 0x8004, 0x5
	special sub_08161E88
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F7E6
	message gJPText_00220736
	waitmessage
	playfanfare 0x172
	waitfanfare
	loadword 0x0, gJPText_00220769
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F7E6::
	loadword 0x0, gJPText_00221873
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022189E
	callstd 0x9
	call BattleFrontier_BattleTowerLobby_EventScript_0021F88E
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special sub_08161E88
	compare_var_to_value 0x800D, 0x31
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_0021F823
	loadword 0x0, gJPText_002206DE
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F823::
	loadword 0x0, gJPText_002209A0
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F833::
	compare_var_to_value 0x40CE, 0x2
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_0021F85F
	checkflag 0x152
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F85F
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special sub_08161E88
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_0021F871

BattleFrontier_BattleTowerLobby_EventScript_0021F85F::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special sub_08161E88

BattleFrontier_BattleTowerLobby_EventScript_0021F871::
	lock
	faceplayer
	message gJPText_00220681
	waitmessage
	call BattleFrontier_BattleTowerLobby_EventScript_0021F88E
	loadword 0x0, gJPText_002209A0
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F88E::
	message gJPText_0022068D
	waitmessage
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special sub_08161E88
	playse 0x37
	waitse
	call BattleFrontier_BattleTowerLobby_EventScript_0021F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F920
	message gJPText_00220A3B
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F920
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F8F5
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F920

BattleFrontier_BattleTowerLobby_EventScript_0021F8F5::
	setvar 0x8004, 0x13
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F918
	playse 0x37
	loadword 0x0, gJPText_00222412
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F920

BattleFrontier_BattleTowerLobby_EventScript_0021F918::
	loadword 0x0, gJPText_0022247E
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F920::
	return

BattleFrontier_BattleTowerLobby_EventScript_0021F921::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x6
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_0021F92F::
	lock
	faceplayer
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F971
	message gJPText_002206A8
	waitmessage
	message gJPText_002206B5
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F971::
	setvar 0x40BC, 0x1
	return

BattleFrontier_BattleTowerLobby_EventScript_0021F977::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, 0x08220FA0
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F989::
	message 0x08220FE6
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F9C5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FAD2
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021F9C5::
	setvar 0x40CE, 0x0
	message 0x082209B7
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x08221126
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, 0x082209FD
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FA6B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FA6B::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
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
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	setvar 0x40BC, 0x1
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FAD2::
	loadword 0x0, 0x08221000
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F989
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FAE0::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, 0x08221144
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021FAF2::
	message 0x08221189
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FB2E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FC3B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021FB2E::
	setvar 0x40CE, 0x1
	message 0x082209B7
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x082212C4
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x4
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, 0x082209FD
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FBD4
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FBD4::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
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
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FC3B::
	loadword 0x0, 0x082211A2
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FAF2
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FC49::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	clearflag 0x152
	special SavePlayerParty
	loadword 0x0, 0x082212E2
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021FC5E::
	message 0x08221327
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FC9A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FDA7
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021FC9A::
	setvar 0x40CE, 0x2
	message 0x082209B7
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x082214BC
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, 0x082209FD
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FD40
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FD40::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
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
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FDA7::
	loadword 0x0, 0x08221340
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FC5E
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FDB5::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, 0x082214DA
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021FDC7::
	message 0x08221523
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FE03
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022041B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021FE03::
	setvar 0x40CE, 0x3
	message 0x082209B7
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822169F
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, 0x082209FD
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FEA9
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FEA9::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special sub_08161E88
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	specialvar 0x800D, IsWirelessAdapterConnected
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220429
	goto BattleFrontier_BattleTowerLobby_EventScript_00220306
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FF28::
	lock
	faceplayer
	message 0x08220781
	waitmessage
	multichoice 0x10, 0x4, 0x6D, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FF73
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FF8D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFA7
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFC1
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFC1
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FF73::
	loadword 0x0, 0x082207C9
	callstd 0x4
	setvar 0x8004, 0x1
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FFCB
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FF8D::
	loadword 0x0, 0x082207E6
	callstd 0x4
	setvar 0x8004, 0x2
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FFCB
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFA7::
	loadword 0x0, 0x08220809
	callstd 0x4
	setvar 0x8004, 0x3
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FFCB
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFC1::
	loadword 0x0, 0x0822082B
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFCB::
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFE2
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFEC
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFE2::
	loadword 0x0, 0x0822084C
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFEC::
	loadword 0x0, 0x0822086A
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFF6::
	loadword 0x0, 0x08220896
	callstd 0x2
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFFF::
	loadword 0x0, 0x082208CE
	callstd 0x2
	end

BattleFrontier_BattleTowerLobby_EventScript_00220008::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_00220021::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_0022003A::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x2
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_00220053::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_0022006C::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220087
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200CC

BattleFrontier_BattleTowerLobby_EventScript_00220087::
	copyvar 0x8000, 0x40CE
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200B0
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200BE
	loadword 0x0, 0x08220E53
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200B0::
	loadword 0x0, 0x08220BB9
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200BE::
	loadword 0x0, 0x08220D06
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200CC::
	copyvar 0x8000, 0x40CE
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200F5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220103
	loadword 0x0, 0x08220EFF
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200F5::
	loadword 0x0, 0x08220C65
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_00220103::
	loadword 0x0, 0x08220DB2
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_00220111::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_00220127
	end

BattleFrontier_BattleTowerLobby_EventScript_00220124::
	special LoadPlayerParty

BattleFrontier_BattleTowerLobby_EventScript_00220127::
	special CloseLink
	loadword 0x0, gJPText_002209A0
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_00220132::
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_00220134::
	special SavePlayerParty
	setvar 0x8004, 0x3
	call BattleFrontier_BattleTowerLobby_EventScript_002202B3
	special CallFrontierUtilFunc
	setvar 0x800D, 0x0

BattleFrontier_BattleTowerLobby_EventScript_00220149::
	setvar 0x8004, 0xC
	special sub_08161E88
	delay 0x1
	compare_var_to_value 0x800D, 0x6
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_00220149
	call BattleFrontier_BattleTowerLobby_EventScript_00220176
	clearflag 0x77
	warp 0x1A06, 0xFF, 0x1, 0x6
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_00220176::
	call BattleFrontier_BattleTowerLobby_EventScript_002201E8
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220193
	loadword 0x0, gJPText_00220A1E
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022019C

BattleFrontier_BattleTowerLobby_EventScript_00220193::
	messageautoscroll 0x08220A1E
	waitmessage
	delay 0x30

BattleFrontier_BattleTowerLobby_EventScript_0022019C::
	closemessage
	call BattleFrontier_BattleTowerLobby_EventScript_00220229
	call BattleFrontier_BattleTowerLobby_EventScript_0022026E
	applymovement 0x800F, 0x082201D6
	applymovement 0xFF, 0x082201D6
	waitmovement 0x0
	opendoor 0x8004, 0x1
	waitmoncry
	applymovement 0x800F, 0x082201DA
	applymovement 0xFF, 0x082201DD
	waitmovement 0x0
	closedoor 0x8004, 0x1
	waitmoncry
	return

	.incbin "baserom_jp.gba", 0x2201d6, 0x12
BattleFrontier_BattleTowerLobby_EventScript_002201E8::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220215
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022021A
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022021F
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220224
	return

BattleFrontier_BattleTowerLobby_EventScript_00220215::
	bufferstdstring 0x0, 0x13
	return

BattleFrontier_BattleTowerLobby_EventScript_0022021A::
	bufferstdstring 0x0, 0x14
	return

BattleFrontier_BattleTowerLobby_EventScript_0022021F::
	bufferstdstring 0x0, 0x15
	return

BattleFrontier_BattleTowerLobby_EventScript_00220224::
	bufferstdstring 0x0, 0x16
	return

BattleFrontier_BattleTowerLobby_EventScript_00220229::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220256
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022025C
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220262
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220268
	return

BattleFrontier_BattleTowerLobby_EventScript_00220256::
	setvar 0x800F, 0x1
	return

BattleFrontier_BattleTowerLobby_EventScript_0022025C::
	setvar 0x800F, 0x7
	return

BattleFrontier_BattleTowerLobby_EventScript_00220262::
	setvar 0x800F, 0x8
	return

BattleFrontier_BattleTowerLobby_EventScript_00220268::
	setvar 0x800F, 0x9
	return

BattleFrontier_BattleTowerLobby_EventScript_0022026E::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022029B
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202A1
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202A7
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202AD
	return

BattleFrontier_BattleTowerLobby_EventScript_0022029B::
	setvar 0x8004, 0x6
	return

BattleFrontier_BattleTowerLobby_EventScript_002202A1::
	setvar 0x8004, 0xA
	return

BattleFrontier_BattleTowerLobby_EventScript_002202A7::
	setvar 0x8004, 0xE
	return

BattleFrontier_BattleTowerLobby_EventScript_002202AD::
	setvar 0x8004, 0x12
	return

BattleFrontier_BattleTowerLobby_EventScript_002202B3::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202E0
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202E6
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202EC
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202F2
	return

BattleFrontier_BattleTowerLobby_EventScript_002202E0::
	setvar 0x8005, 0x3
	return

BattleFrontier_BattleTowerLobby_EventScript_002202E6::
	setvar 0x8005, 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002202EC::
	setvar 0x8005, 0x2
	return

BattleFrontier_BattleTowerLobby_EventScript_002202F2::
	setvar 0x8005, 0x2
	return

BattleFrontier_BattleTowerLobby_EventScript_002202F8::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_00220306::
	setvar 0x8004, 0x9
	message 0x08247C79
	waitmessage
	setvar 0x8005, 0x0
	special TryBattleLinkup
	waitstate
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203F0
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x08246FBE
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220368
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220392
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x08246FB1
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203A7
	end

BattleFrontier_BattleTowerLobby_EventScript_00220368::
	special CloseLink
	compare_var_to_value 0x8005, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220380
	loadword 0x0, 0x08247D84
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_00220380::
	loadword 0x0, 0x0822176C
	callstd 0x4
	loadword 0x0, 0x082217DA
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_00220392::
	loadword 0x0, 0x0822171D
	callstd 0x4
	special CloseLink
	loadword 0x0, 0x08247DAF
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_002203A7::
	special CloseLink
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203D5
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203DE
	compare_var_to_value 0x8005, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203E7
	loadword 0x0, 0x082217DA
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_002203D5::
	loadword 0x0, 0x0822176C
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002203DE::
	loadword 0x0, 0x08221742
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002203E7::
	loadword 0x0, 0x08221755
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002203F0::
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	message 0x08221821
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	special sub_080A0194
	waitstate
	playse 0x37
	waitse
	special TrySetBattleTowerLinkType
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0022041B::
	loadword 0x0, 0x08221540
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FDC7
	end

BattleFrontier_BattleTowerLobby_EventScript_00220429::
	setvar 0x8004, 0x14
	goto BattleFrontier_BattleTowerLobby_EventScript_00220434
	end

BattleFrontier_BattleTowerLobby_EventScript_00220434::
	message 0x082485D7
	waitmessage
	multichoice 0x10, 0x6, 0x51, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204A4
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220471
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	end

BattleFrontier_BattleTowerLobby_EventScript_00220471::
	call 0x0824780F
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204D7
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220434
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220471
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203A7
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_002204A4::
	call 0x08247814
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204D7
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220434
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204A4
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203A7
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_002204D7::
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	message 0x08221821
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	special sub_080A0194
	waitstate
	playse 0x37
	waitse
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_002204FF::
	lockall
	loadword 0x0, 0x082218B8
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022050E::
	message 0x082218CD
	waitmessage
	multichoice 0x11, 0x2, 0x61, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220561
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022056F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022057D
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022058B
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220599
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220599
	end

BattleFrontier_BattleTowerLobby_EventScript_00220561::
	loadword 0x0, 0x082218DD
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022056F::
	loadword 0x0, 0x0822197A
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022057D::
	loadword 0x0, 0x082219CB
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022058B::
	loadword 0x0, 0x08221A3E
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_00220599::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x22059b, 0x18
	.globl gJPText_002205B3
gJPText_002205B3: @ 0x082205B3
	.string "おきゃくさま！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたね？\p"
	.string "もうしわけ　ありませんが　そのばあい\n"
	.string "ちょうせんは　むこうと　なります$"

	.globl gJPText_00220604
gJPText_00220604: @ 0x08220604
	.string "おめでとう　ございます！\n"
	.string "みごと　7にんぬき　されましたね！\p"
	.string "$"

	.incbin "baserom_jp.gba", 0x220624, 0x27
	.globl gJPText_0022064B
gJPText_0022064B: @ 0x0822064B
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "{B_COPY_VAR_1}を　もらった！$"

	.incbin "baserom_jp.gba", 0x220659, 0x28
	.globl gJPText_00220681
gJPText_00220681: @ 0x08220681
	.string "おつかれさまでした！\p"
	.string "$"

	.globl gJPText_0022068D
gJPText_0022068D: @ 0x0822068D
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちください$"

	.globl gJPText_002206A8
gJPText_002206A8: @ 0x082206A8
	.string "おまちしておりました！\p"
	.string "$"

	.globl gJPText_002206B5
gJPText_002206B5: @ 0x082206B5
	.string "バトルルームに　ごあんないする　まえに\n"
	.string "レポートを　かきますので　おまちください$"

	.globl gJPText_002206DE
gJPText_002206DE: @ 0x082206DE
	.string "いよいよ　つぎは　50にんめの\n"
	.string "トレーナー　ですね！\p"
	.string "これからは　7にんを　かちぬく　たびに\n"
	.string "あなたの　ポケモンに　きねんリボンが\l"
	.string "おくられますので　がんばって　くださいね！$"

	.globl gJPText_00220736
gJPText_00220736: @ 0x08220736
	.string "つよい　トレーナー　7にんを\n"
	.string "かちぬいた　きねんの　リボンを　どうぞ！\p"
	.string "{MUS_RG_VS_TRAINER}は　リボンを　もらった！$"

	.globl gJPText_00220769
gJPText_00220769: @ 0x08220769
	.string "{MUS_RG_VS_TRAINER}は　ポケモンに\n"
	.string "リボンを　つけて　あげた！$"

	.incbin "baserom_jp.gba", 0x220781, 0x21f
	.globl gJPText_002209A0
gJPText_002209A0: @ 0x082209A0
	.string "またの　ちょうせんを\n"
	.string "おまちして　おります！$"

	.incbin "baserom_jp.gba", 0x2209b7, 0x67
	.globl gJPText_00220A1E
gJPText_00220A1E: @ 0x08220A1E
	.string "それでは　{B_COPY_VAR_1}　バトルルームに\n"
	.string "ごあんない　いたします！$"

	.globl gJPText_00220A3B
gJPText_00220A3B: @ 0x08220A3B
	.string "バトルタワーで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　しますか？$"

	.incbin "baserom_jp.gba", 0x220a68, 0xdde
	.globl gJPText_00221846
gJPText_00221846: @ 0x08221846
	.string "おめでとう　ございます！\n"
	.string "タワータイクーンを　たおし\l"
	.string "みごと　7にんぬき　されましたね！$"

	.globl gJPText_00221873
gJPText_00221873: @ 0x08221873
	.string "おきゃくさまの\n"
	.string "かぎりない　さいのうを　たたえ\l"
	.string "バトルポイントを　しんてい　します！$"

	.globl gJPText_0022189E
gJPText_0022189E: @ 0x0822189E
	.string "{MUS_RG_VS_TRAINER}は　バトルポイントを\n"
	.string "{B_COPY_VAR_1}　BP　てにいれた！$"

	.incbin "baserom_jp.gba", 0x2218b8, 0x21c
