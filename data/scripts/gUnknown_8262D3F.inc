	setflashradius 0x64A0
	killscript
	setflag 0x2C00
	gotostd 0x2D
	nop
	.incbin "baserom_jp.gba", 0x262D49, 0x1D
