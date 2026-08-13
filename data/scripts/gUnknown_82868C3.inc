	nop 
	.byte 0xF0
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x2868c7, 0x21
