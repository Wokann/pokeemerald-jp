	nop 
	fadedefaultbgm 
	waitstate 
	copylocal 0xB, 0x16
	return 
	.incbin "baserom_jp.gba", 0x27dec8, 0x153
