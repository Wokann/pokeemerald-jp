	nop 
	setflashradius 0xA27
	setworldmapflag 0xC0C
	gotostd 0x19
	messageautoscroll 0x28023F00
	checkmonobedience 0x85A
	end 
	call 0x0
	setworldmapflag 0x0
	nop 
	return 
	playfanfare 0xD4A
	gotostd 0x2
	goto 0x30001
	nop 
	nop 
	goto_if 0x0, 0xB050001
	setworldmapflag 0x50D
	.byte 0x08
