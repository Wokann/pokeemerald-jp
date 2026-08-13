	nop 
	waitmessage 
	waitstate 
	nop 
	message 0x53050327
	loadbyte 0x8, 0x2
	nop 
	copyvar 0xC1, 0x5C0
	end 
	.incbin "baserom_jp.gba", 0x27bdc5, 0x35
