	nop 
	waitmoncry 
	waitstate 
	gotostd_if 0x3, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x280d45, 0x5e
