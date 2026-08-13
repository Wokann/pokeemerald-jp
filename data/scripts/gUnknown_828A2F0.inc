	checkflag 0x9004
	initclock 0x202, 0x200
	nop 
	nop 
	end 
	.incbin "baserom_jp.gba", 0x28a2fb, 0xb
