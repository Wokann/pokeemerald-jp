	nop 
	vcall 0x10000C27
	compare_local_to_addr 0xD0, 0x20FC000
	setweather 0x5721
	gotostd 0x3
	return 
	.incbin "baserom_jp.gba", 0x2851f6, 0xb
