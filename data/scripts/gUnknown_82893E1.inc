	fadedefaultbgm 
	gotonative 0x2023F
	setworldmapflag 0x10
	callstd_if 0x1, 0xC
	setworldmapflag 0x8641
	.byte 0x94
	delay 0x1908
	setworldmapflag 0x0
	nop 
	nop 
	nop 
	.byte 0x19
	setworldmapflag 0x201
	.byte 0x94
	delay 0x3C08
	gettime 
	savebgm 0x241
	end 
	nop 
	callnative 0x412C2E01
	end 
	end 
	nop 
	.byte 0x49
	nop 
	nop 
	delay 0x8D55
	.byte 0x28
	.byte 0x08
