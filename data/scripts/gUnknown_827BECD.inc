	nop 
	fadescreen 0x27
	nop 
	.byte 0xF5
	waitstate 
	gotostd_if 0x0, 0x2
	givemoney 0x2085AD0, 0x6
	nop 
	nop 
	nop 
	nop 
	compare_addr_to_addr 0x28FFE000, 0x3FFFE00
	.byte 0xED
	opendoor 0x815, 0x302
	nop 
	nop 
	end 
	.incbin "baserom_jp.gba", 0x27bef2, 0x48
