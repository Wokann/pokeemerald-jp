	nop 
	.byte 0xE3
	waitstate 
	nop 
	.byte 0xE4
	waitstate 
	nop 
	.byte 0xE5
	waitstate 
	gotostd_if 0x0, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27c369, 0x8e
