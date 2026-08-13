	setvar 0x8004, 0x1
	playse 0x3
	special DoPCTurnOffEffect
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x1f01fb, 0xba4
