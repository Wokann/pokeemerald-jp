@ SootopolisCity_MysteryEventsHouse_B1F scripts (JP map g15 m14 @ 0x08210134)

SootopolisCity_MysteryEventsHouse_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_B1F_EventScript_0021013F
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_B1F_MapScriptTable_00210143
	.byte 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_0021013F::
	special SetEReaderTrainerGfxId
	end

SootopolisCity_MysteryEventsHouse_B1F_MapScriptTable_00210143::
	map_script_2 0x4001, 0x0, SootopolisCity_MysteryEventsHouse_B1F_EventScript_0021014D
	.2byte 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_0021014D::
	lockall
	applymovement 0xFF, 0x082101D8
	waitmovement 0x0
	special CopyEReaderTrainerGreeting
	loadword 0x0, 0x2021C7C
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, SootopolisCity_MysteryEventsHouse_B1F_EventScript_002101B4
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, SootopolisCity_MysteryEventsHouse_B1F_EventScript_002101C2
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, SootopolisCity_MysteryEventsHouse_B1F_EventScript_002101CD
	closemessage
	special HealPlayerParty
	applymovement 0xFF, 0x082101DE
	waitmovement 0x0
	special LoadPlayerParty
	setvar 0x4001, 0x1
	warp 0xF0D, 0xFF, 0x3, 0x1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_002101B4::
	setvar 0x40C0, 0x3
	loadword 0x0, gJPText_00210098
	callstd 0x4
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_002101C2::
	setvar 0x40C0, 0x1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_002101CD::
	setvar 0x40C0, 0x2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

	.incbin "baserom_jp.gba", 0x2101d8, 0xe
