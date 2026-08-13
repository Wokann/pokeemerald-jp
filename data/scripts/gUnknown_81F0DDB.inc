	setvar 0x8004, 0x2
	playse 0x3
	special DoPCTurnOffEffect
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x1f0de8, 0xc89
