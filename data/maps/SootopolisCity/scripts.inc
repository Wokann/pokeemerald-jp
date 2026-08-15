@ SootopolisCity scripts (JP map g0 m7 @ 0x081E1CF6)

SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_EventScript_001E1D10
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_EventScript_001E1D89
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_EventScript_001E1FA5
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MapScriptTable_001E1FAE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_MapScriptTable_001E1F75
	.byte 0

SootopolisCity_EventScript_001E1D10::
	checkflag 0x9E
	call_if 0x0, SootopolisCity_EventScript_001E1D7F
	checkflag 0x81
	goto_if 0x0, SootopolisCity_EventScript_001E1D2C
	checkflag 0x9E
	call_if 0x0, SootopolisCity_EventScript_001E1D2D
	end

SootopolisCity_EventScript_001E1D2C::
	end

SootopolisCity_EventScript_001E1D2D::
	setmetatile 0x9, 0x6, 0x248, 0x1
	setmetatile 0x9, 0x11, 0x248, 0x1
	setmetatile 0x9, 0x1A, 0x248, 0x1
	setmetatile 0x2C, 0x11, 0x248, 0x1
	setmetatile 0x8, 0x23, 0x248, 0x1
	setmetatile 0x35, 0x1C, 0x248, 0x1
	setmetatile 0x2D, 0x6, 0x248, 0x1
	setmetatile 0x30, 0x19, 0x248, 0x1
	setmetatile 0x33, 0x24, 0x248, 0x1
	return

SootopolisCity_EventScript_001E1D7F::
	setmetatile 0x1F, 0x20, 0x250, 0x1
	return

SootopolisCity_EventScript_001E1D89::
	setflag 0x87D
	compare_var_to_value 0x405E, 0x1
	call_if 0x1, SootopolisCity_EventScript_001E1E1B
	compare_var_to_value 0x40CA, 0x1
	call_if 0x1, SootopolisCity_EventScript_001E1E1B
	call SootopolisCity_EventScript_001E1E9F
	call SootopolisCity_EventScript_001E1E4C
	compare_var_to_value 0x405E, 0x1
	call_if 0x1, SootopolisCity_EventScript_001E1E1F
	compare_var_to_value 0x405E, 0x2
	call_if 0x1, SootopolisCity_EventScript_001E1E1F
	compare_var_to_value 0x405E, 0x3
	call_if 0x1, SootopolisCity_EventScript_001E1E1F
	compare_var_to_value 0x405E, 0x4
	call_if 0x1, SootopolisCity_EventScript_001E1E1F
	compare_var_to_value 0x405E, 0x5
	call_if 0x1, SootopolisCity_EventScript_001E1E1F
	compare_var_to_value 0x405E, 0x2
	call_if 0x1, SootopolisCity_EventScript_001E1EDC
	compare_var_to_value 0x405E, 0x3
	call_if 0x1, SootopolisCity_EventScript_001E1EDC
	compare_var_to_value 0x405E, 0x4
	call_if 0x1, SootopolisCity_EventScript_001E1EF5
	compare_var_to_value 0x405E, 0x5
	call_if 0x1, SootopolisCity_EventScript_001E1F0B
	compare_var_to_value 0x405E, 0x6
	call_if 0x1, SootopolisCity_EventScript_001E1F6D
	end

SootopolisCity_EventScript_001E1E1B::
	setflag 0x4000
	return

SootopolisCity_EventScript_001E1E1F::
	setobjectxyperm 0x3, 0xD, 0x30
	setobjectxyperm 0x5, 0x2E, 0x20
	setobjectxyperm 0x4, 0x30, 0x29
	setobjectxyperm 0x8, 0x2D, 0x2B
	setobjectmovementtype 0x3, 0x7
	setobjectmovementtype 0x5, 0x9
	setobjectmovementtype 0x4, 0x9
	setobjectmovementtype 0x8, 0x9
	return

