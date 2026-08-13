	nop 
	.byte 0xE2
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x27bcab, 0x3f
