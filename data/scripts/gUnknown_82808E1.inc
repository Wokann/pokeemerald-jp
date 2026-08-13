	nop 
	setrespawn 0x27
	fadescreen 0x27
	nop 
	buffercontesttype 
	waitstate 
	nop 
	addvar 0x427, 0xA01
	return 
	.incbin "baserom_jp.gba", 0x2808f1, 0xb8
