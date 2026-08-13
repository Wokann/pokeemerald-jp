	nop 
	.byte 0xFC
	waitstate 
	nop 
	playse 0x1927
	fadescreenspeed 0x0, 0xC0
	return 
	.incbin "baserom_jp.gba", 0x2830c0, 0xa1
