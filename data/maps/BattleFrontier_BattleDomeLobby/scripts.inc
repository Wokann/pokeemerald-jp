@ BattleFrontier_BattleDomeLobby scripts (JP map g26 m18 @ 0x08226D8C)

BattleFrontier_BattleDomeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_EventScript_00226D9C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_MapScriptTable_00226DB9
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_MapScriptTable_00226DA5
	.byte 0

BattleFrontier_BattleDomeLobby_EventScript_00226D9C::
	setvar 0x8004, 0x15
	special sub_0818E608
	end

BattleFrontier_BattleDomeLobby_MapScriptTable_00226DA5::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleDomeLobby_EventScript_00226DAF
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_00226DAF::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleDomeLobby_MapScriptTable_00226DB9::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleDomeLobby_EventScript_00226DE3
	map_script_2 0x4000, 0x1, BattleFrontier_BattleDomeLobby_EventScript_00226DEC
	map_script_2 0x4000, 0x2, BattleFrontier_BattleDomeLobby_EventScript_00226FA3
	map_script_2 0x4000, 0x3, BattleFrontier_BattleDomeLobby_EventScript_00226E45
	map_script_2 0x4000, 0x4, BattleFrontier_BattleDomeLobby_EventScript_00226EEA
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_00226DE3::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleDomeLobby_EventScript_00226DEC::
	lockall
	loadword 0x0, gJPText_002277D7
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_00226E45::
	call 0x08221FB3
	lockall
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00226E6B
	loadword 0x0, gJPText_00227828
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_00226E73

BattleFrontier_BattleDomeLobby_EventScript_00226E6B::
	loadword 0x0, gJPText_00227CCA
	callstd 0x4

BattleFrontier_BattleDomeLobby_EventScript_00226E73::
	loadword 0x0, gJPText_00227D04
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022189E
	callstd 0x9
	message gJPText_002278A7
	waitmessage
	special LoadPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x7
	setvar 0x8006, 0x1
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x1
	special sub_0818E608
	special LoadPlayerParty
	special HealPlayerParty
	goto BattleFrontier_BattleDomeLobby_EventScript_00226F3B

BattleFrontier_BattleDomeLobby_EventScript_00226EEA::
	lockall
	loadword 0x0, gJPText_0022789C
	callstd 0x4
	message gJPText_002278A7
	waitmessage
	special LoadPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special sub_0818E608
	special LoadPlayerParty
	special HealPlayerParty

BattleFrontier_BattleDomeLobby_EventScript_00226F3B::
	setvar 0x8004, 0xD
	setvar 0x8005, 0x0
	special sub_0818E608
	playse 0x37
	waitse
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00226F93
	message gJPText_00227D2E
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00226F93
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00226F8E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00226F93

BattleFrontier_BattleDomeLobby_EventScript_00226F8E::
	call 0x0821F8F5

BattleFrontier_BattleDomeLobby_EventScript_00226F93::
	loadword 0x0, gJPText_002274C6
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_00226FA3::
	lockall
	loadword 0x0, gJPText_002278C2
	callstd 0x4
	message gJPText_002278CE
	waitmessage
	setvar 0x8004, 0xD
	setvar 0x8005, 0x1
	special sub_0818E608
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	goto BattleFrontier_BattleDomeLobby_EventScript_0022716C

BattleFrontier_BattleDomeLobby_EventScript_00226FDF::
	lock
	faceplayer
	setvar 0x40CF, 0x1
	setvar 0x40CE, 0x0
	goto BattleFrontier_BattleDomeLobby_EventScript_00227003
	end

BattleFrontier_BattleDomeLobby_EventScript_00226FF1::
	lock
	faceplayer
	setvar 0x40CF, 0x1
	setvar 0x40CE, 0x1
	goto BattleFrontier_BattleDomeLobby_EventScript_00227003
	end

BattleFrontier_BattleDomeLobby_EventScript_00227003::
	special SavePlayerParty
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272A7
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272B0

BattleFrontier_BattleDomeLobby_EventScript_0022701C::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272B9
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272BF
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227069
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002271A4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720E