SootopolisCity_EventScript_001E1E4C::
	compare_var_to_value 0x405E, 0x0
	goto_if 0x1, SootopolisCity_EventScript_001E1E9A
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E1E9A
	compare_var_to_value 0x405E, 0x1
	goto_if 0x1, SootopolisCity_EventScript_001E1E9B
	compare_var_to_value 0x405E, 0x2
	goto_if 0x1, SootopolisCity_EventScript_001E1E9B
	compare_var_to_value 0x405E, 0x3
	goto_if 0x1, SootopolisCity_EventScript_001E1E9B
	compare_var_to_value 0x405E, 0x4
	goto_if 0x1, SootopolisCity_EventScript_001E1E9B
	compare_var_to_value 0x40CA, 0x1
	goto_if 0x3, SootopolisCity_EventScript_001E1E9B
	return

SootopolisCity_EventScript_001E1E9A::
	return

SootopolisCity_EventScript_001E1E9B::
	setmaplayoutindex 0x165
	return

SootopolisCity_EventScript_001E1E9F::
	compare_var_to_value 0x405E, 0x0
	goto_if 0x1, SootopolisCity_EventScript_001E1ED7
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E1ED7
	compare_var_to_value 0x405E, 0x1
	goto_if 0x1, SootopolisCity_EventScript_001E1ED8
	compare_var_to_value 0x40CA, 0x1
	goto_if 0x1, SootopolisCity_EventScript_001E1ED8
	compare_var_to_value 0x40CA, 0x1
	goto_if 0x3, 0x08243106
	return

SootopolisCity_EventScript_001E1ED7::
	return

SootopolisCity_EventScript_001E1ED8::
	setweather 0xD
	return

SootopolisCity_EventScript_001E1EDC::
	checkflag 0x133
	goto_if 0x1, SootopolisCity_EventScript_001E1EE6
	return

SootopolisCity_EventScript_001E1EE6::
	setobjectxyperm 0x1, 0x1E, 0x12
	setobjectxyperm 0x7, 0x20, 0x12
	return

SootopolisCity_EventScript_001E1EF5::
	setobjectxyperm 0x1, 0x1E, 0x12
	setobjectxyperm 0x12, 0x1F, 0x12
	setobjectxyperm 0x7, 0x20, 0x12
	end

SootopolisCity_EventScript_001E1F0B::
	setobjectxyperm 0x1, 0x1F, 0x12
	setobjectxyperm 0x7, 0x1D, 0x21
	setobjectxyperm 0x10, 0x21, 0x23
	setobjectxyperm 0x11, 0x22, 0x23
	compare_var_to_value 0x40D8, 0x0
	call_if 0x1, SootopolisCity_EventScript_001E1F49
	compare_var_to_value 0x40D8, 0x1
	call_if 0x1, SootopolisCity_EventScript_001E1F55
	compare_var_to_value 0x40D8, 0x2
	call_if 0x1, SootopolisCity_EventScript_001E1F61
	return

SootopolisCity_EventScript_001E1F49::
	setobjectxyperm 0x12, 0x1F, 0x21
	setobjectmovementtype 0x12, 0x8
	return

SootopolisCity_EventScript_001E1F55::
	setobjectxyperm 0x12, 0x20, 0x21
	setobjectmovementtype 0x12, 0x8
	return

SootopolisCity_EventScript_001E1F61::
	setobjectxyperm 0x12, 0x1E, 0x21
	setobjectmovementtype 0x12, 0x8
	return

SootopolisCity_EventScript_001E1F6D::
	setobjectxyperm 0x1, 0x1F, 0x12
	return

SootopolisCity_MapScriptTable_001E1F75::
	map_script_2 0x405E, 0x5, SootopolisCity_EventScript_001E1F7F
	.2byte 0

SootopolisCity_EventScript_001E1F7F::
	compare_var_to_value 0x40CA, 0x1
	call_if 0x1, SootopolisCity_EventScript_001E1F96
	compare_var_to_value 0x40CA, 0x2
	call_if 0x1, SootopolisCity_EventScript_001E1F9B
	end

