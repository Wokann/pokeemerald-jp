@ BattleFrontier_BattlePikeThreePathRoom scripts (JP map g26 m36 @ 0x08233CB9)

BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, 0x082746C7
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_MapScriptTable_00233CC9
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_MapScriptTable_00233CF3
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_MapScriptTable_00233CC9::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D07
	map_script_2 0x4000, 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D10
	map_script_2 0x4000, 0x2, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D1A
	map_script_2 0x4005, 0x0, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233EEE
	map_script_2 0x4005, 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F0D
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_MapScriptTable_00233CF3::
	map_script_2 0x4004, 0x0, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233CFD
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233CFD::
	setvar 0x4004, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D07::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D10::
	warp 0x1A22, 0xFF, 0x5, 0x6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D1A::
	lockall
	message gJPText_00234176
	waitmessage
	setvar 0x8004, 0x8
	setvar 0x8005, 0x1
	special CallBattlePikeFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_002341A6
	callstd 0x4
	closemessage
	releaseall
	setvar 0x8004, 0x5
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x63
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233D7E::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233DDE
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233DEE
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233DFE
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E0E
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E1E
	compare_var_to_value 0x8000, 0xB
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E2E
	compare_var_to_value 0x8000, 0xD
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E3E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233DDE::
	lock
	faceplayer
	loadword 0x0, 0x08234053
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233DEE::
	lock
	faceplayer
	loadword 0x0, 0x08234071
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233DFE::
	lock
	faceplayer
	loadword 0x0, 0x0823408F
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E0E::
	lock
	faceplayer
	loadword 0x0, 0x082340AD
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E1E::
	lock
	faceplayer
	loadword 0x0, 0x082340CB
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E2E::
	lock
	faceplayer
	loadword 0x0, 0x082340E9
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E3E::
	lock
	faceplayer
	loadword 0x0, 0x08234108
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E4E::
	loadword 0x0, 0x08234127
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233EA0
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233EA0
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E73::
	setvar 0x8004, 0x6
	special CallFrontierUtilFunc
	message 0x082341C3
	waitmessage
	special LoadPlayerParty
	setvar 0x8004, 0x8
	setvar 0x8005, 0x2
	special CallBattlePikeFunction
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233EA0::
	loadword 0x0, 0x0823413D
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233E73
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233ED0
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233ED0
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233ED0::
	message 0x08234158
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x082746AB
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233EEE::
	setvar 0x8004, 0x11
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F07
	setvar 0x4005, 0xFF
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F07::
	setvar 0x4005, 0x1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F0D::
	applymovement 0x2, 0x08234044
	waitmovement 0x0
	lockall
	loadword 0x0, gJPText_0023433C
	callstd 0x4
	releaseall
	applymovement 0x2, 0x0823404B
	waitmovement 0x0
	setvar 0x4005, 0xFF
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F31::
	setvar 0x8004, 0x13
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00234038
	lock
	faceplayer
	loadword 0x0, 0x08234201
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F80
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F76
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F76
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F76::
	loadword 0x0, 0x08234234
	callstd 0x4
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233F80::
	setvar 0x8004, 0x12
	special CallBattlePikeFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FAF
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FBC
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FC9
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FAF::
	loadword 0x0, 0x0823428F
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FD6

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FBC::
	loadword 0x0, 0x08234271
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FD6

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FC9::
	loadword 0x0, 0x08234253
	callstd 0x4
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FD6

BattleFrontier_BattlePikeThreePathRoom_EventScript_00233FD6::
	setvar 0x8004, 0x13
	special CallBattlePikeFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00234010
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_0023401A
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_00234024
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeThreePathRoom_EventScript_0023402E
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00234010::
	loadword 0x0, 0x08234318
	callstd 0x4
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_0023401A::
	loadword 0x0, 0x082342F8
	callstd 0x4
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00234024::
	loadword 0x0, 0x082342AE
	callstd 0x4
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_0023402E::
	loadword 0x0, 0x082342D2
	callstd 0x4
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_00234038::
	lock
	faceplayer
	loadword 0x0, 0x08234384
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x234044, 0x132
	.globl gJPText_00234176
gJPText_00234176: @ 0x08234176
	.string "おまちして　おりました⋯⋯\p"
	.string "バトルゲームを　さいかいする　まえに\n"
	.string "レポートを　かきましょう⋯⋯$"

	.globl gJPText_002341A6
gJPText_002341A6: @ 0x082341A6
	.string "それでは　ひきつづき\n"
	.string "ゲームを　おたのしみ　ください⋯⋯$"

	.incbin "baserom_jp.gba", 0x2341c3, 0x179
	.globl gJPText_0023433C
gJPText_0023433C: @ 0x0823433C
	.string "おきゃくさま⋯⋯\p"
	.string "このさき　たいへんに\n"
	.string "おそろしい　できごとが　おきゃくさまを\l"
	.string "まちうけている　でしょう⋯⋯\p"
	.string "かくごして　おいて　ください⋯⋯$"
