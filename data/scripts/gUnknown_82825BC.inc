	nop 
	.byte 0xEB
	waitstate 
	nop 
	.byte 0xED
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x2825c3, 0x40
