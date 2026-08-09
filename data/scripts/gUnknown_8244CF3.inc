	.byte 0xDD
	nop 
	nop 
	.byte 0x80
	.byte 0xDE
	setworldmapflag 0x8000
	closemessage 
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x8243B7F
	callstd 0x4
	waitfanfare 
	closemessage 
	delay 0x1E
	return 
