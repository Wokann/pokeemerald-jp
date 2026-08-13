	nop
	checkcoins 0xA27
	end
	clearflag 0xC00
	returnram
	gotostd 0x3
	addobject 0xD4B
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x277F5D, 0x48
