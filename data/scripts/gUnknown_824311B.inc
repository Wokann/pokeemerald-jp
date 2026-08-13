	lockall 
	loadword 0x0, 0x81F0308
	callstd 0x4
	fadescreen 0x1
	special FieldShowRegionMap
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x24312c, 0x525
