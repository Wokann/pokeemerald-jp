	setmysteryeventstatus 0x58
	cleartrainerflag 0x828
	gotostd_if 0x3, 0xC
	returnram
	gotostd 0x3
	settrainerflag 0xA74
	gotostd 0x5
	goto 0x37B0000
	returnram
	nop
	jp_raw_01_u16 0x100
	nop
	return
	setobjectmovementtype 0x1106, 0x8
	.incbin "baserom_jp.gba", 0x27D598, 0x48
