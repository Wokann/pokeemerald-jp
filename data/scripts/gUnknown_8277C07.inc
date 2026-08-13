	nop
	removeobject 0x1C27
	resetobjectsubpriority 0x3F00, 0xA06
	end
	.byte 0xFC
	fadescreenswapbuffers 0x56
	gotostd 0x82
	.incbin "baserom_jp.gba", 0x277C16, 0x11F