SootopolisCity_EventScript_001E1F96::
	turnobject 0xFF, 0x2
	return

SootopolisCity_EventScript_001E1F9B::
	turnobject 0xFF, 0x2
	setvar 0x40CA, 0x3
	return

SootopolisCity_EventScript_001E1FA5::
	setdivewarp 0x1805, 0xFF, 0x9, 0x6
	end

SootopolisCity_MapScriptTable_001E1FAE::
	map_script_2 0x405E, 0x1, SootopolisCity_EventScript_001E1FC0
	map_script_2 0x40CA, 0x1, SootopolisCity_EventScript_001E2298
	.2byte 0

SootopolisCity_EventScript_001E1FC0::
	lockall
	special StorePlayerCoordsInVars
	compare_var_to_value 0x8004, 0x2B
	goto_if 0x5, SootopolisCity_EventScript_001E211C
	compare_var_to_value 0x8005, 0x20
	goto_if 0x5, SootopolisCity_EventScript_001E211C
	goto SootopolisCity_EventScript_001E1FE0
	end

SootopolisCity_EventScript_001E1FE0::
	delay 0x3C
	special SpawnCameraObject
	applymovement 0x7F, 0x081E2102
	waitmovement 0x0
	special RemoveCameraObject
	delay 0x3C
	fadescreenspeed 0x1, 0x8
	setweather 0xF
	resetweather
	setvar 0x8004, 0x0
	special sub_0813B810
	waitstate
	applymovement 0xA, 0x08243627
	applymovement 0x9, 0x0824362B
	waitmovement 0x0
	delay 0x3C
	waitse
	playmoncry 0x194, 0x2
	applymovement 0xA, 0x081E2252
	applymovement 0x9, 0x081E227F
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	applymovement 0xA, 0x081E2269
	applymovement 0x9, 0x081E228A
	waitmovement 0x0
	waitse
	playmoncry 0x195, 0x2
	applymovement 0xA, 0x081E225C
	applymovement 0x9, 0x081E2277
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	applymovement 0xA, 0x081E2269
	applymovement 0x9, 0x081E228A
	waitmovement 0x0
	waitse
	playmoncry 0x194, 0x2
	applymovement 0xA, 0x081E2252
	applymovement 0x9, 0x081E227F
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	applymovement 0xA, 0x081E2269
	applymovement 0x9, 0x081E228A
	waitmovement 0x0
	special SpawnCameraObject
	applymovement 0xA, 0x081E2270
	applymovement 0x9, 0x081E2291
	applymovement 0x7F, 0x081E210F
	waitmovement 0x0
	special RemoveCameraObject
	setvar 0x405E, 0x2
	clearflag 0x4000
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e2102, 0x1a
SootopolisCity_EventScript_001E211C::
	delay 0x3C
	special SpawnCameraObject
	applymovement 0x7F, 0x081E223E
	waitmovement 0x0
	special RemoveCameraObject
	delay 0x3C
	fadescreenspeed 0x1, 0x8
	setweather 0xF
	resetweather
	setvar 0x8004, 0x0
	special sub_0813B810
	waitstate
	applymovement 0xA, 0x08243627
	applymovement 0x9, 0x0824362B
	waitmovement 0x0
	delay 0x3C
	waitse
	playmoncry 0x194, 0x2
	applymovement 0xA, 0x081E2252
	applymovement 0x9, 0x081E227F
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	applymovement 0xA, 0x081E2269
	applymovement 0x9, 0x081E228A
	waitmovement 0x0
	waitse
	playmoncry 0x195, 0x2
	applymovement 0xA, 0x081E225C
	applymovement 0x9, 0x081E2277
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	applymovement 0xA, 0x081E2269
	applymovement 0x9, 0x081E228A
	waitmovement 0x0
	waitse
	playmoncry 0x194, 0x2
	applymovement 0xA, 0x081E2252
	applymovement 0x9, 0x081E227F
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	applymovement 0xA, 0x081E2269
	applymovement 0x9, 0x081E228A
	waitmovement 0x0
	special SpawnCameraObject
	applymovement 0xA, 0x081E2270
	applymovement 0x9, 0x081E2291
	applymovement 0x7F, 0x081E2248
	waitmovement 0x0
	special RemoveCameraObject
	setvar 0x405E, 0x2
	clearflag 0x4000
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e223e, 0x5a
SootopolisCity_EventScript_001E2298::
	lockall
	special StorePlayerCoordsInVars
	compare_var_to_value 0x8004, 0x2B
	goto_if 0x5, 0x081E2368
	compare_var_to_value 0x8005, 0x20
	goto_if 0x5, 0x081E2368
	goto 0x081E22B8
	end

	.incbin "baserom_jp.gba", 0x1e22b8, 0x26f
