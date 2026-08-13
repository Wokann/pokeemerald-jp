	nop 
	turnvobject 0x27, 0x0
	compare_addr_to_local 0x19000428, 0x81
	nop 
	showcoinsbox 0x2, 0x54
	subvar 0x857, 0x680
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	compare_addr_to_local 0x5000000, 0x19
	setrespawn 0x3F00
	return 
	.incbin "baserom_jp.gba", 0x27cbdf, 0x6a
