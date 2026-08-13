	lockall 
	setvar 0x8004, 0x7
	special CallTrainerHillFunction
	loadword 0x0, 0x823BEEC
	callstd 0x4
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x276cc2, 0x4a
