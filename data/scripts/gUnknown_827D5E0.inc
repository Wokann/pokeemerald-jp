	nop 
	animateflash 0x27
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27d5e7, 0x63
