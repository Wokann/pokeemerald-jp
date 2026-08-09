	nop 
	.byte 0x58
	.byte 0x27
	gotostd_if 0x3, 0x3
	.byte 0x39
	savebgm 0x810
	end 
	nop 
	goto 0xC000AC1B
	.byte 0x3F
	end 
	nop 
	end 
	.byte 0xEC
	.byte 0xEB
	.byte 0x56
	gotostd 0x82
	return 
	call_if 0x0, 0xC0000
	call 0xEBEC0205
	.byte 0x56
	gotostd 0x82
	return 
	goto_if 0x0, 0xC0001
	call 0xEBEC0205
	.byte 0x56
	gotostd 0x82
	return 
	setworldmapflag 0x200
	nop 
	returnram 
	nop 
	call 0xEBEC0205
	.byte 0x56
	gotostd 0x82
	return 
	end 
	nop 
	return 
	nop 
	returnram 
	nop 
	call 0xEBEC0205
	.byte 0x56
	gotostd 0x82
	return 
	return 
	nop 
	nop 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	end 
	nop 
	setworldmapflag 0xC00
	nop 
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	goto 0xC000200
	nop 
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	goto_if 0x0, 0xC0003
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	end 
	nop 
	nop 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	end 
	nop 
	setworldmapflag 0xC00
	nop 
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	setworldmapflag 0x200
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	.byte 0x56
	gotostd 0x82
	return 
	goto 0xC000300
	nop 
	call 0x30B0504
	return 
	.byte 0xF1
	savebgm 0x810
	end 
	nop 
	.byte 0x05
	.byte 0x08
