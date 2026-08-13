	lockall 
	fadescreenswapbuffers 0x1
	setflag 0x2CE
	removeobject 0x1
	fadescreenswapbuffers 0x0
	loadword 0x0, 0x823B5BF
	callstd 0x4
	closemessage 
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x23b5bf, 0x1a3c
