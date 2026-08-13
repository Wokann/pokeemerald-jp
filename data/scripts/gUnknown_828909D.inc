	mossdeepgym2
	setworldmapflag 0x210
	nop
	gettime
	specialvar 0x241, sub_080F9424
	checkflag 0x9004
	initclock 0x202, 0x1
	nop
	nop
	.incbin "baserom_jp.gba", 0x2890B2, 0x8F
