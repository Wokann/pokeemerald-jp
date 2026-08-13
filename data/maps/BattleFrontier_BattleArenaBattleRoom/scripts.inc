@ BattleFrontier_BattleArenaBattleRoom scripts (JP map g26 m30 @ 0x08230137)

BattleFrontier_BattleArenaBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleArenaBattleRoom_EventScript_00230150
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaBattleRoom_MapScriptTable_00230182
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaBattleRoom_MapScriptTable_002308B7
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleArenaBattleRoom_EventScript_0023014C
	.byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_0023014C::
	special sub_081399F4
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_00230150::
	setvar 0x8004, 0x5
	special CallFrontierUtilFunc
	call BattleFrontier_BattleArenaBattleRoom_EventScript_0023015E
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_0023015E::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230176
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023017C
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_00230176::
	setvar 0x4011, 0x64
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_0023017C::
	setvar 0x4011, 0x69
	return

BattleFrontier_BattleArenaBattleRoom_MapScriptTable_00230182::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleArenaBattleRoom_EventScript_0023018C
	.2byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_0023018C::
	lockall
	showobject_at 0x8, 0x1A1E
	applymovement 0x8, 0x0823088D
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002301DE
	applymovement 0x5, 0x082308B3
	applymovement 0x8, 0x08230896
	setvar 0x4002, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_002301DE::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x7
	applymovement 0x7, 0x0823089A
	waitmovement 0x0
	applymovement 0x9, 0x082308AD
	playse 0xB9
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_002308E8
	callstd 0x4
	closemessage
	applymovement 0x8, 0x08230890
	waitmovement 0x0
	applymovement 0x9, 0x082308AD
	playse 0xB9
	waitse
	waitmovement 0x0
	setvar 0x8004, 0x6
	special CallBattleArenaFunction
	loadword 0x0, gJPText_002308FF
	callstd 0x4
	closemessage
	applymovement 0x7, 0x0823089D
	waitmovement 0x0
	applymovement 0x9, 0x082308AD
	playse 0xB9
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_00230916
	callstd 0x4
	closemessage
	applymovement 0x8, 0x08230890
	applymovement 0x7, 0x0823089D
	waitmovement 0x0
	setvar 0x8004, 0x5
	special CallBattlePalaceFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_0023081C
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002302E0

BattleFrontier_BattleArenaBattleRoom_EventScript_0023028B::
	applymovement 0x9, 0x082308AD
	applymovement 0x1, 0x082308AD
	applymovement 0x2, 0x082308AD
	applymovement 0x3, 0x082308B0
	applymovement 0x4, 0x082308B0
	playse 0xC5
	waitse
	waitmovement 0x0
	setvar 0x8004, 0x6
	special CallBattleArenaFunction
	loadword 0x0, gJPText_00230944
	callstd 0x4

BattleFrontier_BattleArenaBattleRoom_EventScript_002302C5::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	warp 0x1A1C, 0xFF, 0x7, 0x8
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_002302E0::
	call BattleFrontier_BattleArenaBattleRoom_EventScript_00230854
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230502
	applymovement 0x8, 0x08230892
	applymovement 0x7, 0x082308A5
	waitmovement 0x0
	removeobject 0x7
	applymovement 0x5, 0x082308B3
	applymovement 0x8, 0x08230896
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

BattleFrontier_BattleArenaBattleRoom_EventScript_00230360::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleArenaBattleRoom_EventScript_0023056C
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230520
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230527
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023052E
	compare_var_to_value 0x800D, 0x4
	call_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230535
	compare_var_to_value 0x800D, 0x5
	call_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023053C
	compare_var_to_value 0x800D, 0x6
	call_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230543
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230418
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002304EA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023044E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023048A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002304B8
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_00230418::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002304EA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023048A
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002304B8
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_0023044E::
	message gJPText_00230A9B
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230480
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_00230480::
	call 0x0821F8F5
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_0023048A::
	loadword 0x0, gJPText_00230A44
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023054A
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_002304B8::
	message gJPText_00230A5E
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002302C5
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230360

BattleFrontier_BattleArenaBattleRoom_EventScript_002304EA::
	closemessage
	applymovement 0x8, 0x08230898
	applymovement 0x5, 0x08230898
	waitmovement 0x0
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_002301DE

	.incbin "baserom_jp.gba", 0x230501, 0x1
