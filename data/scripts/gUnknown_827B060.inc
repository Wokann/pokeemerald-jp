	nop 
	setrespawn 0x27
	fadescreen 0x27
	end 
	checkplayergender 
	.byte 0xA9
	addobject 0x208
	goto 0x140000
	nop 
	nop 
	nop 
	nop 
	call 0x1AC40200
	setobjectxy 0x8208, 0xE806, 0x1CFF
	nop 
	delay 0x800
	nop 
	checkplayergender 
	nop 
	nop 
	nop 
	call 0x2F3C0204
	setobjectxy 0x8208, 0xF804, 0x8FF
	nop 
	setworldmapflag 0x200
	nop 
	return 
	vgoto 0x2080D59
	call 0x1800006
	setworldmapflag 0x200
	nop 
	copyvar 0x7B, 0x53F
	end 
	pokemartdecoration2 0x20855A9
	return 
	nop 
	nop 
	setworldmapflag 0x400
	nop 
	.byte 0x08
