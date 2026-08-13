	nop 
	doweather 
	waitstate 
	nop 
	playse 0x27
	fadescreen 0x27
	gotostd_if 0x3, 0x2A
	setworldmapflag 0xC0C
	gotostd 0x2
	showobject_at 0x572E, 0x802
	goto 0x10001
	nop 
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x27f7ec, 0x1ea
