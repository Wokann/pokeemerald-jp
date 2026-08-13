@ MossdeepCity_StevensHouse scripts (JP map g14 m7 @ 0x0820C816)

MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_EventScript_0020C826
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_EventScript_0020C83A
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_MapScriptTable_0020C852
	.byte 0

MossdeepCity_StevensHouse_EventScript_0020C826::
	checkflag 0x864
	call_if 0x0, MossdeepCity_StevensHouse_EventScript_0020C830
	end

MossdeepCity_StevensHouse_EventScript_0020C830::
	setmetatile 0x6, 0x4, 0x2F1, 0x1
	return

MossdeepCity_StevensHouse_EventScript_0020C83A::
	compare_var_to_value 0x40C6, 0x2
	call_if 0x1, MossdeepCity_StevensHouse_EventScript_0020C846
	end

MossdeepCity_StevensHouse_EventScript_0020C846::
	setobjectxyperm 0x1, 0x6, 0x5
	setobjectmovementtype 0x1, 0x7
	return

MossdeepCity_StevensHouse_MapScriptTable_0020C852::
	map_script_2 0x40C6, 0x1, MossdeepCity_StevensHouse_EventScript_0020C85C
	.2byte 0

MossdeepCity_StevensHouse_EventScript_0020C85C::
	lockall
	applymovement 0x1, 0x08243627
	waitmovement 0x0
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	applymovement 0x1, 0x0820C8C5
	waitmovement 0x0
	loadword 0x0, gJPText_0020C9C8
	callstd 0x4
	setorcopyvar 0x8000, 0x15A
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x7B
	setflag 0x12E
	loadword 0x0, gJPText_0020CA36
	callstd 0x4
	closemessage
	delay 0x14
	applymovement 0x1, 0x0820C8CD
	waitmovement 0x0
	setflag 0x314
	setflag 0x3AD
	setvar 0x40C6, 0x2
	releaseall
	end

	.incbin "baserom_jp.gba", 0x20c8c5, 0xe
MossdeepCity_StevensHouse_EventScript_0020C8D3::
	lockall
	loadword 0x0, 0x0820CAF7
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MossdeepCity_StevensHouse_EventScript_0020C8ED
	goto MossdeepCity_StevensHouse_EventScript_0020C8F7
	end

MossdeepCity_StevensHouse_EventScript_0020C8ED::
	loadword 0x0, 0x0820CB5D
	callstd 0x4
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_0020C8F7::
	setvar 0x4001, 0x18E
	givemon 0x18E, 0x5, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MossdeepCity_StevensHouse_EventScript_0020C927
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, MossdeepCity_StevensHouse_EventScript_0020C94F
	goto 0x0824423B
	end

MossdeepCity_StevensHouse_EventScript_0020C927::
	call MossdeepCity_StevensHouse_EventScript_0020C97D
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MossdeepCity_StevensHouse_EventScript_0020C993
	call 0x082441B5
	call 0x08243460
	goto MossdeepCity_StevensHouse_EventScript_0020C993
	end

MossdeepCity_StevensHouse_EventScript_0020C94F::
	call MossdeepCity_StevensHouse_EventScript_0020C97D
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MossdeepCity_StevensHouse_EventScript_0020C972
	call 0x082441C1
	goto MossdeepCity_StevensHouse_EventScript_0020C972
	end

MossdeepCity_StevensHouse_EventScript_0020C972::
	call 0x082441CA
	goto MossdeepCity_StevensHouse_EventScript_0020C993
	end

MossdeepCity_StevensHouse_EventScript_0020C97D::
	buffermovename 0x1, 0x18E
	removeobject 0x2
	playfanfare 0x172
	message 0x0820CB39
	waitmessage
	waitfanfare
	buffermovename 0x0, 0x18E
	return

MossdeepCity_StevensHouse_EventScript_0020C993::
	setflag 0x3C8
	setflag 0x12A
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_0020C99B::
	loadword 0x0, 0x0820CC3F
	callstd 0x3
	end

MossdeepCity_StevensHouse_EventScript_0020C9A4::
	loadword 0x0, 0x0820CAAF
	callstd 0x2
	end

MossdeepCity_StevensHouse_EventScript_0020C9AD::
	lockall
	loadword 0x0, 0x0820CB77
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x20c9b8, 0x10
	.globl gJPText_0020C9C8
gJPText_0020C9C8: @ 0x0820C9C8
	.string "ダイゴ“{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}⋯⋯\p"
	.string "みてのとおり　なにも　ないけど\n"
	.string "ここが　ボクの　いえなんだ\p"
	.string "⋯⋯そうだ　さっきは　ありがとう\n"
	.string "これは　ボクからの　おれいの　きもち\l"
	.string "ひでんマシンの　ダイビングだ\p"
	.string "えんりょ　しないで　もっていきなよ$"

	.globl gJPText_0020CA36
gJPText_0020CA36: @ 0x0820CA36
	.string "ダイゴ“なみのりを　していると\n"
	.string "みずの　いろが　こい　ばしょが　ある\p"
	.string "そこで　ダイビングを　つかうと\n"
	.string "うみの　そこに　もぐれるから\p"
	.string "うかびたい　ときは\n"
	.string "もういちど　ダイビングを　つかうんだ\p"
	.string "ばしょに　よっては\n"
	.string "うかべない　ばあいも　あるけど$"

	.incbin "baserom_jp.gba", 0x20caaf, 0x2ae
