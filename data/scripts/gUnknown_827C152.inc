	nop 
	copybyte 0x70990328, 0x5050811
	copybyte 0x6000028, 0x1F000600
	nop 
	return 
	.incbin "baserom_jp.gba", 0x27c167, 0x9b
