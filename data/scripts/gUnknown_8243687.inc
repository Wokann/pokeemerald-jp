	loadword 0x0, 0x8264313
	callstd 0x3
	end 
	goto 0x11412314
	copylocal 0x0, 0x7A
	setrespawn 0x64AE
	dotimebasedevents 
	.byte 0xFE
	compare_addr_to_value 0x60D1F3F, 0xAC
	.byte 0xFF
	compare_addr_to_value 0x3BFE1910, 0x28
	.byte 0x26
	return 
	dotimebasedevents 
	nop 
	goto 0xC00111F
	setptrbyte 0x1F, 0xFDFFAB0D
	setworldmapflag 0xFE1A
	messageautoscroll 0x197E5A5F
	nop 
	dotrainerbattle 
	waitmovement_at 0x61A0, 0x2D00
	end 
	clearflag 0xAB10
	.byte 0xFF
