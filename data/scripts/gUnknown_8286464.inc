	gotostd_if 0x0, 0x3
	buffermovename 0x2B, 0x817
	goto 0x6E710300
	writebytetoaddr 0x8, 0x2050A
	nop 
	nop 
	nop 
	nop 
	loadbyte 0x0, 0xFF
	bufferpartymonnick 0x5, 0x104
	callstd_if 0x0, 0x4
	end 
	.string "{DYNAMIC_COLOR4}{LIGHT_GRAY}ムホち{BLUE}{DYNAMIC_COLOR1}{MUS_RG_SURF}{MUS_DUMMY}{MUS_DUMMY}{MUS_DUMMY}{TRANSPARENT}$"
	.incbin "baserom_jp.gba", 0x286496, 0xb
