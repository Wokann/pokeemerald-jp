	nop
	.byte 0xEA
	waitstate
	end
	.incbin "baserom_jp.gba", 0x27D487, 0x68
