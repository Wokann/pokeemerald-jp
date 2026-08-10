	nop 
	vgoto_if 0x27, 0x19271B00
	setberrytree 0x0, 0xC0, 0x2
	checkitemtype 0x5713
	gotostd 0x83
	goto_if 0xA, 0x0
	nop 
	nop 
	nop 
	compare_addr_to_local 0x2000000, 0x74
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x1E
	nop 
	nop 
	nop 
	delay 0x0
	nop 
	end 
	mossdeepgym2 
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x1E
	nop 
	setdivewarp 0x28, 0x0, 0x1, 0x7402
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x1E
	nop 
	bufferitemname 0x0, 0x28
	nop 
	nop 
	end 
	mossdeepgym2 
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x1E
	nop 
	showcoinsbox 0x0, 0x28
	nop 
	end 
	nop 
	end 
	mossdeepgym2 
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	gotostd 0x0
	compare_addr_to_local 0x28002000, 0x0
	nop 
	nop 
	end 
	mossdeepgym2 
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	gotostd 0x0
	compare_addr_to_local 0x28006000, 0x0
	setworldmapflag 0x200
	mossdeepgym2 
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	gotostd 0x0
	compare_addr_to_local 0x2800A000, 0x0
	nop 
	nop 
	end 
	mossdeepgym2 
	setptrbyte 0x57, 0xA078408
	nop 
	nop 
	nop 
	gotostd 0x0
	compare_addr_to_local 0x2800E000, 0x0
	end 
	nop 
	goto 0xD4B5503
	gotostd 0x2
	goto 0x40001
	nop 
	nop 
	goto 0x4000100
	loadword 0x1D, 0x133F0077
	setmysteryeventstatus 0x71
	settrainerflag 0x828
	.byte 0x05
	.byte 0x08
