	nop 
	dotimebasedevents 
	waitstate 
	copyvar 0x96, 0x33F
	playfanfare 0xD4A
	gotostd 0x5
	goto 0x1
	end 
	.incbin "baserom_jp.gba", 0x279235, 0xa1
