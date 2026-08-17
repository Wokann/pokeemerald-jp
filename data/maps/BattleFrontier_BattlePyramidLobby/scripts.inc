@ BattleFrontier_BattlePyramidLobby scripts (JP map g26 m25 @ 0x0822BCDD)

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_MapScriptTable_0022BCFC
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, 0x08226DA5
	.byte 0

	.incbin "baserom_jp.gba", 0x22bce8, 0x14
BattleFrontier_BattlePyramidLobby_MapScriptTable_0022BCFC::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePyramidLobby_EventScript_0022BD26
	map_script_2 0x4000, 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022BD2F
	map_script_2 0x4000, 0x2, BattleFrontier_BattlePyramidLobby_EventScript_0022BE73
	map_script_2 0x4000, 0x3, BattleFrontier_BattlePyramidLobby_EventScript_0022BD78
	map_script_2 0x4000, 0x4, BattleFrontier_BattlePyramidLobby_EventScript_0022BE19
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_0022BD26::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022BD2F::
	lockall
	message gJPText_0022C956
	waitmessage
	playse 0x5B
	waitse
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallBattlePyramidFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattlePyramidFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022BD78::
	lockall
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022BD99
	loadword 0x0, gJPText_0022C9CE
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022BDA1

BattleFrontier_BattlePyramidLobby_EventScript_0022BD99::
	loadword 0x0, gJPText_0022D2B7
	callstd 0x4

BattleFrontier_BattlePyramidLobby_EventScript_0022BDA1::
	special DoBattlePyramidMonsHaveHeldItem
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C3A2
	clearflag 0x4004
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar 0x8004, 0xE
	special CallBattlePyramidFunction
	special HealPlayerParty
	message gJPText_0022CAEE
	waitmessage
	playse 0x5B
	waitse
	loadword 0x0, gJPText_0022D2EA
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022189E
	callstd 0x9
	message gJPText_0022CB38
	waitmessage
	setvar 0x8004, 0x4
	special CallBattlePyramidFunction
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallBattlePyramidFunction
	playse 0x37
	waitse
	loadword 0x0, gJPText_0022CBF4
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022BE19::
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar 0x8004, 0xE
	special CallBattlePyramidFunction
	special HealPlayerParty
	lockall
	message gJPText_0022CBBD
	waitmessage
	playse 0x5B
	waitse
	message gJPText_0022CB38
	waitmessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattlePyramidFunction
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallBattlePyramidFunction
	playse 0x37
	waitse
	loadword 0x0, gJPText_0022CBF4
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022BE73::
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022BFE8

BattleFrontier_BattlePyramidLobby_EventScript_0022BE78::
	lock
	faceplayer
	setvar 0x40CF, 0x6
	setvar 0x40CE, 0x0
	special SavePlayerParty
	loadword 0x0, 0x0822C4F8
	callstd 0x4

BattleFrontier_BattlePyramidLobby_EventScript_0022BE8F::
	message 0x0822C53F
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022BECB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C02F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C08B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C08B

BattleFrontier_BattlePyramidLobby_EventScript_0022BECB::
	message 0x0822C6BD
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C08B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C08B
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C03C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822C6EA
	callstd 0x4
	fadescreen 0x1
	call 0x082202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C088
	loadword 0x0, 0x0822C83E
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C088
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022BF6C
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C088

BattleFrontier_BattlePyramidLobby_EventScript_0022BF6C::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special CallBattlePyramidFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special CallBattlePyramidFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x6
	special CallBattlePyramidFunction
	setvar 0x8004, 0x9
	special CallBattlePyramidFunction
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C071

BattleFrontier_BattlePyramidLobby_EventScript_0022BFE8::
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022C866
	callstd 0x4
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_0022C31D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x800D, 0x0
	special HealPlayerParty
	warp 0x1A1A, 0xFF, 0x1, 0x1
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C02F::
	loadword 0x0, 0x0822C571
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022BE8F

BattleFrontier_BattlePyramidLobby_EventScript_0022C03C::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C057
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C064

