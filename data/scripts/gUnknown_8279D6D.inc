	nop 
	animateflash 0x27
	nop 
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x279d77, 0x3e
