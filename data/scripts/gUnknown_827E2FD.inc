	nop 
	dotimebasedevents 
	waitstate 
	gotostd_if 0x3, 0x28
	setworldmapflag 0x901C
	nop 
	showcoinsbox 0x7, 0x7
	end 
	.incbin "baserom_jp.gba", 0x27e30b, 0x106
