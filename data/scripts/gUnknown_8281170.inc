	nop 
	checkplayergender 
	waitstate 
	gotostd_if 0x2, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x281177, 0x5a
