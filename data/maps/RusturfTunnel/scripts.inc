@ RusturfTunnel scripts (JP map g24 m4 @ 0x082135F0)

RusturfTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_EventScript_0021360D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_MapScriptTable_002135FB
	.byte 0

RusturfTunnel_MapScriptTable_002135FB::
	map_script_2 0x409A, 0x4, RusturfTunnel_EventScript_00213677
	map_script_2 0x409A, 0x5, RusturfTunnel_EventScript_00213677
	.2byte 0

RusturfTunnel_EventScript_0021360D::
	compare_var_to_value 0x409A, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213619
	end

RusturfTunnel_EventScript_00213619::
	setobjectxyperm 0x7, 0xD, 0x4
	setobjectxyperm 0x6, 0xD, 0x5
	return

RusturfTunnel_EventScript_00213628::
	lock
	faceplayer
	loadword 0x0, 0x08213CF3
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RusturfTunnel_EventScript_0021363F::
	lock
	faceplayer
	checkflag 0x1
	goto_if 0x1, RusturfTunnel_EventScript_00213662
	setflag 0x1
	loadword 0x0, 0x08213B76
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RusturfTunnel_EventScript_00213662::
	loadword 0x0, 0x08213C05
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RusturfTunnel_EventScript_00213677::
	lockall
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RusturfTunnel_EventScript_00213770
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213785
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_00213790
	call RusturfTunnel_EventScript_002137C8
	loadword 0x0, gJPText_00213C3E
	callstd 0x4
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213791
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_00213791
	setorcopyvar 0x8000, 0x156
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x6A
	loadword 0x0, gJPText_00213C7B
	callstd 0x4
	closemessage
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RusturfTunnel_EventScript_00213726
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213738
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_00213754
	loadword 0x0, gJPText_00213CB3
	callstd 0x4
	closemessage
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RusturfTunnel_EventScript_0021379D
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_002137AF
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_002137AF
	call 0x08243299
	releaseall
	end

RusturfTunnel_EventScript_00213726::
	applymovement 0xFF, 0x0821380B
	applymovement 0x1, 0x08213830
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213738::
	applymovement 0xFF, 0x0821380E
	applymovement 0x1, 0x08213835
	waitmovement 0x0
	applymovement 0xA, 0x0824362D
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213754::
	applymovement 0xFF, 0x0821380E
	applymovement 0x1, 0x08213835
	waitmovement 0x0
	applymovement 0xA, 0x0824362D
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213770::
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213785::
	applymovement 0x1, 0x08213811
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213790::
	return

RusturfTunnel_EventScript_00213791::
	closemessage
	applymovement 0x1, 0x0821382E
	waitmovement 0x0
	return

RusturfTunnel_EventScript_0021379D::
	applymovement 0xA, 0x082137E0
	applymovement 0x1, 0x08213814
	waitmovement 0x0
	return

RusturfTunnel_EventScript_002137AF::
	applymovement 0xFF, 0x082137F8
	applymovement 0xA, 0x082137EC
	applymovement 0x1, 0x08213821
	waitmovement 0x0
	return

RusturfTunnel_EventScript_002137C8::
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x2137e0, 0x5a
RusturfTunnel_EventScript_0021383A::
	setvar 0x4001, 0x1
	end

RusturfTunnel_EventScript_00213840::
	setvar 0x4001, 0x2
	end

RusturfTunnel_EventScript_00213846::
	setvar 0x4001, 0x3
	end

RusturfTunnel_EventScript_0021384C::
	lockall
	loadword 0x0, 0x08213991
	callstd 0x4
	closemessage
	applymovement 0x6, 0x08213874
	applymovement 0x7, 0x08213874
	waitmovement 0x0
	moveobjectoffscreen 0x6
	moveobjectoffscreen 0x7
	setvar 0x409A, 0x3
	releaseall
	end

	.incbin "baserom_jp.gba", 0x213874, 0x4
RusturfTunnel_EventScript_00213878::
	lock
	faceplayer
	waitse
	playmoncry 0x135, 0x0
	loadword 0x0, 0x082139A1
	callstd 0x4
	waitdooranim
	release
	end

	.incbin "baserom_jp.gba", 0x21388b, 0x3b3
	.globl gJPText_00213C3E
gJPText_00213C3E: @ 0x08213C3E
	.string "なんと！　きみが　この　いわを\n"
	.string "くだいて　くれたんだね\p"
	.string "かんしゃの　しるし　として\n"
	.string "この　ひでんマシンを　うけとってくれ$"

	.globl gJPText_00213C7B
gJPText_00213C7B: @ 0x08213C7B
	.string "そいつには　かいりきが　はいっている\n"
	.string "ちからもちの　ポケモンに　おぼえさせれば\l"
	.string "おおきな　いわを　うごかせるよ$"

	.globl gJPText_00213CB3
gJPText_00213CB3: @ 0x08213CB3
	.string "ミチルさん！\n"
	.string "これから　いつでも　あえます！\p"
	.string "ミチル“よかった⋯⋯　です\p"
	.string "さあ　わたしの　いえで\n"
	.string "ゆっくり　やすんで　ください$"

	.incbin "baserom_jp.gba", 0x213cf3, 0xdd
