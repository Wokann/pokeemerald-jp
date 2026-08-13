	nop 
	.byte 0x26
	delay 0xA
	returnram 
	.incbin "baserom_jp.gba", 0x27c5f0, 0x2e
