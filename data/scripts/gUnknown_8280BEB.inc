	nop 
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram 
	gotostd 0x19
	pokemartdecoration 0x8B1DC000
	nop 
	.byte 0x3F
	gotostd_if 0x1D, 0x87
	nop 
	showcoinsbox 0x14, 0x1D
	showcontestresults 
	nop 
	.byte 0x3F
	.byte 0x1E
	.byte 0x1D
	pokemartdecoration 0x1D28C000
	showcontestresults 
	nop 
	.byte 0x3F
	waitfanfare 
	.byte 0x1D
	pokemartdecoration 0x1D3CC000
	showcontestresults 
	nop 
	.byte 0x3F
	checkitemspace 0x871D, 0xC000
	.byte 0x50
	.byte 0x1D
	showcontestresults 
	nop 
	.byte 0x3F
	faceplayer 
	return 
	vmessage 0x2080D4F
	goto 0xFFEE0000
	goto_if 0x0, 0x40006
	return 
	vmessage 0x2080D4F
	goto 0x120001
	goto_if 0x0, 0x40006
	setmysteryeventstatus 0x5A
	returnram 
	delay 0xE08
	faceplayer 
	returnram 
	delay 0xE08
	faceplayer 
	returnram 
	delay 0x508
	callstd_if 0x3, 0xD
	gotostd 0x2
	.byte 0x3C
	playse 0x857
	return 
	call 0xFFF40000
	setworldmapflag 0x100
	nop 
	call 0x2F3C0208
	setobjectxy 0x308, 0xF404, 0x8FF
	nop 
	setworldmapflag 0x100
	nop 
	call 0x2F3C0208
	setobjectxy 0x308, 0xC04, 0x0
	nop 
	setworldmapflag 0x100
	nop 
	.byte 0x04
	gotostd 0xF
