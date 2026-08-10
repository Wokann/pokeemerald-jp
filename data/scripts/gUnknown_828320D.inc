	nop 
	.byte 0xFE
	waitstate 
	copyvar 0xEC, 0x2C0
	takedecoration 0x5AD3
	gotostd 0x2
	return 
	moveobjectoffscreen 0x0
	nop 
	moveobjectoffscreen 0x400
	copyvar 0x1A, 0x510E
	waitfanfare 
	delay 0x208
	takedecoration 0x5AD3
	gotostd 0x2
	end 
	fadeoutbgm 0x0
	nop 
	nop 
	setorcopyvar 0x33F, 0x6255
	writebytetoaddr 0x8, 0x140602
	setworldmapflag 0x500
	nop 
	goto 0xBF000D00
	.byte 0x56
	setmysteryeventstatus 0x51
	waitfanfare 
	delay 0x508
	gotostd 0x2
	takedecoration 0x5AD3
	gotostd 0x2
	return 
	checkitemspace 0x100, 0x4000
	nop 
	call 0xD34C0202
	faceplayer 
	gotostd 0x2
	return 
	warphole 0x0
	nop 
	setdivewarp 0x4, 0x5, 0x4C02, 0x5AD3
	gotostd 0x2
	return 
	.byte 0x50
	nop 
	setworldmapflag 0x4000
	nop 
	call 0xD34C0202
	faceplayer 
	gotostd 0x2
	return 
	warpsilent 0x0, 0x0, 0x78, 0x204
	end 
	takedecoration 0x5AD3
	gotostd 0x2
	return 
	moveobjectoffscreen 0x0
	nop 
	braillemessage 0x2020400
	takedecoration 0x5AD3
	gotostd 0x2
	return 
	faceplayer 
	nop 
	nop 
	nop 
	setdivewarp 0x4, 0x2, 0x4C02, 0x5AD3
	gotostd 0x2
	return 
	waitse 
	nop 
	nop 
	nop 
	setdivewarp 0x4, 0x2, 0x4C02, 0x5AD3
	gotostd 0x2
	return 
	gotopostbattlescript 
	nop 
	setworldmapflag 0x5000
	nop 
	call 0xD34C0202
	faceplayer 
	gotostd 0x2
	return 
	moveobjectoffscreen 0x0
	nop 
	braillemessage 0x2020400
	takedecoration 0x5AD3
	gotostd 0x2
	return 
	givedecoration 0x100
	nop 
	setdivewarp 0x4, 0x2, 0x4C02, 0x5AD3
	gotostd 0x2
	return 
	addobject 0x0
	nop 
	braillemessage 0xF020400
