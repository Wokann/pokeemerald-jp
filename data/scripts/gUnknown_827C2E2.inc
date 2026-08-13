	nop 
	call_if 0x28, 0x2280F00
	release 
	buffercontesttype 
	faceplayer 
	gotostd 0x82
	return 
	.incbin "baserom_jp.gba", 0x27c2ef, 0x4e
