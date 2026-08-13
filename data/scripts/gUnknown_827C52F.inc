	nop 
	.byte 0xE4
	waitstate 
	nop 
	loadbyte 0x28, 0x0
	writebytetoaddr 0x28, 0x28020A
	returnram 
	.incbin "baserom_jp.gba", 0x27c53d, 0xad
