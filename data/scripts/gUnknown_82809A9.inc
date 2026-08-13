	nop
	fadescreen 0x27
	nop
	setrespawn 0xA27
	return
	returnram
	returnram
	gotostd 0x3
	takecoins 0xD50
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x2809BA, 0xBE
