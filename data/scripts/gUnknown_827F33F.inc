	nop 
	resetweather 
	waitstate 
	nop 
	setweather 0xA27
	return 
	.incbin "baserom_jp.gba", 0x27f347, 0xf7
