	nop 
	setrespawn 0x27
	fadescreen 0x27
	gotostd_if 0x3, 0x28
	setworldmapflag 0xC0C
	gotostd 0x19
	pokemartdecoration 0x4C023F00
	setorcopyvar 0x857, 0x802
	.byte 0xF0
	.byte 0xFF
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	gotostd_if 0x0, 0x1
	nop 
	return 
	nop 
	nop 
	nop 
	goto 0x3F008B19
	end 
	warphole 0x2F57
	gotostd 0x3
	call 0x0
	setworldmapflag 0x200
	nop 
	return 
	playfanfare 0xD4A
	gotostd 0x5
	goto 0x40001
	nop 
	nop 
	goto_if 0x0, 0xB050001
	return 
	killscript 
	.byte 0x08
