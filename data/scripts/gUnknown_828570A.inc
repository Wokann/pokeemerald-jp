	nop 
	applymovement 0x27, 0x970027B0
	waitstate 
	gotostd_if 0x3, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x285717, 0x114
