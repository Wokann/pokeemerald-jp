	nop 
	setrespawn 0x27
	dotimebasedevents 
	delay 0x30A
	returnram 
	.incbin "baserom_jp.gba", 0x280695, 0x60
