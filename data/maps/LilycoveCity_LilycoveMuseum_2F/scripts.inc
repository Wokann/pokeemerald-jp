@ LilycoveCity_LilycoveMuseum_2F scripts (JP map g13 m3 @ 0x082061E6)

LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_EventScript_002061F1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_MapScriptTable_002062AA
	.byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_002061F1::
	checkflag 0xA0
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206237
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_00206200
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206200::
	checkflag 0xA1
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_0020624F
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_0020620F
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020620F::
	checkflag 0xA2
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206267
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_0020621E
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020621E::
	checkflag 0xA3
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_0020627F
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_0020622D
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020622D::
	checkflag 0xA4
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206297
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206237::
	setmetatile 0xA, 0x6, 0x25E, 0x1
	setmetatile 0xB, 0x6, 0x25F, 0x1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_00206200
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020624F::
	setmetatile 0x12, 0x6, 0x25C, 0x1
	setmetatile 0x13, 0x6, 0x25D, 0x1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_0020620F
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206267::
	setmetatile 0xE, 0xA, 0x260, 0x1
	setmetatile 0xF, 0xA, 0x261, 0x1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_0020621E
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020627F::
	setmetatile 0x6, 0xA, 0x25A, 0x1
	setmetatile 0x7, 0xA, 0x25B, 0x1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_0020622D
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206297::
	setmetatile 0x2, 0x6, 0x262, 0x1
	setmetatile 0x3, 0x6, 0x263, 0x1
	end

LilycoveCity_LilycoveMuseum_2F_MapScriptTable_002062AA::
	map_script_2 0x4094, 0x0, LilycoveCity_LilycoveMuseum_2F_EventScript_002062B4
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_002062B4::
	lockall
	applymovement 0x1, 0x08243621
	applymovement 0xFF, 0x0820630D
	waitmovement 0x0
	loadword 0x0, gJPText_00206497
	callstd 0x3
	applymovement 0x1, 0x0820630F
	waitmovement 0x0
	applymovement 0xFF, 0x0820630F
	waitmovement 0x0
	loadword 0x0, gJPText_002064A9
	callstd 0x3
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	applymovement 0xFF, 0x0820630D
	waitmovement 0x0
	loadword 0x0, gJPText_0020655D
	callstd 0x3
	copyvar 0x4094, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x20630d, 0x5
LilycoveCity_LilycoveMuseum_2F_EventScript_00206312::
	lockall
	checkflag 0xEC
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_002063CD
	specialvar 0x8004, CountPlayerContestPaintings
	copyvar 0x8000, 0x8004
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206366
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206366
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206366
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206366
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_0020636F
	loadword 0x0, 0x08206607
	callstd 0x2
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206366::
	loadword 0x0, 0x08206636
	callstd 0x2
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020636F::
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x08206681
	callstd 0x4
	applymovement 0x1, 0x0820630F
	loadword 0x0, 0x0820668E
	callstd 0x4
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_00206396
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206396::
	applymovement 0x1, 0x08243621
	loadword 0x0, 0x0820670F
	callstd 0x4
	setorcopyvar 0x8000, 0x2C
	callstd 0x7
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_002063BD
	setflag 0xEC
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_002063BD::
	call 0x082430FD
	loadword 0x0, 0x08206729
	callstd 0x4
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_002063CD::
	loadword 0x0, 0x08206743
	callstd 0x2
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_002063D7::
	lockall
	checkflag 0xA2
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_0020646D
	loadword 0x0, 0x08206788
	callstd 0x3
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_002063EA::
	lockall
	checkflag 0xA4
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206489
	loadword 0x0, 0x0820679E
	callstd 0x3
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_002063FD::
	lockall
	checkflag 0xA0
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_00206451
	loadword 0x0, 0x082067C7
	callstd 0x3
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206410::
	lockall
	checkflag 0xA1
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_0020645F
	loadword 0x0, 0x082067B3
	callstd 0x3
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206423::
	lockall
	checkflag 0xA3
	goto_if 0x1, LilycoveCity_LilycoveMuseum_2F_EventScript_0020647B
	loadword 0x0, 0x082067DB
	callstd 0x3
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206436::
	loadword 0x0, 0x08206803
	callstd 0x2
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020643F::
	loadword 0x0, 0x0820684E
	callstd 0x2
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206448::
	loadword 0x0, 0x08206898
	callstd 0x2
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206451::
	loadword 0x0, 0x082067F2
	callstd 0x3
	fadescreen 0x1
	showcontestwinner 0x9
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020645F::
	loadword 0x0, 0x082067F2
	callstd 0x3
	fadescreen 0x1
	showcontestwinner 0xA
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020646D::
	loadword 0x0, 0x082067F2
	callstd 0x3
	fadescreen 0x1
	showcontestwinner 0xB
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_0020647B::
	loadword 0x0, 0x082067F2
	callstd 0x3
	fadescreen 0x1
	showcontestwinner 0xC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_00206489::
	loadword 0x0, 0x082067F2
	callstd 0x3
	fadescreen 0x1
	showcontestwinner 0xD
	releaseall
	end

	.globl gJPText_00206497
gJPText_00206497: @ 0x08206497
	.string "ここは　とくべつ　てんじしつ　です$"

	.globl gJPText_002064A9
gJPText_002064A9: @ 0x082064A9
	.string "ごらんの　とおり　まだ\n"
	.string "えが　かざられて　おりません\p"
	.string "ここには　1かいに　あるような\n"
	.string "いわゆる　めいが　といった　ものとは\l"
	.string "ちがう　えを　かざりたいの　ですよ！\p"
	.string "ふるい　めいが　ばかりが\n"
	.string "げいじゅつ　なのでは　ありません！\p"
	.string "この　てんじしつ　には⋯⋯\p"
	.string "いまにも　ポケモンが　とびだして　きそうな\n"
	.string "モダンで　いきいきとした　さくひんを\l"
	.string "かざって　みたいのです！$"

	.globl gJPText_0020655D
gJPText_0020655D: @ 0x0820655D
	.string "つい　ながながと　しつれい　しました\p"
	.string "あなたは　まだ　おわかいし\n"
	.string "たびを　なさって　いる　ようだから\p"
	.string "いきいきとした　ポケモンや\n"
	.string "それを　えがいた　すてきな　さくひんに\l"
	.string "であわれる　かも　しれません！\p"
	.string "もし　そんな　さくひんに　であったら\n"
	.string "そのえを　ここに　かざれる　ように\l"
	.string "あなたから　おねがい　して　くださると\l"
	.string "たいへん　うれしいです$"
