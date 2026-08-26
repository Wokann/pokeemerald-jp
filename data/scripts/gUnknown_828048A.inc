	nop
	resetweather
	waitstate
	gotostd_if 0x3, 0x28
	jp_raw_01_u16 0xC0C
	gotostd 0x4
	nop
	end
	.incbin "baserom_jp.gba", 0x280497, 0xD6
