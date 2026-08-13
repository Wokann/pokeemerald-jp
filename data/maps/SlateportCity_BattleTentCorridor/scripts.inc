@ SlateportCity_BattleTentCorridor scripts (JP map g9 m3 @ 0x081FB594)

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_MapScriptTable_001FB5C9
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_MapScriptTable_001FB59F
	.byte 0

SlateportCity_BattleTentCorridor_MapScriptTable_001FB59F::
	map_script_2 0x4001, 0x0, SlateportCity_BattleTentCorridor_EventScript_001FB5A9
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_001FB5A9::
	setvar 0x4001, 0x1
	compare_var_to_value 0x8006, 0x1
	goto_if 0x5, SlateportCity_BattleTentCorridor_EventScript_001FB5C4
	setobjectxy 0x1, 0x2, 0x2
	turnobject 0x1, 0x1

SlateportCity_BattleTentCorridor_EventScript_001FB5C4::
	turnobject 0xFF, 0x2
	end

SlateportCity_BattleTentCorridor_MapScriptTable_001FB5C9::
	map_script_2 0x4000, 0x0, SlateportCity_BattleTentCorridor_EventScript_001FB5D3
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_001FB5D3::
	compare_var_to_value 0x8006, 0x1
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB65C
	setvar 0x4000, 0x1
	applymovement 0x1, 0x081FB7D0
	applymovement 0xFF, 0x081FB7C7
	waitmovement 0x0
	compare_var_to_value 0x8006, 0x2
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB7B2
	setvar 0x8004, 0x9
	special CallSlateportTentFunction
	setvar 0x8004, 0x8
	special CallSlateportTentFunction
	loadword 0x0, gJPText_002323B3
	callstd 0x4
	fadescreen 0x1
	setvar 0x8004, 0x6
	special CallSlateportTentFunction
	waitstate

SlateportCity_BattleTentCorridor_EventScript_001FB622::
	loadword 0x0, gJPText_0023287D
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	opendoor 0x2, 0x1
	waitmoncry
	applymovement 0x1, 0x081FB7D6
	applymovement 0xFF, 0x081FB7CC
	waitmovement 0x0
	closedoor 0x2, 0x1
	waitmoncry
	warp 0x904, 0xFF, 0x4, 0x4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_001FB65C::
	setvar 0x8004, 0x9
	special CallBattleFactoryFunction
	setvar 0x8004, 0x10
	special CallBattleFactoryFunction
	loadword 0x0, gJPText_002323F8
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty

SlateportCity_BattleTentCorridor_EventScript_001FB67B::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB782
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB789
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB729
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB6C9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB6F7

SlateportCity_BattleTentCorridor_EventScript_001FB6C9::
	loadword 0x0, gJPText_002324CA
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB67B
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB790
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB67B

SlateportCity_BattleTentCorridor_EventScript_001FB6F7::
	message gJPText_002324E3
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB67B
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081FBD14
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB67B

SlateportCity_BattleTentCorridor_EventScript_001FB729::
	setvar 0x8004, 0x8
	special CallSlateportTentFunction
	loadword 0x0, gJPText_00232839
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB622
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB75F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB622

SlateportCity_BattleTentCorridor_EventScript_001FB75F::
	fadescreen 0x1
	setvar 0x8004, 0x7
	special CallSlateportTentFunction
	waitstate
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SlateportCity_BattleTentCorridor_EventScript_001FB622
	loadword 0x0, gJPText_0023285F
	callstd 0x4
	goto SlateportCity_BattleTentCorridor_EventScript_001FB622

SlateportCity_BattleTentCorridor_EventScript_001FB782::
	message gJPText_00232415
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_001FB789::
	message gJPText_00232433
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_001FB790::
	message gJPText_0023288B
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x2
	special CallSlateportTentFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

SlateportCity_BattleTentCorridor_EventScript_001FB7B2::
	special SavePlayerParty
	setvar 0x8004, 0xA
	setvar 0x8005, 0x0
	special CallBattleFactoryFunction
	goto SlateportCity_BattleTentCorridor_EventScript_001FB67B

	.incbin "baserom_jp.gba", 0x1fb7c7, 0x492
