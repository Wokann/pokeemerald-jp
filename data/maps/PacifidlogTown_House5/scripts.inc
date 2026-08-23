@ PacifidlogTown_House5 scripts (JP map g7 m6 @ 0x081F8055)

PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_001F8056::
	lock
	faceplayer
	specialvar 0x800D, IsMirageIslandPresent
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PacifidlogTown_House5_EventScript_001F8072
	loadword 0x0, gJPText_001F8085
	callstd 0x4
	release
	end

PacifidlogTown_House5_EventScript_001F8072::
	loadword 0x0, gJPText_001F8099
	callstd 0x4
	release
	end

PacifidlogTown_House5_EventScript_001F807C::
	loadword 0x0, gJPText_001F80B5
	callstd 0x2
	end

	.globl gJPText_001F8085
gJPText_001F8085: @ 0x081F8085
	.string "きょうは　マボロシじま　みえんのう⋯⋯$"

	.globl gJPText_001F8099
gJPText_001F8099: @ 0x081F8099
	.string "なっ　なんと！\n"
	.string "きょうは　マボロシじま　みえるのじゃ！$"

	.globl gJPText_001F80B5
gJPText_001F80B5: @ 0x081F80B5
	.string "マボロシじま⋯⋯\n"
	.string "おそらく　しんきろうの　かんけいで\l"
	.string "みえたり　みえなかったり　するんだろう\p"
	.string "いや　ひょっとしたら　ほんとうに\n"
	.string "あらわれたり　きえたり　しているのか⋯⋯？$"
