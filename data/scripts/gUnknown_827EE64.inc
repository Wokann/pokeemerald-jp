	nop 
	doweather 
	waitstate 
	writebytetoaddr 0x72, 0x6F0827EE
	.byte 0xEF
	waitstate 
	gotostd 0x5
	gotostd 0xA
	end 
	.incbin "baserom_jp.gba", 0x27ee74, 0x245
