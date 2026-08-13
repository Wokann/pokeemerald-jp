@ VerdanturfTown_BattleTentBattleRoom scripts (JP map g6 m2 @ 0x081F6CA5)

VerdanturfTown_BattleTentBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CB5
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentBattleRoom_MapScriptTable_001F6CDF
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentBattleRoom_MapScriptTable_001F6EE2
	.byte 0

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CB5::
	call VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CBB
	end

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CBB::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CD3
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CD9
	return

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CD3::
	setvar 0x4011, 0x64
	return

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CD9::
	setvar 0x4011, 0x69
	return

VerdanturfTown_BattleTentBattleRoom_MapScriptTable_001F6CDF::
	map_script_2 0x4000, 0x0, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CE9
	.2byte 0

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CE9::
	showobject_at 0x1, 0x602
	applymovement 0x1, 0x081F6F16
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6DDD

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6D10::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x2
	applymovement 0x2, 0x081F6F1C
	waitmovement 0x0
	setvar 0x8004, 0x4
	special CallVerdanturfTentFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	call 0x0822B737
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6D69

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6D4B::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	special LoadPlayerParty
	warp 0x600, 0xFF, 0x6, 0x6
	waitstate

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6D69::
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
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6EA2
	applymovement 0x2, 0x081F6F22
	waitmovement 0x0
	removeobject 0x2
	applymovement 0x3, 0x0824362D
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_0022B83B
	callstd 0x4
	special LoadPlayerParty
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6DDD::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6F06
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6F0D
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6E8B
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6E2B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6E59

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6E2B::
	loadword 0x0, gJPText_0022B909
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6DDD
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6EC0
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6DDD

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6E59::
	message gJPText_0022B91F
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6DDD
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6D4B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6DDD

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6E8B::
	applymovement 0x3, 0x0824362B
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	closemessage
	goto VerdanturfTown_BattleTentBattleRoom_EventScript_001F6D10

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6EA2::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	special LoadPlayerParty
	warp 0x600, 0xFF, 0x6, 0x6
	waitstate

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6EC0::
	message gJPText_0022B931
	waitmessage
	setvar 0x8004, 0x5
	setvar 0x8005, 0x2
	special CallVerdanturfTentFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

VerdanturfTown_BattleTentBattleRoom_MapScriptTable_001F6EE2::
	map_script_2 0x4001, 0x0, VerdanturfTown_BattleTentBattleRoom_EventScript_001F6EEC
	.2byte 0

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6EEC::
	hideobject_at 0x1, 0x602
	call VerdanturfTown_BattleTentBattleRoom_EventScript_001F6CBB
	setvar 0x4001, 0x1
	applymovement 0xFF, 0x081F6F14
	removeobject 0x2
	end

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6F06::
	message gJPText_0022B855
	waitmessage
	return

VerdanturfTown_BattleTentBattleRoom_EventScript_001F6F0D::
	message gJPText_0022B873
	waitmessage
	return

	.incbin "baserom_jp.gba", 0x1f6f14, 0x10d