BattleFrontier_BattlePyramidLobby_EventScript_0022C057::
	loadword 0x0, 0x0822C786
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C093

BattleFrontier_BattlePyramidLobby_EventScript_0022C064::
	loadword 0x0, 0x0822C708
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C093

BattleFrontier_BattlePyramidLobby_EventScript_0022C071::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C08B

BattleFrontier_BattlePyramidLobby_EventScript_0022C088::
	special LoadPlayerParty

BattleFrontier_BattlePyramidLobby_EventScript_0022C08B::
	loadword 0x0, 0x0822C559
	callstd 0x4

BattleFrontier_BattlePyramidLobby_EventScript_0022C093::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C095::
	lockall
	applymovement 0x2, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x0822CC44
	callstd 0x4
	call BattleFrontier_BattlePyramidLobby_EventScript_0022C0B7
	loadword 0x0, 0x0822D1C7
	callstd 0x4
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C0B7::
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C0EF
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C12D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C0EE
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C0EE
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C0EE::
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C0EF::
	loadword 0x0, 0x0822CC6D
	callstd 0x4
	setvar 0x8004, 0x1
	setvar 0x8005, 0x5
	special CallBattlePyramidFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidLobby_EventScript_0022C11A
	setvar 0x800D, 0x0
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C16B
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C11A::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special CallBattlePyramidFunction
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C16B
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C12D::
	loadword 0x0, 0x0822CC6D
	callstd 0x4
	setvar 0x8004, 0x1
	setvar 0x8005, 0x6
	special CallBattlePyramidFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePyramidLobby_EventScript_0022C158
	setvar 0x800D, 0x0
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C16B
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C158::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x4
	special CallBattlePyramidFunction
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C16B
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C16B::
	copyvar 0x8004, 0x800D
	special sub_0813B9A0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C255
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C25E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C267
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C270
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C279
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C282
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C28B
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C294
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C29D
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2A6
	compare_var_to_value 0x8000, 0xA
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2AF
	compare_var_to_value 0x8000, 0xB
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2B8
	compare_var_to_value 0x8000, 0xC
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2C1
	compare_var_to_value 0x8000, 0xD
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2CA
	compare_var_to_value 0x8000, 0xE
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2D3
	compare_var_to_value 0x8000, 0xF
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2DC
	compare_var_to_value 0x8000, 0x10
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2E5
	compare_var_to_value 0x8000, 0x11
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2EE
	compare_var_to_value 0x8000, 0x12
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C2F7
	compare_var_to_value 0x8000, 0x13
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C300
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C255::
	loadword 0x0, 0x0822CCA1
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C25E::
	loadword 0x0, 0x0822CCDC
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C267::
	loadword 0x0, 0x0822CD0D
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C270::
	loadword 0x0, 0x0822CD44
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C279::
	loadword 0x0, 0x0822CD9A
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C282::
	loadword 0x0, 0x0822CDE1
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C28B::
	loadword 0x0, 0x0822CE26
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C294::
	loadword 0x0, 0x0822CE63
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C29D::
	loadword 0x0, 0x0822CEA5
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2A6::
	loadword 0x0, 0x0822CEE4
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2AF::
	loadword 0x0, 0x0822CF1F
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2B8::
	loadword 0x0, 0x0822CF5E
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2C1::
	loadword 0x0, 0x0822CFC1
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2CA::
	loadword 0x0, 0x0822D000
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2D3::
	loadword 0x0, 0x0822D03C
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2DC::
	loadword 0x0, 0x0822D077
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2E5::
	loadword 0x0, 0x0822D0B6
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2EE::
	loadword 0x0, 0x0822D0F5
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C2F7::
	loadword 0x0, 0x0822D132
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C300::
	loadword 0x0, 0x0822D187
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C309::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x6
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C31D::
	applymovement 0x1, 0x0822C38B
	applymovement 0xFF, 0x0822C394
	waitmovement 0x0
	loadword 0x0, gJPText_0022C882
	callstd 0x4
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallBattlePyramidFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C35B
	loadword 0x0, gJPText_0022C8A8
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C363

