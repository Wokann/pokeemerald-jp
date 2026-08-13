	nop
	doweather
	waitstate
	returnram
	callstd_if 0x5, 0x22
	return
	setflag 0xCC1B
	nop
	.incbin "baserom_jp.gba", 0x2820D2, 0x3F
