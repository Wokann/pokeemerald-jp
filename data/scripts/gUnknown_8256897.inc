	lockall 
	loadword 0x0, 0x82568A2
	callstd 0x4
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x2568a2, 0x48