BattleFrontier_BattleArenaBattleRoom_EventScript_00230502::
	delay 0x3C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	warp 0x1A1C, 0xFF, 0x7, 0x8
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_00230520::
	message gJPText_00230972
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_00230527::
	message gJPText_00230995
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_0023052E::
	message gJPText_002309B8
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_00230535::
	message gJPText_002309DB
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_0023053C::
	message gJPText_002309FE
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_00230543::
	message gJPText_00230A21
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_0023054A::
	message gJPText_00230A7F
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x2
	special CallBattleArenaFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_0023056C::
	compare_var_to_value 0x4002, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230584
	loadword 0x0, gJPText_00230ABD
	callstd 0x4
	setvar 0x4002, 0x1

BattleFrontier_BattleArenaBattleRoom_EventScript_00230584::
	message gJPText_00230B18
	waitmessage
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002305DB
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230611
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023044E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023048A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002304B8
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230584

BattleFrontier_BattleArenaBattleRoom_EventScript_002305DB::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230611
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023048A
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002304B8
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230584

BattleFrontier_BattleArenaBattleRoom_EventScript_00230611::
	call 0x08222264
	applymovement 0x8, 0x08230898
	applymovement 0x5, 0x08230898
	waitmovement 0x0
	applymovement 0x9, 0x082308AD
	playse 0xB9
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_002308E8
	callstd 0x4
	closemessage
	applymovement 0x8, 0x0823088F
	waitmovement 0x0
	applymovement 0x9, 0x082308AD
	playse 0xB9
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_00230B3E
	callstd 0x4
	closemessage
	addobject 0x7
	applymovement 0x7, 0x0823089F
	waitmovement 0x0
	applymovement 0x7, 0x0823089D
	waitmovement 0x0
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230755
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002306EF
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002307A8
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleArenaBattleRoom_EventScript_002306EF
	loadword 0x0, gJPText_00230B61
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	applymovement 0x7, 0x082308DB
	waitmovement 0x0
	loadword 0x0, gJPText_00230B88
	callstd 0x4
	closemessage
	applymovement 0x7, 0x082308E5
	waitmovement 0x0
	loadword 0x0, gJPText_00230B9B
	callstd 0x4

BattleFrontier_BattleArenaBattleRoom_EventScript_002306EF::
	loadword 0x0, gJPText_00230C03
	callstd 0x4
	call BattleFrontier_BattleArenaBattleRoom_EventScript_0023080E
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_0023070C
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_0023028B

BattleFrontier_BattleArenaBattleRoom_EventScript_0023070C::
	call BattleFrontier_BattleArenaBattleRoom_EventScript_00230854
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleArenaBattleRoom_EventScript_00230502
	applymovement 0x7, 0x0823089C
	waitmovement 0x0
	loadword 0x0, gJPText_00230C1C
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_00230C53
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00230C6D
	callstd 0x4
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_00230502

BattleFrontier_BattleArenaBattleRoom_EventScript_00230755::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleArenaBattleRoom_EventScript_002307A8
	loadword 0x0, gJPText_00230C8E
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	applymovement 0x7, 0x082308DB
	waitmovement 0x0
	loadword 0x0, gJPText_00230CF3
	callstd 0x4
	closemessage
	applymovement 0x7, 0x082308E5
	waitmovement 0x0
	loadword 0x0, gJPText_00230D08
	callstd 0x4

BattleFrontier_BattleArenaBattleRoom_EventScript_002307A8::
	loadword 0x0, gJPText_00230D2A
	callstd 0x4
	call BattleFrontier_BattleArenaBattleRoom_EventScript_0023080E
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_002307C5
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_0023028B

BattleFrontier_BattleArenaBattleRoom_EventScript_002307C5::
	call BattleFrontier_BattleArenaBattleRoom_EventScript_00230854
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaBattleRoom_EventScript_00230502
	applymovement 0x7, 0x0823089C
	waitmovement 0x0
	loadword 0x0, gJPText_00230D43
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_00230D6B
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00230D81
	callstd 0x4
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_00230502

