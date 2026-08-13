	nop
	waitmovement 0x27
	setstepcallback 0x27
	compare_local_to_value 0xA9, 0x0
	.incbin "baserom_jp.gba", 0x2779B1, 0x128
