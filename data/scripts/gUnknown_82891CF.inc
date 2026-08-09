	setptrbyte 0xC0, 0x12085AB9
	.byte 0x40
	nop 
	checkitemspace 0x2801, 0x241
	end 
	nop 
	nop 
	nop 
	nop 
	gettime 
	.byte 0xD6
	.byte 0x3F
	end 
	end 
	nop 
	waitfanfare 
	setdooropen 0x23E, 0x2202
	.byte 0x3D
	end 
	end 
	.byte 0xD6
	.byte 0x3F
	end 
	end 
	setworldmapflag 0x2B96
	nop 
	.byte 0x94
	.byte 0x3E
	end 
	end 
	nop 
	nop 
	nop 
	nop 
	delay 0x2892
	gotostd 0x13
	.byte 0xC4
	vgoto 0x4012085A
	nop 
	fadedefaultbgm 
	gotonative 0x2002023F
	setworldmapflag 0x110
	setmysteryeventstatus 0x5C
	setworldmapflag 0x10B
	returnram 
	setworldmapflag 0x119
	nop 
	nop 
	nop 
	nop 
	nop 
	gotonative 0x8289228
	setflag 0xDE01
	.byte 0x3F
	end 
	end 
	nop 
	checkitem 0x2892, 0x2F08
	.byte 0xD6
	.byte 0x3F
	end 
	end 
	setworldmapflag 0xD62D
	.byte 0x3F
	end 
	end 
	loadbyte 0x3D, 0x2
	end 
	setworldmapflag 0x91E7
	delay 0x3808
	gotonative 0x2002023F
	setworldmapflag 0x110
	.byte 0x3E
