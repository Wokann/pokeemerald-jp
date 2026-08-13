	nop 
	.byte 0xE2
	waitstate 
	nop 
	.byte 0xF0
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x27d6ca, 0x56
