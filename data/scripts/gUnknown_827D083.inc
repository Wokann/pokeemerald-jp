	nop 
	dowildbattle 
	waitstate 
	nop 
	fadeoutbgm 0x27
	nop 
	.byte 0xE0
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27d090, 0x62
