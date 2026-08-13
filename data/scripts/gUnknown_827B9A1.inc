	nop 
	fadescreen 0x27
	nop 
	.byte 0xE7
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27b9ab, 0x5c
