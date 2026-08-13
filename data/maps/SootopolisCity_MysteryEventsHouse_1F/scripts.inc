@ SootopolisCity_MysteryEventsHouse_1F scripts (JP map g15 m13 @ 0x0820FD60)

SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FD6B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_MapScriptTable_0020FDAA
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FD6B::
	setvar 0x8004, 0x10
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FD8A
	compare_var_to_value 0x40C0, 0x0
	call_if 0x5, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FD9E
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FD8A::
	setvar 0x4001, 0x1
	setobjectxyperm 0x1, 0x3, 0x2
	setobjectmovementtype 0x1, 0x8
	setmaplayoutindex 0x1B9
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FD9E::
	setobjectxyperm 0x1, 0x2, 0x2
	setobjectmovementtype 0x1, 0xA
	return

SootopolisCity_MysteryEventsHouse_1F_MapScriptTable_0020FDAA::
	map_script_2 0x40C0, 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FDC4
	map_script_2 0x40C0, 0x2, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FDC4
	map_script_2 0x40C0, 0x3, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FDC4
	.2byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FDC4::
	lockall
	applymovement 0xFF, 0x0820FE2C
	waitmovement 0x0
	applymovement 0x1, 0x0820FE2E
	waitmovement 0x0
	moveobjectoffscreen 0x1
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	compare_var_to_value 0x40C0, 0x1
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE11
	compare_var_to_value 0x40C0, 0x2
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE1A
	compare_var_to_value 0x40C0, 0x3
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE23
	special LoadPlayerParty
	setvar 0x40C0, 0x0
	releaseall
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE11::
	loadword 0x0, gJPText_002100DA
	callstd 0x4
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE1A::
	loadword 0x0, gJPText_00210105
	callstd 0x4
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE23::
	loadword 0x0, gJPText_002100AA
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x20fe2c, 0x5
SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE31::
	lock
	faceplayer
	setvar 0x8004, 0x10
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE5B
	compare_var_to_value 0x4001, 0x1
	goto_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE65
	loadword 0x0, 0x0820FF53
	callstd 0x4
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE5B::
	loadword 0x0, 0x0820FF53
	callstd 0x4
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE65::
	special SavePlayerParty
	special BufferEReaderTrainerName
	loadword 0x0, 0x0820FFC6
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEEF
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEFC
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEEF
	loadword 0x0, 0x0821005E
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEEF
	special LoadPlayerParty
	call 0x082423E9
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEEF
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	loadword 0x0, 0x08210081
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FF0B
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FF1D
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FF2F
	warp 0xF0E, 0xFF, 0x3, 0x1
	waitstate
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEEF::
	special LoadPlayerParty
	loadword 0x0, 0x0820FFFA
	callstd 0x4
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FEFC::
	loadword 0x0, 0x0821001A
	callstd 0x4
	fadescreen 0x1
	special ChooseHalfPartyForBattle
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FF0B::
	applymovement 0x800F, 0x0820FF4D
	applymovement 0xFF, 0x0820FF41
	waitmovement 0x0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FF1D::
	applymovement 0x800F, 0x0820FF50
	applymovement 0xFF, 0x0820FF45
	waitmovement 0x0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FF2F::
	applymovement 0x800F, 0x0820FF4D
	applymovement 0xFF, 0x0820FF49
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x20ff41, 0x157
	.globl gJPText_00210098
gJPText_00210098: @ 0x08210098
	.string "しょうぶは　ひきわけに　おわった！$"

	.globl gJPText_002100AA
gJPText_002100AA: @ 0x082100AA
	.string "ひきわけ　じゃったか！\p"
	.string "おたがい　いっぽも　ゆずらぬ\n"
	.string "すばらしい　しょうぶ　じゃったぞ！$"

	.incbin "baserom_jp.gba", 0x2100d7, 0x3
	.globl gJPText_002100DA
gJPText_002100DA: @ 0x082100DA
	.string "みごと　じゃったぞ！\p"
	.string "まるで　わしの　わかい　ころを\n"
	.string "みている　ようじゃわい！$"

	.incbin "baserom_jp.gba", 0x210102, 0x3
	.globl gJPText_00210105
gJPText_00210105: @ 0x08210105
	.string "ざんねん　じゃったのう\n"
	.string "じゃが　よい　しょうぶ　じゃったぞ！\l"
	.string "つぎこそは　かてると　よいのう$"

