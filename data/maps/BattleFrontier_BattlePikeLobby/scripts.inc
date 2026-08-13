@ BattleFrontier_BattlePikeLobby scripts (JP map g26 m34 @ 0x0823309D)

BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_MapScriptTable_002330A8
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_MapScriptTable_002330CA
	.byte 0

BattleFrontier_BattlePikeLobby_MapScriptTable_002330A8::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePikeLobby_EventScript_002330DE
	map_script_2 0x4000, 0x1, BattleFrontier_BattlePikeLobby_EventScript_002330E7
	map_script_2 0x4000, 0x3, BattleFrontier_BattlePikeLobby_EventScript_00233139
	map_script_2 0x4000, 0x4, BattleFrontier_BattlePikeLobby_EventScript_002331DD
	.2byte 0

BattleFrontier_BattlePikeLobby_MapScriptTable_002330CA::
	map_script_2 0x4001, 0x0, BattleFrontier_BattlePikeLobby_EventScript_002330D4
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_002330D4::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattlePikeLobby_EventScript_002330DE::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePikeLobby_EventScript_002330E7::
	special HealPlayerParty
	setvar 0x8004, 0x1B
	special CallBattlePikeFunction
	lockall
	loadword 0x0, gJPText_002339B7
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallBattlePikeFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	setvar 0x8006, 0x0
	special CallBattlePikeFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_00233139::
	lockall
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023315B
	loadword 0x0, gJPText_00233903
	callstd 0x4
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_00233164

BattleFrontier_BattlePikeLobby_EventScript_0023315B::
	loadword 0x0, gJPText_00233A0B
	callstd 0x4
	waitmessage

BattleFrontier_BattlePikeLobby_EventScript_00233164::
	loadword 0x0, gJPText_00233A3E
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022189E
	callstd 0x9
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	special CallBattlePikeFunction
	addvar 0x800D, 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	copyvar 0x8006, 0x800D
	special CallBattlePikeFunction
	special LoadPlayerParty
	special HealPlayerParty
	setvar 0x8004, 0x1B
	special CallBattlePikeFunction
	message gJPText_00233931
	waitmessage
	setvar 0x8004, 0x8
	setvar 0x8005, 0x0
	special CallBattlePikeFunction
	playse 0x37
	waitse
	loadword 0x0, gJPText_002336C9
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_002331DD::
	lockall
	message gJPText_002338CC
	waitmessage
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	setvar 0x8006, 0x0
	special CallBattlePikeFunction
	special LoadPlayerParty
	special HealPlayerParty
	setvar 0x8004, 0x1B
	special CallBattlePikeFunction
	setvar 0x8004, 0x8
	setvar 0x8005, 0x0
	special CallBattlePikeFunction
	playse 0x37
	waitse
	loadword 0x0, gJPText_002336C9
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_0023323F::
	lock
	faceplayer
	setvar 0x40CF, 0x5
	setvar 0x40CE, 0x0
	special SavePlayerParty
	loadword 0x0, 0x08233529
	callstd 0x4

BattleFrontier_BattlePikeLobby_EventScript_00233256::
	message 0x0823356B
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233292
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_002333F1
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344D
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344D

BattleFrontier_BattlePikeLobby_EventScript_00233292::
	message 0x082336E2
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344D
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344D
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_002333FE
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0823386E
	callstd 0x4
	fadescreen 0x1
	call 0x082202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344A
	loadword 0x0, 0x08233896
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233333
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023344A

BattleFrontier_BattlePikeLobby_EventScript_00233333::
	setvar 0x4000, 0x0
	setvar 0x4001, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x1C
	special CallBattlePikeFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	setvar 0x8006, 0x1
	special CallBattlePikeFunction
	setvar 0x8004, 0x1A
	special CallBattlePikeFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	setvar 0x8004, 0x1A
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233433
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, 0x082338BE
	callstd 0x4
	closemessage
	setvar 0x8004, 0x5
	special CallFrontierUtilFunc
	call BattleFrontier_BattlePikeLobby_EventScript_0023346B
	special HealPlayerParty
	call BattleFrontier_BattlePikeLobby_EventScript_00233520
	warpsilent 0x1A23, 0xFF, 0x6, 0x7
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_002333F1::
	loadword 0x0, 0x08233582
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_00233256

BattleFrontier_BattlePikeLobby_EventScript_002333FE::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233419
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233426

BattleFrontier_BattlePikeLobby_EventScript_00233419::
	loadword 0x0, 0x08233707
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_00233455

