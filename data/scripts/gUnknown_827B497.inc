	return
	goto 0x2081032
	nop
	returnram
	returnram
	gotostd 0xA
	end
	copyvar 0x87, 0x4C0
	.incbin "baserom_jp.gba", 0x27B4A8, 0x36
