	lockall 
	setvar 0x8004, 0x0
	special DoLotteryCornerComputerEffect
	playse 0x4
	loadword 0x0, 0x82436B8
	callstd 0x4
	goto 0x8242E38
	end 
	.incbin "baserom_jp.gba", 0x242e38, 0xf4
