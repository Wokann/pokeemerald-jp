	nop 
	.byte 0xF3
	waitstate 
	nop 
	call_if 0x28, 0x15AB2903
	gotostd 0x2
	nop 
	return 
	.incbin "baserom_jp.gba", 0x282d5c, 0x99
