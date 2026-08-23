@ PacifidlogTown_House1 scripts (JP map g7 m2 @ 0x081F793E)

PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_001F793F::
	loadword 0x0, gJPText_001F7951
	callstd 0x2
	end

PacifidlogTown_House1_EventScript_001F7948::
	loadword 0x0, gJPText_001F79BE
	callstd 0x2
	end

	.globl gJPText_001F7951
gJPText_001F7951: @ 0x081F7951
	.string "ホウエンちほう　には\n"
	.string "いわ⋯⋯　こおり⋯⋯　はがね⋯⋯\p"
	.string "それぞれの　ちからを　つかさどる\n"
	.string "3びきの　ポケモンが\l"
	.string "それぞれ　どこかの　どうくつに　いる⋯⋯\p"
	.string "おれ　ちいさな　ころに\n"
	.string "そんな　はなしを　きいたことが　あるよ$"

	.globl gJPText_001F79BE
gJPText_001F79BE: @ 0x081F79BE
	.string "‘むっつの　てんが\n"
	.string "　みっつの　とびらを　あける’\p"
	.string "おじいちゃんが　よく　いっていたけど\n"
	.string "いまだに　なんのことだか　わからないわ$"
