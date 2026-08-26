	nop
	waitmoncry
	waitstate
	gotostd_if 0x3, 0x28
	jp_raw_01_u16 0xA91C
	nop
	.incbin "baserom_jp.gba", 0x280CEE, 0x50
