	end 
	return 
	.byte 0x39
	.byte 0x20
	nop 
	loadbyte 0xBE, 0x0
	.byte 0x12
	.byte 0x40
	nop 
	fadedefaultbgm 
	gotonative 0x2023F
	returnram 
	.byte 0x80
	nop 
	hidemonpic 
	setworldmapflag 0x3C01
