	nop 
	resetweather 
	waitstate 
	nop 
	setweather 0xA27
	return 
	.incbin "baserom_jp.gba", 0x284f15, 0x12a
