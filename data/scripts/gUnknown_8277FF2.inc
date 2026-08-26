	nop
	dotimebasedevents
	waitstate
	gotostd_if 0x3, 0x2A
	jp_raw_01_u16 0x6802
	writebytetoaddr 0x57, 0x40308
	nop
	nop
	nop
	fadeinbgm 0x0
	nop
	nop
	copyvar 0x90, 0x4C0
	end
	end
	closemessage
	writebytetoaddr 0x57, 0x40308
	nop
	nop
	nop
	fadeinbgm 0x0
	.incbin "baserom_jp.gba", 0x27801B, 0xD1
