	nop 
	checkcoins 0xA27
	end 
	clearflag 0xC00
	returnram 
	gotostd 0x3
	addobject 0xD4B
	gotostd 0x2
	goto 0x20000
	nop 
	nop 
	gotostd 0x0
	setworldmapflag 0xE00
	showcontestresults 
	bufferpartymonnick 0x27, 0xE08
	showcontestresults 
	bufferpartymonnick 0x27, 0xE08
	showcontestresults 
	bufferpartymonnick 0x27, 0xE08
	showcontestresults 
	bufferpartymonnick 0x27, 0xE08
	showcontestresults 
	bufferpartymonnick 0x27, 0xE08
	showcontestresults 
	bufferpartymonnick 0x27, 0x508
	callstd_if 0x2, 0xD
	gotostd 0x19
	setvaddress 0xC02C000
	.byte 0xF0
	addobject_at 0x8208, 0x610
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	compare_addr_to_local 0x4000000, 0x2
	.byte 0x0F
