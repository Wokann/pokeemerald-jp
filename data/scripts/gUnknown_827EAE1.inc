	nop 
	messageautoscroll 0x27970027
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27eaeb, 0x54
