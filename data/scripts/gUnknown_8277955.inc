	nop 
	fadescreen 0x27
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27795c, 0x2d
	.incbin "baserom_jp.gba", 0x277989, 0x1f
