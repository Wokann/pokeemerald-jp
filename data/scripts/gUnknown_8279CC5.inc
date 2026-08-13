	nop
	.byte 0xFF
	waitstate
	end
	fadescreenspeed 0xD3, 0x5A
	gotostd 0x2
	return
	.byte 0xF8
	.byte 0xFF
	buffercontesttype
	.byte 0xFF
	nop
	nop
	end
	fadescreenspeed 0xD3, 0x5A
	gotostd 0x82
	return
	.byte 0xF8
	.byte 0xFF
	buffercontesttype
	.byte 0xFF
	setworldmapflag 0x400
	gotostd_if 0x19, 0xC2
	nop
	nop
	return
	dotrainerbattle
	.byte 0xC9
	copybyte 0x20208, 0x3000000
	dotrainerbattle
	.byte 0xC9
	.incbin "baserom_jp.gba", 0x279CF6, 0x77
