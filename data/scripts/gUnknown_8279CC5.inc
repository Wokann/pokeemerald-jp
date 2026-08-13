	nop 
	.byte 0xFF
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x279cc9, 0xa4
