@ BattleFrontier_BattlePalaceBattleRoom scripts (JP map g26 m24 @ 0x0822B155)

BattleFrontier_BattlePalaceBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B165
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_MapScriptTable_0022B1A1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_MapScriptTable_0022B76F
	.byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B165::
	setvar 0x8004, 0x5
	special CallFrontierUtilFunc
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B173
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B173::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B18B
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B196
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B18B::
	setvar 0x4011, 0x64
	setvar 0x4010, 0x64
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B196::
	setvar 0x4011, 0x69
	setvar 0x4010, 0x69
	return

BattleFrontier_BattlePalaceBattleRoom_MapScriptTable_0022B1A1::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B1AB
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B1AB::
	showobject_at 0x1, 0x1A18
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B1F5
	applymovement 0x1, 0x0822B7D6
	waitmovement 0x0
	applymovement 0x3, 0x0822B7E7
	setvar 0x4002, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B1F5::
	applymovement 0x1, 0x0822B7CD
	waitmovement 0x0

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B1FF::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x2
	applymovement 0x2, 0x0822B7DC
	waitmovement 0x0
	setvar 0x8004, 0x5
	special CallBattlePalaceFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B737
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B251

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B23A::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7F6

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B251::
	call 0x08221FB3
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
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B468
	applymovement 0x2, 0x0822B7E2
	waitmovement 0x0
	removeobject 0x2
	applymovement 0x1, 0x0822B7D4
	applymovement 0x3, 0x0822B7E7
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

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x400F, 0x800D
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B4A1
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7A1
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7A8
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7AF
	compare_var_to_value 0x800D, 0x4
	call_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7B6
	compare_var_to_value 0x800D, 0x5
	call_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7BD
	compare_var_to_value 0x800D, 0x6
	call_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7C4
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B382
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B454
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3B8
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3F4
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B422
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B382::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B454
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3F4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B422
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3B8::
	message gJPText_0022B94A
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3EA
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3EA::
	call 0x0821F8F5
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3F4::
	loadword 0x0, gJPText_0022B909
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B47F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B422::
	message gJPText_0022B91F
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B23A
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B2CA

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B454::
	applymovement 0x1, 0x0822B7D2
	applymovement 0x3, 0x0822B7D2
	closemessage
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B1FF

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B468::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7F6

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B47F::
	message gJPText_0022B931
	waitmessage
	setvar 0x8004, 0x7
	setvar 0x8005, 0x2
	special CallBattlePalaceFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B4A1::
	compare_var_to_value 0x4002, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B4B9
	loadword 0x0, gJPText_0022B969
	callstd 0x4
	setvar 0x4002, 0x1

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B4B9::
	message gJPText_0022B9A6
	waitmessage
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B510
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B546
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3B8
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3F4
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B422
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B4B9

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B510::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B546
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B3F4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B422
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B4B9

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B546::
	call 0x08222264
	loadword 0x0, gJPText_0022B9C3
	callstd 0x4
	closemessage
	applymovement 0x1, 0x0822B7D2
	applymovement 0x3, 0x0822B7D2
	setobjectxyperm 0x2, 0xF, 0x1
	addobject 0x2
	hideobject_at 0x2, 0x1A18
	setobjectxy 0x2, 0xD, 0x1
	setobjectxyperm 0x2, 0xD, 0x1
	applymovement 0x4, 0x0822B81A
	applymovement 0x5, 0x0822B822
	applymovement 0x2, 0x0822B82D
	waitmovement 0x0
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B67A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B5EA
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B6A7
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B5EA
	loadword 0x0, gJPText_0022B9E2
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B5EA::
	loadword 0x0, gJPText_0022BA71
	callstd 0x4
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B737
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B607
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B23A

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B607::
	setvar 0x8004, 0x6
	special CallBattlePalaceFunction
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B468
	loadword 0x0, gJPText_0022BA8A
	callstd 0x4
	applymovement 0x1, 0x0822B7D4
	applymovement 0x3, 0x0822B7E7
	loadword 0x0, gJPText_0022BAC7
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_0022BB02
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	applymovement 0x2, 0x08243639
	waitmovement 0x0
	applymovement 0x1, 0x0824362B
	applymovement 0x3, 0x0824362B
	waitmovement 0x0
	loadword 0x0, gJPText_0022BB1E
	callstd 0x4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B468

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B67A::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B6A7
	loadword 0x0, gJPText_0022BB57
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B6A7::
	loadword 0x0, gJPText_0022BBDF
	callstd 0x4
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B737
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B6C4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B23A

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B6C4::
	setvar 0x8004, 0x6
	special CallBattlePalaceFunction
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B468
	loadword 0x0, gJPText_0022BBEF
	callstd 0x4
	applymovement 0x1, 0x0822B7D4
	applymovement 0x3, 0x0822B7E7
	loadword 0x0, gJPText_0022BC48
	callstd 0x4
	playfanfare 0x1D2
	message gJPText_0022BC8E
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	applymovement 0x2, 0x08243639
	waitmovement 0x0
	applymovement 0x1, 0x0824362B
	applymovement 0x3, 0x0824362B
	waitmovement 0x0
	loadword 0x0, gJPText_0022BCA6
	callstd 0x4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B468

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B737::
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x4
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	setvar 0x8004, 0x12
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar 0x8004, 0x15
	special CallFrontierUtilFunc
	return

