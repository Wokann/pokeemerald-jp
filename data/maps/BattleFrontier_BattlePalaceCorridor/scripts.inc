@ BattleFrontier_BattlePalaceCorridor scripts (JP map g26 m23 @ 0x0822AF25)

BattleFrontier_BattlePalaceCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_MapScriptTable_0022AF2B
	.byte 0

BattleFrontier_BattlePalaceCorridor_MapScriptTable_0022AF2B::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePalaceCorridor_EventScript_0022AF35
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_0022AF35::
	delay 0x10
	applymovement 0x1, 0x0822B03A
	applymovement 0xFF, 0x0822B03A
	waitmovement 0x0
	lockall
	setvar 0x8004, 0x3
	special CallBattlePalaceFunction
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, BattleFrontier_BattlePalaceCorridor_EventScript_0022B00D
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceCorridor_EventScript_0022B016
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, BattleFrontier_BattlePalaceCorridor_EventScript_0022B01F
	compare_var_to_value 0x800D, 0x3
	call_if 0x1, BattleFrontier_BattlePalaceCorridor_EventScript_0022B028
	compare_var_to_value 0x800D, 0x4
	call_if 0x1, BattleFrontier_BattlePalaceCorridor_EventScript_0022B031
	closemessage
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceCorridor_EventScript_0022AFD5
	applymovement 0x1, 0x0822B03F
	applymovement 0xFF, 0x0822B046
	waitmovement 0x0
	opendoor 0x6, 0x3
	waitmoncry
	applymovement 0x1, 0x0822B05C
	applymovement 0xFF, 0x0822B05B
	waitmovement 0x0
	closedoor 0x6, 0x3
	waitmoncry
	goto BattleFrontier_BattlePalaceCorridor_EventScript_0022B003

BattleFrontier_BattlePalaceCorridor_EventScript_0022AFD5::
	applymovement 0x1, 0x0822B04D
	applymovement 0xFF, 0x0822B054
	waitmovement 0x0
	opendoor 0xA, 0x3
	waitmoncry
	applymovement 0x1, 0x0822B05C
	applymovement 0xFF, 0x0822B05B
	waitmovement 0x0
	closedoor 0xA, 0x3
	waitmoncry

BattleFrontier_BattlePalaceCorridor_EventScript_0022B003::
	warp 0x1A18, 0xFF, 0x7, 0x4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_0022B00D::
	loadword 0x0, gJPText_0022B05F
	callstd 0x4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_0022B016::
	loadword 0x0, gJPText_0022B096
	callstd 0x4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_0022B01F::
	loadword 0x0, gJPText_0022B0CE
	callstd 0x4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_0022B028::
	loadword 0x0, gJPText_0022B104
	callstd 0x4
	return

BattleFrontier_BattlePalaceCorridor_EventScript_0022B031::
	loadword 0x0, gJPText_0022B12C
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x22b03a, 0x25
	.globl gJPText_0022B05F
gJPText_0022B05F: @ 0x0822B05F
	.string "ひとも　ポケモンも　みな　おなじ⋯⋯\p"
	.string "それぞれの　せいかくに　よって\n"
	.string "とくいなこと　にがてなことが　ある⋯⋯$"

	.globl gJPText_0022B096
gJPText_0022B096: @ 0x0822B096
	.string "にがてなこと　よりも　とくいな　こと⋯⋯\p"
	.string "ポケモンの　きもちに　なって\n"
	.string "おぼえさせる　わざを　かんがえて　みろ$"

	.globl gJPText_0022B0CE
gJPText_0022B0CE: @ 0x0822B0CE
	.string "せいかくとは　ふしぎな　ものだ⋯⋯\p"
	.string "おいつめられる　ことで　ガラッと\n"
	.string "こうどうが　かわる　ものも　おる⋯⋯$"

	.globl gJPText_0022B104
gJPText_0022B104: @ 0x0822B104
	.string "⋯⋯　そろそろ　ポケモンの　せいかくを\n"
	.string "みきわめられる　ように　なってきたか？$"

	.globl gJPText_0022B12C
gJPText_0022B12C: @ 0x0822B12C
	.string "おお⋯⋯　おぬしと　ポケモンの　あいだに\n"
	.string "つよい　こころの　きずなが　みえる⋯⋯$"