SootopolisCity_EventScript_001E2527::
	lock
	faceplayer
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E255E
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2568
	compare_var_to_value 0x405E, 0x2
	goto_if 0x4, SootopolisCity_EventScript_001E2554
	loadword 0x0, 0x081E305D
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2554::
	loadword 0x0, 0x081E30B4
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E255E::
	loadword 0x0, 0x081E3148
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2568::
	loadword 0x0, 0x081E311F
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2572::
	lock
	faceplayer
	compare_var_to_value 0x405E, 0x1
	goto_if 0x3, SootopolisCity_EventScript_001E25B5
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E25B5
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E25AA
	loadword 0x0, 0x081E2F96
	callstd 0x4
	closemessage
	applymovement 0x3, 0x08243625
	waitmovement 0x0
	release
	end

SootopolisCity_EventScript_001E25AA::
	loadword 0x0, 0x081E2FBE
	callstd 0x4
	closemessage
	release
	end

SootopolisCity_EventScript_001E25B5::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	checkflag 0x932
	goto_if 0x1, SootopolisCity_EventScript_001E2655
	loadword 0x0, 0x08263F33
	callstd 0x4
	random 0xA
	addvar 0x800D, 0x14
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x932
	loadword 0x0, 0x08263FB4
	callstd 0x4
	random 0x2
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SootopolisCity_EventScript_001E2613
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SootopolisCity_EventScript_001E2634
	end

SootopolisCity_EventScript_001E2613::
	setorcopyvar 0x8000, 0x8F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	loadword 0x0, 0x08263FD5
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2634::
	setorcopyvar 0x8000, 0x93
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	loadword 0x0, 0x08263FD5
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2655::
	loadword 0x0, 0x08263FF1
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SootopolisCity_EventScript_001E2672
	loadword 0x0, 0x0826404E
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2672::
	loadword 0x0, 0x08264025
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E267C::
	lockall
	applymovement 0x2, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E26A7
	loadword 0x0, 0x081E32A3
	callstd 0x4
	closemessage
	applymovement 0x2, 0x08243625
	waitmovement 0x0
	releaseall
	end

SootopolisCity_EventScript_001E26A7::
	loadword 0x0, 0x081E3326
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E26B1::
	lock
	faceplayer
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E26C8
	loadword 0x0, 0x081E2FFF
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E26C8::
	loadword 0x0, 0x081E304B
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E26D2::
	lock
	faceplayer
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E2714
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E271E
	compare_var_to_value 0x405E, 0x2
	goto_if 0x4, SootopolisCity_EventScript_001E26FF
	loadword 0x0, 0x081E317C
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E26FF::
	loadword 0x0, 0x081E31E2
	callstd 0x4
	closemessage
	applymovement 0x8, 0x08243625
	waitmovement 0x0
	release
	end

SootopolisCity_EventScript_001E2714::
	loadword 0x0, 0x081E324C
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E271E::
	loadword 0x0, 0x081E3217
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2728::
	lockall
	applymovement 0x4, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2773
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E2769
	compare_var_to_value 0x405E, 0x1
	goto_if 0x3, SootopolisCity_EventScript_001E2769
	loadword 0x0, 0x081E2E17
	callstd 0x4
	closemessage
	applymovement 0x4, 0x08243625
	waitmovement 0x0
	release
	end

