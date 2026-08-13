	nop 
	.byte 0xD0
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x27b8ea, 0x7d
