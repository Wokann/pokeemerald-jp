	setmysteryeventstatus 0x58
	cleartrainerflag 0x828
	gotostd_if 0x3, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27d581, 0x5f