SootopolisCity_EventScript_001E2769::
	loadword 0x0, 0x081E2DD3
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2773::
	loadword 0x0, 0x081E2E24
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E277D::
	lockall
	applymovement 0x5, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E27C7
	checkflag 0x864
	goto_if 0x1, SootopolisCity_EventScript_001E27D1
	compare_var_to_value 0x405E, 0x6
	goto_if 0x4, SootopolisCity_EventScript_001E27DB
	compare_var_to_value 0x405E, 0x1
	goto_if 0x3, SootopolisCity_EventScript_001E27DB
	loadword 0x0, 0x081E2C9A
	callstd 0x4
	closemessage
	applymovement 0x5, 0x08243625
	waitmovement 0x0
	release
	end

SootopolisCity_EventScript_001E27C7::
	loadword 0x0, 0x081E2D00
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E27D1::
	loadword 0x0, 0x081E2D1F
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E27DB::
	loadword 0x0, 0x081E2C5C
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E27E5::
	loadword 0x0, 0x081E2C09
	callstd 0x3
	end

SootopolisCity_EventScript_001E27EE::
	loadword 0x0, 0x081E2C31
	callstd 0x3
	end

EventScript_ClosedSootopolisDoor:: @ 0x081E27F7
	.incbin "baserom_jp.gba", 0x1e27f7, 0x9
SootopolisCity_EventScript_001E2800::
	lockall
	applymovement 0x7, 0x08243621
	waitmovement 0x0
	checkflag 0x133
	call_if 0x0, SootopolisCity_EventScript_001E2866
	compare_var_to_value 0x405E, 0x2
	goto_if 0x1, SootopolisCity_EventScript_001E2848
	compare_var_to_value 0x405E, 0x3
	goto_if 0x1, SootopolisCity_EventScript_001E285C
	compare_var_to_value 0x405E, 0x4
	goto_if 0x1, SootopolisCity_EventScript_001E285C
	checkflag 0x9E
	goto_if 0x1, SootopolisCity_EventScript_001E2852
	loadword 0x0, 0x081E36F0
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E2848::
	loadword 0x0, 0x081E369B
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E2852::
	loadword 0x0, 0x081E3726
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E285C::
	loadword 0x0, 0x081E36BF
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E2866::
	loadword 0x0, 0x081E350F
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, SootopolisCity_EventScript_001E28DD
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, SootopolisCity_EventScript_001E28EF
	loadword 0x0, 0x081E35DC
	callstd 0x4
	closemessage
	applymovement 0x7, 0x081E296E
	applymovement 0xFF, 0x081E29A8
	waitmovement 0x0
	delay 0x78
	applymovement 0x1, 0x081E29DB
	waitmovement 0x0
	applymovement 0x7, 0x081E29DE
	applymovement 0xFF, 0x081E29E9
	waitmovement 0x0
	loadword 0x0, 0x081E3656
	callstd 0x4
	closemessage
	setflag 0x133
	applymovement 0xFF, 0x081E29F4
	waitmovement 0x0
	warp 0x1825, 0xFF, 0x9, 0x14
	waitstate
	end

SootopolisCity_EventScript_001E28DD::
	applymovement 0x7, 0x081E2901
	applymovement 0xFF, 0x081E2926
	waitmovement 0x0
	return

SootopolisCity_EventScript_001E28EF::
	applymovement 0x7, 0x081E2901
	applymovement 0xFF, 0x081E294A
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1e2901, 0xf6
SootopolisCity_EventScript_001E29F7::
	lockall
	applymovement 0xF, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2A22
	loadword 0x0, 0x081E2D60
	callstd 0x4
	closemessage
	applymovement 0xF, 0x08243625
	waitmovement 0x0
	releaseall
	end

SootopolisCity_EventScript_001E2A22::
	loadword 0x0, 0x081E2DAA
	callstd 0x4
	closemessage
	releaseall
	end

