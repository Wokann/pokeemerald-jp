@ LilycoveCity_MoveDeletersHouse scripts (JP map g13 m11 @ 0x08209D70)

LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_00209D71::
	lockall
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	loadword 0x0, gJPText_00209E63
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209DA1
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E4C
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_00209DA1::
	loadword 0x0, gJPText_00209EA5
	callstd 0x4
	special ChoosePartyMon
	waitstate
	compare_var_to_value 0x8004, 0xFF
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E4C
	special IsSelectedMonEgg
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E42
	special GetNumMovesSelectedMonHas
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E35
	loadword 0x0, gJPText_00209EB5
	callstd 0x4
	fadescreen 0x1
	special MoveDeleterChooseMoveToForget
	fadescreen 0x0
	compare_var_to_value 0x8005, 0x4
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209DA1
	special BufferMoveDeleterNicknameAndMove
	loadword 0x0, gJPText_00209EE2
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E16
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E4C
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_00209E16::
	special IsLastMonThatKnowsSurf
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_MoveDeletersHouse_EventScript_00209E56
	special MoveDeleterForgetMove
	playfanfare 0x17A
	waitfanfare
	loadword 0x0, gJPText_00209EF1
	callstd 0x4
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_00209E35::
	special BufferMoveDeleterNicknameAndMove
	loadword 0x0, gJPText_00209EC8
	callstd 0x4
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_00209E42::
	loadword 0x0, gJPText_00209F2B
	callstd 0x4
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_00209E4C::
	loadword 0x0, gJPText_00209F0F
	callstd 0x4
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_00209E56::
	special BufferMoveDeleterNicknameAndMove
	loadword 0x0, gJPText_00209F4A
	callstd 0x4
	releaseall
	end

	.globl gJPText_00209E63
gJPText_00209E63: @ 0x08209E63
	.string "えーと⋯⋯\n"
	.string "そうじゃ　わし　わすれじいさん\p"
	.string "ポケモンの　わざを\n"
	.string "わすれさせる　ことが　できるんじゃ！\p"
	.string "わざを　わすれ　させるかね？$"

	.globl gJPText_00209EA5
gJPText_00209EA5: @ 0x08209EA5
	.string "どの　ポケモンに　するんじゃ？$"

	.globl gJPText_00209EB5
gJPText_00209EB5: @ 0x08209EB5
	.string "どの　わざを\n"
	.string "わすれ　させるんじゃ？$"

	.globl gJPText_00209EC8
gJPText_00209EC8: @ 0x08209EC8
	.string "{STRING 0x02}は　わざを　1つしか\n"
	.string "もってない　ようじゃ⋯⋯$"

	.globl gJPText_00209EE2
gJPText_00209EE2: @ 0x08209EE2
	.string "むむ！\n"
	.string "{STRING 0x02}の　{STRING 0x03}じゃな？$"

	.globl gJPText_00209EF1
gJPText_00209EF1: @ 0x08209EF1
	.string "だいせいこう　じゃ！\p"
	.string "{STRING 0x02}は　{STRING 0x03}を\n"
	.string "わすれた　ようじゃ！$"

	.globl gJPText_00209F0F
gJPText_00209F0F: @ 0x08209F0F
	.string "わすれさせたい　わざが　あったら\n"
	.string "また　くるのじゃぞ！$"

	.globl gJPText_00209F2B
gJPText_00209F2B: @ 0x08209F2B
	.string "なぬ！？　タマゴは\n"
	.string "わざを　おぼえていない　ようじゃが⋯⋯？$"

	.globl gJPText_00209F4A
gJPText_00209F4A: @ 0x08209F4A
	.string "むむ！\p"
	.string "{STRING 0x02}は　なみのりを\n"
	.string "わすれたくない　ようじゃ！$"