BattleFrontier_BattlePalaceBattleRoom_MapScriptTable_0022B76F::
	map_script_2 0x4001, 0x0, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B779
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B779::
	hideobject_at 0x1, 0x1A18
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B173
	setvar 0x4001, 0x1
	applymovement 0xFF, 0x0822B7CB
	removeobject 0x2
	applymovement 0x4, 0x0822B7CB
	applymovement 0x5, 0x0822B7CB
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7A1::
	message gJPText_0022B855
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7A8::
	message gJPText_0022B873
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7AF::
	message gJPText_0022B891
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7B6::
	message gJPText_0022B8AF
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7BD::
	message gJPText_0022B8CD
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7C4::
	message gJPText_0022B8EB
	waitmessage
	return

	.incbin "baserom_jp.gba", 0x22b7cb, 0x2b
BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B7F6::
	copyvar 0x800D, 0x40CE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B810
	warp 0x1A16, 0xFF, 0x5, 0x7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_0022B810::
	warp 0x1A16, 0xFF, 0x13, 0x7
	waitstate
	end

	.incbin "baserom_jp.gba", 0x22b81a, 0x21
	.globl gJPText_0022B83B
gJPText_0022B83B: @ 0x0822B83B
	.string "おみごと⋯⋯\n"
	.string "ポケモンを　かいふくして　やろう⋯⋯$"

	.globl gJPText_0022B855
gJPText_0022B855: @ 0x0822B855
	.string "つぎは　2にんめの　あいて　だが\n"
	.string "じゅんびは　よろしいか？$"

	.globl gJPText_0022B873
gJPText_0022B873: @ 0x0822B873
	.string "つぎは　3にんめの　あいて　だが\n"
	.string "じゅんびは　よろしいか？$"

	.globl gJPText_0022B891
gJPText_0022B891: @ 0x0822B891
	.string "つぎは　4にんめの　あいて　だが\n"
	.string "じゅんびは　よろしいか？$"

	.globl gJPText_0022B8AF
gJPText_0022B8AF: @ 0x0822B8AF
	.string "つぎは　5にんめの　あいて　だが\n"
	.string "じゅんびは　よろしいか？$"

	.globl gJPText_0022B8CD
gJPText_0022B8CD: @ 0x0822B8CD
	.string "つぎは　6にんめの　あいて　だが\n"
	.string "じゅんびは　よろしいか？$"

	.globl gJPText_0022B8EB
gJPText_0022B8EB: @ 0x0822B8EB
	.string "つぎは　7にんめの　あいて　だが\n"
	.string "じゅんびは　よろしいか？$"

	.globl gJPText_0022B909
gJPText_0022B909: @ 0x0822B909
	.string "レポートを　かいて　しゅうりょう　するか？$"

	.globl gJPText_0022B91F
gJPText_0022B91F: @ 0x0822B91F
	.string "ちょうせんを　ちゅうし　するのか？$"

	.globl gJPText_0022B931
gJPText_0022B931: @ 0x0822B931
	.string "レポートを　かいておる⋯⋯\n"
	.string "しばし　またれよ⋯⋯$"

	.globl gJPText_0022B94A
gJPText_0022B94A: @ 0x0822B94A
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　するか？$"

	.globl gJPText_0022B969
gJPText_0022B969: @ 0x0822B969
	.string "さて⋯⋯\p"
	.string "ここまで　かちぬいた　おぬしは\n"
	.string "われらが　あるじ　パレスガーディアンに\l"
	.string "ちょうせんする　しかくを　てにした⋯⋯$"

	.globl gJPText_0022B9A6
