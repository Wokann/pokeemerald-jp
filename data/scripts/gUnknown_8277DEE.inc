	nop
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram
	gotostd 0x19
	fadescreenspeed 0x0, 0xC0
	return
	.byte 0xC9
	checkdecorspace 0x80D
	goto 0x2000005
	nop
	nop
	nop
	checktrainerflag 0x1E00
	nop
	.incbin "baserom_jp.gba", 0x277E0B, 0x77
