	nop 
	setworldmapflag 0x28
	playse 0x327
	hidecoinsbox 0xBA, 0x15
	gotostd 0x5
	nop 
	call 0x6E710308
	writebytetoaddr 0x8, 0x781050A
	gotostd 0x0
	nop 
	nop 
	returnram 
	nop 
	.byte 0xFF
	bufferpartymonnick 0x4, 0xE0E
	.byte 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	setmysteryeventstatus 0xFF
	playfanfare 0x828
	return 
	multichoicegrid 0x6E, 0x11, 0x8, 0xA, 0x5
	bufferspeciesname 0x7, 0x3
	returnram 
	nop 
	nop 
	nop 
	.byte 0xFF
	bufferpartymonnick 0x5, 0xE20
	waitmessage 
	gotopostbattlescript 
	delay 0x808
	end 
	.byte 0x94
	setmonmetlocation 0x85A, 0x2
	end 
	compare_addr_to_local 0x4028000, 0x5
	.byte 0x0F
