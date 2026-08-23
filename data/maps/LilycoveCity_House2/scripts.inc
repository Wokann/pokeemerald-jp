@ LilycoveCity_House2 scripts (JP map g13 m13 @ 0x08209FDC)

LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_00209FDD::
	lock
	faceplayer
	checkflag 0xEA
	goto_if 0x1, LilycoveCity_House2_EventScript_0020A014
	loadword 0x0, gJPText_0020A01E
	callstd 0x4
	setorcopyvar 0x8000, 0x14C
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xEA
	loadword 0x0, gJPText_0020A03E
	callstd 0x4
	release
	end

LilycoveCity_House2_EventScript_0020A014::
	loadword 0x0, gJPText_0020A03E
	callstd 0x4
	release
	end

	.globl gJPText_0020A01E
gJPText_0020A01E: @ 0x0820A01E
	.string "むにゃむにゃ⋯⋯\p"
	.string "ぼく　ねぼけて　いるから\n"
	.string "これを　あげる⋯⋯$"

	.globl gJPText_0020A03E
gJPText_0020A03E: @ 0x0820A03E
	.string "むにゃむにゃ⋯⋯\p"
	.string "ねる　こは　そだつ⋯⋯\n"
	.string "ねむって　たいりょく　かいふく⋯⋯$"
