	nop 
	fadescreen 0x27
	gotostd_if 0x1, 0x14
	setworldmapflag 0x417
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x278f17, 0x66
