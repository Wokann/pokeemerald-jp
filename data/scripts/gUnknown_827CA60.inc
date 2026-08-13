	nop 
	.byte 0xE4
	waitstate 
	gotostd_if 0x0, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27ca67, 0x3c
