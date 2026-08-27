@ BattleFrontier_BattleFactoryLobby scripts (JP map g26 m31 @ 0x08230DBB)

BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_MapScriptTable_00230DDA
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_MapScriptTable_00230DC6
	.byte 0

BattleFrontier_BattleFactoryLobby_MapScriptTable_00230DC6::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleFactoryLobby_EventScript_00230DD0
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_00230DD0::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleFactoryLobby_MapScriptTable_00230DDA::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleFactoryLobby_EventScript_00230E04
	map_script_2 0x4000, 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00230E0D
	map_script_2 0x4000, 0x2, BattleFrontier_BattleFactoryLobby_EventScript_00230F65
	map_script_2 0x4000, 0x3, BattleFrontier_BattleFactoryLobby_EventScript_00230E6E
	map_script_2 0x4000, 0x4, BattleFrontier_BattleFactoryLobby_EventScript_00230ED9
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_00230E04::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleFactoryLobby_EventScript_00230E0D::
	lockall
	loadword 0x0, gJPText_002315ED
	callstd 0x4
	closemessage
	setvar 0x8004, 0x8
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_00230E6E::
	lockall
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00230E90
	loadword 0x0, gJPText_00231554
	callstd 0x4
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_00230E99

BattleFrontier_BattleFactoryLobby_EventScript_00230E90::
	loadword 0x0, gJPText_002317EA
	callstd 0x4
	waitmessage

BattleFrontier_BattleFactoryLobby_EventScript_00230E99::
	loadword 0x0, gJPText_0023181A
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_Text_ObtainedXBattlePoints
	callstd 0x9
	message gJPText_00231840
	waitmessage
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallBattleFactoryFunction
	playse 0x37
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_00230F0E
	end

BattleFrontier_BattleFactoryLobby_EventScript_00230ED9::
	lockall
	message gJPText_002314DC
	waitmessage
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallBattleFactoryFunction
	playse 0x37
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_00230F0E::
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00230F55
	message gJPText_0023188A
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00230F55
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00230F50
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00230F55

BattleFrontier_BattleFactoryLobby_EventScript_00230F50::
	call 0x0821F8F5

BattleFrontier_BattleFactoryLobby_EventScript_00230F55::
	loadword 0x0, gJPText_00231454
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_00230F65::
	lockall
	message gJPText_002315C2
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x1
	special CallBattleFactoryFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	setvar 0x8006, 0x2
	goto BattleFrontier_BattleFactoryLobby_EventScript_002310ED

BattleFrontier_BattleFactoryLobby_EventScript_00230F9E::
	lock
	faceplayer
	setvar 0x40CF, 0x4
	setvar 0x40CE, 0x0
	goto BattleFrontier_BattleFactoryLobby_EventScript_00230FC0
	end

BattleFrontier_BattleFactoryLobby_EventScript_00230FB0::
	setvar 0x40CF, 0x4
	setvar 0x40CE, 0x1
	goto BattleFrontier_BattleFactoryLobby_EventScript_00230FC0
	end

BattleFrontier_BattleFactoryLobby_EventScript_00230FC0::
	special SavePlayerParty
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231184
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023118D

BattleFrontier_BattleFactoryLobby_EventScript_00230FD9::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231196
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023119C
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231026
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023113B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231170
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231170

BattleFrontier_BattleFactoryLobby_EventScript_00231026::
	message 0x08231469
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231170
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231170
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0823148F
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023116D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023108C
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023116D

BattleFrontier_BattleFactoryLobby_EventScript_0023108C::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special CallBattleFactoryFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231156
	setvar 0x8006, 0x0

BattleFrontier_BattleFactoryLobby_EventScript_002310ED::
	special SavePlayerParty
	loadword 0x0, gJPText_002314CD
	callstd 0x4
	closemessage
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_0023112F
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231135
	applymovement 0x800F, 0x0823117A
	applymovement 0xFF, 0x0823117F
	waitmovement 0x0
	warp 0x1A20, 0xFF, 0x8, 0xD
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_0023112F::
	setvar 0x800F, 0x1
	return

BattleFrontier_BattleFactoryLobby_EventScript_00231135::
	setvar 0x800F, 0x6
	return

BattleFrontier_BattleFactoryLobby_EventScript_0023113B::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_002311A2
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_002311AB
	goto BattleFrontier_BattleFactoryLobby_EventScript_00230FD9

BattleFrontier_BattleFactoryLobby_EventScript_00231156::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryLobby_EventScript_00231170

BattleFrontier_BattleFactoryLobby_EventScript_0023116D::
	special LoadPlayerParty

BattleFrontier_BattleFactoryLobby_EventScript_00231170::
	loadword 0x0, gJPText_00231454
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x23117a, 0xa
BattleFrontier_BattleFactoryLobby_EventScript_00231184::
	loadword 0x0, 0x082312C1
	callstd 0x4
	return

BattleFrontier_BattleFactoryLobby_EventScript_0023118D::
	loadword 0x0, 0x0823165C
	callstd 0x4
	return

BattleFrontier_BattleFactoryLobby_EventScript_00231196::
	message 0x08231305
	return

