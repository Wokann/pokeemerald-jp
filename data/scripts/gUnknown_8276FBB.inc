	.byte 0xFD
	setworldmapflag 0x1A00
	.byte 0xFE
	giveegg 0xAE9F
	moveobjectoffscreen 0x16
	returnram 
	.incbin "baserom_jp.gba", 0x276fc7, 0xc
