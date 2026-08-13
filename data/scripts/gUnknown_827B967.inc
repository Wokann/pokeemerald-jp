	nop 
	.byte 0xC7
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x27b96b, 0x36
