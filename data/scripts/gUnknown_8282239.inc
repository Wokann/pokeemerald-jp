	nop 
	mossdeepgym4 
	waitstate 
	nop 
	cmdDB 0x272F0027
	gotostd_if 0x2, 0x19
	setmaplayoutindex 0xC000
	return 
	.incbin "baserom_jp.gba", 0x282249, 0x72
