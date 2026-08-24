@ BattleFrontier_BattlePikeRoomNormal scripts (JP map g26 m37 @ 0x082343A7)

BattleFrontier_BattlePikeRoomNormal_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, 0x082746C7
	map_script MAP_SCRIPT_ON_TRANSITION, 0x082742B8
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_MapScriptTable_002343BC
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, 0x08274371
	.byte 0

BattleFrontier_BattlePikeRoomNormal_MapScriptTable_002343BC::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePikeRoomNormal_EventScript_002343C6
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_002343C6::
	setvar 0x4000, 0x1
	setvar 0x8004, 0x5
	special CallBattlePikeFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023441B
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234763
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023485A
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234486
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234793
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234514
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_0023441B::
	lockall
	delay 0x10
	applymovement 0x1, 0x082349EA
	waitmovement 0x0
	setvar 0x8004, 0x15
	setvar 0x8005, 0x0
	special CallBattlePikeFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	closemessage
	releaseall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023447B

BattleFrontier_BattlePikeRoomNormal_EventScript_0023445F::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	warp 0x1A22, 0xFF, 0x5, 0x6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_0023447B::
	applymovement 0x1, 0x082349ED
	waitmovement 0x0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234486::
	lockall
	delay 0x10
	loadword 0x0, gJPText_00234E6D
	callstd 0x4
	waitmessage
	closemessage
	applymovement 0x1, 0x082349EA
	waitmovement 0x0
	setvar 0x8004, 0x15
	setvar 0x8005, 0x0
	special CallBattlePikeFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	closemessage
	releaseall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002344DA
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_0023445F
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_002344DA::
	applymovement 0x1, 0x082349ED
	waitmovement 0x0
	applymovement 0x2, 0x08234A0B
	waitmovement 0x0
	lock
	faceplayer
	loadword 0x0, gJPText_00234E9E
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty
	loadword 0x0, gJPText_00234ED0
	callstd 0x4
	closemessage
	release
	applymovement 0x2, 0x082349ED
	waitmovement 0x0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234514::
	delay 0x16
	lockall
	applymovement 0x2, 0x08234A34
	waitmovement 0x0
	setvar 0x8004, 0x17
	special CallBattlePikeFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234731
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023473F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234751

BattleFrontier_BattlePikeRoomNormal_EventScript_00234550::
	loadword 0x0, gJPText_002351FE
	callstd 0x4
	closemessage
	special SpawnCameraObject
	applymovement 0x7F, 0x08234C05
	applymovement 0x2, 0x08234A37
	waitmovement 0x0
	playse 0x10B
	call BattleFrontier_BattlePikeRoomNormal_EventScript_00234B3C
	delay 0x4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_00234AF9
	delay 0x4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_00234BC2
	delay 0x4
	waitse
	delay 0x3C
	playse 0x10C
	delay 0x41
	call BattleFrontier_BattlePikeRoomNormal_EventScript_00234AF9
	showobject_at 0x1, 0x1A25
	delay 0x4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_00234B3C
	delay 0x4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_00234B7F
	waitse
	applymovement 0x1, 0x08234A3C
	waitmovement 0x0
	setvar 0x8004, 0x16
	special CallBattlePikeFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023466B
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234612
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234698
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePikeRoomNormal_EventScript_00234612
	loadword 0x0, gJPText_00234EED
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattlePikeRoomNormal_EventScript_00234612::
	loadword 0x0, gJPText_00234F5B
	callstd 0x4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_002349D0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023462F
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_0023445F

BattleFrontier_BattlePikeRoomNormal_EventScript_0023462F::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePikeRoomNormal_EventScript_002346F2
	loadword 0x0, gJPText_00234F78
	callstd 0x4
	waitmessage
	playfanfare 0x1D2
	message gJPText_00234F98
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00234FB2
	callstd 0x4
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_002346F2

BattleFrontier_BattlePikeRoomNormal_EventScript_0023466B::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePikeRoomNormal_EventScript_00234698
	loadword 0x0, gJPText_00234FC6
	callstd 0x4
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc

BattleFrontier_BattlePikeRoomNormal_EventScript_00234698::
	loadword 0x0, gJPText_00235050
	callstd 0x4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_002349D0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002346B5
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_0023445F

