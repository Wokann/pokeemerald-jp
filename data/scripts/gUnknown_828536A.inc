	nop 
	special LoadPlayerParty
	fadescreen 0x27
	end 
	showobject_at 0x55A9, 0x802
	end 
	call 0x4000600
	call 0x3F007A19
	end 
	startcontest 
	.byte 0xD7
	faceplayer 
	gotostd 0x82
	end 
	.byte 0xF0
	.byte 0xFF
	.byte 0xF0
	.byte 0xFF
	call 0x2E700208
	setobjectxy 0x208, 0x1F07, 0x500
	nop 
	setworldmapflag 0xFF00
	bufferpartymonnick 0xA, 0x0
	nop 
	nop 
	nop 
	end 
	warphole 0x2F57
	gotostd 0x83
	call 0x0
	setworldmapflag 0x200
	nop 
	copyvar 0x8B, 0x23F
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
	goto_if 0x0, 0x5040001
	end 
	pokemartdecoration2 0x20855A9
	return 
	setworldmapflag 0x0
	nop 
	goto_if 0x0, 0x8050A04
