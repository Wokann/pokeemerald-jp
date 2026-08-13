	nop
	dotimebasedevents
	waitstate
	gotostd_if 0x3, 0x28
	setworldmapflag 0xC0C
	gotostd 0x3
	playfanfare 0xD4A
	gotostd 0x5
	.incbin "baserom_jp.gba", 0x280375, 0x8D
