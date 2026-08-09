	end 
	return 
	.byte 0xED
	.byte 0x45
	nop 
	.byte 0x11
	nop 
	nop 
	nop 
	nop 
	loadbyte 0xC0, 0x0
	.byte 0x12
	.byte 0x40
	nop 
	fadedefaultbgm 
	gotonative 0x2023F
	returnram 
	.byte 0x80
	nop 
	gotopostbattlescript 
	.byte 0x3C
