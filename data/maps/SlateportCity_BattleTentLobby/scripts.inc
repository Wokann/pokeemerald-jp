@ SlateportCity_BattleTentLobby scripts (JP map g9 m2 @ 0x081FB033)

SlateportCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_MapScriptTable_001FB052
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_MapScriptTable_001FB03E
	.byte 0

SlateportCity_BattleTentLobby_MapScriptTable_001FB03E::
	map_script_2 0x4001, 0x0, SlateportCity_BattleTentLobby_EventScript_001FB048
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_001FB048::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

SlateportCity_BattleTentLobby_MapScriptTable_001FB052::
	map_script_2 0x4000, 0x0, SlateportCity_BattleTentLobby_EventScript_001FB07C
	map_script_2 0x4000, 0x1, SlateportCity_BattleTentLobby_EventScript_001FB085
	map_script_2 0x4000, 0x2, SlateportCity_BattleTentLobby_EventScript_001FB174
	map_script_2 0x4000, 0x3, SlateportCity_BattleTentLobby_EventScript_001FB0BA
	map_script_2 0x4000, 0x4, SlateportCity_BattleTentLobby_EventScript_001FB13A
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_001FB07C::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

SlateportCity_BattleTentLobby_EventScript_001FB085::
	lockall
	loadword 0x0, gJPText_00275660
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_001FB0BA::
	lockall
	message gJPText_00275596
	waitmessage
	setvar 0x8004, 0x4
	special CallSlateportTentFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallSlateportTentFunction
	playse 0x37
	waitse

SlateportCity_BattleTentLobby_EventScript_001FB0EC::
	loadword 0x0, gJPText_002755EC
	callstd 0x4
	setvar 0x8004, 0x5
	special CallSlateportTentFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB12D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	message gJPText_0022064B
	waitmessage
	playfanfare 0x172
	waitfanfare
	goto SlateportCity_BattleTentLobby_EventScript_001FB164

SlateportCity_BattleTentLobby_EventScript_001FB12D::
	loadword 0x0, gJPText_00275607
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB164

SlateportCity_BattleTentLobby_EventScript_001FB13A::
	lockall
	message gJPText_00275524
	waitmessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallSlateportTentFunction
	playse 0x37
	waitse

SlateportCity_BattleTentLobby_EventScript_001FB164::
	loadword 0x0, gJPText_0027549D
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_001FB174::
	lockall
	message gJPText_00275634
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x1
	special CallSlateportTentFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	setvar 0x8006, 0x2
	goto SlateportCity_BattleTentLobby_EventScript_001FB2AF

SlateportCity_BattleTentLobby_EventScript_001FB1AD::
	lock
	faceplayer
	setvar 0x8004, 0x1
	special CallSlateportTentFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, SlateportCity_BattleTentLobby_EventScript_001FB0EC
	special SavePlayerParty
	loadword 0x0, 0x08275307
	callstd 0x4

SlateportCity_BattleTentLobby_EventScript_001FB1CD::
	message 0x08275335
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB209
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB30A
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB331
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB331

SlateportCity_BattleTentLobby_EventScript_001FB209::
	setvar 0x40CF, 0x4
	setvar 0x40CE, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x2
	special CallFrontierUtilFunc
	loadword 0x0, 0x082754D7
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB32E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB253
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB32E

SlateportCity_BattleTentLobby_EventScript_001FB253::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special CallSlateportTentFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB317
	setvar 0x8006, 0x0

SlateportCity_BattleTentLobby_EventScript_001FB2AF::
	loadword 0x0, gJPText_00275515
	callstd 0x4
	closemessage
	call SlateportCity_BattleTentLobby_EventScript_001FB2CC
	warp 0x903, 0xFF, 0x2, 0x7
	setvar 0x4000, 0x0
	waitstate
	end

SlateportCity_BattleTentLobby_EventScript_001FB2CC::
	applymovement 0x1, 0x081FB2FB
	applymovement 0xFF, 0x081FB302
	waitmovement 0x0
	opendoor 0x6, 0x1
	waitmoncry
	applymovement 0x1, 0x081FB2FF
	applymovement 0xFF, 0x081FB306
	waitmovement 0x0
	closedoor 0x6, 0x1
	waitmoncry
	return

	.incbin "baserom_jp.gba", 0x1fb2fb, 0xf
SlateportCity_BattleTentLobby_EventScript_001FB30A::
	loadword 0x0, 0x0827534A
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB1CD

SlateportCity_BattleTentLobby_EventScript_001FB317::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto SlateportCity_BattleTentLobby_EventScript_001FB331

SlateportCity_BattleTentLobby_EventScript_001FB32E::
	special LoadPlayerParty

SlateportCity_BattleTentLobby_EventScript_001FB331::
	loadword 0x0, gJPText_0027549D
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1fb33b, 0x5
SlateportCity_BattleTentLobby_EventScript_001FB340::
	lock
	faceplayer
	checkflag 0x109
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB377
	loadword 0x0, 0x081FB451
	callstd 0x4
	setorcopyvar 0x8000, 0x149
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x109
	loadword 0x0, 0x081FB4C1
	callstd 0x4
	release
	end

SlateportCity_BattleTentLobby_EventScript_001FB377::
	loadword 0x0, 0x081FB4C1
	callstd 0x4
	release
	end

SlateportCity_BattleTentLobby_EventScript_001FB381::
	loadword 0x0, 0x081FB516
	callstd 0x2
	end

SlateportCity_BattleTentLobby_EventScript_001FB38A::
	loadword 0x0, 0x081FB54A
	callstd 0x2
	end

SlateportCity_BattleTentLobby_EventScript_001FB393::
	loadword 0x0, 0x081FB570
	callstd 0x2
	end

SlateportCity_BattleTentLobby_EventScript_001FB39C::
	lockall
	loadword 0x0, 0x08231A91
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB3AB
	end

SlateportCity_BattleTentLobby_EventScript_001FB3AB::
	message 0x08231AA7
	waitmessage
	multichoice 0x11, 0x0, 0x6F, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB409
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB417
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB425
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB433
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB441
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB44F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_BattleTentLobby_EventScript_001FB44F
	end

SlateportCity_BattleTentLobby_EventScript_001FB409::
	loadword 0x0, 0x082756F3
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB3AB
	end

SlateportCity_BattleTentLobby_EventScript_001FB417::
	loadword 0x0, 0x08275757
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB3AB
	end

SlateportCity_BattleTentLobby_EventScript_001FB425::
	loadword 0x0, 0x082757A8
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB3AB
	end

SlateportCity_BattleTentLobby_EventScript_001FB433::
	loadword 0x0, 0x08275803
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB3AB
	end

SlateportCity_BattleTentLobby_EventScript_001FB441::
	loadword 0x0, 0x0827589C
	callstd 0x4
	goto SlateportCity_BattleTentLobby_EventScript_001FB3AB
	end

SlateportCity_BattleTentLobby_EventScript_001FB44F::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1fb451, 0x143
