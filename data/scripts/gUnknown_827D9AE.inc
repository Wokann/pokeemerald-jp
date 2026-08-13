	nop 
	.byte 0xE3
	waitstate 
	nop 
	.byte 0xE4
	waitstate 
	nop 
	writebytetoaddr 0x27, 0xA273500
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x27d9bd, 0x93
