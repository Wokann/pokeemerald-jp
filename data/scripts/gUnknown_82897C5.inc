	loadbyte 0x2A, 0x0
	loadbytefromaddr 0x1640040
	fadedefaultbgm 
	gotonative 0x2023F
	jp_raw_01_u16 0x10
	callstd_if 0x1, 0xC
	jp_raw_01_u16 0x119
	nop 
	nop 
	nop 
	nop 
	nop 
	gotonative 0x82897E6
	.byte 0x3E
