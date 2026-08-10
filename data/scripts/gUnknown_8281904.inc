	nop 
	copyvar 0x27, 0x2797
	compare_local_to_value 0x78, 0x0
	showcoinsbox 0x1C, 0x2
	return 
	givepcitem 0x114D, 0x508
	return 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	goto 0x128030A
	returnram 
	returnram 
	gotostd 0x1C
	setfieldeffectarg 0x0, 0x14C0
	end 
	return 
	vmessage 0x2080D4F
	goto 0xC0000
	call 0x4000100
	nop 
	return 
	setflag 0x10E7
	gotostd 0x5
	end 
	setworldmapflag 0x4600
	nop 
	end 
	pokemartdecoration2 0x208571E
	goto 0xFFE7
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x2
	pokemartdecoration2 0x208571E
	goto 0x19
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	subvar 0xA002, 0x55A9
	gotostd 0x2
	goto 0x180000
	nop 
	nop 
	nop 
	nop 
	callstd 0x0
	call 0x2F3C0211
	setobjectxy 0x208, 0x1004, 0x0
	nop 
	setworldmapflag 0x100
	nop 
	end 
	warphole 0x2F57
	gotostd 0x2
	call 0xFFF0
	setworldmapflag 0x100
	nop 
	copyvar 0x88, 0x53F
	end 
	pokemartdecoration2 0x20855A9
	return 
	nop 
	nop 
	nop 
	nop 
	callstd_if 0x0, 0x5
	callstd_if 0x3, 0xD
	.byte 0x08
