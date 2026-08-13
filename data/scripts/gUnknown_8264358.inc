	lockall 
	delay 0x14
	applymovement 0xFF, 0x8264371
	waitmovement 0x0
	playse 0x2B
	delay 0x3C
	special DoFallWarp
	end 
	.incbin "baserom_jp.gba", 0x264371, 0x1293e
