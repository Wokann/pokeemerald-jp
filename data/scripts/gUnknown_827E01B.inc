	nop
	fadescreen 0x27
	nop
	setrespawn 0x27
	fadedefaultbgm
	waitstate
	gotostd_if 0x1, 0xC
	returnram
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x27E02A, 0xBA
