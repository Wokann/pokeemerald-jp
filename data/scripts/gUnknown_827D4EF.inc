	nop 
	compare_local_to_value 0x28, 0x0
	setweather 0xA27
	return 
	.incbin "baserom_jp.gba", 0x27d4f7, 0x26
