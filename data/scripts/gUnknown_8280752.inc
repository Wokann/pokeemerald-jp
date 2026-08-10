	nop 
	setrespawn 0x27
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram 
	gotostd 0x2
	checkplayergender 
	.byte 0xA9
	addobject 0x208
	goto 0xFFE80000
	nop 
	nop 
	nop 
	nop 
	gotostd 0x0
	goto 0x88020A04
	.byte 0xA9
	addobject 0x208
	return 
	nop 
	nop 
	nop 
	nop 
	return 
	nop 
	call 0x1A640202
	setobjectxy 0x208, 0xF008, 0x8FF
	nop 
	nop 
	nop 
	nop 
	nop 
	gotostd_if 0x0, 0x1
	nop 
	setworldmapflag 0x100
	nop 
	copyvar 0x8F, 0x53F
	end 
	warphole 0x2F57
	gotostd 0x2
	call 0x0
	setworldmapflag 0x100
	nop 
	copyvar 0x7B, 0x23F
	checkplayergender 
	.byte 0xA9
	addobject 0x208
	goto 0xFFE40001
	nop 
	nop 
	nop 
	nop 
	return 
	nop 
	call 0x4D090303
	killscript 
	gotostd 0x2
	goto 0x30001
	nop 
	nop 
	callstd_if 0x0, 0x1
	nop 
	goto 0x88020504
	.byte 0xA9
	addobject 0x208
	return 
	setworldmapflag 0x0
	nop 
	goto_if 0x0, 0xD030B05
	.byte 0x08
