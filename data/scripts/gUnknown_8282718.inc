	nop 
	.byte 0xF0
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x28271c, 0x153
