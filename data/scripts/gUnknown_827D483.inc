	nop 
	.byte 0xEA
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x27d487, 0x68
