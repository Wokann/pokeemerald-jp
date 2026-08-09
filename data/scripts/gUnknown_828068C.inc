	nop 
	setrespawn 0x27
	dotimebasedevents 
	delay 0x30A
	returnram 
	returnram 
	gotostd 0x19
	startcontest 
	nop 
	.byte 0x3F
	end 
	opendoor 0x571A, 0x208
	return 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	end 
	opendoor 0x571A, 0x208
	return 
	nop 
	nop 
	nop 
	nop 
	setworldmapflag 0x400
	delay 0x8819
	nop 
	.byte 0x3F
	end 
	multichoicedefault 0x2E, 0x57, 0x8, 0x2, 0x7
	.byte 0x1F
	nop 
	return 
	nop 
	setworldmapflag 0xFF00
	.byte 0x7F
	gotostd_if 0x0, 0x0
	nop 
	gotostd_if 0x0, 0x2
	.byte 0xB4
	playse 0x857
	return 
	call 0x0
	setworldmapflag 0x1400
	nop 
	return 
	playfanfare 0xD4A
	gotostd 0x5
	goto 0x70001
	nop 
	nop 
	callstd 0x0
	setworldmapflag 0x500
	callstd_if 0x3, 0xD
	.byte 0x08
