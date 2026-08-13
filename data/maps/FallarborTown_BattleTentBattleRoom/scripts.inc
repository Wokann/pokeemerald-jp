@ FallarborTown_BattleTentBattleRoom scripts (JP map g5 m3 @ 0x081F591A)

FallarborTown_BattleTentBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_BattleTentBattleRoom_EventScript_001F592A
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentBattleRoom_MapScriptTable_001F595E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentBattleRoom_MapScriptTable_001F5C31
	.byte 0

FallarborTown_BattleTentBattleRoom_EventScript_001F592A::
	call FallarborTown_BattleTentBattleRoom_EventScript_001F5930
	end

FallarborTown_BattleTentBattleRoom_EventScript_001F5930::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5948
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5953
	return

FallarborTown_BattleTentBattleRoom_EventScript_001F5948::
	setvar 0x4011, 0x64
	setvar 0x4010, 0x64
	return

FallarborTown_BattleTentBattleRoom_EventScript_001F5953::
	setvar 0x4011, 0x69
	setvar 0x4010, 0x69
	return

FallarborTown_BattleTentBattleRoom_MapScriptTable_001F595E::
	map_script_2 0x4000, 0x0, FallarborTown_BattleTentBattleRoom_EventScript_001F5968
	.2byte 0

FallarborTown_BattleTentBattleRoom_EventScript_001F5968::
	lockall
	showobject_at 0x1, 0x503
	applymovement 0x1, 0x081F5C0E
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, FallarborTown_BattleTentBattleRoom_EventScript_001F5BF4

FallarborTown_BattleTentBattleRoom_EventScript_001F5990::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x3
	applymovement 0x3, 0x081F5C17
	waitmovement 0x0
	applymovement 0x2, 0x081F5C24
	playse 0xB9
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_00230916
	callstd 0x4
	setvar 0x8004, 0x4
	special CallVerdanturfTentFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	call 0x0823081C
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5A1D
	applymovement 0x2, 0x081F5C24
	playse 0xC5
	waitse
	waitmovement 0x0
	setvar 0x8004, 0x6
	special CallFallarborTentFunction
	loadword 0x0, gJPText_00230944
	callstd 0x4

FallarborTown_BattleTentBattleRoom_EventScript_001F59FF::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	special LoadPlayerParty
	warp 0x501, 0xFF, 0x6, 0x6
	waitstate

FallarborTown_BattleTentBattleRoom_EventScript_001F5A1D::
	applymovement 0x2, 0x081F5C24
	playse 0x14
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_00230930
	callstd 0x4
	closemessage

FallarborTown_BattleTentBattleRoom_EventScript_001F5A34::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5B74
	applymovement 0x3, 0x081F5C1F
	waitmovement 0x0
	removeobject 0x3
	applymovement 0x2, 0x081F5C27
	waitmovement 0x0
	applymovement 0x1, 0x081F5C15
	waitmovement 0x0
	loadword 0x0, gJPText_00230958
	callstd 0x4
	special LoadPlayerParty
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty

FallarborTown_BattleTentBattleRoom_EventScript_001F5AAB::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5BC4
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5BCB
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5B59
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5AF9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5B27

FallarborTown_BattleTentBattleRoom_EventScript_001F5AF9::
	loadword 0x0, gJPText_00230A44
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5AAB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5BD2
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5AAB

FallarborTown_BattleTentBattleRoom_EventScript_001F5B27::
	message gJPText_00230A5E
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5AAB
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F59FF
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5AAB

FallarborTown_BattleTentBattleRoom_EventScript_001F5B59::
	closemessage
	applymovement 0x2, 0x081F5C2C
	waitmovement 0x0
	applymovement 0x1, 0x081F5C13
	waitmovement 0x0
	goto FallarborTown_BattleTentBattleRoom_EventScript_001F5990

	.incbin "baserom_jp.gba", 0x1f5b73, 0x1
FallarborTown_BattleTentBattleRoom_EventScript_001F5B74::
	delay 0x3C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	special LoadPlayerParty
	warp 0x501, 0xFF, 0x6, 0x6
	waitstate
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallBattleArenaFunction
	compare_var_to_value 0x800D, 0x270F
	goto_if 0x1, FallarborTown_BattleTentBattleRoom_EventScript_001F5A34
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallBattleArenaFunction

FallarborTown_BattleTentBattleRoom_EventScript_001F5BC4::
	message gJPText_00230972
	waitmessage
	return

FallarborTown_BattleTentBattleRoom_EventScript_001F5BCB::
	message gJPText_00230995
	waitmessage
	return

FallarborTown_BattleTentBattleRoom_EventScript_001F5BD2::
	message gJPText_00230A7F
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x2
	special CallFallarborTentFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

FallarborTown_BattleTentBattleRoom_EventScript_001F5BF4::
	applymovement 0x2, 0x081F5C27
	waitmovement 0x0
	applymovement 0x1, 0x081F5C15
	waitmovement 0x0
	goto FallarborTown_BattleTentBattleRoom_EventScript_001F5AAB
	end

	.incbin "baserom_jp.gba", 0x1f5c0e, 0x23
FallarborTown_BattleTentBattleRoom_MapScriptTable_001F5C31::
	map_script_2 0x4001, 0x0, FallarborTown_BattleTentBattleRoom_EventScript_001F5C3B
	.2byte 0

FallarborTown_BattleTentBattleRoom_EventScript_001F5C3B::
	hideobject_at 0xFF, 0x503
	hideobject_at 0x1, 0x503
	removeobject 0x3
	setvar 0x4001, 0x1
	end

