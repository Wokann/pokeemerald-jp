	nop
	waitbuttonpress
	waitstate
	setmysteryeventstatus 0x58
	cleartrainerflag 0x828
	.incbin "baserom_jp.gba", 0x27B5E9, 0x1C
