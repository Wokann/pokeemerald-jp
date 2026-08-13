	nop 
	messageautoscroll 0x27970027
	gotostd_if 0x1, 0x14
	setworldmapflag 0xC17
	returnram 
	.incbin "baserom_jp.gba", 0x27eb4c, 0xa3
