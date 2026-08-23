@ OldaleTown_House1 scripts (JP map g2 m0 @ 0x081F28D3)

OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_001F28D4::
	loadword 0x0, gJPText_001F28DD
	callstd 0x2
	end

	.globl gJPText_001F28DD
gJPText_001F28DD: @ 0x081F28DD
	.string "ポケモンしょうぶの　とき\n"
	.string "ポケモンの　リストの　ひだりに　いる\l"
	.string "ポケモンが　とびだして　たたかうの\p"
	.string "だから　つれあるく　ポケモンが　ふえてきたら\n"
	.string "ポケモンの　じゅんばんを　かえると\l"
	.string "しょうぶが　ゆうりに　なるかも！$"
