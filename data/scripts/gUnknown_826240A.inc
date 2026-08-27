	lockall
	special GetPokeblockFeederInFront
	compare_var_to_value 0x800D, 0xFFFF
	goto_if 0x5, 0x8262449
	loadword 0x0, 0x82624B7
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x826242E
	releaseall
	end
	fadescreen 0x1
	special OpenPokeblockCaseOnFeeder
	compare_var_to_value 0x800D, 0xFFFF
	goto_if 0x5, 0x8262440
	end
	message 0x82624DC
	waitmessage
	waitbuttonpress
	releaseall
	end
	message 0x82624CD
	waitmessage
	waitbuttonpress
	releaseall
	end
	.globl gJPText_00262452
gJPText_00262452: @ 0x08262452
	.string "サファリゾーンを\n"
	.string "このまま　しゅうりょう　しますか？$"

	.globl gJPText_0026246D
gJPText_0026246D: @ 0x0826246D
	.string "ピンポーン！　じかん　でーす！\n"
	.string "サファリゲームを　しゅうりょう　します$"

	.globl gJPText_00262491
gJPText_00262491: @ 0x08262491
	.string "サファリボールを　つかいきったので\n"
	.string "サファリゲームを　しゅうりょう　します$"

	.globl gJPText_002624B7
gJPText_002624B7: @ 0x082624B7
	.string "ポロックおきばに　ポロックを　おきますか？$"

	compare_addr_to_value 0x2FD0041, 0x37
	nop
	copyvar 0x500A, 0x213
	compare_addr_to_value 0x2FDFF0D, 0x2D
	.byte 0xFE
	.incbin "baserom_jp.gba", 0x2624E0, 0x813
