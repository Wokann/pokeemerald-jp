@ BattleFrontier_BattleArenaLobby scripts (JP map g26 m28 @ 0x0822F1C9)

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_MapScriptTable_0022F1E8
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_MapScriptTable_0022F1D4
	.byte 0

BattleFrontier_BattleArenaLobby_MapScriptTable_0022F1D4::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleArenaLobby_EventScript_0022F1DE
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_0022F1DE::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleArenaLobby_MapScriptTable_0022F1E8::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleArenaLobby_EventScript_0022F212
	map_script_2 0x4000, 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F21B
	map_script_2 0x4000, 0x2, BattleFrontier_BattleArenaLobby_EventScript_0022F353
	map_script_2 0x4000, 0x3, BattleFrontier_BattleArenaLobby_EventScript_0022F262
	map_script_2 0x4000, 0x4, BattleFrontier_BattleArenaLobby_EventScript_0022F2BE
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_0022F212::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F21B::
	lockall
	loadword 0x0, gJPText_0022FAC1
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallBattleArenaFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattleArenaFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F262::
	lockall
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F283
	loadword 0x0, gJPText_0022FB23
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F28B

BattleFrontier_BattleArenaLobby_EventScript_0022F283::
	loadword 0x0, gJPText_00230023
	callstd 0x4

BattleFrontier_BattleArenaLobby_EventScript_0022F28B::
	loadword 0x0, gJPText_00230058
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022189E
	callstd 0x9
	message gJPText_0022FB3C
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_0022F2EC
	loadword 0x0, gJPText_0022FBE9
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F2BE::
	lockall
	message gJPText_0022FBC2
	waitmessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattleArenaFunction
	call BattleFrontier_BattleArenaLobby_EventScript_0022F2EC
	loadword 0x0, gJPText_0022FBE9
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F2EC::
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallBattleArenaFunction
	playse 0x37
	waitse
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F352
	message gJPText_0022FC36
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F352
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F34D
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F352

BattleFrontier_BattleArenaLobby_EventScript_0022F34D::
	call 0x0821F8F5

BattleFrontier_BattleArenaLobby_EventScript_0022F352::
	return

BattleFrontier_BattleArenaLobby_EventScript_0022F353::
	lockall
	message gJPText_0022FC01
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x1
	special CallBattleArenaFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F4E7

BattleFrontier_BattleArenaLobby_EventScript_0022F387::
	lock
	faceplayer
	setvar 0x40CF, 0x3
	setvar 0x40CE, 0x0
	special SavePlayerParty
	loadword 0x0, 0x0822F6F9
	callstd 0x4

BattleFrontier_BattleArenaLobby_EventScript_0022F39E::
	message 0x0822F747
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F3DA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F532
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58E

BattleFrontier_BattleArenaLobby_EventScript_0022F3DA::
	message 0x0822F904
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58E
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F53F
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822F933
	callstd 0x4
	fadescreen 0x1
	call 0x082202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58B
	loadword 0x0, 0x0822F8DB
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58B
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F47B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F58B

BattleFrontier_BattleArenaLobby_EventScript_0022F47B::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special CallBattleArenaFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special CallBattleArenaFunction
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
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F574

BattleFrontier_BattleArenaLobby_EventScript_0022F4E7::
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022FAAA
	callstd 0x4
	closemessage
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F598
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F5E3
	warp 0x1A1D, 0xFF, 0x9, 0xD
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F532::
	loadword 0x0, 0x0822F776
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F39E

BattleFrontier_BattleArenaLobby_EventScript_0022F53F::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F55A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F567

BattleFrontier_BattleArenaLobby_EventScript_0022F55A::
	loadword 0x0, 0x0822F9F8
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F596

BattleFrontier_BattleArenaLobby_EventScript_0022F567::
	loadword 0x0, 0x0822F951
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F596

BattleFrontier_BattleArenaLobby_EventScript_0022F574::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F58E

BattleFrontier_BattleArenaLobby_EventScript_0022F58B::
	special LoadPlayerParty

BattleFrontier_BattleArenaLobby_EventScript_0022F58E::
	loadword 0x0, 0x0822F75E
	callstd 0x4

