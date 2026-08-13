	nop
	dotimebasedevents
	waitstate
	compare_local_to_value 0xAB, 0x0
	showcoinsbox 0x8, 0x3
	return
	addobject 0x1162
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x279EA3, 0x18C
