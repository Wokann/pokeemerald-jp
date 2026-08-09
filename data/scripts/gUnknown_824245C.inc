	.byte 0x4F
	loadword 0x80, 0x82424D4
	.byte 0x51
	nop 
	nop 
	.byte 0x25
	fadeinbgm 0x0
	dotrainerbattle 
	gotobeatenscript 
