	lockall
	dofieldeffect 0x28
	waitstate
	goto 0x82567A2
	end
	setflag 0x889
	loadword 0x0, 0x82567F3
	callstd 0x4
	releaseall
	end
	loadword 0x0, 0x8256824
	callstd 0x4
	releaseall
	end
	loadword 0x0, 0x8256843
	callstd 0x4
	releaseall
	end
	closemessage
	releaseall
	end
	.incbin "baserom_jp.gba", 0x2567C6, 0x97
