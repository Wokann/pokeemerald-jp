	nop 
	.byte 0xF0
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x2864f5, 0x7
