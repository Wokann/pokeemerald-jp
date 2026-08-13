@ BattleFrontier_BattleTowerMultiPartnerRoom scripts (JP map g26 m15 @ 0x08223475)

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022348A
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223493
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_002234F7
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_00223506
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022348A::
	setvar 0x8004, 0x11
	special CallBattlePyramidFunction
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223493::
	checkflag 0x152
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002234BD
	clearflag 0x2C7
	clearflag 0x2C8
	clearflag 0x2C9
	clearflag 0x2CA
	clearflag 0x2CB
	clearflag 0x2CC
	setflag 0x360
	setflag 0x361
	setvar 0x8004, 0xA
	special sub_08161E88
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002234BD::
	setvar 0x4010, 0x7
	setvar 0x4011, 0x7
	setvar 0x4012, 0x7
	setvar 0x4013, 0x7
	setvar 0x4014, 0x7
	setvar 0x4015, 0x7
	setvar 0x4016, 0x7
	setvar 0x4017, 0x7
	setvar 0x4001, 0x1
	setvar 0x4003, 0x1
	setobjectxyperm 0x1, 0xA, 0x2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_002234F7::
	map_script_2 0x4003, 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223501
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223501::
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_00223506::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223524
	map_script_2 0x4003, 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223518
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223518::
	lockall
	setvar 0x4003, 0x0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223598
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223524::
	lockall
	applymovement 0xFF, 0x08223558
	waitmovement 0x0
	applymovement 0x1, 0x0822355A
	waitmovement 0x0
	moveobjectoffscreen 0x1
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_00223739
	callstd 0x4
	special HealPlayerParty
	setvar 0x4001, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x223558, 0x5
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022355D::
	lock
	faceplayer
	message 0x0822375E
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223580
	loadword 0x0, 0x08223797
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223580::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto 0x08221CFC
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223598::
	loadword 0x0, gJPText_002237C1
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	opendoor 0xA, 0x1
	waitmoncry
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002235C7
	closedoor 0xA, 0x1
	waitmoncry
	warp 0x1A06, 0xFF, 0x1, 0x6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002235C7::
	applymovement 0x1, 0x08223609
	applymovement 0xFF, 0x082235FD
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x2235d9, 0x33
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022360C::
	lock
	faceplayer
	setvar 0x4002, 0x0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619::
	checkflag 0x152
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6
	setvar 0x8004, 0xB
	setvar 0x8005, 0x0
	special sub_08161E88
	waitmessage
	waitbuttonpress
	setvar 0x8004, 0xB
	setvar 0x8005, 0x1
	special sub_08161E88
	waitmessage
	waitbuttonpress
	setvar 0x8004, 0xB
	setvar 0x8005, 0x2
	special sub_08161E88
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6
	setvar 0x8004, 0xB
	setvar 0x8005, 0x3
	special sub_08161E88
	waitmessage
	waitbuttonpress
	closemessage
	compare_var_to_value 0x800C, 0x1
	call_if 0x5, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236B7
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236C2
	removeobject 0x800F
	setflag 0x152
	warpsilent 0x1A0F, 0xFF, 0xA, 0x3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6::
	setvar 0x8004, 0xB
	setvar 0x8005, 0x4
	special sub_08161E88
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236B7::
	applymovement 0x800F, 0x082236CD
	waitmovement 0x0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236C2::
	applymovement 0x800F, 0x082236D5
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x2236cd, 0x11
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236DE::
	lock
	faceplayer
	setvar 0x4002, 0x1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236EB::
	lock
	faceplayer
	setvar 0x4002, 0x2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236F8::
	lock
	faceplayer
	setvar 0x4002, 0x3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223705::
	lock
	faceplayer
	setvar 0x4002, 0x4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223712::
	lock
	faceplayer
	setvar 0x4002, 0x5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022371F::
	lock
	faceplayer
	setvar 0x4002, 0x6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022372C::
	lock
	faceplayer
	setvar 0x4002, 0x7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

	.globl gJPText_00223739
gJPText_00223739: @ 0x08223739
	.string "こちらに　いる　トレーナーの　なかから\n"
	.string "パートナーを　おさがしください！$"

	.incbin "baserom_jp.gba", 0x22375e, 0x63
	.globl gJPText_002237C1
gJPText_002237C1: @ 0x082237C1
	.string "パートナーさがし\n"
	.string "おつかれさまでした！\p"
	.string "それでは　マルチ　バトルルームへ\n"
	.string "おつれいたします$"

	.incbin "baserom_jp.gba", 0x2237ef, 0x2c11
