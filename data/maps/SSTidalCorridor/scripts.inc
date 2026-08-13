@ SSTidalCorridor scripts (JP map g25 m41 @ 0x0821DE46)

SSTidalCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_MapScriptTable_0021DE4C
	.byte 0

SSTidalCorridor_MapScriptTable_0021DE4C::
	map_script_2 0x40D4, 0x0, SSTidalCorridor_EventScript_0021E090
	map_script_2 0x40B4, 0x1, SSTidalCorridor_EventScript_0021DE76
	map_script_2 0x40B4, 0x5, SSTidalCorridor_EventScript_0021DE8C
	map_script_2 0x40B4, 0x9, SSTidalCorridor_EventScript_0021DEDE
	map_script_2 0x40B4, 0xA, SSTidalCorridor_EventScript_0021DEF4
	.2byte 0

SSTidalCorridor_EventScript_0021DE76::
	special SetSSTidalFlag
	setvar 0x40B4, 0x2
	lockall
	playse 0x49
	loadword 0x0, gJPText_0021E201
	callstd 0x4
	releaseall
	end

SSTidalCorridor_EventScript_0021DE8C::
	setvar 0x40B4, 0x6
	lockall
	playse 0x49
	loadword 0x0, gJPText_0021E227
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21de9f, 0x3f
SSTidalCorridor_EventScript_0021DEDE::
	special ResetSSTidalFlag
	setvar 0x40B4, 0x3
	lockall
	playse 0x49
	loadword 0x0, gJPText_0021E227
	callstd 0x4
	releaseall
	end

SSTidalCorridor_EventScript_0021DEF4::
	special ResetSSTidalFlag
	setvar 0x40B4, 0x8
	lockall
	playse 0x49
	loadword 0x0, gJPText_0021E248
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21df0a, 0x46
SSTidalCorridor_EventScript_0021DF50::
	loadword 0x0, 0x0821E350
	callstd 0x2
	end

SSTidalCorridor_EventScript_0021DF59::
	lock
	faceplayer
	waitse
	playmoncry 0x135, 0x0
	loadword 0x0, 0x0821E3B8
	callstd 0x4
	waitdooranim
	release
	end

SSTidalCorridor_EventScript_0021DF6C::
	loadword 0x0, 0x0821E3C9
	callstd 0x3
	end

SSTidalCorridor_EventScript_0021DF75::
	loadword 0x0, 0x0821E3CF
	callstd 0x3
	end

SSTidalCorridor_EventScript_0021DF7E::
	loadword 0x0, 0x0821E3D5
	callstd 0x3
	end

SSTidalCorridor_EventScript_0021DF87::
	loadword 0x0, 0x0821E3DB
	callstd 0x3
	end

SSTidalCorridor_EventScript_0021DF90::
	lock
	faceplayer
	compare_var_to_value 0x40B4, 0x4
	goto_if 0x1, SSTidalCorridor_EventScript_0021DFB2
	compare_var_to_value 0x40B4, 0x8
	goto_if 0x1, SSTidalCorridor_EventScript_0021DFD1
	loadword 0x0, 0x0821E28A
	callstd 0x4
	release
	end

SSTidalCorridor_EventScript_0021DFB2::
	setrespawn 0x8
	loadword 0x0, 0x0821E2E5
	callstd 0x4
	checkflag 0x104
	call_if 0x1, SSTidalCorridor_EventScript_0021DFF0
	warp 0xD0A, 0xFF, 0x8, 0xB
	waitstate
	release
	end

SSTidalCorridor_EventScript_0021DFD1::
	setrespawn 0x4
	loadword 0x0, 0x0821E2E5
	callstd 0x4
	checkflag 0x104
	call_if 0x1, SSTidalCorridor_EventScript_0021DFF0
	warp 0x909, 0xFF, 0x8, 0xB
	waitstate
	release
	end

SSTidalCorridor_EventScript_0021DFF0::
	setflag 0x3B7
	return

SSTidalCorridor_EventScript_0021DFF4::
	lockall
	compare_var_to_value 0x40B4, 0x2
	goto_if 0x1, SSTidalCorridor_EventScript_0021E015
	compare_var_to_value 0x40B4, 0x7
	goto_if 0x1, SSTidalCorridor_EventScript_0021E015
	loadword 0x0, 0x0821E336
	callstd 0x4
	releaseall
	end

SSTidalCorridor_EventScript_0021E015::
	special sub_080FC014
	waitstate
	end

SSTidalCorridor_EventScript_0021E01A::
	lock
	faceplayer
	checkflag 0xF7
	goto_if 0x1, SSTidalCorridor_EventScript_0021E034
	call SSTidalCorridor_EventScript_0021E03E
	loadword 0x0, 0x0821E2F0
	callstd 0x4
	release
	end

SSTidalCorridor_EventScript_0021E034::
	loadword 0x0, 0x0821E324
	callstd 0x4
	release
	end

SSTidalCorridor_EventScript_0021E03E::
	checktrainerflag 0x1EE
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0x1EF
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0x126
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0xFF
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0x100
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0x281
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0x8A
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	checktrainerflag 0x77
	goto_if 0x0, SSTidalCorridor_EventScript_0021E08F
	setflag 0xF7
	goto SSTidalCorridor_EventScript_0021E034
	return

SSTidalCorridor_EventScript_0021E08F::
	return

SSTidalCorridor_EventScript_0021E090::
	lockall
	applymovement 0x5, 0x0821E0E4
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, gJPText_0021E106
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0821E0F4
	applymovement 0x1, 0x0821E0FB
	applymovement 0x5, 0x0821E0EC
	waitmovement 0x0
	playse 0x9
	waitse
	removeobject 0x5
	applymovement 0x1, 0x0821E102
	waitmovement 0x0
	delay 0x1E
	setflag 0x1D0
	setvar 0x40D4, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21e0e4, 0x22
	.globl gJPText_0021E106
gJPText_0021E106: @ 0x0821E106
	.string "エニシダ“やあ　やあ　やあ\n"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\p"
	.string "わたしは　ようじが　あって\n"
	.string "もう　ふねを　おりるんだけど\l"
	.string "あえて　よかったよ！\p"
	.string "リーグチャンピオン　おめでとう！\n"
	.string "そんな　きみを　しょうたい　したい\l"
	.string "ところが　ある！\p"
	.string "それは⋯⋯　バトルフロンティア　だ！\p"
	.string "どんな　ところかって？\n"
	.string "とにかく　きてみれば　わかるよ\p"
	.string "このふねの　せんちょうには\n"
	.string "はなしを　しておいた　から⋯⋯\l"
	.string "つぎから　ふねに　のるときは\l"
	.string "バトルフロンティアに　いける　はずだよ！\p"
	.string "じゃあね　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}\n"
	.string "バトルフロンティアで　まっているよ！$"

	.globl gJPText_0021E201
gJPText_0021E201: @ 0x0821E201
	.string "かいりゅうを　ものともせず　すすむ\n"
	.string "れんらくせんを　どうぞ　ごらんください$"

	.globl gJPText_0021E227
gJPText_0021E227: @ 0x0821E227
	.string "それでは　れんらくせんに　よる\n"
	.string "ふなたびを　おたのしみ　ください$"

	.globl gJPText_0021E248
gJPText_0021E248: @ 0x0821E248
	.string "おつかれさまです　ただいま\n"
	.string "カイナシティに　とうちゃく　しました$"

	.incbin "baserom_jp.gba", 0x21e269, 0x6fd
