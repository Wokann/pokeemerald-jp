	nop 
	call 0xC020A28
	gotostd 0x8
	copyvar 0xE1, 0x2C0
	checkitemtype 0x56F8
	gotostd 0x2
	nop 
	call 0xF8480204
	addobject_at 0x208, 0x4
	call 0x56F84802
	gotostd 0x2
	nop 
	goto 0xC0006619
	return 
	.string "オツち{MUS_RG_FUCHSIA}{GREEN}{SE_LEDGE}{MUS_DUMMY}{SE_PC_LOGIN}{MUS_DUMMY}{SE_LEDGE}$"
	.incbin "baserom_jp.gba", 0x279cbf, 0x6
