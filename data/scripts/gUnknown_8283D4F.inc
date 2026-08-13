	nop 
	.byte 0xD0
	waitstate 
	nop 
	setstepcallback 0x27
	copyvar 0xA1, 0x23F
	.byte 0xE4
	gotoram 
	faceplayer 
	gotostd 0x82
	nop 
	call 0x4A31030A
	killscript 
	.incbin "baserom_jp.gba", 0x283d66, 0x28