BattleFrontier_BattleDomeLobby_EventScript_00227069::
	message 0x0822764D
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720E
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002271BF
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822767D
	callstd 0x4
	fadescreen 0x1
	call 0x082202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720B
	loadword 0x0, 0x08227624
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720B
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022710A
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022720B

BattleFrontier_BattleDomeLobby_EventScript_0022710A::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special sub_0818E608
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002271F4
	setvar 0x8004, 0x16
	special sub_0818E608

BattleFrontier_BattleDomeLobby_EventScript_0022716C::
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	setvar 0x8004, 0xF
	special sub_0818E608
	loadword 0x0, gJPText_002277BF
	callstd 0x4
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_00227218
	special HealPlayerParty
	warp 0x1A13, 0xFF, 0x17, 0x6
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_002271A4::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272C5
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272CE
	goto BattleFrontier_BattleDomeLobby_EventScript_0022701C

BattleFrontier_BattleDomeLobby_EventScript_002271BF::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002271DA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002271E7

BattleFrontier_BattleDomeLobby_EventScript_002271DA::
	loadword 0x0, 0x08227711
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_00227216

BattleFrontier_BattleDomeLobby_EventScript_002271E7::
	loadword 0x0, 0x0822769C
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_00227216

BattleFrontier_BattleDomeLobby_EventScript_002271F4::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleDomeLobby_EventScript_0022720E

BattleFrontier_BattleDomeLobby_EventScript_0022720B::
	special LoadPlayerParty

BattleFrontier_BattleDomeLobby_EventScript_0022720E::
	loadword 0x0, gJPText_002274C6
	callstd 0x4

BattleFrontier_BattleDomeLobby_EventScript_00227216::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_00227218::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227287
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022728F
	applymovement 0xFF, 0x082272EF
	waitmovement 0x0
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272D7
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272DD
	waitmoncry
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227297
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022729F
	applymovement 0xFF, 0x082272F8
	waitmovement 0x0
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272E3
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_002272E9
	waitmoncry
	return

BattleFrontier_BattleDomeLobby_EventScript_00227287::
	applymovement 0x1, 0x082272EF
	return

BattleFrontier_BattleDomeLobby_EventScript_0022728F::
	applymovement 0x6, 0x082272EF
	return

BattleFrontier_BattleDomeLobby_EventScript_00227297::
	applymovement 0x1, 0x082272F5
	return

BattleFrontier_BattleDomeLobby_EventScript_0022729F::
	applymovement 0x6, 0x082272F5
	return

BattleFrontier_BattleDomeLobby_EventScript_002272A7::
	loadword 0x0, 0x08227461
	callstd 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272B0::
	loadword 0x0, 0x082278F7
	callstd 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272B9::
	message 0x082274AA
	return

BattleFrontier_BattleDomeLobby_EventScript_002272BF::
	message 0x0822793F
	return

BattleFrontier_BattleDomeLobby_EventScript_002272C5::
	loadword 0x0, 0x082274DB
	callstd 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272CE::
	loadword 0x0, 0x0822795A
	callstd 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272D7::
	opendoor 0x5, 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272DD::
	opendoor 0x11, 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272E3::
	closedoor 0x5, 0x4
	return

BattleFrontier_BattleDomeLobby_EventScript_002272E9::
	closedoor 0x11, 0x4
	return

	.incbin "baserom_jp.gba", 0x2272ef, 0xd
BattleFrontier_BattleDomeLobby_EventScript_002272FC::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_00227315::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x1
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_0022732E::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x9
	special sub_0818E608
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227373
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022737C
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227385
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022738E
	fadescreen 0x1
	setvar 0x8004, 0x8
	special sub_0818E608
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_00227373::
	loadword 0x0, 0x08227AB0
	callstd 0x3
	return

BattleFrontier_BattleDomeLobby_EventScript_0022737C::
	loadword 0x0, 0x08227AD8
	callstd 0x3
	return

BattleFrontier_BattleDomeLobby_EventScript_00227385::
	loadword 0x0, 0x08227AFF
	callstd 0x3
	return

BattleFrontier_BattleDomeLobby_EventScript_0022738E::
	loadword 0x0, 0x08227B29
	callstd 0x3
	return