BattleFrontier_BattleArenaBattleRoom_EventScript_0023080E::
	loadword 0x0, gJPText_00230916
	callstd 0x4
	call BattleFrontier_BattleArenaBattleRoom_EventScript_0023081C
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_0023081C::
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x5
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	setvar 0x8004, 0x12
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x15
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_00230854::
	applymovement 0x9, 0x082308AD
	applymovement 0x1, 0x082308AD
	applymovement 0x2, 0x082308AD
	applymovement 0x3, 0x082308B0
	applymovement 0x4, 0x082308B0
	playse 0x14
	waitse
	waitmovement 0x0
	loadword 0x0, gJPText_00230930
	callstd 0x4
	closemessage
	call 0x08221FB3
	return

	.incbin "baserom_jp.gba", 0x23088d, 0x2a
BattleFrontier_BattleArenaBattleRoom_MapScriptTable_002308B7::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleArenaBattleRoom_EventScript_002308C1
	.2byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_002308C1::
	hideobject_at 0x8, 0x1A1E
	removeobject 0x7
	call 0x08228868
	applymovement 0xFF, 0x082292FF
	setvar 0x4001, 0x1
	end

	.incbin "baserom_jp.gba", 0x2308db, 0xd
	.globl gJPText_002308E8
gJPText_002308E8: @ 0x082308E8
	.string "しんぱん“トレーナー　{MUS_RG_VS_TRAINER}！\n"
	.string "まえへーーー！$"

	.globl gJPText_002308FF
gJPText_002308FF: @ 0x082308FF
	.string "しんぱん“トレーナー　{B_COPY_VAR_1}！\n"
	.string "まえへーーー！$"

	.globl gJPText_00230916
gJPText_00230916: @ 0x08230916
	.string "しんぱん“かちぬきチームバトル！\n"
	.string "はじめーーー！！$"

	.globl gJPText_00230930
gJPText_00230930: @ 0x08230930
	.string "しんぱん“しょうしゃーーー！\n"
	.string "{MUS_RG_VS_TRAINER}！！$"

	.globl gJPText_00230944
gJPText_00230944: @ 0x08230944
	.string "しんぱん“しょうしゃーーー！\n"
	.string "{B_COPY_VAR_1}！！$"

	.globl gJPText_00230958
gJPText_00230958: @ 0x08230958
	.string "ポケモンの　たいりょくを\n"
	.string "かいふく　いたしますぞ！$"

	.globl gJPText_00230972
gJPText_00230972: @ 0x08230972
	.string "つぎは　2にんめの　あいてですぞ！\n"
	.string "じゅんびは　よろしい　ですかな？$"

	.globl gJPText_00230995
gJPText_00230995: @ 0x08230995
	.string "つぎは　3にんめの　あいてですぞ！\n"
	.string "じゅんびは　よろしい　ですかな？$"

	.globl gJPText_002309B8
gJPText_002309B8: @ 0x082309B8
	.string "つぎは　4にんめの　あいてですぞ！\n"
	.string "じゅんびは　よろしい　ですかな？$"

	.globl gJPText_002309DB
gJPText_002309DB: @ 0x082309DB
	.string "つぎは　5にんめの　あいてですぞ！\n"
	.string "じゅんびは　よろしい　ですかな？$"

	.globl gJPText_002309FE
gJPText_002309FE: @ 0x082309FE
	.string "つぎは　6にんめの　あいてですぞ！\n"
	.string "じゅんびは　よろしい　ですかな？$"

	.globl gJPText_00230A21
gJPText_00230A21: @ 0x08230A21
	.string "つぎは　7にんめの　あいてですぞ！\n"
	.string "じゅんびは　よろしい　ですかな？$"

	.globl gJPText_00230A44
gJPText_00230A44: @ 0x08230A44
	.string "レポートを　かいて\n"
	.string "しゅうりょう　なされますかな？$"

	.globl gJPText_00230A5E
gJPText_00230A5E: @ 0x08230A5E
	.string "かちぬきチームバトルの　ちょうせんを\n"
	.string "ちゅうし　なされますかな？$"

	.globl gJPText_00230A7F
gJPText_00230A7F: @ 0x08230A7F
	.string "レポートを　かいております！\n"
	.string "しばし　おまちくだされ！$"

	.globl gJPText_00230A9B
gJPText_00230A9B: @ 0x08230A9B
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　されますかな？$"

	.globl gJPText_00230ABD
