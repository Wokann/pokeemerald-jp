@ LilycoveCity_House1 scripts (JP map g13 m12 @ 0x08209F66)

LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_00209F67::
	loadword 0x0, gJPText_00209F83
	callstd 0x2
	end

LilycoveCity_House1_EventScript_00209F70::
	lock
	faceplayer
	waitse
	playmoncry 0x13D, 0x0
	loadword 0x0, gJPText_00209FCF
	callstd 0x4
	waitdooranim
	release
	end

	.globl gJPText_00209F83
gJPText_00209F83: @ 0x08209F83
	.string "ポケモンは　にんげんの　パートナーであって\n"
	.string "けっして　にんげんの　どうぐ　じゃないよ\p"
	.string "そこを　かんちがい　しておる\n"
	.string "にんげんも　たまに　いるんだよ⋯⋯$"

	.globl gJPText_00209FCF
gJPText_00209FCF: @ 0x08209FCF
	.string "カクレオン“るろろ⋯⋯？$"
