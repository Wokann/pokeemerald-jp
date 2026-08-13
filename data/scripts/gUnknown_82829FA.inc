	nop 
	.byte 0xF4
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x2829fe, 0xb7
