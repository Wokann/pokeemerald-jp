	nop 
	.byte 0xF6
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x282b20, 0x170
