@ FallarborTown_MoveRelearnersHouse scripts (JP map g5 m7 @ 0x081F6155)

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_001F6156::
	lockall
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	checkflag 0x1
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F617B
	loadword 0x0, gJPText_001F622F
	callstd 0x4
	setflag 0x1
	goto FallarborTown_MoveRelearnersHouse_EventScript_001F617B
	end

FallarborTown_MoveRelearnersHouse_EventScript_001F617B::
	checkitem 0x6F, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F6225
	loadword 0x0, gJPText_001F62A4
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F6225
	goto FallarborTown_MoveRelearnersHouse_EventScript_001F61A9
	end

FallarborTown_MoveRelearnersHouse_EventScript_001F61A9::
	loadword 0x0, gJPText_001F62CB
	callstd 0x4
	special ChooseMonForMoveRelearner
	waitstate
	compare_var_to_value 0x8004, 0xFF
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F6225
	special IsSelectedMonEgg
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F6217
	compare_var_to_value 0x8005, 0x0
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F6209
	goto FallarborTown_MoveRelearnersHouse_EventScript_001F61DF
	end

FallarborTown_MoveRelearnersHouse_EventScript_001F61DF::
	loadword 0x0, gJPText_001F62DB
	callstd 0x4
	special TeachMoveRelearnerMove
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, FallarborTown_MoveRelearnersHouse_EventScript_001F61A9
	loadword 0x0, gJPText_001F6310
	callstd 0x4
	removeitem 0x6F, 0x1
	goto FallarborTown_MoveRelearnersHouse_EventScript_001F6225
	end

FallarborTown_MoveRelearnersHouse_EventScript_001F6209::
	loadword 0x0, gJPText_001F62E9
	callstd 0x4
	goto FallarborTown_MoveRelearnersHouse_EventScript_001F61A9
	end

FallarborTown_MoveRelearnersHouse_EventScript_001F6217::
	loadword 0x0, gJPText_001F634D
	callstd 0x4
	goto FallarborTown_MoveRelearnersHouse_EventScript_001F61A9
	end

FallarborTown_MoveRelearnersHouse_EventScript_001F6225::
	loadword 0x0, gJPText_001F632B
	callstd 0x4
	releaseall
	end

	.globl gJPText_001F622F
gJPText_001F622F: @ 0x081F622F
	.string "ぼく　ポケモン　わざマニア\p"
	.string "ポケモンが　せいちょうして　おぼえていく\n"
	.string "わざを　すべて　しっていて\l"
	.string "ポケモンに　おしえることが　できるんだ！\p"
	.string "ぼくが　いま　あつめている\n"
	.string "ハートのウロコを　くれたら\l"
	.string "しってる　わざを　おしえてあげるよ！$"

	.globl gJPText_001F62A4
gJPText_001F62A4: @ 0x081F62A4
	.string "おおっ！\n"
	.string "それは　まさしく　ハートのウロコ！\p"
	.string "わざを　おぼえさせたいんだね？$"

	.globl gJPText_001F62CB
gJPText_001F62CB: @ 0x081F62CB
	.string "どの　ポケモンに　するんだい？$"

	.globl gJPText_001F62DB
gJPText_001F62DB: @ 0x081F62DB
	.string "どの　わざに　するんだい？$"

	.globl gJPText_001F62E9
gJPText_001F62E9: @ 0x081F62E9
	.string "ごめんね⋯⋯\p"
	.string "ぼくが　その　ポケモンに\n"
	.string "おしえられる　わざは　ないみたいだよ$"

	.globl gJPText_001F6310
gJPText_001F6310: @ 0x081F6310
	.string "{STRING 0x01}は　おれいに\n"
	.string "ハートのウロコを　1まい　あげた！$"

	.globl gJPText_001F632B
gJPText_001F632B: @ 0x081F632B
	.string "おぼえさせたい　わざが　あったら\n"
	.string "ハートのウロコを　もってきてね！$"

	.globl gJPText_001F634D
gJPText_001F634D: @ 0x081F634D
	.string "えっ？\n"
	.string "タマゴに　おしえられる　わざは　ないよ$"
