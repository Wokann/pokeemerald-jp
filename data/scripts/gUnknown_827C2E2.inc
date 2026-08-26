	nop
	call_if 0x28, 0x2280F00
	release
	buffercontesttype
	faceplayer
	gotostd 0x82
	return
	jp_raw_01_u16 0x0
	nop
	end
	nop
	end
	release
	buffercontesttype
	faceplayer
	gotostd 0x82
	return
	jp_raw_01_u16 0x100
	nop
	end
	nop
	.incbin "baserom_jp.gba", 0x27C302, 0x3B
