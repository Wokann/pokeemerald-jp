@ LittlerootTown_MaysHouse_1F scripts (JP map g1 m2 @ 0x081F0358)

LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_EventScript_001F0368
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_EventScript_001F03A7
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_MapScriptTable_001F03ED
	.byte 0

LittlerootTown_MaysHouse_1F_EventScript_001F0368::
	compare_var_to_value 0x4092, 0x6
	call_if 0x0, LittlerootTown_MaysHouse_1F_EventScript_001F037D
	checkflag 0x112
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F0390
	end

LittlerootTown_MaysHouse_1F_EventScript_001F037D::
	setmetatile 0x5, 0x4, 0x270, 0x1
	setmetatile 0x5, 0x2, 0x268, 0x1
	return

LittlerootTown_MaysHouse_1F_EventScript_001F0390::
	checkplayergender
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F039D
	return

LittlerootTown_MaysHouse_1F_EventScript_001F039D::
	setmetatile 0x6, 0x7, 0x293, 0x1
	return

LittlerootTown_MaysHouse_1F_EventScript_001F03A7::
	compare_var_to_value 0x4092, 0x3
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F03E1
	compare_var_to_value 0x4092, 0x5
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F03C9
	compare_var_to_value 0x4092, 0x6
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F03D5
	end

LittlerootTown_MaysHouse_1F_EventScript_001F03C9::
	setobjectxyperm 0x1, 0x2, 0x4
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_MaysHouse_1F_EventScript_001F03D5::
	setobjectxyperm 0x1, 0x6, 0x5
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_MaysHouse_1F_EventScript_001F03E1::
	setobjectxyperm 0x1, 0x1, 0x8
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_MaysHouse_1F_MapScriptTable_001F03ED::
	map_script_2 0x4092, 0x3, LittlerootTown_MaysHouse_1F_EventScript_001F043F
	map_script_2 0x4092, 0x5, LittlerootTown_MaysHouse_1F_EventScript_001F0417
	map_script_2 0x4092, 0x6, LittlerootTown_MaysHouse_1F_EventScript_001F0450
	map_script_2 0x408C, 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F0461
	map_script_2 0x4082, 0x3, 0x082582DC
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_001F0417::
	lockall
	loadword 0x0, gJPText_001EFAFC
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081F043D
	applymovement 0x1, 0x081F043D
	waitmovement 0x0
	warp 0x103, 0xFF, 0x1, 0x1
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f043d, 0x2
LittlerootTown_MaysHouse_1F_EventScript_001F043F::
	lockall
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	goto 0x08257EEE
	end

LittlerootTown_MaysHouse_1F_EventScript_001F0450::
	lockall
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	goto 0x082580C6
	end

LittlerootTown_MaysHouse_1F_EventScript_001F0461::
	lockall
	playse 0x15
	applymovement 0x4, 0x0824361B
	waitmovement 0x0
	applymovement 0x4, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	applymovement 0x4, 0x081F049F
	waitmovement 0x0
	special GetRivalSonDaughterString
	loadword 0x0, gJPText_001F0678
	callstd 0x4
	setflag 0x57
	setvar 0x408C, 0x2
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f049f, 0x7
LittlerootTown_MaysHouse_1F_EventScript_001F04A6::
	lock
	faceplayer
	checkflag 0x82
	goto_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F04E6
	checkflag 0x860
	goto_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F04DC
	compare_var_to_value 0x408D, 0x3
	goto_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F04D2
	special GetRivalSonDaughterString
	loadword 0x0, 0x081F0701
	callstd 0x4
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_001F04D2::
	loadword 0x0, 0x081F0755
	callstd 0x4
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_001F04DC::
	loadword 0x0, 0x081F078A
	callstd 0x4
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_001F04E6::
	loadword 0x0, 0x081F07D8
	callstd 0x4
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_001F04F0::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	loadword 0x0, 0x081F0ABD
	callstd 0x4
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_001F04FF::
	lockall
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	applymovement 0x8004, 0x0824362B
	waitmovement 0x0
	goto 0x08257F4F
	end

LittlerootTown_MaysHouse_1F_EventScript_001F051A::
	lockall
	setvar 0x8008, 0x0
	goto LittlerootTown_MaysHouse_1F_EventScript_001F053E
	end

LittlerootTown_MaysHouse_1F_EventScript_001F0526::
	lockall
	setvar 0x8008, 0x1
	goto LittlerootTown_MaysHouse_1F_EventScript_001F053E
	end

LittlerootTown_MaysHouse_1F_EventScript_001F0532::
	lockall
	setvar 0x8008, 0x2
	goto LittlerootTown_MaysHouse_1F_EventScript_001F053E
	end

LittlerootTown_MaysHouse_1F_EventScript_001F053E::
	playse 0x9
	delay 0xA
	addobject 0x7
	delay 0x1E
	playse 0x15
	applymovement 0x7, 0x0824361B
	waitmovement 0x0
	applymovement 0x7, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x8008, 0x1
	call_if 0x5, LittlerootTown_MaysHouse_1F_EventScript_001F05DD
	playbgm 0x19F, 0x1
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F05E8
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F05F3
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F05FE
	loadword 0x0, 0x081F0843
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F061D
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F062F
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_MaysHouse_1F_EventScript_001F0641
	playse 0x9
	removeobject 0x7
	setflag 0x2EA
	setflag 0x332
	clearflag 0x2D2
	delay 0x1E
	setvar 0x408D, 0x3
	setvar 0x4050, 0x1
	savebgm 0x0
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_001F05DD::
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_001F05E8::
	applymovement 0x7, 0x081F0609
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_001F05F3::
	applymovement 0x7, 0x081F0611
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_001F05FE::
	applymovement 0x7, 0x081F0615
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1f0609, 0x14
LittlerootTown_MaysHouse_1F_EventScript_001F061D::
	applymovement 0xFF, 0x081F0653
	applymovement 0x7, 0x081F0662
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_001F062F::
	applymovement 0xFF, 0x081F0657
	applymovement 0x7, 0x081F0668
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_001F0641::
	applymovement 0xFF, 0x081F065E
	applymovement 0x7, 0x081F0672
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1f0653, 0x25
	.globl gJPText_001F0678
gJPText_001F0678: @ 0x081F0678
	.string "えーと　どなた　かしら？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "そうか　あなたが　おとなりに\n"
	.string "ひっこしてきた　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　ね！\p"
	.string "うちにも　あなたと　おなじ　としごろの\n"
	.string "{B_COPY_VAR_1}が　いるのよ！\p"
	.string "‘あたらしい　おともだちが　できる！'\n"
	.string "なんて　いって\l"
	.string "とっても　たのしみに　してたの！$"

	.incbin "baserom_jp.gba", 0x1f0701, 0x3e1