gJPText_00230ABD: @ 0x08230ABD
	.string "おきゃくじん！\p"
	.string "あなたの　じつりょくは\n"
	.string "じつに　すさまじいで　ございますな！\p"
	.string "そこで　ここらで　ひとつ\n"
	.string "われらが　たいしょう　アリーナキャプテンと\l"
	.string "おてあわせ　いただき　ましょう！$"

	.globl gJPText_00230B18
gJPText_00230B18: @ 0x08230B18
	.string "アリーナキャプテンとの　しょうぶ！\n"
	.string "かくごの　ほうは　よろしい　ですかな？$"

	.globl gJPText_00230B3E
gJPText_00230B3E: @ 0x08230B3E
	.string "しんぱん“アリーナキャプテン！　コゴミさま！\n"
	.string "ごにゅうじょうーーー！$"

	.globl gJPText_00230B61
gJPText_00230B61: @ 0x08230B61
	.string "コゴミ“ウィーッス！　よろしくー！！\p"
	.string "⋯⋯　って　あなたが　ちょうせんしゃ？$"

	.globl gJPText_00230B88
gJPText_00230B88: @ 0x08230B88
	.string "ふーん⋯⋯　へーえ⋯⋯　へえぇぇ⋯⋯$"

	.globl gJPText_00230B9B
gJPText_00230B9B: @ 0x08230B9B
	.string "なんて　いうかー　しょうじき　いって\n"
	.string "かなり　よわっちい　かんじ　なんだけどー\l"
	.string "アタシと　たたかっても\l"
	.string "だいじょうぶ　なのかなー？\p"
	.string "ぅうーん⋯⋯\p"
	.string "まあ　いいかっ！\n"
	.string "まずは　かるーく　おてなみ　はいけんねっ！$"

	.globl gJPText_00230C03
gJPText_00230C03: @ 0x08230C03
	.string "さあっ！\n"
	.string "アタシの　とうしに　ひを　つけてねっ！$"

	.globl gJPText_00230C1C
gJPText_00230C1C: @ 0x08230C1C
	.string "コゴミ“やだ　ちょっとー！\n"
	.string "あなた　ぜんぜん　つよい　じゃんー！\l"
	.string "きにいった！　フロンティアパス　かしてっ！$"

	.globl gJPText_00230C53
gJPText_00230C53: @ 0x08230C53
	.string "フロンティアパスに\n"
	.string "ガッツシンボルが　きざまれた！$"

	.globl gJPText_00230C6D
gJPText_00230C6D: @ 0x08230C6D
	.string "ぅうーん！\p"
	.string "つぎに　あえるときが\n"
	.string "たのしみに　なって　きたなー！$"

	.globl gJPText_00230C8E
gJPText_00230C8E: @ 0x08230C8E
	.string "コゴミ“ウィーッス！　ごぶさたー！\n"
	.string "やーっと　ここまで　かちぬいて　きたね！\p"
	.string "おそいから　しんぱい　しちゃったよーっ！\n"
	.string "あなたと　あえるの　もの　すっごーくっ！\l"
	.string "たのしみに　してたん　だからねーっ！！$"

	.globl gJPText_00230CF3
gJPText_00230CF3: @ 0x08230CF3
	.string "⋯⋯　⋯⋯　⋯⋯　⋯⋯　だから　いーい？$"

	.globl gJPText_00230D08
gJPText_00230D08: @ 0x08230D08
	.string "はんぱな　たたかいじゃ　ゆるさないっ！！\n"
	.string "かくご　しといてねっ！！$"

	.globl gJPText_00230D2A
gJPText_00230D2A: @ 0x08230D2A
	.string "ほらっ　しんぱん！\n"
	.string "さっさと　はじめなさいっ！！$"

	.globl gJPText_00230D43
gJPText_00230D43: @ 0x08230D43
	.string "コゴミ“あーーーっ！　もーーーっ！！\n"
	.string "さっさと　フロンティアパス　かしてよっ！$"

	.globl gJPText_00230D6B
gJPText_00230D6B: @ 0x08230D6B
	.string "ガッツシンボルが\n"
	.string "きんいろに　かがやいた！$"

	.globl gJPText_00230D81
gJPText_00230D81: @ 0x08230D81
	.string "むきーっ！！　くやしーーーっ！！\p"
	.string "こんど　たたかう　ことが　あったら\n"
	.string "ぜーったい　まけない　からっ！　バイバイっ！$"

