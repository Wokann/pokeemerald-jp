	nop 
	buffertrainerclassname 0x27, 0xDE00
	waitstate 
	nop 
	cmdDB 0x6E710327
	writebytetoaddr 0x8, 0xA050A
	nop 
	nop 
	nop 
	nop 
	gotostd_if 0x0, 0xFF
	bufferpartymonnick 0x5, 0x503
	setobjectmovementtype 0x810, 0x5
	nop 
	end 
	.incbin "baserom_jp.gba", 0x2822de, 0x1d7
