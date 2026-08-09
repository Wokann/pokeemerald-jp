	nop 
	callstd_if 0x28, 0xE
	.byte 0x58
	cleartrainerflag 0x828
	return 
	.byte 0x41
	call 0x1030811
	setworldmapflag 0x300
	settrainerflag 0xA74
	gotostd 0x5
	goto 0x7FFF0001
	returnram 
	nop 
	return 
	nop 
	setworldmapflag 0x1C00
	.byte 0xD9
	nop 
	showcoinsbox 0x18, 0x3
	call 0x4410310
	.byte 0x11
	gotostd 0x3
	setworldmapflag 0x0
	return 
	settrainerflag 0xA74
	gotostd 0x5
	goto 0x7FFF0000
	returnram 
	nop 
	return 
	nop 
	setworldmapflag 0x500
	setmysteryeventstatus 0x64
	cleartrainerflag 0x828
	.byte 0x08
