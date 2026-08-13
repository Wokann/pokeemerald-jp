	nop
	checkplayergender
	waitstate
	gotostd_if 0x2, 0xC
	returnram
	gotostd 0x1C
	setobjectsubpriority 0xC000, 0x140F, 0xE
	.incbin "baserom_jp.gba", 0x28117F, 0x52