BattleFrontier_BattlePikeRoomNormal_EventScript_002346B5::
	setvar 0x8004, 0xC
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002346F2
	loadword 0x0, gJPText_00235060
	callstd 0x4
	waitmessage
	playfanfare 0x1D2
	message gJPText_00235081
	waitmessage
	waitfanfare
	setvar 0x8004, 0xD
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00235097
	callstd 0x4
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_002346F2
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_002346F2::
	applymovement 0x1, 0x08234A3F
	waitmovement 0x0
	applymovement 0xFF, 0x08234A31
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallBattlePikeFunction
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallBattlePikeFunction
	call 0x082745CD
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234731::
	loadword 0x0, gJPText_002350B6
	callstd 0x4
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_00234550
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_0023473F::
	loadword 0x0, gJPText_0023510F
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_00234550
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234751::
	loadword 0x0, gJPText_00235158
	callstd 0x4
	playfanfare 0x170
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_00234550
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234763::
	lockall
	delay 0x10
	applymovement 0x1, 0x082349EA
	waitmovement 0x0
	message gJPText_00234C0B
	waitmessage
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty
	loadword 0x0, gJPText_00234C3B
	callstd 0x4
	closemessage
	applymovement 0x1, 0x082349ED
	waitmovement 0x0
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234793::
	lockall
	delay 0x10
	applymovement 0x1, 0x08234A16
	applymovement 0x2, 0x08234A18
	waitmovement 0x0
	applymovement 0x1, 0x08234A1A
	applymovement 0x2, 0x08234A1A
	waitmovement 0x0
	applymovement 0x1, 0x08234A1D
	applymovement 0x2, 0x08234A1F
	waitmovement 0x0
	applymovement 0xFF, 0x08234A10
	waitmovement 0x0
	setvar 0x8004, 0x15
	setvar 0x8005, 0x0
	special CallBattlePikeFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	closemessage
	delay 0x10
	applymovement 0xFF, 0x08234A12
	waitmovement 0x0
	setvar 0x8004, 0x15
	setvar 0x8005, 0x1
	special CallBattlePikeFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	closemessage
	setvar 0x8004, 0x9
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234831
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_0023445F
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234831::
	applymovement 0xFF, 0x08234A12
	waitmovement 0x0
	applymovement 0x1, 0x08234A21
	waitmovement 0x0
	applymovement 0x2, 0x08234A29
	waitmovement 0x0
	applymovement 0xFF, 0x08234A14
	waitmovement 0x0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_0023485A::
	lockall
	message gJPText_00234D2A
	applymovement 0x2, 0x082349FF
	waitmovement 0x0
	setvar 0x8004, 0xC
	special CallBattlePikeFunction
	copyvar 0x8004, 0x800D
	compare_var_to_value 0x8004, 0x0
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234898
	compare_var_to_value 0x8004, 0x1
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_0023492A
	loadword 0x0, gJPText_00234E0C
	callstd 0x4
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234898::
	loadword 0x0, gJPText_00234D39
	callstd 0x4
	closemessage
	waitse
	playmoncry 0x189, 0x0
	waitdooranim
	setvar 0x8004, 0xB
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002349A6
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002349AD
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002349B4
	compare_var_to_value 0x800D, 0x4
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002349BB
	setvar 0x8004, 0xF
	special CallBattlePikeFunction
	waitstate
	applymovement 0x1, 0x082349F7
	waitmovement 0x0
	applymovement 0x2, 0x08234A06
	waitmovement 0x0
	waitse
	playmoncry 0x189, 0x0
	waitdooranim
	loadword 0x0, gJPText_00234DB5
	callstd 0x4
	waitse
	playmoncry 0x189, 0x0
	waitdooranim
	closemessage
	applymovement 0x2, 0x08234A08
	applymovement 0x1, 0x082349F9
	waitmovement 0x0
	loadword 0x0, gJPText_00234DCA
	callstd 0x4
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_0023492A::
	loadword 0x0, gJPText_00234D4D
	callstd 0x4
	closemessage
	waitse
	playmoncry 0x16A, 0x0
	waitdooranim
	setvar 0x8004, 0xB
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002349C2
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_002349C9
	setvar 0x8004, 0xF
	special CallBattlePikeFunction
	waitstate
	applymovement 0x1, 0x082349F7
	waitmovement 0x0
	applymovement 0x2, 0x08234A06
	waitmovement 0x0
	waitse
	playmoncry 0x16A, 0x0
	waitdooranim
	loadword 0x0, gJPText_00234DB5
	callstd 0x4
	waitse
	playmoncry 0x16A, 0x0
	waitdooranim
	closemessage
	applymovement 0x2, 0x08234A08
	applymovement 0x1, 0x082349F9
	waitmovement 0x0
	loadword 0x0, gJPText_00234DEA
	callstd 0x4
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349A6::
	message gJPText_00234D62
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349AD::
	message gJPText_00234D8E
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349B4::
	message gJPText_00234D82
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349BB::
	message gJPText_00234D73
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349C2::
	message gJPText_00234DA5
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349C9::
	message gJPText_00234D99
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_002349D0::
	closemessage
	applymovement 0xFF, 0x08234A31
	waitmovement 0x0
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	return

	.incbin "baserom_jp.gba", 0x2349ea, 0x58
