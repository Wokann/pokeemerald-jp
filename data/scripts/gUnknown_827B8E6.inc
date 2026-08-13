	nop
	.byte 0xD0
	waitstate
	return
	callstd 0x4D
	killscript
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x27B8EF, 0x78
