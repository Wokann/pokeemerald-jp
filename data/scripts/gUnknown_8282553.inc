	nop 
	.byte 0xE8
	waitstate 
	nop 
	.byte 0xEC
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x28255a, 0x62