BattleFrontier_BattlePikeRoomNormal_EventScript_00234A42::
	setvar 0x8004, 0x5
	special CallBattlePikeFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234A70
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234A86
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234A93

BattleFrontier_BattlePikeRoomNormal_EventScript_00234A70::
	lock
	faceplayer
	setvar 0x8004, 0xE
	special CallBattlePikeFunction
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234A86::
	lock
	faceplayer
	loadword 0x0, 0x08234E42
	callstd 0x4
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234A93::
	setvar 0x8004, 0xD
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234AD6
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattlePikeRoomNormal_EventScript_00234ACA
	playfanfare 0x170
	waitfanfare
	loadword 0x0, 0x08234CA3
	callstd 0x4
	closemessage
	release
	applymovement 0x1, 0x082349F3
	waitmovement 0x0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234ACA::
	lock
	faceplayer
	loadword 0x0, 0x08234C58
	callstd 0x4
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_00234AD6::
	lock
	faceplayer
	loadword 0x0, 0x0823521C
	callstd 0x4
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_00234AE2::
	lock
	faceplayer
	loadword 0x0, 0x08234E5B
	callstd 0x4
	closemessage
	release
	applymovement 0x2, 0x08234A09
	waitmovement 0x0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_00234AF9::
	setmetatile 0x4, 0x1, 0x22A, 0x1
	setmetatile 0x3, 0x2, 0x231, 0x1
	setmetatile 0x4, 0x2, 0x232, 0x1
	setmetatile 0x5, 0x2, 0x233, 0x1
	setmetatile 0x3, 0x3, 0x239, 0x1
	setmetatile 0x4, 0x3, 0x23A, 0x0
	setmetatile 0x5, 0x3, 0x23B, 0x1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_00234B3C::
	setmetatile 0x4, 0x1, 0x20A, 0x1
	setmetatile 0x3, 0x2, 0x211, 0x1
	setmetatile 0x4, 0x2, 0x212, 0x1
	setmetatile 0x5, 0x2, 0x213, 0x1
	setmetatile 0x3, 0x3, 0x219, 0x1
	setmetatile 0x4, 0x3, 0x21A, 0x0
	setmetatile 0x5, 0x3, 0x21B, 0x1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_00234B7F::
	setmetatile 0x4, 0x1, 0x2AB, 0x1
	setmetatile 0x3, 0x2, 0x2B2, 0x1
	setmetatile 0x4, 0x2, 0x2B3, 0x1
	setmetatile 0x5, 0x2, 0x2B4, 0x1
	setmetatile 0x3, 0x3, 0x2BA, 0x1
	setmetatile 0x4, 0x3, 0x2BB, 0x0
	setmetatile 0x5, 0x3, 0x2BC, 0x1
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_00234BC2::
	setmetatile 0x4, 0x1, 0x24A, 0x1
	setmetatile 0x3, 0x2, 0x251, 0x1
	setmetatile 0x4, 0x2, 0x252, 0x1
	setmetatile 0x5, 0x2, 0x253, 0x1
	setmetatile 0x3, 0x3, 0x259, 0x1
	setmetatile 0x4, 0x3, 0x25A, 0x0
	setmetatile 0x5, 0x3, 0x25B, 0x1
	special DrawWholeMapView
	return

	.incbin "baserom_jp.gba", 0x234c05, 0x6
	.globl gJPText_00234C0B
