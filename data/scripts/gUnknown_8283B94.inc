	nop 
	setptrbyte 0x28, 0x128030A
	returnram 
	returnram 
	gotostd 0x3
	playfanfare 0xD4A
	gotostd 0x5
	goto 0x0
	end 
	nop 
	gettime 
	nop 
	setworldmapflag 0x400
	goto_if 0x3, 0x8107F19
	goto 0x1B006401
	resetweather 
	nop 
	showcoinsbox 0x3F, 0x1
	nop 
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	return 
	playfanfare 0xD4A
	gotostd 0x5
	goto 0x30001
	nop 
	nop 
	checkflag 0x100
	nop 
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	setmysteryeventstatus 0xE
	warphole 0x2808
	goto 0x80D030B
	end 
	.byte 0xE0
	returnram 
	setobjectxy 0x308, 0xA04, 0xA00
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x4
	end 
	end 
	.byte 0xE0
	returnram 
	setobjectxy 0x308, 0xA04, 0xA00
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x4
	end 
	.byte 0x0F
