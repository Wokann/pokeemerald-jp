	nop 
	.byte 0xEF
	waitstate 
	nop 
	doweather 
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x28266e, 0xaa
