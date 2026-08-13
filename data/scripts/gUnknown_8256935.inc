	lockall
	checkpartymove 0x123
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x8256974
	bufferpartymonnick 0x0, 0x800D
	setfieldeffectarg 0x0, 0x800D
	setfieldeffectarg 0x1, 0x1
	loadword 0x0, 0x82569F2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8256983
	loadword 0x0, 0x82569B8
	callstd 0x4
	dofieldeffect 0x2C
	goto 0x8256983
	end
	lockall
	loadword 0x0, 0x82569CA
	callstd 0x4
	goto 0x8256983
	end
	releaseall
	end
	compare_local_to_value 0x6, 0x2
	nop
	return
	.incbin "baserom_jp.gba", 0x25698A, 0x16
	.globl gJPText_002569A0
gJPText_002569A0: @ 0x082569A0
	.string "ふかい　うみだ！\n"
	.string "ダイビングを　つかいますか？$"

	.globl gJPText_002569B8
gJPText_002569B8: @ 0x082569B8
	.string "{B_COPY_VAR_1}　は　ダイビングを　つかった！$"

	.incbin "baserom_jp.gba", 0x2569ca, 0x28
	.globl gJPText_002569F2
gJPText_002569F2: @ 0x082569F2
	.string "うえから　ひかりが　さしこんでいる！\n"
	.string "ダイビングを　つかいますか？$"

