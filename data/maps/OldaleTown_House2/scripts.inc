@ OldaleTown_House2 scripts (JP map g2 m1 @ 0x081F2949)

OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_001F294A::
	loadword 0x0, gJPText_001F295C
	callstd 0x2
	end

OldaleTown_House2_EventScript_001F2953::
	loadword 0x0, gJPText_001F297B
	callstd 0x2
	end

	.globl gJPText_001F295C
gJPText_001F295C: @ 0x081F295C
	.string "ポケモンって　たたかうと\n"
	.string "レベルアップして　つよくなるのよ！$"

	.globl gJPText_001F297B
gJPText_001F297B: @ 0x081F297B
	.string "つれて　あるく　ポケモンが　つよかったら\n"
	.string "とおくまで　いけるように　なるね！$"