BattleFrontier_BattlePyramidLobby_EventScript_0022C35B::
	loadword 0x0, gJPText_0022C8CF
	callstd 0x4

BattleFrontier_BattlePyramidLobby_EventScript_0022C363::
	message gJPText_0022C8EA
	waitmessage
	playse 0x5B
	waitse
	loadword 0x0, gJPText_0022C907
	callstd 0x4
	closemessage
	applymovement 0x1, 0x0822C39C
	waitmovement 0x0
	applymovement 0xFF, 0x0822C39F
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x22c38b, 0x17
BattleFrontier_BattlePyramidLobby_EventScript_0022C3A2::
	loadword 0x0, gJPText_0022C9F4
	callstd 0x4
	setflag 0x4004
	special sub_081C62AC
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C3C7
	message gJPText_0022CA67
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C3D0
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C3C7::
	loadword 0x0, gJPText_0022CA3F
	callstd 0x4
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C3D0::
	multichoice 0x11, 0x6, 0x53, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C407
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C417
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C427
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C427
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C407::
	special sub_081C472C
	waitstate
	message gJPText_0022CAB5
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C3D0
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C417::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message gJPText_0022CAB5
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C3D0
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C427::
	special DoBattlePyramidMonsHaveHeldItem
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C436
	return

BattleFrontier_BattlePyramidLobby_EventScript_0022C436::
	loadword 0x0, gJPText_0022CA9D
	callstd 0x4
	message gJPText_0022CAB5
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C3D0
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C44A::
	loadword 0x0, 0x0822D202
	callstd 0x2
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C453::
	loadword 0x0, 0x0822D276
	callstd 0x2
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C45C::
	lockall
	loadword 0x0, 0x0822D31A
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C46B
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C46B::
	message 0x0822D333
	waitmessage
	multichoice 0xF, 0x2, 0x65, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C4BE
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C4CC
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C4DA
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C4E8
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C4F6
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePyramidLobby_EventScript_0022C4F6
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C4BE::
	loadword 0x0, 0x0822D343
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C46B
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C4CC::
	loadword 0x0, 0x0822D398
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C46B
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C4DA::
	loadword 0x0, 0x0822D3FE
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C46B
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C4E8::
	loadword 0x0, 0x0822D46E
	callstd 0x4
	goto BattleFrontier_BattlePyramidLobby_EventScript_0022C46B
	end

BattleFrontier_BattlePyramidLobby_EventScript_0022C4F6::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x22c4f8, 0x36e
	.globl gJPText_0022C866
gJPText_0022C866: @ 0x0822C866
	.string "では　バトルピラミッドの　なかへ\n"
	.string "おつれいたしますぞ！$"

	.globl gJPText_0022C882
gJPText_0022C882: @ 0x0822C882
	.string "{MUS_RG_VS_TRAINER}さんの　もっている　バッグは\n"
	.string "こちらで　あずからせて　いただきますぞ！$"

	.globl gJPText_0022C8A8
gJPText_0022C8A8: @ 0x0822C8A8
	.string "かわりに　ぜんかい　おつかいになった\n"
	.string "この　バトルバッグを　おもちくだされ！$"

	.globl gJPText_0022C8CF
gJPText_0022C8CF: @ 0x0822C8CF
	.string "かわりに　こちらの\n"
	.string "バトルバッグを　おもちくだされ！$"

	.globl gJPText_0022C8EA
gJPText_0022C8EA: @ 0x0822C8EA
	.string "{MUS_RG_VS_TRAINER}は　バッグを　あずけて\n"
	.string "バトルバッグを　うけとった！$"

	.globl gJPText_0022C907
gJPText_0022C907: @ 0x0822C907
	.string "こちらにある　ゆかを　ふんで　いただくと\n"
	.string "ピラミッドの　うえの　だんへと\l"
	.string "すすむことが　できますぞ！\p"
	.string "ぶじ　ぼうけんが　すすむことを\n"
	.string "いのって　おりますぞ！$"

	.globl gJPText_0022C956
