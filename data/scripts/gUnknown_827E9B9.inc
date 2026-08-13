	nop 
	dotimebasedevents 
	waitstate 
	nop 
	playbgm 0x1927, 0xAB
	nop 
	showcoinsbox 0x3, 0x31
	checkpcitem 0x80D, 0x505
	nop 
	nop 
	nop 
	nop 
	end 
	.incbin "baserom_jp.gba", 0x27e9cf, 0xc7
