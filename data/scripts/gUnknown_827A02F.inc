	nop 
	fadescreen 0x27
	nop 
	compare_local_to_local 0x27, 0x4
	nop 
	return 
	.incbin "baserom_jp.gba", 0x27a038, 0x20e
