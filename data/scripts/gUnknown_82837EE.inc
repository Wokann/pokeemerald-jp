	nop 
	setrespawn 0x27
	fadescreen 0x27
	delay 0xC01
	returnram 
	.incbin "baserom_jp.gba", 0x2837f8, 0x2e
	.incbin "baserom_jp.gba", 0x283826, 0x52
	.incbin "baserom_jp.gba", 0x283878, 0xb
