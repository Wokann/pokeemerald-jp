	setmysteryeventstatus 0x58
	cleartrainerflag 0x828
	return 
	choosecontestmon 
	nop 
	.byte 0x11
	gotostd 0x2
	nop 
	.byte 0x19
	.byte 0xCB
	nop 
	showcoinsbox 0x4, 0xF
	setmysteryeventstatus 0x64
	cleartrainerflag 0x828
	.byte 0x05
	.byte 0x08