gJPText_0022B9A6: @ 0x0822B9A6
	.string "パレスガーディアンを　およびする\n"
	.string "⋯⋯かくごは　よいか？$"

	.globl gJPText_0022B9C3
gJPText_0022B9C3: @ 0x0822B9C3
	.string "パレスガーディアン　ウコンさまーーー！\n"
	.string "ごらいでんーーー！！$"

	.globl gJPText_0022B9E2
gJPText_0022B9E2: @ 0x0822B9E2
	.string "ウコン“わが　み\n"
	.string "つねに　ポケモンと　ありっ！\p"
	.string "わが　こころ\n"
	.string "つねに　ポケモンと　ありっ！\p"
	.string "わかき　トレーナーよ！！\n"
	.string "きさまは　ポケモンを\l"
	.string "しんじて　おるか？\p"
	.string "きさまは　ポケモンを\n"
	.string "しんじぬく　ことが　できるかっ！\p"
	.string "もろき　しんらいの　きずな　では\n"
	.string "わが　きょうだい　には　かてん！！$"

	.globl gJPText_0022BA71
gJPText_0022BA71: @ 0x0822BA71
	.string "ポケモンとの　きずな！！\n"
	.string "ここに　しめせぇい！！$"

	.globl gJPText_0022BA8A
gJPText_0022BA8A: @ 0x0822BA8A
	.string "ウコン“ぐわはっはっ！\p"
	.string "やはり　ハッタリ　なんぞ　きかんか！！\n"
	.string "おどしたり　して　わるかったのぅ！！\p"
	.string "おーい！　あれを！$"

	.globl gJPText_0022BAC7
gJPText_0022BAC7: @ 0x0822BAC7
	.string "やれやれ　あのまま　いげんを　たもって\n"
	.string "おいて　くだされば　よい　ものを⋯⋯\p"
	.string "おい！　フロンティアパスを　かさんか！$"

	.globl gJPText_0022BB02
gJPText_0022BB02: @ 0x0822BB02
	.string "フロンティアパスに\n"
	.string "スピリットシンボルが　きざまれた！$"

	.globl gJPText_0022BB1E
gJPText_0022BB1E: @ 0x0822BB1E
	.string "ウコン“おまえの　ポケモンたちは\n"
	.string "まことに　すんだ　ひとみを　しとる！\p"
	.string "つぎの　きかいを　たのしみに　しとるぞ！$"

	.globl gJPText_0022BB57
gJPText_0022BB57: @ 0x0822BB57
	.string "ウコン“ぐわはっはっ！\n"
	.string "ここまで　かちぬいて　きおったか！\p"
	.string "おまえは　ポケモン　たちと\n"
	.string "まことに　ええ　かんけいを\l"
	.string "きずいて　おるよう　だな！\p"
	.string "うむ！\p"
	.string "ほいじゃあ　こんどは　わしらも\n"
	.string "ハッタリや　てかげんは\l"
	.string "いっさい　ぬきで　いくと　しよう！\p"
	.string "ええか？　かくご　せい！！$"

	.globl gJPText_0022BBDF
gJPText_0022BBDF: @ 0x0822BBDF
	.string "⋯⋯　⋯⋯　⋯⋯　かーっ！！！$"

	.globl gJPText_0022BBEF
gJPText_0022BBEF: @ 0x0822BBEF
	.string "ウコン“いやはや　よう　やったわ！！\n"
	.string "ぜんりょくの　わが　きょうだいが\l"
	.string "はが　たたん　とは　なぁ！\p"
	.string "いやー　おまえらは　まことに　すんばらしい！\n"
	.string "おーいっ！　はやく　あれを！！$"

	.globl gJPText_0022BC48
gJPText_0022BC48: @ 0x0822BC48
	.string "ったく　ここの　イメージと　いうのを\n"
	.string "かんがえて　くれない　おかた　だ⋯⋯\p"
	.string "ええい！　おまえ！！\n"
	.string "さっさと　フロンティアパスを　かさんか！$"

	.globl gJPText_0022BC8E
gJPText_0022BC8E: @ 0x0822BC8E
	.string "スピリットシンボルが\n"
	.string "きんいろに　かがやいた！$"

	.globl gJPText_0022BCA6
gJPText_0022BCA6: @ 0x0822BCA6
	.string "ウコン“ぐわはっはっ！\p"
	.string "これからも　ときどき　あそびに　こいよ！\n"
	.string "わしも　きょうだいも　まっとる　からな！！$"

