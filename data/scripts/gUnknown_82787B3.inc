	nop
	fadescreen 0x27
	nop
	setrespawn 0xA27
	jp_raw_01_u16 0x204
	end
	.incbin "baserom_jp.gba", 0x2787BE, 0x91
