	nop 
	drawbox 
	waitstate 
	end 
	setvaddress 0x208571F
	goto 0xFFF80000
	setworldmapflag 0x3C00
	nop 
	nop 
	nop 
	end 
	setvaddress 0x208571F
	goto 0x0
	setworldmapflag 0x3C00
	nop 
	setworldmapflag 0x200
	setvaddress 0x208571F
	goto 0x80000
	setworldmapflag 0x3C00
	nop 
	end 
	nop 
	end 
	setvaddress 0x208571F
	goto 0x100000
	setworldmapflag 0x3C00
	nop 
	return 
	nop 
	end 
	setvaddress 0x208571F
	goto 0x180000
	setworldmapflag 0x3C00
	nop 
	call 0x1FB80200
	setobjectxy 0x208, 0x5, 0x2000
	nop 
	setworldmapflag 0x3C00
	nop 
	nop 
	nop 
	call 0x871C05
	setdynamicwarp 0xA04, 0x3, 0x4B55, 0x80D
	end 
	goto 0x40001
	nop 
	nop 
	loadword 0x0, 0x1D040001
	return 
	takecoins 0xD50
	gotostd 0x2
	goto 0xC0001
	goto_if 0x0, 0x50001
	call 0x811907
	setdynamicwarp 0x335, 0x56, 0x80D, 0x205
	setworldmapflag 0x800
	nop 
	.byte 0x05
	.byte 0x08
