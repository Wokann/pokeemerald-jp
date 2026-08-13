	nop
	fadescreen 0x27
	nop
	drawbox
	waitstate
	end
	vcall_if 0xE8, 0x1020856
	nop
	nop
	copyvar 0xA2, 0x5C0
	.incbin "baserom_jp.gba", 0x279568, 0x45
