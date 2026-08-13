	setmysteryeventstatus 0x58
	cleartrainerflag 0x828
	return
	.byte 0x25
	nop
	.incbin "baserom_jp.gba", 0x27B351, 0x15
