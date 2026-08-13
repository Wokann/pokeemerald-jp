	nop
	setstepcallback 0x27
	copyvar 0x7E, 0x2C0
	startcontest
	.incbin "baserom_jp.gba", 0x27FAFA, 0x39
