@ FallarborTown_CozmosHouse scripts (JP map g5 m6 @ 0x081F5E78)

FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_001F5E79::
	lock
	faceplayer
	checkflag 0xE5
	goto_if 0x1, FallarborTown_CozmosHouse_EventScript_001F5F18
	checkitem 0x118, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FallarborTown_CozmosHouse_EventScript_001F5E9E
	loadword 0x0, gJPText_001F5F54
	callstd 0x4
	release
	end

FallarborTown_CozmosHouse_EventScript_001F5E9E::
	checkflag 0x2
	call_if 0x0, FallarborTown_CozmosHouse_EventScript_001F5EF1
	checkflag 0x2
	call_if 0x1, FallarborTown_CozmosHouse_EventScript_001F5F02
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, FallarborTown_CozmosHouse_EventScript_001F5F0B
	loadword 0x0, gJPText_001F6035
	callstd 0x4
	setorcopyvar 0x8000, 0x13B
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setvar 0x8004, 0x118
	call 0x08243467
	setflag 0xE5
	loadword 0x0, gJPText_001F605B
	callstd 0x4
	release
	end

FallarborTown_CozmosHouse_EventScript_001F5EF1::
	loadword 0x0, gJPText_001F5F54
	callstd 0x4
	loadword 0x0, gJPText_001F5FBC
	callstd 0x5
	return

FallarborTown_CozmosHouse_EventScript_001F5F02::
	loadword 0x0, gJPText_001F609F
	callstd 0x5
	return

FallarborTown_CozmosHouse_EventScript_001F5F0B::
	setflag 0x2
	loadword 0x0, gJPText_001F6085
	callstd 0x4
	release
	end

FallarborTown_CozmosHouse_EventScript_001F5F18::
	loadword 0x0, gJPText_001F605B
	callstd 0x4
	release
	end

FallarborTown_CozmosHouse_EventScript_001F5F22::
	lock
	faceplayer
	checkflag 0xE5
	goto_if 0x1, FallarborTown_CozmosHouse_EventScript_001F5F4A
	checkflag 0x8B
	goto_if 0x1, FallarborTown_CozmosHouse_EventScript_001F5F40
	loadword 0x0, gJPText_001F60E3
	callstd 0x4
	release
	end

FallarborTown_CozmosHouse_EventScript_001F5F40::
	loadword 0x0, gJPText_001F611C
	callstd 0x4
	release
	end

FallarborTown_CozmosHouse_EventScript_001F5F4A::
	loadword 0x0, gJPText_001F6138
	callstd 0x4
	release
	end

	.globl gJPText_001F5F54
gJPText_001F5F54: @ 0x081F5F54
	.string "ソライシ“ああ⋯⋯\n"
	.string "マグマだんに　だまされたからと　いって\l"
	.string "いんせきが　てに　はいる　ばしょを\l"
	.string "おしえてしまったら　だめ　だなあ⋯⋯\p"
	.string "りゅうせいのたき　の　いんせき\n"
	.string "もう　ぼくの　モノには　ならないよな⋯⋯$"

	.globl gJPText_001F5FBC
gJPText_001F5FBC: @ 0x081F5FBC
	.string "おお！　ええ？\p"
	.string "それは⋯⋯\p"
	.string "もしかして　もしかすると⋯⋯\p"
	.string "マグマだんが　りゅうせいのたき　から\n"
	.string "もっていった　いんせき　ですか⋯⋯！？\p"
	.string "よかったら　ぼくに　ください！\p"
	.string "ただで　とは　いいません\n"
	.string "かわりに　この　わざマシンを\l"
	.string "あげますから⋯⋯$"

	.globl gJPText_001F6035
gJPText_001F6035: @ 0x081F6035
	.string "ソライシ“この　わざマシンは\n"
	.string "ぼくの　きもちです\l"
	.string "ぜひ　つかってください！$"

	.globl gJPText_001F605B
gJPText_001F605B: @ 0x081F605B
	.string "ソライシ“いやー　すごく　うれしいな\n"
	.string "これで　ぼくの　けんきゅうも　はかどります！$"

	.globl gJPText_001F6085
gJPText_001F6085: @ 0x081F6085
	.string "ソライシ“そんな⋯⋯\n"
	.string "ものすごく　がっかりだよ⋯⋯$"

	.globl gJPText_001F609F
gJPText_001F609F: @ 0x081F609F
	.string "ソライシ“その　いんせき⋯⋯\n"
	.string "よかったら　ぼくに　ください！\p"
	.string "ただで　とは　いいません\n"
	.string "かわりに　この　わざマシンを\l"
	.string "あげますから⋯⋯$"

	.globl gJPText_001F60E3
gJPText_001F60E3: @ 0x081F60E3
	.string "ソライシはかせは\n"
	.string "マグマだんの　ひとと　いっしょに\l"
	.string "114ばん　どうろに　ある\l"
	.string "りゅうせいのたきに　いきましたよ$"

	.globl gJPText_001F611C
gJPText_001F611C: @ 0x081F611C
	.string "ソライシはかせ⋯⋯\n"
	.string "あんなに　おちこんで　かわいそう！$"

	.globl gJPText_001F6138
gJPText_001F6138: @ 0x081F6138
	.string "ソライシはかせ　ったら\n"
	.string "あんなに　よろこんで　かわいい！$"
