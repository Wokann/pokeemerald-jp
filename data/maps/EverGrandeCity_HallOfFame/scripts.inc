@ EverGrandeCity_HallOfFame scripts (JP map g16 m11 @ 0x08211287)

EverGrandeCity_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_MapScriptTable_002112A1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_MapScriptTable_00211292
	.byte 0

EverGrandeCity_HallOfFame_MapScriptTable_00211292::
	map_script_2 0x4001, 0x0, EverGrandeCity_HallOfFame_EventScript_0021129C
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_0021129C::
	turnobject 0xFF, 0x2
	end

EverGrandeCity_HallOfFame_MapScriptTable_002112A1::
	map_script_2 0x4001, 0x0, EverGrandeCity_HallOfFame_EventScript_002112AB
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_002112AB::
	lockall
	applymovement 0x1, 0x0821135C
	applymovement 0xFF, 0x0821135C
	waitmovement 0x0
	applymovement 0x1, 0x0824362B
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, gJPText_00211369
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08211363
	applymovement 0xFF, 0x08211363
	waitmovement 0x0
	delay 0x14
	applymovement 0x1, 0x0824362B
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, gJPText_002113B4
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	delay 0x14
	dofieldeffect 0x3E
	waitfieldeffect 0x3E
	delay 0x28
	setvar 0x4001, 0x1
	call 0x0824285B
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, EverGrandeCity_HallOfFame_EventScript_00211344
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, EverGrandeCity_HallOfFame_EventScript_00211350
	end

EverGrandeCity_HallOfFame_EventScript_00211344::
	setrespawn 0x1
	fadescreenspeed 0x1, 0x18
	special GameClear
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_00211350::
	setrespawn 0x2
	fadescreenspeed 0x1, 0x18
	special GameClear
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21135c, 0xd
	.globl gJPText_00211369
gJPText_00211369: @ 0x08211369
	.string "ミクリ“ここは⋯⋯\p"
	.string "はげしい　たたかいを　かちぬいた\n"
	.string "ポケモンを　きろくする　ばしょ\p"
	.string "リーグ　チャンピオンの\n"
	.string "えいこうを　たたえる　ための　へやさ！$"

	.globl gJPText_002113B4
gJPText_002113B4: @ 0x082113B4
	.string "ミクリ“さあ！　ポケモン　リーグを\n"
	.string "かちぬいた　きみの　なまえと\p"
	.string "ともに　たたかった　きみの　パートナーを\n"
	.string "この　マシンに　きろく　するのだ！$"

