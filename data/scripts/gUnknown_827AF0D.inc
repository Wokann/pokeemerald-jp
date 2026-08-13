	nop 
	fadescreen 0x27
	nop 
	setrespawn 0x327
	playslotmachine 0x1054
	gotostd 0x2
	nop 
	return 
	.incbin "baserom_jp.gba", 0x27af1b, 0x71