BattleFrontier_BattlePikeLobby_EventScript_00233426::
	loadword 0x0, 0x082337C0
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_00233455

BattleFrontier_BattlePikeLobby_EventScript_00233433::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePikeLobby_EventScript_0023344D

BattleFrontier_BattlePikeLobby_EventScript_0023344A::
	special LoadPlayerParty

BattleFrontier_BattlePikeLobby_EventScript_0023344D::
	loadword 0x0, gJPText_002336C9
	callstd 0x4

BattleFrontier_BattlePikeLobby_EventScript_00233455::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_00233457::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x5
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_0023346B::
	applymovement 0x1, 0x0823347E
	applymovement 0xFF, 0x0823347D
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x23347d, 0x5
BattleFrontier_BattlePikeLobby_EventScript_00233482::
	loadword 0x0, 0x08233A64
	callstd 0x2
	end

BattleFrontier_BattlePikeLobby_EventScript_0023348B::
	loadword 0x0, 0x08233AA9
	callstd 0x2
	end

BattleFrontier_BattlePikeLobby_EventScript_00233494::
	loadword 0x0, 0x08233AD9
	callstd 0x2
	end

BattleFrontier_BattlePikeLobby_EventScript_0023349D::
	lockall
	loadword 0x0, 0x08233B48
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_002334AC
	end

BattleFrontier_BattlePikeLobby_EventScript_002334AC::
	message 0x08233B5D
	waitmessage
	multichoice 0x10, 0x4, 0x66, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_002334F4
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233502
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_00233510
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023351E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePikeLobby_EventScript_0023351E
	end

BattleFrontier_BattlePikeLobby_EventScript_002334F4::
	loadword 0x0, 0x08233B6D
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_002334AC
	end

BattleFrontier_BattlePikeLobby_EventScript_00233502::
	loadword 0x0, 0x08233B95
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_002334AC
	end

BattleFrontier_BattlePikeLobby_EventScript_00233510::
	loadword 0x0, 0x08233BC7
	callstd 0x4
	goto BattleFrontier_BattlePikeLobby_EventScript_002334AC
	end

BattleFrontier_BattlePikeLobby_EventScript_0023351E::
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_00233520::
	playse 0x10B
	special sub_0813B8B8
	waitstate
	waitse
	return

	.incbin "baserom_jp.gba", 0x233529, 0x1a0
	.globl gJPText_002336C9
gJPText_002336C9: @ 0x082336C9
	.string "では　またの　きかいを\n"
	.string "おまちして　おります⋯⋯$"

	.incbin "baserom_jp.gba", 0x2336e2, 0x1ea
	.globl gJPText_002338CC
gJPText_002338CC: @ 0x082338CC
	.string "ゲーム　しゅうりょう　ですね⋯⋯\p"
	.string "せいせきを　レポートに　かきましょう⋯⋯\n"
	.string "しょうしょう　おまちください⋯⋯$"

	.globl gJPText_00233903
gJPText_00233903: @ 0x08233903
	.string "ゲーム　クリア　ですね⋯⋯\p"
	.string "おきゃくさま⋯⋯　なかなかの　うんを\n"
	.string "おもちの　ようですね⋯⋯$"

	.globl gJPText_00233931
gJPText_00233931: @ 0x08233931
	.string "せいせきを　レポートに　かきましょう⋯⋯\n"
	.string "しばらく　おまちください⋯⋯$"

	.incbin "baserom_jp.gba", 0x233955, 0x62
	.globl gJPText_002339B7
gJPText_002339B7: @ 0x082339B7
	.string "おきゃくさま⋯⋯\p"
	.string "ぜんかい　きちんと　レポートを　かかずに\n"
	.string "しゅうりょう　されましたね⋯⋯\p"
	.string "もうしわけ　ありませんが　ちょうせんは\n"
	.string "むこうと　させて　いただきます⋯⋯$"

	.globl gJPText_00233A0B
gJPText_00233A0B: @ 0x08233A0B
	.string "⋯⋯　おめでとう　ございます⋯⋯\n"
	.string "チューブクイーンに　しょうりし\l"
	.string "ゲームを　クリア　されましたね⋯⋯$"

	.globl gJPText_00233A3E
gJPText_00233A3E: @ 0x08233A3E
	.string "おきゃくさまの　つよき　うんを　たたえ\n"
	.string "バトルポイントを　さしあげます⋯⋯$"

	.incbin "baserom_jp.gba", 0x233a64, 0x19d
