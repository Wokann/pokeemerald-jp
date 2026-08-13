	nop 
	loadbytefromaddr 0x28030A28
	setworldmapflag 0x100C
	nop 
	end 
	.incbin "baserom_jp.gba", 0x27bb84, 0x34
