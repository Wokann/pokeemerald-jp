	nop
	loadbytefromaddr 0x3010A27
	waitdooranim
	addobject_at 0x810, 0x200
	end
	.incbin "baserom_jp.gba", 0x27BA14, 0x1B
