	fadedefaultbgm 
	gotonative 0x2023F
	setworldmapflag 0x10
	callstd_if 0x3, 0xC
	return 
	.incbin "baserom_jp.gba", 0x28945c, 0x31