BattleFrontier_BattleDomeLobby_EventScript_00227397::
	setvar 0x8004, 0x14
	special sub_0818E608
	loadword 0x0, 0x08227B52
	callstd 0x2
	end

BattleFrontier_BattleDomeLobby_EventScript_002273A8::
	loadword 0x0, 0x08227BF7
	callstd 0x2
	end

BattleFrontier_BattleDomeLobby_EventScript_002273B1::
	loadword 0x0, 0x08227C4A
	callstd 0x2
	end

BattleFrontier_BattleDomeLobby_EventScript_002273BA::
	loadword 0x0, 0x08227C79
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x2273c3, 0x1b
BattleFrontier_BattleDomeLobby_EventScript_002273DE::
	lockall
	loadword 0x0, 0x08227D5C
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_002273ED
	end

BattleFrontier_BattleDomeLobby_EventScript_002273ED::
	message 0x08227D74
	waitmessage
	multichoice 0x11, 0x4, 0x62, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227435
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227443
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_00227451
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022745F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomeLobby_EventScript_0022745F
	end

BattleFrontier_BattleDomeLobby_EventScript_00227435::
	loadword 0x0, 0x08227D84
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_002273ED
	end

BattleFrontier_BattleDomeLobby_EventScript_00227443::
	loadword 0x0, 0x08227DDA
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_002273ED
	end

BattleFrontier_BattleDomeLobby_EventScript_00227451::
	loadword 0x0, 0x08227E6C
	callstd 0x4
	goto BattleFrontier_BattleDomeLobby_EventScript_002273ED
	end

BattleFrontier_BattleDomeLobby_EventScript_0022745F::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x227461, 0x65
	.globl gJPText_002274C6
gJPText_002274C6: @ 0x082274C6
	.string "またの　ごりようを　おまちして　おります$"

	.incbin "baserom_jp.gba", 0x2274db, 0x2e4
	.globl gJPText_002277BF
gJPText_002277BF: @ 0x082277BF
	.string "それでは　バトルドームへ\n"
	.string "ごあんない　します！$"

	.globl gJPText_002277D7
gJPText_002277D7: @ 0x082277D7
	.string "おきゃくさま！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたね？\p"
	.string "もうしわけ　ありませんが　そのばあい\n"
	.string "ちょうせんは　むこうと　なります$"

	.globl gJPText_00227828
gJPText_00227828: @ 0x08227828
	.string "バトルトーナメント　ゆうしょう\n"
	.string "おめでとう　ございます！$"

	.incbin "baserom_jp.gba", 0x227845, 0x20
	.globl gJPText_00227865
gJPText_00227865: @ 0x08227865
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "{B_COPY_VAR_1}を　もらった！$"

	.incbin "baserom_jp.gba", 0x227873, 0x29
	.globl gJPText_0022789C
gJPText_0022789C: @ 0x0822789C
	.string "おつかれさまでした！$"

	.globl gJPText_002278A7
gJPText_002278A7: @ 0x082278A7
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちください$"

	.globl gJPText_002278C2
gJPText_002278C2: @ 0x082278C2
	.string "おまちしておりました！$"

	.globl gJPText_002278CE
gJPText_002278CE: @ 0x082278CE
	.string "バトルドームに　ごあんないする　まえに\n"
	.string "レポートを　かきますので　おまちください$"

	.incbin "baserom_jp.gba", 0x2278f7, 0x3d3
	.globl gJPText_00227CCA
gJPText_00227CCA: @ 0x08227CCA
	.string "おめでとう　ございます！\p"
	.string "みごと　ドームスーパースターを　たおし\n"
	.string "バトルトーナメントに\l"
	.string "ゆうしょう　されましたね！$"

	.globl gJPText_00227D04
gJPText_00227D04: @ 0x08227D04
	.string "おきゃくさまの\n"
	.string "うつくしい　せんりゃくを　たたえ\l"
	.string "バトルポイントを　さしあげます！$"

	.globl gJPText_00227D2E
gJPText_00227D2E: @ 0x08227D2E
	.string "バトルドームで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　されますか？$"

	.incbin "baserom_jp.gba", 0x227d5c, 0x16d