gJPText_0022C956: @ 0x0822C956
	.string "ぼうけんしゃよ！\p"
	.string "ぜんかい　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたな？\p"
	.string "ざんねんですが　この　ばあい\n"
	.string "ちょうせんは　むこうと　なりますぞ！\p"
	.string "おあずかり　していた\n"
	.string "バッグは　おかえし　いたしますぞ！\p"
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "バッグを　うけとった！$"

	.globl gJPText_0022C9CE
gJPText_0022C9CE: @ 0x0822C9CE
	.string "おかえりなさいませ！\p"
	.string "みごとに　バトルピラミッドを\n"
	.string "せいは　されましたな！$"

	.globl gJPText_0022C9F4
gJPText_0022C9F4: @ 0x0822C9F4
	.string "おおっ！\p"
	.string "ポケモンに\n"
	.string "どうぐを　もたせていますな⋯⋯\p"
	.string "もうしわけ　ありませんが\n"
	.string "ピラミッドで　てにいれた　どうぐは\l"
	.string "もっていくことが　できませんぞ！$"

	.globl gJPText_0022CA3F
gJPText_0022CA3F: @ 0x0822CA3F
	.string "もたせている　どうぐは\n"
	.string "すべて　{MUS_RG_VS_TRAINER}さんの　バトルバッグに\l"
	.string "いれておきますぞ！$"

	.globl gJPText_0022CA67
gJPText_0022CA67: @ 0x0822CA67
	.string "バトルバッグには\n"
	.string "すべて　はいらない　ようなので\l"
	.string "バトルバッグと　もたせたどうぐを\l"
	.string "せいりして　くだされ！$"

	.globl gJPText_0022CA9D
gJPText_0022CA9D: @ 0x0822CA9D
	.string "ポケモンに\n"
	.string "まだ　どうぐを　もたせていますぞ！$"

	.globl gJPText_0022CAB5
gJPText_0022CAB5: @ 0x0822CAB5
	.string "バトルバッグと　もたせたどうぐを\n"
	.string "せいりして　くだされ！$"

	.incbin "baserom_jp.gba", 0x22cad2, 0x1c
	.globl gJPText_0022CAEE
gJPText_0022CAEE: @ 0x0822CAEE
	.string "おつかいになられた　バトルバッグは\n"
	.string "じかいの　ちょうせんまで\l"
	.string "おあずかり　いたしますぞ！\p"
	.string "{MUS_RG_VS_TRAINER}は　バトルバッグを　あずけて\n"
	.string "バッグを　うけとった！$"

	.globl gJPText_0022CB38
gJPText_0022CB38: @ 0x0822CB38
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちくだされ！$"

	.incbin "baserom_jp.gba", 0x22cb54, 0x69
	.globl gJPText_0022CBBD
gJPText_0022CBBD: @ 0x0822CBBD
	.string "ざんねんでしたな⋯⋯\p"
	.string "おあずかりしていた\n"
	.string "バッグは　おかえし　いたしますぞ！\p"
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "バッグを　うけとった！$"

	.globl gJPText_0022CBF4
gJPText_0022CBF4: @ 0x0822CBF4
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

	.incbin "baserom_jp.gba", 0x22cc0c, 0x6ab
	.globl gJPText_0022D2B7
gJPText_0022D2B7: @ 0x0822D2B7
	.string "おかえりなさいませ！\p"
	.string "ピラミッドキングを　たおし\n"
	.string "みごと　バトルピラミッドを\l"
	.string "せいは　されましたな！$"

	.globl gJPText_0022D2EA
gJPText_0022D2EA: @ 0x0822D2EA
	.string "ぼうけんしゃよ！\n"
	.string "あなたの　あつい　ゆうきを　たたえ\l"
	.string "バトルポイントを　おおくり　しましょう！$"

	.incbin "baserom_jp.gba", 0x22d31a, 0x1e2
