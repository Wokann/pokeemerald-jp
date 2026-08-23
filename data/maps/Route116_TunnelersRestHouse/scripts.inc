@ Route116_TunnelersRestHouse scripts (JP map g21 m0 @ 0x08212820)

Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_EventScript_00212826
	.byte 0

Route116_TunnelersRestHouse_EventScript_00212826::
	setflag 0x8BA
	end

Route116_TunnelersRestHouse_EventScript_0021282A::
	loadword 0x0, gJPText_0021285B
	callstd 0x2
	end

Route116_TunnelersRestHouse_EventScript_00212833::
	loadword 0x0, gJPText_002128DD
	callstd 0x2
	end

Route116_TunnelersRestHouse_EventScript_0021283C::
	lock
	faceplayer
	checkflag 0xC7
	goto_if 0x1, Route116_TunnelersRestHouse_EventScript_00212851
	loadword 0x0, gJPText_0021295A
	callstd 0x4
	release
	end

Route116_TunnelersRestHouse_EventScript_00212851::
	loadword 0x0, gJPText_0021299F
	callstd 0x4
	release
	end

	.globl gJPText_0021285B
gJPText_0021285B: @ 0x0821285B
	.string "あの　カナシダトンネル⋯⋯\p"
	.string "はじめは　たくさんの　にんげんと\n"
	.string "さいしんの　キカイで　ほりすすんでいた\p"
	.string "だが　そのまま　ほりすすむと\n"
	.string "あたりの　ポケモンに\l"
	.string "あくえいきょうを　あたえる　らしくてね\p"
	.string "で　おれら　どうしようもなく\n"
	.string "ここで　ぼんやりと　しているわけさ$"

	.globl gJPText_002128DD
gJPText_002128DD: @ 0x082128DD
	.string "どうしても　シダケに　いきたい\n"
	.string "やつが　じぶんの　ちから　だけで\l"
	.string "トンネルを　ほっているよ\p"
	.string "にんげんの　ちからで　すこしずつ　ほれば\n"
	.string "ポケモンを　おどろかせなくて　すむし\l"
	.string "まわりの　しぜんにも　わるい　えいきょうを\l"
	.string "あたえないで　すむって　いってな$"

	.globl gJPText_0021295A
gJPText_0021295A: @ 0x0821295A
	.string "トンネルを　つかわずに　ここから\n"
	.string "シダケに　いくなら　うみを　わたり\l"
	.string "ムロから　カイナ　そして\l"
	.string "キンセツを　とおって　いくしか　ないな！$"

	.globl gJPText_0021299F
gJPText_0021299F: @ 0x0821299F
	.string "なんでも　シダケ　までの\n"
	.string "トンネルが　つうじた　らしいぞ！\p"
	.string "ねがい　つづければ\n"
	.string "いつかは　かなう　って　ことなんだな！$"
