	nop 
	fadescreen 0x27
	nop 
	setrespawn 0x27
	dotimebasedevents 
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x2835e2, 0x7b
