	nop 
	.byte 0xC7
	waitstate 
	end 
	loadbyte 0xE9, 0x56
	gotostd 0x82
	return 
	setworldmapflag 0xF800
	.byte 0xFF
	nop 
	nop 
	copyvar 0x88, 0x43F
	call 0x56E91002
	gotostd 0x82
	return 
	setworldmapflag 0x800
	nop 
	nop 
	nop 
	return 
	addobject 0xD4B
	gotostd 0x2
	goto 0x40001
	nop 
	nop 
	loadbytefromaddr 0x19000100
	pokemartdecoration2 0x8053F00