SootopolisCity_EventScript_001E2A2D::
	lockall
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2A61
	loadword 0x0, 0x081E2E35
	callstd 0x4
	closemessage
	applymovement 0xE, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x081E2E55
	callstd 0x4
	closemessage
	applymovement 0xE, 0x08243625
	waitmovement 0x0
	releaseall
	end

SootopolisCity_EventScript_001E2A61::
	applymovement 0xE, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x081E2E7F
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E2A75::
	lockall
	applymovement 0xD, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2AA0
	loadword 0x0, 0x081E2FD7
	callstd 0x4
	closemessage
	applymovement 0xD, 0x08243625
	waitmovement 0x0
	releaseall
	end

SootopolisCity_EventScript_001E2AA0::
	loadword 0x0, 0x081E2FEB
	callstd 0x4
	closemessage
	releaseall
	end

SootopolisCity_EventScript_001E2AAB::
	lockall
	applymovement 0xC, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2AD6
	loadword 0x0, 0x081E2EC0
	callstd 0x4
	closemessage
	applymovement 0xC, 0x08243625
	waitmovement 0x0
	releaseall
	end

SootopolisCity_EventScript_001E2AD6::
	loadword 0x0, 0x081E2F2C
	callstd 0x4
	releaseall
	end

SootopolisCity_EventScript_001E2AE0::
	lock
	faceplayer
	compare_var_to_value 0x405E, 0x4
	goto_if 0x1, SootopolisCity_EventScript_001E2B72
	checkflag 0x138
	goto_if 0x1, SootopolisCity_EventScript_001E2B7C
	checkflag 0x9E
	goto_if 0x1, SootopolisCity_EventScript_001E2B09
	loadword 0x0, 0x081E37B8
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2B09::
	loadword 0x0, 0x081E380B
	callstd 0x4
	setorcopyvar 0x8000, 0x159
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x138
	loadword 0x0, 0x081E38A0
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, SootopolisCity_EventScript_001E2B4C
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, SootopolisCity_EventScript_001E2B4C
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, SootopolisCity_EventScript_001E2B5F
	release
	end

SootopolisCity_EventScript_001E2B4C::
	applymovement 0x12, 0x081E2B86
	waitmovement 0x0
	moveobjectoffscreen 0x12
	setvar 0x40D8, 0x1
	return

SootopolisCity_EventScript_001E2B5F::
	applymovement 0x12, 0x081E2B89
	waitmovement 0x0
	moveobjectoffscreen 0x12
	setvar 0x40D8, 0x2
	return

SootopolisCity_EventScript_001E2B72::
	loadword 0x0, 0x081E376F
	callstd 0x4
	release
	end

SootopolisCity_EventScript_001E2B7C::
	loadword 0x0, 0x081E3943
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1e2b86, 0x6
SootopolisCity_EventScript_001E2B8C::
	lockall
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2BA3
	loadword 0x0, 0x081E335D
	callstd 0x4
	closemessage
	releaseall
	end

SootopolisCity_EventScript_001E2BA3::
	loadword 0x0, 0x081E33BA
	callstd 0x4
	setflag 0x135
	checkflag 0x134
	goto_if 0x1, SootopolisCity_EventScript_001E2BE6
	releaseall
	end

SootopolisCity_EventScript_001E2BB9::
	lockall
	compare_var_to_value 0x405E, 0x5
	goto_if 0x1, SootopolisCity_EventScript_001E2BD0
	loadword 0x0, 0x081E343A
	callstd 0x4
	closemessage
	releaseall
	end

SootopolisCity_EventScript_001E2BD0::
	loadword 0x0, 0x081E3495
	callstd 0x4
	setflag 0x134
	checkflag 0x135
	goto_if 0x1, SootopolisCity_EventScript_001E2BE6
	releaseall
	end

SootopolisCity_EventScript_001E2BE6::
	setflag 0x33B
	setflag 0x33A
	setflag 0x9E
	clearflag 0x358
	clearflag 0x394
	setvar 0x40B9, 0x2
	warpsilent 0x7, 0xFF, 0x1F, 0x22
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1e2c05, 0xd74
