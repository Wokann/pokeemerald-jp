	nop
	.byte 0xF0
	waitstate
	return
	bufferdecorationname 0x87, 0x811
	end
	nop
	return
	takecoins 0x172C
	gotostd 0x2
	nop
	.incbin "baserom_jp.gba", 0x2868D4, 0x14
