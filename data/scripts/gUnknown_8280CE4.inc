	nop 
	waitmoncry 
	waitstate 
	gotostd_if 0x3, 0x28
	setworldmapflag 0xA91C
	nop 
	setdynamicwarp 0x120A, 0xE, 0xD04, 0x828
	setmysteryeventstatus 0x4
	killscript 
	.incbin "baserom_jp.gba", 0x280cf9, 0x45
