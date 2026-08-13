	nop
	fadescreen 0x27
	nop
	setrespawn 0x27
	dotimebasedevents
	waitstate
	gotostd_if 0x1, 0xC
	returnram
	gotostd 0x19
	.incbin "baserom_jp.gba", 0x2835E4, 0x79
