	nop 
	gotostd 0x28
	nop 
	.byte 0xEA
	waitstate 
	return 
	.incbin "baserom_jp.gba", 0x27b65d, 0x62
