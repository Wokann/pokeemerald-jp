	nop 
	.byte 0xEE
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x282607, 0x60
