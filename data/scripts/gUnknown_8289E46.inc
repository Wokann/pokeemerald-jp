	hidemonpic 
	setworldmapflag 0x7612
	setworldmapflag 0x5415
	callstd 0x1
	.byte 0x39
	gotostd 0x0
	.byte 0x54
	callstd 0x1
	hidemonpic 
	setworldmapflag 0x760E
	gotostd 0x10
	hidemonpic 
	gotostd 0x11
	.byte 0x39
	.byte 0x40
	nop 
	hidemonpic 
	setworldmapflag 0x760F
	setworldmapflag 0x3E16
	.byte 0x54
	.byte 0x49
	nop 
	hidemonpic 
	setworldmapflag 0x760E
	nop 
	loadbyte 0x76, 0x0
	.byte 0x11
	.byte 0x39
	.byte 0x40
	nop 
	hidemonpic 
	setworldmapflag 0x3E0F
