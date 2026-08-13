	nop 
	setstepcallback 0x27
	copyvar 0x7E, 0x2C0
	startcontest 
	compare_local_to_addr 0x57, 0x14048208
	nop 
	nop 
	nop 
	delay 0x0
	nop 
	goto 0xD4A3103
	gotostd 0x5
	goto 0x30001
	nop 
	nop 
	goto 0x3000100
	addobject 0x1162
	gotostd 0x2
	goto_if 0x4, 0x2000100
	nop 
	nop 
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x27fb29, 0xa
