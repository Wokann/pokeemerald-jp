	nop
	.byte 0xEA
	waitstate
	end
	.incbin "baserom_jp.gba", 0x2824F4, 0x5F
