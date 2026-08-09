	gotonative 0x8288E7E
	setflag 0xDE01
	.byte 0x3F
	end 
	end 
	nop 
	.byte 0x7D
	contestlinktransfer 
	delay 0x2B08
	call 0x2022C90
	gotostd 0x0
	nop 
	nop 
	waitfieldeffect 0x288D
	gotostd 0x2B
	goto 0x2023F24
	nop 
	nop 
	.byte 0x40
	nop 
	waitfieldeffect 0x288D
	gotostd 0x10
	.byte 0x51
	setworldmapflag 0xD62E
	.byte 0x3F
	end 
	end 
	nop 
	message 0x3FD70029
	end 
	end 
	nop 
	waitfieldeffect 0x288D
	gotostd 0x72
	.byte 0x7D
	contestlinktransfer 
	delay 0x1008
	.byte 0x12
	setworldmapflag 0x350
	.byte 0x7D
	contestlinktransfer 
	delay 0x5108
	return 
	end 
	checkflag 0x9005
	initclock 0x202, 0x8
	nop 
	nop 
	.byte 0x58
	contestlinktransfer 
	delay 0x2B08
	call 0x2022C90
	end 
	nop 
	nop 
	nop 
	.byte 0x58
	contestlinktransfer 
	delay 0x2B08
	call 0x2022C90
	nop 
	nop 
	nop 
	end 
	.byte 0x58
	contestlinktransfer 
	delay 0x2B08
	call 0x2022C90
	nop 
	setworldmapflag 0x3F
	.byte 0x58
	contestlinktransfer 
	delay 0x2B08
	call 0x2022C90
	setworldmapflag 0x0
	nop 
	.byte 0x58
	contestlinktransfer 
	delay 0x2B08
	call 0x2023F24
	nop 
	nop 
	.byte 0x40
	nop 
	.byte 0x58
	contestlinktransfer 
	delay 0x2908
	nop 
	fadedefaultbgm 
	.byte 0x41
	end 
	end 
	setworldmapflag 0x8E58
	delay 0x4F08
	callstd_if 0x58, 0x8E
	delay 0x1008
	setorcopyvar 0x2E01, 0x3FD6
	end 
	end 
	nop 
	message 0x3FD70029
	end 
	end 
	setworldmapflag 0x8E58
	delay 0x6E08
	.byte 0x50
	.byte 0x81
	.byte 0x58
	contestlinktransfer 
	delay 0x5108
	setworldmapflag 0x2902
	nop 
	.byte 0xD6
	.byte 0x3F
	end 
	end 
	goto_if 0x58, 0x6B08288E
	hidemonpic 
	setworldmapflag 0x7405
	setworldmapflag 0x210
	nop 
	.byte 0xE2
	setworldmapflag 0x4B3A
	.byte 0x3A
	settrainerflag 0x4C01
	setworldmapflag 0x14D
	drawboxtext 0x1, 0x10, 0x3, 0x0
	cleartrainerflag 0x4E01
	setworldmapflag 0x3A00
	.byte 0x52
	setworldmapflag 0x616D
	return 
	.byte 0x4C
	return 
	checkdecor 0x7303
	return 
	loadbyte 0x3, 0x0
	cleartrainerflag 0x4E03
	return 
	nop 
	.byte 0x3A
	hidemonpic 
	setworldmapflag 0x5207
	return 
	checkflag 0x9004
	initclock 0x202, 0x1
	nop 
	nop 
	.byte 0x7D
	contestlinktransfer 
	delay 0x6808
	.byte 0x3E
	.byte 0x50
	goto 0x8288E84
	.byte 0x51
	return 
	nop 
	.byte 0x50
	goto_if 0xB4, 0x5108288E
	return 
	nop 
	.byte 0x51
	return 
	return 
	settrainerflag 0x4C03
	return 
	checkdecor 0x7303
	return 
	loadbyte 0x3, 0x0
	cleartrainerflag 0x4E03
	return 
	nop 
	.byte 0x3A
	.byte 0x52
	goto 0x23EB12D
	end 
	loadbyte 0x3D, 0x2
	end 
	setworldmapflag 0x8E90
	delay 0x3E08
