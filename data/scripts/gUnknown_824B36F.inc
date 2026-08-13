	waitmovement 0xAE9C
	.byte 0x79
	checktrainerflag 0x7152
	nop 
	returnram 
	.incbin "baserom_jp.gba", 0x24b378, 0x957
