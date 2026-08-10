	nop 
	checkitemtype 0x27
	fadescreen 0x27
	gotostd_if 0x1, 0xC
	returnram 
	gotostd 0x19
	showcontestresults 
	nop 
	showcoinsbox 0x2, 0xA0
	.byte 0xA9
	addobject 0x208
	goto 0x140000
	return 
	nop 
	nop 
	nop 
	call 0x2010400
	givecoins 0x56E4
	gotostd 0x2
	end 
	nop 
	nop 
	nop 
	nop 
	call 0x8D1903
	setdynamicwarp 0x23C, 0x2F, 0x857, 0x403
	nop 
	nop 
	nop 
	nop 
	setworldmapflag 0x100
	nop 
	end 
	checkplayergender 
	.byte 0xA9
	addobject 0x208
	goto 0xFFF40001
	gotostd_if 0x0, 0x0
	nop 
	return 
	nop 
	end 
	pokemartdecoration2 0x20855A9
	return 
	nop 
	nop 
	nop 
	nop 
	goto 0x3030400
	callstd 0x4D
	killscript 
	gotostd 0x2
	goto 0x1
	return 
	nop 
	goto_if 0x0, 0x4050001
	goto 0x55A98802
	gotostd 0x2
	return 
	setworldmapflag 0x0
	nop 
	goto_if 0x0, 0xD010B05
	.byte 0x08
