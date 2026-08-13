	nop 
	.byte 0xD0
	waitstate 
	copyvar 0xA1, 0x43F
	setworldmapflag 0x204
	return 
	.incbin "baserom_jp.gba", 0x282ac1, 0x5b
