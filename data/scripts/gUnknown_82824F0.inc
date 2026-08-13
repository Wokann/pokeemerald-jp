	nop 
	.byte 0xEA
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x2824f4, 0x5f
