	nop 
	faceplayer 
	waitstate 
	gotostd_if 0x2, 0x28
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x27e87b, 0xa0
