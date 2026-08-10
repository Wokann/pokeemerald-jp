	nop 
	.byte 0xF8
	waitstate 
	nop 
	.byte 0xF7
	waitstate 
	gotostd_if 0x3, 0x2A
	setworldmapflag 0x9719
	nop 
	showcoinsbox 0x1D, 0x97
	nop 
	showcoinsbox 0xA, 0x3
	takecoins 0x1591
	gotostd 0x2
	call 0xFFC0FFC0
	setworldmapflag 0x0
	nop 
	end 
	compare_addr_to_addr 0x2085712, 0x3
	nop 
	nop 
	nop 
	call 0x12200203
	setobjectxy 0x308, 0x3, 0x0
	nop 
	setworldmapflag 0x400
	return 
	end 
	compare_addr_to_addr 0x4085712, 0x3
	nop 
	end 
	nop 
	call 0x12200203
	setobjectxy 0x408, 0x3, 0x0
	nop 
	return 
	nop 
	call 0x91B50328
	copybyte 0xC0040208, 0x2003FFF
	nop 
	nop 
	nop 
	goto 0x911929
	setdynamicwarp 0x355, 0x4B, 0x80D, 0x502
	setworldmapflag 0x400
	nop 
	nop 
	nop 
	killscript 
	nop 
	setworldmapflag 0x200
	.byte 0x50
	loadbytefromaddr 0x1020857
	nop 
	nop 
	end 
	.byte 0x50
	loadbytefromaddr 0x1020857
	clearflag 0x200
	.byte 0x50
	loadbytefromaddr 0x1020857
	.byte 0x54
	nop 
	end 
	.byte 0x50
	loadbytefromaddr 0x1020857
	bufferleadmonspeciesname 0x0
	end 
	.byte 0x50
	loadbytefromaddr 0x1020857
	.byte 0xA8
	nop 
	end 
	.byte 0x50
	loadbytefromaddr 0x1020857
	setmonmetlocation 0x500, 0xB
	return 
	.byte 0x08