gJPText_00234C0B: @ 0x08234C0B
	.string "ようこそ⋯⋯\n"
	.string "おきゃくさまは　ラッキー　ですね⋯⋯\p"
	.string "ポケモンを　かいふくして　さしあげます⋯⋯$"

	.globl gJPText_00234C3B
gJPText_00234C3B: @ 0x08234C3B
	.string "それでは　ひきつづき\n"
	.string "ゲームを　おたのしみ　ください⋯⋯$"

	.incbin "baserom_jp.gba", 0x234c58, 0xd2
	.globl gJPText_00234D2A
gJPText_00234D2A: @ 0x08234D2A
	.string "！！\p"
	.string "きみ！　あぶないっ！！$"

	.globl gJPText_00234D39
gJPText_00234D39: @ 0x08234D39
	.string "おいっ！\n"
	.string "キルリア！！　やめなさいっ！$"

	.globl gJPText_00234D4D
gJPText_00234D4D: @ 0x08234D4D
	.string "おいっ！\n"
	.string "サマヨール！！　やめなさいっ！$"

	.globl gJPText_00234D62
gJPText_00234D62: @ 0x08234D62
	.string "キルリアの　どくどく　こうげき！$"

	.globl gJPText_00234D73
gJPText_00234D73: @ 0x08234D73
	.string "キルリアの　さいみんじゅつ！$"

	.globl gJPText_00234D82
gJPText_00234D82: @ 0x08234D82
	.string "キルリアの　でんじは！$"

	.globl gJPText_00234D8E
gJPText_00234D8E: @ 0x08234D8E
	.string "キルリアの　おにび！$"

	.globl gJPText_00234D99
gJPText_00234D99: @ 0x08234D99
	.string "サマヨールの　おにび！$"

	.globl gJPText_00234DA5
gJPText_00234DA5: @ 0x08234DA5
	.string "サマヨールの　れいとうビーム！$"

	.globl gJPText_00234DB5
gJPText_00234DB5: @ 0x08234DB5
	.string "ええいっ！　いいかげんに　しないかっ！！$"

	.globl gJPText_00234DCA
gJPText_00234DCA: @ 0x08234DCA
	.string "もうしわけない⋯⋯\p"
	.string "わたしの　キルリアは　おくびょう　でな⋯⋯$"

	.globl gJPText_00234DEA
gJPText_00234DEA: @ 0x08234DEA
	.string "もうしわけない　⋯⋯\p"
	.string "わたしの　サマヨールは　おくびょう　でな⋯⋯$"

	.globl gJPText_00234E0C
gJPText_00234E0C: @ 0x08234E0C
	.string "きゅうに　ひとを　みると　おどろいて\n"
	.string "おそいかかって　しまうのだ⋯⋯\p"
	.string "きみも　ポケモンも　だいじょうぶか？$"

	.incbin "baserom_jp.gba", 0x234e42, 0x2b
	.globl gJPText_00234E6D
gJPText_00234E6D: @ 0x08234E6D
	.string "ようこそ⋯⋯\p"
	.string "こちらでは　しょうしょう　うでの　たつ\n"
	.string "トレーナーと　たたかって　いただきます⋯⋯$"

	.globl gJPText_00234E9E
gJPText_00234E9E: @ 0x08234E9E
	.string "⋯⋯すばらしい⋯⋯\p"
	.string "おきゃくさまの　しょうりを　たたえ\n"
	.string "ポケモンを　かいふくして　さしあげます⋯⋯$"

	.globl gJPText_00234ED0
gJPText_00234ED0: @ 0x08234ED0
	.string "それでは　ひきつづき\n"
	.string "ゲームを　おたのしみ　ください⋯⋯$"

	.globl gJPText_00234EED
