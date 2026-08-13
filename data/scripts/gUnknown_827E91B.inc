	nop 
	faceplayer 
	waitstate 
	copyvar 0x9F, 0x2C0
	checkplayergender 
	resetobjectsubpriority 0x855, 0x205
	nop 
	nop 
	.byte 0xF6
	.byte 0xFF
	nop 
	nop 
	nop 
	nop 
	return 
	.incbin "baserom_jp.gba", 0x27e932, 0x87