BattleFrontier_BattleFactoryLobby_EventScript_0023119C::
	message 0x0823169E
	return

BattleFrontier_BattleFactoryLobby_EventScript_002311A2::
	loadword 0x0, 0x0823131F
	callstd 0x4
	return

BattleFrontier_BattleFactoryLobby_EventScript_002311AB::
	loadword 0x0, 0x082316B7
	callstd 0x4
	return

BattleFrontier_BattleFactoryLobby_EventScript_002311B4::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x4
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_002311CD::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x4
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_002311E6::
	loadword 0x0, 0x082318BC
	callstd 0x2
	end

BattleFrontier_BattleFactoryLobby_EventScript_002311EF::
	loadword 0x0, 0x0823192E
	callstd 0x2
	end

BattleFrontier_BattleFactoryLobby_EventScript_002311F8::
	lock
	loadword 0x0, 0x08231957
	callstd 0x4
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_00231203::
	loadword 0x0, 0x0823198B
	callstd 0x2
	end

BattleFrontier_BattleFactoryLobby_EventScript_0023120C::
	lockall
	loadword 0x0, 0x08231A91
	callstd 0x4
	goto BattleFrontier_BattleFactoryLobby_EventScript_0023121B
	end

BattleFrontier_BattleFactoryLobby_EventScript_0023121B::
	message 0x08231AA7
	waitmessage
	multichoice 0x11, 0x0, 0x63, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231279
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231287
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_00231295
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_002312A3
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_002312B1
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_002312BF
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleFactoryLobby_EventScript_002312BF
	end

BattleFrontier_BattleFactoryLobby_EventScript_00231279::
	loadword 0x0, 0x08231AB7
	callstd 0x4
	goto BattleFrontier_BattleFactoryLobby_EventScript_0023121B
	end

BattleFrontier_BattleFactoryLobby_EventScript_00231287::
	loadword 0x0, 0x08231B1D
	callstd 0x4
	goto BattleFrontier_BattleFactoryLobby_EventScript_0023121B
	end

BattleFrontier_BattleFactoryLobby_EventScript_00231295::
	loadword 0x0, 0x08231B6E
	callstd 0x4
	goto BattleFrontier_BattleFactoryLobby_EventScript_0023121B
	end

BattleFrontier_BattleFactoryLobby_EventScript_002312A3::
	loadword 0x0, 0x08231BC9
	callstd 0x4
	goto BattleFrontier_BattleFactoryLobby_EventScript_0023121B
	end

BattleFrontier_BattleFactoryLobby_EventScript_002312B1::
	loadword 0x0, 0x08231C62
	callstd 0x4
	goto BattleFrontier_BattleFactoryLobby_EventScript_0023121B
	end

BattleFrontier_BattleFactoryLobby_EventScript_002312BF::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x2312c1, 0x193
	.globl gJPText_00231454
gJPText_00231454: @ 0x08231454
	.string "またの　ごりようを　おまちしていますよ！$"

	.incbin "baserom_jp.gba", 0x231469, 0x64
	.globl gJPText_002314CD
gJPText_002314CD: @ 0x082314CD
	.string "さあさあ　こちらに　どうぞ！$"

	.globl gJPText_002314DC
gJPText_002314DC: @ 0x082314DC
	.string "おつかれさまでした！\p"
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　します！\p"
	.string "せいせきを　レポートに　かきますので\n"
	.string "しょうしょう　おまちください！$"

	.incbin "baserom_jp.gba", 0x23152f, 0x25
	.globl gJPText_00231554
gJPText_00231554: @ 0x08231554
	.string "バトルトレード　7せん　とっぱ\n"
	.string "おめでとう　ございます！$"

	.incbin "baserom_jp.gba", 0x231571, 0x51
	.globl gJPText_002315C2
gJPText_002315C2: @ 0x082315C2
	.string "おまちしておりましたよ！\p"
	.string "ちょうせんを　さいかいする　まえに\n"
	.string "レポートを　かきます！$"

	.globl gJPText_002315ED
gJPText_002315ED: @ 0x082315ED
	.string "おきゃくさまー！！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しません　でしたね！\p"
	.string "ざんねんですが\n"
	.string "ちょうせんは　むこうと　なります！$"

	.incbin "baserom_jp.gba", 0x231637, 0x1b3
	.globl gJPText_002317EA
gJPText_002317EA: @ 0x082317EA
	.string "ファクトリーヘッドへの　しょうり！\n"
	.string "ならびに　7れんしょう　たっせい\l"
	.string "おめでとう　ございます！$"

	.globl gJPText_0023181A
gJPText_0023181A: @ 0x0823181A
	.string "おきゃくさまの　ふかい　ちしきを　たたえ\n"
	.string "バトルポイントを　さしあげます！$"

	.globl gJPText_00231840
gJPText_00231840: @ 0x08231840
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　しましょう！\p"
	.string "せいせきを　レポートに　かきますので\n"
	.string "しょうしょう　おまちください！$"

	.globl gJPText_0023188A
gJPText_0023188A: @ 0x0823188A
	.string "バトルファクトリーで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　いたしますか？$"
