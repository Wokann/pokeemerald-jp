	nop
	setrespawn 0x27
	fadescreen 0x27
	nop
	buffercontesttype
	waitstate
	nop
	addvar 0x427, 0xA01
	return
	returnram
	returnram
	gotostd 0x19
	.incbin "baserom_jp.gba", 0x2808F5, 0xB4
