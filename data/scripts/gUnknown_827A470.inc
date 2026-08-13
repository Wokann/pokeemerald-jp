	nop 
	compare_addr_to_local 0xE8840227, 0x56
	gotostd 0x28
	nop 
	end 
	.incbin "baserom_jp.gba", 0x27a47b, 0x2b
