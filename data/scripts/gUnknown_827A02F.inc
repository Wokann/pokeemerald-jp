	nop
	fadescreen 0x27
	nop
	compare_local_to_local 0x27, 0x4
	nop
	return
	addobject 0x1162
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x27A03D, 0x209
