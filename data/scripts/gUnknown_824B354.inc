	.byte 0xFD
	end
	setorcopyvar 0x20FE, 0x152E
	dotimebasedevents
	nop
	.incbin "baserom_jp.gba", 0x24B35D, 0x12
