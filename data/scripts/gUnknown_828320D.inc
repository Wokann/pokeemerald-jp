	nop 
	.byte 0xFE
	.byte 0x27
	.byte 0x19
	.byte 0xEC
	nop 
	showcoinsbox 0x2, 0x4C
	.byte 0xD3
	faceplayer 
	gotostd 0x2
	return 
	.byte 0x64
	nop 
	nop 
	nop 
	.byte 0x64
	nop 
	call 0xE001A19
	.byte 0x51
	waitfanfare 
	delay 0x208
	.byte 0x4C
	.byte 0xD3
	faceplayer 
	gotostd 0x2
	end 
	fadeoutbgm 0x0
	nop 
	nop 
	setorcopyvar 0x33F, 0x6255
	.byte 0x11
	gotostd 0x2
	goto_if 0x14, 0x5000100
	nop 
	goto 0xBF000D00
	.byte 0x56
	setmysteryeventstatus 0x51
	waitfanfare 
	delay 0x508
	gotostd 0x2
	.byte 0x4C
	.byte 0xD3
	faceplayer 
	gotostd 0x2
	return 
	checkitemspace 0x100, 0x4000
	nop 
	call 0xD34C0202
	faceplayer 
	gotostd 0x2
	return 
	.byte 0x3C
	nop 
	nop 
	nop 
	.byte 0x40
	nop 
	call 0xD34C0205
	faceplayer 
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
	.byte 0x3A
	nop 
	nop 
	nop 
	braillemessage 0x2020400
	.byte 0x4C
	.byte 0xD3
	faceplayer 
	gotostd 0x2
	return 
	.byte 0x64
	nop 
	nop 
	nop 
	braillemessage 0x2020400
	.byte 0x4C
	.byte 0xD3
	faceplayer 
	gotostd 0x2
	return 
	faceplayer 
	nop 
	nop 
	nop 
	.byte 0x40
	nop 
	call 0xD34C0202
	faceplayer 
	gotostd 0x2
	return 
	waitse 
	nop 
	nop 
	nop 
	.byte 0x40
	nop 
	call 0xD34C0202
	faceplayer 
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
	.byte 0x64
	nop 
	nop 
	nop 
	braillemessage 0x2020400
	.byte 0x4C
	.byte 0xD3
	faceplayer 
	gotostd 0x2
	return 
	.byte 0x4B
	nop 
	setworldmapflag 0x4000
	nop 
	call 0xD34C0202
	faceplayer 
	gotostd 0x2
	return 
	.byte 0x55
	nop 
	nop 
	nop 
	braillemessage 0xF020400
