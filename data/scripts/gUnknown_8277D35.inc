	nop 
	vloadword 0x27970027
	gotostd_if 0x3, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x277d3f, 0xaf
