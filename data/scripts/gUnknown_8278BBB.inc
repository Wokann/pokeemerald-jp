	nop
	fadescreen 0x27
	nop
	setrespawn 0xA27
	jp_raw_01_u16 0xC0C
	gotostd 0x11
	.byte 0xD4
	showcontestresults
	waitstate
	gotostd 0x45
	startcontest
	waitstate
	gotostd 0x5
	callstd_if 0x1, 0xD
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x278BD5, 0xE1
