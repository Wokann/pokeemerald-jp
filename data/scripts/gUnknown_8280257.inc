	nop 
	setfieldeffectarg 0x27, 0xA400
	waitstate 
	gotostd_if 0x3, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x280261, 0xf0
