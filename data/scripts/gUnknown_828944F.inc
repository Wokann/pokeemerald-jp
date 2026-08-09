	fadedefaultbgm 
	gotonative 0x2023F
	setworldmapflag 0x10
	callstd_if 0x3, 0xC
	return 
	.byte 0x41
	pokemart 0x19082894
	return 
	nop 
	nop 
	nop 
	nop 
	nop 
	.byte 0x19
	return 
	setworldmapflag 0x9470
	delay 0x3C08
	gettime 
	savebgm 0x241
	end 
	nop 
	callnative 0x412C2E03
	end 
	end 
	nop 
	.byte 0x49
	nop 
	nop 
	delay 0x8D55
	delay 0x1008
	.byte 0x95
	nop 
	.byte 0x12
	.byte 0x40
	nop 
	.byte 0x3C
