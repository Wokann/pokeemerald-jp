@ PacifidlogTown_House4 scripts (JP map g7 m5 @ 0x081F7F3D)

PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_001F7F3E::
	loadword 0x0, gJPText_001F7FD3
	callstd 0x2
	end

PacifidlogTown_House4_EventScript_001F7F47::
	loadword 0x0, gJPText_001F7F85
	callstd 0x2
	end

PacifidlogTown_House4_EventScript_001F7F50::
	lock
	faceplayer
	loadword 0x0, gJPText_001F7FE9
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PacifidlogTown_House4_EventScript_001F7F71
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PacifidlogTown_House4_EventScript_001F7F7B
	end

PacifidlogTown_House4_EventScript_001F7F71::
	loadword 0x0, gJPText_001F7FF6
	callstd 0x4
	release
	end

PacifidlogTown_House4_EventScript_001F7F7B::
	loadword 0x0, gJPText_001F8015
	callstd 0x4
	release
	end

	.globl gJPText_001F7F85
gJPText_001F7F85: @ 0x081F7F85
	.string "ホウエンの　そらたかくを　とんでいく\n"
	.string "ポケモンを　みた！　って　ひとが　いるけど\p"
	.string "ずっと　とびまわって　いるのかしら？\n"
	.string "どこかで　やすんだり　しそうだけど$"

	.globl gJPText_001F7FD3
gJPText_001F7FD3: @ 0x081F7FD3
	.string "おそらの　ポケモン！\n"
	.string "おそらの　ポケモン！$"

	.globl gJPText_001F7FE9
gJPText_001F7FE9: @ 0x081F7FE9
	.string "きみ　どこから　きたの？$"

	.globl gJPText_001F7FF6
gJPText_001F7FF6: @ 0x081F7FF6
	.string "はい⋯⋯？\n"
	.string "ハイ⋯　タウン⋯⋯？\p"
	.string "しらないなぁ　そんな　まち$"

	.globl gJPText_001F8015
gJPText_001F8015: @ 0x081F8015
	.string "いいえ　って　そんな⋯⋯\n"
	.string "どこからも　きてない　はずが　ないでしょ\p"
	.string "ま　まさか　きみ⋯⋯\n"
	.string "うみの　そこで　うまれた　とか⋯⋯？$"
