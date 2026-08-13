	nop 
	buffertrainername 0x27, 0xF002
	.byte 0xF7
	addobject_at 0x408, 0x300
	nop 
	nop 
	nop 
	nop 
	nop 
	end 
	.incbin "baserom_jp.gba", 0x2828a2, 0x158
