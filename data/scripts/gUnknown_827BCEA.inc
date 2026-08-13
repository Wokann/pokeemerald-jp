	nop
	fadescreen 0x27
	nop
	faceplayer
	waitstate
	nop
	checkpcitem 0xA27, 0x2803
	setworldmapflag 0xC0C
	gotostd 0x3
	waitdooranim
	addvar 0x811, 0x2
	.incbin "baserom_jp.gba", 0x27BD01, 0x2A
