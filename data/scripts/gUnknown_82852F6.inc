	nop 
	.byte 0xE4
	waitstate 
	gotostd_if 0x2, 0x14
	return 
	.incbin "baserom_jp.gba", 0x2852fd, 0x59
	.incbin "baserom_jp.gba", 0x285356, 0x14
