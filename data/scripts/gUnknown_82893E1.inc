	fadedefaultbgm 
	gotonative 0x2023F
	jp_raw_01_u16 0x10
	callstd_if 0x1, 0xC
	jp_raw_01_u16 0x8641
	.byte 0x94
	delay 0x1908
	jp_raw_01_u16 0x0
	nop 
	nop 
	nop 
	copyvar 0x101, 0x9402
	delay 0x3C08
	gettime 
	savebgm 0x241
	end 
	nop 
	callnative 0x412C2E01
	end 
	end 
	nop 
	addpcitem 0x0, 0x5528
	showcontestresults
	.byte 0x28
	.byte 0x08
