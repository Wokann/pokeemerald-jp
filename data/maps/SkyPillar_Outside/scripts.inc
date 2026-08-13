@ SkyPillar_Outside scripts (JP map g24 m78 @ 0x0821BBED)

SkyPillar_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_EventScript_0021BBFD
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_EventScript_0021BC22
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_MapScriptTable_0021BC3F
	.byte 0

SkyPillar_Outside_EventScript_0021BBFD::
	compare_var_to_value 0x405E, 0x3
	call_if 0x1, SkyPillar_Outside_EventScript_0021BC14
	compare_var_to_value 0x405E, 0x4
	call_if 0x4, SkyPillar_Outside_EventScript_0021BC18
	end

SkyPillar_Outside_EventScript_0021BC14::
	setflag 0x4000
	return

SkyPillar_Outside_EventScript_0021BC18::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	return

SkyPillar_Outside_EventScript_0021BC22::
	checkflag 0x137
	call_if 0x1, SkyPillar_Outside_EventScript_0021BC2C
	end

SkyPillar_Outside_EventScript_0021BC2C::
	setmetatile 0xE, 0x4, 0x2AA, 0x0
	setmetatile 0xE, 0x5, 0x2B2, 0x0
	return

SkyPillar_Outside_MapScriptTable_0021BC3F::
	map_script_2 0x405E, 0x3, SkyPillar_Outside_EventScript_0021BC49
	.2byte 0

SkyPillar_Outside_EventScript_0021BC49::
	lockall
	applymovement 0x1, 0x0821BD18
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, gJPText_0021BD56
	callstd 0x4
	closemessage
	delay 0x1E
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x3
	special sub_081395D0
	waitstate
	delay 0x28
	loadword 0x0, gJPText_0021BDB5
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0821BD30
	applymovement 0x1, 0x0821BD23
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x3
	setvar 0x8006, 0x14
	setvar 0x8007, 0x5
	special sub_081395D0
	waitstate
	delay 0x14
	applymovement 0x1, 0x08243627
	waitmovement 0x0
	delay 0xA
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	delay 0x14
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	loadword 0x0, gJPText_0021BDD5
	callstd 0x4
	closemessage
	setflag 0x88A
	setweather 0xF
	resetweather
	special WaitWeather
	delay 0x1E
	loadword 0x0, gJPText_0021BDF8
	callstd 0x4
	closemessage
	playse 0x9
	fadescreenswapbuffers 0x1
	clearflag 0x4000
	setvar 0x405E, 0x4
	removeobject 0x1
	clearflag 0x330
	fadescreenswapbuffers 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21bd18, 0x25
SkyPillar_Outside_EventScript_0021BD3D::
	end

gUnknown_821BD3E:: @ 0x0821BD3E
	.incbin "baserom_jp.gba", 0x21bd3e, 0x18
	.globl gJPText_0021BD56
gJPText_0021BD56: @ 0x0821BD56
	.string "ミクリ“やっ　ごめん　ごめん！\p"
	.string "あんまり　あわてた　ものだから\n"
	.string "きみを　おいてきて　しまったよ！\p"
	.string "しまっていた　そらのはしらの　とびらは\n"
	.string "わたしが　あけて　おいた\p"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　さあ　いこう！$"

	.globl gJPText_0021BDB5
gJPText_0021BDB5: @ 0x0821BDB5
	.string "ミクリ“じしんだ！\p"
	.string "こうしては　いられない\n"
	.string "さきを　いそごう！$"

	.globl gJPText_0021BDD5
gJPText_0021BDD5: @ 0x0821BDD5
	.string "ミクリ“うーむ　じょうきょうは\n"
	.string "だんだん　わるくなって　きている⋯⋯$"

	.globl gJPText_0021BDF8
gJPText_0021BDF8: @ 0x0821BDF8
	.string "ミクリ“まずいな⋯⋯\p"
	.string "てんこうの　みだれが　このあたりまで\n"
	.string "ひろがり　はじめている⋯⋯\p"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}\p"
	.string "ここを　のぼって　いけば\n"
	.string "レックウザが　いるはずだ\p"
	.string "わたしは　まちのことが　しんぱい　だから\n"
	.string "さきに　ルネまで　もどっていよう！\p"
	.string "ここは　きみに　まかせるから\n"
	.string "しっかり　たのんだよ！$"

