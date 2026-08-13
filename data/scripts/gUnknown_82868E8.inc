	nop 
	.byte 0xF0
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x2868ec, 0x5a
