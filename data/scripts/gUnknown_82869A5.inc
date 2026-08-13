	return
	settrainerflag 0x1187
	gotostd 0x2
	nop
	nop
	buffercontesttype
	waitstate
	end
	.incbin "baserom_jp.gba", 0x2869B0, 0xBA