BattleFrontier_BattleArenaLobby_EventScript_0022F596::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F598::
	applymovement 0x1, 0x0822F5C7
	applymovement 0xFF, 0x0822F5D4
	waitmovement 0x0
	opendoor 0x2, 0x2
	waitmoncry
	applymovement 0x1, 0x0822F5D1
	applymovement 0xFF, 0x0822F5DF
	waitmovement 0x0
	closedoor 0x2, 0x2
	waitmoncry
	return

	.incbin "baserom_jp.gba", 0x22f5c7, 0x1c
BattleFrontier_BattleArenaLobby_EventScript_0022F5E3::
	applymovement 0x1, 0x0822F612
	applymovement 0xFF, 0x0822F61B
	waitmovement 0x0
	opendoor 0xB, 0x2
	waitmoncry
	applymovement 0x1, 0x0822F5D1
	applymovement 0xFF, 0x0822F5DF
	waitmovement 0x0
	closedoor 0xB, 0x2
	waitmoncry
	return

	.incbin "baserom_jp.gba", 0x22f612, 0x13
BattleFrontier_BattleArenaLobby_EventScript_0022F625::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F639::
	loadword 0x0, 0x0822FC66
	callstd 0x2
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F642::
	loadword 0x0, 0x0822FC95
	callstd 0x2
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F64B::
	loadword 0x0, 0x0822FCC3
	callstd 0x2
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F654::
	loadword 0x0, 0x0822FD06
	callstd 0x2
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F65D::
	lockall
	loadword 0x0, 0x0822FD87
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F66C
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F66C::
	message 0x0822FDA0
	waitmessage
	multichoice 0x11, 0x2, 0x60, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F6BF
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F6CD
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F6DB
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F6E9
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F6F7
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleArenaLobby_EventScript_0022F6F7
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F6BF::
	loadword 0x0, 0x0822FDB0
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F66C
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F6CD::
	loadword 0x0, 0x0822FE72
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F66C
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F6DB::
	loadword 0x0, 0x0822FECB
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F66C
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F6E9::
	loadword 0x0, 0x0822FFB6
	callstd 0x4
	goto BattleFrontier_BattleArenaLobby_EventScript_0022F66C
	end

BattleFrontier_BattleArenaLobby_EventScript_0022F6F7::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x22f6f9, 0x3b1
	.globl gJPText_0022FAAA
gJPText_0022FAAA: @ 0x0822FAAA
	.string "では　バトルアリーナへ\n"
	.string "おつれいたしますぞ！$"

	.globl gJPText_0022FAC1
gJPText_0022FAC1: @ 0x0822FAC1
	.string "おきゃくじん！\p"
	.string "ぜんかい　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたな？\p"
	.string "ざんねんですが　その　ばあい\n"
	.string "ちょうせんは　むこうと　なりますぞ！\p"
	.string "また　はじめから\n"
	.string "ちょうせん　してくだされ！！$"

	.globl gJPText_0022FB23
gJPText_0022FB23: @ 0x0822FB23
	.string "7にんぬき　たっせい\n"
	.string "おみごとで　ございました！$"

	.globl gJPText_0022FB3C
gJPText_0022FB3C: @ 0x0822FB3C
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちくだされ！$"

	.incbin "baserom_jp.gba", 0x22fb58, 0x6a
	.globl gJPText_0022FBC2
gJPText_0022FBC2: @ 0x0822FBC2
	.string "おつかれさまでした！\p"
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちくだされ！$"

	.globl gJPText_0022FBE9
gJPText_0022FBE9: @ 0x0822FBE9
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

	.globl gJPText_0022FC01
gJPText_0022FC01: @ 0x0822FC01
	.string "おまちしておりました！\p"
	.string "バトルアリーナに　おつれする　まえに\n"
	.string "レポートを　かきますので　おまちくだされ！$"

	.globl gJPText_0022FC36
gJPText_0022FC36: @ 0x0822FC36
	.string "バトルアリーナで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　されますかな？$"

	.incbin "baserom_jp.gba", 0x22fc66, 0x3bd
	.globl gJPText_00230023
gJPText_00230023: @ 0x08230023
	.string "アリーナキャプテンからの　きんぼし！\n"
	.string "ならびに　7にんぬき　たっせい！\l"
	.string "まこと　みごとで　ございました！$"

	.globl gJPText_00230058
gJPText_00230058: @ 0x08230058
	.string "おきゃくじんの　ふくつの　とうしを　たたえ\n"
	.string "バトルポイントを　さしあげましょう！$"

