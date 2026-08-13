	nop
	setrespawn 0x27
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram
	gotostd 0x2
	checkplayergender
	resetobjectsubpriority 0x855, 0x205
	nop
	nop
	.byte 0xE8
	.byte 0xFF
	nop
	nop
	nop
	nop
	gotostd 0x0
	.incbin "baserom_jp.gba", 0x28076E, 0x7A
