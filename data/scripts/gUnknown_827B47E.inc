	setmysteryeventstatus 0x58
	cleartrainerflag 0x828
	return 
	choosecontestmon 
	nop 
	writebytetoaddr 0x8, 0xCB190002
	nop 
	showcoinsbox 0x4, 0xF
	setmysteryeventstatus 0x64
	cleartrainerflag 0x828
	.byte 0x05
	.byte 0x08
