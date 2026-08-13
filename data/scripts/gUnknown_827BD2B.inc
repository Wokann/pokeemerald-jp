	nop 
	gettime 
	delay 0x9700
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x27bd32, 0x80
