	end 
	showobject_at 0x572E, 0x800
	goto 0x70002
	nop 
	nop 
	callstd 0x0
	compare_addr_to_value 0xAB1900, 0xC0
	return 
	setmonobedient 0x15DA
	gotostd 0x5
	call_if 0x1E, 0x8000
	nop 
	setworldmapflag 0x200
	nop 
	nop 
	nop 
	setworldmapflag 0x500
	end 
	showobject_at 0x572E, 0x800
	goto 0x40002
	callstd 0x0
	nop 
	nop 
	compare_addr_to_value 0x6040500, 0x2
	pokemartdecoration2 0x855A9
	return 
	nop 
	nop 
	nop 
	nop 
	.byte 0x0F
	nop 
	.byte 0x08
