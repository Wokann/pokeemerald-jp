	hidemonpic 
	setworldmapflag 0x3A13
	hidemonpic 
	setworldmapflag 0x3A14
	removeobject 0x3A01
	loadbyte 0x7B, 0x1
	.byte 0xF8
	setworldmapflag 0x533A
	return 
	.incbin "baserom_jp.gba", 0x288fa6, 0x17
