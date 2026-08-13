	gotostd_if 0x2, 0x28
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x27ca1f, 0x41