gJPText_00234EED: @ 0x08234EED
	.string "あたしは　アザミ⋯⋯\n"
	.string "ここの　あるじ⋯⋯　チューブクイーン⋯⋯\p"
	.string "⋯⋯　まあ　わかると　おもうけど\n"
	.string "あたしを　たおさなきゃ\l"
	.string "このさき　すすめないよ⋯⋯\p"
	.string "⋯⋯　おしゃべりは　すきじゃ　ないからね\n"
	.string "さっさと　かかっといで⋯⋯$"

	.globl gJPText_00234F5B
gJPText_00234F5B: @ 0x08234F5B
	.string "あんたの　うん⋯⋯\n"
	.string "ここで　つきなきゃ　いい　けどね⋯⋯$"

	.globl gJPText_00234F78
gJPText_00234F78: @ 0x08234F78
	.string "アザミ“⋯⋯　⋯⋯　⋯⋯　⋯⋯\n"
	.string "フロンティアパス　よこしな⋯⋯$"

	.globl gJPText_00234F98
gJPText_00234F98: @ 0x08234F98
	.string "フロンティアパスに\n"
	.string "ラックシンボルが　きざまれた！$"

	.globl gJPText_00234FB2
gJPText_00234FB2: @ 0x08234FB2
	.string "⋯⋯　ほら⋯⋯　さっさと　きえな⋯⋯⋯$"

	.globl gJPText_00234FC6
gJPText_00234FC6: @ 0x08234FC6
	.string "アザミ“⋯⋯　また　あんたか⋯⋯\p"
	.string "⋯⋯　⋯⋯　⋯⋯　⋯⋯\p"
	.string "⋯⋯　⋯⋯　はなも　あらしも　ふみこえて\n"
	.string "いきてきた　この　あたし⋯⋯　⋯⋯\p"
	.string "そうそう　おなじ　あいてに\n"
	.string "まけて　やる　ひつようも　ないね⋯⋯\l"
	.string "⋯⋯　⋯⋯　⋯⋯　⋯⋯　いいわ⋯⋯\l"
	.string "やって　やるよ⋯⋯　⋯⋯　⋯⋯　⋯⋯$"

	.globl gJPText_00235050
gJPText_00235050: @ 0x08235050
	.string "おらっ！！　かかっといでっ！！$"

	.globl gJPText_00235060
gJPText_00235060: @ 0x08235060
	.string "アザミ“⋯⋯　⋯⋯　⋯⋯　⋯⋯\p"
	.string "⋯⋯　⋯⋯　フロンティアパス⋯⋯$"

	.globl gJPText_00235081
gJPText_00235081: @ 0x08235081
	.string "ラックシンボルが\n"
	.string "きんいろに　かがやいた！$"

	.globl gJPText_00235097
gJPText_00235097: @ 0x08235097
	.string "⋯⋯　⋯⋯　あんた⋯⋯\n"
	.string "いっしょう　わすれない　からね⋯⋯⋯$"

	.globl gJPText_002350B6
gJPText_002350B6: @ 0x082350B6
	.string "ようこそ　いらっしゃい　ました⋯⋯\p"
	.string "うふふ⋯⋯\n"
	.string "なんて　うんの　ない　おかた⋯⋯\p"
	.string "さいごに　えらんだのが\n"
	.string "このへやで　なければ　ポケモンたちを\l"
	.string "かいふくして　さしあげたのに⋯⋯$"

	.globl gJPText_0023510F
gJPText_0023510F: @ 0x0823510F
	.string "ようこそ　いらっしゃい　ました⋯⋯\p"
	.string "さいごに　このへやを　えらばれた\n"
	.string "おきゃくさまは　ポケモンを　1ひきだけ\l"
	.string "かいふくして　さしあげましょう⋯⋯$"

	.globl gJPText_00235158
gJPText_00235158: @ 0x08235158
	.string "ようこそ　いらっしゃい　ました⋯⋯\p"
	.string "さいごに　このへやを　えらばれた\n"
	.string "おきゃくさまは　ポケモンを　2ひき\l"
	.string "かいふくして　さしあげましょう⋯⋯$"

	.incbin "baserom_jp.gba", 0x23519f, 0x5f
	.globl gJPText_002351FE
gJPText_002351FE: @ 0x082351FE
	.string "では　わたくしどもの　あるじを\n"
	.string "よんで　まいり　ますね⋯⋯$"
