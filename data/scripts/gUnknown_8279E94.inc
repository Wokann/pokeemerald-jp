	nop 
	dotimebasedevents 
	waitstate 
	compare_local_to_value 0xAB, 0x0
	showcoinsbox 0x8, 0x3
	return 
	.incbin "baserom_jp.gba", 0x279e9e, 0x191
