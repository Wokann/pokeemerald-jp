	nop 
	dotimebasedevents 
	waitstate 
	gotostd_if 0x3, 0x28
	setworldmapflag 0xC0C
	gotostd 0x3
	playfanfare 0xD4A
	gotostd 0x5
	goto 0x0
	end 
	.incbin "baserom_jp.gba", 0x28037b, 0x87
