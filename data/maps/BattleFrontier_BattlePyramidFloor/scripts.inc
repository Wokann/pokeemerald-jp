@ BattleFrontier_BattlePyramidFloor scripts (JP map g26 m26 @ 0x0822D4FC)

BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_EventScript_0022D56B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_MapScriptTable_0022D50C
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_EventScript_0022D693
	.byte 0

BattleFrontier_BattlePyramidFloor_MapScriptTable_0022D50C::
	map_script_2 0x400D, 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D526
	map_script_2 0x400E, 0x0, BattleFrontier_BattlePyramidFloor_EventScript_0022D561
	map_script_2 0x400F, 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D558
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_0022D526::
	lockall
	setvar 0x8004, 0xD
	setvar 0x8005, 0x4
	setvar 0x8006, 0x1
	setvar 0x8007, 0x37
	setvar 0x800D, 0x0

BattleFrontier_BattlePyramidFloor_EventScript_0022D540::
	special CallBattlePyramidFunction
	delay 0x2
	compare_var_to_value 0x800D, 0x2
	goto_if 0x5, BattleFrontier_BattlePyramidFloor_EventScript_0022D540
	setvar 0x400D, 0x0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D558::
	special ShowMapNamePopup
	setvar 0x400F, 0x0
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D561::
	playbgm 0x1CD, 0x0
	setvar 0x400E, 0x1
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D56B::
	setvar 0x8004, 0xF
	special CallBattlePyramidFunction
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x4000
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D656
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D62F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D656
	setvar 0x8004, 0x1
	setvar 0x8005, 0x5
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D602
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D602
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D602
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D60B
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D60B
	compare_var_to_value 0x800D, 0x9
	goto_if 0x1, BattleFrontier_BattlePyramidFloor_EventScript_0022D60B
	setvar 0x8004, 0xE
	setvar 0x8005, 0x8
	special CallFrontierUtilFunc
	setvar 0x400D, 0x1

BattleFrontier_BattlePyramidFloor_EventScript_0022D602::
	setvar 0x8004, 0x11
	special CallBattlePyramidFunction
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D60B::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	setvar 0x8006, 0xFF
	special CallBattlePyramidFunction

BattleFrontier_BattlePyramidFloor_EventScript_0022D62F::
	setvar 0x8004, 0xD
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallBattlePyramidFunction
	setvar 0x8004, 0xE
	special CallBattlePyramidFunction
	special HealPlayerParty
	warpsilent 0x1A19, 0xFF, 0x7, 0xD
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D656::
	setvar 0x8004, 0x3
	setvar 0x8005, 0x1
	special CallBattlePyramidFunction
	special SavePlayerParty
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x9
	special CallBattlePyramidFunction
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	setvar 0x400F, 0x1
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D693::
	call BattleFrontier_BattlePyramidFloor_EventScript_0022D69E
	setvar 0x400F, 0x1
	end

BattleFrontier_BattlePyramidFloor_EventScript_0022D69E::
	setvar 0x8004, 0xD
	setvar 0x8005, 0x20
	setvar 0x8006, 0x0
	special CallBattlePyramidFunction
	return

gUnknown_822D6B1:: @ 0x0822D6B1
	.incbin "baserom_jp.gba", 0x22d6b1, 0x12f1
